def swap(a, b):
    return b, a

# Exemplo de uso da função swap
x = 5
y = 10

print("Antes da troca: x =", x, ", y =", y)
x, y = swap(x, y)
print("Depois da troca: x =", x, ", y =", y)