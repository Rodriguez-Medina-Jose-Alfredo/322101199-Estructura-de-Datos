
#include <stdio.h>

    void rhorizontal(int n, int m, int matriz[n][m]){
        int i;
        int j;
          printf("\nRecorrido horizontal:\n");
         for(i=0;i<n;i++){
            for(j=0;j<m;j++){
            
            printf("|%d%d|",i,matriz[i][j]);
            
            }
            printf("\n");
        }
    }
    
    void rvertical(int n, int m, int matriz[n][m]){
        int i;
        int j;
          printf("\nRecorrido vertical:\n");
         for(i=n-1;i>=0;i--){
            for(j=m-1;j>=0;j--){
            
            printf("|%d%d|",i,matriz[i][j]);
            
            }
              printf("\n");
        }
    }
    
    void rdiagonal(int n, int m, int matriz[n][m]){
        int i;
        int j;
         printf("\nRecorrido diagonal:\n");
        if(n==m){
         for(i=0;i<n;i++){
              printf("\n");
            for(j=i;j<=i;j++){
            
            printf("|%d%d|",i,matriz[i][j]);
            }
             printf("\n");
            }
        }
        
    else{
        
            if(n>m){
         for(i=0;i<n-1;i++){
            for(j=i;j<=i;j++){
            j=i;
            printf("\n|%d%d|\n",i,matriz[i][j]);
            }}}
            
            if(n<m){
         for(i=0;i<m-1;i++){
            for(j=i;j<=i;j++){
            
            printf("|%d%d|",i,matriz[i][j]);
            }}}
         }
        
    }
    
int main()
{

    int n=0;
    int m=0;
    int i, j;
    
    printf("Arreglos bidimensionales: Ingrese el tamaño de su matriz bidimensional (maximo 10, mayor a 0)");
    
    while(n<=0||n>10){
        
    printf("\nTamaño n (maximo 10):\n");
    scanf("%d", &n);
    
    if(n<=0||n>10)
    printf("\nTamaño incorrecto, intentelo denuevo:\n");
        
    }
    
    
     while(m<=0||m>10){
        
    printf("\nTamaño m (maximo 10):\n");
    scanf("%d", &m);
    
    if(m<=0||m>10)
    printf("\nTamaño incorrecto, intentelo denuevo:\n");
        
    }
    
    int matriz[n][m];
    
    for(i=0;i<n;i++){
            for(j=0;j<m;j++){
            matriz[i][j]=j;
            }
        }
    
    rhorizontal( n, m, matriz);
    rvertical( n, m, matriz);
    rdiagonal( n, m, matriz);
    

    return 0;
}
