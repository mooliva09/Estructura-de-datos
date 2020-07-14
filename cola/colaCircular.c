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
			nuevo->detras=++nuevo->detras % 100;
			nuevo->elementos[nuevo->detras]=dato;
		}
		return nuevo;
	}
	
	void agregar(struct cola *Cola,int elemento){
		if (Cola->frente-1==Cola->detras || Cola->frente==0 && Cola->detras==99 || Cola->frente==99 && Cola->detras==0)
	        printf("\nLa cola está llena");
	    else{
		    Cola->detras=++Cola->detras % 100;
	        Cola->elementos[Cola->detras]=elemento;
	    }
	}
	
	void eliminar(struct cola *Cola){
		if (Cola->detras ==-1)
	        printf("\n No hay elementos en la cola");
	    else{
	     Cola->elementos[Cola->frente]=0;
	     if(Cola->frente+1 % 100 == Cola->detras+1 % 100){
			 	Cola->detras=-1;
			}
		   else
		      Cola->frente=++Cola->frente % 100;
	 }
	}	
	
	void mostrar(struct cola* Cola){
		if (Cola->detras==-1)
	        printf("\n No hay elementos en la cola");
	    else{
		
		if(Cola->frente > Cola->detras){
				
		    int i=Cola->frente;
		    
		    while(i<=99){
		    	printf("%d,",Cola->elementos[i]);
		    	++i;
			 }
			 
			 i=0;
			 while(i<=Cola->detras){
			 		printf("%d,",Cola->elementos[i]);
		    	++i;
			 }
		     	printf("\n");	
			}
			else 
			if(Cola->frente <= Cola->detras){
				int i=Cola->frente;
		    
		    while(i<=Cola->detras){
		    	printf("%d,",Cola->elementos[i]);
		    	++i;
			 }
			 printf("\n");
			}	
		}	
		}
	
	int main(void){
	int opc=0;
	int creada=0;
	int dato=0;
	struct cola *Cola=NULL;
	printf("----------Cola circular----------\n");
	
	while(opc != 4){
	printf("\nEscoja una de las siguientes opciones:\n");
	printf("1.-Agregar\n2.-Mostrar\n3.-Eliminar\n4.-Salir\n");
	scanf("%d",&opc);
	if(opc==1){
		if(creada==0){
			printf("\nEscriba el dato que va a encolar:\n ");
			scanf("%d",&dato);
			Cola=crear(Cola,dato);
			if(Cola ==NULL){
	        	printf("\nNo se pudo crear la cola\n");
		        return 1;
	        }
			creada=1;
		}
		else{
			printf("\nEscriba el dato que va a encolar:\n ");
			scanf("%d",&dato);
			agregar(Cola,dato);
		}
	}
	if(opc==2){
		if(Cola==NULL){
			printf("\nNO hay una cola\n");
		}
		else{
		mostrar(Cola);
	}
	}
	if(opc==3){
		if(Cola==NULL){
			printf("\nNO hay una cola\n");
		}
		else{
			eliminar(Cola);
		}
	}	
	if(opc<1 || opc>4){
		printf("Opcion no valida");
	}
}
	
	
	return 0;
	}
