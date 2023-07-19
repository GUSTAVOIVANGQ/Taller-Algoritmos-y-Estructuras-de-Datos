typedef struct reg {
    long boleta;
    char Nombre [50];
    char alta;
  } registro;
  
typedef struct t {
  	 int size;
  	 int NR;
  	 registro * * tabla;
  } td;
  
typedef td * tablahash; 
typedef enum m { NOMEMORY , OK , NOCREADA } mensaje;  
 
int direccion (tablahash th,const long boleta);  
mensaje creartabla (tablahash * th, int N);
mensaje insertar (tablahash th,registro R);
mensaje borrar(tablahash th,const long boleta);
registro * buscar (tablahash th,const long clave);
void liberartabla(tablahash * th);


