#include<stdio.h>
#include<conio.h>
#include<stdlib.h>
#include<string.h>
#include "pila.c"

   char nombre[10] ;
   FILE *fichero;
   /*
int verificarBalanceada(char *mat)
{
    int f;
    for (f=0;f<strlen(mat);f++)
    {
        if (mat[f]=='(' || mat[f]=='[' || mat[f]=='{')
        {
            push(mat[f]);
        }
        else
        {
            if (mat[f]==')')
            {
                if (extraer()!='(')
                {
                    return 0;
                }
            }
            else
            {
                if (mat[f]==']')
                {
                    if (extraer()!='[')
                    {
                        return 0;
                    }
                }
                else
                {
                    if (mat[f]=='}')
                    {
                        if (extraer()!='{')
                        {
                            return 0;
                        }
                    }
                }
            }
        }
    }
    if (empty())
    {
        return 1;
    }
    else
    {
        return 0;
    }
}
 */ 
int main(int argc, char *argv[]) {

   int i=0 ;
	int n;
    char formula[100], archivo[100];
    printf("\t\t prac 1.c\n");
    printf("1.	Archivo 1.c\n");
    printf("2.	Archivo 2.c\n");
    printf("3.	Archivo 3.c\n");
    printf("4.	Archivo 4.c\n");
    printf("5.  Salir\n");
    printf("Dame el numero  de arcivo: ");
    scanf("%d", &n);  
    switch(n) {
	case 1:{
	strcpy(archivo,"1.c"); 
	break; } 
	case 2:{
		strcpy(archivo,"2.c"); 
		break; }
	case 3:{
		strcpy(archivo,"3.c"); 
		break;
	}
	case 4:{
		strcpy(archivo,"4.c"); 
		break;
	}
	default:{
		puts("Error");
		break;
	}
} 


   fichero = fopen(archivo, "r" );
   printf( "Fichero: %s -> ", archivo );
   if( fichero )
      printf( "existe (ABIERTO)\n" );
   else
   {
      printf( "Error (NO ABIERTO)\n" );
      return 1;
   }

 //   char mat[100];
    Info mat ;
    mat.columna= 1 ;
    mat.linea= 1 ; 
    pila p;
   crearpila (&p);
   i=-76 ;
   printf( "Los 18 primeros caracteres del fichero: %s\n\n", nombre );
	while(mat.llave!= EOF){
		if (mat.llave=='\n')
        {
            mat.columna= 1 ;
           mat.linea++ ;
        }else{
            mat.columna++;
                    }
		
	   mat.llave =fgetc(fichero); 
	   
   	printf( "%c", mat.llave  ); 
	   i++;
   	
    int f;
        if (mat.llave=='(' || mat.llave=='[' || mat.llave=='{')
        {
            push (&p,mat);
   			i++;
        }
        else
        {
            if (mat.llave==')')
            {
                if (top(p).llave=='(')
                {
                    pop(&p);i--;
                }
                	else{
                        
                    }
            }
            else
            {
                if (mat.llave==']')
                {
                    if (top(p).llave=='[')
                    {
                        pop(&p);i--;
                    }
                	else{
                    
                    }
                }
                else
                {
                    if (mat.llave=='}')
                    {
                    	
                        if (empty (p))
                        {
                              if (mat.llave==')' || mat.llave==']' || mat.llave=='}')
        						{
        printf("La formula no esta correctamente balanceada\n");
        printf("Error tipo 2 hace falta (, [ o { que abre antes de la  linea %d columna  %d ",mat.linea,mat.columna);
                              return 1;
        						}
                       }
                            else
                        {
                        if (top(p).llave=='{' )
                        {
                            pop(&p);i--;
                        }
                        }
                    }
                }
            }
        }
   }   
   
    if (empty (p))
    {
        printf("La formula esta correctamente balanceada");
    }
    else
    {
    	
		if (i>=2)
        {        printf("La formula no esta correctamente balanceada\n");
        printf("Error tipo 3   %c  que esta en la línea %d columna  %d  no es del mismo tipo que  %c  de la línea %d columna  %d ",pop(&p).llave,top(p).linea,top(p).columna,pop(&p).llave,top(p).linea,top(p).columna );
        }else{        printf("La formula no esta correctamente balanceada\n");
        printf("Error tipo 1 hace falta ), ] o } a partir de la linea %d columna  %d ",top(p).linea,top(p).columna);
                    }
		

        
    }
//void cargarFormula(char *formula)

   if( !fclose(fichero) )
      printf( "\nFichero cerrado\n" );
   else
   {
      printf( "\nError: fichero NO CERRADO\n" );
      return 1;
   }/*
 // cargarFormula(char *formula)
  //  printf("Ingrese la formula:");
 //   gets(formula);
    if (verificarBalanceada(mat))
    {
        printf("La formula esta correctamente balanceada");
    }
    else
    {
        printf("La formula no esta correctamente balanceada");
    }
 */ 
	return 0;
}
