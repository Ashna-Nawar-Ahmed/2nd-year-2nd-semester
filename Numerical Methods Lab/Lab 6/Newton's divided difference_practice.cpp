#include<bits/stdc++.h>
using namespace std;
int main()
{
    double a[100],div[100][100],x[100],y[100],xp,vals[100];
    int n;
    printf("Enter number of points:");
    cin>>n;
    printf("Enter values of x & y:");
    for(int i=1; i<=n; i++)
        cin>>x[i]>>y[i];
    printf("Enter value of x to be interpolated:");
    cin>>xp;
    for(int i=1; i<=n; i++)
    {
        div[i][1]=y[i];
    }
    int k=1;
    for(int j=2; j<=n; j++)
    {
        for(int i=1; i<=n-j+1; i++)
        {
            div[i][j]=(div[i+1][j-1]-div[i][j-1])/(x[i+j-1]-x[i]);
            vals[k]=div[i][j];
            k++;
            cout<<"div["<<i<<"]["<<j<<"]:"<<div[i][j]<<endl;
        }
    }
    for(int i=1; i<=n; i++)
    {
        a[i]=div[1][i];
    }
    double lf,sum=a[1];
    for(int i=2; i<=n; i++)
    {
        lf=1.0;
        for(int j=1; j<=i-1; j++)
        {
            lf*=(xp-x[j]);
        }
        sum+=(lf*a[i]);

    }
    /*for(int i=1;i<=n;i++)
    {
        cout<<x[i]<<"\t"<<y[i]<<"\t"<<a[i]<<"\t"<<endl;
    }*/
    printf("\nxi\tyi\tf[xi,xj]\tf[xi,xj,xk]\tf[xi,xj,xk,xl]\n");
    printf("%.0f\t%.0f\n",x[1],y[1]);
    printf("\t\t%.3f\n",vals[1]);
    printf("%.0f\t%.0f\t\t\t%.3f\n",x[2],y[2],vals[4]);
    printf("\t\t%.3f\t\t%.3f\n",vals[2],vals[6]);
    printf("%.0f\t%.0f\t\t\t\t\t%.3f\n",x[3],y[3],vals[5]);
    printf("\t\t%.3f\n",vals[3]);
    printf("%.0f\t%.0f\n",x[4],y[4]);
    cout<<"the value of f("<<xp<<") is:"<<sum<<endl;

}
