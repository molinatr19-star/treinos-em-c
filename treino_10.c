#include <stdio.h>
#include <string.h>

#define QTD_ALUNOS 3

// Estrutura que representa um aluno
struct Aluno {
    char nome[50];
    double nota1, nota2;
    double media;
};

// Descarta o que sobrou no buffer do teclado
void limparBuffer() {
    int ch;
    while ((ch = getchar()) != '\n' && ch != EOF);
}

// Le uma nota de 0 a 10, protegida contra letra
double lerNota(const char *texto) {
    double nota;
    while (1) {
        printf("%s", texto);
        if (scanf("%lf", &nota) != 1) {
            printf("Entrada invalida! Digite um numero.\n");
            limparBuffer();
        } else if (nota < 0 || nota > 10) {
            printf("A nota deve estar entre 0 e 10.\n");
        } else {
            // Limpa o ENTER que sobrou, para o proximo fgets funcionar
            limparBuffer();
            return nota;
        }
    }
}

int main() {
    struct Aluno alunos[QTD_ALUNOS];
    int i;
    size_t tamanho;

    printf("=== CADASTRO DE ALUNOS ===\n");

    for (i = 0; i < QTD_ALUNOS; i++) {
        printf("\n--- Aluno %d ---\n", i + 1);

        printf("Nome: ");
        fgets(alunos[i].nome, sizeof(alunos[i].nome), stdin);

        // Remove o \n que o fgets deixa no final do nome
        tamanho = strlen(alunos[i].nome);
        if (tamanho > 0 && alunos[i].nome[tamanho - 1] == '\n') {
            alunos[i].nome[tamanho - 1] = '\0';
        }

        alunos[i].nota1 = lerNota("Nota 1: ");
        alunos[i].nota2 = lerNota("Nota 2: ");

        // Calcula a media do aluno
        alunos[i].media = (alunos[i].nota1 + alunos[i].nota2) / 2;
    }

    printf("\n=== LISTA DE ALUNOS ===\n");
    printf("%-20s %6s %6s %7s  %s\n", "Nome", "Nota1", "Nota2", "Media", "Situacao");
    for (i = 0; i < QTD_ALUNOS; i++) {
        printf("%-20s %6.2f %6.2f %7.2f  %s\n",
               alunos[i].nome,
               alunos[i].nota1,
               alunos[i].nota2,
               alunos[i].media,
               alunos[i].media >= 7 ? "PASSOU" : "NAO PASSOU");
    }

    printf("\nPassaram (media >= 7):\n");
    int passaram = 0;
    for (i = 0; i < QTD_ALUNOS; i++) {
        if (alunos[i].media >= 7) {
            printf("- %s (%.2f)\n", alunos[i].nome, alunos[i].media);
            passaram++;
        }
    }
    if (passaram == 0) {
        printf("Ninguem passou.\n");
    }

    printf("\nPressione ENTER para sair...");
    getchar();
    return 0;
}
