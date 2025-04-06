#https://docs.python.org/3/library/sqlite3.html

#https://pythonclub.com.br/guia-rapido-comandos-sqlite3.html

#https://pythonclub.com.br/gerenciando-banco-dados-sqlite3-python-parte1.htmlclea

import sqlite3
con = sqlite3.connect("usuario.db")
cur = con.cursor()

print('Concexão feita com sucesso.')

cur.execute("""
INSERT INTO usuario VALUES
        ('victor', "santos", 54.2)
""")

con.commit()
print('Dados inseridos com sucesso')
con.close()