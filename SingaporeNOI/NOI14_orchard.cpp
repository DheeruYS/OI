#include <bits/stdc++.h>
using namespace std;
#define fast ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
#define ll long long int
#define tc ll test;cin >> test;while(test--)
#define vi vector<ll>
#define pll pair<ll,ll>
#define pb push_back
#define mp make_pair
#define INF 1e18
#define MOD 1000000007
#define ff first
#define ss second
#define in >>
#define out <<
#define space << " " <<
#define spacef << " "
#define fo(i,a,b) for(ll i = a; i <= b; i++)
#define rfo(i,a,b) for(ll i = a; i >= b; i--)
#define nextline out "\n"
#define print(x) for(auto i : x ) cout out i spacef
#define mmax(x,i) x = max(x,i)
#define mmin(x,i) x = min(x,i)
#define N 105
 
vector<vi> grid;
vector<vi> sum;
vector<vi> sum0;
vector<vi> sum1;
 
int main() {
    
    fast;
 
	ll n,m;
	cin in n in m;
 
	ll cnt = 0;
 
	fo(i,0,n+1){
		vi a;
		fo(j,0,m+1){
			a.pb(0);
		}
 
		grid.pb(a);
		sum.pb(a);
		sum0.pb(a);
		sum1.pb(a);
	}
 
	fo(i,1,n){
		fo(j,1,m){
 
			cin in grid[i][j];
 
			if(!grid[i][j]) grid[i][j] = -1;
			else cnt++;
			
			sum0[i][j] = sum0[i-1][j]+sum0[i][j-1]-sum0[i-1][j-1]+(grid[i][j] == -1);
			sum1[i][j] = sum1[i-1][j]+sum1[i][j-1]-sum1[i-1][j-1]+(grid[i][j] == 1);
			sum[i][j] = sum[i-1][j]+sum[i][j-1]-sum[i-1][j-1]+grid[i][j];
		}
	}
 
	ll ans = INF;
 
	fo(r1,1,n){
		fo(r2,r1,n){
			
			ll left = 1;
 
			for(ll right = 1; right <= m;){
				ll s = sum[r2][right]-sum[r2][left-1]-sum[r1-1][right]+sum[r1-1][left-1];
				ll one = cnt-(sum1[r2][right]-sum1[r2][left-1]-sum1[r1-1][right]+sum1[r1-1][left-1]);
				ll zero = sum0[r2][right]-sum0[r2][left-1]-sum0[r1-1][right]+sum0[r1-1][left-1];
 
				mmin(ans,one+zero);
 
				if(s < 0) left = right+1;
				right++;
			}
		}
	}
 
	cout out ans;
 
    return 0;
}
