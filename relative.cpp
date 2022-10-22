

//In the name of ALLAH

#include<bits/stdc++.h>
using namespace std;

#define endl '\n'
#define optimize() ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define fraction() cout.unsetf(ios::floatfield); cout.precision(10); cout.setf(ios::fixed,ios::floatfield);

const int MX = 1e7+123;
bitset<MX> is_prime;
vector<long long int> prime;

void primeGen ( int n )
{
    n += 100;
    for ( int i = 3; i <= n; i += 2 ) is_prime[i] = 1;

    int sq = sqrt ( n );
    for ( int i = 3; i <= sq; i += 2 ) {
        if ( is_prime[i] == 1 ) {
            for ( int j = i*i; j <= n; j += ( i + i ) ) {
                is_prime[j] = 0;
            }
        }
    }
is_prime[1]=0;
    is_prime[2] = 1;
    prime.push_back (2);

    for ( int i = 3; i <= n; i += 2 ) {
        if ( is_prime[i] == 1 ) prime.push_back ( i );
    }
}

long long int phi( long long  int n ) // n = 120 = 2^3 * 3^1 * 5^1
{
    if(n==1)
        return 0;
    long long  int ret = n;
    for ( auto p : prime ) { //n = 5,  p = 5
        if ( 1LL * p * p > n || n == 0 ) break;

        if (  n % p == 0 ) {
            ret /= p; // ret = 20
            ret *= (p-1); // ret = 40

            while ( n % p == 0 ) {
                n /= p;
            }
        }
    }

    if ( n > 1 ) { // n = 5
        ret /= n; // ret = 8
        ret *= (n-1); // ret = 32
    }

    return ret;

}


int main()
{


    primeGen( 1e6 );
    long long n;


    while(scanf("%lld",&n)==1 && n)
    {
        printf("%lld\n",phi(n));
    }


    return 0;
}
