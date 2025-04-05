# lista telefonica
# dicionário com nomes e telefones
# Programa que busca o telefone de uma pessoa em uma lista telefônica (dicionário)
pessoas = {
    "Lucas": 123456789,
    "Ana": 987654321,
    "Pedro": 456789123,
    "Maria": 321654987,
    "João": 654321789,
    "Carla": 789123456,
    "Rafael": 159753486,
    "Fernanda": 753159852,
    "Gustavo": 951753486,
    "Patrícia": 258963147
}

contato = input("Digite o nome da pessoa que deseja buscar: ")
if contato in pessoas:
    print(f"Telefone de {contato}: {pessoas[contato]}")
else:
    print(f"{contato} não está na lista telefônica.")