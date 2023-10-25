#include <stdio.h>
#include <stdlib.h>
#include <time.h>

//declaração de estruturas

struct no {
	int numero;
	struct no *esquerda;
	struct no *direita;
};

//funcao que insere um no na arvore

struct no *inserir(struct no *raiz, int numero) {
	if (raiz == NULL) {
		raiz = (struct no *) malloc(sizeof(struct no));
		raiz -> numero = numero;
		raiz -> esquerda = NULL;
		raiz -> direita = NULL;
	}else {
		if (numero < raiz -> numero) {
			raiz -> esquerda = inserir(raiz -> esquerda, numero);
		}else if (numero > raiz -> numero){
			raiz -> direita = inserir(raiz -> direita, numero);
		}
	}
	return raiz;
}

//funcao que busca um no na arvore

void buscar(struct no *raiz, int numero) {
	if (raiz == NULL) {
		printf("Nao achei!!!");
	}else if (raiz -> numero == numero) {
		printf("Achei porra!!");
	}else if (numero < raiz -> numero) {
		buscar(raiz -> esquerda, numero);
	}else {
		buscar(raiz -> direita, numero);
	}
}

//funcao que navega a arvore em ordem

void navegar(struct no *raiz) {
	if (raiz != NULL) {
		navegar(raiz -> esquerda);
		printf("%d\t", raiz -> numero);
		navegar(raiz -> direita);
	}
}

//funcao em desenha um menu na tela

int menu(){
	int opcao;
	
	printf("\n");
	printf("+=====================================+\n");
	printf("|           MENU DE OPCOES            |\n");
	printf("+=====================================+\n");
	printf("| 1- Inseir                           |\n");
	printf("| 2- Buscar                           |\n");
	printf("| 3- Navegar                          |\n");
	printf("| 4- Construir Arvore Aleatoriamente  |\n");
	printf("| 5- Sair                             |\n");
	printf("+=====================================+\n");
	printf("Digite sua opcao: ");
	scanf("%d", &opcao);
	
	return opcao;
}

int main(){
	//declaraçao de var
	struct no *raiz = NULL;
	int opcao = 0;
	int numero = 0;
	int i = 0;
	
	//inicializacao da aleatoriedade
	time_t t;
	srand((unsigned) time(&t));
	
	//manipulação da arvore
	while (opcao != 5) {
		opcao = menu();
		switch (opcao) {
			case 1: 
				printf("Digite o numero: ");
				scanf("%d", &numero);
				raiz = inserir(raiz, numero);
				break;
			case 2:
				printf("Digite o numero: ");
				scanf("%d", &numero);
				buscar(raiz, numero);
				break;
			case 3:
				navegar(raiz);
				break;
			case 4:
				for (i = 0; i < 100000000000; i++) {
					raiz = inserir(raiz, rand());
				}
				break;
		}
	}
}
