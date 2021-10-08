#include <stdio.h>
#include <stdlib.h>

struct listaDupEnc{
    int matricula;
    float media;
    char situacao;
    struct listaDupEnc* ant;
    struct listaDupEnc* prox;
};

typedef struct listaDupEnc ListaDupEnc;

ListaDupEnc* create(){
    return NULL;
}

int vazia(ListaDupEnc *l){
    if(l == NULL){
        printf("Lista Vazia");
        return 1; 
    }else{
        printf("Lista nao esta vazia");
        return 0;
    }
}

ListaDupEnc* inserir(ListaDupEnc* l, int ma, float me ){
    
    ListaDupEnc* novo = (ListaDupEnc*)malloc(sizeof(ListaDupEnc));
    novo->matricula = ma;
    novo->media = me;

    novo->situacao = 'R';
    if(me >= 7) {
		novo->situacao = 'A';
	}

    if(l == NULL){
        novo->prox = NULL;
        novo->ant = NULL;
        l = novo;
    }else{
        ListaDupEnc* p = l;
        ListaDupEnc* anter;

        while(p != NULL && p->matricula < ma){
            anter = p;
            p = p->prox;
        }
        if(p == l){
            novo->ant = NULL;
            l->ant = novo;
            novo->prox = l;
            l = novo;
        }else{
            novo->prox = p;
            novo->ant = anter;
            anter->prox = novo;
            if(p != NULL){
                p->ant = novo;
            }
        }
    }
    return l;
}

void imprimir(ListaDupEnc*l){
    ListaDupEnc* p;
	
	for(p = l; p!= NULL; p = p->prox){
		printf("\n\nMatricula: %d", p->matricula);
		printf("\nMedia: %f", p->media);
		printf("\nSituacao: %c", p->situacao);
	}
}

ListaDupEnc* busca(ListaDupEnc* l, int elemBusca){
    ListaDupEnc* p;
    for (p = l; p!=NULL; p = p->prox){
         if(p->matricula == elemBusca){
            printf("\nElemento %d foi encontrado", p->matricula);
            return p;
         }
    }
    printf("\nO elemento nao pertence a lista");
    return NULL;
}

ListaDupEnc* remover(ListaDupEnc* l, int elemRemove){
   
   ListaDupEnc* p = busca(l, elemRemove);

   if(p->ant == NULL && p->prox != NULL){
       l = p->prox;
   }
   
   if(p->ant != NULL && p->prox != NULL){
       p->ant->prox = p->prox;
       p->prox->ant = p->ant;
   }
   
   if(p->ant != NULL && p->prox == NULL){
       p->ant->prox = NULL;
   }
   free(p);
   return l;
}

ListaDupEnc* liberar (ListaDupEnc*l){
    ListaDupEnc *p = l;
	ListaDupEnc* next;

	while(p != NULL) {
		next = p->prox;
		free(p);
		p = next;
	}
	return p;
}

int tamanhoLista(ListaDupEnc* l){

	ListaDupEnc *aux = l;
	int qtdElem = 0;

	while(aux != NULL){
		qtdElem++;
		aux = aux->prox;
    }
    printf("\nTamanho da lista: %d", qtdElem);
	return qtdElem;
}


int main(int argc, char const *argv[]){
    ListaDupEnc* exemplo;
    exemplo = create();

    exemplo = inserir(exemplo, 1007, 7.8);
    exemplo = inserir(exemplo, 1004, 8.2);
    exemplo = inserir(exemplo, 1001, 6.3);
    exemplo = inserir(exemplo, 1003, 10.0);
    exemplo = inserir(exemplo, 1003, 9.0);
    
    //printf("\n--------------------------------");
    //imprimir(exemplo);
    //printf("\n--------------------------------");
    //busca(exemplo, 1002);
    //printf("\n--------------------------------");
    //imprimir(exemplo);
    //printf("\n--------------------------------");
    tamanhoLista(exemplo);
    //exemplo = remover(exemplo,1003);
    imprimir(exemplo);
    tamanhoLista(exemplo);
    //printf("\n--------------------------------");
    //imprimir(exemplo);
    //printf("\n--------------------------------");

    return 0;
}


