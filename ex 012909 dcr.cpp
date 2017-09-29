#include<stdio.h>
#include<stdlib.h>

struct TNo {
       int N;
       
       TNo *prox;
};                                              // se eu definisse o *P aqui, entre a chave e o ponto e v�rgula, seria uma vari�vel global
                                                // *P � o endere�o de mem�ria apontado por P
int main(){
    TNo *P;                                   // esse *P � definido aqui pois eu quero que seja uma vari�vel local. E como n�o � vetor, estamos usando *P
    int cont;
    
    printf("Conteudo de P=%d\n\n", P);
    P = (TNo *)malloc(sizeof(TNo));
    printf("Conteudo de P apos malloc = %d\n\n", P);
    P-> N = 37;                                            // a seta significa que P est� apontando para um campo N
    P-> prox = NULL;                                      //Sintaxe: (*P).N  OU P -> N   � a mesma coisa
    printf("Valor do no 1: %d", P-> N);          
                                                          //quem tem o .N � quem est� sendo apontado por P
    P-> prox = (TNo *)malloc(sizeof(TNo)); 
    P-> prox -> N = 59;
    P-> prox -> prox = NULL;
    printf("\nValor do no 2: %d", P -> prox -> N);
    
    P-> prox -> prox = (TNo *)malloc(sizeof(TNo));
    P-> prox -> prox -> N = 16;
    P-> prox -> prox -> prox = NULL;
    printf("\nValor do no 3: %d\n\n", P -> prox -> prox -> N);
    
    printf("\nExibindo valores do while\n");
    cont = 1;
    while (P !=NULL) {
          printf("\nValor do no %d: %d", cont, P -> N);
          P = P -> prox;
          cont++;
          }
               
    printf("\nFim do Programa\n");
    system("pause");
    return 0;
}
    
       
