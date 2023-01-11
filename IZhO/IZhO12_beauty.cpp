#include<bits/stdc++.h>
using namespace std;
#define fast ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
#define ll long long int
const ll N = 20 , INF = 1e9 , MOD = 1e9+7;
 
ll twocount(ll x){
 
	ll cnt = 0;
 
	while(x){
		if(x%2 == 1) cnt++;
		x /= 2;
	}
 
	return cnt;
}
 
ll threecount(ll x){
 
	ll cnt = 0;
 
	while(x){
		if(x%3 == 1) cnt++;
		x /= 3;
	}
 
	return cnt;
}
 
ll c2[N],c3[N];
ll n;
ll dp[(1ll<<N)][N];
 
ll go(ll mask , ll last){
 
	if(__builtin_popcountll(mask) == n) return 1;
	if(last != -1 && dp[mask][last] != -1) return dp[mask][last];
 
	ll ans = 0;
 
	for(ll i = 0; i < n; i++){
		if(mask&(1ll<<i)) continue;
 
		if(last == -1) ans += go(mask|(1ll<<i),i);
		else if(c2[i] == c2[last] || c3[i] == c3[last]) ans += go(mask|(1ll<<i),i);
	}
 
	return dp[mask][last] = ans;
}
 
void solve(){
 
	cin >> n;
	vector<ll> a(n+5);
 
	for(ll i = 0; i < n; i++){
		cin >> a[i];
		c2[i] = twocount(a[i]);
		c3[i] = threecount(a[i]);
	}
 
	memset(dp,-1,sizeof dp);
 
	cout << go(0,-1);
}
 
int main(){
 
	fast;
 
	ll tc = 1;
	// cin >> tc;
	while(tc--) solve();
 
	return 0;
}
