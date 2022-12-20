#include<bits/stdc++.h>
using namespace std;
#define fast ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
#define ll long long int
const ll N = 1000+5 , INF = 1e18 , MOD = 1e9+7;

ll n;
vector<ll> a(N);
ll dp[N][N];

ll go(ll i , ll jump){

	if(i == n) return a[n];
	if(i > n) return INF;
	if(i < 1) return INF;

	if(dp[i][jump] != -1) return dp[i][jump];

	ll ans = go(i+jump+1,jump+1)+a[i];
	if(jump != 0) ans = min(ans,go(i-jump,jump)+a[i]);
	
	return dp[i][jump] = ans;
}

void solve(){

	cin >> n;
	for(ll i = 1; i <= n; i++) cin >> a[i];

	memset(dp,-1,sizeof dp);

	cout << go(1,0)-a[1];
}

int main(){

	fast;

	ll tc = 1;
	// cin >> tc;
	while(tc--) solve();

	return 0;
}
