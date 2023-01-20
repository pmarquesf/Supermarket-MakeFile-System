#include <stdio.h>
#include <stdlib.h>
#include "main.h"

//  Filtrar uma categoria para ver apenas os produtos da mesma;

int filtrarCategoria(listaProdutos lp){
    int categoria;

    printf("\n== Menu de Categorias ==\n");
            printf("    1. Padaria\n");
            printf("    2. Alimentos (cereais e grãos)\n");
            printf("    3. Congelados e frios\n");
            printf("    4. Hortifruti\n");
            printf("    5. Produtos de limpeza\n");
            printf("    6. Higiene pessoal\n");
            printf("    7. Bebidas\n");
            printf("    8. Papelaria\n");
    printf("\nDigite uma categoria para filtrar os produtos: ");

    scanf("%d", &categoria);

    return categoria;
}

// Após a categoria ser selecionada, será exibido os produto daquela categoria

void filtrarProdutos(listaProdutos lp, int categoria){

    struct Produto *aux;

        printf("- Exibindo produtos da categoria %d\n", categoria);

        char *row1[] = {"ID", "PRODUTO", "DATA", "VALOR"};

        printf("%*s | %*s | %*s | %*s\n", -3, row1[0], -MAX, row1[1], MAX1, row1[2], -MAX, row1[3]);
        printf("%*c | %*c | %*c | %*c\n", -3, '-', -MAX, '-', MAX1, '-', -MAX, '-');

        if(lp.inicio == NULL) printf("\nLista Vazia!");

        else{
            aux = lp.inicio;
            do{
                if(aux->categ == categoria){
                        printf("%-3d | %-18s | %02d/%02d/%d | R$ %-3.2f\n", aux->idProduto, aux->nomeProduto, aux->validade.dia, aux->validade.mes, aux->validade.ano, aux->preco);
                }
                aux = aux->prox;
            }while(aux != NULL);
        }
}