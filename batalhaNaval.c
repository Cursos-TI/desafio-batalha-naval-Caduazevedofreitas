#include <stdio.h>
#include <stdlib.h>

#define TAMANHO_TABULEIRO 10
#define TAMANHO_NAVIO 3
#define AGUA 0
#define NAVIO 3
#define HABILIDADE 5
#define IMPACTO 5  

void gerarOctaedro(int matriz[HABILIDADE][HABILIDADE]) {
    for (int i = 0; i < HABILIDADE; i++) {
        for (int j = 0; j < HABILIDADE; j++) {
            if (abs(i - 2) + abs(j - 2) <= 2) matriz[i][j] = 1;
            else matriz[i][j] = 0;
        }
    }
}

void aplicarHabilidade(int tabuleiro[TAMANHO_TABULEIRO][TAMANHO_TABULEIRO],
                       int habilidade[HABILIDADE][HABILIDADE],
                       int origemLinha, int origemColuna) {
    for (int i = 0; i < HABILIDADE; i++) {
        for (int j = 0; j < HABILIDADE; j++) {
            int linhaTabuleiro = origemLinha - HABILIDADE / 2 + i;
            int colunaTabuleiro = origemColuna - HABILIDADE / 2 + j;

            if (linhaTabuleiro >= 0 && linhaTabuleiro < TAMANHO_TABULEIRO &&
                colunaTabuleiro >= 0 && colunaTabuleiro < TAMANHO_TABULEIRO) {
                if (habilidade[i][j] == 1 && tabuleiro[linhaTabuleiro][colunaTabuleiro] == AGUA) {
                    tabuleiro[linhaTabuleiro][colunaTabuleiro] = IMPACTO;
                }
            }
        }
    }
}

void exibirTabuleiro(int tabuleiro[TAMANHO_TABULEIRO][TAMANHO_TABULEIRO]) {
    printf("  ");
    for (int j = 0; j < TAMANHO_TABULEIRO; j++) {
        printf("%d ", j);
    }
    printf("\n");

    for (int i = 0; i < TAMANHO_TABULEIRO; i++) {
        printf("%d ", i);
        for (int j = 0; j < TAMANHO_TABULEIRO; j++) {
            printf("%d ", tabuleiro[i][j]);
        }
        printf("\n");
    }
}

int main() {
    int tabuleiro[TAMANHO_TABULEIRO][TAMANHO_TABULEIRO] = {0};

    // Posiciona navio vertical (linha 2 a 4, coluna 3)
    for (int i = 2; i <= 4; i++) {
        tabuleiro[i][3] = NAVIO;
    }

    // Posiciona navio isolado (linha 1, coluna 3)
    tabuleiro[1][3] = NAVIO;

    // Gera matriz de habilidade octaedro
    int octaedro[HABILIDADE][HABILIDADE];
    gerarOctaedro(octaedro);

    // Aplica habilidade centrada em (4,5)
    aplicarHabilidade(tabuleiro, octaedro, 4, 5);

    // Exibe o tabuleiro
    exibirTabuleiro(tabuleiro);

    return 0;
}