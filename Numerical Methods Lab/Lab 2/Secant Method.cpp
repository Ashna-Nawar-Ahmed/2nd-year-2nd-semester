///SECANT METHOD
#include<bits/stdc++.h>
#define E 0.0001
int degree,coeff[100];
double f(double x0);
int main()
{
    double f1,f2,f3,x1,x2,x3,er=1,root;
    int itr=1;
    printf("Enter degree:");
    scanf("%d",&degree);
    for(int i=0; i<=degree; i++)
    {
        printf("\nEnter a%d:",degree-i);
        scanf("%d",&coeff[i]);
    }
    printf("Enter x1:");
    scanf("%lf",&x1);
    printf("\nx1: %lf",x1);
    printf("Enter x2:");
    scanf("%lf",&x2);
    printf("\nx2: %lf",x2);

    while(er>E)
    {
        printf("\nIteration: %d",itr);
        itr++;
        f1=f(x1);
        f2=f(x2);
        x3=(f2*x1-f1*x2)/(f2-f1);
        er=fabs((x3-x2)/x3);
        printf("\nx1: %.3f",x1);
        printf("\nx2: %.3f",x2);
        printf("\nx3: %.3f",x3);
        printf("\nf1: %.3f",f1);
        printf("\nf2: %.3f",f2);
        printf("\nf3: %.3f",f3);
        printf("\nError: %.3f",er);
        if(er<=E)
        {
            root=x3;
            //printf("Root: %.4f",root);
            break;
        }
        else
        {
            x1=x2;
            f1=f2;
            x2=x3;
            f2=f(x3);
            continue;
        }
    }
    printf("\nApproximate Root: %.4f",root);
    return 0;

}
double f(double x0)
{
    //x2-3x+2
    double result=coeff[0];
    for(int i=1; i<=degree; i++)
        result=result*x0+coeff[i];
    return result;
}
