#include <bits/stdc++.h>
using namespace std;
#define fast ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
#define ll long long
#define tc ll test;cin >> test;while(test--)
#define vi vector<ll>
#define pb push_back
#define mp make_pair
#define INF 0x3f3f3f3f3f
#define MOD 20011
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

int main() {

    fast;

    ll n,m,d;
    cin in n in m in d;

    vector<vi> grid(n+5,vi(m+5));

    fo(i,1,n){
        fo(j,1,m){
            cin in grid[i][j];
        }
    }

    vector<vector<vi>> dp(n+5,vector<vi>(m+5,vi(2,0)));

    // SUB-PROBLEM :

    // dp[i][j][1] = Number of ways to come to (i,j) horizontally
    // dp[i][j][2] = Number of ways to come to (i,j) vertically

    // BASE CASE :

    dp[1][1][1] = 1;
    dp[1][1][2] = 1;

    fo(j,2,d+1){
        if(grid[1][j] == 0) break;
        dp[1][j][1] = 1;
    }

    fo(i,2,d+1){
        if(grid[i][1] == 0) break;
        dp[i][1][2] = 1;
    }

    // RECURRENCE RELATION :

    fo(i,2,n){
        fo(j,2,m){
            if(grid[i][j] == 0) continue;
            for(ll k = i-1; k >= max(1ll,i-d); k--){
                if(grid[k][j] == 0) break;
                dp[i][j][2] += dp[k][j][1];
                dp[i][j][2] %= MOD;
            }
            for(ll k =j-1; k >= max(1ll,j-d); k--){
                if(grid[i][k] == 0) break;
                dp[i][j][1] += dp[i][k][2];
                dp[i][j][1] %= MOD;
            }
        }
    }

    // OPTIMAL ANSWER :

    cout out (dp[n][m][1]%MOD + dp[n][m][2]%MOD)%MOD;

    return 0;

}
