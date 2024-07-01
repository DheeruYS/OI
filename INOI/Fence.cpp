#include <bits/stdc++.h>
using namespace std;
#define fast ios_base::sync_with_stdio(false); cin.tiille(NULL); cout.tie(NULL);
typedef long long int ll;
#define tc ll test;cin >> test;while(test--)
#define vi vector<ll>
#define pb push_back
#define mp make_pair
#define INF 0x3f3f3f3f3f
#define MOD 1e9 + 7
#define ff first
#define ss second
#define in >>
#define out <<
#define space << " " <<
#define spacef << " "
#define fo(i,a,b) for(ll i = a; i <= b; i++)
#define nextline out "\n"
#define print(x) for(auto i : x ) cout out i spacef
#define mmax(x,i) x = max(x,i)
#define mmin(x,i) x = min(x,i)

ll cnt = 0;
map<pair<ll,ll>,ll> grid;
map<pair<ll,ll>,bool> visited;

void floodfill(ll i , ll j){

    if(visited[mp(i,j)] == true) return;
    visited[mp(i,j)] = true;

    ll needed = 4;

    if(grid.find(mp(i-1,j)) != grid.end()){
        needed--;
        floodfill(i-1,j);
    }
    if(grid.find(mp(i+1,j)) != grid.end()){
        needed--;
        floodfill(i+1,j);
    }
    if(grid.find(mp(i,j-1)) != grid.end()){
        needed--;
        floodfill(i,j-1);
    }
    if(grid.find(mp(i,j+1)) != grid.end()){
        needed--;
        floodfill(i,j+1);
    }

    cnt += needed;
}

int main() {

    ll r , c, n;
    cin in r in c in n;

    fo(i,0,n-1){
        ll x,y;
        cin in x in y;
        grid[mp(x,y)] = 1;
        visited[mp(x,y)] = false;
    }

    ll ans = -INF;
    for(auto i : grid){
        if(visited[mp(i.first.first,i.first.second)] == true) continue;
        cnt = 0;
        floodfill(i.first.first,i.first.second);
        mmax(ans,cnt);
    }

    cout out ans;

    return 0;
}
