#include<bits/stdc++.h>
using namespace std;
#define fast ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
#define ll long long int
const ll N = 100+5 , INF = 1e18 , MOD = 1e9+7;

void solve(){

	ll n,m;
	cin >> n >> m;

	vector<ll> a(n+5);
	for(ll i = 1; i <= n; i++){
		cin >> a[i];
		if(i != 1) a[i] = min(a[i],a[i-1]);
	}

	ll last = n+1;

	while(m--){

		ll x;
		cin >> x;

		ll low = 1 , high = last-1;
		ll ans = 0;

		while(low <= high){
			ll mid = (low+high)/2;
			if(a[mid] >= x){
				ans = mid;
				low = mid+1;
			}
			else high = mid-1;
		}

		last = ans;
	}

	cout << last;
}

int main(){

	fast;

	ll tc = 1;
	// cin >> tc;
	while(tc--) solve();

	return 0;
}
