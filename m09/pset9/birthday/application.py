from flask import Flask, render_template, request, redirect, url_for
import sqlite3

app = Flask(__name__)

@app.route('/')
def index():
    # Conectando ao banco de dados
    try:
        conn = sqlite3.connect('sqlite.db')
        cursor = conn.cursor()

        # Inserindo dados na tabela
        cursor.execute("SELECT * FROM birthdays;")
        birthdays = cursor.fetchall()  # Armazena todos os resultados
        print('Consulta realizada com sucesso.')

    except Exception as e:
        print(f'Falha ao exibir: {e}')
        birthdays = []  # Define birthdays como uma lista vazia em caso de erro

    finally:
        # Desconectando
        conn.close()

    return render_template('index.html',birthdays=birthdays)

# https://pythoniluminado.netlify.app/tuplas
# https://cs50.harvard.edu/x/2025/psets/9/birthdays/

@app.route('/adicionarAniversario',methods=['POST'])
def adicionarAniversario():
     # Obtendo dados do formulário
    nome = request.form.get('nome')
    mes = request.form.get('mes')
    dia = request.form.get('dia')
    print(nome, mes, dia)

    # Conectando ao banco de dados
    try:
        conn = sqlite3.connect('sqlite.db')
        cursor = conn.cursor()

        # Inserindo dados na tabela
        cursor.execute("INSERT INTO birthdays (name, month, day) VALUES (?, ?, ?)", (nome, mes, dia))
        conn.commit()  # Commit necessário para persistir a alteração
        print('Inserção criada com sucesso.')

    except Exception as e:
        print(f'Falha ao inserir: {e}')

    finally:
        # Desconectando
        conn.close()
    return redirect(url_for('index'))  # Redireciona para a página inicial
    # return render_template('sucesso.html', nome=nome, mes=mes, dia=dia)

@app.route('/apagar', methods=['GET'])
def apagar():
   if request.method == "GET":
        id = request.args.get('id') # Usar request.form.get para dados de formulário em post

        if id:
            conn = sqlite3.connect('sqlite.db')  # Substitua pelo nome do seu banco
            cursor = conn.cursor()

            cursor.execute("DELETE FROM birthdays WHERE id = ?", (id))
            conn.commit()
            conn.close()
        return redirect(url_for('index'))  # Redireciona para a página inicial
        # return render_template('delete.html', id=id)

if __name__ == '__main__':
    app.run(debug=True)