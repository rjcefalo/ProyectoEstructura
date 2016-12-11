#include "UtilidadesLista.h"
#include "operationDirecto.h"

void direccion(lista **p,int x){
	int aux=get_Exponent_Value(size_Main_Memory());
	for (int i =0;i<aux;i++){
		lista *t=new lista;
		t->valor=x%2;		
		if (vacio(*p)){
			t->sig=NULL;
			*p=t;			
		}
		else{
			t->sig=*p;
			*p=t;
		}
			
		x=x/2;
	}
}

void printList(lista *p){	
	if(p){
		printf("[%i]->", p->valor);
		if ((p->sig)==NULL)
			printf("NULL");
		if (p->sig)
		printList(p->sig);
	}

}

void calculoMapeoDirecto(lista **p){
	int main_Memory_Exp, cache_Memory_Exp,blocks_Memory, LINE, TAG, x;
	printf("Indique direccion: \n");
	scanf("%i", &x);
	main_Memory_Exp = get_Exponent_Value(size_Main_Memory());
	//system("cls");
    cache_Memory_Exp = get_Exponent_Value(size_Cache_Memory());
   // system("cls");
    blocks_Memory = get_Exponent_Value(size_Block_Memory());//este seria el valor del modulo de bytes en el mapeo o la cantidad de palabras;
    LINE = get_Line_Value(cache_Memory_Exp , blocks_Memory);
    TAG = get_TAG_Value(main_Memory_Exp , LINE , blocks_Memory);
	//Calculo Binario de Direccion
	
	for (int i =0;i<main_Memory_Exp;i++){
		lista *t=new lista;
		t->valor=x%2;		
		if (vacio(*p)){
			t->sig=NULL;
			*p=t;			
		}
		else{
			t->sig=*p;
			*p=t;
		}			
		x=x/2;
	}
	
	//Asignacion de etiquetas
	lista *etiqueta = *p;
	lista *linea = *p;
	lista *byte = *p;
	
	etiqueta=*p;
	for (int i =0 ; i < TAG; i++)
		linea = linea->sig;
	for (int i =0 ; i < (TAG+LINE); i++)
		byte = byte->sig;
	
	//Impresion de etiquetas
	printf("\nEtiqueta: \n");
	for (int i =0 ; i < TAG; i++){

		printf("[%i]->",etiqueta->valor);
		etiqueta=etiqueta->sig;
	}

	lista *lineaEnCache=linea;//referencia al inicio de la linea para numero de linea en cache

	printf("\nLinea [%i]: \n", LINE);
	for (int i =0 ; i < LINE; i++){

		printf("[%i]->",linea->valor);
		linea=linea->sig;
	}
	printf("\nByte: \n");
	for (int i =0 ; i < (main_Memory_Exp-TAG-LINE) ; i++){

		printf("[%i]->",byte->valor);
		byte=byte->sig;
	}
	printf("\n\n");

	int lineaCache=0;
	for (int i=LINE-1; i>=0;i--){
		lineaCache=lineaCache+((lineaEnCache->valor)*((double)pow((double)2 , (double)i)));
		lineaEnCache=lineaEnCache->sig;
	}
	printf("\nEl bloque se coloca en la linea %i de la memoria cache\n",lineaCache);

}

