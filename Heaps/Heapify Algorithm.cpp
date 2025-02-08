// Heapify algorithm is nothing but it is just like a pop()'s and re-arrangement of the minheap. 

#include<iostream>
using namespace std;

void display(int arr[], int n){
    for(int i=0; i<n; i++){
        cout<<arr[i]<<" ";
    }
    cout<<endl;
}

// heapify algorithm is just like a pop()'s and re-arrangement.
void heapify(int i, int arr[], int n){  
        while(true){
            int left=2*i;
            int right=2*i+1;
            if(left>=n) break; // array's size != idx 
            if(right>=n){  
                if(arr[i]>arr[left]){ 
                    swap(arr[i],arr[left]);
                    i=left;
                    break;
                }
                else break;
            }
            
            if(arr[left]<arr[right]){ 
                if(arr[i]>arr[left]){ 
                    swap(arr[i],arr[left]);
                    i=left;
                }
                else break;
            }
            else{
                if(arr[i]>arr[right]){   
                    swap(arr[i],arr[right]);
                    i=right;
                }
                else break;
            }
        }
    }

int main(){
    int arr[]={-1,10,2,14,11,1,4}; // Take -1 in 0th idx as fisrt ele. becoz our idx 1 is not disturb
    int n=sizeof(arr)/4; // divide by integer
  
    display(arr,n);
  
    // heapify algorithm used 
    for(int i=n/2; i>=1; i--){
        heapify(i,arr,n);
    }
    display(arr,n);
}



// Ignore 1st ele. 
// -1 10 2 14 11 1 4 -> original array 
// -1 1 2 4 11 10 14 -> sorted by heapify algo.
