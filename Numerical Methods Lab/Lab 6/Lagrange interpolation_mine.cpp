#include<bits/stdc++.h>
using namespace std;
struct point
{
    int x,y;
};
int main()
{
    int n,val;
    printf("Enter number of points:");
    scanf("%d",&n);
    point f[n];
    for(int i=0; i<n; i++)
    {
        int a,b;
        scanf("%d %d",&f[i].x,&f[i].y);

    }
    printf("Enter value of x:");
    cin>>val;
    double result=0;
    for(int i=0; i<n; i++)
    {
        double term=f[i].y;
        for(int j=0; j<n; j++)
        {
            if(i!=j)
            {
                term=(term*(val-f[j].x))/(f[i].x-f[j].x);
            }
        }
        result+=term;
    }
    cout<<"value of f("<<val<<")is:"<<result<<endl;

}
