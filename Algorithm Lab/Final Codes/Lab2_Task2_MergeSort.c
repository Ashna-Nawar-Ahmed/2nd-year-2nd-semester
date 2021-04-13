#include<stdio.h>
int A[1000];
void MS(int A[],int s,int e);
void merge(int A[],int s,int m,int e);
int main()
{
    int e,i;
    printf("Enter array size:");
    scanf("%d",&e);
    printf("\nEnter array elements:");
    for(i=1; i<=e; i++)
        scanf("%d",&A[i]);
    printf("\nEntered array elements:");
    for(i=1; i<=e; i++)
        printf("%d\n",A[i]);
    MS(A,1,e);
    printf("\nSorted array elements:");
    for(i=1; i<=e; i++)
        printf("%d\n",A[i]);

    return 0;
}
void MS(int A[],int s,int e)
{
    int mid;
    if(s<e)
    {
        mid=(s+e)/2;
        MS(A,s,mid);
        MS(A,mid+1,e);
        merge(A,s,mid,e);
    }
}
void merge(int A[],int s,int m,int e)
{
    int n1=m-s+1,n2=e-m,i,j;
    int L[n1],R[n2];
    L[n1+1]=999999,R[n2+1]=999999;
    for(i=1;i<=n1;i++)
        L[i]=A[s+i-1];
    for(j=1;j<=n2;j++)
        R[j]=A[m+j];
    int k;
    i=1;
    j=1;
    for(k=s; k<=e; k++)
    {
        if(L[i]<R[j])
        {
            A[k]=L[i];
            i++;
        }
        else
        {

            A[k]=R[j];
            j++;

        }
    }
}
