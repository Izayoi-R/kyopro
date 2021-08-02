template<class T>
class LSGT{
    public :
    int n ;
    V<T> num ;
    V<T> lazy ;
    V<int> len ;
    function<T(T,T,T)> fx ; // num->num
    function<T(T,T)> fm ; // lazy->lazy
    function<T(T,T,int)> fa ; // lazy->num
    function<T(T,int)> fp ;
    T d1,d2 ;
 
    LSGT(int n_,function<T(T,T,T)> fx_,T d1_):fx(fx_),d1(d1_){
        n = 1 ;
        while(n<n_) n <<= 1 ;
        num.resize(2*n-1,d1) ;
        len.resize(2*n-1) ;
        int tmp = 1 ;
        for(int i=0;i<2*n-1;i++){
            if(tmp*2-1==i) tmp *= 2 ;
            len[i] = n/tmp ;
        }
    }
 
    void init(V<T> &a){
        int sz = a.size() ;
        for(int i=0;i<sz;i++) num[i+n-1] = a[i] ;
        for(int i=n-2;i>=0;i--) num[i] = fx(num[i*2+1],num[i*2+2],len[i]) ;
    }
 
    void init(int sz,T a){
        for(int i=0;i<sz;i++) num[i+n-1] = a ;
        for(int i=n-2;i>=0;i--) num[i] = fx(num[i*2+1],num[i*2+2],len[i]) ;
    }
 
    void set_fm(function<T(T,T)> fm_,T d2_){
        fm = fm_ ;
        d2 = d2_ ;
        lazy.resize(2*n-1,d2) ;
    }
 
    void set_fa(function<T(T,T,int)> fa_){
        fa = fa_ ;
    }
 
    void set_fp(function<T(T,int)> fp_){
        fp = fp_ ;
    }
 
    void eval(int k){
        if(lazy[k]!=d2){
            num[k] = fa(num[k],fp(lazy[k],len[k]),len[k]) ;
            if(len[k]>1){
                lazy[k*2+1] = fm(lazy[k*2+1],lazy[k]) ;
                lazy[k*2+2] = fm(lazy[k*2+2],lazy[k]) ;
            }
            lazy[k] = d2 ;
        }
    }
 
    void update(int a,int b,T x,int k=0,int l=0,int r=-1){
        if(r<0) r = n ;
        eval(k) ;
        if(b<=l||r<=a) return ;
        if(a<=l&&r<=b){
            lazy[k] = fm(lazy[k],x) ;
            eval(k) ;
        }else{
            update(a,b,x,k*2+1,l,(l+r)/2) ;
            update(a,b,x,k*2+2,(l+r)/2,r) ;
            num[k] = fx(num[k*2+1],num[k*2+2],len[k]) ;
        }
    }
 
    T query(int a,int b,int k=0,int l=0,int r=-1){
        if(r<0) r = n ;
        eval(k) ;
        if(r<=a||b<=l) return d1 ;
        if(a<=l&&r<=b) return num[k] ;
        T r1 = query(a,b,k*2+1,l,(l+r)/2) ;
        T r2 = query(a,b,k*2+2,(l+r)/2,r) ;
        return fx(r1,r2,len[k]) ;
    }
 
    T at(int i){
        return num[i+n-1] ;
    }
} ;