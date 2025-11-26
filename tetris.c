#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <stdbool.h>

#define TAM_FILA 5   
typedef struct {
    char nome; 
    int id;    
} Peca;

Peca fila[TAM_FILA];
int inicio = 0;      
int fim = 0;         
int quantidade = 0;  
int proximoID = 0;   

Peca gerarPeca() {
    // Tipos possíveis de peça
    char tipos[] = {'I', 'O', 'T', 'L'};
    int indice = rand() % 4;

    Peca nova;
    nova.nome = tipos[indice];
    nova.id = proximoID++;

    return nova;
}

void inserirPeca() {
    if (quantidade == TAM_FILA) {
        printf("A fila está cheia! Não é possível inserir outra peça.\n");
        return;
    }

    Peca nova = gerarPeca();
    fila[fim] = nova;

    fim = (fim + 1) % TAM_FILA;
    quantidade++;

    printf("Peça inserida: [%c %d]\n", nova.nome, nova.id);
}

void jogarPeca() {
    if (quantidade == 0) {
        printf("A fila está vazia! Não há peça para jogar.\n");
        return;
    }

    Peca jogada = fila[inicio];

    inicio = (inicio + 1) % TAM_FILA;
    quantidade--;

    printf("Peça jogada: [%c %d]\n", jogada.nome, jogada.id);
}

void exibirFila() {
    printf("\n========== FILA DE PEÇAS ==========\n");

    if (quantidade == 0) {
        printf("Fila vazia!\n");
        return;
    }

    int i = inicio;
    for (int c = 0; c < quantidade; c++) {
        printf("[%c %d] ", fila[i].nome, fila[i].id);
        i = (i + 1) % TAM_FILA;
    }
    printf("\n===================================\n");
}

void exibirMenu() {
    printf("\n------ MENU DE AÇÕES ------\n");
    printf("1 - Jogar peça (dequeue)\n");
    printf("2 - Inserir nova peça (enqueue)\n");
    printf("0 - Sair\n");
    printf("Escolha: ");
}

int main() {
    srand(time(NULL));

    // Inicializa a fila com 5 peças
    for (int i = 0; i < TAM_FILA; i++) {
        inserirPeca();
    }

    int opcao;

    do {
        exibirFila();
        exibirMenu();
        scanf("%d", &opcao);

        switch (opcao) {
            case 1:
                jogarPeca();
                break;

            case 2:
                inserirPeca();
                break;

            case 0:
                printf("Encerrando o sistema...\n");
                break;

            default:
                printf("Opção inválida!\n");
        }

    } while (opcao != 0);

    return 0;
}
