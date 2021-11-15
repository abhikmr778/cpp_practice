#include <iostream>
#include <vector>
using namespace std;

int main() {
	// your code goes here
	int t;
	cin>>t;
	for(int i=0;i<t;i++){
	    int n,m,k;
	    cin>>n>>m>>k;
	    vector<vector<char>> grid(n,vector<char>(m,'0'));
	    // for(int i=0;i<n*m;i++){
	    //     int x,y;
	    //     cin>>x>>y;
	    //     if(i%2==0){
	    //         grid[x-1][y-1]='A';
	    //     }
	    //     else{
	    //         grid[x-1][y-1]='B';
	    //     }
	    // }
	    for(int i=0;i<n;i++){
	        for(int j=0;j<m;j++){
	            cout<<grid[i][j]<<" ";
	        }
	        cout<<endl;
	    }
	    // for(int j=0;j<n-k;j++){
	    //     for(int l=0;l<m-k;l++){
	    //         int flag=0,countA=0,countB=0;
	    //         if(grid[j][l]=='B') flag=1;
	    //         for(int q=j;q<j+k;q++){
	    //             for(int r=l;r<l+k;r++){
	    //                 if(!flag){//ie A
	    //                     if(grid[q][r]!='A') break;
	    //                     else countA++;
	    //                 }
	    //                 else{
	    //                     if(grid[q][r]!='B') break;
	    //                     else countB++;
	    //                 }
	    //             }
	    //         }
	    //         if(!flag && countA==k*k){
	    //             cout<<"Alice";
        //             break;
	    //         }
	    //         else if(flag && countB==k*k){
	    //             cout<<"Bob";
        //             break;
	    //         }
	    //     }
	    // }
        // cout<<"Draw";
	}
	return 0;
}