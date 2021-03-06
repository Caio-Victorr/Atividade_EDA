#include <stdio.h>
#include <stdlib.h>

struct listaEnc{
    int matricula;
    float media;
    char situacao;
    struct listaEnc *prox;
};

typedef struct listaEnc ListaEnc;

ListaEnc* create(){
    return NULL;
}

ListaEnc* busca(ListaEnc *l, int elemBusca){
	ListaEnc* p;
	for(p = l; p != NULL; p = p->prox){
		if(p->matricula == elemBusca){
			printf("\nElemento %d encontrado", p->matricula);
			return p;
		}
	}
	printf("\nElemento %d nao encontrado", elemBusca);
	return NULL;
}

ListaEnc* remover(ListaEnc* l, int elemRemove){
	
	ListaEnc* ant = NULL;
    ListaEnc* p = l;

    while(p!=NULL && p->matricula!=elemRemove){
        ant = p;
        p = p->prox;
    }
    if(p == NULL){
        printf("\nNao tem esse elemento");
        return l;
    }
    if(ant == NULL){
        l = p->prox;
    }else{
        ant->prox = p->prox;
    }
    free(p);
    printf("\nElemento %d removido", elemRemove);
    return l;
}

int vazia(ListaEnc *l){
    if(l == NULL){
        printf("Lista Vazia");
        return 1; 
    }else{
        printf("Lista nao esta vazia");
        return 0;
    }
}

ListaEnc* inserir(ListaEnc *l, int ma, float me){
    ListaEnc* novo;
    ListaEnc* ant = NULL;
    ListaEnc* p = l;

    while (p != NULL && p->matricula < ma){
        ant = p;
        p = p->prox;
    }

    novo = (ListaEnc*)malloc(sizeof(ListaEnc));
    novo->matricula = ma;
    novo->media = me;

    if(ant == NULL){
        novo->prox = l;
        l = novo;
    }else{
        novo->prox = ant->prox;
        ant->prox = novo;
    }
    
    novo->situacao = 'R';
    if(me >= 7){
    	novo->situacao = 'A';
	}
    return l;
}

ListaEnc* liberar (ListaEnc*l){
    ListaEnc *p = l;
	ListaEnc* next;

	while(p != NULL) {
		next = p->prox;
		free(p);
		p = next;
	}
	return p;
}

void imprimir(ListaEnc* l){
	ListaEnc* p;
    for(p = l; p!= NULL; p = p->prox){
		printf("\n\nMatricula: %d", p->matricula);
		printf("\nMedia: %f", p->media);
		printf("\nSituacao: %c", p->situacao);
    }
}

int tamanhoLista(ListaEnc* l){

	ListaEnc *p = l;
	int qtdElem = 0;

	while(p != NULL){
		qtdElem++;
		p = p->prox;
	}
    printf("\nTamanho da lista: %d", qtdElem);
	return qtdElem;
}

int main(int argc, char const *argv[]){
	
	ListaEnc* exemplo;
	exemplo = create();

    vazia(exemplo);
	
	exemplo = inserir(exemplo, 1001, 7.8);
	exemplo = inserir(exemplo, 1002, 8.2);
	exemplo = inserir(exemplo, 1003, 6.3);
	exemplo = inserir(exemplo, 1004, 10.0);
	
	//printf("\n-----------------------------------");
	//exemplo = quantidadeElementos(exemplo);
	//imprimir(exemplo);
    //tamanhoLista(exemplo);
    //exemplo = remover(exemplo, 1004);
    //tamanhoLista(exemplo);
    //printf("\n-----------------------------------\n");
    imprimir(exemplo);
    remover(exemplo, 1003);
    imprimir(exemplo);
    liberar(exemplo);
    imprimir(exemplo);
    vazia(exemplo);

	//exemplo = liberar(exemplo);
	
    //printf("\n-----------------------------------\n");

    //vazia(exemplo);

    //printf("\n-----------------------------------\n");

	//imprimir(exemplo);

    //busca(exemplo, 1002);
}