#include<bits/stdc++.h>
using namespace std;
#define optimization() ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define endl '\n'
const int mx=5e6+123;
unsigned long long int phi[mx];


 int main()
 {
     optimization();

 int lim=5e6+123;
 for(int i=1;i<=lim;i++)
 {
     phi[i]=i;
 }

 for(int i=2;i<=lim;i++)
 {

     if(phi[i]==i)
     {
         int p=i;
         for(int j=p;j<=lim;j+=p)
         {
             phi[j]*=(p-1);
             phi[j]/=p;
         }
     }
 }


 for(int i=1;i<=lim;i++)
 {
phi[i]*=phi[i];
phi[i]+=phi[i-1];

 }

int tc,k=1;
cin>>tc;
while(tc--)
{

 int a,b;
 cin>>a>>b;


     cout<<"Case "<<k<<": "<<phi[b]-phi[a-1]<<endl;
     k++;
}
return 0;


 }
