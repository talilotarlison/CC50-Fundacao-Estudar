import sys

words = set()  # Criar um conjunto vazio para armazenar as palavras

def check(word):
    return word.lower() in words  # Retorna True se a palavra estiver no conjunto

def load(dictionary):
    try:
        with open(dictionary, "r") as file:
            for line in file:
                words.add(line.strip())  # Adicionar cada palavra ao conjunto
        return True
    except FileNotFoundError:
        print(f"Erro: Arquivo '{dictionary}' não encontrado.")
        return False

def size():
    return len(words)  # Retorna o número de palavras no conjunto

def unload():
    words.clear()  # Limpa o conjunto de palavras
    return True

# Verifica se um argumento foi passado
if len(sys.argv) != 2:
    print("Uso: python spellchecker.py <arquivo_dicionario>")
    sys.exit(1)

# Carrega o arquivo passado no argumento
dictionary_file = sys.argv[1]
if load(dictionary_file):
    print(f"Arquivo '{dictionary_file}' carregado com sucesso!")
    print(f"O dicionário contém {size()} palavras.")

# Execute no terminal
# Agora, você pode executar o script passando o arquivo dictionary.txt como argumento:

# python spellchecker.py dictionary.txt