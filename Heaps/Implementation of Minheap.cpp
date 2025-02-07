// Implementation of minheap by using array and visulise the minheap by using complete binary tree (CBT)
// Minheap is implemented through array.
// Parent should be greater than child in case of maxheap and Parent is lesser than child in case of minheap.

#include<iostream>
using namespace std;
class Minheap{
    public:
    int arr[50];
    int idx;
    // constructor 
    Minheap(){
        idx=1;
    }

    // top of the ele. of the minheap 
    int top(){
        return arr[1];
    }

    void push(int x){
        arr[idx]=x;
        int i=idx;
        idx++;

        // swapping of i with parent till i==1 (1 is idx)
        // visualise like a CBT means that we are doing swapping(min ele. goes to their right position or goes to parent node
        // which is min and both the left and right child of parent is greater ) till i goes to 1st index of CBT.

        while(i!=1){
            int parent=i/2;
            // when we are going to swapping 
            if(arr[i]<arr[parent])
            swap(arr[i],arr[parent]);
            // not swapping if ele which we push in the arr or CBT is greater than parent 
            else break;

            i=parent; // then i ko parent per la dete h next itertion ke liye (checking again that ele.s swaps or not)
        }
    }
    
    // size == idx-1
    int size(){
        return idx-1;
    }


    void pop(){
        // delete/pop the ele (sbse min. ele. pop hoga) from the top of the minheap 
        idx--;
        arr[1]=arr[idx]; // last ele (which is max ele in the minheap) ko rakh denge min ele ke place per

        // re-arrangement -> after deleting ele from top of the minheap 
        int i=1;
        while(true){
            int left=2*i;
            int right=2*i+1;
            if(left>idx-1) break; // idx-1 = size
            if(right>idx-1){ // it means left exists 
                if(arr[i]>arr[left]){ // parent ele. greater h left child se than swap 
                    swap(arr[i],arr[left]);
                    i=left;
                    break;
                }
                else break;
            }
            
            if(arr[left]<arr[right]){ // we find min ele. from left and right child if left child have min ele than agian 
                if(arr[i]>arr[left]){ // check if parent is greater than left child than swap 
                    swap(arr[i],arr[left]);
                    i=left;
                }
                else break;
            }
            else{ // (arr[left]>arr[right])    // right ele. is min ele. 
                if(arr[i]>arr[right]){    // if parent ele. is graeter than right than swap 
                    swap(arr[i],arr[right]);
                    i=right;
                }
                else break;
            }
        }
    }

    // display minheap ele.s via array 
    void display(){
        for(int i=1; i<=idx-1; i++){ // size = idx-1
            cout<<arr[i]<<" ";
        }
        cout<<endl;
    }

};
int main(){

    Minheap pq;
    pq.push(10);
    pq.push(20);
    pq.display();
    cout<<pq.top()<<" "<<pq.size()<<endl;
    pq.push(11);
    pq.push(2);
    pq.display();
    cout<<pq.top()<<" "<<pq.size()<<endl;
    pq.pop();
    cout<<pq.top()<<" "<<pq.size()<<endl;
    pq.display();

}


// 10 20 
// 10 2
// 2 10 11 20
// 2 4
// 10 3
// 10 20 11
