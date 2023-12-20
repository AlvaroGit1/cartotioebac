#include <stdio.h> // biblioteca de comunicaçao com o usuario
#include <stdlib.h> // biblioteca de alocaçao de espaço em mamoria
#include <locale.h> // biblioteca de alocaçoes de texto por regiao
#include <string.h> // biblioteca responsavel por cuidar das strings

int registro()
{
	char arquivo[40];
	char cpf[40];
	char nome[40];
	char sobrenome[40];
	char cargo[40];
	
	printf("digite seu cpf: ");
	scanf("%s", cpf); // %s refere-se a salvar uma string
	
	strcpy(arquivo,cpf); // responsavel por copiar os valores das strings
	
	FILE *file; // cria uma variavel para servir de ponteiro para arquivo, nesse caso o "file"
	file = fopen(arquivo, "w");// cria um arquivo e "w" indica que o abrirá para escrita
	fprintf(file,cpf);// "file" aponta que o conteudo do "cpf" deve ser escrito no arquivo, graças ao "w" acima
	fclose(file); // fechamento do arquivo
	
	file = fopen(arquivo,"a");
	fprintf(file,", ");
	fclose(file);
	
	printf("Nome: ");
	scanf("%s", nome);
	
	file = fopen(arquivo,"a");
	fprintf(file, nome);
	fclose(file);
	
	file = fopen(arquivo,"a");
	fprintf(file, ", ");
	fclose(file);
	
	printf("Sobrenome: ");
	scanf("%s", sobrenome);
	
	file = fopen(arquivo,"a");
	fprintf(file, sobrenome);
	fclose(file);
	
	file = fopen(arquivo,"a");
	fprintf(file, ", ");
	fclose(file);
	
	printf("Cargo: ");
	scanf("%s", cargo);
	
	file = fopen(arquivo,"a");
	fprintf(file, cargo);
	fclose(file);

	
	system("pause");
}

int consulta()
{
	setlocale(LC_ALL, "Portuguese");
	
	char cpf[40];
	char conteudo[200];
	
	printf("Digite o cpf a ser consultado: ");
	scanf("%s",cpf);
	
	FILE *file;
	file= fopen(cpf, "r");
	
	if(file==NULL)
	{
		printf("Cpf não encontrado.");
	}
	while(fgets(conteudo,200, file)  != NULL)
	{
		printf("\n Essas são as informações do usuário: ");
		printf("%s",conteudo);
		printf("\n");
	}
		system("pause");
}

int deletar()
{
	char cpf[40];
	
	printf("Digite o cpf a ser deletado: ");
	scanf("%s",cpf);
	
	remove(cpf);
	
	
	system("pause");
}

int main()
{
    int opcao = 0;
    int laco = 0;
    
    for(laco=1; laco=1;)
    {
		system("cls");
		setlocale(LC_ALL, "Portuguese");
    
		printf("\nEscolha a opção desejada no menu. \n\n");
    	printf("\t1ª:Registrar nomes.\n\n");
    	printf("\t2ª:Consultar nomes.\n\n");
    	printf("\t3ª:Deletar nomes.\n\n");
    	printf("\t4ª:Sair do sistema.\n\n");
		printf("Opção: ");
	
		scanf("%d", &opcao);
		system("cls");
    	
    	switch(opcao)
    	{
    		case 1:
    		registro();
    	    break;
    	    
			case 2:
    	   	consulta();
    		break;
    		
    		case 3:
    		deletar();
    		break;
    		
    		case 4:
    		printf("Obrigado por utilizar o sistema.\n\n");
    		system("pause");
    		return 0;
			break;
    		
    		
    		default:
    		printf("Essa opção não existe.");
			system("pause");
			break;
		}
		
    
	}
}

