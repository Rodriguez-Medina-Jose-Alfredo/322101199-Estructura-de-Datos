//Rodriguez Medina Jose Alfredo 322101199
#include <stdio.h>

int main()
{
   int i, j, n;
   
   printf("Ingrese su numero de cuenta\n");
   
   scanf("%d", &n);
   
   j=n%10;
       
        printf("\nEl ultimo digito de su numero de cuenta es: %d\n 10 primeros numeros pares:\n", j);

   
 for(i=10;i>=1;i--){
       
       printf("| %d |", i*2);
       
   }
   
   
   if(j!=0)
   printf("\n\n 10 primeros numeros pares, el valor del ultimo digito de su numero de cuenta (%d) sera reemplazado con un -1\n", j);
   else{
     printf("\n\n 10 primeros numeros pares (el ultimo digito del N de cuenta es 0)\n"); 
   }
   
   
    for(i=10;i>=1;i--){
       
       if(i!=j)
       printf("| %d |", i*2);
       else{
           printf("| %d |", -1);
       }
   }
   
   
   return 0;
}
