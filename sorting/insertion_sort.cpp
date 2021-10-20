#include<iostream>
#include<stdlib.h>
using namespace std;
void InsertionSort();

int main(){
    do{
        cout<<"1. Insert\n";
        cout<<"2. Quit\n";
        int choice ;
        cin>>choice;
        switch(choice){
            case 1:InsertionSort();
            break;
            case 2:
                exit(1);
            break;
        }
    }while(1);
    return 0;
}
void InsertionSort(){
    int n;
    cout<<"How many numbers of value to sort : ";
    cin>>n;
    cout<<"\n Enter the value : ";
    int a[n];
    for(int i=0; i<n; i++){
        cin>>a[i];
    }
    cout<<"\nIntial Stage : ";
    for(int i=0; i<n; i++){
        cout<<a[i]<<" ";
    }cout<<endl;
    for(int i=1; i<n; i++){
        int x = a[i];
        int j = i-1;
        while(j > -1 && a[j] > x){
            a[j+1] = a[j];
            j--;
        }
        a[j+1] = x;
    }
    cout<<"final Stage : ";
    for(int i=0; i<n; i++){
        cout<<a[i]<<" ";
    }cout<<endl;
}