dinero = [500, 200, 100, 50, 20, 10, 5, 2, 1]


def calcularVuelto(precio, pago):
    restante = pago - precio
    vuelto = []
    indice = 0
    if restante == 0:
        vuelto.append("0")
        return vuelto
    while restante > 0:
        if(restante - dinero[indice] >= 0):
            vuelto.append(str(dinero[indice]))
            restante = restante - dinero[indice]
        else:
            indice = indice + 1
    return vuelto

print("Ingrese pago, precio en el siguiente formato (pago, precio): ")
caso = input()
numeros = [numero.strip() for numero in caso.split(',')]
vuelto = calcularVuelto(int(numeros[1]), int(numeros[0]))
imprimir = "["
for moneda in vuelto[:-1]:
    imprimir = imprimir + " " + moneda + ","

imprimir = imprimir + " " + vuelto[-1] + " ]"
print(imprimir)
