#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_TENTATIVAS 7

// Descarta o que sobrou no buffer do teclado
void limparBuffer() {
    int ch;
    while ((ch = getchar()) != '\n' && ch != EOF);
}

// Joga uma partida. Retorna 1 se o jogador acertou, 0 se perdeu
int jogarPartida() {
    int secreto, palpite, tentativa;

    // Sorteia numero de 1 a 100
    secreto = rand() % 100 + 1;

    printf("\nPensei em um numero de 1 a 100. Voce tem %d tentativas!\n", MAX_TENTATIVAS);

    for (tentativa = 1; tentativa <= MAX_TENTATIVAS; tentativa++) {
        printf("\nTentativa %d de %d: ", tentativa, MAX_TENTATIVAS);

        // Protecao contra letra: nao gasta a tentativa
        if (scanf("%d", &palpite) != 1) {
            printf("Entrada invalida! Digite um numero.\n");
            limparBuffer();
            tentativa--;
            continue;
        }

        if (palpite == secreto) {
            printf("Acertou em %d tentativa(s)!\n", tentativa);
            return 1;
        } else if (palpite < secreto) {
            printf("O numero e MAIOR que %d.\n", palpite);
        } else {
            printf("O numero e MENOR que %d.\n", palpite);
        }
    }

    printf("\nAcabaram as tentativas! O numero era %d.\n", secreto);
    return 0;
}

int main() {
    char resposta = 's';
    int partidas = 0, vitorias = 0;

    // Semente do sorteio: muda a cada execucao
    srand(time(NULL));

    printf("=== JOGO DA ADIVINHACAO ===\n");

    while (resposta == 's' || resposta == 'S') {
        partidas++;
        vitorias += jogarPartida();

        printf("\nJogar de novo? (s/n): ");
        limparBuffer();
        scanf("%c", &resposta);
    }

    printf("\nPartidas: %d | Vitorias: %d\n", partidas, vitorias);
    printf("Ate a proxima!\n");
    return 0;
}
