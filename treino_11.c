#include <stdio.h>
#include <stdlib.h>

#define QTD_NUMEROS 10

// Descarta o que sobrou no buffer do teclado
void limparBuffer() {
    int ch;
    while ((ch = getchar()) != '\n' && ch != EOF);
}

// Le um numero decimal, protegido contra letra
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
    double maior, menor;
    int i;

    printf("=== MAIOR E MENOR DO VETOR ===\n");
    printf("Digite %d numeros:\n", QTD_NUMEROS);

    for (i = 0; i < QTD_NUMEROS; i++) {
        numeros[i] = lerNumero(i + 1);
    }

    // Comeca com o primeiro valor e compara com os demais
    maior = numeros[0];
    menor = numeros[0];
    for (i = 1; i < QTD_NUMEROS; i++) {
        if (numeros[i] > maior) {
            maior = numeros[i];
        }
        if (numeros[i] < menor) {
            menor = numeros[i];
        }
    }

    printf("\nVetor digitado:");
    for (i = 0; i < QTD_NUMEROS; i++) {
        printf(" %.2f", numeros[i]);
    }
    printf("\n");

    printf("Maior: %.2f\n", maior);
    printf("Menor: %.2f\n", menor);

    printf("\nPressione ENTER para sair...");
    getchar();
    return 0;
}
