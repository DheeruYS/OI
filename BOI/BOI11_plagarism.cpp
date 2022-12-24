#include<bits/stdc++.h>
using namespace std;
#define fast ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
#define ll long long int
const ll N = 100+5 , INF = 1e18 , MOD = 1e9+7;
 
void solve(){
 
	ll n;
	cin >> n;
 
	vector<ll> a(n+5);
	for(ll i = 1; i <= n; i++) cin >> a[i];
	sort(a.begin()+1,a.begin()+n+1);
 
	ll cnt = 0;
 
	for(ll i = 1; i <= n; i++){
		
		ll low = 1, high = i-1;
		ll ans = i;
		ll zeropoint9 = ceil((double)0.9 * (double)a[i]);
 
		while(low <= high){
			ll mid = (low+high)/2;
 
			if(a[mid] >= zeropoint9){
				ans = mid;
				high = mid-1;
			}
			else low = mid+1;
		}
 
		cnt += i-ans;
	}
 
	cout << cnt;
}
 
int main(){
 
	fast;
 
	// #ifndef ONLINE_JUDGE
	// 	freopen("input.txt","r",stdin);
	// 	freopen("output.txt","w",stdout);
	// #endif
 
	ll tc = 1;
	// cin >> tc;
	while(tc--) solve();
 
	return 0;
}
