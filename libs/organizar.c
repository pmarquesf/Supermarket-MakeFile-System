#include <stdio.h>
#include <stdlib.h>
#include "main.h"

//  Função para organizar o ID dos produtos dentro da categoria

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