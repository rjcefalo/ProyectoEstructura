#include <stdlib.h>
#include <stdio.h>
#include "operation.h"//Archivo donde se tienen declaradas todas las operaciones a realizar en el programa.
#include "print.h"//;archivo que tendra todas las funciones que me muestran por pantalla.
//prototipo de funciones/metodos.
void User_Menu();
void Mapping_Menu();

void User_Menu(){  //funcion que le permite al usuario escoger opcion principal.
  int option ,x;


    do{
      system("cls");
      printf("Aviso: Favor introducir un valor numerico.\n");
      printf("1) Modulo 1: Mapeo de memoria\n");
      printf("2) Modulo 2: Ubicacion de bloques\n");
      printf("3) Modulo 3: Simulador de reemplazo de bloques\n");
      printf("4) Salir del programa\n");
      scanf("%d" , &option);
     if(option == 1) Mapping_Menu();

     if ((option < 1) || (option > 4)){
       printf("Introduzca una opcion correcta\n");
       system("pause");
       system("cls");
     }

    }while(option != 4);//deberia de validar con otro tipo de datos que no sean enteros.
}

void Mapping_Menu(){
  //necesito las siguientes variables locales.
  int typeMapping , main_Memory_Exp, cache_Memory_Exp , blocks_Memory , TAG , LINE;

  //falta validar.
  system("cls");
  printf("introducir el tipo de mapeo que deasea\n");
  printf("1) Mapeo directo\n");
  printf("2) Mapeo asociativo por conjunto\n");
  scanf("%d", &typeMapping);

  if (typeMapping == 1){
    //obtengo los valores que necesito para realiar mi mapeo.
    main_Memory_Exp = get_Exponent_Value(size_Main_Memory());
    system("cls");
    cache_Memory_Exp = get_Exponent_Value(size_Cache_Memory());
    system("cls");
    blocks_Memory = get_Exponent_Value(size_Block_Memory());//este seria el valor del modulo de bytes en el mapeo o la cantidad de palabras;
    LINE = get_Line_Value(cache_Memory_Exp , blocks_Memory);
    TAG = get_TAG_Value(main_Memory_Exp , LINE , blocks_Memory);
    print_Direct_Mapping(TAG , LINE , blocks_Memory);
  }
}

void main(){
  //llamada a metodos;
  User_Menu();
  system("pause");
}
