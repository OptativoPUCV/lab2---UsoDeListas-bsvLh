#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <ctype.h>
#include "arraylist.h"
#include "stack.h"

//#include "exercises.h"

//Funciones auxiliares que puedes utilizar para debuggear tus ejercicios
//NO MODIFICAR
void imprime_lista(List *L) {
   int *dato;
   dato = (int*)first(L);
   printf("[");
   while(dato != NULL) {
      printf("%d ", *dato);
      dato = (int*)next(L);
   }
   printf("]\n");

}

//Ojo que la pila se vacía al imprimir y se imprime en orden inverso
//NO MODIFICAR
void imprime_y_vacia_pila(Stack *P) {
   void *dato;
   printf("[");
   while((dato = pop(P)) != NULL) {
      printf("%d ", *(int*)dato);
   }
   printf("]\n");
}

/* 
Ejercicio 1.
Crea una Lista y agrega punteros a elementos del 1 al 10.
Recuerda que la lista almacena punteros, por lo que
debes reservar memoria para cada elemento que agregues.
Al finalizar retorna la lista creada.
*/

List* crea_lista() {
  List* L = create_list();
  int *arreglo = NULL;
  arreglo = (int*)malloc(sizeof(int) * 10);
  if (arreglo == NULL) exit(EXIT_FAILURE);
  
  for(int i = 0; i < 10; i++)
    {
      arreglo[i] = i + 1;
      pushBack(L, &arreglo[i]);
    }
  return L;
}

/*
Ejercicio 2.
Crea una función que reciba una lista de enteros (int*) y 
retorne la suma de sus elementos.
*/
int sumaLista(List *L) 
{
  int suma = 0;
  int *aux = first(L);
  while (aux != NULL)
    {
      suma += (*aux);
      aux = next(L);
    }

   return suma;
}

/*
Ejercicio 3.
Crea una función que reciba una lista de punteros a int (int*) y
un entero elem. La función debe eliminar todos los elementos 
de la lista que sean iguales a elem.
Asume que popCurrent luego de eliminar un elemento se
posiciona en el elemento anterior.
*/

void eliminaElementos(List*L, int elem)
{
  int *aux = first(L);
  while (aux != NULL)
    {
      if (*aux == elem)
      {
        popCurrent(L);
      }
      aux = next(L);
    }
}

/*
Ejercicio 4.
La función copia los punteros de la pila P1 en la pila P2.
El orden de ambas pilas se debe mantener.
Puedes usar una pila auxiliar.
*/

void copia_pila(Stack* P1, Stack* P2) 
{
  Stack* P3 = create_stack();
  while (top(P1) != NULL)
    {
      int *aux = top(P1);
      push(P3, aux);
      pop(P1);
    }
  
  while (top(P3) != NULL)
    {
      int *aux = top(P3);
      push(P1, aux);
      push(P2, aux);
      pop(P3);
    }
  
}

/*
Ejercicio 5.
La función verifica si la cadena de entrada tiene sus 
paraéntesis balanceados. Retorna 1 si están balanceados,
0 en caso contrario.
*/

int parentesisBalanceados(char *cadena)
{
  int largo = strlen(cadena);
  int i = 0;
  int j = 0;
  while (i < largo / 2)
    {
      j = largo - 1 - i;
      if (cadena[i] + 1 == cadena[j] || cadena[i] + 2 == cadena[j]) i++;
      else
          return 0;
    }
   return 1;
}

