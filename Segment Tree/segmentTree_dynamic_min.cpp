#include <bits/stdc++.h>
using namespace std;
vector<int> tree;

int querymin(int node_idx, int node_low, int node_high, int query_low, int query_high){
    if(query_low<=node_low && node_high<=query_high){
        return tree[node_idx];
    }
    if(node_high < query_low || query_high < node_low){
        return INT_MAX;
    }
    int last_on_left = (node_low + node_high)/2;
    return min(querymin(2*node_idx, node_low, last_on_left, query_low, query_high),
                querymin(2*node_idx+1, last_on_left+1, node_high, query_low, query_high));
}

void update(int i, int v, int n){
    tree[n+i] = v;
    int j = (n+i)/2;
    for(;j>=1; j/=2){
        tree[j] = min(tree[2*j], tree[2*j+1]);
    }
}

int main(){
    int n,q;
    cin>>n>>q;
    vector<int> a(n);
    for(int i=0; i<n; i++)
        cin>>a[i];
    // pad 0 in array to make it 2^x
    while(__builtin_popcount(n)!=1){
        a.push_back(0);
        n++;
    }

    // build the tree
    tree.resize(2*n);
    // array elements go into n to 2n-1
    for(int i=0; i<n; i++){
        tree[n+i] = a[i];
    }
    // rest can be built up
    for(int j=n-1; j>=1; j--){
        tree[j] = min(tree[2*j],tree[2*j+1]);
    }

    while(q--){
        int type;
        cin>>type;
        if(type==1){
            int i, val;
            cin>>i>>val;
            i--;
            update(i, val, n);
        }
        else{
            int low, high;
            cin>>low>>high;
            // change to base 0
            low--;
            high--;
            cout<<querymin(1, 0, n-1, low, high)<<endl;
        }
    }
    return 0;
}