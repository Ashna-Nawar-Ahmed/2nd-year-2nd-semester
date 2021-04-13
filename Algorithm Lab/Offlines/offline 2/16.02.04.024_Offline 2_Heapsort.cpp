#include<bits/stdc++.h>
using namespace std;
int heapsize,alength,a[100];
int left(int i);
int right(int i);
void maxHeapify(int a[],int i);
void buildMaxHeap(int a[]);
void heapSort(int a[]);
int main()
{
    printf("Enter heapsize:");
    scanf("%d",&heapsize);
    alength=heapsize;
    printf("\nEnter values:\n");
    for(int i=1;i<=alength;i++)
    {
        scanf("%d",&a[i]);
    }
    printf("\nUnsorted values:\n");
    for(int i=1;i<=alength;i++)
    {
        printf("%d\n",a[i]);
    }
    heapSort(a);
    printf("\nSorted values:\n");
    for(int i=1;i<=alength;i++)
    {
        printf("%d\n",a[i]);
    }
    return 0;
}
int left(int i)
{
    return 2*i;
}
int right(int i)
{
    return 2*i+1;
}
void maxHeapify(int a[],int i)
{
    int largest=i;
    int l=left(i),r=right(i);
    if(a[largest]<a[l]&&l<=heapsize)
        largest=l;
    if(a[largest]<a[r]&&r<=heapsize)
        largest=r;
    if(largest!=i)
    {
        swap(a[largest],a[i]);
        maxHeapify(a,largest);
    }
}
void buildMaxHeap(int a[])
{
    int m=floor(alength/2);
    for(int i=m;i>=1;--i)
    {
        maxHeapify(a,i);
    }
}
void heapSort(int a[])
{
    buildMaxHeap(a);
    for(int i=1;i<=alength-1;i++)
    {
        swap(a[1],a[heapsize]);
        heapsize--;
        maxHeapify(a,1);

    }
}

