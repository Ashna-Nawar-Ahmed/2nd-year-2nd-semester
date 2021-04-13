#include<stdio.h>
#include<math.h>
#define E 0.001
double coeff[50];
int degree;
double f(double x0);
double fd(double x0);
int main()
{
    double x0,f0,fd0,x1,root,er=1;
    int itr=1;
    printf("Enter degree:");
    scanf("%d",&degree);
    for(int i=degree;i>=0;i--)
    {
        printf("\nEnter a%d:",i);
        scanf("%d",&coeff[i]);
    }
    printf("\nEnter x0=");
    scanf("%lf",&x0);
    f0=f(x0);
    fd0=fd(x0);
    printf("\n\t\tx0\tx1\tf(x0)\tf'(x0)\tError\n");
    while(er>E)
    {
        x1=x0-(f0/fd0);
        er=fabs((x1-x0)/x1);
        printf("Iteration: %d\t%.3f\t%.3f\t%.3f\t%.3f\t%.3f\n",itr,x0,x1,f0,fd0,er);
        if(er<=E)
        {
            root=x1;
            //printf("Root: %.3f",root);
            break;
        }
        else
            x0=x1;
    }
    printf("Approximate root:%.3f",root);
    return 0;
}
double f(double x0)
{
    double result=coeff[degree];
    for(int i=degree; i>=0; i--)
    {
        result=result*x0+coeff[i];
    }
    return result;
}
double fd(double x0)
{
    return 2*x0+3;
}
