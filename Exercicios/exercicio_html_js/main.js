function validarFormulario() {
    var campoA = document.getElementById('campoA').value;
    var campoB = document.getElementById('campoB').value;

    campoA = parseFloat(campoA);
    campoB = parseFloat(campoB);

    if (campoB > campoA) {
        exibirMensagem(true);
    } else {
        exibirMensagem(false);
    }
}

function exibirMensagem(valido) {
    var resultDiv = document.getElementById('result');
    resultDiv.innerHTML = '';

    var mensagem = document.createElement('p');
    mensagem.className = valido ? 'valid' : 'invalid';
    mensagem.textContent = valido ? 'Formulário válido! Número B é maior que o número A.' : 'Formulário inválido! Número B deve ser maior que o número A.';

    resultDiv.appendChild(mensagem);
}
