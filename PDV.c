#include <stdio.h>
#include <locale.h>
#include <ctype.h>
#define U 2

void salvarEmArquivo();

typedef struct{
	int cod;
	int quantidade;
	float unidade;
	char descricao[50];
}produto[U];

int main(void){
	
	setlocale(LC_ALL,"Portuguese");
	
	produto prod;
	//declaração de variaveis
	int i;
	char resposta;
	
	//printf("----------MENU----------");
	//printf("[1] CADASTRAR PRODUTO\n[2] CONSULTAR PRODUTO\n[3] SAIR");
	
	do{
		for(i = 0; i < U; i++){
			printf("Produto [%i]\n", i + 1);
			printf("Código..........: "); scanf("%d", &prod[i].cod);
			printf("Quantidade......: "); scanf("%d", &prod[i].quantidade);
			printf("R$ p/ unidade R$  "); scanf("%f", &prod[i].unidade);
			printf("Descrição.......: "); fflush(stdin); gets(prod[i].descricao);
			printf("---------------------------------------------------\n");
		}
		system("cls");
		//mostrar o relatorio
		for(i = 0; i < U; i++){
			printf("Produto [%i]\n", i + 1);
			printf("Código.........: %d\n", prod[i].cod);
			printf("Quantidade.....: %d\n", prod[i].quantidade);
			printf("R$ p/ unidade R$ %.2f\n", prod[i].unidade);
			printf("Descrição......: %s\n", prod[i].descricao);
			printf("---------------------------------------------------\n");
		}
		printf("Dados cadastrados ! Confirma os dados ? [S/N]: ");
		resposta = getchar();
		resposta = toupper(resposta);
		if(resposta == 'S'){
			salvarEmArquivo();
		}else{
			system("cls");
			printf("Por favor ! Insira novamente os dados.\n");
		}
	}while(resposta == 'N');
	
	
	printf("Está OK até aqui.");

	return 0;
}

void salvarEmArquivo(){
	int i;
	produto prod;
	FILE *arquivo = fopen("arquivo_produto.txt", "w");
	if(arquivo == NULL){
		printf("Não foi possível abrir o arquivo !");
	}else{
		for(i = 0; i < U; i++){
			fprintf(arquivo, "PRODUTOS DA NOTA FISCAL\n");
			fprintf(arquivo, "Código...........: %d\n", prod[i].cod);
			fprintf(arquivo, "Quantidade.......: %d\n", prod[i].quantidade);
			fprintf(arquivo, "R$ p/ unidade...R$ %.2f\n", prod[i].unidade);
			fprintf(arquivo, "Descrição........: %s/n",prod[i].descricao);
			fprintf(arquivo, "\n---------------------------------------------\n");
		}
		fclose(arquivo);
	}
	
}


