#include <iostream>

using namespace std;
#define MAX_SIZE 101

class SortedArray 
{
private: 
    int end;
    int arr[MAX_SIZE];

public:
    SortedArray() { 
        arr[MAX_SIZE];
        end = -1;
    }

    void print() {
        for (int i = 0; i <= end; i++) {
            cout<<arr[i]<<" ";
        }
        cout<<endl;
    }

    void insert(int data) {
        if(end == -1) {
            arr[++end] = data;
            return;
        }
        int i = 0;
        while(arr[i] < data && i != end+1) i++;
        for (int j = end; j >= i; j--) {
            arr[j+1] = arr[j];            
        }
        arr[i] = data;
        end++;
        return;
    }

    void search(int data) {
        if(end == -1) {
            cout<<"Array is empty!"<<endl;
            return;
        }
        int lo = 0; 
        int hi = end;
        int mid;
        while(lo < hi) {
            mid = (lo + hi)/2;
            if(arr[mid] == data) {
                cout<<data<<" found at index "<<mid<<endl;
                return;
            } else if(arr[mid] < data) {
                lo = mid+1;
            } else {
                hi = mid;
            }
        }
        cout<<data<<" is not in the array"<<endl;
        return;
    }

    void deleteData(int data) {
        
    }

};

int main() 
{
    SortedArray sr;
    sr.insert(1);
    sr.insert(3);
    sr.insert(2);
    sr.insert(9);
    sr.insert(7);
    sr.insert(9);

    sr.search(9);

    sr.print();

}