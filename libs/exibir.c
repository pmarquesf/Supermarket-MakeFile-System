#include <stdio.h>
#include <stdlib.h>
#include "main.h"

// Exibindo todos os produtos e seus dados da lista principal (Sem categorias e sem filtragem)

void mostraLista(listaProdutos lp){

        struct Produto *aux;
        int cont = 1;

        char *row1[] = {"ID", "PRODUTO", "DATA", "VALOR"};

        printf("%*s | %*s | %*s | %*s\n", -3, row1[0], -MAX, row1[1], MAX1, row1[2], -MAX, row1[3]);
        printf("%*c | %*c | %*c | %*c\n", -3, '-', -MAX, '-', MAX1, '-', -MAX, '-');

        if(lp.inicio == NULL) printf("\nLista Vazia!");

        else{
            aux = lp.inicio;

            do{
                printf("%-3d | %-18s | %02d/%02d/%d | R$ %-3.2f\n", aux->idProduto, aux->nomeProduto, aux->validade.dia, aux->validade.mes, aux->validade.ano, aux->preco);
                aux = aux->prox;
                cont++;
            }while(aux != NULL);
        }
}