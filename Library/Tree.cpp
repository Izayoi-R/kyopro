class Tree{
    public :
    int node ; // 頂点数
    int edge ; // 辺の数
    bool directed ; // 有向辺かどうか
    vector<vector<pair<int,ll>>> edges ; // 隣接リスト
    vector<vector<ll>> distance ; // 各頂点からの距離、基本は空リスト
    vector<bool> checked ; // 各頂点からの距離を求めたかどうか
    vector<bool> checked_par ; // 各頂点を根に親配列を作ったかどうか
    vector<vector<int>> parents ;
    vector<int> depth ;

    Tree(int n,string s="undirected"):node(n),edge(n-1),directed(!(s=="undirected")){
        edges = vector<vector<pair<int,ll>>>(n) ;
        checked.resize(n,false) ;
        checked_par.resize(n,false) ;
        distance.resize(n,vector<ll>(0)) ;
        parents.resize(30,vector<int>(n,-1)) ;
    }

    void add_edge(int u,int v,ll cost){
        edges[u].emplace_back(v,cost) ;
        if(!directed) edges[v].emplace_back(u,cost) ;
    }

    void Distance(int from){
        if(checked[from]) return ;
        distance[from].resize(node,INF) ;
        queue<int> q ;
        q.push(0) ;
        distance[from][from] = 0 ;
        while(!q.empty()){
            int p = q.front() ;
            q.pop() ;
            for(auto [nx,cost]:edges[p]){
                if(distance[from][nx]==INF){
                    distance[from][nx] = distance[from][p]+cost ;
                    q.push(nx) ;
                }
            }
        }
        checked[from] = true ;
        return ;
    }

    // 木の直径を求める関数を書く

    // 木の重心を求める関数を書く

    // 親の記録した配列を返す関数(ダブリングの用意もする)
    void Parent(int from=0){
        if(checked_par[from]) return ;
        checked_par[from] = true ;
        parents.resize(30,vector<int>(node,-1)) ;
        depth.resize(node,0) ;
        queue<int> q ;
        q.push(from) ;
        while(!q.empty()){
            int p = q.front() ;
            q.pop() ;
            for(auto [nx,cost]:edges[p]){
                if(nx!=from&&parents[0][nx]==-1){
                    parents[0][nx] = p ;
                    depth[nx] = depth[p]+1 ;
                    q.push(nx) ;
                }
            }
        }
        for(int i=1;i<parents.size();i++){
            for(int j=0;j<node;j++){
                if(parents[i-1][j]==-1) parents[i][j] = -1 ;
                else parents[i][j] = parents[i-1][parents[i-1][j]] ;
            }
        }
        return ;
    }

    // 最小共通祖先を求める関数
    int LCA(int a,int b,int root=0){
        Parent(root) ;
        if(depth[a]>depth[b]) swap(a,b) ;
        int d = depth[b]-depth[a] ;
        for(int i=0;i<parents.size();i++) if((d>>i)&1) b = parents[i][b] ;
        if(a==b) return a ;
        for(int i=parents.size()-1;i>=0;i--){
            if(parents[i][a]!=parents[i][b]){
                a = parents[i][a] ;
                b = parents[i][b] ;
            }
        }
        a = parents[0][a] ;
        return a ;
    }

    // LCAを使って2頂点間の距離を求める関数
    ll Distance(int a,int b,int root=0){
        Distance(root) ;
        return distance[root][a]+distance[root][b]-2*distance[root][LCA(a,b,root)] ;
    }

    // 木DPをする関数を書く（部分木のサイズ取得もこれ）

    // 全方位木DPをする関数を書く
} ;