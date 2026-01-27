#include <stdio.h>

// Desafio Batalha Naval - MateCheck
// Este código inicial serve como base para o desenvolvimento do sistema de Batalha Naval.
// Siga os comentários para implementar cada parte do desafio.

int main() {
    // Nível Novato - Posicionamento dos Navios
    // Sugestão: Declare uma matriz bidimensional para representar o tabuleiro (Ex: int tabuleiro[5][5];).
    // Sugestão: Posicione dois navios no tabuleiro, um verticalmente e outro horizontalmente.
    // Sugestão: Utilize `printf` para exibir as coordenadas de cada parte dos navios.

    int tabuleiro [10][10] = {
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

    int naviovertical[2] = {8,5}; //posição inicial do navio vertical linha e coluna
    int naviohorizontal[2] = {7,2}; //posição inicial do navio horizontal linha e coluna

    //verificar se a posição está dentro dos limites do tabuleiro
    if(naviovertical[0] < 1 || naviovertical[0] > 8 || naviovertical[1] < 1 || naviovertical[1] > 10 ||
       naviohorizontal[0] < 1 || naviohorizontal[0] > 10 || naviohorizontal[1] < 1 || naviohorizontal[1] > 8){
        printf("Posição do navio fora dos limites do tabuleiro! Posicione-os novamente.\n");
        return 0; //encerra o programa 
    }

    //verifica se os navios se chocam
    if((naviovertical[0]+2 >= naviohorizontal[0] && naviovertical[0] <= naviohorizontal[0] ) && ( naviohorizontal[1] + 2 >= naviovertical[1] && naviohorizontal[1] <= naviovertical[1])){
        printf("Os navios se chocam! Posicione-os novamente.\n");
        return 0; //encerra o programa
    }
    
    //linhas
    for(int l=0; l<10; l++){
        //imprimir legenda das colunas A, B, C...
        if(l==0){
            printf("  \t");
            for(char c='A'; c<='J'; c++){
                printf("%c ", c);
            }
            printf("\n");
        }
        //colunas
        for(int c=0; c<10; c++){
            //imprimir legenda das linhas
            if(c==0){
                printf("%d\t", l+1);
            }
            //verifica se a posição atual é parte de algum navio
            //utilizo -1 para ajustar com o índice da matriz pois a posição do navio está em 1-10
            //utilizo a posição inicial do navio e adiciono 2 para cobrir o tamanho do navio (3 posições)
            //utilizo else if pois uma posição não pode ser dos dois navios ao mesmo tempo, já foi verificado se eles se chocam
            if(l == naviohorizontal[0]-1 && c >= naviohorizontal[1]-1 && c < naviohorizontal[1]+2){
                tabuleiro[l][c] = 3; //posição do navio horizontal
            } else if(c == naviovertical[1]-1 && l >= naviovertical[0]-1 && l < naviovertical[0]+2){
                tabuleiro[l][c] = 3; //posição do navio vertical
            }
            printf("%d ",tabuleiro[l][c]);
        }
        printf("\n");
    }

    // Nível Aventureiro - Expansão do Tabuleiro e Posicionamento Diagonal
    // Sugestão: Expanda o tabuleiro para uma matriz 10x10.
    // Sugestão: Posicione quatro navios no tabuleiro, incluindo dois na diagonal.
    // Sugestão: Exiba o tabuleiro completo no console, mostrando 0 para posições vazias e 3 para posições ocupadas.

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
