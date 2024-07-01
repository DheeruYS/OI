// Easy Method , DFS :

#include <bits/stdc++.h>
using namespace std;
#define fast ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
typedef long long int ll;
#define tc ll test;cin >> test;while(test--)
#define vi vector<ll>
#define pb push_back
#define mp make_pair
#define INF 0x3f3f3f3f3f
#define MOD 7
#define ff first
#define ss second
#define in >>
#define out <<
#define space << " " <<
#define spacef << " "
#define fo(i,a,b) for(ll i = a; i <= b; i++)
#define nextline out "\n"
#define print(x) for(auto i : x ) cout out i spacef;
#define mmax(x,i) x = max(x,i)
#define mmin(x,i) x = min(x,i)

vi children[100005];
vector<bool> visited(100005);
vi wealth(100005);
ll maxdiff = -INF;


ll dfs(ll s){

    if(visited[s] == true) return INF;
    visited[s] = true;

    ll mininsubtreeofs = INF;

    if(children[s].size() == 0) return wealth[s];
    else{
        for(auto u : children[s]){
            mmin(mininsubtreeofs,wealth[u]);
            mmin(mininsubtreeofs,dfs(u));
        }
    }

    mmax(maxdiff,wealth[s]-mininsubtreeofs);

    return mininsubtreeofs;
}

int main() {

    ll n;
    cin in n;

    fo(i,0,n-1) cin in wealth[i];

    ll boss;

    fo(i,0,n-1) {
        ll x;
        cin in x;

        if(x == -1) boss = i;
        else children[x-1].pb(i);
    }

    dfs(boss);

    cout out maxdiff;

    return 0;
}

// More complex method : DP on Trees

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

vector<bool> visited(100005, false);
vi child[100005];
vi mindp(100005, INF);
vi wealth(100005);

void dfs(ll s) {

    if (visited[s] == true ) return;
    visited[s] = true;

    for (auto u : child[s]) {
        dfs(u);
        mmin(mindp[s], mindp[u]);
        mmin(mindp[s],wealth[u]);
    }

    if (child[s].size() == 0) mindp[s] = wealth[s];

}

int main() {

    ll n;
    cin in n;

    fo(i, 0, n - 1) cin in wealth[i];

    ll boss;

    vi parent(n + 5);

    fo(i, 0, n - 1) {
        cin in parent[i];
        if (parent[i] == -1) {
            boss = i;
            continue;
        }
        parent[i]--;
        child[parent[i]].pb(i);
    }

    dfs(boss);

    ll ans = 0;

    fo(i, 0, n - 1) mmax(ans, wealth[i] - mindp[i]);

    cout out ans;

    return 0;
}
