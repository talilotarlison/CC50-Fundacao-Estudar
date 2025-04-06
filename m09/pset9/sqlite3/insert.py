# 03_create_data_sql.py
import sqlite3

conn = sqlite3.connect('favoritos.db')
cursor = conn.cursor()

# inserindo dados na tabela
cursor.execute("""
INSERT INTO favoritos (nome, url, criado_em)
VALUES ('Pasterbin','www.pasterbin.com', '2015-06-08')
""")
cursor.execute("""
INSERT INTO favoritos (nome, url, criado_em)
VALUES ('CS50','www.cs50.dec', '2013-06-08')
""")



# gravando no bd
conn.commit()

print('Dados inseridos com sucesso.')

conn.close()