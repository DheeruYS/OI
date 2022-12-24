#include<bits/stdc++.h>
using namespace std;
#define fast ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
#define ll long long int
const ll N = 100+5 , INF = 1e18 , MOD = 1e9+7;
 
void solve(){
 
	ll n,k;
	cin >> n >> k;
 
	vector<ll> a(n+5);
	for(ll i = 1; i <= n; i++) cin >> a[i];
 
	vector<ll> diff;
	for(ll i = 2; i <= n; i++) diff.push_back(a[i]-a[i-1]-1);
 
	sort(diff.begin(),diff.end());
 
	ll ans = n;
 
	for(ll i = 1; i <= n-k; i++) ans += diff[i-1];
 
	cout << ans;
}
 
int main(){
 
	fast;
 
	ll tc = 1;
	// cin >> tc;
	while(tc--) solve();
 
	return 0;
}
