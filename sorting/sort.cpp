#include<iostream>
#include<stdlib.h>
using namespace std;

class Array {
    private:
        int *p;
        int size;
        int partition(int *,int ,int);
    public :
        Array(){
            cout<<"How many numbers of value to sort : ";
            cin>>size;
            size = size + 1;
            p = new int [size+1];
            cout<<"\n Enter the value : ";
            for(int i=0; i<size; i++){
                cin>>p[i];
            }
            p[size] = INT_MAX;
            cout<<"\n Inserted value : ";
            for(int i=0; i<size; i++){
                cout<<p[i]<<" ";
            }cout<<endl;
        }
        ~Array(){
            cout<<"final result : ";
            for(int i=0; i<size; i++){
                cout<<p[i]<<" ";
            }cout<<endl;
            delete[] p;
        }
        void BubbleSort();
        void SelectionSort();
        void InsertionSort();
        void QuickSort(int l,int h);
};

int main(){
    do{
        Array arr;
        cout<<"1. Bubble Sort\n";
        cout<<"2. Selection Sort\n";
        cout<<"3. Insertion Sort\n";
        cout<<"4. Quick Sort\n";
        cout<<"5. Quit\n";
        int choice ;
        cin>>choice;
        switch(choice){
            case 1: arr.BubbleSort();break;
            case 2: arr.SelectionSort();break;
            case 3: arr.InsertionSort();break;
            case 4: arr.QuickSort();break;
            default: exit(1);
        }
    }while(1);
    return 0;
}
void Array::BubbleSort(){
    int flag;
    for(int i=0; i<size-1; i++){
        flag =0;
        for(int j=0; j<size-1-i; j++){
            if(p[j]>p[j+1]){
                int temp = p[j];
                p[j] = p[j+1];
                p[j+1] = temp;
                flag = 1;
            }
        }
        if(!flag){
            break;
        }
    }
}
void Array::SelectionSort(){
      int j,k,temp;
    for(int i=0; i<size; i++){
        j = k = i;
        for(j; j<size; j++){
            if(p[j]<p[k]){
                k = j;
            }
        }
        temp = p[i];
        p[i] = p[k];
        p[k] = temp;
    }
}
void Array::InsertionSort(){
    for(int i=1; i<n; i++){
        int x = p[i];
        int j = i-1;
        while(j > -1 && p[j] > x){
            p[j+1] = p[j];
            j--;
        }
        p[j+1] = x;
    }
}
int Array::partition(int a[],int l,int h){
    int pivot = a[l];
    int i = l,j=h;
    do{
        do{i++;}while(a[i]<=pivot);
        do{j--;}while(a[j]>pivot);
        if(i<j){
            int temp = a[i];
            a[i] = a[j];
            a[j] = temp;
        }
    }while(i<j);
    int temp = a[l];
    a[l] = a[j];
    a[j] = temp;
    return j; 
}
void Array::QuickSort(int l, int h){
    // int pivot,i,j,temp;
    // pivot = p[0];
    // i = 0; j = size-1;
    // while(i<j){
    //     if(pivot >= p[i]) i++;
    //     if(pivot < p[j]) j--;
    //     if(p[i] > p[j]){
    //         temp = p[i];
    //         p[i] = p[j];
    //         p[j] = temp;
    //     }
    // }
    int j;
    if(l<h){
        j=partition(p,l,h);
        QuickSort(l,j);
        QuickSort(j+1,h);
    }
}