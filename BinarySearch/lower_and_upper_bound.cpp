// complexity O(log2 N)

#include<bits/stdc++.h>
using namespace std;

// find the position of first occurrence
// if the element not found it will point to first occurrence of the next element
// if the search element is smaller than first element then it will point to position 0
// if the search element is greater than last element then it will point to (array last position + 1)
int lowerBound(int arr[],int len,int val){
    int left = 0;
    int right = len - 1;
    int ans = len;

    while(left <= right){
        int mid = (right - left) / 2 + left;
        if(arr[mid]>=val){
            ans = mid;
            right = mid - 1;
        }else{
            left = mid + 1;
        }
    }

    return ans;
}

// return the last occurrence + 1
// if the search element is smaller than first element then it will point to position 0
// if the search element is greater than last element then it will point to (array last position + 1)
int upperBound(int arr[],int len,int val){
    int left = 0;
    int right = len - 1;
    int ans = len;

    while(left <= right){
        int mid = (right - left) / 2 + left;
        if(arr[mid]>val){
            ans = mid;
            right = mid - 1;
        }else{
            left = mid + 1;
        }
    }

    return ans;
}

int main(){

    int arr[] = {-2, 0, 0, 4, 6, 6, 7,7, 7, 8, 99, 121, 121, 4333, 9333};
    int len = sizeof arr / sizeof arr[0];
    int search_element = 7;

    int lower_b = lowerBound(arr,len,search_element);
    int upper_b = upperBound(arr,len,search_element);

//    built in
//    int lower_b = lower_bound(arr,arr+len,search_element) - arr;
//    int upper_b = upper_bound(arr,arr+len,search_element) - arr;

    cout<<"Lower bound of "<<search_element<<" is "<<lower_b<<endl;
    cout<<"Upper bound of "<<search_element<<" is "<<upper_b<<endl;
    return 0;
}
