#include<iostream>
#include<stdlib.h>
using namespace std;

//Declaration of structure node
struct node{
    int data;
    node *next;
    node *prev;
    node(int data){
        this->data = data;
        this->next = NULL;
        this->prev = NULL;
    }
};

class DoubleList{
    node *head;
    public:
        DoubleList():head(NULL){}
        void create(int);
        void display();
        void displayReverse();
        void count();
        bool search(int);
        void addAtBegin(int);
        void addAtEnd(int);
        void addAfterNode(int,int);
        void addBeforeNode(int,int);
        void addAtPosition(int,int);
        void Delete(int);
        void reverse();
};

void DoubleList::create(int size){
    while(size--){
        int val;
        cout<<"Enter the value : ";
        cin>>val;
        cout<<endl;
        if(head == NULL){
            addAtBegin(val);
        }else{
            addAtEnd(val);
        }
    }
}
void DoubleList::display(){
   node *temp = head;
   while(temp != NULL){
       cout<<temp->data<<" ";
       temp = temp->next;
   }
   cout<<endl;
}
void DoubleList::displayReverse(){
   node *temp = head;
   while(temp->next != NULL){
       temp = temp->next;
   }
   while(temp != NULL){
       cout<<temp->data<<" ";
       temp = temp->prev;
   }
   cout<<endl;
}
void DoubleList::count(){
    int c = 0;
    node *temp = head;
    while(temp != NULL){
        c++;
        temp = temp->next;
    }
    cout<<"count : "<<c<<endl;
}
bool DoubleList::search(int find){
    node *temp = head;
    while(temp != NULL){
        if(temp->data == find){
            return true;
        }
        temp = temp->next;
    }   
    return false;
}
void DoubleList::addAtBegin(int val){
    if(head == NULL){
        head = new node(val);
    }else{
        node *temp = new node(val);
        temp->next = head;
        head->prev = temp;
        head = temp;
    }
}
void DoubleList::addAtEnd(int val){
    if(head == NULL){
        return;
    }else{
        node *temp = head;
        while(temp->next != NULL){
            temp = temp->next;
        }
        node *add = new node(val);
        temp->next = add;
        add->prev = temp;
    }
}
void DoubleList::addAfterNode(int val,int item){
    if(head == NULL){
        return;
    }else{
        node *temp = head;
        while(temp != NULL){
            if(temp->data == item){
                break;
            }
            temp = temp->next;
        }
        node *add = new node(val);
        add->next = temp->next;
        temp->next->prev = add;
        temp->next = add;
        add->prev = temp;
    }
}
void DoubleList::addBeforeNode(int val,int item){
    if(head == NULL){
        return;
    }else{
        node *temp = head;
        node *prev = NULL;
        while(temp != NULL){
            if(temp->data == item){
                break;
            }
            prev = temp;
            temp = temp->next;
        }
        node *add = new node(val);
        if(prev != NULL){
            add->next = prev->next;
            prev->next->prev = add;
            prev->next = add;
            add->prev = prev;
        }else{
            addAtBegin(val);
        }
    }
}
void DoubleList::addAtPosition(int val,int pos){
    if(head == NULL){
        return;
    }else{
    node *temp = head;
    int x = pos;
    while(--pos > 0){
        temp = temp->next;
    }
    if(x == 0){
        addAtBegin(val);
    }else{
    node *add = new node(val);
    add->next = temp->next;
    temp->next->prev = add;
    temp->next = add;
    add->prev = temp;
    }
    }
}
void DoubleList::Delete(int item){
    if(head == NULL){
        return;
    }else{
    node *temp,*prev;
    temp = head;
    prev = NULL;
    while(temp != NULL){
        if(temp->data == item){
            break;
        }
        prev = temp;
        temp = temp->next;
    }
    if(prev != NULL){
        prev->next = temp->next;
        temp->next->prev = prev;
        delete temp;
    }else{
        head = temp->next;
        temp->next->prev = NULL;
        delete temp;
    }
    }
}
void DoubleList::reverse(){
    node *prev,*curr;
    prev = NULL;
    curr = head;
    while(curr != NULL){
        curr->prev = curr->next;
        curr->next = prev;
        prev = curr;
        curr = curr->prev;
    }
    head = prev;
}

int main(){

        DoubleList sl;
    do{
        cout<<"1. Create List\n";
        cout<<"2. Display\n";
        cout<<"3. Count\n";
        cout<<"4. Search\n";
        cout<<"5. Add to empty list / Add at beginning\n";
        cout<<"6. Add at end\n";
        cout<<"7. Add after node\n";
        cout<<"8. Add before node\n";
        cout<<"9. Add at position\n";
        cout<<"10. Delete\n";
        cout<<"11. Reverse\n";
        cout<<"12. Display Reverse\n";
        cout<<"13. Quit\n";
        int n;
        cin>>n;
        int val,item,pos,size;
        val = item = pos = size = 0;
        switch(n){
            case 1:{
                cout<<"Enter the size : ";
                cin>>size;
                cout<<endl;
                sl.create(size);
            }
            break;
            case 2:
                sl.display();
            break;
            case 3:
                sl.count();
            break;
            case 4:{
                cout<<"Enter the item to search : ";
                cin>>item;
                cout<<endl;
                cout<<sl.search(item)<<endl;
            }
            break;
            case 5:{
                cout<<"Enter a value : ";
                cin>>val;
                cout<<endl;
                sl.addAtBegin(val);
            }
            break;
            case 6:{
                cout<<"Enter a value : ";
                cin>>val;
                cout<<endl;
                sl.addAtEnd(val);
            }            
            break;
            case 7:{
                cout<<"Enter a value : ";
                cin>>val;
                cout<<endl;
                cout<<"Enter a item : ";
                cin>>item;
                cout<<endl;
                sl.addAfterNode(val,item);
            }
            break;
            case 8:{
                cout<<"Enter a value : ";
                cin>>val;
                cout<<endl;
                cout<<"Enter a item : ";
                cin>>item;
                cout<<endl;
                sl.addBeforeNode(val,item);
            }break;
            case 9:{
                cout<<"Enter a value : ";
                cin>>val;
                cout<<endl;
                cout<<"Enter a position : ";
                cin>>pos;
                cout<<endl;
                sl.addAtPosition(val,pos);
            }break;
            case 10:{
                cout<<"Enter a element to be deleted : ";
                cin>>val;
                cout<<endl;
                sl.Delete(val);
            }break;
            case 11:
                sl.reverse();
            break;
            case 12:
                sl.displayReverse();
            break;
            case 13:
                exit(1);            
            break;
        }
        
    }while(1);

    return 0;
}