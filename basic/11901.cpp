#include <stdio.h>

int main(void)
{
    int A, B;
    while( scanf("%d %d", &A, &B) != EOF )
    {
        printf("%d\n", A+B);
    }
}