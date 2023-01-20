
// Trabalho final para a disciplina de LAB de AED ll
// Grupo - Luiz Pedro e Leonardo Moraes

/*  Proposta: Programa organiza��o e tratamento de dados em um supermercado por data de validade.
              Um programa onde ser� poss�vel inserir os produtos por:
    1 - ID
    2 - Nome do Produto
    3 - Data de Validade

    Os produtos ser�o inseridos, exclu�dos, filtrados e ordenados.
    Ser�o inseridos nas Lista j� ordenados, para quando o usu�rio pedir para
    filtrar por ID, j� aparecer os produtos ordenados por data de validade.

    O principal objetivo � ajudar os supermercados a organizar a data de validade
    dos produtos que muitas vezes acabam se perdendo.

    1 - Cadastrar o produto
    2 - Excluir
    3 - Filtrar o produto */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <locale.h>
#include "codigo08.h"

/*
#ifndef MAX
#define MAX 18
#define MAX1 -10
#endif

struct dataValidade{
    int dia;
    int mes;
    int ano;
};

struct Produto{
    struct Produto *ant;
    int categ;
    int idProduto;
    char nomeProduto[30];
    float preco;
    struct dataValidade validade;
    struct Produto *prox;
};

typedef struct {
    struct Produto *inicio;
    struct Produto *fim;
}listaProdutos;

void criaLista(listaProdutos *lp);
void excluirProduto(listaProdutos *lp);
int verificarLista(listaProdutos *lp);
int filtrarCategoria(listaProdutos lp);
void criarIdent(listaProdutos *lp, int categoria);
void filtrarProdutos(listaProdutos lp, int categoria);
void mostraLista(listaProdutos lp);
void verificarVencimento(listaProdutos *lp);
void red();

*/

int main(){

    setlocale(LC_ALL, "Portuguese");

    listaProdutos lista;
    int op, cont=0, c;

    do{
        red();
        printf("\n== Sistema de supermercado ==\n");
        printf("    1. Cadastrar Produto\n");
        printf("    2. Excluir Produto\n");
        printf("    3. Verificar Produtos vencidos\n");
        printf("    4. Filtrar Produtos\n");
        printf("    5. Exibir Lista Completa\n");
        printf("    6. Sair\n");

        printf("\nDigite a opcao: ");

        scanf("%d", &op);

        printf("\n");

        switch(op){
            case 1:
                if(cont==0){
                    cont++;
                    criaLista(&lista);
                }
                    verificarLista(&lista);
                break;

            case 2:
                criarIdent(&lista, 0);
                excluirProduto(&lista);
                break;

            case 3:
                criarIdent(&lista, 0);
                verificarVencimento(&lista);
                break;

            case 4:
                c = filtrarCategoria(lista);
                criarIdent(&lista, c);
                filtrarProdutos(lista, c);
                break;

            case 5:
                criarIdent(&lista, 0);
                mostraLista(lista);
                break;

            case 6:
                break;

            default:
                printf("Opcao invalida\n");
        }
    }while(op!=6);

    return(0);
}

void red () {
  printf("\033[0;42;0m");
}

/*
void criaLista(listaProdutos *lp){
        lp->inicio = NULL;
        lp->fim = NULL;
}

void excluirProduto(listaProdutos *lp){
        struct Produto *aux, *ultimo, *c;

        aux = lp->inicio;
        c   = lp->inicio;
        int id = 0;

        char *row1[] = {"ID", "PRODUTO", "DATA", "VALOR"};

        printf("\n%*s | %*s | %*s | %*s\n", -3, row1[0], -MAX, row1[1], MAX1, row1[2], -MAX, row1[3]);
        printf("%*c | %*c | %*c | %*c\n", -3, '-', -MAX, '-', MAX1, '-', -MAX, '-');

        while(c != NULL){
            printf("%-3d | %4s | %02d/%02d/%d | R$ %-3.2f\n", c->idProduto, c->nomeProduto, c->validade.dia, c->validade.mes, c->validade.ano, c->preco);
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
*/

int verificarLista(listaProdutos *lp){
            struct Produto *aux, *p, *b;
            //int categ, cont = 0;

            aux = (struct Produto*)malloc(sizeof(struct Produto));
            if(aux == NULL)
            return 0;

            aux->prox = NULL;

            printf("\n== Menu de Categorias ==\n");
            printf("    1. Padaria\n");
            printf("    2. Alimentos (cereais e grãos)\n");
            printf("    3. Congelados e frios\n");
            printf("    4. Hortifruti\n");
            printf("    5. Produtos de limpeza\n");
            printf("    6. Higiene pessoal\n");
            printf("    7. Bebidas\n");
            printf("    8. Papelaria\n");
            printf("\nDigite a categoria do produto: ");
            scanf("%d", &aux->categ);

            printf("\nDigite o nome do produto: ");
            getchar();
            fgets(aux->nomeProduto,29,stdin);

            printf("\nDigite o valor do produto: ");
            scanf("%f", &aux->preco);

            printf("\nDigite a data de validade do produto: ");
            scanf("%d %d %d", &aux->validade.dia, &aux->validade.mes, &aux->validade.ano);

            if(lp->inicio == NULL){
                lp->inicio = aux;
                lp->fim    = aux;
            }
            else{
                p = lp->inicio;

                while(p != NULL){
                    if(aux->validade.ano < p->validade.ano){
                        if(lp->inicio == p)
                            lp->inicio = aux;
                        else
                            b->prox = aux;
                        aux->prox = p;
                        break;
                    }else
                        if(aux->validade.ano == p->validade.ano){
                            if(aux->validade.mes < p->validade.mes){
                                if(lp->inicio == p)
                                    lp->inicio = aux;
                                else
                                    b->prox = aux;
                                aux->prox = p;
                                break;
                            }else
                                if(aux->validade.mes == p->validade.mes){
                                    if(aux->validade.dia < p->validade.dia){
                                        if(lp->inicio == p)
                                            lp->inicio = aux;
                                        else
                                            b->prox = aux;
                                        aux->prox = p;
                                        break;
                                }else
                                    if(aux->validade.dia == p->validade.dia){
                                        if(strcmp(aux->nomeProduto, p->nomeProduto) < 0){
                                            if(lp->inicio == p)
                                                lp->inicio = aux;
                                            else
                                                b->prox = aux;
                                            aux->prox = p;
                                            break;
                                        }
                                    }

                                }
                            }
                    b = p;
                    p = p->prox;
                }
                if(p == NULL){
                    lp->fim->prox = aux;
                    lp->fim = aux;
                }
            }

            printf("\nCadastro Realizado\n");
	    getchar();

	    return 0;
}

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

void criarIdent(listaProdutos *lp, int categoria){

     struct Produto *p;
     int cont = 0;

      p = lp->inicio;

      if(categoria==0)
            while (p != NULL)
            {
                cont++;
                p->idProduto = cont;
                p = p->prox;
            }
      else
        while (p != NULL)
        {
            if(p->categ == categoria){
                cont++;
                p->idProduto = cont;
                p = p->prox;
	    }
        }
}

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
