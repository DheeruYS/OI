#include<bits/stdc++.h>
using namespace std;
#define fast ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
#define ll long long int
const ll N = 800+5 , INF = 1e18 , MOD = 1e9+7;

ll sx,sy,ex,ey;
vector<ll> dx = {0,0,-1,1};
vector<ll> dy = {-1,1,0,0};
vector<vector<ll>> bee(N,vector<ll>(N,INF));
vector<vector<char>> grid(N,vector<char>(N));
ll n,s;

bool check(ll start){

	vector<vector<double>> dist(n+5,vector<double>(n+5,INF));
	dist[sx][sy] = start;

	queue<pair<ll,ll>> q;
	q.push(make_pair(sx,sy));

	while(!q.empty()){
		ll a = q.front().first;
		ll b = q.front().second;
		q.pop();

		for(ll t = 0; t <= 3; t++){
			ll x = a+dx[t];
			ll y = b+dy[t];

			if(x < 1 || x > n || y < 1 || y > n || grid[x][y] == 'T' || grid[x][y] == 'H') continue;
			if(dist[x][y] != INF) continue;

			double d = dist[a][b]+((double)1/(double)s);

			if(bee[x][y] <= floor(d)) continue;
			
			dist[x][y] = d;
			q.push(make_pair(x,y));
		}
	}

	return (dist[ex][ey] != INF);
}

void solve(){

	cin >> n >> s;

	queue<pair<ll,ll>> q;

	for(ll i = 1; i <= n; i++){
		for(ll j = 1; j <= n; j++){
			cin >> grid[i][j];

			if(grid[i][j] == 'M'){
				sx = i;
				sy = j;
			}
			else if(grid[i][j] == 'H'){
				q.push(make_pair(i,j));
				bee[i][j] = 0;
			}
			else if(grid[i][j] == 'D'){
				ex = i;
				ey = j;
			}
		}
	}

	while(!q.empty()){
		ll a = q.front().first;
		ll b = q.front().second;
		q.pop();

		for(ll t = 0; t <= 3; t++){
			ll x = a+dx[t];
			ll y = b+dy[t];

			if(x < 1 || x > n || y < 1 || y > n || grid[x][y] == 'D' || grid[x][y] == 'T') continue;
			if(bee[x][y] != INF) continue;
			
			bee[x][y] = bee[a][b]+1;
			q.push(make_pair(x,y));
		}
	}

	ll low = 0 , high = bee[sx][sy]-1;
	ll ans = INF;

	while(low <= high){
		ll mid = (low+high)/2;

		if(check(mid)){
			ans = mid;
			low = mid+1;
		}
		else high = mid-1;
	}

	if(ans == INF) ans = -1;
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
