//same as unbounded knapsack only name change like weight array= length array and value array=price array and weight=size of rod........
#include<bits/stdc++.h>
using namespace std;
int t[100][100];
int rod_cutting(int price[],int length[],int n)
{
    
    for(int i=0;i<n+1;i++)
   {
       for(int j=0;j<n+1;j++)
       {
           if(i==0||j==0)
           {
               t[i][j]=0;
           }
       }
   }
   for(int i=1;i<n+1;i++)
   for(int j=1;j<n+1;j++)
   {
       if(length[i-1]<=j)
       t[i][j]=max(price[i-1]+t[i][j-length[i-1]],t[i-1][j]);
       else
       t[i][j]=t[i-1][j];
   }
   return t[n][n];
}
int main()
{
    int n;
    cin>>n;
    int price[n],length[n];
    for(int i=0;i<n;i++)
    length[i]=i+1;
    for(int i=0;i<n;i++)
    cin>>price[i];
    cout<<rod_cutting(price,length,n);
    return 0;
}
