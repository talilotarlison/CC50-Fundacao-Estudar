#https://pythonclub.com.br/gerenciando-banco-dados-sqlite3-python-parte1.html

import sqlite3

conn = sqlite3.connect('favoritos.db')
# definindo um cursor
cursor = conn.cursor()

cursor.execute("""
DELETE FROM favoritos WHERE id="4";
""")
conn.commit()
print('Regsitro deletetado com sucesso!')
conn.close()


