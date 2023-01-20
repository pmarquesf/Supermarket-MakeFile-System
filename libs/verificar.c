#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "main.h"

// Função para verificar apenas os produtos vencidos

void verificarVencimento(listaProdutos *lp){

        struct Produto *aux;

        time_t mytime;
        mytime = time(NULL);
        struct tm tm = *localtime(&mytime);
        printf("\nData atual: %d/%d/%d", tm.tm_mday, tm.tm_mon + 1, tm.tm_year + 1900);

        char *row1[] = {"ID", "PRODUTO", "DATA", "VALOR"};

        printf("%*s | %*s | %*s | %*s\n", -3, row1[0], -MAX, row1[1], MAX1, row1[2], -MAX, row1[3]);
        printf("%*c | %*c | %*c | %*c\n", -3, '-', -MAX, '-', MAX1, '-', -MAX, '-');

        aux = lp->inicio;

        while(aux != NULL){
            if(aux->validade.ano < (tm.tm_year + 1900))
                 printf("%-3d | %-18s | %02d/%02d/%d | R$ %-3.2f\n", aux->idProduto, aux->nomeProduto, aux->validade.dia, aux->validade.mes, aux->validade.ano, aux->preco);
            else
                if(aux->validade.ano == (tm.tm_year + 1900))
                {
                    if(aux->validade.mes < (tm.tm_mon + 1))
                    {
                         printf("%-3d | %-18s | %02d/%02d/%d | R$ %-3.2f\n", aux->idProduto, aux->nomeProduto, aux->validade.dia, aux->validade.mes, aux->validade.ano, aux->preco);
                    }
                    else
                        if(aux->validade.mes == (tm.tm_mon + 1))
                        {
                            if(aux->validade.dia < tm.tm_mday)
                                printf("%-3d | %-18s | %02d/%02d/%d | R$ %-3.2f\n", aux->idProduto, aux->nomeProduto, aux->validade.dia, aux->validade.mes, aux->validade.ano, aux->preco);
                        }
                }

            aux = aux->prox;
        }
}