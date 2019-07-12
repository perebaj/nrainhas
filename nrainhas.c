/*
@Nome: Jonathan Silva
@Curso: Eng de Computação
@RA: 759052
 */

#include <stdio.h>
#include <stdlib.h>


int solution = 0; //variavel global que conta a quantidade de soluções possiveis.

/*
@Brief Função responsável pela verificação se é ou não seguro alocar a rainha na posição tabuleiro[line][column], onde line e column sao passados na assinatura na função;
@param  {int ***tabuleiro}  Matriz com as peças
@param  {int line}  Linha em que a rainha vai ser alocada
@param  {column}    Coluna em que a rainha vai ser alocada
@param  {tam_Tabuleiro}       Tamanho da matriz que representa o tabuleiro
@Return 0 - Não é seguro// 1 - É seguro

 */
int safezone(int **tabuleiro ,int line, int column, int tam_Tabuleiro){ 
    //verifica linha
    for(int count = 0; count < tam_Tabuleiro; count ++){
        if(tabuleiro[line][count] == 1)
            return 0;
    }
    //verifica coluna
    for(int count = 0; count < tam_Tabuleiro; count++){
        if(tabuleiro[count][column] == 1)
            return 0;
    }
    int count1, count2; // declaração dos contadores
        
    //verifica Diagonal principal acima 
    for (count1 = line, count2 = column;
        count1 >=0 && count2 >=0;
        count1--, count2--)
    {
        if(tabuleiro[count1][count2] == 1)
            return 0;
    }

    //verifica a diagonal principal abaixo
    for(count1 = line, count2 = column; 
        count1 <tam_Tabuleiro && count2 < tam_Tabuleiro; 
        count1++, count2++)
    {
        if(tabuleiro[count1][count2] == 1)
            return 0;
    }

    //verifica a diagonal secundária acima
    for(count1 = line, count2 = column;
        count1 >= 0 && count2 < tam_Tabuleiro;
        count1--, count2++)
    {
            
        if(tabuleiro[count1][count2] == 1)
           return 0;
    }
    //verifica a diagonal secundária abaixo
    for(count1 = line, count2 = column;
        count1 < tam_Tabuleiro && count2 >= 0;
        count1++, count2--){
            if (tabuleiro[count1][count2] == 1)     
                return 0;
            
    }

    return 1;
}

/*
@Brief Cria um tabuleiro com dimensão tam_Tabuleiro x tam_Tabuleiro, inicializada com zeros.
@param  {int tam_Tabuleiro}     Dimensão do tabuleiro
@return     Retorna a primeira posição para a matriz.
 */

int **creatBoad(int tam_Tabuleiro){
    int **board; //ponteiro que aponta para um vetor de inteiros(Uma matriz)
    board = calloc(tam_Tabuleiro,sizeof(int *)); 
    for(int line = 0; line < tam_Tabuleiro; line++)
        board[line] = calloc(tam_Tabuleiro, sizeof(int));

    return board;
}
/*
@Brief      Imprime a matriz com os elementos em ordem. 
@param      {int **tambuleiro} Matriz que representa meu tabuleiro
@param      {int tam_Tabuleiro} Dimensão do tabuleiro
 */
void printBoard(int **tabuleiro, int tam_Tabuleiro){
    for(int line = 0; line < tam_Tabuleiro; line++){
        for(int column = 0; column < tam_Tabuleiro; column++)
            printf("%d", tabuleiro[line][column]);   
        printf("\n");
    }
}

/*
@Brief      Resolve o problema, verificando coluna por coluna se é válido inserir a rainha.
@param      {int **tabuleiro}   Matriz que representa meu tabuleiro
@param      {int tam+Tabuleiro}     Dimensão da minha matriz
@param      {int column}        Coluna que estou verificando, començando pela zero.
 */

void resolve(int **tabuleiro, int tam_Tabuleiro, int column){
    if(column == tam_Tabuleiro){ //Caso de parada
       solution ++;
       return;
    }

    for(int line = 0; line < tam_Tabuleiro; line++){
        if(safezone(tabuleiro, line, column, tam_Tabuleiro)){
            tabuleiro[line][column] = 1;
            
            resolve(tabuleiro, tam_Tabuleiro, column+1);

            //bekiTrack,,  se o candidato à solução não servir, abandona-se a opção, inserindo 0 no lugar.
            tabuleiro[line][column] = 0;
        }
    }
}


int main(){
    int tamanho;
    scanf("%d", &tamanho);
    int **tabuleiro = creatBoad(tamanho);
    
    resolve(tabuleiro, tamanho, 0);
    printf("%d \n", solution);
}