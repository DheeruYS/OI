#include<bits/stdc++.h>
using namespace std;
#define fast ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
#define ll long long int
const ll N = 20000+5 , INF = 1e18 , MOD = 1e9+7;

vector<ll> a(N);
ll dp[N];
ll n,m,k;

ll go(ll i){

	if(i == n+1) return 0;
	if(dp[i] != -1) return dp[i];

	ll ans = INF;

	ll maxi = -INF , mini = INF , cnt = 0;

	for(ll j = i; j <= n; j++){
		maxi = max(maxi,a[j]);
		mini = min(mini,a[j]);
		cnt++;

		if(cnt > m) break;

		ans = min(ans,k+cnt*(maxi-mini)+go(j+1));
	}

	return dp[i] = ans;
}

void solve(){

	cin >> n >> m >> k;
	for(ll i = 1; i <= n; i++) cin >> a[i];

	memset(dp,-1,sizeof dp);

	cout << go(1) << "\n";
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
