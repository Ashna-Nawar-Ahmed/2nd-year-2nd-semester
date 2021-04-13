#include<bits/stdc++.h>
#define E 0.0001
using namespace std;
int coeff[100],degree;
double f(double x0);
int main()
{
    double x1,x2,x3,f1,f2,f3,er=1,root;
    int itr=1;
    printf("Enter degree:");
    scanf("%d",&degree);
    for(int i=0; i<=degree; i++)
    {
        printf("\nEnter a%d:",degree-i);
        scanf("%d",&coeff[i]);
    }
    printf("\nEnter x1:");
    scanf("%lf",&x1);
    printf("\nEnter x2:");
    scanf("%lf",&x2);
    printf("\nIteration\t  x1  \t x2  \tx3\tf(x1)\tf(x2)\tf(x3)\tError\n");
    for(int i=0; i<=70; i++)
        printf("-");
        while(er>E)
        {
            f1=f(x1);
            f2=f(x2);
            f3=f(x3);
            x3=(f2*x1-f1*x2)/(f2-f1);
            er=fabs((x3-x2)/x3);
            printf("\n  %d",itr);
            printf("\t");
            printf("\t");
            if(x1>0)
                printf("+%.3f",x1);
            else printf("%.3f",x1);
            printf("\t");
            if(x2>0)
                printf("+%.3f",x2);
            else printf("%.3f",x2);
            printf("\t");
            if(x3>0)
                printf("+%.3f",x3);
            else printf("%.3f",x3);
            printf("\t");
            if(f1>0)
                printf("+%.3f",f1);
            else printf("%.3f",f1);
            printf("\t");
            if(f2>0)
                printf("+%.3f",f2);
            else printf("%.3f",f2);
            printf("\t");
            if(f3>0)
                printf("+%.3f",f3);
            else printf("%.3f",f3);
            printf("\t");
            if(er>0)
                printf("+%.3f",er);
            else printf("%.3f",er);
            //printf("\n  %d\t\t%.3f\t%.3f\t%.3f\t%.3f\t%.3f\t%.3f\t%.3f\n",itr,x1,x2,x3,f1,f2,f3,er);
            itr++;
            if(er<=E)
            {
                root=x3;
                break;
            }
            else
            {
                x1=x2;
                f1=f2;
                x2=x3;
                f2=f3;
                continue;
            }
        }
        printf("\n");
        for(int i=0; i<=70; i++)
        printf("-");
        printf("\nAppropriate root: %.3f\n",root);
}
double f(double x0)
{
    double result=coeff[0];
    for(int i=1; i<=degree; i++)
    {
        result=result*x0+coeff[i];
    }
    return result;
}
