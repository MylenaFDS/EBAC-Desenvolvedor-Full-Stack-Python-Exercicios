#include <stdio.h>//Biblioteca de comunicação com o usuário
#include <stdlib.h>//Biblioteca de alocação de espaço em memória
#include <locale.h>//Biblioteca de alocações de texto por região
#include <string.h>//Biblioteca responsável por cuidar das strings

int registro()//Função responsável por cadastrar os usuários no sistema
{
	//Início da criação de variáveis/string
	char arquivo[40];
	char cpf[40];
	char nome[40];
	char sobrenome[40];
	char cargo[40];
	//Final da criação de variáveis/string
	
	printf("Digite o CPF a ser cadastrado: ");//Coletando informação do usuário
	scanf("%s",cpf);//%s refere-se a string
	
	strcpy(arquivo,cpf);//Responsável por copiar os valores das strings
	
	FILE *file;//Cria o arquivo
	file=fopen(arquivo,"w");//Cria o arquivo e o "w" significa escrever
	fprintf(file,"Essas são as informações do usuário:\n ");//Frase salva no arquivo para ser vista acima das informações do usuário ao consultar o CPF deste.
	fprintf(file,"\nCPF: ");//Salva o nome da variável,de modo que quando for consultado pelo usuário,aparecerá da seguinte forma:"CPF:valor da variável"(exemplo)
	fprintf(file,cpf);//Salva o valor da variável
	fclose(file);//Fecha o arquivo
	
	file=fopen(arquivo,"a");//Abre o arquivo criado."a" significa atualizar
	fprintf(file,"\n");//Inclui a vírgula no arquivo
	fclose(file);//Fecha o arquivo
	
	printf("Digite o nome a ser cadastrado: ");
    getchar(); // Limpa o caractere de nova linha pendente no buffer
    fgets(nome, sizeof(nome), stdin); // Lê uma linha inteira, incluindo espaços em branco
    nome[strcspn(nome, "\n")] = '\0'; // Remove a nova linha do final do nome
	
	file=fopen(arquivo,"a");
	fprintf(file,"Nome: ");
	fprintf(file,nome);
	fclose(file);
	
	file=fopen(arquivo,"a");
	fprintf(file,"\n");
	fclose(file);
	
	printf("Digite o sobrenome a ser cadastrado: ");
	fgets(sobrenome, sizeof(sobrenome), stdin); // Lê uma linha inteira, incluindo espaços em branco
    sobrenome[strcspn(sobrenome, "\n")] = '\0'; // Remove a nova linha do final do sobrenome
	
	file=fopen(arquivo,"a");
	fprintf(file,"Sobrenome: ");
	fprintf(file,sobrenome);
	fclose(file);
	
	file=fopen(arquivo,"a");
	fprintf(file,"\n");
	fclose(file);
	
	printf("Digite o cargo a ser cadastrado: ");
	fgets(cargo, sizeof(cargo), stdin);
	cargo[strcspn(cargo, "\n")] = '\0';
	
	file=fopen(arquivo,"a");
	fprintf(file,"Cargo: ");
	fprintf(file,cargo);
	fclose(file);
	
	file=fopen(arquivo,"a");
	fprintf(file,"\n");
	fclose(file);
	
	system("pause");
	
}

int consulta()
{
	setlocale(LC_ALL,"Portuguese");//Definindo a linguagem
	
	char cpf[40];
	char conteudo[200];
	
	
	printf("Digite o CPF a ser consultado: ");
	scanf("%s",cpf);
	
	FILE *file;
	file=fopen(cpf,"r");

	system("cls");
	
	if(file==NULL)
	{
		printf("Não foi possível abrir o arquivo,não localizado.\n!");
	}
	
	while(fgets(conteudo,200,file)!=NULL)
	{
        printf("%s",conteudo); 
	}
	
		system("pause");
}

int deletar()
{
	char cpf[40];
	
	printf("Digite o CPF do usuário a ser deletado:\n ");
	scanf("%s", cpf);
	
	FILE *file;
	file = fopen(cpf,"r");
	
	system("cls");
		
	if (file == NULL)
	{
		fclose(file);
		printf("Usuário não encontrado no sistema! \n");
		system("pause");
	}

    
   else if (file != NULL)
    
	{
		fclose(file);
		printf("Usuário deletado!) \n");
		remove (cpf);
		system("pause");
	
	}
	
	
}

int main()
{
	int opcao=0;//Definindo variáveis
	int laco=1;
	char senhadigitada[10]="a";
	int comparacao;
	
	printf("### Cartório da EBAC ###\n\n");
	printf("Login de administrador!\n\nDigite a sua senha: ");
	scanf("%s", senhadigitada);
	
	comparacao=strcmp(senhadigitada,"admin");
	
	 if(comparacao== 0)
	{
	
		for(laco=1;laco=1;)
		{
			system("cls");
	
			setlocale(LC_ALL,"Portuguese");//Definindo a linguagem
	
			printf("### Cartório da EBAC ###\n\n");//Início do menu
			printf("Escolha a opção desejada do menu:\n\n");
			printf("\t1 - Registrar nomes\n");
			printf("\t2 - Consultar nomes\n");
			printf("\t3 - Deletar nomes\n");
			printf("\t4 - Sair do sistema\n\n");
			printf("Opção: ");//Fim do menu

			scanf("%d",&opcao);//Armazenando a escolha do usuário
	
			system("cls");//Responsável por limpar a tela
		
		
			switch(opcao)
			{
				case 1:
		    	 registro();//Chamada de Funções
		    	break;
		    
		    	case 2:
		   		 consulta();//Chamada de Funções
				break;
			
				case 3:
				 deletar();//Chamada de Funções
				break;
			
				case 4:
	 			 printf("Obrigado por utilizar o sistema!\n");
	 	    	return 0;
	 	    	break;
	 		 
	 		 
				default:
		   		 printf("Essa opção não está disponível!\n");
				 system("pause");
				break;		
			}
		}
	}
	
	else
		printf("Senha incorreta!");
}
