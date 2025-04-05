# from cs50 import get_float

def main():
    # Solicita ao usuário um valor válido
    while True:
        dollars = float(input("Change owed: "))
        if dollars >= 0:
            break

    # Converte dólares para centavos
    cents = round(dollars * 100)

    # Calcula o número mínimo de moedas
    coins = 0
    for coin in [25, 10, 5, 1]:
        coins += cents // coin
        cents %= coin

    # Imprime o número mínimo de moedas
    print(coins)

if __name__ == "__main__":
    main()