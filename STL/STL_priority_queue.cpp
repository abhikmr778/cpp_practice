// first element is always greatest; its essentially a max heap

#include <iostream>
#include <queue>

using namespace std;

int main(){
    //max heap
    priority_queue<int> maxh;

    //min heap 
    priority_queue<int, vector<int>, greater<int>> minh;

    maxh.push(1);
    maxh.push(3);
    maxh.push(2);
    maxh.push(0);

    int size = maxh.size();
    for(int i=0;i<size;i++){
        cout<<maxh.top()<<" ";
        maxh.pop();
    }
    cout<<endl;

    minh.push(5);
    minh.push(1);
    minh.push(0);
    minh.push(4);
    minh.push(3);
    size = minh.size();
    for(int i=0;i<size;i++){
        cout<<minh.top()<<" ";
        minh.pop();
    }
    cout<<endl;
    return 0;
}