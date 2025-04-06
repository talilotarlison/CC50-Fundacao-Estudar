document.addEventListener("DOMContentLoaded", function () {
    const form = document.querySelector("form");

    form.addEventListener("submit", function (event) {
        const nome = form.nome.value.trim();
        const dia = parseInt(form.dia.value);
        const mes = parseInt(form.mes.value);

        let erros = [];

        if (!nome) {
            erros.push("O nome não pode estar vazio.");
        }

        if (isNaN(mes) || mes < 1 || mes > 12) {
            erros.push("O mês deve ser um número entre 1 e 12.");
        }

        if (isNaN(dia) || dia < 1 || dia > 31) {
            erros.push("O dia deve ser um número entre 1 e 31.");
        }

        if (erros.length > 0) {
            event.preventDefault(); // Impede o envio do formulário
            alert(erros.join("\n"));
        }
    });
});
