#include <stdio.h>
#include <math.h>

int main() {
    double a, b, c, delta, x1, x2;
    double parteReal, parteImag;

    printf("=== EQUACAO DO 2o GRAU COMPLETA ===\n");
    printf("=== ax^2 + bx + c = 0 ===\n\n");

    printf("Digite a: ");
    scanf("%lf", &a);
    printf("Digite b: ");
    scanf("%lf", &b);
    printf("Digite c: ");
    scanf("%lf", &c);

    printf("\nEquacao: %.0fx^2 + %.0fx + %.0f = 0\n", a, b, c);
    printf("\n--- PASSO A PASSO ---\n");

    if (a == 0) {
        printf("ERRO: a=0, nao e equacao do 2o grau!\n");
        printf("Vira equacao do 1o grau: %.0fx + %.0f = 0\n", b, c);
        if (b != 0) {
            printf("x = %.2f\n", -c/b);
        }
        return 0;
    }

    printf("1) Delta = b^2 - 4ac\n");
    printf("   Delta = (%.0f)^2 - 4*%.0f*%.0f\n", b, a, c);

    delta = b*b - 4*a*c;
    printf("   Delta = %.2f - %.2f = %.2f\n", b*b, 4*a*c, delta);

    printf("\n2) Analise:\n");
    if (delta < 0) {
        printf("   Delta < 0 -> Duas raizes COMPLEXAS\n");
        printf("\n3) Bhaskara Complexa:\n");
        parteReal = -b / (2*a);
        parteImag = sqrt(-delta) / (2*a);
        printf("   sqrt(Delta) = sqrt(%.2f) = sqrt(%.2f)i = %.2fi\n", delta, -delta, sqrt(-delta));
        printf("   x1 = %.2f + %.2fi\n", parteReal, parteImag);
        printf("   x2 = %.2f - %.2fi\n", parteReal, parteImag);
        printf("\n--- RESULTADO FINAL (COMPLEXO) ---\n");
        printf("x1 = %.2f + %.2fi\n", parteReal, parteImag);
        printf("x2 = %.2f - %.2fi\n", parteReal, parteImag);

    } else if (delta == 0) {
        printf("   Delta = 0 -> Uma raiz REAL dupla\n");
        x1 = -b / (2*a);
        printf("\n3) Bhaskara: x = -b / 2a\n");
        printf("   x = %.2f / %.2f = %.2f\n", -b, 2*a, x1);
        printf("\n--- RESULTADO FINAL ---\n");
        printf("Raiz unica: x = %.2f\n", x1);

    } else {
        printf("   Delta > 0 -> Duas raizes REAIS\n");
        printf("\n3) Bhaskara: x = (-b +- sqrt(Delta)) / 2a\n");
        printf("   sqrt(Delta) = %.2f\n", sqrt(delta));

        x1 = (-b + sqrt(delta)) / (2*a);
        x2 = (-b - sqrt(delta)) / (2*a);

        printf("   x1 = (%.2f + %.2f) / %.2f = %.2f\n", -b, sqrt(delta), 2*a, x1);
        printf("   x2 = (%.2f - %.2f) / %.2f = %.2f\n", -b, sqrt(delta), 2*a, x2);

        printf("\n--- RESULTADO FINAL (REAL) ---\n");
        printf("x1 = %.2f\n", x1);
        printf("x2 = %.2f\n", x2);

        printf("\nPressione ENTER para sair...");
            int c;
            while ((c = getchar()) != '\n' && c != EOF);
            printf("\nPressione ENTER para sair...");
            getchar();

    }
    return 0;
}
