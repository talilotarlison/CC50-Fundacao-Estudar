
// TODO: Add code to check answers to questions

//Pega varios seletores de uma vez e colocar no arraw

var escolhas = document.querySelectorAll('.section button');
var total = escolhas.length;
console.log(total);

//percorre o array de valores do botoes com for off

for (escolha of escolhas) {
  console.log(escolha.innerText);
};

var resu1 = document.getElementById('resultado1');
var resu2 = document.getElementById('resultado2');
//Buca todos os elementos da classe 'btn'
var tdBtn = document.getElementsByClassName('bts');

// pegando botoes
/*
var btn1 = document.querySelector('#op1');
var btn2 = document.querySelector('#op2');
var btn3 = document.querySelector('#op2');
var btn4 = document.querySelector('#op4');
var btn5 = document.querySelector('#op5');
var btn6 = document.querySelector('#op6');
var btn7 = document.querySelector('#op7');
*/

//percorre o array de valores do botoes com for
//criação da função
for (i = 0; i < tdBtn.length; i++) {
  tdBtn[i].addEventListener("click", (e) => {
    var btValor = document.getElementById(e.target.id);
    var escolhaCorreta = "Pele";
    if (escolhaCorreta === btValor.innerText) {
      document.getElementById(e.target.id).style.backgroundColor = "green";
      resu1.style.color = "green";
      resu1.innerHTML = `<p> Parabens, você acertou é o <strong>${btValor.innerText}</strong>!!!</p>`;
    } else {
      document.getElementById(e.target.id).style.backgroundColor = "red";
      resu1.style.color = "red";
      resu1.innerHTML =
        `<p>Infelizmente você Errou, não é <strong>${btValor.innerText}</strong>, tente novamente!!</p>`;
    }
  });
};

//codigo da resposta dois
function verificar() {
  var respostaUser1 = document.getElementById('resposta');
  var btnVerifica = document.getElementById('check');
  var respostaUser = respostaUser1.value;
  var respostaQuizz = "barcelona";
  if (respostaQuizz === respostaUser.toLowerCase()) {
    btnVerifica.style.backgroundColor = "green";
    resu2.style.color = "green";
    resu2.innerHTML = `<p> Parabens, você acertou é o <strong>${respostaUser}</strong>!!!</p>`;
    respostaUser1.value = "";
  } else if (respostaUser.toLowerCase() == "") {
    btnVerifica.style.backgroundColor = "red";
    resu2.style.color = "red";
    resu2.innerHTML = `<p> Informe algum time, o campo esta vazio!!!</p>`;
  } else {
    btnVerifica.style.backgroundColor = "red";
    resu2.style.color = "red";
    resu2.innerHTML = `<p> Infelizmente você errou é o <strong>${respostaUser}</strong>!!!</p>`;
    respostaUser1.value = "";
  }
};
