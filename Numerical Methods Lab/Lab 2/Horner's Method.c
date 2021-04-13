#include<stdio.h>
int main()
{
    int n,x;
    printf("Enter degree:");
    scanf("%d",&n);
    int coeffs[n];
    for(int i=0;i<n;i++)
    {
        printf("Enter coefficient a%d:",n-i);
        scanf("%d",&coeffs[i]);
    }
    return 0;
}
