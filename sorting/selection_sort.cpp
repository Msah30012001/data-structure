#include<iostream>
#include<stdlib.h>
using namespace std;
void SelectionSort();

int main(){
    do{
        cout<<"1. Insert\n";
        cout<<"2. Quit\n";
        int choice ;
        cin>>choice;
        switch(choice){
            case 1:SelectionSort();
            break;
            case 2:
                exit(1);
            break;
        }
    }while(1);
    return 0;
}
void SelectionSort(){
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
        int j,k,temp;
    for(int i=0; i<n; i++){
        j = k = i;
        for(j; j<n; j++){
            if(a[j]<a[k]){
                k = j;
            }
        }
        temp = a[i];
        a[i] = a[k];
        a[k] = temp;
    }
    cout<<"final Stage : ";
    for(int i=0; i<n; i++){
        cout<<a[i]<<" ";
    }cout<<endl;
}