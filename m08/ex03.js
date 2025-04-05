// Função Declarativa
function saudacao(nome) {
    return `Olá, ${nome}!`;
}
console.log(saudacao("Maria"));

// Função de Expressão (Function Expression)
const soma = function (a, b) {
    return a + b;
};
console.log(soma(5, 3));

// Arrow Function
const multiplicar = (a, b) => a * b;
console.log(multiplicar(4, 2));

// Função Anônima (usada frequentemente como callback)
setTimeout(function () {
    console.log("Essa é uma função anônima!");
}, 1000);

// Função Imediatamente Invocada (IIFE - Immediately Invoked Function Expression)
(function () {
    console.log("Essa função é executada imediatamente!");
})();