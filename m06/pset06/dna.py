import csv
import sys

def main():
    # Verifica se o número correto de argumentos foi fornecido
    if len(sys.argv) != 3:
        print("Usage: python dna.py data.csv sequence.txt")
        sys.exit(1)

    # Lê o arquivo CSV e armazena os dados
    database_file = sys.argv[1]
    sequence_file = sys.argv[2]

    try:
        with open(database_file, "r") as file:
            reader = csv.DictReader(file)
            database = list(reader)
            str_sequences = reader.fieldnames[1:]  # Obtém os STRs da primeira linha
    except FileNotFoundError:
        print(f"Error: File {database_file} not found.")
        sys.exit(1)

    # Lê o arquivo de sequência de DNA
    try:
        with open(sequence_file, "r") as file:
            dna_sequence = file.read().strip()
    except FileNotFoundError:
        print(f"Error: File {sequence_file} not found.")
        sys.exit(1)

    # Calcula a contagem mais longa de repetições consecutivas para cada STR
    str_counts = {str_seq: longest_match(dna_sequence, str_seq) for str_seq in str_sequences}

    # Compara as contagens com o banco de dados
    for person in database:
        if all(int(person[str_seq]) == str_counts[str_seq] for str_seq in str_sequences):
            print(person["name"])
            return

    print("No match")


def longest_match(sequence, subsequence):
    """Retorna a execução mais longa de repetições consecutivas de `subsequence` em `sequence`."""
    longest_run = 0
    subseq_length = len(subsequence)
    seq_length = len(sequence)

    for i in range(seq_length):
        count = 0
        while sequence[i + count * subseq_length:i + (count + 1) * subseq_length] == subsequence:
            count += 1
        longest_run = max(longest_run, count)

    return longest_run


if __name__ == "__main__":
    main()