# ATUALIZAR DADOS DO BANCO
#https://pythonclub.com.br/gerenciando-banco-dados-sqlite3-python-parte1.html

import sqlite3

conn = sqlite3.connect('favoritos.db')
cursor = conn.cursor()

id = 2
nome = 'Google'
url = 'www.google.com.br'

# alterando os dados da tabela
cursor.execute("""
UPDATE favoritos
SET nome = ?, url = ?
WHERE id = ?
""", (nome, url, id))

conn.commit()

print('Dados atualizados com sucesso.')

conn.close()