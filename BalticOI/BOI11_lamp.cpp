#include<bits/stdc++.h>
using namespace std;
#define fast ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
#define ll long long int
const ll N = 100+5 , INF = 1e18 , MOD = 1e9+7;

void solve(){

	ll n,m;
	cin >> n >> m;

	vector<vector<char>> grid(n+5,vector<char>(m+5));

	for(ll i = 1; i <= n; i++){
		for(ll j = 1; j <= m; j++){
			cin >> grid[i][j];
		}
	}

	deque<pair<ll,ll>> q;
	vector<vector<ll>> dist(n+5,vector<ll>(m+5,INF));

	q.push_front(make_pair(1,1));
	dist[1][1] = 0;

	vector<ll> dx = {-1,-1,0,0};
	vector<ll> dy = {0,1,0,1};

	while(!q.empty()){

		ll a = q.front().first;
		ll b = q.front().second;
		q.pop_front();

		ll x,y,cost,mx,my;

		x = a-1;
		y = b-1;
		mx = a-1;
		my = b-1;
		cost = dist[a][b]+(grid[x][y] == '/');

		if(mx >= 1 && mx <= n+1 && my >= 1 && my <= m+1 && dist[mx][my] > cost){
			if(grid[x][y] == '\\'){
				dist[mx][my] = dist[a][b];
				q.push_front(make_pair(mx,my));
			}
			else{
				dist[mx][my] = dist[a][b]+1;
				q.push_back(make_pair(mx,my));
			}
		}

		x = a-1;
		y = b;
		mx = a-1;
		my = b+1;
		cost = dist[a][b]+(grid[x][y] == '\\');

		if(mx >= 1 && mx <= n+1 && my >= 1 && my <= m+1 && dist[mx][my] > cost){
			if(grid[x][y] == '/'){
				dist[mx][my] = dist[a][b];
				q.push_front(make_pair(mx,my));
			}
			else{
				dist[mx][my] = dist[a][b]+1;
				q.push_back(make_pair(mx,my));
			}
		}

		x = a;
		y = b-1;
		mx = a+1;
		my = b-1;
		cost = dist[a][b]+(grid[x][y] == '\\');

		if(mx >= 1 && mx <= n+1 && my >= 1 && my <= m+1 && dist[mx][my] > cost){
			if(grid[x][y] == '/'){
				dist[mx][my] = dist[a][b];
				q.push_front(make_pair(mx,my));
			}
			else{
				dist[mx][my] = dist[a][b]+1;
				q.push_back(make_pair(mx,my));
			}
		}

		x = a;
		y = b;
		mx = a+1;
		my = b+1;
		cost = dist[a][b]+(grid[x][y] == '/');

		if(mx >= 1 && mx <= n+1 && my >= 1 && my <= m+1 && dist[mx][my] > cost){
			if(grid[x][y] == '\\'){
				dist[mx][my] = dist[a][b];
				q.push_front(make_pair(mx,my));
			}
			else{
				dist[mx][my] = dist[a][b]+1;
				q.push_back(make_pair(mx,my));
			}
		}

	}

	if(dist[n+1][m+1] == INF) cout << "NO SOLUTION";
	else cout << dist[n+1][m+1];
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
