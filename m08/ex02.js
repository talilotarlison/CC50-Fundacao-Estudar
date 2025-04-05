// Podemos passar uma função lambda com a sintaxe function(), então aqui passamos os dois ouvintes diretamente para addEventListener.

// Além de submit , existem muitos outros eventos que podemos ouvir:

// blur

// change

// click

// drag

// focus

// keyup

// load

// mousedown

// mouseover

// mouseup

// submit

// touchmove

// unload

document.addEventListener("click", function () {
    console.log("O documento foi clicado!");
});

document.addEventListener("keyup", function (event) {
    console.log(`Tecla pressionada: ${event.key}`);
});

window.addEventListener("load", function () {
    console.log("A página foi carregada!");
});

document.querySelector("form").addEventListener("submit", function (event) {
    event.preventDefault();
    console.log("Formulário enviado!");
});