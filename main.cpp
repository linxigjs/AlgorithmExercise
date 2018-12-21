//
// Created by gjs on 18-10-18.
//

// selection sort and insert sort

#include <iostream>
#include <vector>

using namespace std;

template <typename T>
void SelectionSort(vector<T>& vec) {
    int len = vec.size();
    for(int i=0; i<len; i++) {
        int min = i;
        for(int j=i+1; j<len; j++) {
            if(vec[j] < vec[min]) {
                min = j;
            }
        }
        int temp = vec[min];
        vec[min] = vec[i];
        vec[i] = temp;
    }
}

template <typename T>
void InsertionSortSwap(vector<T>& vec) {
    int len = vec.size();
    for(int i=1; i<len; i++) {
        for(int j=i; j>0; j--) {
            if(vec[j] < vec[j-1]) {
                T temp = vec[j];
                vec[j] = vec[j-1];
                vec[j-1] = temp;
            }
        }
    }
}

template <typename T>
void InsertionSortBack(vector<T>& vec) {
    int len = vec.size();
    for(int i=1; i<len; i++) {
        T temp = vec[i];
        int j;
        for(j=i-1; j>=0 && (vec[j] > temp); j--) {
            vec[j+1] = vec[j];
        }
        vec[j+1] = temp;
    }
}

template <typename T>
void InsertionSortWithGuard(vector<T>& vec) {
    int len = vec.size(), min=0;
    for(int k=0; k<len; k++) {
        if(vec[k] < vec[min]) {
            min = k;
        }
    }
    T temp = vec[min];
    vec[min] = vec[0];
    vec[0] = temp;
    for(int i=1; i<len; i++) {
        T temp = vec[i];
        int j;
        for(j=i-1; j>=0; j--) {
            if(vec[j] > temp)
                vec[j+1] = vec[j];
            else
                break;
        }
        vec[j+1] = temp;
    }
}

int main() {
    vector<int> vec{1, 42, 6, 33, 2, 70, 1};
    SelectionSort(vec);
    for(auto e : vec) {
        cout << e << " ";
    }
    cout << endl;
    return 0;
}
