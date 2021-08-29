#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>
#include "list.h"

const char *get_csv_field (char * tmp, int k) {
  int open_mark = 0;
  char* ret=(char*) malloc (1000*sizeof(char));
  int ini_i=0, i=0;
  int j=0;
  while(tmp[i+1]!='\1'){

    if(tmp[i]== '\"'){
        open_mark = 1-open_mark;
        if(open_mark) ini_i = i+1;
        i++;
        continue;
    }

    if(open_mark || tmp[i]!= ','){
        if(k==j) ret[i-ini_i] = tmp[i];
        i++;
        continue;
    }

    if(tmp[i]== ','){
      if(k==j) {
        ret[i-ini_i] = 0;
        return ret;
      }
      j++; ini_i = i+1;
    }

    i++;
  }

  if(k==j) {
      ret[i-ini_i] = 0;
      return ret;
  }


  return NULL;
}


int main(void) {

List* L = createList();
  int i;
  
    int * j = (int*) malloc(sizeof(int));
    *j=i;
    
  int* aux = firstList(L);
  while (aux){
    printf("%d ", *aux);
    aux = nextList(L);
  }
  printf("\n");

  aux = lastList(L);
  while(aux) {

    printf("%d", *aux);
    aux = prevList(L);

  }


  int op;

    while (op!=0)
    {   
        printf("---------------------------------------------------\n");
        printf("1.- Importar Canciones\n");
        printf("2.- Exportar Canciones\n");
        printf("3.- Agregar Cancion\n");
        printf("4.- Buscar Cancion por Nombre\n");
        printf("5.- Buscar Cancion por Artista\n");
        printf("6.- Buscar Cancion por Genero\n");
        printf("7.- Eliminar Cancion\n");
        printf("8.- Mostrar nombres de las listas de reproducción\n");
        printf("9.- Mostrar una lista de reproducción\n");
        printf("10.- Mostrar todas las cancionesn\n");
        printf("0.- Salir\n");
        printf("---------------------------------------------------\n");
        printf("Indica la opcion: ");
        scanf("%d", &op);
        printf("\n");

        switch(op)
        {         
      
            
      case 1: printf("Importar Canciones: \n");
// Se abre el archivo de mundos csv en modo lectura "r"
    FILE *fp = fopen ("canciones.csv", "r");

    // Cadena para guardar la linea completa del archivo csv
    char linea[1024];
    int i;

    fgets (linea, 1023, fp);
    int k=0;
    while (fgets (linea, 1023, fp) != NULL) { // Se lee la linea
        for(i=0;i<1;i++){
            const char *aux = get_csv_field(linea, i); // Se obtiene el nombre
            printf("%s ",aux);
        }

        printf("\n");
        k++; if(k==100) break;
    }
    return 0;

   // case 2: printf("Exportar Canciones: \n");

   case 3: printf("Agregar Cancion \n");
   char nombre[20];
   char artista[20];
   char genero[20];
   char año[20];
   char lista[20];

   printf("Ingresar Nombre de la Cancion: \n");
   scanf("%s",nombre);
   printf("Ingresar Artista: \n");
   scanf("%s",artista);
   printf("Ingresar Genero: \n");
   scanf("%s",genero);
   printf("Ingresar Año: \n");
   scanf("%s",año);
   printf("Ingresar Lista de Reproduccion: \n");
   scanf("%s",lista);

   FILE *fpA = fopen ("canciones.csv", "a");
   fputc('\n',fpA);
   fputs(nombre,fpA);
   fputc(',',fpA);
   fputs(artista,fpA);




    

  case 4: printf("printf("Agregar Cancion"); \n");

  char cancion[30];

  


  
     
  }



    }
    








}