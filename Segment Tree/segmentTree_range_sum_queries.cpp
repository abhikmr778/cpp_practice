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
    // otherwise split into two range
    // at every call we will have a length of 2^n, 
    // suppose 8: _, _, _, x, _, _, _, _
    // here x will be what we will get as middle
    int last_in_left = (node_low+node_high)/2;
    return querysum(2*node, node_low, last_in_left, query_low, query_high)
            + querysum(2*node+1, last_in_left+1, node_high, query_low, query_high);
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
    // bottom-up manner
    // assume 8 nodes given, it will always become a power of two
    // leaf nodes would be in second half of tree, from 8 to 16
    for(int i=0; i<N; i++){
        tree[N+i] = a[i];
    }
    // go from 7 to 1, using 2*i and 2*i+1
    for(int i=N-1; i>=1; i--){
        tree[i] = tree[2*i] + tree[2*i+1];
    }



    // queries
    for(int q=0; q<Q; q++){
        int low, high;
        cin>>low>>high; // inputs are in 1 base
        // change to 0 base
        low--;
        high--;
        cout<<querysum(1, 0, N-1, low, high)<<endl;
    }
    return 0;
}