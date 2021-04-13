#include<bits/stdc++.h>
using namespace std;
int main()
{
    int n;
    printf("Enter number of values of x&y:");
    scanf("%d",&n);
    int x[n],y[n],fit_y[n];
    printf("Enter values of x:");
    for(int i=0; i<n; i++)
        scanf("%d",&x[i]);
    printf("Enter values of y:");
    for(int i=0; i<n; i++)
        scanf("%d",&y[i]);
    for(int i=0; i<n; i++)
    {
        printf("x%d=%d\ty%d=%d\n",i+1,i+1,x[i],y[i]);
    }
    double xsum=0,ysum=0,xysum=0,x2sum=0;
    for(int i=0; i<n; i++)
    {
        xsum+=x[i];
        ysum+=y[i];
        xysum+=x[i]*y[i];
        x2sum+=x[i]*x[i];
    }
    double a,b;
    b=((n*xysum)-(xsum*ysum))/((n*x2sum)-(xsum*xsum));
    a=(ysum/n)-((b*xsum)/n);
    for(int i=0; i<n; i++)
    {
        fit_y[i]=b*x[i]+a;
    }
    for(int i=0; i<n; i++)
    {
        printf("x%d=%d\ty%d=%d\tfit_y%d%.1f\n",i+1,i+1,i+1,x[i],y[i],fit_y[i]);
    }
    printf("%.3f x+ %.3f",b,a);
}
