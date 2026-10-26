#include <stdio.h>

#define TAM_HISTORICO 100

// Descarta o que sobrou no buffer do teclado
void limparBuffer() {
    int ch;
    while ((ch = getchar()) != '\n' && ch != EOF);
}

// Le um numero real, protegido contra letra
double lerNumero(const char *texto) {
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

// Operacoes
double somar(double a, double b) {
    return a + b;
}

double subtrair(double a, double b) {
    return a - b;
}

double multiplicar(double a, double b) {
    return a * b;
}

double dividir(double a, double b) {
    return a / b;
}

// Mostra todos os resultados guardados no historico
void mostrarHistorico(double historico[], int qtd) {
    int i;
    printf("\n--- HISTORICO (%d resultado(s)) ---\n", qtd);
    if (qtd == 0) {
        printf("Nenhuma operacao realizada.\n");
        return;
    }
    for (i = 0; i < qtd; i++) {
        printf("%3d) %.2f\n", i + 1, historico[i]);
    }
}

int main() {
    double historico[TAM_HISTORICO];
    int qtd = 0;        // quantos resultados ja foram guardados
    int opcao;
    double a, b, resultado;

    while (1) {
        printf("\n=== CALCULADORA COM HISTORICO ===\n");
        printf("1 - Somar\n");
        printf("2 - Subtrair\n");
        printf("3 - Multiplicar\n");
        printf("4 - Dividir\n");
        printf("5 - Ver historico\n");
        printf("0 - Sair\n");
        printf("Escolha: ");

        if (scanf("%d", &opcao) != 1) {
            printf("Entrada invalida! Digite um numero do menu.\n");
            limparBuffer();
            continue;
        }

        if (opcao == 0) {
            break;
        }

        if (opcao == 5) {
            mostrarHistorico(historico, qtd);
            continue;
        }

        if (opcao < 1 || opcao > 4) {
            printf("Opcao invalida!\n");
            continue;
        }

        if (qtd >= TAM_HISTORICO) {
            printf("Historico cheio! Encerrando o programa.\n");
            break;
        }

        a = lerNumero("Digite o primeiro numero: ");
        b = lerNumero("Digite o segundo numero: ");

        if (opcao == 1) {
            resultado = somar(a, b);
            printf("%.2f + %.2f = %.2f\n", a, b, resultado);
        } else if (opcao == 2) {
            resultado = subtrair(a, b);
            printf("%.2f - %.2f = %.2f\n", a, b, resultado);
        } else if (opcao == 3) {
            resultado = multiplicar(a, b);
            printf("%.2f * %.2f = %.2f\n", a, b, resultado);
        } else {
            if (b == 0) {
                printf("Nao existe divisao por zero!\n");
                continue;
            }
            resultado = dividir(a, b);
            printf("%.2f / %.2f = %.2f\n", a, b, resultado);
        }

        // Guarda no vetor e avanca a posicao
        historico[qtd] = resultado;
        qtd++;
    }

    // Mostra o historico no final
    mostrarHistorico(historico, qtd);
    printf("\nAte mais!\n");
    return 0;
}
