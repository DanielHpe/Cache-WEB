#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <conio.h>
#include <string.h>
#include <stdBool.h>

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

t_pilha *top;
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
	printf("Digite a opcao desejada: ");
	scanf("%d", &opcao);
	printf("\n");
	system("pause");
	system("cls");
	
	return opcao;
}

int vazia(){
	return (topo == NULL ? 1 : 0);
}

void inicializaPilha(){
	topo = malloc(sizeof(t_pilha));
	topo = NULL;
}

void inicializaStack(){
	top = malloc(sizeof(t_pilha));
	top = NULL;
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
	printf("www.");
	gets(dados.url);
	printf(" Tempo de acesso: ");
	dados.data = retorna_tempo();
	printf(" Acessos: ");
	printf("%d", dados.qtdAcesso = dados.qtdAcesso + 1);
	printf("\n");
	
}

/* void historicoLFU(pagina info){
	
	char vetorPag[10][100]; //Vetor que guarda páginas salvas
	int cont = 0; //Contadores
	t_pilha *elemento = malloc(sizeof(t_pilha)); //Alocando memória
	t_pilha *antecessor = malloc(sizeof(t_pilha)); //Ponteiro para controlar a página atualizada
	
	elemento->info = info; //Ponteiro elemento do tipo t_pilha recebe info (dados)
	elemento->prox = topo; //Ponteiro prox de elemento aponta para o topo (Que caso, a lista esteja vazia, aponta para NULL)
	topo = elemento; //Topo aponta para elemento (Que se tornará o topo da pilha

	printf("\nElemento inserido com sucesso!"); 
		
	printf("\n\n");
	system("pause");
	system("cls");

} */

/* bool existe(char vetor[], int contador){
	t_pilha *aux = topo;
	int novoCont;
	
	while(aux->prox != NULL){
		for(novoCont = 0; novoCont < contador; novoCont++){
			if(!strcmp(aux->info.titulo, vetor[novoCont]))
			{ //Percorre a pilha e verifica se titulo ja existe
				return true; 
			}
		}
	}
} */

void historicoLRU(pagina info){
	
	bool existencia;
	int achou;
	int cont; //Contador para contar o número de elementos da Pilha
	t_pilha *elemento = malloc(sizeof(t_pilha)); //Alocando memória
	t_pilha *antecessor = malloc(sizeof(t_pilha));

	elemento->info = info; //Ponteiro elemento do tipo t_pilha recebe info (dados)
	elemento->prox = topo; //Ponteiro prox de elemento aponta para o topo (Que caso, a lista esteja vazia, aponta para NULL)
	topo = elemento; //Topo aponta para elemento (Que se tornará o topo da pilha)

	printf("\nElemento inserido com sucesso!\n"); 
	
	while (elemento->prox != NULL) {
		antecessor = elemento;
		elemento = elemento->prox;
		if (!strcmp(topo->info.url, elemento->info.url)) { // achou o nó
			antecessor->prox = elemento->prox;
			free(elemento);	
			break;
		}
	}
	
	removerLRU();

	printf("\n\n");
	system("pause");
	system("cls");		
		
}


void removerLRU(){
	
	t_pilha *aux = malloc(sizeof(t_pilha));
	t_pilha *controle = malloc(sizeof(t_pilha));
	t_pilha *antecessor = malloc(sizeof(t_pilha));
	t_pilha *auxiliar = malloc(sizeof(t_pilha));
	int cont = 0;
	int contador = 1;
	
	aux = topo;
	controle = topo;
	
	/* while (aux != NULL){
		cont++;
		aux = aux->prox;
		if(cont == 4){
			while(controle->prox != NULL){
				antecessor = controle;
				controle = controle->prox;
				if(controle->info.data < antecessor->info.data){
					antecessor->prox = controle->prox;
					break;
				}	
			}
			free(controle);
			printf("\nElemento removido com sucesso!");
		}
		
		printf("\n\n");
		system("pause");
		system("cls");	
	} */
	
	while(aux != NULL){
		cont++;
		aux = aux->prox;
		if(cont == 11){
			while (controle->prox != NULL){
				antecessor = controle;
				controle = controle->prox;
			}
			
			antecessor->prox = controle->prox;
			free(controle);
			
		}
	} 
	
	if(cont > 10){
		
		printf("\n++++++ ELEMENTO REMOVIDO ++++++\n");
		
		printf("\n Id.: %d\n", controle->info.id);
		printf(" Titulo.: %s\n", controle->info.titulo);
		printf(" URL: www.%s\n", controle->info.url);
		printf(" Tempo.: %d\n", controle->info.data);
		printf(" Acessos.: %d", controle->info.qtdAcesso);
		printf("\n");
		
	}
}

void limparPilha(){
	
	t_pilha *aux = malloc(sizeof(t_pilha));
	
	/* if(topo == NULL){
		printf("\n\nPilha Vazia !");
		return;
	}
	else{
		aux = topo;
		topo = topo->prox;
	} */
	
	while(topo != NULL){
		aux = topo;
		topo = topo->prox;
		free(aux);
	}
	
	printf("\n\nPilha Destruida");
	
	printf("\n\n");
	system("pause");
	system("cls");	
	
}

void exibirLRU(){
	
	t_pilha *aux = topo;
	t_pilha *auxx = top;
	 
	if(aux == NULL){
		printf("Pilha Vazia\n\n");
		printf("\n\n");
		system("pause");
		system("cls");
		return;
	}
	else{
		
		printf("\n++++++ TODOS OS ELEMENTOS ++++++\n");
						
		while (aux != NULL) 
		{
			printf("\n Id.: %d\n", aux->info.id);
			printf(" Titulo.: %s\n", aux->info.titulo);
			printf(" URL: www.%s\n", aux->info.url);
			printf(" Tempo.: %d\n", aux->info.data);
			printf(" Acessos.: %d", aux->info.qtdAcesso);
			printf("\n");
			aux = aux->prox; //Aponta pro proximo elemento
		}
		
	}
	
	/* while (auxx != NULL) 
	{
		printf("\n Id.: %d\n", auxx->info.id);
		printf(" Titulo.: %s\n", auxx->info.titulo);
		printf(" URL: www.%s\n", auxx->info.url);
		printf(" Tempo.: %d\n", auxx->info.data);
		printf(" Acessos.: %d", auxx->info.qtdAcesso);
		printf("\n");
		auxx = auxx->prox; //Aponta pro proximo elemento
	} */
	
	/* printf("\n++++++ ELEMENTO ++++++\n");
	
	printf("\n Id.: %d\n", antecessor->info.id);
	printf(" Titulo.: %s\n", antecessor->info.titulo);
	printf(" URL: www.%s\n", antecessor->info.url);
	printf(" Tempo.: %d\n", antecessor->info.data);
	printf(" Acessos.: %d", antecessor->info.qtdAcesso);
	printf("\n"); */
	 	
	 	
	printf("\n\n");
	system("pause");
	system("cls");
	
}

void exibirLFU(){
	
}

int main(){
	
	int opcao;
	srand(time(NULL));
	
	inicializaPilha();
	inicializaStack();
	
	do{
		
		opcao = menu();
		
		switch(opcao){
			case 1:
				lerDados();
				historicoLRU(dados);
			//	historicoLFU(dados);
				break;
			case 2:
				exibirLRU();
				break;
			case 3:
			break;
			case 4:
				limparPilha();
				break;
			default:
			break;
		}
		
	} while(opcao != 5);
}
