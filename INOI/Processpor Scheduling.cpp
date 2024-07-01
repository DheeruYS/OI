#include <bits/stdc++.h>
using namespace std;
#define fast ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
typedef long long int ll;
#define tc ll test;cin >> test;while(test--)
#define vi vector<ll>
#define pll pair<ll,ll>
#define pb push_back
#define mp make_pair
#define INF 0x3f3f3f3f3f
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
#define mmax(x,i) x = max(x,i)
#define mmin(x,i) x = min(x,i)
#define N 5005

vector<vi> dp(N,vi(N,INF));

int main() {

    fast;

    tc{

        ll n,m;
        cin in n in m;

        fo(i,0,n){
            fo(j,0,m){
                dp[i][j] = INF;
            }
        }

        vector<vi> pjob(m+5,vi(2));
        vi c(n+5);

        fo(i,1,n) cin in c[i];
        fo(i,1,m) cin in pjob[i][1];
        fo(i,1,m) cin in pjob[i][0];

        sort(pjob.begin()+1,pjob.begin()+m+1);
        fo(i,1,m) swap(pjob[i][0],pjob[i][1]);

        // dp[i][j] = minimum time required to complete the first i classified jobs and first j public jobs

        // base case :

        dp[0][0] = 0;
        fo(i,1,n) dp[i][0] = dp[i-1][0] + c[i];

        // recurrence relation :

        fo(i,0,n){
            fo(j,1,m){

                if(i != 0 && dp[i-1][j] != INF){
                    dp[i][j] = dp[i - 1][j] + c[i]; // If we do the classified job
                }

                /*
                
                 If we do the public job

                 pjob[j][0] = p[j]
                 pjob[j][1] = t[j]

                 Case 1 :

                        t[j].......dp[i][j-1]

                        cost = INF

                 Case 2 :

                        dp[i][j-1].............................t[j]
                                  <------------------->
                                            p[j]

                        cost = t[j]

                 Case 3 :

                        dp[i][j-1]............t[j]
                                  <--------------------->
                                            p[j]

                        cost = dp[i][j-1] + p[j]

                */
                ll cost;

                ll p = pjob[j][0];
                ll t = pjob[j][1];

                if (t < dp[i][j - 1]) continue;
                else if (dp[i][j - 1] + p <= t) cost = t;
                else if (dp[i][j - 1] + p > t) cost = dp[i][j - 1] + p;

                mmin(dp[i][j],cost);
            }
        }

        // asnwer :

        if(dp[n][m] == INF ) cout out "-1";
        else cout out dp[n][m];

        cout nextline;
    }

    return 0;
}
