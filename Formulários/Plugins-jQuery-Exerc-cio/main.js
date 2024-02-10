$(document).ready(function(){
    // Aplicar máscaras aos campos
    $('#telefone').mask('+00 (00) 0 0000-0000');
    $('#cpf').mask('000.000.000-00', {reverse: true});
    $('#cep').mask('00000-000');

    // Adicionar ação ao formulário
    $('#cadastroForm').validate({
        rules: {
            nomeCompleto: {
                required: true
            },
            email: {
                required: true,
                email: true
            },
            telefone: {
                required: true
            },
            cpf: {
                required: true
            },
            endereco: {
                required: true
            },
            cep: {
                required: true
            }
        },
        messages: {
            nomeCompleto: 'Por favor, insira o seu nome',
            telefone: 'Por favor, insira o seu telefone',
            email: 'Por favor, insira o seu e-mail',
            cpf: 'Por favor, insira o seu CPF',
            endereco: 'Por favor, insira o seu endereço',
            cep: 'Por favor, insira o seu CEP'
        },
        submitHandler: function(form) {
            // Lógica para enviar os dados do formulário para o servidor
            alert('Formulário enviado com sucesso!');
            
            // Limpar os campos do formulário
            form.reset();
        },
        invalidHandler: function(event, validator) {
            let camposIncorretos = validator.numberOfInvalids();
            if (camposIncorretos) {
                $('#mensagem').html(`Existem ${camposIncorretos} campos incorretos`);
                
                // Adicionar um atraso de 2 segundos antes de limpar a mensagem
                setTimeout(function() {
                    $('#mensagem').html('');
                }, 2000);
            }
        }
    });
});

