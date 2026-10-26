#include <stdio.h>
#include <math.h>

// Descarta o que sobrou no buffer do teclado
void limpar_buffer() {
    int ch;
    while ((ch = getchar()) != '\n' && ch != EOF);
}

// Le um numero real, repetindo ate o usuario digitar algo valido
double ler_coef(const char *texto) {
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
    int total, i;
    int qtd_reais = 0, qtd_complexas = 0, qtd_invalidas = 0;
    double a, b, c, delta, x1, x2, raiz, parte_real, parte_imag;

    printf("=== EQUACAO DO 2o GRAU TURBINADA ===\n\n");

    // Pergunta quantas equacoes serao resolvidas
    while (1) {
        printf("Quantas equacoes deseja resolver? ");
        if (scanf("%d", &total) != 1) {
            printf("Entrada invalida! Digite um numero inteiro.\n");
            limpar_buffer();
        } else if (total < 1) {
            printf("Digite pelo menos 1.\n");
        } else {
            break;
        }
    }

    for (i = 1; i <= total; i++) {
        printf("\n=============================\n");
        printf("   EQUACAO %d de %d\n", i, total);
        printf("=============================\n");

        a = ler_coef("Digite a: ");
        b = ler_coef("Digite b: ");
        c = ler_coef("Digite c: ");

        printf("\nEquacao: %.2fx^2 + %.2fx + %.2f = 0\n", a, b, c);
        printf("\n--- PASSO A PASSO ---\n");

        if (a == 0) {
            printf("Nao e do 2o grau (a=0)\n");
            qtd_invalidas++;
            continue;
        }

        printf("1) Formula do Delta: b^2 - 4ac\n");
        printf("   Delta = (%.2f)^2 - 4*(%.2f)*(%.2f)\n", b, a, c);

        delta = b * b - 4 * a * c;
        printf("   Delta = %.2f - (%.2f) = %.2f\n", b * b, 4 * a * c, delta);

        printf("\n2) Analise do Delta:\n");
        if (delta < 0) {
            // Raizes complexas: parte real +- parte imaginaria
            printf("   Delta < 0 -> Raizes complexas\n");
            qtd_complexas++;

            parte_real = -b / (2 * a);
            parte_imag = sqrt(-delta) / (2 * a);
            if (parte_imag < 0) {
                parte_imag = -parte_imag;
            }

            printf("\n3) Bhaskara: x = (-b +- i*sqrt(-Delta)) / 2a\n");
            printf("   sqrt(-Delta) = sqrt(%.2f) = %.2f\n", -delta, sqrt(-delta));

            printf("\n--- RESULTADO FINAL ---\n");
            printf("x1 = %.2f + %.2fi\n", parte_real, parte_imag);
            printf("x2 = %.2f - %.2fi\n", parte_real, parte_imag);
        } else if (delta == 0) {
            printf("   Delta = 0 -> Uma raiz real\n");
            qtd_reais++;

            x1 = -b / (2 * a);
            printf("\n3) Bhaskara: x = -b / 2a\n");
            printf("   x = %.2f / %.2f = %.2f\n", -b, 2 * a, x1);

            printf("\n--- RESULTADO FINAL ---\n");
            printf("x = %.2f\n", x1);
        } else {
            printf("   Delta > 0 -> Duas raizes reais\n");
            qtd_reais++;

            raiz = sqrt(delta);
            printf("\n3) Bhaskara: x = (-b +- sqrt(Delta)) / 2a\n");
            printf("   sqrt(Delta) = sqrt(%.2f) = %.2f\n", delta, raiz);

            x1 = (-b + raiz) / (2 * a);
            x2 = (-b - raiz) / (2 * a);

            printf("\n   x1 = (%.2f + %.2f) / %.2f = %.2f\n", -b, raiz, 2 * a, x1);
            printf("   x2 = (%.2f - %.2f) / %.2f = %.2f\n", -b, raiz, 2 * a, x2);

            printf("\n--- RESULTADO FINAL ---\n");
            printf("x1 = %.2f\n", x1);
            printf("x2 = %.2f\n", x2);
        }
    }

    // Relatorio final
    printf("\n=============================\n");
    printf("        RELATORIO FINAL\n");
    printf("=============================\n");
    printf("Total de equacoes:      %d\n", total);
    printf("Com raizes reais:       %d\n", qtd_reais);
    printf("Com raizes complexas:   %d\n", qtd_complexas);
    printf("Invalidas (a = 0):      %d\n", qtd_invalidas);
    printf("=============================\n");

    printf("\nPressione ENTER para sair...");
    limpar_buffer();
    getchar();
    return 0;
}
