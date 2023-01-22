#include<bits/stdc++.h>
using namespace std;
#define fast ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
#define ll long long int
const ll N = 50+5 , INF = 1e18 , MOD = 1e9+7;

vector<vector<ll>> grid(N,vector<ll>(N)) , presum(N,vector<ll>(N));
ll dp[N][N][N][N];

ll go(ll ri , ll re , ll ci , ll ce){

	if(ri == re && ci == ce) return 0;
	if(dp[ri][re][ci][ce] != -1) return dp[ri][re][ci][ce];

	ll ans = INF;

	ll cost = presum[re][ce]-presum[ri-1][ce]-presum[re][ci-1]+presum[ri-1][ci-1];

	for(ll i = ri; i < re; i++) ans = min(ans,cost+go(ri,i,ci,ce)+go(i+1,re,ci,ce));
	for(ll j = ci; j < ce; j++) ans = min(ans,cost+go(ri,re,ci,j)+go(ri,re,j+1,ce));

	return dp[ri][re][ci][ce] = ans;
}

void solve(){

	ll n,m;
	cin >> n >> m;

	for(ll i = 1; i <= n; i++){
		for(ll j = 1; j <= m; j++){
			cin >> grid[i][j];
			presum[i][j] = presum[i-1][j]+presum[i][j-1]-presum[i-1][j-1]+grid[i][j];
		}
	}

	memset(dp,-1,sizeof dp);
	cout << go(1,n,1,m);
}

int main(){

	fast;

	#ifndef ONLINE_JUDGE
		freopen("input.txt","r",stdin);
		freopen("output.txt","w",stdout);
	#endif

	ll tc = 1;
	// cin >> tc;
	while(tc--) solve();

	return 0;
}
