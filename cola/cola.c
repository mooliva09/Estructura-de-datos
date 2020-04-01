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
	    else
		 Cola->frente=++Cola->frente % 100;
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
			if(Cola->frente < Cola->detras){
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
		struct cola *Cola=NULL;
		Cola=crear(Cola,1);
	    agregar(Cola,2);
	    agregar(Cola,3);
	    agregar(Cola,4);
	    mostrar(Cola);
	    eliminar(Cola);
	    eliminar(Cola);
	    mostrar(Cola);
	    agregar(Cola,5);
	    agregar(Cola,6);
	    mostrar(Cola);
	   return 0;
	}
