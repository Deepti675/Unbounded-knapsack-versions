#include<bits/stdc++.h>
using namespace std;
//maximum number of ways to find coin sum (given in qus).
//value array ko remove kar dete hai kyu ki ek hi array diya hai
//unbounded knapsack lege kyu ki ek item kitni bar bhi use kar skte hai
//this question is related to subset sum and count of subset sum
//this problem same as count of subset sum but the difference is here we are including one element more than one time
//weight array coin array ho jayega and weight =sum ho jayega

int t[100][100];
int coin_change(int coin[],int n,int sum)
{
    
    for(int i=0;i<n+1;i++)
   {
       for(int j=0;j<sum+1;j++)
       {
           if(i==0)
           {
               t[i][j]=0;
           }
           if(j==0)
             t[i][j]=1;
       }
   }
   for(int i=1;i<n+1;i++)
   for(int j=1;j<sum+1;j++)
   {
       if(coin[i-1]<=j)
       t[i][j]=(t[i][j-coin[i-1]]+t[i-1][j]);
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
    cout<<coin_change(coin,n,sum);
    return 0;
}
