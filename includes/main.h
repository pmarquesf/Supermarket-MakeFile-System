#ifndef MAX
#define MAX 18
#define MAX1 -10
#endif

// Definição das Structs

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
} listaProdutos;

//  Protótipos das funções;

void criaLista(listaProdutos *lp);
void excluirProduto(listaProdutos *lp);
int InserirLista(listaProdutos *lp);
int filtrarCategoria(listaProdutos lp);
void criarIdent(listaProdutos *lp, int categoria);
void filtrarProdutos(listaProdutos lp, int categoria);
void mostraLista(listaProdutos lp);
void verificarVencimento(listaProdutos *lp);
void red();

