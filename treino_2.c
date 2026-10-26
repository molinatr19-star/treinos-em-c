#include <stdio.h>

// Descarta o que sobrou no buffer do teclado
void limpar_buffer() {
    int ch;
    while ((ch = getchar()) != '\n' && ch != EOF);
}

int main() {
    int opcao, numero, i;

    while (1) {
        printf("\n=============================\n");
        printf("       TABUADA COM MENU\n");
        printf("=============================\n");
        printf(" 1 - Ver tabuada de um numero\n");
        printf(" 0 - Sair\n");
        printf("=============================\n");
        printf("Escolha: ");

        // Protecao contra letra no menu
        if (scanf("%d", &opcao) != 1) {
            printf("Entrada invalida! Digite um numero.\n");
            limpar_buffer();
            continue;
        }

        if (opcao == 0) {
            printf("Saindo... ate mais!\n");
            break;
        } else if (opcao == 1) {
            printf("Digite um numero de 0 a 10: ");
            if (scanf("%d", &numero) != 1) {
                printf("Entrada invalida! Digite um numero.\n");
                limpar_buffer();
                continue;
            }
            if (numero < 0 || numero > 10) {
                printf("Numero fora do intervalo (0 a 10).\n");
                continue;
            }

            // Mostra a tabuada de 0 a 10
            printf("\n----- Tabuada do %d -----\n", numero);
            for (i = 0; i <= 10; i++) {
                printf("  %2d x %2d = %3d\n", numero, i, numero * i);
            }
            printf("------------------------\n");
        } else {
            printf("Opcao invalida!\n");
        }
    }

    return 0;
}
