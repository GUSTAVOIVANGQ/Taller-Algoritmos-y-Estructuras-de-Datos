#include<stdlib.h>
#include "cola.h"

  mensaje encolar(cola c,Info D){
  	   
  	   conexion temp=(conexion)malloc(sizeof(NODO));
	   if(temp==NULL)
	      return NOMEMORY;	 
	   temp->E=D;
  	   temp->ant=NULL;
  	   
  	   if (empty(c))
  	    {
  	    	c->I=c->F=temp;
		}else{  //hay elementos en la cola
			c->F->ant=temp;
			c->F=temp;
		}
  	
  	    return OK;
  }
  
  Info desencolar( cola C ){
  	Info copia;
  	conexion aux;
  	copia=C->I->E; // paso 1
  	aux=C->I->ant;
  	if( C->I != NULL && C->I==C->F ) // Un elemento
  	       C->F=NULL;
    free(C->I);
    C->I=aux;
    return copia;
  }
  
  booleano empty( cola C ){
  	
  	   if (C!=NULL && C->I == NULL && C->F == NULL)
  	         return TRUE;
  	   return FALSE;      
  	         
  }
  
  mensaje crearcola ( cola * C ){
  	    cola temp=(cola)malloc(sizeof(cabecera));
  	    if (temp == NULL)
  	       return NOMEMORY;
  	    temp->F=temp->I=NULL;
		*C = temp;
		return OK;   
  }
  
  void vaciarcola ( cola C ){
  	   while(!empty(C)){
  	   	      desencolar(C);
		 }
  }
 void liberarcola ( cola * C ){
 	  vaciarcola(*C);
 	  free(*C);
 	  *C=NULL;
 }
