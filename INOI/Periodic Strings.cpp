#include <bits/stdc++.h>
using namespace std;
#define fast ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
#define ll long long int
#define tc ll test;cin >> test;while(test--)
#define vi vector<ll>
#define pb push_back
#define mp make_pair
#define INF 0x3f3f3f3f3f
#define MOD 13371337
#define ff first
#define ss second
#define in >>
#define out <<
#define space << " " <<
#define spacef << " "
#define fo(i,a,b) for(ll i = a; i <= b; i++)
#define nextline out "\n"
#define print(x) for(auto i : x ) cout out i spacef
#define mmax(x,i) x = max(x,i)
#define mmin(x,i) x = min(x,i)
#define N 200005

ll power(ll x, ll y , ll m){
    if(y == 1) return x;

    ll res = (power(x, y / 2 , m)) % m;

    if(y % 2) return ((res * res * x) % m);
    return ((res * res) % m);
}

int main() {

    fast;

    ll n,m;
    cin in n in m;

    vi dp(n+5);

    // dp[i] = number of ways we can create non-perioidic strings with length n

    dp[1] = 2;

    fo(i,2,n){

        dp[i] = power(2,i,m) - dp[1];
        dp[i] %= m;

        for(ll j = 2; j*j <= i; j++){
            if(i%j == 0){
                dp[i] -= dp[j];

                dp[i] += m;
                dp[i] %= m;

                if(j*j != i ){
                    dp[i] -= dp[i/j];
                    dp[i] += m;
                    dp[i] %= m;
                }
            }
        }
    }

    cout out dp[n];

    return 0;
}
