# from cs50 import get_string
import re

def main():
    # Solicita ao usuário que insira o texto
    text = input("Text: ")

    # Conta o número de letras, palavras e frases
    letters = count_letters(text)
    words = count_words(text)
    sentences = count_sentences(text)

    # Calcula o índice Coleman-Liau
    L = (letters / words) * 100
    S = (sentences / words) * 100
    index = round(0.0588 * L - 0.296 * S - 15.8)

    # Imprime o nível escolar
    if index < 1:
        print("Before Grade 1")
    elif index >= 16:
        print("Grade 16+")
    else:
        print(f"Grade {index}")

def count_letters(text):
    # Conta letras (a-z, A-Z)
    return len(re.findall(r'[a-zA-Z]', text))

def count_words(text):
    # Conta palavras separadas por espaços
    return len(text.split())

def count_sentences(text):
    # Conta frases terminadas por ., ! ou ?
    return len(re.findall(r'[.!?]', text))

if __name__ == "__main__":
    main()