 
typedef struct btn {
 	char N_OP;
 	struct btn * I;
 	struct btn * D;
 } BTN;

struct info {
    BTN * rama;	
};

struct nodo{
	struct info E;
	struct nodo * sig;
};

// seccion de alias

typedef struct nodo NODO;
typedef struct info INFO;
typedef NODO * pila;
typedef enum b { FALSE, TRUE } booleano;
typedef enum men { OK, NOMEMORY,VACIA} mensaje;

/* un enum enumeracion en c es una coleccion de constantes literales


 enum simp { BART=12, HOMER , MAGGIE , MARGE , LISA };
 
 #define BART 0
 #define HOMER 1
 
 
 int personaje;
 if (a==0)
 if (personaje == BART)
    printf("ay caramba");

*/
 mensaje push (pila * p,INFO E);
  // Antes de llamar TOP y POP se debe verificar que la pila no este vacia
 INFO pop (pila * p);
 INFO top (pila p);
 booleano empty (pila p);
 void crearpila(pila * p);
 void liberarpila(pila * p);
 
 

