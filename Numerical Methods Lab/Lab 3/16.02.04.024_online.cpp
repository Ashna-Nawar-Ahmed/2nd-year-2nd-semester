#include<bits/stdc++.h>
using namespace std;
int degree,rootCount,itr=1;
double coeff[10],deriv[10],root[10],b[10];
double f(double x0);
double fprime(double x0);
int main()
{
    double E=0.001;
    printf("Enter the degree of the equation:");
    scanf("%d",&degree);
    printf("Enter the coefficients of the equation:");
    for(int i=0; i<=degree; i++)
        scanf("%lf",&coeff[i]);
    double x0;
    printf("Enter x0=");
    scanf("%lf",&x0);
    double xr,er;
    for(int i=0; i<70; i++)
        printf("-");
    printf("\n\t\t   x0\t  x1\tf(x0)\tfd(x0)\tError\n");
    for(int i=0; i<70; i++)
        printf("-");
    rootCount=1;
    while(degree>0)
    {
        while(true)
        {
            double f0=f(x0);
            double fd0=fprime((x0));
            xr=x0-(f0/fd0);
            er=fabs((xr-x0)/xr);
            printf("\nIteration %d=\t",itr);
            if(x0>=0)
                printf("+%.3f\t",x0);
            else printf("%.3f\t",x0);
            if(xr>=0)
                printf("+%.3f\t",xr);
            else printf("%.3f\t",xr);
            if(f0>=0)
                printf("+%.3f\t",f0);
            else printf("%.3f\t",f0);
            if(fd0>=0)
                printf("+%.3f\t",fd0);
            else printf("%.3f\t",fd0);
            if(er>=0)
                printf("+%.3f\t",er);
            else printf("%.3f\t",er);
            itr++;
            if(er<=E)
            {
                root[rootCount]=xr;
                rootCount++;
                break;
            }
            x0=xr;
        }
        b[degree]=0;
        for(int i=degree; i>0; i--)
        {
            b[i-1]=coeff[i]+xr*b[i];
        }
        degree--;
        for(int i=0; i<=degree; i++)
            coeff[i]=b[i];
        x0=xr;
    }
    printf("\n");
    for(int i=0; i<70; i++)
        printf("-");
    for(int i=1; i<rootCount; i++)
        printf("\nRoot %d:%lf",i,root[i]);

    return 0;
}
double f(double x0)
{
    int n=degree;
    double res=coeff[n];
    for(int i=n-1; i>=0; i--)
    {
        res=res*x0+coeff[i];
    }
    return res;
}
double fprime(double x0)
{
    int n=degree;
    for(int i=n; i>0; i--)
        deriv[i-1]=coeff[i]*i;
    n--;
    double res=deriv[n];
    for(int i=n-1; i>=0; i--)
    {
        res=res*x0+deriv[i];
    }
    return res;
}
