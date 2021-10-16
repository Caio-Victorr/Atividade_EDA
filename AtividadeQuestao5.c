#include <stdio.h>
#include <stdlib.h>

struct lista{
    int info;
    struct lista *prox;
};

typedef struct lista Lista;

Lista* create(){
    return NULL;
}

Lista* inserir(Lista *l, int item){
    
    Lista* novo = (Lista*)malloc(sizeof(Lista));
    novo->info = item;
    novo->prox = l;
    return novo;
}

int quantidadeCelulas(Lista* l) {
	Lista* p = l;
	int quantidade = 0;
	while(p != NULL) {
		quantidade = quantidade + 1;
		p = p->prox;
	}
	
	printf("\nQuantidade celulas na lista: %d", quantidade);
    return 1;
}

Lista* concatena(Lista* L1, Lista* L2) {
	
	while(L2->prox != NULL) {
		L2 = L2->prox;
	}
    L2->prox = L1;
}

void imprimir(Lista* l){
	Lista* p;
    for(p = l; p!= NULL; p = p->prox){
		printf("\n\nMatricula: %d", p->info);
    }
}

int main(int argc, char const *argv[]){

    Lista* listinha1;
	listinha1 = create();

    Lista* listinha2;
	listinha2 = create();

    listinha1 = inserir(listinha1, 1001);
	listinha1 = inserir(listinha1, 1002);
	listinha1 = inserir(listinha1, 1003);
	listinha1 = inserir(listinha1, 1004);
    imprimir(listinha1);

    printf("\n============================");

    listinha2 = inserir(listinha2, 1007);
	listinha2 = inserir(listinha2, 1009);
	listinha2 = inserir(listinha2, 1005);
	listinha2 = inserir(listinha2, 1006);
    imprimir(listinha2);

    printf("\n============================");

    concatena(listinha1, listinha2);
    imprimir(listinha2);

    return 0;
}


