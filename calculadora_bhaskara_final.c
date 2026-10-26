#include <stdio.h>
#include <math.h>

int main() {
    double a, b, c, delta, x1, x2;
    double parteReal, parteImag;
    int opcao = 1;
    int contador = 0;

    while (opcao != 0) {
        printf("\n========================================\n");
        printf("=== CALCULADORA BHASKARA - MENU ===\n");
        printf("========================================\n");
        printf("Equacoes calculadas: %d\n", contador);
        printf("1 - Calcular nova equacao\n");
        printf("0 - Sair do programa\n");
        printf("Escolha: ");
        scanf("%d", &opcao);

        if (opcao == 0) {
            printf("\nObrigado por usar! Total: %d equacoes.\n", contador);
            break;
        }

        if (opcao != 1) {
            printf("Opcao invalida!\n");
            continue;
        }

        contador++;
        printf("\n--- EQUACAO %d ---\n", contador);
        printf("Digite a: ");
        scanf("%lf", &a);
        printf("Digite b: ");
        scanf("%lf", &b);
        printf("Digite c: ");
        scanf("%lf", &c);

        printf("\nEquacao: %.0fx^2 + %.0fx + %.0f = 0\n", a, b, c);

        if (a == 0) {
            printf("Nao e do 2o grau!\n");
            continue;
        }

        delta = b*b - 4*a*c;
        printf("Delta = %.2f\n", delta);

        if (delta < 0) {
            parteReal = -b / (2*a);
            parteImag = sqrt(-delta) / (2*a);
            printf("RESULTADO COMPLEXO:\n");
            printf("x1 = %.2f + %.2fi\n", parteReal, parteImag);
            printf("x2 = %.2f - %.2fi\n", parteReal, parteImag);
        } else if (delta == 0) {
            x1 = -b / (2*a);
            printf("RESULTADO UNICO: x = %.2f\n", x1);
        } else {
            x1 = (-b + sqrt(delta)) / (2*a);
            x2 = (-b - sqrt(delta)) / (2*a);
            printf("RESULTADO REAL:\n");
            printf("x1 = %.2f\n", x1);
            printf("x2 = %.2f\n", x2);
        }
    }
    return 0;
}
