
#include<stdio.h>
#include<stdlib.h>
#include<iostream>
#include<string.h>
using namespace std;
int max(int a1,int a2,int a3){
   if(a1>=a2 && a1>=a3)
    return a1;
   else if(a2>=a1 && a2>=a3)
    return a2;
   else
    return a3;
}
int main(){
   char *s1,*s2;
   int n1,n2,i,j;
   cin>>n1;
   cin>>n2;
   s1=new char[n1];
   s2=new char[n2];
   cin>>s1;
   cin>>s2;
   //cout<<s1<<" "<<s2;
   int arr[n1+1][n2+1];
   for(i=0;i<n1+1;i++)
   arr[i][0]=i*-2;
   for(i=0;i<n2+1;i++)
    arr[0][i]=i*-2;
   for(i=1;i<n1+1;i++){
      for(j=1;j<n2+1;j++){
        if(s1[i-1]==s2[j-1])
            arr[i][j]=max(arr[i-1][j-1]+5,arr[i-1][j]-2,arr[i][j-1]-2);
        else
            arr[i][j]=max(arr[i-1][j-1]-1,arr[i][j-1]-2,arr[i-1][j]-2);
      }

   }
   cout<<"Score Matrix for global sequence alignment is ";
   cout<<"\n";
   for(i=0;i<n1+1;i++){
    for(j=0;j<n2+1;j++){
        cout<<arr[i][j]<<" ";
    }
    cout<<"\n";
   }
   return 0;
}
