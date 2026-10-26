#include <stdio.h>

// Descarta o que sobrou no buffer do teclado (evita loop infinito com letra)
void limpar_buffer() {
    int ch;
    while ((ch = getchar()) != '\n' && ch != EOF);
}

// Le um numero real, repetindo ate o usuario digitar algo valido
double ler_valor(const char *texto) {
    double valor;
    while (1) {
        printf("%s", texto);
        if (scanf("%lf", &valor) == 1) {
            return valor;
        }
        printf("Entrada invalida! Digite um numero.\n");
        limpar_buffer();
    }
}

int main() {
    int opcao;
    double c, f;

    while (1) {
        printf("\n=== CONVERSOR DE TEMPERATURA ===\n");
        printf("1 - Celsius para Fahrenheit\n");
        printf("2 - Fahrenheit para Celsius\n");
        printf("0 - Sair\n");
        printf("Escolha: ");

        // Se o usuario digitar letra, scanf falha e o buffer precisa ser limpo
        if (scanf("%d", &opcao) != 1) {
            printf("Entrada invalida! Digite 0, 1 ou 2.\n");
            limpar_buffer();
            continue;
        }

        if (opcao == 0) {
            printf("Saindo...\n");
            break;
        } else if (opcao == 1) {
            c = ler_valor("Digite a temperatura em Celsius: ");
            f = c * 1.8 + 32;
            printf("F = C * 1.8 + 32\n");
            printf("F = %.2f * 1.8 + 32 = %.2f\n", c, f);
            printf("Resultado: %.2f C = %.2f F\n", c, f);
        } else if (opcao == 2) {
            f = ler_valor("Digite a temperatura em Fahrenheit: ");
            c = (f - 32) / 1.8;
            printf("C = (F - 32) / 1.8\n");
            printf("C = (%.2f - 32) / 1.8 = %.2f\n", f, c);
            printf("Resultado: %.2f F = %.2f C\n", f, c);
        } else {
            printf("Opcao invalida!\n");
        }
    }

    return 0;
}
