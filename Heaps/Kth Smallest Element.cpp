// Q-> Find the kth smallest ele. in a given array. 

#include<iostream>
#include<queue>
using namespace std;
int main(){
    int arr[]={3,1,-76,40,38,50,5,30,66}; 
    int k=2; // 2th smallest ele. we want
    int n=sizeof(arr)/4; // find array size 

    priority_queue<int> pq; // maxheap(by default)
    for(int i=0; i<n; i++){ // traverse in the array and push ele. in the maxheap
        pq.push(arr[i]);
        if(pq.size()>k) pq.pop(); // topmost ele. -> ko delete kar diye
    }
  
    cout<<pq.top(); // our kth smallest ele.

} 

//O/P-: 1

// Leetcode -: 215 kth largest ele. 
