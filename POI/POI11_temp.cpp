#include<bits/stdc++.h>
using namespace std;
#define fast ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
#define ll int
const ll N = 1e6+5 , INF = 1e9 , MOD = 1e9+7;

int main(){

	fast;

	ll n;
	cin >> n;

	pair<ll,ll> a[n+1];
	
	for(ll i = 1; i <= n; i++) cin >> a[i].first >> a[i].second;

	ll ans = 1;
	ll left = 1, right = 1;
	multiset<ll> s;

	while(left <= n){

		if(right < left) right = left;

		while(right <= n){

			auto it = s.end();
			if(s.size()) it--;
			if(!s.size() || (*(it)) <= a[right].second){
				s.insert(a[right].first);
				right++;
			}
			else break;
		}

		ll x = s.size();
		ans = max(ans,x);

		if(s.count(a[left].first)) s.erase(s.find(a[left].first));
		left++;
	}

	cout << ans;

	return 0;
}
