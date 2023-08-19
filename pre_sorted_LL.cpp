#include<iostream>
#include<cstdlib> 

using namespace std;

class node{
    public:

    int data;
    node *link;
};

node * insertsort(node * start,int data){
    node * n=new node;
    n->data=data;
    n->link=NULL;

    if(start==NULL || data<start->data){
        n->link=start;
        start=n;
        return start;  
    }
    node * temp=start;

    while(temp->link!=NULL && temp->link->data<data){
        temp=temp->link;
    }
    n->link=temp->link;
    temp->link=n;
    return start;
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

void search(node *start,int data){
    node * temp=start;
    while(temp!=NULL){
        if(temp->data==data){
            cout<<"data found"<<endl;
            return;
        }
        temp=temp->link;       
    }
    cout<<"data not found"<<endl;
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
       
        cout<<"03 for search "<<endl;
        
        cout<<"04 for quit"<<endl;
        cout<<endl;
        cout<<"enter your choice"<<endl;
        cin>>choice;
        cout<<endl;

        switch(choice){
            case 1:
            cout<<"enter data"<<endl;
            cin>>data;
            start=insertsort(start,data);
            break;

            case 2:
            display(start);
            break;

            case 3:
            cout<<"enter data to search"<<endl;
            cin>>data;
            search(start,data);
            break;

            case 4:
            cout<<"you have choosen exit"<<endl;
            exit(1);

            default:
            cout<<"wrong choice entered"<<endl;
                
        }
    }
}