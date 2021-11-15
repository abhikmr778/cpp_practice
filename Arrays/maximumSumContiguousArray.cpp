#include <iostream>
using namespace std;


int main(){
    int n = 14;
    int arr[] = {74, -72, 94, -53, -59, -3, -66, 36, -13, 22, 73, 15, -52, 75};
    int sum = arr[0];
    int max = arr[0];
    if(sum>max) max = sum;
    if(sum<0) sum = 0;
    
    for(int i=1;i<n;i++){
        sum += arr[i];
        if(sum>max) max = sum;
        if(sum<0) sum = 0;
    }
    cout<<max;

    return 0;
}