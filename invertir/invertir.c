#include<stdio.h>
#include<stdlib.h>

struct Lista{
	int dato;
	struct Lista *siguiente;
};

struct Lista * crear(int dato){
	struct Lista *nuevo=NULL;
	
	nuevo=(struct Lista *)malloc(sizeof(struct Lista));
	if(nuevo==NULL){
		return NULL;
	}
	
	nuevo->dato=dato;
	nuevo->siguiente=NULL;
	return nuevo;
}

struct Lista * insertar(struct Lista *lista, int dato){
	struct Lista * nueva=crear(dato);
	nueva->siguiente=lista;
}

void mostrar(struct Lista *lista){
	while(lista!=NULL){
		printf("%d, ", lista->dato);
		lista=lista->siguiente;
	}
	printf("\n");
	
	invertir();
}

struct Lista * invertir(struct Lista *lista, int dato){
	struct Lista * nueva=crear(dato);
	int i=0;
	nueva->siguiente=lista;
	
	for(i=1;i<4;i++){
		
	}
}



int main(void){
	struct Lista * miLista=crear(10);
	
	if(miLista==NULL){
		printf("No se puede crear la lista, por falta de memoria");
		return -1;
	}
	
	miLista=insertar(miLista,12);
	miLista=insertar(miLista,27);
	miLista=insertar(miLista,2020);
	miLista=insertar(miLista,1);
	mostrar(miLista);
}

