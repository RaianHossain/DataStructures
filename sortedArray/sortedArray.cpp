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

    void insert(int data) { //inserting
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

    int search(int data) { //binary search
        if(end == -1) {
            return -1;
        }
        int lo = 0; 
        int hi = end+1;
        int mid;
        while(lo < hi) {
            mid = (lo + hi)/2;
            if(arr[mid] == data) {
                return mid;
            } else if(arr[mid] < data) {
                lo = mid+1;
            } else {
                hi = mid;
            }
        }
        return -1;
    }

    void deleteByDataAll(int data) { //deletes all the matches
        int pos = search(data);
        if(pos == -1) {
            return;
        }
        for(int i = pos; i < end; i++) {
            arr[i] = arr[i+1];
        }
        end--;
        deleteByDataAll(data);
    }

    void deleteByData(int data) { //deletes only the first match
        int pos = search(data);
        if(pos == -1) {
            return;
        }
        for(int i = pos; i < end; i++) {
            arr[i] = arr[i+1];
        }
        end--;
    }

};

int main() 
{
    SortedArray sr;
    sr.insert(1);
    sr.insert(3);
    sr.insert(3);
    sr.insert(2);
    sr.insert(9);
    sr.insert(7);
    sr.insert(9);
    cout<<"After insertion: ";
    sr.print();
    cout<<"Searching Number 3: ";
    cout<<"Found at "<<sr.search(3)<<endl;
    cout<<"Delete by the(all the matches of 9): ";
    sr.deleteByDataAll(9);
    sr.print();
    cout<<"Delete by the(Only the first match of 3): ";
    sr.deleteByData(3);
    sr.print();
    cout<<endl;
    return 0;
}