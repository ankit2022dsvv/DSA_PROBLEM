#include <bits/stdc++.h>
#include <stdlib.h>
#include <time.h> 
 
using namespace std;
long long mod = 1e9 + 7;
double EPS = 1e-12;
typedef long long int lld;
typedef pair<lld,lld> PA;
long double tick(){static clock_t oldt; clock_t newt=clock();
    long double diff=1.0L*(newt-oldt)/CLOCKS_PER_SEC; oldt = newt; return diff; }
#define rep(i,a,n) for(long long int i = (a); i <= (n); ++i)
#define repI(i,a,n) for(int i = (a); i <= (n); ++i)
#define repD(i,a,n) for(long long int i = (a); i >= (n); --i)
#define repDI(i,a,n) for(int i = (a); i >= (n); --i)
inline lld sc() { lld a; scanf("%lld", &a); return a; }
inline int scd() { int a; scanf("%d", &a); return a; }
#define prL(a) printf("%lld\n",a)
#define prS(a) printf("%lld ",a)
#define prdL(a) printf("%d\n",a)
#define prdS(a) printf("%d ",a)
#define all(c) (c).begin(), (c).end()
#define sz(a) ((int)a.size())
#ifdef LOCAL_RUN
#define Error(x...) { cout << "(" << #x << ")" << " = ( "; printIt(x); }
#define errorpair(a) cout<<#a<<" = ( "<<((a).first)<<" , "<<((a).second)<<" )\n";
#else
#define Error(x...) 42
#define errorpair(a) 42
#endif
template <typename T1> void printIt(T1 t1) { cout << t1 << " )" << endl; }
template <typename T1, typename... T2>
void printIt(T1 t1, T2... t2) { cout << t1 << " , "; printIt(t2...); }
#define mset(a, v) memset(a, v, sizeof(a))
#define popcount __builtin_popcountll

#define lim 300010
#define lim2 200010
// unordered_map<lld,lld>::iterator it; // Ab :)
// std::ios::sync_with_stdio(false);

lld A[lim], W[lim];
lld dp[103][lim];


int main(){
    lld n = sc();
    lld w = sc();
    rep(i,1,n) W[i] = sc(), A[i] = sc();
    lld mxVal = accumulate(A+1, A+n+1, 0LL);
    rep(j,1,mxVal) dp[0][j] = 1e18;
    rep(i,1,n) rep(j,1,mxVal) {
        dp[i][j] = dp[i-1][j];
        if(j - A[i] < 0) continue;
        dp[i][j] = min(dp[i][j], dp[i - 1][j - A[i]] + W[i]);
    }
    lld ans = 0;
    rep(i,1,mxVal) {
        if(dp[n][i] <= w) ans = i;
    }
    prL(ans);
    return 0;
}