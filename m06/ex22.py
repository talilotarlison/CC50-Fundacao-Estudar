# Programa que recebe um texto, exibe o texto original e o texto em maiúsculas usando for

# Solicita ao usuário que insira um texto
texto = input("Digite um texto: ")

# Exibe o texto original
print("Texto original:", texto)

# Converte o texto para maiúsculas usando um loop for
print("Texto em maiúsculas:" , end="")
for caractere in texto:
    print(caractere.upper(), end="")


