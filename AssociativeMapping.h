#include <stdlib.h>
#include <stdio.h>
#include <math.h>


//retorna valor del conjunto de la memoria.
int size_Set_Memory(){
  system("cls");

  int size_Track;//tamano del conjunto en bloques.
  //falta validar.
  printf("Introduzca el tama~o del conjunto en bloques \n");
  printf("1) 2 bloques\n");
  printf("2) 4 bloques\n");
  printf("3) 8 bloques\n");
  scanf("%d", &size_Track);

  switch (size_Track) {
    case 1: return pow (2 , 1);
    case 2: return pow (2 , 2);
    case 3: return pow (2 , 3);
  }
}

//funcion que me devolvera el tamano del conjunto de memoria.
int get_V_Set(int cacheValue , int track){//obtengo d.
  return cacheValue - track;
}
