#include <stdio.h>
#include <stdlib.h>
#include "tablahash.c"
#define NA 3
/* run this program using the console pauser or add your own getch, system("pause") or input loop */

int main(int argc, char *argv[]) {
	int i,opcion=1;
	long boleta;
	registro R;
	registro * Alumno;
	
	tablahash TH;
	
	creartabla(&TH,2503);
		
	for (i=0;i<NA;i++){
		
		printf("Numero de boleta:");
		scanf("%d",&R.boleta);
		printf("Nombre:");
		scanf("%s",R.Nombre);
		insertar(TH,R);
		
	}
	
	while(opcion==1){
	
	
		printf("buscar que Alumno con boleta:");
		scanf("%d",&boleta);
	
		Alumno=buscar(TH,boleta);
	
	
		if (Alumno == NULL)
			{
	 			 printf("No se encontro ese Alumno \n");
			}else{
	  			printf("Alumno: %s  con Boleta: %d \n" , Alumno->Nombre , Alumno->boleta);	
			}
        printf("Buscar otro teclea 1");
		scanf("%d",&opcion);	
    }
	
	
	
	return 0;
}
