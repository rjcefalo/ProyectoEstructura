#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct lista {
	int valor;
	struct lista *sig;
}lista;


int vacio(lista *p){
	return (p==NULL);
}
/*
void alistar (lista **p, int x){
  lista *t = (lista *)malloc(sizeof(lista));
	t->valor = x;
	t->sig = *p;
	//*p=t;
}*/