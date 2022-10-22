#include<bits/stdc++.h>
using namespace std;

#define endl '\n'
#define optimization() ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
typedef long long ll;
const int mx=1e6+123;
bitset<mx>is_prime;
vector<int>prime;

void primeGen(int n)
{

    for(int i=3; i<=n; i+=2)
    {
        is_prime[i]=1;
    }
    int sq=sqrt(n);

    for(int i=3; i<=sq; i+=2)
    {
        if(is_prime[i]==1)
        {
            for(int j=i*i; j<=n; j+=(i+i))
            {
                is_prime[j]=0;


            }
        }
    }

    is_prime[2]=1;
    prime.push_back(2);
    for(int i=3;i<=n;i+=2)
    {
        if(is_prime[i]==1)
        {
            prime.push_back(i);
        }

    }

//    for(auto p:prime)
//    {
//        cout<<p<<" ";
//    }

}


int phi(int n)
{
    optimization();
    int ret=n;
    for(auto p:prime)
    {
        ll len=p*p;
        if(len>n)
        {
            break;
        }
        if(n%p==0)
        {
            ret/=p;
            ret*=(p-1);
            while(n%p==0)
            {
                n/=p;
            }
        }

    }
    if(n>1)
    {
        ret/=n;
        ret*=(n-1);
    }
    return ret;
}


int main()
{
int lim=1e6;
primeGen(lim);

int tc;
cin>>tc;
while(tc--)
{
    int m;
    cin>>m;
  cout<<phi(m)<<endl;
}





    return 0;

}
