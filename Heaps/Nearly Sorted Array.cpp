// Q-: Sort a 'k' sortedd array (sort a nearly sorted array). 


// here we use **minheap** 

#include<iostream>
#include<queue>
#include<vector>
using namespace std;
int main(){

    int arr[]={6,5,3,2,8,9,10};
    int n=sizeof(arr)/sizeof(arr[0]);
    int k=3;

    vector<int>ans; // we make a empty vector ans where we push our sorted array 
    priority_queue<int,vector<int>,greater<int>> pq; // minheap 
    
    // T.C. = n*logk, S.C.= O(n), push and pop -> T.C.= logk 
    // In this time S.C.= O(n) becoz we take an extra space (ans vector) but we can also change our array 
    // therefore, no extra space can be taken 

    for(int i=0; i<n; i++){ // n 
        pq.push(arr[i]);
        if(pq.size()>k){    // logk 
            ans.push_back(pq.top());
            pq.pop();
        }
    }

    // only k ele.s are sorted 
    for(int i=0; i<n; i++){
        cout<<ans[i]<<" ";
    }
    cout<<endl;

    // this loop is for except ele. which is present inside the minheap 
    while(pq.size()>0){ 
        ans.push_back(pq.top()); 
        pq.pop();
    }

    // all ele.s are sorted 
    for(int i=0; i<n; i++){
        cout<<ans[i]<<" ";
    }

} 

// Output->
// 2 3 5 6 6512997 0 2124256005 
// 2 3 5 6 8 9 10







// New Method -> we use our array itself not ues extra vecor ans or extra space 
// S.C. = O(k) no extra space can be taken. 

#include<iostream>
#include<queue>
#include<vector>
using namespace std;
int main(){
    int arr[]={6,5,3,2,8,9,10};
    int k=3;
    int n=sizeof(arr)/sizeof(arr[0]);

    for(int i=0; i<n; i++){
        cout<<arr[i]<<" ";
    }
    cout<<endl;

    // extra space or extra ans vector is not reqired 
    // vector<int>ans; 

    priority_queue<int,vector<int>,greater<int>> pq; // minheap 
    int idx=0; // by using indexing we reduce extra space and we use our array itself  

    // T.C. = n*logk, S.C.= O(k)
    for(int i=0; i<n; i++){ 
        pq.push(arr[i]);
        if(pq.size()>k){

            // arr[idx++]=pq.top();
            //        Or 
            arr[idx]=pq.top();
            idx++;
            pq.pop();

        }
    }

    // except ele.s present inside the minheap 
    while(pq.size()>0){ 
            arr[idx++]=pq.top();
            pq.pop();
    }

    for(int i=0; i<n; i++){
        cout<<arr[i]<<" ";
    }
}

// Output-> 
// 6 5 3 2 8 9 10 
// 2 3 5 6 8 9 10 

