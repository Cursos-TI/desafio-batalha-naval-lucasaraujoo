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
    // tamanhos das matrizes de habilidades conforme enunciado. Caso mude teria que implementar outra logica para definir as posições das habilidades
    int tamanhoHabilidades[2] = {3,5}; 
    int habilidadeCone[tamanhoHabilidades[0]][tamanhoHabilidades[1]] ;
    int habilidadeCruz[tamanhoHabilidades[0]][tamanhoHabilidades[1]] ;
    int habilidadeOctaedro[tamanhoHabilidades[0]][tamanhoHabilidades[1]] ;

    int origemHabilidadeCone[2] = {2,3}; // posição do centro do cone na matriz
    int origemHabilidadeCruz[2] = {9,8}; // posição do centro da cruz na matriz
    int origemHabilidadeOctaedro[2] = {9,3}; // posição do centro do octaedro na matriz

    //verificar se a posição está dentro dos limites do tabuleiro
    if (
        origemHabilidadeCone[0] - tamanhoHabilidades[0]/2 < 1 || origemHabilidadeCone[0] + tamanhoHabilidades[0]/2 > 10 ||
        origemHabilidadeCone[1] - tamanhoHabilidades[1]/2 < 1 || origemHabilidadeCone[1] + tamanhoHabilidades[1]/2 > 10 ||

        origemHabilidadeCruz[0] - tamanhoHabilidades[0]/2 < 1 || origemHabilidadeCruz[0] + tamanhoHabilidades[0]/2 > 10 ||
        origemHabilidadeCruz[1] - tamanhoHabilidades[1]/2 < 1 || origemHabilidadeCruz[1] + tamanhoHabilidades[1]/2 > 10 ||

        origemHabilidadeOctaedro[0] - tamanhoHabilidades[0]/2 < 1 || origemHabilidadeOctaedro[0] + tamanhoHabilidades[0]/2 > 10 ||
        origemHabilidadeOctaedro[1] - tamanhoHabilidades[1]/2 < 1 || origemHabilidadeOctaedro[1] + tamanhoHabilidades[1]/2 > 10
    ) {
        printf("Posição da habilidade fora dos limites do tabuleiro! Posicione-as novamente.\n");
        return 0; // encerra o programa
    }
    
    // preenchimento das matrizes de habilidades
    printf("Habilidade Cone:\n");
    for(int i=0; i<tamanhoHabilidades[0]; i++){
        for(int j=0; j<tamanhoHabilidades[1]; j++){
            if(j >= (tamanhoHabilidades[1]/2)-i && j <= (tamanhoHabilidades[1]/2)+i){
                habilidadeCone[i][j] = 1;
            } else {
            habilidadeCone[i][j] = 0;
            
            }
            printf("%d ", habilidadeCone[i][j]);
        }
        printf("\n");
    }

    printf("\nHabilidade Cruz:\n");
    for(int i=0; i<tamanhoHabilidades[0]; i++){
        for(int j=0; j<tamanhoHabilidades[1]; j++){
            if(i == tamanhoHabilidades[0]/2 || j == tamanhoHabilidades[1]/2){
                habilidadeCruz[i][j] = 1;
            } else {
            habilidadeCruz[i][j] = 0;
            }
            printf("%d ", habilidadeCruz[i][j]);
        }
        printf("\n");
    }

    printf("\nHabilidade Octaedro:\n");
    for(int i=0; i<tamanhoHabilidades[0]; i++){
        for(int j=0; j<tamanhoHabilidades[1]; j++){
            if((i == tamanhoHabilidades[0]/2 && j!= 0 && j!= tamanhoHabilidades[1]-1)|| j == tamanhoHabilidades[1]/2){
                habilidadeOctaedro[i][j] = 1;
            } else {
            habilidadeOctaedro[i][j] = 0;
            }
            printf("%d ", habilidadeOctaedro[i][j]);
        }
        printf("\n");
    }


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
        naviodiagonal1 > 3 && naviodiagonal2 > 3 && naviodiagonal1 < 6 && naviodiagonal2 < 6
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


    // printar as habilidades no tabuleiro
    // habilidade cone
    for(int i=0; i<tamanhoHabilidades[0]; i++){
        for(int j=0; j<tamanhoHabilidades[1]; j++){
            // habilidade cone
            if(habilidadeCone[i][j] == 1){
                tabuleiro[origemHabilidadeCone[0]-1 - tamanhoHabilidades[0]/2 + i][origemHabilidadeCone[1]-1 - tamanhoHabilidades[1]/2 + j] = 5;
            }
        }
    }

    // habilidade cruz
    for(int i=0; i<tamanhoHabilidades[0]; i++){
        for(int j=0; j<tamanhoHabilidades[1]; j++){
            if(habilidadeCruz[i][j] == 1){
                tabuleiro[origemHabilidadeCruz[0]-1 - tamanhoHabilidades[0]/2 + i][origemHabilidadeCruz[1]-1 - tamanhoHabilidades[1]/2 + j] = 5;
            }
        }
    }

    // habilidade octaedro
    for(int i=0; i<tamanhoHabilidades[0]; i++){
        for(int j=0; j<tamanhoHabilidades[1]; j++){
            if(habilidadeOctaedro[i][j] == 1){
                tabuleiro[origemHabilidadeOctaedro[0]-1 - tamanhoHabilidades[0]/2 + i][origemHabilidadeOctaedro[1]-1 - tamanhoHabilidades[1]/2 + j] = 5;
            }
        }
    }


    // impressão do tabuleiro com os navios posicionados
    printf("\nTabuleiro Final:\n");
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



    return 0;
}
