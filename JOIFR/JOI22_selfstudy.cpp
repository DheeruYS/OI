#include<bits/stdc++.h>
using namespace std;
#define fast ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
#define ll long long int
const ll N = 3e5+5 , INF = 1e18 , MOD = 1e9+7;

vector<ll> a(N),b(N);
ll n,m;

bool check(ll x){

	ll cnt = 0;

	for(ll i = 1; i <= n; i++){
		ll maxi = max(a[i],b[i]);
		if(maxi*m < x){
			cnt += m;
			ll cur = x-(maxi*m);
			cnt += ((cur+b[i]-1)/b[i]);
		}
		else cnt += ((x+maxi-1)/maxi);
		
		if(cnt > (n*m)) return false;
	}

	return (cnt <= (n*m));
}

void solve(){

	cin >> n >> m;
	for(ll i = 1; i <= n; i++) cin >> a[i];
	for(ll i = 1; i <= n; i++) cin >> b[i];

	ll low = 1 , high = 1e18;
	ll ans;

	while(low <= high){
		ll mid = (low+high)/2;

		if(check(mid)){
			ans = mid;
			low = mid+1;
		}
		else high = mid-1;
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
