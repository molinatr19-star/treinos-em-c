#include <stdio.h>

// Descarta o que sobrou no buffer do teclado
void limpar_buffer() {
    int ch;
    while ((ch = getchar()) != '\n' && ch != EOF);
}

// Le uma nota valida (0 a 10), repetindo ate o usuario acertar
double ler_nota(int numero) {
    double nota;
    while (1) {
        printf("Digite a nota %d: ", numero);
        if (scanf("%lf", &nota) != 1) {
            printf("Entrada invalida! Digite um numero.\n");
            limpar_buffer();
        } else if (nota < 0 || nota > 10) {
            printf("A nota deve estar entre 0 e 10.\n");
        } else {
            return nota;
        }
    }
}

int main() {
    double n1, n2, n3, media;
    int contador = 0;       // quantos alunos ja foram calculados
    char continuar;

    printf("=== CALCULADORA DE MEDIA ===\n");

    do {
        contador++;
        printf("\n--- Aluno %d ---\n", contador);

        n1 = ler_nota(1);
        n2 = ler_nota(2);
        n3 = ler_nota(3);

        // Media aritmetica das 3 notas
        media = (n1 + n2 + n3) / 3;
        printf("Media = (%.2f + %.2f + %.2f) / 3 = %.2f\n", n1, n2, n3, media);

        // Classificacao
        if (media >= 7) {
            printf("Resultado: APROVADO\n");
        } else if (media >= 5) {
            printf("Resultado: RECUPERACAO\n");
        } else {
            printf("Resultado: REPROVADO\n");
        }

        printf("\nCalcular outro aluno? (s/n): ");
        limpar_buffer();
        scanf("%c", &continuar);
    } while (continuar == 's' || continuar == 'S');

    printf("\nTotal de alunos calculados: %d\n", contador);

    printf("\nPressione ENTER para sair...");
    limpar_buffer();
    getchar();
    return 0;
}
