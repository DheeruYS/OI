#include<bits/stdc++.h>
using namespace std;
#define fast ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
#define ll long long int
const ll N = 100+5 , INF = 1e18 , MOD = 1e9+7;

void solve(){

	ll n;
	cin >> n;

	vector<ll> a(n+5),cnt(n+5);

	for(ll i = 1; i <= n; i++){
		cin >> a[i];
		ll x = a[i] , cur = 1;
		while((x%2)==0){
			x /= 2;
			cur*=2;
		}
		a[i] = x;
		cnt[i] = cnt[i-1]+cur;
	}

	ll q;
	cin >> q;

	while(q--){
		ll x;
		cin >> x;

		ll low = 1 , high = n;
		ll ind = n;

		while(low <= high){
			ll mid = (low+high)/2;

			if(cnt[mid] >= x){
				ind = mid;
				high = mid-1;
			}
			else low = mid+1;
		}

		cout << a[ind] << "\n";
	}
	
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
