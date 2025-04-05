# from cs50 import get_string

def main():
    # Solicita o número do cartão de crédito ao usuário
    card_number = input("Number: ")

    # Verifica se o número do cartão é válido usando o algoritmo de Luhn
    if not is_valid(card_number):
        print("INVALID")
        return

    # Determina o tipo de cartão
    card_type = get_card_type(card_number)
    print(card_type)

def is_valid(card_number):
    """Verifica se o número do cartão é válido usando o algoritmo de Luhn."""
    total = 0
    reverse_digits = card_number[::-1]

    for i, digit in enumerate(reverse_digits):
        n = int(digit)
        if i % 2 == 1:
            n *= 2
            if n > 9:
                n -= 9
        total += n

    return total % 10 == 0

def get_card_type(card_number):
    """Determina o tipo de cartão com base no número."""
    if len(card_number) == 15 and (card_number.startswith("34") or card_number.startswith("37")):
        return "AMEX"
    elif len(card_number) == 16 and card_number[:2] in {"51", "52", "53", "54", "55"}:
        return "MASTERCARD"
    elif (len(card_number) == 13 or len(card_number) == 16) and card_number.startswith("4"):
        return "VISA"
    else:
        return "INVALID"

if __name__ == "__main__":
    main()