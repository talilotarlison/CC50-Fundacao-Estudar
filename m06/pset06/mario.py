# from cs50 import get_int

def main():
    # Solicita ao usuário a altura da meia-pirâmide
    while True:
        height = int(input("Height: "))
        if 1 <= height <= 8:
            break

    # Gera a meia-pirâmide
    for i in range(1, height + 1):
        # Imprime os espaços e os hashes
        print(" " * (height - i) + "#" * i)

if __name__ == "__main__":
    main()