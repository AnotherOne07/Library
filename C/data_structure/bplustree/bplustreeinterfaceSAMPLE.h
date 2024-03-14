#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

#ifndef ARV_AVL
#define ARV_AVL


typedef enum {NoEsquerdo, NoDireito, NoPai, NoRaiz} DIRECAO;

typedef int ITEM;

typedef struct estrutura
{
    ITEM item;
    struct estrutura *esq;
    struct estrutura *dir;
    struct estrutura *pai;
    int altura;     // Altura do No, sendo que um No folha tem altura 0

} ARVORE_BINARIA;


/*
   Compara o item x com o y, retornando:
     1 caso x > y
     0 caso x = y
    -1 caso x < y
*/
char compare(ITEM x, ITEM y);

// Retorna true se x = y e false caso contrario
bool igual(ITEM x, ITEM y);

// Inicializa a arvore binaria deixando-a pronta para ser utilizada.
void inicializar(ARVORE_BINARIA *arvore);

// Retorna true se a arvore esta vazia (igual a NULL)
bool vazia(ARVORE_BINARIA *arvore);

// Cria um novo no usando o apontador arvore passado contendo o item,
// os apontadores para o pai e para os filhos contendo NULL.
// A altura e inicializada com 0.
void criarNo(ITEM item, ARVORE_BINARIA **arvore);

// Testa se o No indicado por Direcao a partir de arv existe
bool existeNo(DIRECAO direcao, ARVORE_BINARIA *arvore);

// Deslocar o apontador Arvore para o No indicado por Direcao
void deslocar(DIRECAO direcao, ARVORE_BINARIA **arvore);

/*
 * Objetivo: Cria um filho no NO apontado por Arvore na direcao informada. 
 *           Retorna um apontador para o NO criado ou NULL caso nao consiga.
 */ 
ARVORE_BINARIA* adicionarFilho(ITEM item, DIRECAO direcao, ARVORE_BINARIA *arvore);

// Desaloca da memoria toda a arvore
void disposeArvore(ARVORE_BINARIA *arvore);

/*
| Objetivos: Percorre a arvore, visitando primeiro a raiz, depois a subarvore
|            esquerda e por ultimo a subarvore direita.
*/
void preOrdem(ARVORE_BINARIA *arvore, void (*visite)(ARVORE_BINARIA*) );

/*
| Objetivos: Percorre a arvore, visitando primeiro a subarvore esquerda,
|            depois a raiz e por ultimo a subarvore direita.
*/
void inOrdem(ARVORE_BINARIA *arvore, void (*visite)(ARVORE_BINARIA*) );

/*
| Objetivos: Percorre a arvore, visitando primeiro a subarvore esquerda,
|            depois subarvore direita e por ultimo a a raiz.
*/
void posOrdem(ARVORE_BINARIA *arvore, void (*visite)(ARVORE_BINARIA*) );

// Retorna true se a item for encontrado.
// Neste caso, p aponta para o No.
// Se o item nao for encontrado, retorna false e p
// aponta para o No que seria o seu pai (caso existisse).
bool encontrarNo(ITEM item, ARVORE_BINARIA **p, ARVORE_BINARIA *arvore);

// Procura o item na arvore, retornando true caso esteja contido
// e false caso contrario
bool contem(ITEM item, ARVORE_BINARIA *arvore);


/////////////////////////////////////////////////
//     FUNCOES ESPECIFICAS DE ARVORES AVL      //
/////////////////////////////////////////////////


// Retorna true se o no passado e o filho esquerdo
bool eFilhoEsquerdo(ARVORE_BINARIA *no);


// Retorna true se o no passado e o filho direito    
bool eFilhoDireito(ARVORE_BINARIA *no);


// Calcula a altura de um No da arvore
int alturaNo(ARVORE_BINARIA *no);


// Retorna o balanceamento de um No da arvore
int balanceamento(ARVORE_BINARIA *no);


// Retorna o balanco de um No da Arvore AVL
int balanco(ARVORE_BINARIA *no);


/*
| Objetivos: Tenta inserir um No na Arvore AVL apontada por arvore.
|            Se conseguir, retorna o No inserido. Caso nao consiga, retorna NULL.
*/
ARVORE_BINARIA* inserir(ITEM item, ARVORE_BINARIA **arvore);


/*
| Objetivos: Retira o No contendo o item da arvore apontada por arvore. 
|            Retorna true se conseguiu remover e false caso contrario.
*/
bool remover(ITEM item, ARVORE_BINARIA **arvore);

#endif //ARV_AVL