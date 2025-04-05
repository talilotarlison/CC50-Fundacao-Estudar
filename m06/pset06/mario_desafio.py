# from cs50 import get_int

# mario.py

def main():
    # Solicita ao usuário a altura da pirâmide
    height = get_height_piramide()

    # Gera as meias pirâmides
    for i in range(1, height + 1):
        # Espaços à esquerda
        print(" " * (height - i), end="")
        # Hashes da primeira pirâmide
        print("#" * i, end="")
        # Espaço entre as pirâmides
        print("  ", end="")
        # Hashes da segunda pirâmide
        print("#" * i)

def get_height():
    while True:
        # Solicita um número inteiro entre 1 e 8
        height = get_int("Height: ")
        if 1 <= height <= 8:
            return height

def get_height_piramide():
    height = int(input("Height: "))
    while height < 1 or height > 8:
        height = int(input("Height: "))
    return height

if __name__ == "__main__":
    main()