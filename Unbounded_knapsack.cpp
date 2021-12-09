//in unbounded knapsack i can take any item more than one time if it is included if not included initially i will discard them and not take further.
#include <bits/stdc++.h>

using namespace std;
int main()
{
   int n,w;
   cin>>n>>w;
   int t[n+1][w+1];
   int wt[n],val[n];
   for(int i=0;i<n;i++)
   {
       cin>>wt[i];
   }
   for(int i=0;i<n;i++)
   {
       cin>>val[i];
   } 
   for(int i=0;i<n+1;i++)
   {
       for(int j=0;j<w+1;j++)
       {
           if(i==0||j==0)
           {
               t[i][j]=0;
           }
       }
   }
   
   for(int i=1;i<n+1;i++)
   for(int j=1;j<w+1;j++)
   {
       if(wt[i-1]<=j)
       {
           t[i][j]=max(val[i-1]+t[i][j-wt[i-1]],t[i-1][j]);
           
       }
       else 
       t[i][j]=t[i-1][j];
   }
   cout<<t[n][w];
    return 0;
}
