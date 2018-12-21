//
// Created by gjs on 18-10-18.
//

// 希尔排序

#include <iostream>
#include <vector>

using namespace std;

void Shell(vector<int>& vec) {
    int len = vec.size();
    int h = 1;
    while (h < len/3)
        h = 3*h + 1;
    while(h >= 1) {
        for(int i=h; i<len; i++) {
            int tt = vec[i], j=0;
            for(j=i; j>=h && vec[j-h]>tt; j-=h) {
                vec[j] = vec[j-h];
            }
            vec[j] = tt;
        }
        h /= 3;
    }
}

int main() {
    vector<int> vec{100, 4, 23, 14, 46, 90, 24, 54, 46, 20};
    Shell(vec);
    cout << endl << "result : " << endl;
    for(auto e : vec) {
        cout << e << " ";
    }
    cout << endl;
    return 0;
}
