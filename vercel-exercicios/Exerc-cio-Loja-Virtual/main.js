document.addEventListener('DOMContentLoaded', function () {
    const buttons = document.querySelectorAll('.add-to-cart');
    const nav = document.querySelector('nav');

    buttons.forEach(button => {
        button.addEventListener('click', function () {
            alert('Produto adicionado ao carrinho! Que sua jornada seja repleta de elegância e encanto.');
        });
    });

    $('.menu-hamburguer').click(function(){
        nav.classList.toggle('show');
    });
});































