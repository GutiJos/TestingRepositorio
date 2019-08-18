#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>

void lanzarmoneda(int *a, int c, int d, int *e);

int main(){
  int j,k;
  int y,c;
  int op,ap,ap2; //ap y ap2 hacen referencia a la apuesta
  int moneda[2]={0,0};

  printf("Este juego se llama 'El tramposo'.\n\nConsiste en apostar cara o sello. Si la cantidad apostada es mayor a la otra cantidad, ganas el juego, de lo contrario lo pierdes.\n");
  printf("Puedes elegir la cantidad de veces que se lanza la moneda, cada opción tiene un costo asociado que deberá ser pagado al final del juego.\nRecuerda que, las probabilidades de que salga cada cara es igual a 1/2.\n\n");
  printf("1) lanza la moneda 10 veces.\n   Costo=$1.000 pesos.\n   Premio=$5.000 pesos.\n");
  printf("2) lanza la moneda 100 veces.\n   Costo=$10.000 pesos.\n   Premio=$50.000 pesos.\n");
  printf("3) lanza la moneda 1000 veces.\n   Costo=$100.000 pesos.\n   Premio=$500.000 pesos.\n");

  while(1){
    printf("Haz tu apuesta: ");
    scanf("%i",&ap);
    if(ap==1){
      ap2=10;
      break;
    }
    else if(ap==2){
      ap2=100;
      break;
    }
    else if(ap==3){
      ap2=1000;
      break;
    }
    else{
      printf("Opción inválida. Inténtalo de nuevo.\n");
    }
  }

  int lista[ap2];

  printf("\nEscoge cara(1) o sello(0): ");
  scanf("%i",&op);

  lanzarmoneda(moneda, ap2, op, lista);

  //para imprimir los valores y comprobarlos
  printf("\n----------------------------\n");
  for(k=0; k<ap2; k++){
    printf("%i ",lista[k]);
  }

  printf("\n----------------------------");
  printf("\nLa cantidad de caras es: %i",moneda[1]);
  printf("\nLa cantidad de sellos es: %i",moneda[0]);

  //moneda[1]=6;
  //moneda[0]=4; //estos comentes eran para probar algunas cosas
  //c=ap2*0.3;
  c=sqrt(ap2);
  y=rand()%c; //para que parezca que los datos son al azar
  printf("\nEl valor de y es %i",y);
  if(moneda[op]>=moneda[1-op]){
    for(j=0; moneda[op]>=moneda[1-op]-y; j++){
      if(lista[j]==op){
        lista[j]=1-op;
        moneda[op]-=1;
        moneda[1-op]+=1;
      }
    }
  }

  printf("\n----------------------------\n");
  printf("La cantidad de caras es: %i\n",moneda[1]);
  printf("La cantidad de sellos es: %i\n",moneda[0]);
  printf("----------------------------\n");

  //para comprobar los valores nuevamente
  for(k=0; k<ap2; k++){
    printf("%i ",lista[k]);
  }
  printf("\n----------------------------\n");

  if(moneda[op]>moneda[1-op]){
    printf("\nHas ganado!\n");
    if(ap==1){
      printf("Ganas $5.000 pesos");
    }
    else if(ap==2){
      printf("Ganas $50.000 pesos");
    }
    else if(ap==3){
      printf("Ganas $500.000 pesos");
    }
  }
  else{
    printf("\nHas perdido! :(\n");
    printf("Intentalo de nuevo.\n");
    if(ap==1){
      printf("Debes pagar $1.000 pesos");
    }
    else if(ap==2){
      printf("Debes pagar $10.000 pesos");
    }
    else if(ap==3){
      printf("Debes pagar $100.000 pesos");

    }
  }

  return 0;
}

void lanzarmoneda(int *a, int c, int d, int *e){
  int x,i;

  srand(time(NULL)); //para evitar que se repitan los mismos valores
  for(i=0;i<c;i++){
    x=rand()%2;
    printf("%i",x);
    *(e+i)=x;
    if(x==d){
      *(a+d)+=1;
    }
    else{
      *(a+1-d)+=1;
    }
  }
}
