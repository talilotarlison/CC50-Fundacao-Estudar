import sqlite3
# https://pythongeeks.org/switch-in-python/
# Conectar ao banco de dados
con = sqlite3.connect("bd.db")

# Verificar se a tabela já existe
cur = con.cursor()
cur.execute("SELECT name FROM sqlite_master WHERE type='table' AND name='usuario'")
tabela_existe = cur.fetchone()

if tabela_existe:
    print("A tabela 'usuario' já existe.")
else:
    # Criar a tabela
    cur.execute("CREATE TABLE usuario(nome varchar(50), sobrenome varchar(50), idade int(50))")
    con.commit()  # Confirmar as alterações no banco de dados
    print("Tabela 'usuario' criada com sucesso.")

# Fechar a conexão
con.close()