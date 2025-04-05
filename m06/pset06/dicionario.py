words = set()  # Criar um conjunto vazio para armazenar as palavras

def check(word):
    return word.lower() in words  # Retorna True se a palavra estiver no conjunto

def load(dictionary):
    try:
        # Abrir o arquivo do dicionário e ler cada linha
        with open(dictionary, "r") as file:
            for line in file:
                words.add(line.strip())  # Adicionar cada palavra ao conjunto
        return True  # Retorna True se for bem-sucedido
    except FileNotFoundError:
        print(f"Erro: Arquivo '{dictionary}' não encontrado.")
        return False  # Retorna False se o arquivo não existir

def size():
    return len(words)  # Retorna o número de palavras no conjunto

def unload():
    words.clear()  # Limpa o conjunto de palavras
    return True  # Retorna True se for bem-sucedido
