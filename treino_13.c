#include <stdio.h>
#include <stdlib.h>

#define LIMITE_TABUADA 10

// Descarta o que sobrou no buffer do teclado
void limparBuffer() {
    int ch;
    while ((ch = getchar()) != '\n' && ch != EOF);
}

// Le um numero inteiro, protegido contra letra e fim da entrada
int lerInteiro() {
    int valor;
    int resultado;
    while (1) {
        printf("Digite um numero inteiro: ");
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
    int numero;
    int i;

    printf("=== TABUADA ===\n");
    numero = lerInteiro();

    printf("\nTabuada do %d:\n", numero);
    for (i = 1; i <= LIMITE_TABUADA; i++) {
        printf("%d x %2d = %d\n", numero, i, numero * i);
    }

    printf("\nPressione ENTER para sair...");
    getchar();
    return 0;
}
