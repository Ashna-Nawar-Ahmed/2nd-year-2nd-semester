///POLYNOMIAL REGRESSION
#include <bits/stdc++.h>
using namespace std;

int main()
{
    int N;
    cout << "how many values for x & y? : ";
         cin >> N;
    double x[N], y[N];
    cout << "input for x: ";
    for (int i = 0; i < N ; i++)
    {
        cin >> x[i];
    }
    cout << "input for y: ";
    for (int i = 0; i < N ; i++)
    {
        cin >> y[i];
    }

    cout << "Degree? : ";
    int n;
    cin >> n;

    double X[2*n+1];

    for(int i = 0; i < 2*n+1; i++)
    {
        X[i] = 0;
        for(int j = 0; j < N; j++)
        {
            X[i] += pow(x[j], i);
        }
    }

    double B[n+1] [n+2], a[n+1];

    for(int i = 0 ; i <=n ; i++)
    {
        for (int j = 0; j <=n ; j++)
        {
            B[i][j] = X[i+j];
        }
    }

    double Y[n+1];
    for(int i = 0; i <=n; i++)
    {
        Y[i] = 0;
        for(int j = 0 ; j <N; j++)
        {
            Y[i] += pow(x[j], i)*y[j];
        }
    }

    for(int i = 0; i <=n; i++)
    {
        B[i] [n+1] = Y[i];
    }

    n = n + 1;


    for(int i=0; i<n; i++)
    {
        for(int k=i+1; k<n; k++)
        {
            if(fabs(B[i][i])<fabs(B[k][i]))
            {
                for(int j=0; j<=n; j++)
                {
                    double temp = B[i][j];
                    B[i][j] = B[k][j];
                    B[k][j] = temp;
                }
            }
        }
    }

    for(int i=0; i<n-1; i++)
    {
        for(int k=i+1; k<n; k++)
        {
            double t = B[k][i]/B[i][i];
            for(int j=0; j<=n; j++)
            {
                B[k][j] -= t*B[i][j];
            }
        }
    }

    for(int i=n-1; i>=0; i--)
    {
        a[i] = B[i][n];
        for(int j=i+1; j<n; j++)
   0     {
            if(j!=i)
            {
                a[i] = a[i] - B[i][j]*a[j];
            }
        }
        a[i] = a[i]/B[i][i];
    }

    cout << "The values of the co-efficients are as follows: \n";
    for(int i=0; i <n; i++)
        cout << "x^" << i <<" = " << a[i] << endl;
    cout <<" hence the fitted poly eqn is: \n";
    for(int i = 0; i < n; i++)
    {
        cout << " + (" << a[i] << " ) " << "x^ " << i;
    }
    cout << endl;
    return 0;



}
