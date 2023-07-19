/* TAD: Cola de prioridad*/

//estructuras

/*hace uso de dos estructuras, la primera contiene un arreglo de caracteres
para ingresar los nombres de los archivos de la aplicaci�n a dise�ar
tambi�n necesita de un entero sin signo que ser� el que controle la prioridad,
 es decir, la posici�n en donde se ingresaran los datos*/
struct Nodo{
       char archivo[150];
       unsigned int prio;
       struct Nodo *sig;
};
//la segunda estructura contiene dos apuntadores de tipo nodo
//para controlar el ingreso y salida de los elementos
struct Cabecera{
       struct Nodo *p;
       struct Nodo *u;
};

//Se especifican alias, apodos, etiquetas

typedef struct Nodo NODO; // Se etiqueta la estructura 'Nodo' 
typedef struct Nodo *nodo;// y un apuntador del mismo tipo
typedef struct Cabecera CABECERA; // Se etiqueta la estructura 'Cabecera'
typedef struct Cabecera *cola;// y un apuntador del mismo tipo
typedef enum e{NO_MEMORY, VACIA,OK}ERROR;//etiquetas para errores
typedef enum b{FALSE, TRUE}booleano;//y booleanos

//prototipos de funciones

/*
* Funci�n Crear: 
* funci�n de modificaci�n
* Incializa la cola, regresa un mensaje error
* dependiendo de los recursos disponibles en memoria
* Para inicializarla hace que los apuntadores primero y 
* �ltimo que son el inicio y fin de la cola, apunten a NULL
*/
ERROR Crear(cola *c);

/*
* Funci�n Limpiar: 
* Saca todos los elementos existentes en la cola
* hasta que se queda completamtne vac�a
* hace uso de la funci�n Vacia para verificar
* que no haya un solo elemento
* los elementos son removidos con la funcion Sacar
* al contener un solo elemento, manda los apuntadores primero y �ltimo a NULL
* Si la cola est� vac�a desde el inicio, devuelve el valor de vac�a,
* y no hay nada que sacar; si la cola tiene elementos y se vac�a-limpia
* manda un valor de �xito 
*/
ERROR Limpiar(cola c);

/*
* Funci�n Destruir: 
* No devuelve ningun valor 
* limpia completamente la cola
* libera la memoria solicitada
*/
void Destruir(cola *c);

/*
* Funci�n Vacia: 
* Es una funci�n de solo lectura
* Si la cola se encuentra vac�a, esto es, cuando los apuntadores primero y 
* �ltimo apuntan a NULL, devuelve verdadero, de lo contrario, devuelve falso
*/
booleano Vacia(cola c);

/*
* Funci�n Meter: 
* Devuelve un valor de error en caso de que no haya suficiente memoria para
* crear el nuevo nodo e ingresar el dato En caso contrario, devuelve un valor 
* equivalente a una operaci�n exitosa
* Para ingresar el dato, verifica primero la cola, si est� vac�a, solo mueve el 
* primer apuntador. 
* Con el campo de prioridad, verifica en donde debe ir ingresando cada dato
*/
ERROR Meter(cola c, NODO d);

/*
* Funci�n Sacar: 
* Devuelve una copia del dato que se encuentra al principio de la cola
* Mueve los apuntadores primero y ultimo para que queden listos para
* seguir ingresando datos
*/
NODO Sacar(cola c);
