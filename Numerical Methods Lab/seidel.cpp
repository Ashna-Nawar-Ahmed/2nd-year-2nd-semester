///SEIDEL
#include<bits/stdc++.h>

using namespace std;
#define maxIt 100
int main()
{
    cout << "How many unknowns? : ";
    int n;
    cin >>  n;

    double arr[n][n+1], u[n], v[n];

    for(int i = 0; i<n; i++)
    {
        u[i] = 0;
        for(int j = 0; j<=n; j++)
        {
            cin >> arr[i][j];
        }
    }
    int it = 0;
    bool flag = true;
    do
    {
        ++it;
        for(int i= 0; i < n; i++)
        {
            double temp = arr[i][n];
            for(int j = 0; j< n; j++)
            {
                if(i!=j)
                {
                    arr[i][n] = arr[i][n] - arr[i][j] * u[j];
                }
                u[i] = arr[i][n]/arr[i][i];
            }
            arr[i][n] = temp;
            if(fabs((v[i]-u[i])/v[i]) <= 0.01 && it < maxIt)
                flag = false;
        }
        //for(int k = 0; k<n; k++)
        //    u[k] = v[k];3
    }
    while(it < maxIt);

    for(int i = 0; i < n; i++)
    {
        cout << "\nRoot (" << i+1 << "): " << u[i];
    }
    return 0;
}


