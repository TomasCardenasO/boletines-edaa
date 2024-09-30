#include <bits\stdc++.h>

using namespace std;

#define ERROR_NOT_FOUND -1
#define ERROR_INVALID_INDEX -2
#define ERROR_INVALID_LENGTH -3

long long linear_search(const long long arr[], long long length, long long value) {
    for(long long i = 0; i < length; i++) {
        if(arr[i] == value) {
            return i;
        }
    }
    return ERROR_NOT_FOUND;
}

//Requires an ordered array.
long long binary_search(const long long arr[], long long firstindex, long long lastindex, long long value) {
    long long midd;
    if(firstindex < 0 or lastindex < 0 or lastindex < firstindex) {
        return ERROR_INVALID_INDEX;
    }
    while(firstindex <= lastindex) {
        midd = firstindex + (lastindex - firstindex) / 2;
        if(arr[midd] == value) {
            return midd;
        } else if(arr[midd] > value) {
            lastindex = midd - 1;
        } else { //arr[midd] < value
            firstindex = midd + 1;
        }
    }
    return ERROR_NOT_FOUND;
}

//Requires an ordered array.
long long exponential_search(const long long arr[], long long length, long long value) {
    if(length <= 0) {
        return ERROR_INVALID_LENGTH;
    }
    if(arr[0] == value) {
        return 0;
    }
    long long bound = 1;
    while(bound < length and arr[bound] < value) {
        bound *= 2;
    }
    return binary_search(arr, bound / 2, min(bound, length - 1), value);
}

int main() {

    return 0;
}