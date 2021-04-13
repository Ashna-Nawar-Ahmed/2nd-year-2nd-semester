#include<stdio.h>
#include<vector>
using namespace std;
int main()
{
    vector<int> arr;
    int N,K,u,v,flag=0;
    scanf("%d %d",&N,&K);
    for(int i=0; i<N; i++)
    {
        int a;
        scanf("%d",&a);
        arr.push_back(a);
    }
    for(int i=0; i<N; i++)
    {
        u=arr[i];
        for(int j=i+1; j<N; j++)
        {
            v=arr[j];
            if(u+v==K)
            {
                printf("YES");
                flag=1;
                break;
            }
            else continue;
        }
        if(flag==1)
            break;
    }
    if(flag==0)
        printf("NO");
}

