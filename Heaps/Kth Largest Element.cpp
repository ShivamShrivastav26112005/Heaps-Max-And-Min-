// Q-> Find the kth largest ele. in a given array. 


#include<iostream>
#include<queue> // header file to include the priority queue
using namespace std;

int main(){
    int arr[]={41,4,55,9,94,3};
    int k=3; // 3rd largest ele.
    int n=sizeof(arr)/sizeof(arr[0]);

    // we use min heap to find the largest ele in the array 
    priority_queue<int, vector<int> , greater<int>> pq;
    for(int i=0; i<n; i++){
        pq.push(arr[i]);
        if(pq.size()>k) pq.pop();
    }
    cout<<pq.top();
}

// o/p-> 41 
