#include<bits/stdc++.h>
using namespace std;
#define endl '\n'
#define optimization() ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
int main()
{


    long long n;
    while(cin>>n)
    {
        long long int ans=1,cnt=1;

        while(ans%n !=0)
        {
            ans=((ans*10)+1)%n;
            cnt++;
        }
        cout<<cnt<<endl;
    }
    return 0;

}
