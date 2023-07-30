//find position of an element in a distinct sorted array
// complexity O(log2 N)

#include<bits/stdc++.h>
using namespace std;

int binarySearch(int arr[],int len,int val){
    int left = 0;
    int right = len - 1;

    while(left <= right){
        int mid = (right - left) / 2 + left;
        if(arr[mid]==val) return mid;
        else if(arr[mid]<val){
            left = mid + 1;
        }else right = mid - 1;
    }

    return -1;
}

int main(){

    int arr[] = {-2, 0, 4, 6, 7, 8, 99, 121, 4333, 9333};
    int len = sizeof arr / sizeof arr[0];
    int search_element = 99;

    int pos = binarySearch(arr,len,search_element);

    cout<<"position of "<<search_element<<" is "<<pos<<endl;
    return 0;
}
