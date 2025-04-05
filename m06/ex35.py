import pyttsx3

engine = pyttsx3.init()
nome = input("Digite seu nome: ")
engine.say(f"Hello, {nome}.")
engine.runAndWait()
