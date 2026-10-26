#include <stdio.h>
#include <stdlib.h>

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

// Retorna 1 se o numero for primo, 0 caso contrario
int ehPrimo(int n) {
    long long i; // long long evita estouro de i * i com n perto de INT_MAX
    if (n < 2) {
        return 0;
    }
    // Basta testar divisores ate a raiz quadrada de n
    for (i = 2; i * i <= n; i++) {
        if (n % i == 0) {
            return 0;
        }
    }
    return 1;
}

int main() {
    int numero;

    printf("=== VERIFICADOR DE PRIMO ===\n");
    numero = lerInteiro();

    if (ehPrimo(numero)) {
        printf("%d e primo.\n", numero);
    } else {
        printf("%d nao e primo.\n", numero);
    }

    printf("\nPressione ENTER para sair...");
    getchar();
    return 0;
}
