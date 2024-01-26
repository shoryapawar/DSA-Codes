#include <bits/stdc++.h>
using namespace std;

// class of disjoint set DSU and DSS
class DisjointSet
{
    vector<int> rank,parent,size;
public:
    DisjointSet(int n) {  // constructor
        rank.resize(n + 1, 0);
        parent.resize(n + 1);
        size.resize(n + 1);
        for (int i = 0; i <= n; i++) {
            parent[i] = i; // assigning each parent to itself
            size[i] =1; // assignall size by one
        }
    }

    // find ultimate parent 
    int findUPar(int node){
        if(node==parent[node]){
            return node;
        }
        return parent[node] = findUPar(parent[node]);
    }

    // Union By Rank 
    void unionByRank(int u , int v){
        int par_v = findUPar(v);
        int par_u = findUPar(u);
        
        if(par_u==par_v) return;
        if(rank[par_u] <rank[par_v]){ // if rank of parent of u < rank of parent of v
            parent[par_u] = par_v;  // then parent of u = v;
        }
        else if(rank[par_u]>rank[par_v]){  // if rank of parent of u > rank of parent of v
            parent[par_v] = par_u;  // then parent of v = u;

        }
        else {// if none then add u in v so v becomes parent of u 
            parent[par_u] = par_v;  
            rank[par_v]++; // increase rank of v by 1
        }

    }

    // Union By Size
    void unionBySize(int u , int v){
        int par_v = findUPar(v);
        int par_u = findUPar(u);
        if(par_u==par_v) return ;

        if(size[par_u]<size[par_v]){ // if size of parent of u < size of parent of v
            size[par_v]+=size[par_u]; // increase size of v by ading size of u in it
            parent[par_u]= par_v; // update parent
        }
        else{// size[u] > size[v] OR size[u]==size[v]  
            size[par_u] += size[par_v]; // increase size of parent of u by parent of v;
            parent[par_v] = par_u; // update parent
        }

    }
    
};// class 

int main(){

     DisjointSet ds(7);
    // Union BY Rank 
    // ds.unionByRank(1, 2);
    // ds.unionByRank(2, 3);
    // ds.unionByRank(4, 5);
    // ds.unionByRank(6, 7);
    // ds.unionByRank(5, 6);


    // Union BY SIZE 
    ds.unionBySize(1, 2);
    ds.unionBySize(2, 3);
    ds.unionBySize(4, 5);
    ds.unionBySize(6, 7);
    ds.unionBySize(5, 6);

    // if 3 and 7 same or not
    if (ds.findUPar(3) == ds.findUPar(7)) {
        cout << "Same\n";
    }
    else cout << "Not same\n";

    ds.unionBySize(3, 7);

    if (ds.findUPar(3) == ds.findUPar(7)) {
        cout << "Same\n";
    }
    else cout << "Not same\n";

    return 0;
}
