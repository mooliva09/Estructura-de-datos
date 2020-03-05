#include <stdio.h>
#include <stdlib.h>

int main(void){

int num=0,cont=0,aux1=1,i=0;
int *apuntador,*aux;
printf("Cuantos numeros quieres ");
scanf("%d",&num);

apuntador=(int *)malloc(1 *sizeof(int));
apuntador[0]=1;

if(num==0){
        printf("El numero elegido es 0 o mas grande que 10 a la 8");
}
else
{
    if(apuntador==NULL){
        puts("Fin de ejecución. Error de asignación de memoria.");
        exit (-1) ;

    }
    cont=num/num;
    cont=cont+1;
        do{
            aux=(int *)malloc((aux1*2) *sizeof(int));

            do{
            for(i=0;i<aux1;i++){
            aux[i]=apuntador[i];
            }

            free(apuntador);

            apuntador=(int *)malloc((aux1*2) *sizeof(int));

            for(i=0;i<aux1;i++){
            apuntador[i]=aux[i];
            }

            free(aux);
            aux1=aux1*2;
            }while(aux1==aux1*2);

            apuntador[cont-1]=cont;

            for(i=0;i<cont;i++){
            printf("%d ",*apuntador+i);
            }
            printf("\n");
            cont++;

        }while(cont<=num);
        free(apuntador);
    }
return 0;
}
