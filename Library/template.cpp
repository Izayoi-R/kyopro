#include <iostream>
#include <iomanip>
#include <string>
#include <vector>
#include <algorithm>
#include <utility>
#include <functional>
#include <set>
#include <stack>
#include <map>
#include <queue>
#include <deque>
#include <bitset>
#include <math.h>
#include <random>
#include <chrono>
#include <assert.h>
using namespace std ;
using ll = long long ;
using ld = long double ;
template<class T> using V = vector<T> ;
template<class T> using VV = V<V<T>> ;
using pll = pair<ll,ll> ;
#define all(v) v.begin(),v.end()
const ll mod = 1000000007 ;
// const ll mod = 998244353 ;
long double pie = acos(-1) ;
const ll INF = 1e18 ;

void yorn(bool a){if(a) cout << "Yes" << endl ; else cout << "No" << endl ;}
//void YorN(bool a){if(a) cout << "YES" << endl ; else cout << "NO" << endl ;}
ll gcd(long long a,long long b){if(b==0) return a ; return gcd(b,a%b) ;}
ll lcm(long long a,long long b){return a/gcd(a,b)*b ;}
ll extGCD(ll a,ll b,ll &x,ll &y){
    if(b==0){
        x = 1 ;
        y = 0 ;
        return a ;
    }
    ll d = extGCD(b,a%b,y,x) ;
    y -= a/b*x ;
    return d ;
}
void fix_cout(){cout << fixed << setprecision(20) ;}
template<class T> void chmax(T &a,T b){if(a<b) a = b ;}
template<class T> void chmin(T &a,T b){if(a>b) a = b ;}

int main(){
}