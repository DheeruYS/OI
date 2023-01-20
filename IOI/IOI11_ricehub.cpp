#include "ricehub.h"
#include<bits/stdc++.h>
using namespace std;
#define fast ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
#define ll int
const ll N = 100+5 , INF = 1e9 , MOD = 1e9+7;
 
int besthub(int R, int L, int X[], long long B){
 
	ll n = R;
	vector<long long> a(n+5),presum(n+5);
	for(ll i = 1; i <= n; i++){
		a[i] = X[i-1];
		presum[i] = presum[i-1]+a[i];
	}
 
	ll low = 1 , high = n;
	ll ans;
 
	function<bool(ll)> check = [&](ll l){
 
		for(ll i = 1; i <= n-l+1; i++){
			ll j = i+l-1;
			ll mid = (i+j)/2;
 
			long long cost = (mid-i)*a[mid]-presum[mid-1]+presum[i-1]+presum[j]-presum[mid]-(j-mid)*a[mid];
			if(cost <= B) return true;
		}
 
		return false;
	};
 
	while(low <= high){
		ll mid = (low+high)/2;
		if(check(mid)){
			ans = mid;
			low = mid+1;
		}
		else high = mid-1;
	}
 
	return ans;
}
