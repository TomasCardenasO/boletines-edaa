#include <bits\stdc++.h>

using namespace std;

int linear_search(int arr[], int length, int value) {
    for(int i = 0; i < length; i++) {
        if(arr[i] == value) {
            return i;
        }
    }
    return -1;
}

//Requires an ordered array.
int binary_search(int arr[], int firstindex, int lastindex, int value) {
    if(firstindex > lastindex) {
        return -1;
    }
    int midd = firstindex + (lastindex - firstindex) / 2;
    if(arr[midd] == value) return (midd);
    else if(arr[midd] > value) return binary_search(arr, firstindex, midd - 1, value);
    else return binary_search(arr, midd + 1, lastindex, value);
}

//Requires an ordered array.
int exponential_search(int arr[], int length, int value) {
    if(length <= 0) {
        return -1;
    }
    if(arr[0] == value) {
        return 0;
    }
    int bound = 1;
    while(arr[bound] < value and bound < length) {
        bound *= 2;
    }
    return binary_search(arr, bound / 2, min(bound, length - 1), value);
}

int main() {

    return 0;
}