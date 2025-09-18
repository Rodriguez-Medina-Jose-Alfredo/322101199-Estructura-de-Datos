
#include <stdio.h>
#include <stdlib.h>

void lista(int n, int m, char** arr){
    
    int i;
    int j=0;
    char nombre[25];
    char edad[2];
    char calificacion[3];
    
    for(i=0;i<n;i++){
        
            j=0;
            printf("\nIngrese el nombre del alumno(%d) (maximo 25 caracteres)\n", i+1);
            scanf("%s", &arr[i][j]);
            j+=1;
            printf("\nIngrese la edad\n");
            scanf("%s", &arr[i][j]);
            j+=1;
            printf("\nIngrese la calificacion\n");
            scanf("%s", &arr[i][j]);
        
    }
    
    printf("|  \tNombre\t ||Edad||Calificacion|");
    
    for(i=0;i<n;i++){
        
            j=0;
            printf("\n|%25s||%s||%s|", arr[i][j], arr[i][j++], arr[i][j++]);
        
    }
    
    
}

int main()
{
    int m =3;
    int n, i;
    
    
    
    printf("Lista de alumnos, ingrese la cantidad de alumnos de la lista\n");
    scanf("%d", &n);
    
    char **arr = (char **) malloc(n * sizeof(char *));
    arr[0] = (char *) malloc(n * m * sizeof(char));
    
    for (int i = 1; i < n; i++)
    arr[i] = arr[0] + i * m;

    lista(n,m, arr);
    
    return 0;
}
