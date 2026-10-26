#include <stdio.h>
#include <stdlib.h>

#define QTD_NUMEROS 5

// Descarta o que sobrou no buffer do teclado
void limparBuffer() {
    int ch;
    while ((ch = getchar()) != '\n' && ch != EOF);
}

// Le um numero decimal, protegido contra letra e fim da entrada
double lerNumero(int posicao) {
    double valor;
    int resultado;
    while (1) {
        printf("Numero %d: ", posicao);
        resultado = scanf("%lf", &valor);
        if (resultado == EOF) {
            // Fim da entrada: sem isso o programa ficaria em loop infinito
            printf("\nEntrada encerrada antes do fim. Programa finalizado.\n");
            exit(1);
        }
        if (resultado != 1) {
            printf("Entrada invalida! Digite um numero.\n");
            limparBuffer();
        } else {
            limparBuffer();
            return valor;
        }
    }
}

int main() {
    double numeros[QTD_NUMEROS];
    double soma = 0;
    double media;
    int i;

    printf("=== SOMA E MEDIA ===\n");
    printf("Digite %d numeros:\n", QTD_NUMEROS);

    for (i = 0; i < QTD_NUMEROS; i++) {
        numeros[i] = lerNumero(i + 1);
        soma += numeros[i];
    }

    // Media aritmetica simples: soma dividida pela quantidade
    media = soma / QTD_NUMEROS;

    printf("\nNumeros digitados:");
    for (i = 0; i < QTD_NUMEROS; i++) {
        printf(" %.2f", numeros[i]);
    }
    printf("\n");

    printf("Soma: %.2f\n", soma);
    printf("Media: %.2f\n", media);

    printf("\nPressione ENTER para sair...");
    getchar();
    return 0;
}
