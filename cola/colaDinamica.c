#include <stdio.h>
#include <stdlib.h>


struct Cola{
	struct Cola * sig;
	int dato;
};

struct Cola * crear(int dato){
	struct Cola *nuevo=NULL;
	nuevo=(struct Cola *)malloc(sizeof(struct Cola));
	
	if(nuevo==NULL){
		printf("\nNo hay memoria sufuciente");
		return NULL;
	}
	
	nuevo->sig=NULL;
	nuevo->dato=dato;
}

struct Cola * encolar(struct Cola * cola,int dato){
    struct Cola * nuevo=NULL;
    struct Cola * aux=cola;
    while(aux->sig != NULL){
    	aux=aux->sig;
	}
	nuevo=crear(dato);
	aux->sig=nuevo;
	
	return cola;
}

void mostrar(struct Cola * cola){
	if(cola==NULL){
		printf("\nNo hay una cola que mostrar");
		return;
	}
	printf("\n");
	while(cola != NULL){
		printf("%d,",cola->dato);
		cola=cola->sig;
	}
}

struct Cola * desencolar(struct Cola * cola){
	if(cola==NULL){
		printf("\nNo hay una cola de la cual eliminar");
		return NULL;
	}
	struct Cola * aux=cola->sig;
	free(cola);
	return aux;
}

int main(void){
	struct Cola * cola=NULL;
	int opc=0;
	int dato=0;
	printf("----------Cola dinamica----------\n");
	
	while(opc != 4){
	printf("\nEscoja una de las siguientes opciones:\n");
	printf("1.-Agregar\n2.-Mostrar\n3.-Eliminar\n4.-Salir\n");
	scanf("%d",&opc);
	if(opc==1){
		if(cola==NULL){
			printf("\nEscriba el dato que va a meter en la cola:\n");
			scanf("%d",&dato);
			cola=crear(dato);
		}
		else{
			printf("\nEscriba el dato que va a meter en la cola:\n");
			scanf("%d",&dato);
			cola=encolar(cola,dato);
		}
	}
	if(opc==2)
		mostrar(cola);
	if(opc==3)
	   cola=desencolar(cola);
	if(opc<1 || opc>4){
		printf("Opcion no valida");
	}
}
	
	return 0;
}
