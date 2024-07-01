// Thanks to Saarang Srinivasan ( saarang123 ) for explaining this very elaborately

#include <bits/stdc++.h>
using namespace std;
#define fast ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
typedef long long int ll;
#define tc ll test;cin >> test;while(test--)
#define vi vector<ll>
#define pb push_back
#define mp make_pair
#define INF 0x3f3f3f3f3f
#define MOD 1000000007
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

int main() {

    tc {

        ll n,m,k;
        cin in n in m in k;

        vector<vi> grid(n+5, vi(m+5));
        vector<vi> presum(n+5, vi(m+5));

        fo(i, 1, n) {
            fo(j, 1, m) {
                cin in grid[i][j];
                presum[i][j] = presum[i][j - 1] + grid[i][j];
            }
        }

        vector<vector<vi>> maxdp(n+5,vector<vi>(m+5,vi(k+5)));
        vector<vector<vi>> mindp(n+5,vector<vi>(m+5,vi(k+5)));

        // maxdp[i][j][k] = maximum sum possible if we go from (i,j) to the top of grid with atmost k up-left moves
        // mindp[i][j][k] = minimum sum possible if we go from (i,j) to the top of grid with atmost k up-left moves and we wont consider the (i,j) itself in this

        // base case

        fo(i,1,n){
            fo(j,1,m){
                maxdp[i][j][0] = presum[i][j] + maxdp[i-1][j][0];
                mindp[i][j][0] = presum[i][j] - grid[i][j] + mindp[i-1][j][0];
            }
        }

        // recurrence

        fo(i,1,n){
            fo(j,1,m){
                fo(p,1,k){
                    maxdp[i][j][p] = presum[i][j] + max(maxdp[i-1][j-1][p-1],maxdp[i-1][j][p]);
                    mindp[i][j][p] = presum[i][j]  - grid[i][j] + min(mindp[i-1][j-1][p-1],mindp[i-1][j][p]);
                }
            }
        }

        // answer

        ll ans = -INF;

        fo(i,1,m){
            fo(j,i+k+1,m){
                ll x = maxdp[n][j][k]-mindp[n][i][k];
                mmax(ans,x);
            }
        }

        cout out ans nextline;

    }

    return 0;
}
