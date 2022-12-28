#include<bits/stdc++.h>
using namespace std;
#define fast ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
#define ll long long int
const ll N = 400+5 , INF = 1e18 , MOD = 1e9+7;

ll dp[N][N];
ll n,k;
vector<ll> a(N);

ll go(ll i , ll change){

	if(i == n+1){
		if(change <= k+1) return 0;
		return INF;
	}
	if(change > k) return INF;

	if(dp[i][change] != -1) return dp[i][change];

	ll maxi = -INF , sum = 0;
	ll ans = INF;

	for(ll j = i; j <= n; j++){
		maxi = max(maxi,a[j]);
		sum += a[j];

		ll waste = (j-i+1)*maxi-sum;

		ans = min(ans,waste+go(j+1,change+1));
	}

	return dp[i][change] = ans;
}

void solve(){

	cin >> n >> k;
	for(ll i = 1; i <= n; i++) cin >> a[i];

	memset(dp,-1,sizeof dp);

	cout << go(1,0);
}

int main(){

	fast;

	
		freopen("snakes.in","r",stdin);
		freopen("snakes.out","w",stdout);
	

	ll tc = 1;
	// cin >> tc;
	while(tc--) solve();

	return 0;
}
