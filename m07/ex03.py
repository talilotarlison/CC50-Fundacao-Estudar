import csv

titles = set()

with open('Favorite TV Shows - From Responses 1.csv', 'r') as file:
    reader = csv.DictReader(file)
    header = next(reader)  # Skip the header row
    for row in reader:
        titles.add(row['title'].strip().lower())  # Convert to lowercase to avoid duplicates

for title in sorted(titles):
    print(title)

# Os dados com entrada sem padronizão podem gerar inconsistências, como por exemplo:
# "The Office" " the office" e "the office" serem considerados diferentes.
# Para evitar isso, podemos usar o método .lower() para padronizar as entradas.

# As etapas da análise de dados são: 
# Definição de objetivos e perguntas
# Coleta de dados
# Limpeza de dados (padronização dos dados para evitar inconsistências) 
# Análise de dados
# Interpretação e visualização de dados
# Narrativa de dados