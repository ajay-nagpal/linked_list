#include<iostream>
#include<cstdlib> 

using namespace std;

class node{
    public:

    int data;
    node *link;
};

node * addatbeg(node *start,int data){
    node *n=new node;
    n->data=data;
    n->link=start;
    start=n;

    return start;
}

void addatend(node *start,int data){
    node *n=new node;
    n->data=data;
    n->link=NULL;

    if(start==NULL){
        cout<<"list is empty"<<endl;
        return;
    }
    node *temp=start;
    while(temp->link!=NULL){
        temp=temp->link;
    }
    temp->link=n;
}

node * create(node * start,int data){
    if(start==NULL){
        cout<<"list is empty so added node will be first node"<<endl; 
        start=addatbeg(start,data);
        return start;
    }
    else{ 
        cout<<"node will be added at end"<<endl; 
        addatend(start,data);
    }
    return start;
}

node * remove(node * start,int data){
    node * dummy=new node;
    dummy->data=0;
    dummy ->link=NULL;
    
    node * p=start;
    node * q=dummy;
    while(p!=NULL){
        if(p->data==data){
            p=p->link;
            if(p==NULL)
                dummy->link=p;
            continue;
        }
        dummy->link=p;
        dummy=dummy->link;
        p=p->link;
    }
    return q->link;  
}
void display(node * start){
    
    if(start==NULL){
        cout<<"empty list"<<endl;
        return;
    }
    node *temp=start;
    cout<<"list is"<<endl;
    
    while(temp!=NULL){
        cout<<temp->data<<" ";
        temp=temp->link;
    }
    cout<<endl;
}
int main(){
    int data,choice,pos,item;
    node *start;
    while(1){
        cout<<endl;
        cout<<"given choices"<<endl;
        cout<<endl;
        cout<<"01 for create list"<<endl;
        cout<<"02 for display"<<endl;
      
        cout<<"03 for add in empty list / add at beg"<<endl;
        cout<<"04 for add at end"<<endl;
        
        cout<<"05 for remove a element completely from the list"<<endl;
        cout<<"06 for quit"<<endl;
        cout<<endl;
        cout<<"enter your choice"<<endl;
        cin>>choice;
        cout<<endl;

        switch(choice){
            case 1:
            cout<<"enter data"<<endl;
            cin>>data;
            start=create(start,data);
            break;

            case 2:
            display(start);
            break;

            case 3:
            cout<<"enter data to add at beg or in empty list"<<endl;
            cin>>data;

            start=addatbeg(start,data);
            break;

            case 4:
            cout<<"enter data to add at end"<<endl;
            cin>>data;

            addatend(start,data);
            break;

            case 5:
            cout<<"enter data to remove"<<endl;
            cin>>data;
            
            start=remove(start,data);
            break;

            case 6:
            cout<<"you have choosen exit"<<endl;
            exit(1);

            default:
            cout<<"wrong choice entered"<<endl;
                
        }
    }
}