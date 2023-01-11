#include<bits/stdc++.h>
using namespace std;
#define fast ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
#define ll long long int
const ll N = 600+5 , INF = 1e18 , MOD = 1e9+7;

ll w,h,n;
vector<pair<ll,ll>> a(N);
ll dp[N][N];

ll go(ll i , ll j){

	if(i == 0 || j == 0) return 0;
	if(i < 0 || j < 0) return INF;

	if(dp[i][j] != -1) return dp[i][j];

	ll ans = i*j;
	
	for(ll tile = 1; tile <= n; tile++){
		if(a[tile].first <= i && a[tile].second <= j){
			ans = min(ans,go(i-a[tile].first,j)+go(a[tile].first,j-a[tile].second));
			ans = min(ans,go(i,j-a[tile].second)+go(i-a[tile].first,a[tile].second));
		}
	}

	return dp[i][j] = ans;
}

void solve(){

	cin >> w >> h >> n;
	for(ll i = 1; i <= n; i++) cin >> a[i].second >> a[i].first;

	memset(dp,-1,sizeof dp);

	cout << go(h,w);
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
