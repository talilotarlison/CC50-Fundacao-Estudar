import sys

numeros = [1, 2, 3, 4, 5]
# busca linea 1 na lista numeros
if 1 in numeros:
    print("1 está na lista")
    sys.exit(0)
else:
    print("1 não está na lista")
    sys.exit(1)
# O que acontece se você substituir 1 por 6?