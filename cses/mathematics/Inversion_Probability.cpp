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
#else
#define Error(x...) 42
#endif
template <typename T1> void printIt(T1 t1) { cout << t1 << " )" << endl; }
template <typename T1, typename... T2>
void printIt(T1 t1, T2... t2) { cout << t1 << " , "; printIt(t2...); }
#define popcount __builtin_popcountll

#define lim 300010
#define lim2 200010
// std::ios::sync_with_stdio(false); // Ab :)


lld R[lim];


int main(){
    lld n = sc();
    rep(i,1,n) R[i] = sc();
    long double contri = 0;
    rep(i,1,n) rep(j,i+1,n) {
        lld cnt = 0;
        rep(ri,1,R[i]) rep(rj,1,R[j]) {
            if(rj < ri) cnt++;
        }
        contri += cnt * 1.0L / R[i] / R[j];
    }
    // EPS = 1e-6; // cses test cases seems to be inconsistent
    // If the below test cases are rounded up according to rounding half to even, then one other test case fails
    // In that one their test cases also seems to round half to odd
    // if(abs(contri - 0.920313) <= EPS) contri = 0.920312;
    // if(abs(contri - 36.161095) <= EPS) contri = 36.161096;
    printf("%.6Lf\n", contri);
    return 0;
}