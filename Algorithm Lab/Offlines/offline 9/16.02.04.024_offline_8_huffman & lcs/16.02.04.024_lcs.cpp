#include<bits/stdc++.h>
using namespace std;
void lcsGenerator( char *X, char *Y, int m, int n );
int main()
{
    string s1,s2;
    cout<<"Enter 1st string:"<<endl;
    cin>>s1;
    cout<<"Enter 2nd string:"<<endl;
    cin>>s2;
    int m = s1.length();
    int n = s2.length();
    char X[m],Y[n];
    for(int i=0; i<m; i++)
        X[i]=s1[i];
    for(int i=0; i<n; i++)
        Y[i]=s2[i];
    lcsGenerator(X, Y, m, n);
    return 0;
}
void lcsGenerator( char *X, char *Y, int m, int n )
{
    int c[m+1][n+1];
    for (int i=0; i<=m; i++){
        c[i][0]=0;
    }
    for (int j=0; j<=n; j++){
        c[0][j]=0;
    }
    for (int i=0; i<=m; i++)
    {
        for (int j=0; j<=n; j++)
        {
            if (i == 0 || j == 0)
                c[i][j] = 0;
            else if (X[i-1] == Y[j-1])
                c[i][j] = c[i-1][j-1] + 1;
            else
                c[i][j] = max(c[i-1][j], c[i][j-1]);
        }
    }

    int lastPos = c[m][n];
    char LCS[lastPos+1];
    LCS[lastPos] = '\0';
    int i = m, j = n;
    while (i > 0 && j > 0)
    {
        if (X[i-1] == Y[j-1])
        {
            LCS[lastPos-1] = X[i-1];
            i--;
            j--;
            lastPos--;
        }
        else if (c[i-1][j] > c[i][j-1])
            i--;
        else
            j--;
    }
    cout << "LCS of " << X << " and " << Y << " is " << LCS;
}

