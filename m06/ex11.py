s = string(input("Entre com S(sim) N(Não): "))

if s.lower() in ["s", "sim"]:
    print("Aceito!")
elif s.lower() in ["n", "não"]:
    print("Não aceito!")