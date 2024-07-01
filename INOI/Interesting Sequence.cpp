#include <bits/stdc++.h>
using namespace std;
#define fast ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
typedef long long int ll;
#define tc ll test;cin >> test;while(test--)
#define vi vector<ll>
#define pb push_back
#define mp make_pair
#define pll pair<ll,ll>
#define INF 1e18
#define MOD 1000000007
#define ff first
#define ss second
#define in >>
#define out <<
#define space << " " <<
#define spacef << " "
#define fo(i,a,b) for(ll i = a; i <= b; i++)
#define nextline out "\n"
#define print(x) for(auto i : x ) cout out i spacef
#define mmax(x,i) x = max((x),(i))
#define mmin(x,i) x = min((x),(i))
#define N 3005

ll n,l;
vector<pll> a(N);

bool isPossible(ll cost){

    vi dp(n+5,1);
    // dp[i] = maximum length of the interesting sequence possible if we select the ith element

    // recurrence relation :

    fo(i,1,n){
        fo(j,1,n){
            if(abs(a[j].second - a[i].second) >= cost && a[j].first >= a[i].first){
                mmax(dp[i],dp[j]+1);
            }
        }
    }

    // answer :

    ll maxl = -INF;
    fo(i,1,n) mmax(maxl,dp[i]);

    return maxl >= l;
}

int main() {

    fast;

    tc{

        cin in n in l;

        fo(i,1,n) {
            cin in a[i].first;
            a[i].second = i;
        }

        sort(a.begin()+1,a.begin()+n+1,greater<>());

        ll ans = 0;

        fo(i,1,n){
            fo(j,1,n){
                if(a[i].first == a[j].first){
                    mmax(ans,abs(a[j].second - a[i].second));
                }
            }
        }

        ll low = ans;
        ll high = n - 1;
        ll an = ans;

        while (low <= high) {

            ll mid = (low + high) / 2;
            if (isPossible(mid) == true) {
                low = mid + 1;
                an = mid;
            } else {
                high = mid - 1;
            }
        }

        mmax(ans,an);
        

        cout out ans nextline;

        a.clear();
        a.resize(N);
    }

    return 0;
}
