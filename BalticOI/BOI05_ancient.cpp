#include<bits/stdc++.h>
using namespace std;
#define fast ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
#define ll long long int
const ll N = 15+5 , INF = 1e18 , MOD = 1e9+7;

vector<ll> a(N);
ll n;
ll ve,vc,ce,cc;
ll dp[N][30][5][5];

bool vowel(ll x){
	if(x == 1 || x == 5 || x == 9 || x == 15 || x == 21) return true;
	return false;
}

ll go(ll i , ll pre , ll equal , ll consecutive){

	if(i == n+1) return 1;
	if(dp[i][pre][equal][consecutive] != -1) return dp[i][pre][equal][consecutive];

	ll ans = 0;

	if(pre == 0){
		for(ll c = 1; c <= 26; c++) if(a[i] == 0 || a[i] == c) ans += go(i+1,c,1,1);
		return ans;
	}

	for(ll c = 1; c <= 26; c++){

		if(a[i] == 0 || a[i] == c){

			if(vowel(pre)){
				if(vowel(c)){
					ll x1;
					if(pre == c) x1 = equal+1;
					else x1 = 1;
					ll x2 = consecutive+1;

					if(x1 > ve || x2 > vc) continue;
					ans += go(i+1,c,x1,x2);
				}
				else{
					ans += go(i+1,c,1,1);
				}
			}
			else{
				if(vowel(c)){
					ans += go(i+1,c,1,1);
				}
				else{
					ll x1;
					if(pre == c) x1 = equal+1;
					else x1 = 1;
					
					ll x2 = consecutive+1;

					if(x1 > ce || x2 > cc) continue;
					ans += go(i+1,c,x1,x2);
				}
			}
		}
	}

	return dp[i][pre][equal][consecutive] = ans;
}

void solve(){

	cin >> ve >> vc >> ce >> cc;

	string s;
	cin >> s;

	n = s.size();
	s = ' '+s;

	for(ll i = 1; i <= n; i++){
		if(s[i] == '*') a[i] = 0;
		else a[i] = (int)(s[i])-96;
	}

	memset(dp,-1,sizeof dp);

	cout << go(1,0,0,0);
}

int main(){

	fast;

// 	#ifndef ONLINE_JUDGE
// 		freopen("input.txt","r",stdin);
// 		freopen("output.txt","w",stdout);
// 	#endif

	ll tc = 1;
	// cin >> tc;
	while(tc--) solve();

	return 0;
}
