#include <stdio.h>
#include <stdlib.h>
#include <string.h>


struct lista {
	int valor;
	lista *sig;
};

int vacio(lista *p){
	return (p==NULL);
}
void alistar (lista **p, int x){
	lista *t = new lista;
	t->valor = x;
	t->sig = *p;
	*p=t;
}

void desalistar(lista **p){
	if(!vacio(*p)){
		lista *aux=*p;
		*p=(*p)->sig;
		delete aux;
	}
}