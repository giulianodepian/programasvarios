print("Ingrese caso de prueba: ")
caso = input()
cantCorchete1 = 0
cantCorchete2 = 0
for corchete in caso:
    if corchete == '[':
        cantCorchete1 = cantCorchete1 + 1
    elif corchete == ']' and cantCorchete1 > cantCorchete2:
        cantCorchete2 = cantCorchete2 + 1
    else:
        cantCorchete1 = cantCorchete1 + 1
        break
print(cantCorchete1 == cantCorchete2)
