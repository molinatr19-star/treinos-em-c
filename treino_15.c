#include <stdio.h>
#include <stdlib.h>

#define TAMANHO 3

// Descarta o que sobrou no buffer do teclado
void limparBuffer() {
    int ch;
    while ((ch = getchar()) != '\n' && ch != EOF);
}

// Le um numero inteiro, protegido contra letra e fim da entrada
int lerInteiro(int linha, int coluna) {
    int valor;
    int resultado;
    while (1) {
        printf("Elemento [%d][%d]: ", linha + 1, coluna + 1);
        resultado = scanf("%d", &valor);
        if (resultado == EOF) {
            // Fim da entrada: sem isso o programa ficaria em loop infinito
            printf("\nEntrada encerrada antes do fim. Programa finalizado.\n");
            exit(1);
        }
        if (resultado != 1) {
            printf("Entrada invalida! Digite um numero inteiro.\n");
            limparBuffer();
        } else {
            limparBuffer();
            return valor;
        }
    }
}

int main() {
    int matriz[TAMANHO][TAMANHO];
    long long soma = 0; // long long evita estouro com valores grandes
    int i;
    int j;

    printf("=== SOMA DA DIAGONAL PRINCIPAL ===\n");
    for (i = 0; i < TAMANHO; i++) {
        for (j = 0; j < TAMANHO; j++) {
            matriz[i][j] = lerInteiro(i, j);
        }
    }

    printf("\nMatriz digitada:\n");
    for (i = 0; i < TAMANHO; i++) {
        for (j = 0; j < TAMANHO; j++) {
            printf("%6d", matriz[i][j]);
        }
        printf("\n");
    }

    // Diagonal principal: elementos em que linha == coluna
    for (i = 0; i < TAMANHO; i++) {
        soma += matriz[i][i];
    }

    printf("\nSoma da diagonal principal: %lld\n", soma);

    printf("\nPressione ENTER para sair...");
    getchar();
    return 0;
}
