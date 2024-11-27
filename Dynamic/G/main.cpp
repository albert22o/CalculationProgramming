#include "bits/stdc++.h"

using std::cin, std::cout, std::endl, std::vector, std::reverse;

template<typename T> T min(const T &x, const T &y);

template<typename T> T max(const T &x, const T &y);

template<typename T> T* read_array(const size_t &n);

template <typename T> int CompareFunc(const void *elem1, const void *elem2);

template <typename T> int CompareFuncReverse(const void *elem1, const void *elem2);

const int inf = 0;

void dfs(vector<vector<int>> &graph, int v, vector<int> &visited, vector<int> &order)
{
    visited[v] = 1;
    for (auto i : graph[v])
    {
        if(!visited[i])
            dfs(graph, i, visited, order);
    }
    order.push_back(v);  
}

vector<int> topSort(vector<vector<int>> &graph)
{
    vector<int> visited(graph.size());
    vector<int> order;

    for (int v = 0; v < graph.size(); v++)
    {
        if(!visited[v])
            dfs(graph, v, visited, order);
    }
    
    reverse(order.begin(), order.end());

    // for (size_t i = 0; i < order.size(); i++)
    // {
    //     cout << order[i] << " ";
    // }
    // cout << endl;

    vector<int> dist(graph.size(), inf);
    dist[order[0]] = 0;

    for(int v : order)
        for(auto i : graph[v])
            if(dist[i] < dist[v] + 1)
                dist[i] = dist[v] + 1;
    return dist;
}

void _solve()
{
    size_t n, m;
    cin >> n >> m;
    vector<vector<int>> graph(n+1);
    for (size_t i = 0; i < m; ++i)
    {
        int a, b;
        cin >> a >> b;
        graph[a].push_back(b);
    }
    // for (size_t i = 0; i < n+1; ++i)
    // {
    //     for (size_t k = 0; k < graph[i].size(); k++)
    //     {
    //         cout << graph[i][k] << " ";
    //     }
    //     cout << endl;
    // }

    vector<int> dist = topSort(graph);

    int max = inf;
    for (int d : dist)
        if(max < d)
            max = d;
    if(max > 0)
        cout << max << endl;
    else
        cout << 0 << endl;

    // for (int d : dist)
    //     cout << d << " ";
    
}
 
int main()
{
    // std::ios::sync_with_stdio(false);
    // std::cin.tie(nullptr);
    // std::cout.tie(nullptr);
 
    std::freopen("longpath.in", "r", stdin);
    std::freopen("longpath.out", "w", stdout);
    // int t;
    // cin >> t;
    // for (size_t i = 0; i < t; ++i)
    // {
    //     _solve();
    // }
    _solve();
    
    return 0;
}

template<typename T> T* read_array(const size_t &n)
{
    T* array = new T[n];
    for (size_t i = 0; i < n; ++i)
        cin >> array[i];
        
    return array;
}

template<typename T> T min(const T &x, const T &y)
{
    if(x < y)
        return x;
    else
        return y;
}

template<typename T> T max(const T &x, const T &y)
{
    if(x > y)
        return x;
    else
        return y;
}

template <typename T> int CompareFunc(const void *elem1, const void *elem2)
{
 if ( *(T*)elem1 == *(T*)elem2 ) return 0;
 return ( *(T*)elem1 > *(T*)elem2 ) ? 1 : -1;
}

template <typename T> int CompareFuncReverse(const void *elem1, const void *elem2)
{
 if ( *(T*)elem1 == *(T*)elem2 ) return 0;
 return ( *(T*)elem1 < *(T*)elem2 ) ? 1 : -1;
}