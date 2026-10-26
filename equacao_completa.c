#include <stdio.h>
#include <math.h>

int main() {
    double a, b, c, delta, x1, x2;

    printf("=== EQUACAO DO 2o GRAU: ax^2 + bx + c = 0 ===\n\n");

    printf("Digite a: ");
    scanf("%lf", &a);
    printf("Digite b: ");
    scanf("%lf", &b);
    printf("Digite c: ");
    scanf("%lf", &c);

    printf("\nEquacao: %.0fx^2 + %.0fx + %.0f = 0\n", a, b, c);
    printf("\n--- PASSO A PASSO ---\n");

    if (a == 0) {
        printf("Nao e do 2o grau (a=0)\n");
        return 0;
    }

    printf("1) Formula do Delta: b^2 - 4ac\n");
    printf("   Delta = (%.0f)^2 - 4*%.0f*%.0f\n", b, a, c);

    delta = b*b - 4*a*c;
    printf("   Delta = %.2f - (%.2f) = %.2f\n", b*b, 4*a*c, delta);

    printf("\n2) Analise do Delta:\n");
    if (delta < 0) {
        printf("   Delta < 0 -> Nao tem raiz real\n");
    } else if (delta == 0) {
        printf("   Delta = 0 -> Uma raiz real\n");
        x1 = -b / (2*a);
        printf("\n3) Bhaskara: x = -b / 2a\n");
        printf("   x = %.2f / %.2f = %.2f\n", -b, 2*a, x1);
    } else {
        printf("   Delta > 0 -> Duas raizes reais\n");
        printf("\n3) Bhaskara: x = (-b +- sqrt(Delta)) / 2a\n");
        printf("   sqrt(Delta) = sqrt(%.2f) = %.2f\n", delta, sqrt(delta));

        x1 = (-b + sqrt(delta)) / (2*a);
        x2 = (-b - sqrt(delta)) / (2*a);

        printf("\n   x1 = (-(%.0f) + %.2f) / %.2f = %.2f\n", b, sqrt(delta), 2*a, x1);
        printf("   x2 = (-(%.0f) - %.2f) / %.2f = %.2f\n", b, sqrt(delta), 2*a, x2);

        printf("\n--- RESULTADO FINAL ---\n");
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
