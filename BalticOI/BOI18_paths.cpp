#include<bits/stdc++.h>
using namespace std;
#define fast ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
#define ll long long int
const ll N = 3e5+5 , INF = 1e18 , MOD = 1e9+7;

ll dp[N][1ll<<6];
vector<ll> color(N);
vector<ll> adj[N];

ll go(ll i , ll mask){

	if(dp[i][mask] != -1) return dp[i][mask];

	ll ans = 1;

	for(auto u : adj[i]){
		ll x = color[u];
		if(mask&(1ll<<x)) continue;
		ans += go(u,mask|(1ll<<x));
	}

	return dp[i][mask] = ans;
}

void solve(){

	ll n,m,k;
	cin >> n >> m >> k;

	for(ll i = 1; i <= n; i++) cin >> color[i];

	for(ll i = 1; i <= m; i++){
		ll a,b;
		cin >> a >> b;

		adj[a].push_back(b);
		adj[b].push_back(a);
	}

	memset(dp,-1,sizeof dp);

	ll ans = 0;
	for(ll i = 1; i <= n; i++) ans += go(i,0|(1ll<<color[i]));

	ans -= n;
	cout << ans;
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
