#include<bits/stdc++.h>
using namespace std;
#define fast ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
#define ll long long int
const ll N = 1e5+5 , INF = 1e18 , MOD = 1e9+7;

ll dp[N][3][3][2];
vector<ll> a(N);
ll n;

ll go(ll i , ll pre , ll change , ll consider){

	if(i == n+1) return 0;	
	if(dp[i][pre][change][consider] != -1) return dp[i][pre][change][consider];

	ll ans = INF;

	if(consider){
		if(a[i] == pre){
			if(change != 2) ans = 1+go(i+1,1-a[i],1,1);
			else ans = 0;
		}
		else{
			if(change == 1) ans = 1+go(i+1,a[i],2,1);
			else ans = 1+go(i+1,a[i],change,1);
		}
	}
	else{
		ans = max(go(i+1,2,0,1),go(i+1,2,0,0));
	}

	return dp[i][pre][change][consider] = ans; 
}

void solve(){

	cin >> n;
	for(ll i = 1; i <= n; i++) cin >> a[i];

	memset(dp,-1,sizeof dp);

	cout << max(go(1,2,0,1),go(1,2,0,0)) << "\n";
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
