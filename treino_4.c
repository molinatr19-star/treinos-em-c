#include <stdio.h>

// Descarta o que sobrou no buffer do teclado
void limpar_buffer() {
    int ch;
    while ((ch = getchar()) != '\n' && ch != EOF);
}

// Le um numero real positivo, repetindo ate o usuario acertar
double ler_positivo(const char *texto) {
    double valor;
    while (1) {
        printf("%s", texto);
        if (scanf("%lf", &valor) != 1) {
            printf("Entrada invalida! Digite um numero.\n");
            limpar_buffer();
        } else if (valor <= 0) {
            printf("O valor deve ser maior que zero.\n");
        } else {
            return valor;
        }
    }
}

int main() {
    double peso, altura, imc;

    printf("=== CALCULADORA DE IMC ===\n\n");

    peso = ler_positivo("Digite o peso em kg (ex: 70.5): ");
    altura = ler_positivo("Digite a altura em metros (ex: 1.75): ");

    printf("\n--- PASSO A PASSO ---\n");
    printf("1) Formula: IMC = peso / (altura * altura)\n");
    printf("2) Substituindo: IMC = %.2f / (%.2f * %.2f)\n", peso, altura, altura);
    printf("3) Altura ao quadrado = %.4f\n", altura * altura);

    imc = peso / (altura * altura);
    printf("4) IMC = %.2f / %.4f = %.2f\n", peso, altura * altura, imc);

    printf("\n5) Classificacao:\n");
    if (imc < 18.5) {
        printf("   IMC < 18.5 -> MAGRO\n");
    } else if (imc < 25) {
        printf("   18.5 <= IMC < 25 -> NORMAL\n");
    } else if (imc < 30) {
        printf("   25 <= IMC < 30 -> SOBREPESO\n");
    } else {
        printf("   IMC >= 30 -> OBESO\n");
    }

    printf("\n--- RESULTADO FINAL ---\n");
    printf("IMC = %.2f\n", imc);

    printf("\nPressione ENTER para sair...");
    limpar_buffer();
    getchar();
    return 0;
}
