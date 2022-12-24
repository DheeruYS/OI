#include<bits/stdc++.h>
using namespace std;
#define fast ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
#define ll long long int
const ll N = 200+5 , INF = 1e18 , MOD = 1e9+7;

ll p = 0 , n = 0;
ll m;
vector<ll> pos,neg;
ll dp[N][N][3];

ll dist(ll a , ll b){
	if(b < a) swap(a,b);
	return b-a;
}

ll go(ll i , ll j , ll last){

	if(i == n && j == p) return 0;
	if(i > n || j > p) return INF;

	if(dp[i][j][last] != -1) return dp[i][j][last];

	ll ans = INF;

	if(last == 0){
		ans = min(ans,go(1,0,2)+dist(0,neg[1])*m);
		ans = min(ans,go(0,1,1)+dist(0,pos[1])*m);
	}
	else if(last == 1){
		ans = min(ans,go(i,j+1,1)+dist(pos[j],pos[j+1])*(m-i-j));
		ans = min(ans,go(i+1,j,2)+dist(pos[j],neg[i+1])*(m-i-j));
	}
	else{
		ans = min(ans,go(i,j+1,1)+dist(neg[i],pos[j+1])*(m-i-j));
		ans = min(ans,go(i+1,j,2)+dist(neg[i],neg[i+1])*(m-i-j));
	}

	return dp[i][j][last] = ans;
}

void solve(){

	cin >> m;

	pos.push_back(0);

	for(ll i = 1; i <= m; i++){
		ll x;
		cin >> x;

		if(x < 0){
			neg.push_back(x);
			n++;
		}
		else{
			pos.push_back(x);
			p++;
		}
	}

	neg.push_back(0);
	reverse(neg.begin(),neg.end());

	memset(dp,-1,sizeof dp);


	cout << go(0,0,0);
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
