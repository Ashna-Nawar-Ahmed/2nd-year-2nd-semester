#include<bits/stdc++.h>
int coeff[10],degree,tempCoeff[10];
void differentiation(int coeff[10],int degree);
int main()
{
    printf("Enter degree:");
    scanf("%d",&degree);
    //n=degree;
    for(int i=0; i<=degree; i++)
    {
        printf("\nEnter a%d:",degree-i);
        scanf("%d",&coeff[i]);
    }
    printf("\nCoefficients of derivative:");
    differentiation(coeff,degree);
    for(int i=0; i<degree; i++)
    {
        printf("\na%d: %d",degree-1-i,coeff[i]);
    }
}
void differentiation(int coeff[10],int degree)
{
    int j=0;
    for(int i=0;i<=degree;i++)
    {
        tempCoeff[j]=(degree-i)*coeff[i];
        j++;
    }
    for(int i=0;i<=j;i++)
    {
        coeff[i]=tempCoeff[i];
    }
    degree--;
}
