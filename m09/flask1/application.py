from flask import Flask, render_template, request, redirect, url_for

app = Flask(__name__)

@app.route('/')
def hello():
    return render_template('index.html', name=request.args.get('name'))


# https://pt.linkedin.com/pulse/estrutura-e-organiza%C3%A7%C3%A3o-de-pastas-mvc-em-projetos-dalmo-cabral
# https://flask.palletsprojects.com/en/stable/