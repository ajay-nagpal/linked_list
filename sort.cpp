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

void selectionsort(node * start){
    if(start==NULL ){
        cout<<"empty list"<<endl;
        return ;
    }
    if( start->link==NULL){
        cout<<" list only has one element"<<endl;
        return ;
    }
    node * p,*q;
    int temp;
    for(p=start;p->link!=NULL;p=p->link){
        for(q=p->link;q!=NULL;q=q->link){
            if(p->data>q->data){
                temp=p->data;
                p->data=q->data;
                q->data=temp;
            }
         }
    }
}

void bubblesort(node * start){
    if(start==NULL ){
        cout<<"empty list"<<endl;
        return ;
    }
    if( start->link==NULL){
        cout<<" list only has one element"<<endl;
        return ;
    }
    node * p,*q,*end;
    int temp;
    for(end=NULL;end!=start->link;end=q){
        for(p=start;p->link!=end;p=p->link){
            q=p->link;
            if(p->data>q->data){
                temp=p->data;
                p->data=q->data;
                q->data=temp;
            }
         }
    }
}

node * selectionsortlink(node * start){
    if(start==NULL ){
        cout<<"empty list"<<endl;
        return start;
    }
    if( start->link==NULL){
        cout<<" list only has one element"<<endl;
        return start;
    }

    node *p,*q,*r,*s,*temp;

    for(p=q=start;q->link!=NULL;p=q,q=q->link){
        for(r=s=q->link;s!=NULL;r=s,s=s->link){
            if(q->data>s->data){
                temp=q->link;
                q->link=s->link;
                s->link=temp;

                if(q!=start)
                    p->link=s;
                r->link=q;
                if(q==start)
                    start=s;

                temp=q;
                q=s;
                s=temp;
            }
        }
    }
    return start;
}

node * bubblesortlink(node * start){
    if(start==NULL ){
        cout<<"empty list"<<endl;
        return start;
    }
    if( start->link==NULL){
        cout<<" list only has one element"<<endl;
        return start;
    }
    node * p,*q,*r,*end,*temp;
    for(end=NULL;end!=start->link;end=q){
        for(r=p=start;p->link!=end;r=p,p=p->link){
            q=p->link;
            if(p->data>q->data){
    
                p->link=q->link;
                q->link=p;

                if(p!=start)
                    r->link=q;
                else
                    start=q;

                temp=p;
                p=q;
                q=temp;
                
            }
         }
    }
    return start;
}

int main(){
    int data,choice;
    node *start;
    while(1){
        cout<<endl;
        cout<<"given choices"<<endl;
        cout<<endl;
        cout<<"01 for create list"<<endl;
        cout<<"02 for display"<<endl;
        
        cout<<"03 for selection sort by exchanging data"<<endl;
        cout<<"04 for bubble sort by exchanging data"<<endl;
        
        cout<<"05 for selection sort by exchanging links"<<endl;
        cout<<"06 for bubblesort by exchanging links"<<endl;

        cout<<"07 for quit"<<endl;
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
            selectionsort(start);
            break;

            case 4:
            bubblesort(start);
            break;

            case 5:
            start=selectionsortlink(start);
            break;

            case 6:
            start=bubblesortlink(start);
            break;

            case 7:
            cout<<"you have choosen exit"<<endl;
            exit(1);

            default:
            cout<<"wrong choice entered"<<endl;
                
        }
    }
}