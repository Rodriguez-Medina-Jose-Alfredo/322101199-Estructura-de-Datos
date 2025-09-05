
#include <stdio.h>
#include <stdlib.h>

int main()
{

    int i, j, N;
    char edad, calif, total;
    char nombre[25];
    
    char **arreglo;
    
    printf("Lista de alumnos, ingrese la cantidad de alumnos en la lista:\n");
    
    scanf("%d", &N);
    
      arreglo = (char**) malloc(N * sizeof(char*));
        if(arreglo==NULL)
        return 1;
        
        arreglo[N] = (char *) malloc(N* sizeof(char));
        arreglo[N][3] = (char *) malloc(3* sizeof(char));

        total =0;
    
    for(i=0; i < N; i++){
      
        j=0;
        
        printf("Ingrese el nombre del alumno:\n");
        
        scanf("%s", nombre);
        arreglo[i][j]= &nombre;
        
        printf("Ingrese la edad del alumno:\n");
        
        scanf("%s", &edad);
        arreglo[i][j+1]= &edad;
        
        printf("Ingrese la calificacion del alumno:\n");
        
        scanf("%s", &calif);
        arreglo[i][j+2]= &calif;
        
        
        total+=calif;
        
        
        
    }
    
    printf("|          Nombre          | Edad | Calificacion |\n|------------------------|-------|--------------|");
    for(i=0;i<N;i++){
        j=0;
        printf("\n| %s | %s | %s |", arreglo[i][j], arreglo[i][j+1], arreglo[i][j+2]);
        
    }
    printf("\n|------------------------|-------|--------------|\n Calificacion promedio: %d", total/N);
    return 0;
  }
