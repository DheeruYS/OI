#include <bits/stdc++.h>
using namespace std;
#define fast ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
#define ll long long int
#define tc ll test;cin >> test;while(test--)
#define vi vector<ll>
#define pll pair<ll,ll>
#define pb push_back
#define mp make_pair
#define INF 1e18
#define MOD 1000000007
#define ff first
#define ss second
#define in >>
#define out <<
#define space << " " <<
#define spacef << " "
#define fo(i,a,b) for(ll i = a; i <= b; i++)
#define rfo(i,a,b) for(ll i = a; i >= b; i--)
#define nextline out "\n"
#define print(x) for(auto i : x ) cout out i spacef
#define mmax(x,i) x = max(x,i)
#define mmin(x,i) x = min(x,i)
#define N 105
 
int main() {
    
    fast;
 
	map<vi,ll> dist;
	queue<vi> q;
		
	vi asc;
	fo(i,1,8) asc.pb(i);
 
	q.push(asc);
	dist[asc] = 0;
 
	while(!q.empty()){
 
		vi s = q.front();
		q.pop();
 
		fo(i,2,8){
			vi s1 = s;
			reverse(s1.begin(),s1.begin()+i);
 
			if(dist.find(s1) != dist.end()){
				if(dist[s1] > dist[s]+1){
					dist[s1] = dist[s]+1;
					q.push(s1);
				}
			}
			else{
				dist[s1] = dist[s]+1;
				q.push(s1);
			}
		}
	}
 
	tc{
		ll n;
		cin in n;
 
		vi a;
		fo(i,1,n){
			ll x;
			cin in x;
 
			a.pb(x);
		}
		reverse(a.begin(),a.end());
 
		vi b = a;
		sort(b.begin(),b.end());
 
		map<ll,ll> compress;
		ll number = 0;
 
		fo(i,0,n-1){
			if(compress.find(b[i]) == compress.end()){
				number++;
				compress[b[i]] = number;
			}
		}
 
		fo(i,0,n-1) a[i] = compress[a[i]];
		fo(i,number+1,8) a.pb(i);
 
		cout out dist[a] nextline;
	}
 
    return 0;
}
