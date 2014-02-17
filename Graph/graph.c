#include <iostream>
#include <algorithm>
#include <string.h>
using namespace std;

bool graph[50001][50001];


int pf(int l,int k,int n,bool vist[])
{
    if( graph[l][k]==1&&vist[k]==false)
            return 1;
    for(int i=0;i<n;i++)
    {
        if(graph[l][i]==true&&vist[i]==false)
        {
           
            vist[i]=true;
            if(pf(i,k,n,vist))
                return 1;
        }
    }    
    return 0;
}


int main() {
 int window[50001]={0};
 int m,n,i,k,l,j,ctr=0,ctr1=0,fg;
 cin>>n>>m;
 for(i=0;i<n;i++)
    cin>>window[i];
 for(i=0;i<m;i++)
 {
    cin>>k>>l;
    graph[k-1][l-1]=true;
    graph[l-1][k-1]=true;
 }
 for(i=0;i<n;i++)
 {
     
     fg=0;
     if(window[i]==1)
     {
         
         for(j=i+1;j<n;j++)
         {
            bool vist[50001]={0};
            vist[i]=true;
            if(window[j]==1&&pf(i,j,n,vist))
            {
                fg=1;
                ctr++;
            }
            
         }
         if(fg==1)
            ctr1++;
     }
     if(ctr1>1)
        ctr1++;
 }
 cout<<ctr<<" "<<ctr1;
 
 return 0;
}
