#include <stdio.h>
#include <stdlib.h>

struct Nodo{
	 int dato;
	 struct Nodo * derecha;
	 struct Nodo * izquierda;
	};

struct Nodo *insertar (struct Nodo * raiz,int dato){
		struct Nodo* nuevo=NULL;
		nuevo=(struct Nodo *)malloc(sizeof(struct Nodo));
		
		if(nuevo==NULL){
			printf("\nNo se pudo insertar");
		}
		else{
			nuevo->dato=dato;
			nuevo->derecha=NULL;
			nuevo->izquierda=NULL;
			
			if(raiz == NULL){
				printf("\nDato insertado");
				return nuevo;
			}
			else{
				struct Nodo* aux=NULL;
				aux=raiz;
				int insertado=0;
				while(insertado == 0){
					if(dato>=aux->dato && aux->derecha==NULL){
						aux->derecha=nuevo;
						insertado=1;
					}else
					if(dato>=aux->dato && aux->derecha!=NULL){
						aux=aux->derecha;
					}
					else
					if(dato<aux->dato && aux->izquierda==NULL){
						aux->izquierda=nuevo;
						insertado=1;
					}
					else
					if(dato<aux->dato && aux->izquierda!=NULL){
						aux=aux->izquierda;
					}
				}
				printf("\nDato insertado");
				return raiz;
			}
		}
	}
	
void buscar(struct Nodo*raiz,int dato){
	int encontrado=0;
	struct Nodo * nodo=raiz;
	struct Nodo * padre=NULL;
	
	if(nodo == NULL){
		printf("\nNo existe el dato");
		return;
	}
	
	while(nodo != NULL && encontrado==0){
		if(nodo->dato == dato){
			encontrado=1;
			break;
		}
		padre=nodo;
		if(dato<nodo->dato)
		  nodo=nodo->izquierda;
		  else
		  nodo=nodo->derecha;
	}
	
	if(encontrado==1){
		printf("\nEl dato si se encuentra en el arbol");
		if(padre==NULL){
			printf("\nEl dato es la raiz del arbol");
		}
		printf("\nEl padre del nodo es %d",padre->dato);
	}
	else
	 printf("\nNo se encontro el dato");
}
	
/*Inorden*/
void mostrar_1(struct Nodo *raiz){
	
	if(raiz == NULL){
		return;
	}
	
	mostrar_1(raiz->izquierda);
	printf("%d ",raiz->dato);
	mostrar_1(raiz->derecha);
}

/*Preorden*/
void mostrar_2(struct Nodo *raiz){
	if(raiz == NULL){
		return;
	}
	
	printf("%d ",raiz->dato);
	mostrar_2(raiz->izquierda);
	mostrar_2(raiz->derecha);
}

/*Postorden*/
void mostrar_3(struct Nodo *raiz){
	if(raiz == NULL){
		return;
	}
	
	mostrar_3(raiz->izquierda);
	mostrar_3(raiz->derecha);
	printf("%d ",raiz->dato);
}

struct Nodo * eliminar(struct Nodo * raiz,int dato){
	if(raiz == NULL){
		return NULL;
	}
	
	struct Nodo* nodoeliminar=raiz;
	struct Nodo* padrenodo=NULL;
	struct Nodo* sucesor=NULL;
	struct Nodo* padresucesor=NULL;
	
	while(nodoeliminar->dato != dato){
		
		padrenodo=nodoeliminar;
		if(dato < nodoeliminar->dato){
			nodoeliminar=nodoeliminar->izquierda;
		}else{
			nodoeliminar=nodoeliminar->derecha;
		}
		
		if(nodoeliminar == NULL)
		 break;
	}
	
	if(nodoeliminar==NULL){
		printf("\n No existe el dato en el arbol");
		return raiz;
	}
	
	
	if(nodoeliminar->derecha == NULL && nodoeliminar->izquierda==NULL){
		if(padrenodo != NULL){
		if(nodoeliminar->dato < padrenodo->dato){
			padrenodo->izquierda=NULL;
		}
		else{
			padrenodo->derecha=NULL;
		}
		free(nodoeliminar);
		return raiz;
	  }
	  else{
	  	free(nodoeliminar);
		return NULL;
	  }
	}
	
	if(nodoeliminar->derecha == NULL || nodoeliminar->izquierda==NULL){
		if(nodoeliminar->derecha !=NULL){
			if(padrenodo != NULL){
			if(nodoeliminar->dato < padrenodo->dato){
			   padrenodo->izquierda=nodoeliminar->derecha;
		    }
		     else{
			  padrenodo->derecha=nodoeliminar->derecha;
		     }
		 }
		 else{
		 	sucesor=nodoeliminar->derecha;
		 	free(nodoeliminar);
		 	return sucesor;
		 }
     	}
     	 else{
     	 	if(padrenodo != NULL){
     		if(nodoeliminar->dato < padrenodo->dato){
		    	padrenodo->izquierda=nodoeliminar->izquierda;
		    }
		    else{
			    padrenodo->derecha=nodoeliminar->izquierda;
		    }
		  }
		  else{
		  	sucesor=nodoeliminar->izquierda;
		  	free(nodoeliminar);
		  	return sucesor;
		  }
		 }
		 free(nodoeliminar);
		 return raiz;
	}
	
	sucesor=nodoeliminar->derecha;
	while(sucesor->izquierda != NULL){
		padresucesor=sucesor;
		sucesor=sucesor->izquierda;
	}
	
	if(sucesor->derecha==NULL && sucesor->izquierda==NULL){
		nodoeliminar->dato=sucesor->dato;
		if(padresucesor != NULL && padresucesor !=raiz)
		padresucesor->izquierda=NULL;
		else{
		nodoeliminar->derecha=NULL;
		}
		free(sucesor);
		 
		return raiz;
	}
	
	if(sucesor->derecha==NULL || sucesor->izquierda==NULL){
		 nodoeliminar->dato=sucesor->dato;
		 
		 if(padresucesor==NULL){
		 	nodoeliminar->derecha=sucesor->derecha;
		 }
		 else{
		 	padresucesor->izquierda=sucesor->derecha;
		 }
		 free(sucesor);
		 return raiz;
	    }
	
}

int main(void){
	struct Nodo* raiz=NULL;
	int opc,dato;
	
	printf("\n------Arbol binario------");
	
	do{
	 printf("\nEscoge una opcion");
	 printf("\n1.-Insertar un dato\n2.-Mostrar recorrido en pre orden\n3.-Mostrar recorrido en inorden\n4.-Mostrar recorrido en post orden\n5.-Buscar un dato\n6.-Eliminar un dato\n7.-Salir\n");
	 scanf(" %d",&opc);
		switch(opc){
			case 1:
				printf("\nIngrese el valor a insertar\n");
				scanf("%d",&dato);
				raiz=insertar(raiz,dato);
			break;
			case 2:
			    mostrar_2(raiz);
			break;
			case 3:
				mostrar_1(raiz);
			break;
			case 4:
			    mostrar_3(raiz);
			break;
			case 5:
			    printf("\nIngrese el valor a buscar\n");
				scanf("%d",&dato);
				buscar(raiz,dato);
			break;
			case 6:
				printf("\nIngrese el valor a eliminar\n");
				scanf("%d",&dato);
			    raiz=eliminar(raiz,dato);
			break;
			case 7:
				printf("\nEjecucion terminada");
			break;
			default:
				printf("\nEscoge una opcion valida");
		}
	}while(opc != 7);
	
	return 0;
}
