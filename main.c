#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

const char* afd(const char *cadena) {
    char estado[3] = "q0";
    int i;

    for (i = 0; cadena[i] != '\0'; i++) {
        char c = cadena[i];

        if (strcmp(estado, "q0") == 0) {
            if (c == '+') {
                strcpy(estado, "q1");
            } else if (isupper(c)) {
                strcpy(estado, "q3");
            } else {
                return "NO ACEPTA";
            }
        }
        else if (strcmp(estado, "q1") == 0) {
            if (c == '+') {
                strcpy(estado, "q2");
            } else {
                return "NO ACEPTA";
            }
        }
        else if (strcmp(estado, "q2") == 0) {
            return "NO ACEPTA";
        }
        else if (strcmp(estado, "q3") == 0) {
            if (islower(c) || isdigit(c)) {
                strcpy(estado, "q4");
            } else {
                return "NO ACEPTA";
            }
        }
        else if (strcmp(estado, "q4") == 0) {
            if (islower(c) || isdigit(c)) {
                strcpy(estado, "q4");
            } else {
                return "NO ACEPTA";
            }
        }
    }

    /* Estados finales */
    if (strcmp(estado, "q1") == 0) {
        return "SUMA";
    } else if (strcmp(estado, "q2") == 0) {
        return "INCR";
    } else if (strcmp(estado, "q3") == 0 || strcmp(estado, "q4") == 0) {
        return "ID";
    } else {
        return "NO ACEPTA";
    }
}

int main(int argc, char *argv[]) {
    if (argc != 2) {
        printf("Uso: %s archivo.txt\n", argv[0]);
        return 1;
    }

    FILE *archivo = fopen(argv[1], "r");
    if (archivo == NULL) {
        printf("Archivo no encontrado\n");
        return 1;
    }

    char linea[256];

    while (fgets(linea, sizeof(linea), archivo)) {
        // Eliminar salto de línea si existe
        linea[strcspn(linea, "\r\n")] = 0;
        printf("%s\n", afd(linea));
    }

    fclose(archivo);
    return 0;
}