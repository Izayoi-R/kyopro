template<class T>
class SGT{
    public :
    int n ;
    vector<T> num ;
    function<T(T,T)> f ;
    T d ;
 
    // コンストラクタ：サイズ、関数、単位元を指定
    SGT(size_t n_,function<T(T,T)> f_,T d_) : f(f_),d(d_){
        n = 1 ;
        while(n<n_) n *= 2 ;
        num = vector<T>(2*n-1,d) ;
    }
 
    // sz個のaで前から初期化
    void init(int sz,T a){
        for(int i=0;i<sz;i++) num[i+n-1] = a ;
        for(int i=n-2;i>=0;i--) num[i] = f(num[i*2+1],num[i*2+1]) ;
    }
 
    // 配列aで前から初期化
    void init(vector<T> &a){
        for(int i=0;i<a.size();i++) num[i+n-1] = a[i] ;
        for(int i=n-2;i>=0;i--) num[i] = f(num[i*2+1],num[i*2+2]) ;
    }
 
    // 0-indexedでp番目をaで上書き
    void update(int p,T a){
        p += n-1 ;
        num[p] = a ;
        while(p){
            p = (p-1)/2 ;
            num[p] = f(num[p*2+1],num[p*2+2]) ;
        }
    }
 
    // 0-indexedでp番目にaを加算
    void add(int p,T a){
        p += n-1 ;
        num[p] += a ;
        while(p){
            p = (p-1)/2 ;
            num[p] = f(num[p*2+1],num[p*2+2]) ;
        }        
    }
    
    T query(int a,int b,int cur=0,int l=0,int r=-1){
        if(r<0) r = n ;
        if(r<=a||b<=l) return d ;
        if(a<=l&&r<=b) return num[cur] ;
        T r1 = query(a,b,cur*2+1,l,(l+r)/2) ;
        T r2 = query(a,b,cur*2+2,(l+r)/2,r) ;
        return f(r1,r2) ;
    }
 
    T operator[](int p){
        return num[p+n-1] ;
    }
 
    int bsr(int a,int b,T x,function<bool(T,T)> check,int l=0,int r=-1,int cur=0){
        if(r<0) r = n ;
        cout << l << " " << r << " " << cur << endl ;
        if(!check(num[cur],x)||r<=a||b<=l) return a-1 ;
        if(cur>=n-1) return cur-(n-1) ;
        int right = bsr(a,b,x,check,(l+r)/2,r,cur*2+2) ;
        if(right==a-1){
            return bsr(a,b,x,check,l,(l+r)/2,cur*2+1) ;
        }else{
            return right ;
        }
    }
 
    int bsl(int a,int b,T x,function<bool(T,T)> check,int l=0,int r=-1,int cur=0){
        if(r<0) r = n ;
        if(!check(num[cur],x)||r<=a||b<=l) return b ;
        if(cur>=n-1) return cur-(n-1) ;
        int left = bsl(a,b,x,check,l,(l+r)/2,cur*2+1) ;
        if(left==b){
            return bsl(a,b,x,check,(l+r)/2,r,cur*2+2) ;
        }else{
            return left ;
        }
    }
} ;