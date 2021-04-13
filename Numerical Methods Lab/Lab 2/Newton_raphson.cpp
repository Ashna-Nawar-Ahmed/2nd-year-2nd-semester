#include<stdio.h>
#include<math.h>

using namespace std;

double err = 0.001;
int max_power = 0;
int co_eff[10];

double f(double x0)
{
    double result = 0;

    for(int i = max_power; i >= 0 ; --i)
        result = result * x0 + co_eff[i];

    return result;
}



double fd(double x0)
{
    return ((2*x0)-3);
}

int main()
{
    int i,k = 0;
    double x0,x1,temp,f0,f1,error;
    printf("\nEnter the maximum power of function: \n");
    scanf("%d",&max_power);

    for(i = 0; i <= max_power; i++)
    {
        printf("\nCo-efficient of %d th term of x:\n",i);
        scanf("%d",&co_eff[i]);
    }

    printf("\nGuess the root: \n");
    scanf("%lf",&x0);

    printf("Iteration:\t x0:\t\t x1:\t\t f0:\t\t f1:\t\t Error:\n");
    do
    {
        k++;

        printf("%d\t\t",k);
        printf("%lf\t",x0);

        f0=f(x0);
        //f1=f(x1);
        x1 = x0 - (f(x0)/fd(x0));
        f1=f(x1);
        printf("%lf\t",x1);
        printf("%lf\t",f0);
        printf("%lf\t",f1);

        temp = x0;
        x0 = x1;

        error = fabs((x1-temp)/x1);
        printf("%lf\t\n",error);

    }while(fabs((x1-temp)/x1)>= err);

    printf("\nThe root is = %lf\n",x1);

    return 0;
}






