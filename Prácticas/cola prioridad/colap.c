/* TAD: Cola de Prioridad*/

#include "colap.h"
#include <stdio.h>
#include <stdlib.h>

/*
* Función Crear: 
* función de modificación
* Incializa la cola, regresa un mensaje error
* dependiendo de los recursos disponibles en memoria
* Para inicializarla hace que los apuntadores primero y 
* último que son el inicio y fin de la cola, apunten a NULL
*/

ERROR Crear(cola *c){
      *c=(cola)malloc(sizeof(CABECERA));
      if (*c==NULL)
         return NO_MEMORY;
      (*c)->u=(*c)->p=NULL;
      return OK;
}

/*
* Función Limpiar: 
* Saca todos los elementos existentes en la cola
* hasta que se queda completamtne vacía
* hace uso de la función Vacia para verificar
* que no haya un solo elemento
* los elementos son removidos con la funcion Sacar
* al contener un solo elemento, manda los apuntadores primero y último a NULL
* Si la cola está vacía desde el inicio, devuelve el valor de vacía,
* y no hay nada que sacar; si la cola tiene elementos y se vacía-limpia
* manda un valor de éxito 
*/
       
ERROR Limpiar(cola c){
      if (Vacia(c))
         return VACIA;
      while (!(Vacia(c)))
            Sacar(c);
      c->p = c->u = NULL;
      return OK;
}

/*
* Función Destruir: 
* No devuelve ningun valor 
* limpia completamente la cola
* libera la memoria solicitada
*/

void Destruir(cola *c){
     Limpiar(*c);
     free(*c);
     *c=NULL;
}

/*
* Función Vacia: 
* Es una función de solo lectura
* Si la cola se encuentra vacía, esto es, cuando los apuntadores primero y 
* último apuntan a NULL, devuelve verdadero, de lo contrario, devuelve falso
*/

booleano Vacia(cola c){
         if (c->u ==NULL && c->p==NULL)
            return TRUE;
         return FALSE;
}

/*
* Función Meter: 
* Devuelve un valor de error en caso de que no haya suficiente memoria para
* crear el nuevo nodo e ingresar el dato En caso contrario, devuelve un valor 
* equivalente a una operación exitosa
* Para ingresar el dato, verifica primero la cola, si está vacía, solo mueve el 
* primer apuntador. 
* Con el campo de prioridad, verifica en donde debe ir ingresando cada dato
*/

ERROR Meter(cola c, NODO d){
      nodo temp = NULL;
      nodo aux = NULL;
      temp=(nodo)malloc(sizeof(NODO));
      if (temp==NULL)
         return NO_MEMORY;
      *temp=d;
      temp->sig=NULL;       
      if (Vacia(c)){                    
         c->p=c->u=temp; 
         return OK;
      }
      if (temp->prio > c->p->prio){
         temp->sig = c->p;
         c->p =temp;
         return OK;
      }
      aux = c->p;      
      while ( aux->sig!=NULL && aux->sig->prio >= temp->prio)
            aux = aux->sig;
            if (aux->sig==NULL)
               c->u=temp;
            else
                temp->sig = aux->sig;
      aux->sig =temp;
      return OK;            
}

/*
* Función Sacar: 
* Devuelve una copia del dato que se encuentra al principio de la cola
* Mueve los apuntadores primero y ultimo para que queden listos para
* seguir ingresando datos
*/

NODO Sacar(cola c){
     NODO temp; 
     temp=*(c->p);
     if (c->p==c->u )
        c->p=c->u=NULL;
     else{
          c->p=c->p->sig;
          temp.sig = NULL;
     }
     return temp;
}
