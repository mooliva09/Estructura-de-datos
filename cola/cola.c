#include <stdio.h>
#include <stdlib.h>

struct cola{
   int elementos[100];
   int frente;
   int detras;
};


struct cola* crear(struct cola*Cola,int dato){
	struct cola *nuevo=(struct cola*)malloc(sizeof(struct cola));
	if(nuevo==NULL){
		printf("\nNo hay memoria");
	}
	else{
		nuevo->frente=0;
		nuevo->detras=-1;
		nuevo->elementos[++nuevo->detras]=dato;
	}
	return nuevo;
}

void agregar(struct cola *Cola,int elemento){
	if (Cola->detras==100)
        printf("\nLa cola está llena");
    else
        Cola->elementos[++Cola->detras]=elemento;
}

void eliminar(struct cola *Cola){
	if (Cola->detras ==-1)
        printf("\n No hay elementos en la cola");
    else
     ++Cola->frente;
}	


void mostrar(struct cola* Cola){
	if (Cola->detras==-1)
        printf("\n No hay elementos en la cola");
    else{
	
    int i=Cola->frente;
    
    while(i<=Cola->detras){
    	printf("%d,",Cola->elementos[i]);
    	++i;
	}
	printf("\n");
}	
}



int main(void){
	struct cola *Cola=NULL;
	Cola=crear(Cola,5);
    agregar(Cola,1);
    agregar(Cola,2);
    agregar(Cola,3);
    agregar(Cola,4);
    mostrar(Cola);
    eliminar(Cola);
    eliminar(Cola);
    mostrar(Cola);
   return 0;
}
