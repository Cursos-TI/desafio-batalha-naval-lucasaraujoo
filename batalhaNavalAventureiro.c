#include <stdio.h>

// Desafio Batalha Naval - MateCheck
// Este código inicial serve como base para o desenvolvimento do sistema de Batalha Naval.
// Siga os comentários para implementar cada parte do desafio.

int main() {
    // Nível Novato - Posicionamento dos Navios
    // Sugestão: Declare uma matriz bidimensional para representar o tabuleiro (Ex: int tabuleiro[5][5];).
    // Sugestão: Posicione dois navios no tabuleiro, um verticalmente e outro horizontalmente.
    // Sugestão: Utilize `printf` para exibir as coordenadas de cada parte dos navios.

    // Nível Aventureiro - Expansão do Tabuleiro e Posicionamento Diagonal
    // Sugestão: Expanda o tabuleiro para uma matriz 10x10.
    // Sugestão: Posicione quatro navios no tabuleiro, incluindo dois na diagonal.
    // Sugestão: Exiba o tabuleiro completo no console, mostrando 0 para posições vazias e 3 para posições ocupadas.

    int tabuleiro[10][10] = {
        {0,0,0,0,0,0,0,0,0,0},
        {0,0,0,0,0,0,0,0,0,0},
        {0,0,0,0,0,0,0,0,0,0},
        {0,0,0,0,0,0,0,0,0,0},
        {0,0,0,0,0,0,0,0,0,0},
        {0,0,0,0,0,0,0,0,0,0},
        {0,0,0,0,0,0,0,0,0,0},
        {0,0,0,0,0,0,0,0,0,0},
        {0,0,0,0,0,0,0,0,0,0},
        {0,0,0,0,0,0,0,0,0,0}
    };

    int naviovertical[2] = {8, 5};     // posição inicial do navio vertical linha e coluna
    int naviohorizontal[2] = {7, 2};   // posição inicial do navio horizontal linha e coluna
    int naviodiagonal1 = 4;            // posição inicial do navio diagonal 1 (linha e coluna iguais)
    int naviodiagonal2 = 3;            // posição inicial do navio diagonal 2 (linha e coluna iguais)

    // verificar se a posição está dentro dos limites do tabuleiro
    if (
        naviovertical[0] < 1 || naviovertical[0] > 8 || naviovertical[1] < 1 || naviovertical[1] > 10 ||
        naviohorizontal[0] < 1 || naviohorizontal[0] > 10 || naviohorizontal[1] < 1 || naviohorizontal[1] > 8 ||
        naviodiagonal1 < 1 || naviodiagonal1 > 8 || naviodiagonal2 < 1 || naviodiagonal2 > 8
    ) {
        printf("Posição do navio fora dos limites do tabuleiro! Posicione-os novamente.\n");
        return 0; // encerra o programa
    }

    // verificar se os navios diagonais se cruzam mesmo quando um nao ocupa a posição do outro
    if (
        naviodiagonal1 > 3 && naviodiagonal2 > 3 &&
        naviodiagonal1 < 6 && naviodiagonal2 < 6
    ) {
        printf("Os navios diagonais se cruzam! Posicione-os novamente.\n");
        return 0; // encerra o programa
    }

    // marca os navios no tabuleiro e verifica colisões

    // navio vertical
    for (int i = 0; i < 3; i++) {
        if (tabuleiro[naviovertical[0] - 1 + i][naviovertical[1] - 1] == 3) {
            printf("Os navios se chocam! Posicione-os novamente.\n");
            return 0; // encerra o programa
        }
        tabuleiro[naviovertical[0] - 1 + i][naviovertical[1] - 1] = 3;
    }

    // navio horizontal
    for (int i = 0; i < 3; i++) {
        if (tabuleiro[naviohorizontal[0] - 1][naviohorizontal[1] - 1 + i] == 3) {
            printf("Os navios se chocam! Posicione-os novamente.\n");
            return 0; // encerra o programa
        }
        tabuleiro[naviohorizontal[0] - 1][naviohorizontal[1] - 1 + i] = 3;
    }

    // navio diagonal 1
    for (int i = 0; i < 3; i++) {
        if (tabuleiro[naviodiagonal1 - 1 + i][naviodiagonal1 - 1 + i] == 3) {
            printf("Os navios se chocam! Posicione-os novamente.\n");
            return 0; // encerra o programa
        }
        tabuleiro[naviodiagonal1 - 1 + i][naviodiagonal1 - 1 + i] = 3;
    }

    // navio diagonal 2
    for (int i = 0; i < 3; i++) {
        if (tabuleiro[naviodiagonal2 - 1 + i][10 - naviodiagonal2 - i] == 3) {
            printf("Os navios se chocam! Posicione-os novamente.\n");
            return 0; // encerra o programa
        }
        tabuleiro[naviodiagonal2 - 1 + i][10 - naviodiagonal2 - i] = 3;
    }

// for (int l = 0; l < 10; l++) {
//     for (int c = 0; c < 10; c++) {

//         // navio vertical
//         if ((l >= naviovertical[0] - 1 && l <= naviovertical[0] + 1) &&
//             (c == naviovertical[1] - 1)) {

//             if (tabuleiro[l][c] == 3) {
//                 printf("Os navios se chocam! Posicione-os novamente.\n");
//                 return 0; // encerra o programa
//             }
//             tabuleiro[l][c] = 3; // marca o navio vertical no tabuleiro
//         }

//         // navio horizontal
//         if ((l == naviohorizontal[0] - 1) &&
//             (c >= naviohorizontal[1] - 1 && c <= naviohorizontal[1] + 1)) {

//             if (tabuleiro[l][c] == 3) {
//                 printf("Os navios se chocam! Posicione-os novamente.\n");
//                 return 0; // encerra o programa
//             }
//             tabuleiro[l][c] = 3; // marca o navio horizontal no tabuleiro
//         }

//         // navio diagonal 1
//         if (l == c && l == naviodiagonal1 - 1) {
//             for (int i = 0; i < 3; i++) {

//                 if (tabuleiro[l + i][c + i] == 3) {
//                     printf("Os navios se chocam! Posicione-os novamente.\n");
//                     return 0; // encerra o programa
//                 }
//                 tabuleiro[l + i][c + i] = 3; // marca o navio diagonal 1 no tabuleiro
//             }
//         }

//         // navio diagonal 2
//         if (l == 9 - c && l == naviodiagonal2 - 1) {
//             for (int i = 0; i < 3; i++) {

//                 if (tabuleiro[l + i][c - i] == 3) {
//                     printf("Os navios se chocam! Posicione-os novamente.\n");
//                     return 0; // encerra o programa
//                 }
//                 tabuleiro[l + i][c - i] = 3; // marca o navio diagonal 2 no tabuleiro
//             }
//         }
//     }
// }


    // impressão do tabuleiro com os navios posicionados
    for (int l = 0; l < 10; l++) {
        // imprimir legenda das colunas A, B, C...
        if (l == 0) {
            printf("  \t");
            for (char c = 'A'; c <= 'J'; c++) {
                printf("%c ", c);
            }
            printf("\n");
        }

        for (int c = 0; c < 10; c++) {
            // imprimir legenda das linhas
            if (c == 0) {
                printf("%d\t", l + 1);
            }
            printf("%d ", tabuleiro[l][c]);
        }
        printf("\n");
    }

    // Nível Mestre - Habilidades Especiais com Matrizes
    // Sugestão: Crie matrizes para representar habilidades especiais como cone, cruz, e octaedro.
    // Sugestão: Utilize estruturas de repetição aninhadas para preencher as áreas afetadas por essas habilidades no tabuleiro.
    // Sugestão: Exiba o tabuleiro com as áreas afetadas, utilizando 0 para áreas não afetadas e 1 para áreas atingidas.

    // Exemplos de exibição das habilidades:
    // Exemplo para habilidade em cone:
    // 0 0 1 0 0
    // 0 1 1 1 0
    // 1 1 1 1 1
    
    // Exemplo para habilidade em octaedro:
    // 0 0 1 0 0
    // 0 1 1 1 0
    // 0 0 1 0 0

    // Exemplo para habilidade em cruz:
    // 0 0 1 0 0
    // 1 1 1 1 1
    // 0 0 1 0 0

    return 0;
}
