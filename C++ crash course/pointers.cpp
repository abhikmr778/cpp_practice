#include<iostream>
#include<cstdlib>
using namespace std;
int main()
{
    int *ptr;
    ptr = (int*) malloc(5*sizeof(int));

    if(!ptr){
        cout << "Memory Allocation Failed";
        return 0;
    }
    // Initialize values
    for (int i=0; i<5; i++){
        ptr[i] = i+i;
    }

    // Initialized values"
    for (int i=0; i<5; i++){
        /* ptr[i] and *(ptr+i) can be used interchangeably */
        cout << *(ptr+i) << " ";
    }
    cout<<endl;
    // output: 0 2 4 6 8

    free(ptr);
    // If we again prints the value it will print some garbage value
     
    for (int i=0; i<5; i++){
        cout << *(ptr+i) << " ";
    }
    // This will not give any error but prints some garbage value
    return 0;
}