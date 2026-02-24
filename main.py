import sys

def afd(cadena):
    estado = "q0"
    
    for c in cadena:
        if estado == "q0":
            if c == "+":
                estado = "q1"
            elif c.isupper():
                estado = "q3"
            else:
                return "NO ACEPTA"
        
        elif estado == "q1":
            if c == "+":
                estado = "q2"
            else:
                return "NO ACEPTA"
        
        elif estado == "q2":
            return "NO ACEPTA"
        
        elif estado == "q3":
            if c.islower() or c.isdigit():
                estado = "q4"
            else:
                return "NO ACEPTA"
        
        elif estado == "q4":
            if c.islower() or c.isdigit():
                estado = "q4"
            else:
                return "NO ACEPTA"
    
    # Estados finales
    if estado == "q1":
        return "SUMA"
    elif estado == "q2":
        return "INCR"
    elif estado == "q3" or estado == "q4":
        return "ID"
    else:
        return "NO ACEPTA"


def main():
    if len(sys.argv) != 2:
        print("Uso: python afd.py archivo.txt")
        return
    
    archivo = sys.argv[1]
    
    try:
        with open(archivo, 'r') as f:
            for linea in f:
                cadena = linea.strip()
                print(afd(cadena))
    except FileNotFoundError:
        print("Archivo no encontrado")
        
main()