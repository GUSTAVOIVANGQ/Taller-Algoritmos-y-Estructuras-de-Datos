#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "cola.c"


typedef enum c{uno,dos,tres}tiempos;


void mostrarcajas(cola,cola,cola);
int atender(cola,tiempos, int *);
void espera(int *, int *, int *);

int main(int argc, char *argv[]) {
	
	srand(time(NULL));
	cola caja0, caja1,caja2;
	
	
	int *e1, *e2, *e3;
	int clientes=0,clientesA=0,caja;
	char opcion;
	Info capsula;
	
	crearcola(&caja0);
	crearcola(&caja1);
	crearcola(&caja2);
	
	printf("\t\t\tBIENVENIDO A ESCOMARKET\n");
	do
	{
		fflush(stdin);
		if(clientes==0)
		{
			printf("CAJA 0: ESTA SIN CLIENTES\n\n");
			printf("CAJA 1: ESTA SIN CLIENTES\n\n");
			printf("CAJA 2: ESTA SIN CLIENTES\n\n");
		}
		printf("\t\tHasta ahora se han formado %d clientes\n",clientes);
		printf("Da click en enter para introducir un cliente: \n\n");
		opcion = getchar();
		
		if(opcion == '\n')
		{
			caja = rand()%3;
			
			printf("\n\nAtendiendo los clientes: \n");
			clientes++;
			if(clientesA<10)
			{	
				
				switch(caja)
				{
					case 0: 
						{						
							capsula.cliente = clientes;
							capsula.tiempo_atencion = 130;
							encolar(caja0,capsula);					
						}
					break;
				
					case 1:
						{	
							capsula.cliente=clientes;
							capsula.tiempo_atencion = 150;
							encolar(caja1,capsula);
						}
					break;
					
					case 2:
						{
							capsula.cliente=clientes;
							capsula.tiempo_atencion = 170;
							encolar(caja2,capsula);
						}
					break;				
				}
			}
			
			clientesA += atender(caja0,uno,&e1);
			clientesA += atender(caja1,dos,&e2);
			clientesA += atender(caja2,tres,&e3);
			
			espera(&e1, &e2, &e3);
			mostrarcajas(caja0,caja1,caja2);
		}
		else
		{
			printf("\t\t\t\tDebes presionar solo enter...\n\n\n");
		}
		
	}while( !empty(caja0)||!empty(caja1)||!empty(caja2)||(clientesA<=10) );
	
	printf("\n\n\t\t\tESCOMART ha cerrado \nEn total se atendieron %d clientes", clientesA-1);
	printf("\nGracias por su visita, vuelva pronto!! :)");
	return 0;
}


void mostrarcajas(cola caja0,cola caja1,cola caja2)
{
	if(empty(caja0))
	{
		printf("\nCAJA 0: ");
		mostrarcola(caja0);
		printf("ESTA SIN CLIENTES");
		printf("\n\n");
	}
	else
	{
		printf("\nCAJA 0: ");
		mostrarcola(caja0);
		printf("\n\n");
	}
	
	if(empty(caja1))
	{
		printf("CAJA 1: ");
		mostrarcola(caja1);
		printf("ESTA SIN CLIENTES");
		printf("\n\n");
	}
	else
	{
		printf("CAJA 1: ");
		mostrarcola(caja1);
		printf("\n\n");
	}
	
	if(empty(caja2))
	{
		printf("CAJA 2: ");
		mostrarcola(caja2);
		printf("ESTA SIN CLIENTES");
		printf("\n\n");
	}
	else
	{
		printf("CAJA 2: ");
		mostrarcola(caja2);
		printf("\n\n");
	}
}


int atender(cola c,tiempos t, int *e)
{
	int copia;
	int atendidos = 0;
	
	if(!empty(c))
	{
		copia = c->I->E.tiempo_atencion;
		copia -= 40;
		if(copia <= 0)
		{
			switch(t)
			{
				case 0:
					{
						copia += 90;
					}
				break;
			
				case 1:
					{
						copia += 110; 
					}
				break;
			
				case 2:
					{
						copia += 130;
					}
				break;
			}
			printf("\n\t\t\tSe termino de atender al cliente %d",desencolar(c).cliente);
			atendidos = 1;
		}
		
		if(!empty(c))
		{
			c->I->E.tiempo_atencion = copia;
		}
			*e = copia;
		
		return atendidos;
	}
	
	else
	{
		copia = 0;
		*e = copia;
		return 0;
	}
}

void espera(int *e1, int *e2, int *e3)
{
	printf("\ntiempo de espera de la caja0 --- %d segundos\n",*e1);
	printf("tiempo de espera de la caja1 --- %d segundos\n",*e2);
	printf("tiempo de espera de la caja2 --- %d segundos\n",*e3);
}
