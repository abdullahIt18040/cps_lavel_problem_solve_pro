#include<bits/stdc++.h>
using namespace std;
#define optimization() ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);

#define endl '\n'
const int mx=1e6+123;
long long  phi[mx];
long long res[mx];

int main()
{
    optimization();

    int lim=1e6;
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
        for(int j=i;j<=lim;j+=i)
        {
           res[j]+=(phi[i]*i) ;
        }
    }

    int tc;
    cin>>tc;
    while(tc--)
    {
      int n;
      cin>>n;
      long long sum;
      sum=res[n]+1;
      sum*=n;
      sum/=2;
      cout<<sum<<endl;



    }












 return 0;
}
