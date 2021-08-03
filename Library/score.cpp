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
#include <fstream>
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

ll score(string,string) ;
const ll max_score = 1e15 ;

int main(){
    string s ;
    cout << "Do you check all cases?(y/n) :" ;
    cin >> s ;
    ifstream read ;
    if(s=="y"||s=="Y"||s=="yes"||s=="Yes"){
        // 欠番が発生するまで試す
        int ac=0,wa=0 ;
        ll sum = 0 ;
        for(int i=1;;i++){
            // in/outフォルダの名前をhogeフォルダに変更した場合は"hoge\\～"に変更する
            string in = "in\\"+to_string(i)+".txt" ;
            string out = "out\\"+to_string(i)+".txt" ;
            bool ok = true ;
            read.open(in)  ; ok &= read.good() ; read.close() ;
            read.open(out) ; ok &= read.good() ; read.close() ;
            if(ok){
                ll res = score(in,out) ;
                if(res<0){
                    wa++ ;
                }else{
                    ac++ ;
                    sum += res ;
                }
            }else{
                break ;
            }
        }
        cout << endl ;
        cout << ac+wa << " cases are checked." << endl ;
        cout << "AC       : " << ac << endl ;
        cout << "WA       : " << wa << endl ;
        cout << "Score    : " << sum << endl ;
        cout << "Score(%) : " << (ac?100.0*sum/ac/max_score:-1) << endl ;
    }else{
        int num,ac=0,wa=0 ;
        ll sum = 0 ;
        cout << "The number of cases you want to check : " ;
        cin >> num ;
        for(int i=1;i<=num;i++){
            // in/outフォルダの名前をhogeフォルダに変更した場合は"hoge\\～"に変更する
            string in = "in\\"+to_string(i)+".txt" ;
            string out = "out\\"+to_string(i)+".txt" ;
            ll res = score(in,out) ;
            cout << endl ;
            cout << "Case " << i << " : " << (res>=0?"AC":"WA") << endl ;
            cout << "   Score    : " << (res>=0?res:-1) << endl ;
            cout << "   Score(%) : " << 100.0*res/max_score << endl ;
            if(res<0) wa++ ;
            else{
                ac++ ;
                sum += res ;
            }
        }
        cout << endl ;
        cout << ac+wa << " cases are checked." << endl ;
        cout << "AC       : " << ac << endl ;
        cout << "WA       : " << wa << endl ;
        cout << "Score    : " << sum << endl ;
        cout << "Score(%) : " << (ac?100.0*sum/ac/max_score:-1) << endl ;
    }
}

ll score(string in,string out){
    ifstream input,output ;
    input.open(in) ; output.open(out) ;
    // 点数算出用のコードを書く
    // 形式を満たさない出力だった場合、負の値を返すことにする
    // 入力受け取りはcinじゃなくてinputを使う
    // ex) input >> hoge >> huga ;
    // 出力受け取りはcinじゃなくてoutputを使う
    // ex) output >> hoge >> huga ;
    ll res = 0 ;
    
    input.close() ; output.close() ;
    return res ;
}
