#include<iostream>
#include<stdlib.h>
using namespace std;
void BubbleSort();

int main(){
    do{
        cout<<"1. Insert\n";
        cout<<"2. Quit\n";
        int choice ;
        cin>>choice;
        switch(choice){
            case 1:BubbleSort();
            break;
            case 2:
                exit(1);
            break;
        }
    }while(1);
    return 0;
}
void BubbleSort(){
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
    int flag;
    for(int i=0; i<n-1; i++){
        flag =0;
        for(int j=0; j<n-1-i; j++){
            if(a[j]>a[j+1]){
                int temp = a[j];
                a[j] = a[j+1];
                a[j+1] = temp;
                flag = 1;
            }
        }
        if(!flag){
            break;
        }
    }
    cout<<"final Stage : ";
    for(int i=0; i<n; i++){
        cout<<a[i]<<" ";
    }cout<<endl;
}