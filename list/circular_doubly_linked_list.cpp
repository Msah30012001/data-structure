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

class DoublyCircularList{
    node *head;
    public:
        DoublyCircularList():head(NULL){}
        void create(int);
        void display();
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

void DoublyCircularList::create(int size){
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
void DoublyCircularList::display(){
   node *temp = head;
   while(temp->next != head){
       cout<<temp->data<<" ";
       temp = temp->next;
   }
   cout<<temp->data<<endl;
}
void DoublyCircularList::count(){
    int c = 0;
    node *temp = head;
    while(temp->next != head){
        c++;
        temp = temp->next;
    }
    cout<<"count : "<<++c<<endl;
}
bool DoublyCircularList::search(int find){
    node *temp = head;
    while(temp->next != head){
        if(temp->data == find){
            return true;
        }
        temp = temp->next;
    }   
    if(temp->data == find){
        return true;
    }
    return false;
}
void DoublyCircularList::addAtBegin(int val){
    if(head == NULL){
        head = new node(val);
        head->next = head;
        head->prev = head;
    }else{
        node *temp = head;
        while(temp->next != head){
            temp = temp->next;
        }
        node *add = new node(val);
        add->next = head;
        head->prev = add;
        temp->next = add;
        add->prev = temp;
        head = add;
    }
}
void DoublyCircularList::addAtEnd(int val){
    if(head == NULL){
        return;
    }else{
        node *temp = head;
        while(temp->next != head){
            temp = temp->next;
        }
        node *add = new node(val);
        temp->next = add;
        add->prev = temp;
        add->next = head;
        head->prev = add;
    }
}
void DoublyCircularList::addAfterNode(int val,int item){
    if(head == NULL){
        return;
    }else{
        node *temp = head;
        while(temp->next != head && temp->data != item){
            temp = temp->next;
        }
        node *add = new node(val);
        add->next = temp->next;
        add->prev = temp;
        temp->next = add;
        head->prev = add;
    }
}
void DoublyCircularList::addBeforeNode(int val,int item){
    if(head == NULL){
        return;
    }else{
        node *temp = head;
        node *prev = NULL;
        while(temp->next != head && temp->data != item){
            prev = temp;
            temp = temp->next;
        }
        node *add = new node(val);
        if(prev != NULL){
            add->next = prev->next;
            add->prev = prev;
            prev->next->prev = add;
            prev->next = add;
        }else{
            addAtBegin(val);
        }
    }
}
void DoublyCircularList::addAtPosition(int val,int pos){
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
        add->prev = temp;
        temp->next->prev = add;
        temp->next = add;
    }
    }
}
void DoublyCircularList::Delete(int item){
    if(head == NULL){
        return;
    }else{
    node *temp,*prev;
    temp = head;
    prev = NULL;
    while(temp->next != head){
        if(temp->data == item){
            break;
        }
        prev = temp;
        temp = temp->next;
    }
    if(temp->data != item){
        return;
    }
    if(prev != NULL){
        prev->next = temp->next;
        temp->next->prev = prev;
        delete temp;
    }else{
        node* t = temp;
        while(t->next != head){
            t = t->next;
        }
        t->next = temp->next;
        head = temp->next;
        delete temp;
    }
    }
}
void DoublyCircularList::reverse(){
    node *prev,*curr,*next;
    prev = head;
    curr = head;
    while(prev->next != head){
        prev = prev->next;
    }
    while(curr->next != head){
        next = curr->next;
        curr->next = prev;
        prev = curr;
        curr = next;
    }
    curr->next = prev;
    head = curr;
}

int main(){

        DoublyCircularList sl;
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
        cout<<"12. Quit\n";
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
                exit(1);            
            break;
        }
        
    }while(1);

    return 0;
}