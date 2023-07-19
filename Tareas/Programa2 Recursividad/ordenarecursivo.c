#include <stdio.h>
#include <stdlib.h>
// Seccion Prototipos 
void ordenar (int * a,int I,int F);
int menor(int * a,int I,int F);

// funcion principal
int main(int argc, char *argv[]) {
	
	int i;
	int W[]={5,6,1,3,7,9,0,2,8,4};
	
	ordenar(W,0,9);
	for(i=0;i<10;i++){
		printf("%d,",W[i]);
	}
	
	return 0;
}

// La funcion recursiva ordenar ordena el arreglo de menor a mayor, siguiendo la misma idea que Seleccion.
// encuentra el menor en una seccion del arreglo y si es distinto al elemento del inicio
// hace el intercambio
void ordenar (int * a,int I,int F){
      // caso base es cuando la seccion del arreglo que se esta ordenando solo tiene un elemento
      // por lo que ya esta ordenado.
      
      // parte recursiva se llama menor() la cual regresa la posicion del elemento menor
      // en la seccion del arreglo delimitado por I y F
      
	  if (   )// si la posicion que regreso menor() es distinto a I
	     {
	          // se hace el intercambio
		 }
		 
	  // Se vuelve a llamar ordenar para la parte restante del arreglo delimitada por I+1 y F	 
  }
  
// La funcion recursiva menor regresa el numero entero de la posicion del elemento menor de la
// seccion del arreglo que se especifique por I y F 
int menor(int * a,int I,int F){
    
}
