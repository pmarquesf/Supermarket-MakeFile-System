#include <stdio.h>
#include <stdlib.h>
#include "main.h"

// Excluindo um produto da lista;

void excluirProduto(listaProdutos *lp){
        struct Produto *aux, *ultimo, *c;

        aux = lp->inicio;
        c   = lp->inicio;
        int id = 0;

        char *row1[] = {"ID", "PRODUTO", "DATA", "VALOR"};

        printf("\n%*s | %*s | %*s | %*s\n", -3, row1[0], -MAX, row1[1], MAX1, row1[2], -MAX, row1[3]);
        printf("%*c | %*c | %*c | %*c\n", -3, '-', -MAX, '-', MAX1, '-', -MAX, '-');

        while(c != NULL){
                       printf("%-3d | %4s | %02d/%02d/%d | R$ %-3.2f\n", 
c->idProduto, c->nomeProduto, c->validade.dia, c->validade.mes, c->validade.ano, c->preco);
            c = c->prox;
        }

        printf("\nDigite o ID que deseja excluir: ");
        scanf("%d", &id);

        while(aux != NULL){
            if(aux->idProduto == id){
                if(lp->inicio == aux){
                    lp->inicio = lp->inicio->prox;
                    if(lp->inicio == NULL){
                        lp->fim = NULL;
                    }
                    free(aux);
                }
                else{
                    ultimo->prox = aux->prox;
                    free(aux);
                }
                break;
            }
            ultimo = aux;
            aux = aux->prox;
        }
        printf("\nProduto excluido!");
        getchar();
}