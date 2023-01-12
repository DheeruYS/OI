#include<bits/stdc++.h>
using namespace std;
#define fast ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
#define ll int
const ll N = 21 , INF = 1e18 , MOD = 1e9+7;

ll dp[N][(1ll<<N)];
map<ll,vector<ll>> maskpossible;
vector<ll> a(N);
ll n,m;

ll go(ll i , ll mask){

	if(i == n+1) return 1;
	if(dp[i][mask] != -1) return dp[i][mask];

	ll ans = 0;

	for(auto u : maskpossible[a[i]]){
		if(mask&u) continue;
		ans |= go(i+1,mask|u);
	}

	return dp[i][mask] = ans;
}

void solve(){

	cin >> n >> m;
	for(ll i = 1; i <= n; i++) cin >> a[i];

	vector<ll> b(m+5);
	for(ll i = 1; i <= m; i++) cin >> b[i];

	for(ll i = 1; i < (1ll<<m); i++){
		ll sum = 0;
		for(ll j = 0; j < m; j++){
			if(i&(1ll<<j)){
				sum += b[j+1];
			}
		}
		maskpossible[sum].push_back(i);
	}

	memset(dp,-1,sizeof dp);

	if(go(1,0)) cout << "YES";
	else cout << "NO";
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
