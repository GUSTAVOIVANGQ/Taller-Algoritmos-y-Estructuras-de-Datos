
typedef struct informacion {
	
	// Aqui se pone la informacion que se quiera almacenar
	
} info;


typedef struct nodo {
	
    info Inf;
    struct nodo * sig;
	struct nodo * ant;
  	
} NODO;

typedef struct Cab {
	NODO * I;
	NODO * F;
	int NE;
} cabecera;


// Alias

typedef  cabecera * lista;
typedef  NODO * link;
typedef  enum men { NO_MEMORY , OK , INDEXOUTOFBOUND, EMPTY } mensaje;
typedef  enum b { FALSE , TRUE } booleano;


// Prototipos 

info get ( int pos , lista l );  

link ubicar ( int pos , lista l );                                        

mensaje add ( int pos, info E , lista l );         

mensaje borrar (  int Pos , lista l );                   

booleano empty ( lista l  );
 
mensaje set ( int Pos ,  info E , lista l);      

mensaje  crearlista( lista * l ); 

void  liberarlista( lista * l );  
	   
void Vaciarlista( lista l );      




