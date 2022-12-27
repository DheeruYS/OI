#include<bits/stdc++.h>
using namespace std;
#define fast ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
#define ll long long int
const ll N = 100+5 , INF = 1e18 , MOD = 1e9+7;

void solve(){

	ll n,m;
	cin >> n >> m;

	vector<ll> path(m+5);
	for(ll i = 1; i <= m; i++) cin >> path[i];

	vector<ll> a(n+5),b(n+5),c(n+5);
	for(ll i = 1; i < n; i++) cin >> a[i] >> b[i] >> c[i];
		
	vector<ll> cnt(n+5,0);

	for(ll i = 2; i <= m; i++){
		cnt[min(path[i],path[i-1])]++;
		cnt[max(path[i],path[i-1])]--;
	}		
	for(ll i = 1; i <= n; i++) cnt[i] += cnt[i-1];

	ll ans = 0;
	for(ll i = 1; i < n; i++) ans += min(a[i]*cnt[i],b[i]*cnt[i]+c[i]);

	cout << ans << "\n";
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
