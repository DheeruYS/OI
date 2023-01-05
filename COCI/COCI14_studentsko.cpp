#include<bits/stdc++.h>
using namespace std;
#define fast ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
#define ll long long int
const ll N = 100+5 , INF = 1e18 , MOD = 1e9+7;
 
void solve(){
 
	ll n,k;
	cin >> n >> k;
 
	vector<pair<ll,ll>> a(n+5);
 
	for(ll i = 1; i <= n; i++){
		cin >> a[i].first;
		a[i].second = i;
	}
 
	sort(a.begin()+1,a.begin()+n+1);
 
	vector<ll> b(n+5);
	for(ll i = 1; i <= n; i++) b[a[i].second] = ((i+k-1)/k);
 
	vector<ll> sub;
	sub.push_back(b[1]);
	
	for(ll i = 2; i <= n; i++){
 
		ll low = 0 , high = sub.size()-1;
		ll ind = INF;
 
		while(low <= high){
			ll mid = (low+high)/2;
			if(sub[mid] > b[i]){
				ind = mid;
				high = mid-1;
			}
			else low = mid+1;
		}
 
		if(ind == INF) sub.push_back(b[i]);
		else sub[ind] = b[i];
	}
 
	cout << n-sub.size();
}
 
int main(){
 
	fast;
 
	ll tc = 1;
	// cin >> tc;
	while(tc--) solve();
 
	return 0;
}
