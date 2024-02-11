$(document).ready(function(){
    $('#carousel-imagens').slick({
        autoplay: true
    });

    $('.menu-hamburguer').click(function(){
        $('nav').slideToggle();
    })

    $('#telefone').mask('(00)00000-0000')

    $('form').validate({
        rules: {
            nome: {
                required:true
            },

            email: {
                required:true,
                email:true
            },

            telefone: {
                required:true
            },

            veiculo_interesse: {
                required:true
            },

            mensagem: {
                required:true
            }
        },messages: {
            nome:'Por favor,insira o seu nome',
            telefone:'Por favor,insira o seu telefone',
            email:'Por favor,insira o seu e-mail',
            veiculo_interesse:'Por favor,insira o nome do veículo de seu interesse',
            mensagem: 'Por favor,insira sua mensagem'
        },
        submitHandler: function(form) {
            console.log(form)
        },
        invalidHandler: function(evento,validador) {
            let camposIncorretos = validador.numberOfInvalids();
           if(camposIncorretos) {
            alert(`Existem ${camposIncorretos} campos incorretos`)
           }
        }
    })

    $('.lista-veículos button').click(function(){
        const destino = $('#contato');
        const nomeVeiculo = $(this).parent().find('h3').text();

        $(`#veiculo_interesse`).val(nomeVeiculo);
        
        $('html').animate({
            scrollTop: destino.offset().top
            
        },1000)
    })
    
});