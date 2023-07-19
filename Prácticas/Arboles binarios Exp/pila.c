#include "pila.h"
#include <stdlib.h>

 mensaje push (pila * p,INFO C){
 	
 	pila temp;
 	// paso 1
 	temp=(pila) malloc (sizeof(NODO));
 	if(temp==NULL)
 	    return NOMEMORY;
    
 	temp->E=C; // paso 2
 	
 	temp->sig=*p; // paso 3
 	
 	*p=temp; // paso 4
 	
 	return OK;
 }
 
 INFO pop (pila * p){
 	INFO copia;
 	pila aux;
 	
 	aux=*p; // paso 0
 	
 	copia=(*p)->E; // paso 1
 	
 	*p=(*p)->sig; // paso 2
 	
 	free(aux); // paso 3
 	
 	return copia; // paso 4
 }
 
 
 booleano empty (pila p){
 	  if(p==NULL)
 	      return TRUE;
 	  return FALSE;
 }

 INFO top (pila p){
 	  INFO copia;
 	  copia=p->E;
 	  return copia;	
 }
 
 void crearpila(pila * p){
 	*p=NULL; // representa que la pila esta vacia y lista para usarse
 }
 void liberarpila(pila * p){
 	  while(!empty(*p)){
 	  	    pop(p);
	   }	
 }



