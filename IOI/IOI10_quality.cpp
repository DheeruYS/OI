#include<bits/stdc++.h>
using namespace std;
#define fast ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
#define ll long long int
const ll N = 3000+5 , INF = 1e18 , MOD = 1e9+7;

vector<vector<ll>> grid(N,vector<ll>(N));
ll n,m,h,w;

bool check(ll x){

	vector<vector<ll>> presum(n+5,vector<ll>(m+5));

	for(ll i = 1; i <= n; i++){
		for(ll j = 1; j <= m; j++){
			presum[i][j] = presum[i-1][j]+presum[i][j-1]-presum[i-1][j-1]+(grid[i][j] > x ? -1 : 1);
		}
	}

	for(ll i = 1; i <= n; i++){
		for(ll j = 1; j <= m; j++){
			ll newi = i+h-1;
			ll newj = j+w-1;

			if(newi > n || newj > m) continue;

			ll sum = presum[newi][newj]-presum[newi][j-1]-presum[i-1][newj]+presum[i-1][j-1];
			if(sum >= 0) return true;
		}
	}

	return false;

}

void solve(){

	cin >> n >> m >> h >> w;

	for(ll i = 1; i <= n; i++){
		for(ll j = 1; j <= m; j++){
			cin >> grid[i][j];
		}
	}

	ll low = 1 , high = n*m;
	ll ans;

	while(low <= high){
		ll mid = (low+high)/2;
		if(check(mid)){
			ans = mid;
			high = mid-1;
		}
		else low = mid+1;
	}

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
