#include<iostream>
#include<queue> // we include the header file to use the STL of priority queue 
using namespace std;
int main(){
    // max heap -: 
    // priority_queue<int> pq_name-: it is used to include the stl of PQ.
    // like a stack<int> st;
    priority_queue<int> pq;
    pq.push(10);
    pq.push(25);
    pq.push(-6);
    pq.push(81);
    cout<<pq.top()<<endl; // 81
    pq.pop(); // 81 is removed 
    cout<<pq.top()<<endl; // 25



    // // min heap -: we include this
    priority_queue<int, vector<int> , greater<int>> pq;
    pq.push(10); // at the top present 10 
    pq.push(25); // 10 
    pq.push(-6); // -6
    pq.push(81); // -6 present at the top
    cout<<pq.top()<<endl; // -6
    pq.pop(); // -6 is removed 
    cout<<pq.top()<<endl; // 10


    // // min heap -:
    priority_queue<float, vector<float> , greater<float>> pq;
    pq.push(10.3); // at the top present 10.3
    pq.push(23.5); // 10.3
    pq.push(-6.6); // -6.6
    pq.push(0); // -6.6 present at the top
    cout<<pq.top()<<endl; // -6.6
    pq.pop(); // -6.6 is removed 
    cout<<pq.top()<<endl; // 0 


}

// O/P -: 
// -6.6
// 0