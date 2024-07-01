#include <bits/stdc++.h>
using namespace std;
#define fast ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
#define ll long long
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

int main() {

	ll n,start;
	cin in n in start;

	vi a(n+5);
	fo(i,1,n) cin in a[i];

	vi forwarddp(n+5,-INF);
	vi backwarddp(n+5);

	forwarddp[start] = 0;
	if(start != n) forwarddp[start+1] = a[start+1];

	fo(i,start+2,n) forwarddp[i] = a[i] + max(forwarddp[i-1] , forwarddp[i-2]);

	backwarddp[n] = forwarddp[n];
	backwarddp[n-1] = max(forwarddp[n]+a[n-1],forwarddp[n-1]);

	for(ll i = n-2; i >= 1; i--) backwarddp[i] = max(forwarddp[i],a[i]+max(backwarddp[i+1],backwarddp[i+2]));

	cout out backwarddp[1];

	return 0;

}
