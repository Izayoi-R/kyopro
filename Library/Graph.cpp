class Graph{
    public :
    int node ; // 頂点数
    int edge ; // 辺の数
    bool directed ; // trueなら有向辺,falseなら無向辺
    bool is_bipartite ; // 二部グラフかどうか
    vector<vector<pair<int,ll>>> edges ; // 隣接リスト
    vector<vector<ll>> distance ; // 各頂点からの距離,求めるまでは空リスト
    vector<bool> checked ; // 各頂点からの距離を求めたかどうか
    vector<int> bipartite ; // 二部グラフの塗り分け

    Graph(int n,int m,string s="undirected") : node(n),edge(m),directed(s!="undirected"){
        edges = vector<vector<pair<int,ll>>>(node) ;
        distance = vector<vector<ll>>(node) ;
        checked.resize(node,false) ;
        is_bipartite = true ;
    }

    void add_edge(int u,int v,ll cost){
        edges[u].emplace_back(v,cost) ;
        if(!directed) edges[v].emplace_back(u,cost) ;
    }

    void Dijkstra(int from){
        if(checked[from]) return ;
        distance[from].resize(node,INF) ;
        vector<bool> used(node,false) ;
        priority_queue<pair<ll,int>,V<pair<ll,int>>,greater<pair<ll,int>>> pq ;
        pq.emplace(0,from) ;
        distance[from][from] = 0 ;
        while(!pq.empty()){
            int p = pq.top().second ;
            ll d = pq.top().first ;
            pq.pop() ;
            if(used[p]) continue ;
            used[p] = true ;
            for(auto [nx,cost]:edges[p]){
                if(d+cost<distance[from][nx]){
                    distance[from][nx] = d+cost ;
                    pq.emplace(d+cost,nx) ;
                }
            }
        }
        for(auto &i:distance[from]) if(i==INF) i = -1 ;
        checked[from] = true ;
        return ;
    }

    bool Bipartite(){
        if(bipartite.size()==node) return is_bipartite ;
        bipartite.resize(node,-1) ;
        bipartite[0] = 0 ;
        queue<int> q ;
        q.push(0) ;
        while(!q.empty()){
            int p = q.front() ;
            q.pop() ;
            int cur = bipartite[p] ;
            for(auto [nx,cost]:edges[p]){
                if(bipartite[nx]==bipartite[p]) is_bipartite = false ;
                if(bipartite[nx]==-1){
                    bipartite[nx] = cur^1 ;
                    q.push(nx) ;
                }
            }
        }
        return is_bipartite ;
    }
} ;