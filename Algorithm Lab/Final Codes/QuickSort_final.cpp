#include<bits/stdc++.h>
using namespace std;
int ar[100];
void QS(int ar[],int p,int r);
int PARTITION(int ar[],int p,int r);
int main()
{
    int n;
    printf("Enter n=");
    scanf("%d",&n);
    printf("Enter %d values to be sorted:",n);
    for(int i=1; i<=n; i++)
    {
        scanf("%d",&ar[i]);
    }
    printf("\nUnsorted elements:");
    for(int i=1; i<=n; i++)
    {
        printf("%d ",ar[i]);
    }
    QS(ar,1,n);
    printf("\nSorted elements:");
    for(int i=1; i<=n; i++)
    {
        printf("%d ",ar[i]);
    }
    return 0;

}
void QS(int ar[],int p,int r)
{
    int q;
    if(p<r)
    {
        q=PARTITION(ar,p,r);
        QS(ar,p,q-1);
        QS(ar,q+1,r);
    }
}
int PARTITION(int ar[],int p,int r)
{
    int x,i,j,temp;
    x=ar[r];
    i=p-1;
    for(j=p; j<=r-1; j++)
    {
        if(ar[j]<=x)
        {
            i++;
            /*temp=ar[i];
            ar[i]=ar[j];
            ar[j]=temp;*/
            swap(ar[i],ar[j]);
        }

    }
    /*temp=ar[i+1];
    ar[i+1]=ar[r];
    ar[r]=temp;*/
    swap(ar[i+1],ar[r]);
    return i+1;
}
