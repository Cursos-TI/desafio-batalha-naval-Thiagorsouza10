#include <stdio.h>
#include <stdlib.h>

#define TAMANHO 10
#define NAVIO 3

void inicializarTabuleiro(int tabuleiro[TAMANHO][TAMANHO]) {
    for (int i = 0; i < TAMANHO; i++) {
        for (int j = 0; j < TAMANHO; j++) {
            tabuleiro[i][j] = 0;
        }
    }
}

int validarPosicao(int tabuleiro[TAMANHO][TAMANHO], int linha, int coluna, char orientacao) {
    if (orientacao == 'H') {
        if (coluna + NAVIO > TAMANHO) return 0;
        for (int i = 0; i < NAVIO; i++) {
            if (tabuleiro[linha][coluna + i] != 0) return 0;
        }
    } else if (orientacao == 'V') {
        if (linha + NAVIO > TAMANHO) return 0;
        for (int i = 0; i < NAVIO; i++) {
            if (tabuleiro[linha + i][coluna] != 0) return 0;
        }
    }
    return 1;
}

void posicionarNavio(int tabuleiro[TAMANHO][TAMANHO], int linha, int coluna, char orientacao) {
    if (!validarPosicao(tabuleiro, linha, coluna, orientacao)) {
        printf("Posição inválida para o navio!\n");
        return;
    }

    if (orientacao == 'H') {
        for (int i = 0; i < NAVIO; i++) {
            tabuleiro[linha][coluna + i] = 3;
        }
    } else if (orientacao == 'V') {
        for (int i = 0; i < NAVIO; i++) {
            tabuleiro[linha + i][coluna] = 3;
        }
    }
}

void imprimirTabuleiro(int tabuleiro[TAMANHO][TAMANHO]) {
    printf("  0 1 2 3 4 5 6 7 8 9\n");
    for (int i = 0; i < TAMANHO; i++) {
        printf("%d ", i);
        for (int j = 0; j < TAMANHO; j++) {
            printf("%d ", tabuleiro[i][j]);
        }
        printf("\n");
    }
}

int main() {
    int tabuleiro[TAMANHO][TAMANHO];
    int linhaH, colunaH, linhaV, colunaV;
    char orientacaoH = 'H', orientacaoV = 'V';
    
    inicializarTabuleiro(tabuleiro);
    
    // Coordenadas fixas para teste (poderiam ser solicitadas ao usuário)
    linhaH = 2; colunaH = 3;
    linhaV = 5; colunaV = 7;
    
    posicionarNavio(tabuleiro, linhaH, colunaH, orientacaoH);
    posicionarNavio(tabuleiro, linhaV, colunaV, orientacaoV);
    
    imprimirTabuleiro(tabuleiro);
    
    return 0;
}
