// Q-: Minimum cost to connect all ropes.
 
#include<iostream>
#include<queue>
using namespace std;
int main(){

    int arr[]={2,7,4,1,8};
    int n=sizeof(arr)/sizeof(arr[0]);
    int mincost=0;

    // minheap
    priority_queue<int, vector<int>, greater<int> > pq;
    for(int ele : arr){
        pq.push(ele);
    }

    while(pq.size()>1){
        int x=pq.top(); // 1st min ele.
        pq.pop();
        int y=pq.top(); // 2nd min ele.
        pq.pop();

        pq.push(x+y);
        mincost += (x+y);
    }
    cout<<mincost;

} 
