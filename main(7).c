
#include <stdio.h>

int factTail(int n, int a) {
	if (n < 0)
		return 0;
	else if (n == 0)
		return 1;
	else if (n == 1)
		return a;
	else
		return factTail(n - 1, n * a);
}

int main()
{
    int n, a;
    a=1;
    
    printf("Factorial iterativo: ingrese un numero y se le regresara su factorial.\n");
    
    scanf("%d", &n);
    
    printf("Fact iterativo: %d\n", factTail(n, a));

    return 0;
}
