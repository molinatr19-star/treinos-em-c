#include <stdio.h>
#include <math.h>

// Descarta o que sobrou no buffer do teclado
void limparBuffer() {
    int ch;
    while ((ch = getchar()) != '\n' && ch != EOF);
}

// Le um numero real, protegido contra letra
double lerCoeficiente(const char *texto) {
    double valor;
    while (1) {
        printf("%s", texto);
        if (scanf("%lf", &valor) == 1) {
            return valor;
        }
        printf("Entrada invalida! Digite um numero.\n");
        limparBuffer();
    }
}

// Calcula o delta: b^2 - 4ac
double calculaDelta(double a, double b, double c) {
    return b * b - 4 * a * c;
}

// Calcula as raizes reais e devolve nos ponteiros x1 e x2
// Retorna a quantidade de raizes reais pelo ponteiro qtd (0, 1 ou 2)
void calculaRaizes(double a, double b, double delta, double *x1, double *x2, int *qtd) {
    if (delta < 0) {
        *qtd = 0;
    } else if (delta == 0) {
        *qtd = 1;
        *x1 = -b / (2 * a);
        *x2 = *x1;
    } else {
        *qtd = 2;
        *x1 = (-b + sqrt(delta)) / (2 * a);
        *x2 = (-b - sqrt(delta)) / (2 * a);
    }
}

// Mostra todo o passo a passo e o resultado final
void mostraPassoAPasso(double a, double b, double c) {
    double delta, x1 = 0, x2 = 0;
    int qtd;

    printf("\nEquacao: %.2fx^2 + %.2fx + %.2f = 0\n", a, b, c);
    printf("\n--- PASSO A PASSO ---\n");

    if (a == 0) {
        printf("Nao e do 2o grau (a=0)\n");
        return;
    }

    printf("1) Formula do Delta: b^2 - 4ac\n");
    printf("   Delta = (%.2f)^2 - 4*(%.2f)*(%.2f)\n", b, a, c);
    delta = calculaDelta(a, b, c);
    printf("   Delta = %.2f - (%.2f) = %.2f\n", b * b, 4 * a * c, delta);

    printf("\n2) Analise do Delta:\n");
    calculaRaizes(a, b, delta, &x1, &x2, &qtd);

    if (qtd == 0) {
        printf("   Delta < 0 -> Nao tem raiz real\n");
    } else if (qtd == 1) {
        printf("   Delta = 0 -> Uma raiz real\n");
        printf("\n3) Bhaskara: x = -b / 2a\n");
        printf("   x = %.2f / %.2f = %.2f\n", -b, 2 * a, x1);
        printf("\n--- RESULTADO FINAL ---\n");
        printf("x = %.2f\n", x1);
    } else {
        printf("   Delta > 0 -> Duas raizes reais\n");
        printf("\n3) Bhaskara: x = (-b +- sqrt(Delta)) / 2a\n");
        printf("   sqrt(Delta) = sqrt(%.2f) = %.2f\n", delta, sqrt(delta));
        printf("\n   x1 = (%.2f + %.2f) / %.2f = %.2f\n", -b, sqrt(delta), 2 * a, x1);
        printf("   x2 = (%.2f - %.2f) / %.2f = %.2f\n", -b, sqrt(delta), 2 * a, x2);
        printf("\n--- RESULTADO FINAL ---\n");
        printf("x1 = %.2f\n", x1);
        printf("x2 = %.2f\n", x2);
    }
}

// Pede os coeficientes e chama o passo a passo
void resolverEquacao() {
    double a, b, c;
    a = lerCoeficiente("Digite a: ");
    b = lerCoeficiente("Digite b: ");
    c = lerCoeficiente("Digite c: ");
    mostraPassoAPasso(a, b, c);
}

// Main so tem o menu
int main() {
    int opcao;

    while (1) {
        printf("\n=== BHASKARA COM FUNCOES ===\n");
        printf("1 - Resolver equacao do 2o grau\n");
        printf("0 - Sair\n");
        printf("Escolha: ");

        if (scanf("%d", &opcao) != 1) {
            printf("Entrada invalida! Digite 0 ou 1.\n");
            limparBuffer();
            continue;
        }

        if (opcao == 1) {
            resolverEquacao();
        } else if (opcao == 0) {
            printf("Saindo...\n");
            break;
        } else {
            printf("Opcao invalida!\n");
        }
    }

    return 0;
}
