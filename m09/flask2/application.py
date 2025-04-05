from flask import Flask, render_template, request, redirect, url_for

app = Flask(__name__)


@app.route('/')
def index():
    return render_template('index.html', name=request.args.get('name','word'))

@app.route('/greet')
def greet():
    nome = request.args.get('name')
    idade = request.args.get('idade')
    return render_template('greet.html', name=nome,idade=idade)

@app.route('/rotapost', methods=['POST'])
def rotapost():
  if request.method == "POST":
        nome = request.form.get('name') # Usar request.form para dados de formulário
        idade = request.form.get('idade')
        return render_template('rotapost.html', name=nome, idade=idade)

if __name__ == '__main__':
    app.run(debug=True)