#include<iostream>
#include<cstdlib> 

using namespace std;

class node{
    public:

    int data;
    node *link;
};

void addatend(node *head,int data){
    node *n=new node;
    n->data=data;
    n->link=NULL;

    node *temp=head;
    while(temp->link!=NULL){
        temp=temp->link;
    }
    temp->link=n;
}

void create(node * head,int data){
        addatend(head,data);
}

void display(node * head){
  
  if(head->link==NULL){
    cout<<"list is empty"<<endl;
    return ;
  }
    node *temp=head->link;
    cout<<"list is"<<endl;
    
    while(temp!=NULL){
        cout<<temp->data<<" ";
        temp=temp->link;
    }
    cout<<endl;
}

void count(node *head){
    int c;
    if(head->link==NULL){
    cout<<"list is empty"<<endl;
    return ;
  }
    node *temp=head->link;
    while(temp!=NULL){
        c++;
        temp=temp->link;
    }
    
    cout<<" count is "<<c<<endl;   
}

void search(node *head,int data){

    if(head->link==NULL){
    cout<<"list is empty"<<endl;
    return ;
  }
    node * temp=head->link;
    while(temp!=NULL){
        if(temp->data==data){
            cout<<"data found"<<endl;
            return;
        }
        temp=temp->link;       
    }
    cout<<"data not found"<<endl;
}

void addbefore(node * head,int data,int item){
    node *n=new node;
    n->data=data;
    n->link=NULL;

    if(head->link==NULL){
        cout<<"no data present because list is empty"<<endl;
        return ;
    }
    if(head->link->data==item){
        cout<<"node will become 1st node"<<endl;
        n->link=head->link;
        head->link=n;
        return ;
    }
    node * temp=head->link;
    while(temp!=NULL){
        if(temp->link->data==item){
            n->link=temp->link;
            temp->link=n;
            return ;
        }
        temp=temp->link;
    }
    cout<<"item not found"<<endl;    
}

void  delete1(node * head,int data){
    if(head->link==NULL){
        cout<<"list is empty no data to delete"<<endl;
        return ;
    }
    if(head->link->data==data){
        
    }

    node * temp=head;
    while(temp!=NULL){
        if(temp->link->data==data){
            temp->link=temp->link->link;
            return ;
        }
        temp=temp->link;   
    }
    cout<<"no data found to delete"<<endl;
}

void addatpos(node * head,int data ,int pos){
    node *n=new node;
    n->data=data;
    n->link=NULL;

    // if(pos==1 && head->link==NULL){
    //     cout<<"list is empty so no pos"<<endl;
    //     //addatend(head,data);
    //     return ;
    // }
    // if(pos==1 && head->link!=NULL ){
    //     cout<<"node will become 1st node"<<endl;
    //     n->link=head->link;
    //     head->link=n;
        
    //     return ;
    // }

    int point=0;

    node * temp=head;
    
    while( temp!=NULL){
        cout<<"in while"<<temp->data<<endl;
        if(point==pos-1){
            cout<<"in if"<<temp->data<<endl;

            n->link=temp->link;
            temp->link=n;
            return ;
        }
        cout<<"after if"<<temp->data<<endl;
        point++;
        temp=temp->link;   
    }
    cout<<"pos not found"<<endl;
}

void reverse(node * head){
    if(head->link==NULL){
        cout<<"list is empty"<<endl;
        return ;
    }
    
    node *p=NULL;
    node *q=head->link;;
    node *r=q->link;
    while(q!=NULL){
        q->link=p;
        p=q;
        q=r;
        if(q!=NULL)
        r=q->link;
    }
    head->link=p;
    
}
int main(){
    int data,choice,pos,item;
    node *head=new node;
    head->data==0;
    head->link=NULL;

    while(1){
        cout<<endl;
        cout<<"given choices"<<endl;
        cout<<endl;
        cout<<"01 for create list"<<endl;
        cout<<"02 for display"<<endl;
        cout<<"03 for count"<<endl;
        cout<<"04 for search "<<endl;
        cout<<"05 for add at end"<<endl;
        
        cout<<"06 for add before node"<<endl;
        
        cout<<"07 for delete the node"<<endl;
        cout<<"08 for add at pos"<<endl;
        cout<<"09 for reverse the list"<<endl;
        cout<<"10 for quit"<<endl;
        cout<<endl;
        cout<<"enter your choice"<<endl;
        cin>>choice;
        cout<<endl;

        switch(choice){
            case 1:
            cout<<"enter data"<<endl;
            cin>>data;
            create(head,data);
            break;

            case 2:
            display(head);
            break;

            case 3:
            count(head);
            break;

            case 4:
            cout<<"enter data to search"<<endl;
            cin>>data;

            search(head,data);
            break;

            case 5:
            cout<<"enter data to add at end"<<endl;
            cin>>data;

            addatend(head,data);
            break;

            case 6:
            cout<<"enter data to add "<<endl;
            cin>>data;
            cout<<endl;
            cout<<"enter item before which you want  to add data "<<endl;
            cin>>item;

            addbefore(head,data, item);
            break;
           
            case 7:
            cout<<"enter data to delete "<<endl;
            cin>>data;
            delete1(head, data);
            break;

            case 8:
            cout<<"enter data to add "<<endl;
            cin>>data;
            cout<<endl;
            cout<<"enter pos at which you want  to add data "<<endl;
            cin>>pos;

            addatpos(head,data, pos);
            break;

            case 9:
            reverse(head);
            break;

            case 10:
            cout<<"you have choosen exit"<<endl;
            exit(1);

            default:
            cout<<"wrong choice entered"<<endl;
                
        }
    }
}