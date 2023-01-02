#include<bits/stdc++.h>
using namespace std;
#define fast ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
#define ll long long int
const ll N = 100+5 , INF = 1e18 , MOD = 1e9+7;

void solve(){

	ll n,m;
	cin >> n >> m;

	vector<vector<ll>> grid(n+5,vector<ll>(m+5)),presum(n+5,vector<ll>(m+5));

	for(ll i = 1; i <= n; i++){
		for(ll j = 1; j <= m; j++){
			cin >> grid[i][j];
			presum[i][j] = presum[i-1][j]+presum[i][j-1]-presum[i-1][j-1]+grid[i][j];
		}
	}

	ll h,w,c;
	cin >> h >> w >> c;

	vector<tuple<ll,ll,ll,ll,ll,ll>> waste;

	for(ll i = 1; i <= c; i++){
		ll x,y,a,b,arr,alt;
		cin >> x >> y >> a >> b >> arr >> alt;

		waste.push_back(make_tuple(x,y,a,b,arr,alt));
	} 

	ll maxi = 0;
	ll l,r;

	for(ll i = 1; i <= n-h+1; i++){
		for(ll j = 1; j <= m-w+1; j++){

			ll cur = 0;

			for(ll k = 0; k < c; k++){

				if(cur+c-k <= maxi) break;

				ll x,y,a,b,arr,alt;
				tie(x,y,a,b,arr,alt) = waste[k];

				ll ii = i+x-1;
				ll jj = j+y-1;

				if(arr == 0){

					if(ii > n-a+1 || jj > m-b-b+1) continue;

					ll newx1 = ii+a-1;
					ll newy1 = jj+b-1;

					ll sum1 = presum[newx1][newy1]-presum[newx1][jj-1]-presum[ii-1][newy1]+presum[ii-1][jj-1];

					ll newx2 = newx1;
					ll newy2 = newy1+b;

					ll sum2 = presum[newx2][newy2]-presum[newx2][newy1]-presum[ii-1][newy2]+presum[ii-1][newy1];

					double avg1 = ((double)sum1/(double)(a*b));
					double avg2 = ((double)sum2/(double)(a*b));

					if(alt == 0 && avg1 < avg2) cur++;
					else if(alt == 1 && avg1 >= avg2) cur++;
				}
				else{

					if(ii > n-a-a+1 || jj > m-b+1) continue;

					ll newx1 = ii+a-1;
					ll newy1 = jj+b-1;

					ll sum1 = presum[newx1][newy1]-presum[newx1][jj-1]-presum[ii-1][newy1]+presum[ii-1][jj-1];

					ll newx2 = newx1+a;
					ll newy2 = newy1;

					ll sum2 = presum[newx2][newy2]-presum[newx2][jj-1]-presum[newx1][newy2]+presum[newx1][jj-1];

					double avg1 = ((double)sum1/(double)(a*b));
					double avg2 = ((double)sum2/(double)(a*b));

					if(alt == 0 && avg1 < avg2) cur++;
					else if(alt == 1 && avg1 >= avg2) cur++;
				}
			}

			if(cur > maxi){
				maxi = cur;
				l = i;
				r = j;
			}
		}
	}

	cout << l << " " << r;
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
