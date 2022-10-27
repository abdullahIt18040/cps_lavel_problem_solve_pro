
#include<bits/stdc++.h>
using namespace std;
#define optimization() ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define endl '\n'

const int mx=1e6+123;
bitset<mx>is_prime;
vector<int>prime;

void prime_gen(int n)
{
    for(int i=3;i<=n;i+=2)
    {
        is_prime[i]=1;
    }

    int sq=sqrt(n);
    for(int i=3;i<=sq;i+=2)
    {
        if(is_prime[i]==1)
        {
            for(int j=i*i;j<=n;j+=(i+i))
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

}

long long int phi(long long n)
{
    if(n==1)
        return 0;
    long long ret=n;

    for(auto p:prime)
    {
        long long len=p*p;
        if(len>n)
            break;
        if(n%p==0)
        {
            ret*=(p-1);
            ret/=p;
            while(n%p==0)
            {
                n/=p;
            }
        }


    }
    if(n>1)
    {
        ret*=n-1;
        ret/=n;
    }

    return ret;

}



 int main()
 {
     optimization();

     int lim=1e6;
     prime_gen(lim);


     long long int n;

     while(cin>>n)
     {

         if(n==0)
            break;

         cout<<phi(n)<<endl;
     }



return 0;


 }
