#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <conio.h>

typedef struct{
	int id;
	char titulo[100];
	char url[300];
	double data;
	int qtdAcesso;
} pagina;

typedef struct{
	pagina info;
	struct t_pilha *prox;
} t_pilha;

t_pilha *topo;
pagina dados;

int menu (){
	
	int opcao;
	
	printf("Historio Web \n\n");
	printf("1 - Inserir pagina no historico \n");
	printf("2 - Listar Historico LRU \n");
	printf("3 - Listar Historico LFU \n");
	printf("4 - Limpar Historicos \n");
	printf("5 - Sair \n\n");
	printf("Digite a opcao desejada ");
	scanf("%d", &opcao);
	printf("\n");
	system("pause");
	system("cls");
	
	return opcao;
}

int vazia(){
	
}

void inicializaPilha(){
	
}

double retorna_tempo(){
	
	time_t segundos;
	
	segundos = time(NULL);
	
	printf("%d", segundos);
	printf("\n");
	
	return segundos;
}

void lerDados(){
	
	printf("Lendo Dados da Pilha: \n\n ");
	printf("Id da Pagina: ");
	printf("%d", dados.id = rand() % 1000);
	printf("\n");
	printf(" Titulo da pagina: ");
	fflush(stdin);
	gets(dados.titulo);
	printf(" URL da pagina: ");
	fflush(stdin);
	gets(dados.url);
	printf(" Tempo de acesso: ");
	dados.data = retorna_tempo();
	printf(" Acessos: ");
	printf("%d", dados.qtdAcesso = dados.qtdAcesso + 1);
	printf("\n\n");
	system("pause");
	system("cls");
	
}

void insere_dados_pilha(pagina info){
	
}

void historicoLRU(pagina info){
	
}

void historicoLFU(pagina info){
	
}

void exibirLRU(){
	
}

void exibirLFU(){
	
}

int main(){
	
	int opcao;
	srand(time(NULL));
	
	inicializaPilha();
	
	do{
		
		opcao = menu();
		
		switch(opcao){
			case 1:
				lerDados();				
			break;
			case 2:
			break;
			case 3:
			break;
			case 4:
			break;
			default:
			break;
		}
		
	} while(opcao != 5);
}
