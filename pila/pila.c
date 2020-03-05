#include<stdio.h>
#include<stdlib.h>

struct Pila{
	int dato;
	struct Pila *abajo;
};



struct Pila * crear(int dato){
	struct Pila *nueva=NULL;
	
	nueva=(struct Pila *)malloc(sizeof(struct Pila));
	if(nueva==NULL){
		return NULL;
	}
	nueva->dato=dato;
	nueva->abajo=NULL;
	return nueva;
}


struct Pila * push(struct Pila *pila,int dato){
	struct Pila *nuevo=crear (dato);
	nuevo->abajo=pila;
	return nuevo;
	
}


void mostrar(struct Pila *pila){
	while(pila!=NULL){
		printf("%d \n",pila->dato);
		pila=pila->abajo;
		
	}
	printf("\n");
	
}


struct Pila * pop(struct Pila *pila){
	struct Pila *auxdi=pila->abajo;
	int auxdato=pila->dato;
	free(pila);
	pila=auxdi;
	return(pila);
}

int main(void){
	struct Pila *mipila=NULL;
	mipila=crear(10);
	if(mipila==NULL){
		printf("no hay memoria");
		return -1;
	}
	
	mipila=push(mipila,20);
	mipila=push(mipila,25);
	mipila=push(mipila,30);
	mostrar(mipila);
	mipila=pop(mipila);
	mipila=pop(mipila);
	mostrar(mipila);
	return 0;
}
