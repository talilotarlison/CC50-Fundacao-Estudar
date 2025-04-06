# 02_create_schema.py
import sqlite3

# conectando...
conn = sqlite3.connect('favoritos.db')
# definindo um cursor
cursor = conn.cursor()

# criando a tabela (schema)
cursor.execute("""
SELECT * FROM favoritos;
""")

for linha in cursor.fetchall():
    print(linha)

print('Registros do banco lidos com sucesso.')
# desconectando...
conn.close()