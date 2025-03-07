// USED TO FIND MINIMUM SPANNING TREE (MST)
#include<bits/stdc++.h>
using namespace std;
class DisjointSet{
    vector<int>parent,size;
    public:
    DisjointSet(int n){
        parent.resize(n+1,0);
        size.resize(n+1,0);
        for(int i=0;i<n;i++){
            parent[i]=i;
            size[i]=1;
        }
    }

    int findUPar(int node){
        if(node==parent[node]){
            return node;
        }
        return parent[node]=findUPar(parent[node]);  // Path compression
    }

    void unionBySize(int u, int v){
        int ulp_u=findUPar(u);
        int ulp_v=findUPar(v);
        if(ulp_u==ulp_v){
            return;
        }
        if(size[ulp_u]<size[ulp_v]){
            parent[ulp_u]=ulp_v;
            size[ulp_v]+=size[ulp_u];
        }
        else{
            parent[ulp_v]=ulp_u;
            size[ulp_u]+=size[ulp_v];
        }
    }
};
int main(){
DisjointSet ds(7);  // no. of nodes

ds.unionBySize(1,2);
ds.unionBySize(2,3);
ds.unionBySize(4,5);
ds.unionBySize(6,7);
ds.unionBySize(5,6);

// if 3,7 belong to same component ot not

if(ds.findUPar(3)==ds.findUPar(7)){
    cout<<"same"<<endl;
}
else{
    cout<<"not same"<<endl;
}

ds.unionBySize(3,7);

if(ds.findUPar(3)==ds.findUPar(7)){
    cout<<"same"<<endl;
}
else{
    cout<<"not same"<<endl;
}

return 0;

}