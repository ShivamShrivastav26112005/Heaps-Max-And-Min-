// 1584. Minimum Cost to Connect All Points / Ropes. 
 
#include<iostream>
#include<queue>
using namespace std;

int main(){
    int arr[]={2,7,4,1,8};
    int n=sizeof(arr)/sizeof(arr[0]);
    int mincost=0;

    // minheap
    priority_queue<int, vector<int>, greater<int> > pq;
    // insert/push all the ele.s in the minheap by using for each loop 
    for(int ele : arr){
        pq.push(ele);
    }

    // Take 2 minimum ropes from the heap and add this then again push into the minheap 
    while(pq.size()>1){ // becoz at the end we have to return min cost which is integer (only one no).
        int x=pq.top(); // 1st min ele.
        pq.pop();
        int y=pq.top(); // 2nd min ele.
        pq.pop();

        // add this 2 min ele. and again push into the minheap 
        pq.push(x+y);
        mincost += (x+y);
    }
    cout<<mincost;

} 
