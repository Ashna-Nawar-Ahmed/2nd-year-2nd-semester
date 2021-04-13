#include<bits/stdc++.h>
using namespace std;
double coeff[10];
int degree;
double f(double x);
int main()
{
    double x1=0,x2=INT_MIN,x0=0,delX=0.05,f1,f2,f0,E=0.001,root,er=1;
    int a,b;
    printf("Enter maximum power:");
    scanf("%d",&degree);
    printf("\nEnter the coefficients from maximum power:");
    for(int i=0; i<=degree; i++)
        scanf("%lf",&coeff[i]);
    printf("\nEnter the lower and upper limit:");
    scanf("%d %d",&a,&b);

    while(x2<b)
    {
        printf("\nWhile loop 1...");
        bool found=false;
        x1=a;
        //printf("\nx1:%.3f",x1);
        x2=x1+delX;
        //printf("\nx2:%.3f",x2);
        f1=f(x1);
        //printf("\nf1:%.3f",f1);
        f2=f(x2);
        //printf("\nf2:%.3f",f2);
        //printf("\n..........Entering if............");
        if(f1*f2<0)
        {
            printf("\n..........Entered if............");
            while(er>E)
            {
                printf("\nWhile loop 2...");
                f1=f(x1);
                f2=f(x2);
                found=true;
                x0=(x1+x2)/2;
                f0=f(x0);
                er=fabs((x2-x1)/x2);
                if(f0==0)
                {
                    root=x0;

                    printf("\nRoot= %.3f",root);
                    break;
                }
                if(f1*f0<0)
                    x2=x0;
                else
                    x1=x0;
                    //f1=f0;
                er=fabs((x2-x1)/x2);

                if(er<=E)
                {
                    root=(x1+x2)/2;
                    //printf("\nBetween %.3f & %.3f there is a root %.3f",x1,x2,root);
                }
                //else continue;
            }
            if(found)
                printf("\nBetween %.3f & %.3f there is a root %.3f",x1,x2,root);
        }
        //if(x2<b)
            a=x2;

    }
    return 0;
}
double f(double x)
{
    double result=coeff[0];
    for(int i=1; i<=degree; ++i)
        result=result*x+coeff[i];

    return result;
}
