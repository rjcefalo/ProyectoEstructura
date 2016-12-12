#include <stdio.h>
#include <stdlib.h>
#include <math.h>

float LogBase2(float x){
	float resultado;
	resultado= (log(x)/log((float) 2));

	return resultado;
}

int size_Main_Memory(){
  system("cls");
  int size_MM;
    //falta validar.
    printf("Introduzca el tamano de la memoria principal\n");
    printf("1) 256 KB\n");
    printf("2) 512 KB\n");
    printf("3) 1 MB\n");
    printf("4) 2 MB\n");
    printf("5) 4 MB\n");
    printf("6) 8 MB\n");
    printf("7) 16 MB\n");
    printf("8) 32 MB\n");
    scanf("%d", &size_MM);

    switch (size_MM) {
      case 1: return (double)pow((double)2 , (double)18);
      case 2: return (double)pow((double)2 , (double)19);
      case 3: return (double)pow((double)2 , (double)20);
      case 4: return (double)pow((double)2 , (double)21);
      case 5: return (double)pow((double)2 , (double)22);
      case 6: return (double)pow((double)2 , (double)23);
      case 7: return (double)pow((double)2 , (double)24);
      case 8: return (double)pow((double)2 , (double)25);
    }
}
//funcion que me retorna el valor que el usuario escoja de la memoria cache.
int size_Cache_Memory(){
  system("cls");
  int size_MC;
  //falta validar;
  printf("Introduzca el tama~o de la memoria cache\n");
  printf("1) 64 B\n");
  printf("2) 128 B\n");
  printf("3) 256 B\n");
  printf("4) 512 B\n");
  printf("5) 1 kB\n");
  scanf("%d", &size_MC);

  switch (size_MC) {
    case 1: return (double)pow((double)2 , (double)6);
    case 2: return (double)pow((double)2 , (double)7);
    case 3: return (double)pow((double)2 , (double)8);
    case 4: return (double)pow((double)2 , (double)9);
    case 5: return (double)pow((double)2 , (double)10);
  }
}
//funcion que me retorna cantidad de bloques
int size_Block_Memory(){
  system("cls");
  int size_Block;
    //falta validar.
    printf("Introduzca el tamano del bloque en bytes\n");
    printf("1) 2 B\n");
    printf("2) 4 B\n");
    printf("3) 8 B\n");
    printf("4) 16 B\n");
    printf("5) 32 B\n");
    scanf("%d", &size_Block);

    switch (size_Block) {
      case 1: return (double)pow((double)2 , (double)1);
      case 2: return (double)pow((double)2 , (double)2);
      case 3: return (double)pow((double)2 , (double)3);
      case 4: return (double)pow((double)2 , (double)4);
      case 5: return (double)pow((double)2 , (double)5);
    }
}
//funcion que me retorna el exponente de cada valor dado.
int get_Exponent_Value(int number){
  int exponent = 0;

    while (number != 1){
      number = number/2;
      exponent ++;
    }

  return exponent;
}
//funcion que me retorna la longitud de la etiqueta(TAG) en memoria.
int get_TAG_Value(int MM_Value , int line_Size , int words_Size){
  return MM_Value - line_Size - words_Size;
}
//funcion que rertorna el tamano del bloque.
int get_Line_Value(int MC_Exponent , int blocks_Size_Exp){
  return  MC_Exponent - blocks_Size_Exp;
}