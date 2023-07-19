#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "pila.c"

 void reco_orden (BTN * Arbol);
 void post_orden (BTN * Arbol);
 void pre_orden (BTN * Arbol);
 long evaluar (BTN * Arbol);

int main(int argc, char *argv[]) {
	int i;
	char exp [100]="253*+";
	pila num;
	char c;
	INFO dato;
	BTN * arbol;
	BTN * branch;
	
	crearpila(&num);
	
	for(i=0;i<strlen(exp);i++){
		c=exp[i];
		branch=(BTN *)malloc(sizeof(BTN));
        branch->N_OP=c;
		if (c>='0'&&c<='9'){
			branch->I=branch->D=NULL;
		}else{
			branch->D=pop(&num).rama;
			branch->I=pop(&num).rama;
		}
		dato.rama=branch;
	    push(&num,dato);	
	}
	
   arbol=pop(&num).rama;
   reco_orden (arbol);
   printf("\n%ld",evaluar(arbol));
  	
   return 0;
}
void post_orden (BTN * Arbol){
	  if (Arbol == NULL)
	      return;
	  post_orden (Arbol->I);
	  post_orden (Arbol->D);
	  printf("%c",Arbol->N_OP);
}

void reco_orden (BTN * Arbol){
	  if (Arbol == NULL)
	      return;
	  reco_orden (Arbol->I);
	  printf("%c",Arbol->N_OP);
	  reco_orden (Arbol->D);
}

void pre_orden (BTN * Arbol){
	  if (Arbol == NULL)
	      return;
	  printf("%c",Arbol->N_OP);    
	  pre_orden (Arbol->I);
	  pre_orden (Arbol->D);
}

long evaluar(BTN * Arbol){
	long Num1,Num2;
	if(Arbol!=NULL&&Arbol->I==NULL&&Arbol->D==NULL)
	   return (long) Arbol->N_OP-'0';
	Num1=evaluar (Arbol->I);
	Num2=evaluar (Arbol->D);
	switch(Arbol->N_OP){
		case '+':
			     return Num1+Num2;
		case '-':
			     return Num1-Num2;
		case '*':
			     return Num1*Num2;
		case '/':
			     return Num1/Num2;
	}
	
}
