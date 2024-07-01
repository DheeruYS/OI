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

	ll n;
	cin in n;

	vi cobol(n+5);
	vector<vi> other(n+5,vi(2));

	fo(i,0,n-1){
		ll x,y;
		cin in cobol[i] in x in y;
		other[i][0] = x+y;
		other[i][1] = i;
	}

	sort(other.rbegin(),other.rend());

	ll waiting = 0;

	ll ans = -INF;

	fo(i,0,n-1){
		ll time = waiting + other[i][0] + cobol[other[i][1]];
		waiting += cobol[other[i][1]];
		mmax(ans,time);
	}

	cout out ans;

	return 0;

}
