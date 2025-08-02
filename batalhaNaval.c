#include <stdio.h>

#define TAMANHO_TABULEIRO 10
#define TAMANHO_NAVIO 3
#define AGUA 0
#define NAVIO 3

int main() {
    
    int tabuleiro[TAMANHO_TABULEIRO][TAMANHO_TABULEIRO] = {0};
    int linhaHorizontal =7;
    int colunaHorizontal =4;
    int linhaVertical = 2;
    int colunaVertical =3;
    int i;
    int j;
    
    
    
    printf("       TABULEIRO BATALHA NAVAL!\n");
    printf("\n");
    
    
    for (int i = 0; i < TAMANHO_NAVIO; i++) {
        tabuleiro[linhaHorizontal][colunaHorizontal + i] = NAVIO;
    }

    for (int i = 0; i < TAMANHO_NAVIO; i++) {
        tabuleiro[linhaVertical + i][colunaVertical] = NAVIO;
    }


    printf("    ");
    for (int j = 1; j <= TAMANHO_TABULEIRO; j++) {
        printf("%2d ", j);
    }
    printf("\n");

    for (int i = 0; i < TAMANHO_TABULEIRO; i++) {
        printf(" %c  ", 'A' + i);  

        for (int j = 0; j < TAMANHO_TABULEIRO; j++) {
            printf("%2d ", tabuleiro[i][j]);
        }
        printf("\n");
    }
   

return 0;
}