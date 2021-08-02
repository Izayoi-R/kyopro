class UFT{
public :
	vector<int> par ;
	vector<int> rank ;
	vector<int> sz ;
	vector<bool> root ;
	int graph ;
	int tree ;
 
	void init(int n){
        par.resize(n) ;
        rank.resize(n) ;
        sz.resize(n) ;
        root.resize(n) ;
		for(int i=0;i<n;i++){
			par[i] = i ;
			rank[i] = 0 ;
			sz[i] = 1 ;
			root[i] = true ;
		}
		tree = n ;
		graph = n ;
	}
 
	int find(int x){
		if(par[x]==x) return x ;
		return par[x] = find(par[x]) ;
	}
 
	void unite(int x,int y){
		x = find(x) ;
		y = find(y) ;
		if(x==y){
			if(root[x]){
				root[x] = false ;
				tree-- ;
			}
			return ;
		}
		if(rank[x]<rank[y]){
			par[x] = y ;
			sz[y] += sz[x] ;
			graph-- ;
			if(root[x]){
				root[x] = false ;
				tree-- ;
			}
		}else{
			par[y] = x ;
			sz[x] += sz[y] ;
			if(rank[x]==rank[y]) rank[x]++ ;
			graph-- ;
			if(root[y]){
				root[y] = false ;
				tree-- ;
			}
		}
	}
 
	bool same(int x,int y){
		return find(x)==find(y) ;
	}

    int size(int x){
        return sz[find(x)] ;
    }
};