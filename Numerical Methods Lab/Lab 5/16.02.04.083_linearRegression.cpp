///LINEAR REGRESSION
#include <bits/stdc++.h>

using namespace std;

int main()
{
    int n;
    cout << "Enter n?: ";
    cin >> n;
    double x[n], y[n], a, b;
     cout << "input for x";
    for (int i = 0; i < n ; i++)
    {
        cin >> x[i];
    }
    cout << endl;
    cout << "input for y";
    for (int i = 0; i < n ; i++)
    {
        cin >> y[i];
    }
    cout << endl;
    for(int i=0; i<n; i++)
    {
        printf("x%d=%.1f\ty%d=%.1f\n",i+1,i+1,i+1,x[i],y[i]);
    }
    double xysum = 0, xsum =0, ysum = 0, x2sum = 0;
    for(int i = 0; i <n; i++)
    {
        xsum += x[i];
        ysum += y[i];
        xysum += x[i]*y[i];
        x2sum += x[i]*x[i];
    }

    b = (n*xysum - (xsum * ysum))/(n*x2sum - (xsum*xsum));
    a = ysum/n - (b*xsum/n);
    double fit_y[n];
    for(int i = 0; i<n; i++)
    {
        fit_y[i] = b * x[i] + a;
    }

    cout << "S.no" << setw(5) << "x" << setw(19) << "y(observed)" << setw(19) << "y (fitted)" << endl;
    cout <<"_______________________________________________________________________________________\n";
    for (int i = 0 ; i < n ; i++)
        cout << i+1 << setw(5) << x[i] << setw(19) << y[i] << setw(19) << fit_y[i] << endl;

    cout << "\nThe linear fit line is of the form: \n\n" << b << "x + " << a <<endl;
    return 0;



}
