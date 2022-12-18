#include<bits/stdc++.h>
using namespace std;
#define fast ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
#define ll long long int
const ll N = 100+5 , INF = 1e18 , MOD = 1e9+7;

void solve(){

	ll n;
	string s;

	cin >> n >> s;

	string u = s;
	ll c = 0;

	for(ll i = 0; i < n; i++){
		if(s[i] == ',' && c%2 == 0) u[i] = '.';
		else if(s[i] == '"') c++;
	}

	cout << u;
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
