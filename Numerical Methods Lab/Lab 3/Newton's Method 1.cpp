#include<bits/stdc++.h>
using namespace std;
#define E 0.001
double coeff[10],deriv_coeff[10],b[10],tempArr[10];
double root[100];
int degree,n;
double f(double x);
double fprime(double x);
//void synthetic(double xr,int n);
void differentiation(double coeff[10],int degree);
void synthetic(double xr,int n,int start);
int main()
{
    double x0,er,xr,f0,fprime0;
    printf("Enter degree:");
    scanf("%d",&degree);
    n=degree;
    for(int i=0; i<=degree; i++)
    {
        printf("\nEnter a%d:",degree-i);
        scanf("%d",&coeff[i]);
    }
    printf("\nEnter x0:");
    scanf("%d",&x0);
    int start=1;
    while(n>1)
    {
        er=1;
        while(er>E)
        {
            f0=f(x0);
            differentiation(coeff,n);
            fprime0=fprime(x0);
            xr=x0-(f0/fprime0);
            er=fabs((xr-x0)/xr);
        }
        root[n]=xr;
        n--;
        synthetic(xr,n,start);
        start++;
        x0=xr;
    }

    root[1]=-(coeff[degree]/coeff[degree-1]);
    printf("\nRoots are: ");
    for(int i=1; i<=degree; i++)
        printf("%.3f ",root[i]);
    return 0;
}
double f(double x)
{
    double result=coeff[0];
    for(int i=1; i<=degree; i++)
        result=result*x+coeff[i];

    return result;
}

double fprime(double x)
{
    double result=deriv_coeff[0];
    for(int i=1; i<degree; i++)
        result=result*x+deriv_coeff[i];

    return result;
}
void synthetic(double xr,int n,int start)
{
    //b[0]=0;
    for(int i=0; i<=start; i++)
        tempArr[i]=0;
    for(int i=start; i<=n; i++)
    {
        //b[i-1]=coeff[i]+xr*b[i];
        tempArr[i] = coeff[i - 1] + tempArr[i - 1] * xr;
    }
    for(int i=0; i<=n; i++)
    {
        coeff[i]=tempArr[i];
    }
}
void differentiation(double coeff[10],int degree)
{
    int j=0;
    for(int i=0; i<=degree; i++)
    {
        deriv_coeff[j]=(degree-i)*coeff[i];
        j++;
    }
    /* for(int i=0;i<=j;i++)
     {
         coeff[i]=tempCoeff[i];
     }
     degree--;*/
}
