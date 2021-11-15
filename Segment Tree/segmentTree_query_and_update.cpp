#include <bits/stdc++.h>

using namespace std;

vector<long long> tree;

long long querysum(int node, int node_low, int node_high, int query_low, int query_high){
    // if current range lies completely within query range then return node value
    if(query_low<=node_low && node_high<=query_high){
        return tree[node];
    }
    // if current range is disjoint with query range then return 0
    if(node_high<query_low || query_high<node_low){
        return 0;
    }
    int last_in_left = (node_low+node_high)/2;
    return querysum(2*node, node_low, last_in_left, query_low, query_high)
            + querysum(2*node+1, last_in_left+1, node_high, query_low, query_high);
}

// recursive update
void change(int node, int node_low, int node_high, int query_low, int query_high, int val){
    if(query_low<=node_low && node_high<=query_high){// only true if we reach node we have to change
        tree[node] = val;
        return;
    }
    if(node_high<query_low || query_high <node_low){
        return;
    }
    // take two actions to modify left/right children and then modify curr value during a callback
    int last_in_left = (node_low+node_high)/2;
    change(2*node, node_low, last_in_left, query_low, query_high, val);
    change(2*node+1, last_in_left+1, node_high, query_low, query_high, val);
    tree[node] = tree[2*node] + tree[2*node+1];
}
// iterative update method
void update(int i, int v, int N){ // change position i to value v
    // ith node of array would be at position N+i in tree
    tree[N+i] = v;
    // update parents of N+i
    // to get parent of jth node just divide by 2 ie parent_j = j/2
    // works for both odd and even child
    for(int j = (N+i)/2; j>=1; j/=2){
        tree[j] = tree[2*j] + tree[2*j+1];
    }
}


int main(){
    // input is size of array, no of query and then array and queries
    int N;
    cin>>N;
    int Q;
    cin>>Q;
    vector<int> a(N);
    for(int i=0;i<N; i++){
        cin>>a[i];
    }
    // while n is not a power of two keep adding zeros
    while(__builtin_popcount(N)!=1){
        // counts number of 1 in binary repr
        a.push_back(0);
        N++;
    }
    // need to build a tree
    tree.resize(2*N);
    for(int i=0; i<N; i++){
        tree[N+i] = a[i];
    }
    for(int i=N-1; i>=1; i--){
        tree[i] = tree[2*i] + tree[2*i+1];
    }

    // queries
    for(int q=0; q<Q; q++){
        int type;
        cin>>type;
        if(type==1){
            int i, v;
            cin>>i>>v;
            i--;
            // update(i,v,N);
            change(1, 0, N-1, i,i,v);
        }else{
            int low, high;
            cin>>low>>high; // inputs are in 1 base
            // change to 0 base
            low--;
            high--;
            cout<<querysum(1, 0, N-1, low, high)<<endl;

        }
    }
    return 0;
}