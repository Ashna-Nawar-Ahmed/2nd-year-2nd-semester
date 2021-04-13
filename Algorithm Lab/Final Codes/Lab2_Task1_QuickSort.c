#include<stdio.h>
int ar[1000],r;
void QS(int ar[],int p,int r);
int PARTITION(int ar[],int p,int r);
int main()
{
    int p,i;
    printf("Enter array size:");
    scanf("%d",&r);
    printf("\nEnter array elements:");
    for(i=1; i<=r; i++)
        scanf("%d",&ar[i]);
    QS(ar,1,r);
    printf("\nUnsorted elements:\n");
    for(i=1; i<=r; i++)
        printf("%d\n",ar[i]);
    printf("\nSorted elements:\n");
    for(i=1; i<=r; i++)
        printf("%d\n",ar[i]);
    return 0;
}
void QS(int ar[],int p,int r)
{
    int q;
    if(p<r)
    {
        q=PARTITION(ar,p,r);
        QS(ar,p,q);
        QS(ar,q+1,r);
    }
}
int PARTITION(int ar[],int p,int r)
{
    int x=ar[r];
    int i=p-1,j,val;
    for(j=p; j<r; j++)
    {
        if(ar[i]<x)
        {
            val=ar[j];
            ar[j]=ar[i];
            ar[i]=val;
        }

    }
    val=ar[i+1];
    ar[i+1]=ar[r];
    ar[r]=val;


    return i+1;
}
