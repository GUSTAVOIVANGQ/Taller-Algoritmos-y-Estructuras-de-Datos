#include <stdio.h>
#include <stdlib.h>

typedef struct info{
	int N;
} Info;

typedef struct nodo{
	
	Info E;
	struct nodo * I;
	struct nodo * D;

} NODO;

typedef NODO * arbol;

arbol crearnodo (Info D);
void insertar ( arbol * raiz, Info D );
void recorridoenorden(arbol raiz);
arbol * buscar(arbol * raiz,Info C);
void borrar(arbol * raiz, Info D);


int main(int argc, char *argv[]) {
	int i,abuscar;
	Info Y;
	arbol A=NULL;
	arbol * B;
	printf("Entradas  \n\n");
	for(i=0;i<10;i++){
	   Y.N=rand();
	   printf("%d , ",Y.N);
	   insertar(&A,Y);
	}
	printf("\n\n"); 
	
	printf("Asi quedo el arbol \n\n");
	recorridoenorden(A);
	printf("\n\nQue valor quieres buscar?");
	scanf("%d",&abuscar);
	Y.N=abuscar;
	B=buscar(&A,Y);
	if ( B!=NULL )
	    printf ("se encontro este es el elemento : %d",(*B)->E.N);
	else
	    printf ("NO esta en el Arbol");
	
	printf("\n\nQue valor quieres borrar?");
	scanf("%d",&abuscar);
	Y.N=abuscar;
	borrar(&A,Y);
	printf("\n\nAsi quedo el arbol \n\n");
	recorridoenorden(A);    
	    
	return 0;
}
void recorridoenorden(arbol raiz){
	 if (raiz == NULL)
	     return;
	 recorridoenorden(raiz->I);
	 printf("%d , ",raiz->E.N);
	 recorridoenorden(raiz->D);	     
}
arbol * buscar(arbol * raiz,Info C){
	 arbol * RI;
	 arbol * RD; 
	 if(*raiz == NULL)
	    return NULL;
	 if( (*raiz)->E.N == C.N )
	    return raiz;   
	 RI=buscar( &((*raiz)->I) ,C);
	 RD=buscar( &((*raiz)->D) ,C);
	 if(RI!=NULL)
	    return RI;
	 if(RD!=NULL)
	    return RD;
	 return NULL;			
}
void borrar(arbol * raiz, Info D){
	 arbol * eb;
	 arbol * mayor;
	 arbol Iz,De,sus;
	 eb=buscar(raiz,D);
	 if (eb==NULL)
	     return;
	 Iz=(*eb)->I;
	 De=(*eb)->D;
	 free(*eb);
	 if ( Iz==NULL && De==NULL ) // es una hoja   
	      *eb=NULL;  
	 else if ( Iz!=NULL && De==NULL ) //tiene un hijo Izq
	 	  *eb=Iz;
	 else if ( Iz==NULL && De!=NULL ) // tiene un hijo Der
	 	  *eb=De;
	 else { // tiene dos hijos el nodo que se quiere borrar
		    // se busca a partir del subarbol Izquierdo el mayor
			mayor=&Iz;
		    while( (*mayor)->D!=NULL )
		        {
		        	mayor=&((*mayor)->D);
				}
			sus=*mayor; // el mayor sera el nodo con el cual se sustituye el que se borro
			*mayor=sus->I;
			sus->I=Iz;	
			sus->D=De;
			*eb=sus;
	}  
}

arbol crearnodo (Info D){
	  arbol nuevo= (arbol)malloc(sizeof(NODO));
	  if (nuevo == NULL)
          return nuevo;
      nuevo->E=D;
	  nuevo->I=nuevo->D=NULL;
	  return nuevo;    
}

void insertar ( arbol * raiz, Info dato ){
	  if(*raiz==NULL)
	     *raiz=crearnodo(dato);
      else if(dato.N < (*raiz)->E.N ){
	     insertar( &((*raiz)->I) , dato);
	  }else{
	     insertar( &((*raiz)->D) , dato);
	  }
}

