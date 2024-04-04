document.getElementById("texto").innerHTML = "Eu sou uma frase muito legal e a <strong> aula de quinta </strong> é a melhor"
// innerHTML faz escrever no HTML


function foAmarelo(){
    document.body.style.color='yellow';
}

function fAzul() {
    // alert('retorno');
    document.body.style.backgroundColor='blue';
}

function fSemCor(){
    document.body.style.removeProperty('background-color');
    document.body.style.removeProperty('color');
}