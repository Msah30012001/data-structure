#include<iostream>
#include<bits/stdc++.h>

using namespace std;

int binarySearch(int[],int,int);

int main(){
    int e[] = {2,4,6,8,12,18};
    int o[] = {3,8,11,14,16};
    cout<<binarySearch(e,6,12);
    return 0;
}

int binarySearch(int arr[], int size, int key){
    int start = 0;
    int end  = size - 1;
    int mid = 0;
    while(start <= end){
       // mid = (start + end)/2;
        mid = start + (end - start)/2;
        if(arr[mid] == key){
            return mid;
        }
        if(arr[mid] > key){
            start = mid + 1;
        }
        if(arr[mid] < key){
            end = mid - 1;
        }
    }
    return -1;
}