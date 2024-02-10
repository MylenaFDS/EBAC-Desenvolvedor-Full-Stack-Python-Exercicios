#include <stdio.h>//Biblioteca de comunica��o com o usu�rio
#include <stdlib.h>//Biblioteca de aloca��o de espa�o em mem�ria
#include <locale.h>//Biblioteca de aloca��es de texto por regi�o
#include <string.h>//Biblioteca respons�vel por cuidar das strings

int registro()//Fun��o respons�vel por cadastrar os usu�rios no sistema
{
	//In�cio da cria��o de vari�veis/string
	char arquivo[40];
	char cpf[40];
	char nome[40];
	char sobrenome[40];
	char cargo[40];
	//Final da cria��o de vari�veis/string
	
	printf("Digite o CPF a ser cadastrado: ");//Coletando informa��o do usu�rio
	scanf("%s",cpf);//%s refere-se a string
	
	strcpy(arquivo,cpf);//Respons�vel por copiar os valores das strings
	
	FILE *file;//Cria o arquivo
	file=fopen(arquivo,"w");//Cria o arquivo e o "w" significa escrever
	fprintf(file,"Essas s�o as informa��es do usu�rio:\n ");//Frase salva no arquivo para ser vista acima das informa��es do usu�rio ao consultar o CPF deste.
	fprintf(file,"\nCPF: ");//Salva o nome da vari�vel,de modo que quando for consultado pelo usu�rio,aparecer� da seguinte forma:"CPF:valor da vari�vel"(exemplo)
	fprintf(file,cpf);//Salva o valor da vari�vel
	fclose(file);//Fecha o arquivo
	
	file=fopen(arquivo,"a");//Abre o arquivo criado."a" significa atualizar
	fprintf(file,"\n");//Inclui a v�rgula no arquivo
	fclose(file);//Fecha o arquivo
	
	printf("Digite o nome a ser cadastrado: ");
    getchar(); // Limpa o caractere de nova linha pendente no buffer
    fgets(nome, sizeof(nome), stdin); // L� uma linha inteira, incluindo espa�os em branco
    nome[strcspn(nome, "\n")] = '\0'; // Remove a nova linha do final do nome
	
	file=fopen(arquivo,"a");
	fprintf(file,"Nome: ");
	fprintf(file,nome);
	fclose(file);
	
	file=fopen(arquivo,"a");
	fprintf(file,"\n");
	fclose(file);
	
	printf("Digite o sobrenome a ser cadastrado: ");
	fgets(sobrenome, sizeof(sobrenome), stdin); // L� uma linha inteira, incluindo espa�os em branco
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
		printf("N�o foi poss�vel abrir o arquivo,n�o localizado.\n!");
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
	
	printf("Digite o CPF do usu�rio a ser deletado:\n ");
	scanf("%s", cpf);
	
	FILE *file;
	file = fopen(cpf,"r");
	
	system("cls");
		
	if (file == NULL)
	{
		fclose(file);
		printf("Usu�rio n�o encontrado no sistema! \n");
		system("pause");
	}

    
   else if (file != NULL)
    
	{
		fclose(file);
		printf("Usu�rio deletado!) \n");
		remove (cpf);
		system("pause");
	
	}
	
	
}

int main()
{
	int opcao=0;//Definindo vari�veis
	int laco=1;
	char senhadigitada[10]="a";
	int comparacao;
	
	printf("### Cart�rio da EBAC ###\n\n");
	printf("Login de administrador!\n\nDigite a sua senha: ");
	scanf("%s", senhadigitada);
	
	comparacao=strcmp(senhadigitada,"admin");
	
	 if(comparacao== 0)
	{
	
		for(laco=1;laco=1;)
		{
			system("cls");
	
			setlocale(LC_ALL,"Portuguese");//Definindo a linguagem
	
			printf("### Cart�rio da EBAC ###\n\n");//In�cio do menu
			printf("Escolha a op��o desejada do menu:\n\n");
			printf("\t1 - Registrar nomes\n");
			printf("\t2 - Consultar nomes\n");
			printf("\t3 - Deletar nomes\n");
			printf("\t4 - Sair do sistema\n\n");
			printf("Op��o: ");//Fim do menu

			scanf("%d",&opcao);//Armazenando a escolha do usu�rio
	
			system("cls");//Respons�vel por limpar a tela
		
		
			switch(opcao)
			{
				case 1:
		    	 registro();//Chamada de Fun��es
		    	break;
		    
		    	case 2:
		   		 consulta();//Chamada de Fun��es
				break;
			
				case 3:
				 deletar();//Chamada de Fun��es
				break;
			
				case 4:
	 			 printf("Obrigado por utilizar o sistema!\n");
	 	    	return 0;
	 	    	break;
	 		 
	 		 
				default:
		   		 printf("Essa op��o n�o est� dispon�vel!\n");
				 system("pause");
				break;		
			}
		}
	}
	
	else
		printf("Senha incorreta!");
}
