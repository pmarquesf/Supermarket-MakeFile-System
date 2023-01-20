#include <stdio.h>
#include <stdlib.h>
#include "main.h"

/*Depois da lista ser criada, vamos cadastrar os produtos já os separando em cada categoria,
  E os inserindo ordenados na categoria comparando a validade nesta ordem:
  1 - Ano
  2 - Mês
  3 - Dia
  4 - Ordem alfábetica
*/

int InserirLista(listaProdutos *lp){
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
}int InserirLista(listaProdutos *lp){
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