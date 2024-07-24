//transformar o código para receber uma string no lugar de número inteiro
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <locale.h>
#include <string.h>

//Estrutura cadastro produto
struct cadastro {
	char nome[30];
	int codigo;
};

// Definição da estrutura do nó
struct no {
    struct cadastro produto;
    struct no *prox;
};

typedef struct no *No;
No Lista;

// Prototipação
void inserir();
void remover();
void printList();
void menu();
void escolha(int opc);
void removerPilha();
void removerFila();

int main(void) {
    setlocale(LC_ALL, "Portuguese");
    srand(time(NULL));
    Lista = (No)malloc(sizeof(struct no));
    if (Lista == NULL) {
        printf("Erro de alocação de memória\n");
        return 1;
    }
    Lista->prox = NULL;

    int opcao;
    do {
        system("cls");
        printList();
        menu();
        printf("Digite sua opção: ");
        scanf("%d", &opcao);
        fflush(stdin);
        printf("\n");
        escolha(opcao);
    } while (opcao != 5);

    // Liberação de memória
    No temp;
    while (Lista != NULL) {
        temp = Lista;
        Lista = Lista->prox;
        free(temp);
    }

    return 0;
}

void inserir() {
    No temp = Lista;
    while (temp->prox != NULL) {
        temp = temp->prox;
    }

    temp->prox = (No)malloc(sizeof(struct no));
    if (temp->prox == NULL) {
        printf("Erro de alocação de memória\n");
        return;
    }
    temp = temp->prox;
    printf("Insira o código do produto: ");
    scanf("%d", &temp->produto.codigo);
    fflush(stdin);
    printf("Insira o nome do produto: ");
    gets(temp->produto.nome);
    fflush(stdin);
    temp->prox = NULL;
}

void remover() {
    char aux_nome[30];
    int aux_codigo;
    int aux_op;
    
    printf("Opção de remoção por:\n");
    printf("1 - Código\n");
    printf("2 - Nome\n");
    scanf("%d", &aux_op);
    fflush(stdin);
    
    switch(aux_op) {
    	case 1: 
    		printf("\nDigite o código do produto: ");
    		scanf("%d", &aux_codigo);
    	break;
    	case 2: 
    		printf("Digite o nome do produto: ");
    		gets(aux_nome);
    		fflush(stdin);
    	break;
    	default:
    		printf("\nOpção inválida!\n");
    		system("pause");
            remover();
    	break;
	}

    No antecessor = Lista;
    while (antecessor->prox != NULL) {
        No atual = antecessor->prox;
        if (strcmp(atual->produto.nome , aux_nome) == 0) {
            antecessor->prox = atual->prox;
            free(atual);
            printf( "\nO elemento %s foi removido da lista\n", aux_nome);
            system("pause");
            return;
        }
        else if (atual->produto.codigo == aux_codigo) {
        	antecessor->prox = atual->prox;
            free(atual);
            printf( "\nO elemento de código %d foi removido da lista\n", aux_codigo);
            system("pause");
            return;
		}
        antecessor = antecessor->prox;
    }
    system("cls");
    printf("O dado solicitado para remoção não se encontra na lista\n");
    system("pause");
}

void printList() {
    No temp = Lista->prox;
    if (temp == NULL) {
        printf("Lista Vazia\n");
        return;
    }

    printf("Estrutura de Dados - Lista Dinâmica\n");
    while (temp != NULL) {
        printf("%d - %s | ", temp->produto.codigo, temp->produto.nome);
        temp = temp->prox;
    }
   
}

void menu() {
    
    if (Lista->prox == NULL) {
	  printf("\n--------------------------------------");
      printf("\n\n1 - Inserir\n"); 
      printf("5 - Sair\n");
      return; 
    }
    printf("\n--------------------------------------");
    printf("\n1 - Inserir\n");
    printf("2 - Remover\n");
    printf("3 - Remover Pilha\n");
    printf("4 - Remover Fila\n");
    printf("5 - Sair\n");
}

void escolha(int opc) {
    if (Lista->prox == NULL) {
      switch (opc) {
        case 1:
            inserir();
            break;
        case 5:
            system("cls");
            printf("\n\nAplicação encerrada pelo usuário\n");
            break;
        default:
            system("cls");
            printf("Opção digitada inválida\n");
            system("pause");
            break;
        }    
            
      return; 
    }
    
    switch (opc) {
        case 1:
            inserir();
            break;
        case 2:
            remover();
            break;
        case 3:
            removerPilha();
            break;
            
            
        case 4:
            
            removerFila();
            
            break;
        case 5:
            system("cls");
            printf("\n\nAplicação encerrada pelo usuário\n");
            break;
        default:
            system("cls");
            printf("Opção digitada inválida\n");
            system("pause");
            break;
    }
}

void removerPilha() {
    No temp = Lista;
    while (temp->prox->prox != NULL) {
        temp = temp->prox;
    }

    No ultimo = temp->prox;
    temp->prox = NULL;
    free(ultimo);
}

void removerFila(){
        
    No primeiro = Lista->prox;
    Lista->prox = primeiro->prox;
    free(primeiro); 
    
}
