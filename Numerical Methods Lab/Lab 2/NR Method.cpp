///NEWTON RAPHSON
#include<bits/stdc++.h>

int degree,coeff[100];
double f(double x0);
double fprime(double x0);
//double err(double x0,double x1);
int main()
{
    double E=0.0001,er=1.0,x0,root,f1,f0,x1;
    int itr=1;
    printf("Enter degree:");
    scanf("%d",&degree);
    for(int i=0; i<=degree; i++)
    {
        printf("\nEnter a%d:",degree-i);
        scanf("%d",&coeff[i]);
    }
    printf("Enter x0:");
    scanf("%d",&x0);

    while(er>E)
    {
        f0=f(x0);
        f1=fprime(x0);
        printf("\nIteration: %d",itr);

        x1=x0-(f0/f1);
        printf("\nx1: %.3f",x1);
        printf("\nx0: %.3f",x0);
        printf("\nf1: %.3f",f1);
        printf("\nf0: %.3f",f0);
        er=fabs((x1-x0)/x1);
        printf("\nError: %.3f",er);
        if(er<=E)
        {
            root=x1;
            break;
        }
        else
            x0=x1;
        itr++;

    }
    printf("\nApprox Root: %.3f",root);

}
double f(double x0)
{
    //x2-3x+2
    double result=coeff[0];
    for(int i=1; i<=degree; i++)
        result=result*x0+coeff[i];
    return result;
}
double fprime(double x0)
{
    return 2*x0-3;
}
