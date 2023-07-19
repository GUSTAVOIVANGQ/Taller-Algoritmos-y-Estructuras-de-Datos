#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "lista.c"

main(){
	
	lista l;
	info dato;
	int i;
	link Aux;
	
	
	crearlista(&l);
	
    strcpy(dato.palabra,"pulque");
    add(0,dato,l);
    strcpy(dato.palabra,"tequila");
    add(1,dato,l);
    strcpy(dato.palabra,"Chela");
    add(1,dato,l);
    
    for(i=0;i<l->NE;i++){
		
		printf("%s\n",get(i,l).palabra);
	}
    //borrar(1,l);
    ordenarAsc(l);
     
	
	
	
	for(i=0;i<l->NE;i++){
		
		printf("%s\n",get(i,l).palabra);
	}
	
}


