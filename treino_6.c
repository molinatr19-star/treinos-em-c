#include <stdio.h>

// Descarta o que sobrou no buffer do teclado
void limparBuffer() {
    int ch;
    while ((ch = getchar()) != '\n' && ch != EOF);
}

// Le um inteiro dentro de um intervalo, protegido contra letra
int lerInteiro(const char *texto, int minimo, int maximo) {
    int valor;
    while (1) {
        printf("%s", texto);
        if (scanf("%d", &valor) != 1) {
            printf("Entrada invalida! Digite um numero inteiro.\n");
            limparBuffer();
        } else if (valor < minimo || valor > maximo) {
            printf("Digite um valor entre %d e %d.\n", minimo, maximo);
        } else {
            return valor;
        }
    }
}

// Le uma nota de 0 a 10, protegida contra letra
double lerNota(int numero) {
    double nota;
    while (1) {
        printf("Nota do aluno %d: ", numero);
        if (scanf("%lf", &nota) != 1) {
            printf("Entrada invalida! Digite um numero.\n");
            limparBuffer();
        } else if (nota < 0 || nota > 10) {
            printf("A nota deve estar entre 0 e 10.\n");
        } else {
            return nota;
        }
    }
}

// Soma todas as notas e divide pela quantidade
double calcularMedia(double v[], int n) {
    double soma = 0;
    int i;
    for (i = 0; i < n; i++) {
        soma += v[i];
    }
    return soma / n;
}

// Percorre o vetor guardando a maior nota encontrada
double maiorNota(double v[], int n) {
    double maior = v[0];
    int i;
    for (i = 1; i < n; i++) {
        if (v[i] > maior) {
            maior = v[i];
        }
    }
    return maior;
}

// Percorre o vetor guardando a menor nota encontrada
double menorNota(double v[], int n) {
    double menor = v[0];
    int i;
    for (i = 1; i < n; i++) {
        if (v[i] < menor) {
            menor = v[i];
        }
    }
    return menor;
}

int main() {
    double notas[10];
    int quantidade, i;

    printf("=== VETOR DE NOTAS ===\n\n");

    quantidade = lerInteiro("Quantos alunos (1 a 10)? ", 1, 10);

    printf("\n");
    for (i = 0; i < quantidade; i++) {
        notas[i] = lerNota(i + 1);
    }

    printf("\n--- RESULTADO DA TURMA ---\n");
    printf("Notas digitadas: ");
    for (i = 0; i < quantidade; i++) {
        printf("%.2f ", notas[i]);
    }
    printf("\n");
    printf("Media da turma: %.2f\n", calcularMedia(notas, quantidade));
    printf("Maior nota:     %.2f\n", maiorNota(notas, quantidade));
    printf("Menor nota:     %.2f\n", menorNota(notas, quantidade));

    printf("\nPressione ENTER para sair...");
    limparBuffer();
    getchar();
    return 0;
}
