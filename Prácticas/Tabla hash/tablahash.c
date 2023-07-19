#include <stdlib.h>
#include <string.h>
#include "tablahash.h"


mensaje creartabla (tablahash * th, int N){
     int i;
     tablahash temp = (tablahash) malloc (sizeof(tablahash));   
     if ( temp== NULL)
         return NOMEMORY;
     temp->size=N;
	 temp->NR=0;
	 temp->tabla=(tablahash * * ) malloc (sizeof(tablahash *)*N);
	 if (temp->tabla==NULL)    
          return NOMEMORY;
     for (i = 0 ; i<N ; i++)
	      temp->tabla[i]=NULL;
	 *th=temp;     
     return OK;
}
registro * buscar (tablahash th,const long clave){
	registro * r;
	int p;
	if(th==NULL)
	  return NULL;
	p=direccion(th,clave);
	r=th->tabla[p];
	if ( r!= NULL && r->alta == 0)
	    r=NULL;
	return r;       
}
int direccion (tablahash th , const long clave ){
	int i=0,p;
	
	if(th==NULL)
	   return -1;
	p=clave%th->size;
	// ciclo de exploracion
	while( th->tabla[p]!=NULL && th->tabla[p]->boleta != clave ){
		i++;
		p=p+i*i;
		p=p%th->size;
	}
    return p;	
}

mensaje insertar (tablahash th,registro R){
	 
	 int p;
	 registro * temp = (registro * ) malloc (sizeof(registro));
	 
	 if (temp == NULL)
	    return NOMEMORY;
	    
	 temp->boleta=R.boleta;   
	 strcpy(temp->Nombre,R.Nombre);
	 temp->alta=1; 
	 
	 p=direccion(th,R.boleta);
	 
	 if(p == -1 )
	    return NOCREADA;
	    
	 th->tabla[p]=temp;
	 th->NR++;
	 return OK; 
}
mensaje borrar(tablahash th,const long clave){
	
	 int p;
	 
	 p=direccion(th,clave);
	 
	 if(p == -1 )
	    return NOCREADA;
	    
	 if(th->tabla[p]!=NULL)   
	     th->tabla[p]->alta=0;
	 
	 th->NR--;
	 return OK;    
	     
}
void liberartabla(tablahash * th){
	
	
	
	
}