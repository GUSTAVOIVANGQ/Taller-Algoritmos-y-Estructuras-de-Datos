typedef struct Inf {

   int cliente;
   int tiempo_atencion;
 
} Info;


typedef struct nodo {
	
	Info E;
	struct nodo * ant;

 } NODO;
 
 
typedef struct Cab {
 	
     NODO * I;
	 NODO * F;	
 	
 } cabecera;


// seccion de alias
typedef NODO * conexion;
typedef cabecera * cola;
typedef enum B { FALSE , TRUE } booleano;
typedef enum m { NOMEMORY , OK } mensaje;

// Prototipos

 mensaje crearcola ( cola * C );
 void vaciarcola ( cola C );
 void liberarcola ( cola * C ); 


 mensaje encolar(cola C , Info I);
 Info desencolar( cola C ); 
 booleano empty( cola C );
 void mostrarcola( cola C);

