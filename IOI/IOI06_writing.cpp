#include<bits/stdc++.h>
using namespace std;
#define fast ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
#define ll long long int
const ll N = 100+5 , INF = 1e18 , MOD = 1e9+7;

void solve(){

	ll n,m;
	string s,t;
	cin >> n >> m;
	cin >> s >> t;

	map<char,ll> f1,f2;

	s = ' '+s;
	t = ' '+t;

	for(ll i = 1; i <= n; i++) f1[s[i]]++;

	ll ans = 0;

	for(ll i = 1; i <= n; i++) f2[t[i]]++;

	bool possible = true;
	for(auto u : f1){
		if(f2[u.first] != u.second){
			possible = false;
			break;
		}
	}
	if(possible) ans++;

	for(ll i = n+1; i <= m; i++){
		f2[t[i-n]]--;
		f2[t[i]]++;
		possible = true;
		for(auto u : f1){
			if(f2[u.first] != u.second){
				possible = false;
				break;
			}
		}
		if(possible) ans++;
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
