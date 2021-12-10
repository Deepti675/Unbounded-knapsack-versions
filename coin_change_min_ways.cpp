//minimum number of coin for given sum
//initialization m difference hoga from coin change problem for finding number of ways
//INT_MAX+1 negative ho jati hai value esliye INT_MAX-1 kiya taki jab INT_MAX-1+1 to wo puri value negative na ho.
#include<bits/stdc++.h>
using namespace std;
int t[100][100];
int coin_change_min_ways(int coin[],int n,int sum)
{
    
    //initialization*************************************************
    
    for(int i=0;i<n+1;i++)
    for(int j=0;j<sum+1;j++)
    {
        if(j==0)
        t[i][j]=0;
        if(i==0)
        t[i][j]=INT_MAX-1;
        
    }
    for(int i=1;i<n+1;i++)
    for(int j=1;j<sum+1;j++)
    {
        if(i==1)
        {
            if(j%coin[0]==0)
            t[i][j]=j/coin[0];
            else
            t[i][j]=INT_MAX-1;
        }
        
    }
    //*****************************************************************
    for(int i=2;i<n+1;i++)
    for(int j=1;j<sum+1;j++)
    {
        if(coin[i-1]<=j)
        //coin ko include krna hai to plus 1 *******************************
        t[i][j]= min(1+t[i][j-coin[i-1]],t[i-1][j]);
        else
        t[i][j]=t[i-1][j];
    }
    return t[n][sum];
}



int main()
{
    int n,sum;
    cin>>n;
    int coin[n];
    for(int i=0;i<n;i++)
    cin>>coin[i];
    
    cin>>sum;
    cout<<coin_change_min_ways(coin,n,sum);
    return 0;
}
