#include<bits/stdc++.h>
using namespace std;
#define fast ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
#define ll long long int
const ll N = 100+5 , INF = 1e18 , MOD = 1e9+7;

void solve(){

	ll n;
	cin >> n;

	vector<ll> a(n+5);
	ll cost = 0 , sum = 0;
	for(ll i = 1; i <= n; i++){
		cin >> a[i];
		cost += a[i]*(i-1);
		sum += a[i];
	}

	ll ans = cost;

	for(ll i = 2; i <= n; i++){
		cost -= (sum-a[i-1]);
		cost += (n-1)*(a[i-1]);
		ans = min(ans,cost);
	}

	cout << ans;
}

int main(){

	fast;

	freopen("cbarn.in","r",stdin);
	freopen("cbarn.out","w",stdout);

	ll tc = 1;
	// cin >> tc;
	while(tc--) solve();

	return 0;
}
