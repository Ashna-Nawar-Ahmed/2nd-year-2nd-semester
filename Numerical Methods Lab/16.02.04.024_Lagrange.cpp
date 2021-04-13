L#include<bits/stdc++.h>
using namespace std;
struct point
{
    double x;
    double y;
} f[100];
int main()
{
    int n;
    double xp;
    printf("enter the number of points to be entered:");
    scanf("%d",&n);
    printf("Enter the values of x and y:\n");
    for(int i=0; i<n; i++)
    {
        scanf("%lf %lf",&f[i].x,&f[i].y);
    }

    printf("Enter value of x to be interpolated:");
    scanf("%lf",&xp);
    double sum=0,term;
    for(int i=0; i<n; i++)
    {
        term=f[i].y;
        for(int j=0; j<n; j++)
        {
            if(i!=j)
                term=(term*(xp-f[j].x))/(f[i].x-f[j].x);
        }
        sum+=term;
    }
    printf("The result is: f(%.0f)=%lf",xp,sum);
    return 0;
}
