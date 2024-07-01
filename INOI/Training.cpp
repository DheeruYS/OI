#include <bits/stdc++.h>
using namespace std;
#define fast ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
typedef long long int ll;
#define tc ll test;cin >> test;while(test--)
#define vi vector<ll>
#define pb push_back
#define mp make_pair
#define INF 0x3f3f3f3f3f
#define MOD 7
#define ff first
#define ss second
#define in >>
#define out <<
#define space << " " <<
#define spacef << " "
#define fo(i,a,b) for(ll i = a; i <= b; i++)
#define nextline out "\n"
#define print(x) for(auto i : x ) cout out i spacef;
#define mmax(x,i) x = max(x,i)
#define mmin(x,i) x = min(x,i)

ll CubeOfSumOfDigits(ll n){

    ll ans = 0;

    while(n != 0){
        ans += n%10;
        n /= 10;
    }

    return ans*ans*ans ;
}

int main() {

    ll n,sin;
    cin in n in sin;

    vi e(n+5);
    fo(i,1,n) cin in e[i];

    vi strenght(n+5);
    strenght[0] = sin;
    fo(i,1,n) strenght[i] = strenght[i-1]+CubeOfSumOfDigits(strenght[i-1]);

    vector<vi> dp(n+5,vi(n+5,0));

    // dp[i][j] = maximum XV possible if we train i times in the first j cities

    // base case :

    fo(i,0,n) dp[0][i] = 0;
    dp[1][1] = e[1]*strenght[0];

    // recurrence :

    fo(i,1,n){
        fo(j,i,n){
            dp[i][j] = max(dp[i][j-1],dp[i-1][j-1]+e[j]*strenght[j-i]);
        }
    }

    // answer :

    ll ans = -INF;
    fo(i,0,n) mmax(ans,dp[i][n]);

    cout out ans;

    return 0;
}
