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

void count(node *start){
    int c;
    
    node *temp=start;
    while(temp!=NULL){
        c++;
        temp=temp->link;
    }
    
    cout<<" count is "<<c<<endl;   
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

void addafter(node * start,int data,int item){
    node *n=new node;
    n->data=data;
    n->link=NULL;

    if(start==NULL){
        cout<<"no data present because list is empty"<<endl;
        return;
    }
    node * temp=start;
    while(temp!=NULL){
        if(temp->data==item){
            n->link=temp->link;
            temp->link=n;
            return;
        }
        temp=temp->link;
    }
    cout<<"item not found"<<endl;
}


node *addbefore(node * start,int data,int item){
    node *n=new node;
    n->data=data;
    n->link=NULL;

    if(start==NULL){
        cout<<"no data present because list is empty"<<endl;
        return start;
    }
    if(start->data==item){
        n->link=start;
        start=n;
        return start;
    }
    node * temp=start;
    while(temp!=NULL){
        if(temp->link->data==item){
            n->link=temp->link;
            temp->link=n;
            return start;
        }
        temp=temp->link;
    }
    cout<<"item not found"<<endl;
    return start;
}

node * addatpos(node * start,int data ,int pos){
    if(pos==1 && start==NULL){
        cout<<"list is empty so the new node will be the first and only node"<<endl;
        start=addatbeg(start,data);
        return start;
    }

    int point=1;

    node *n=new node;
    n->data=data;
    n->link=NULL;

    node * temp=start;
    while(point !=pos && temp!=NULL){
        if(point==pos-1){
            n->link=temp->link;
            temp->link=n;
            return start;
        }
        point++;
        temp=temp->link;   
    }
    cout<<"pos not found"<<endl;
    return start;
}

void addafterpos(node * start,int data ,int pos){
    if(start==NULL){
        cout<<"list is empty "<<endl;
        return;
    }

    int point=1;

    node *n=new node;
    n->data=data;
    n->link=NULL;

    node * temp=start;
    while(point !=pos+1 && temp!=NULL){
        if(point==pos){
            n->link=temp->link;
            temp->link=n;
            return ;
        }
        point++;
        temp=temp->link;   
    }
    cout<<"pos not found"<<endl;
}

node * addbeforepos(node * start,int data ,int pos){
    if(start==NULL){
        cout<<"list is empty "<<endl;
        return  start ;
    }
    if(pos==1){
        start=addatbeg(start,data);
        return start;
    }

    int point=1;

    node *n=new node;
    n->data=data;
    n->link=NULL;

    node * temp=start;

    while(point !=pos && temp!=NULL){
        if(point==pos-1){
            n->link=temp->link;
            temp->link=n;
            return start;
        }
        point++;
        temp=temp->link;   
    }
    cout<<"pos not found"<<endl;
    return start;
}

node* delete1(node * start,int data){
    if(start==NULL){
        cout<<"list is empty no data to delete"<<endl;
        return start;
    }
    if(start->data==data){
            start=start->link;
            return start;
        }
    node * temp=start;
    while(temp!=NULL){
        if(temp->link->data==data){
            temp->link=temp->link->link;
            return start;
        }
        temp=temp->link;   
    }
    cout<<"no data found to delete"<<endl;
    return start;
}

void deleteafter(node * start,int data){
    if(start==NULL){
        cout<<"list is empty no data to delete"<<endl;
        return ;
    }

    node * temp=start->link, *p=start;
    while(temp!=NULL){
        if(p->data==data){
            p->link=temp->link;
            return ; 
        }
        p=temp;
        temp=temp->link;     
    }
    cout<<"no node found "<<endl;
}

node * deletebefore(node * start,int data){
    if(start==NULL){
        cout<<"list is empty no data to delete"<<endl;
        return start;
    }
    else if(start->data==data){
        cout<<"no data to delete"<<endl;
        return start ;
    }
    // else if(start->link->data==data){
    //     start=start->link;
    //     return start;
    // }
    node *temp=start,*p=start;
    // while(temp->link!=NULL){
    //     if(temp->link->data==data){

    //         p->link=temp->link;
    //         return start; 
    //     }
    //     p=temp;
    //     temp=temp->link;     
    // }

     while(temp->link!=NULL){
        temp=temp->link;
        if(temp->data==data){

            p->link=temp->link;
            return start; 
        }
        p=temp;
    }
    cout<<"no data found "<<endl;
    return start;
}

node* deleteatpos(node * start,int pos){
    if(start==NULL){
        cout<<"list is empty no data to delete"<<endl;
        return start;
    }
    if(pos==1){
            start=start->link;
            return start;
        }
    node * temp=start,*p;
    int point=1;

    while(point!=pos+1 && temp!=NULL){
      
        if(point ==pos){
            p->link=temp->link;
            return start;
        }
        p=temp;
       temp=temp->link;
       point++;    
    }
    cout<<"no pos found to delete"<<endl;
    return start;
}

void deleteafterpos(node * start,int pos){
    if(start==NULL){
        cout<<"list is empty no data to delete"<<endl;
        return ;
    }
    
    node * temp=start->link,*p=start;
    int point=1;

    while(point!=pos+1 && temp!=NULL){
    
        if(point ==pos){
            p->link=temp->link;
            return ;
        }
        p=temp;
        temp=temp->link;
        point++;    
    }
    cout<<"no pos found to delete"<<endl;  
}

node* deletebeforepos(node * start,int pos){
    if(start==NULL){
        cout<<"list is empty no data to delete"<<endl;
        return start;
    }
    if(pos==1){
        cout<<"no element to delete"<<endl;
        return start;
    }
    else if(pos==2){
        start=start->link;
        return start;
    }

    node * temp=start->link,*p=start;
    int point=1;

    while(point!=pos+1 && temp!=NULL){
        if(point ==pos-2){
            p->link=temp->link;
            return start;
        }
        
       temp=temp->link;
       p=p->link;
       point++;    
    }
    cout<<"no pos found to delete"<<endl;
    return start;
}

node * reverse(node * start){
    if(start==NULL){
        cout<<"list is empty"<<endl;
        return start;
    }
    
    node *p=NULL;
    node *q=start;
    node *r=start->link;
    while(q!=NULL){
        q->link=p;
        p=q;
        q=r;
        if(q!=NULL)
        r=q->link;
    }
    start=p;
    return start;
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
        cout<<"03 for count"<<endl;
        cout<<"04 for search "<<endl;
        cout<<"05 for add in empty list / add at beg"<<endl;
        cout<<"06 for add at end"<<endl;
        cout<<"07 for add after node"<<endl;
        cout<<"08 for add before node"<<endl;
        cout<<"09 for add at pos"<<endl;
        cout<<"10 for add after pos"<<endl;
        cout<<"11 for add before pos"<<endl;
        cout<<"12 for delete the node"<<endl;
        cout<<"13 for delete after data"<<endl;
        cout<<"14 for delete before data"<<endl;
        cout<<"15 for delete data at pos "<<endl;
        cout<<"16 for delete data after pos"<<endl;
        cout<<"17 for delete data before pos"<<endl;
        cout<<"18 for reverse the list"<<endl;
        cout<<"19 for quit"<<endl;
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
            count(start);
            break;

            case 4:
            cout<<"enter data to search"<<endl;
            cin>>data;

            search(start,data);
            break;

            case 5:
            cout<<"enter data to add at beg or in empty list"<<endl;
            cin>>data;

            start=addatbeg(start,data);
            break;

            case 6:
            cout<<"enter data to add at end"<<endl;
            cin>>data;

            addatend(start,data);
            break;

            case 7:
            cout<<"enter data to add "<<endl;
            cin>>data;
            cout<<endl;
            cout<<"enter item after which you want  to add data"<<endl;
            cin>>item;

            addafter(start,data,item);
            break;

            case 8:
            cout<<"enter data to add "<<endl;
            cin>>data;
            cout<<endl;
            cout<<"enter item before which you want  to add data "<<endl;
            cin>>item;

            start=addbefore(start,data, item);
            break;

            case 9:
            cout<<"enter data to add "<<endl;
            cin>>data;
            cout<<endl;
            cout<<"enter pos at which you want  to add data"<<endl;
            cin>>pos;

            start=addatpos(start,data, pos);
            break;

            case 10:
            cout<<"enter data to add "<<endl;
            cin>>data;
            cout<<endl;
            cout<<"enter pos after which you want  to add data"<<endl;
            cin>>pos;

            addafterpos(start,data, pos);
            break;

            case 11:
            cout<<"enter data to add "<<endl;
            cin>>data;
            cout<<endl;
            cout<<"enter pos before which you want  to add data"<<endl;
            cin>>pos;

            start=addbeforepos(start,data, pos);
            break;

            case 12:
            cout<<"enter data to delete "<<endl;
            cin>>data;

            start=delete1(start, data);
            break;

            case 13:
            cout<<"enter data after which you want to delete the node "<<endl;
            cin>>data;

            deleteafter(start,data);
            break;

            case 14:
            cout<<"enter data before which you want to delete the node "<<endl;
            cin>>data;

            start=deletebefore(start,data);
            break;

            case 15:
            cout<<"enter pos at which you want to delete the node "<<endl;
            cin>>pos;

            start=deleteatpos(start,pos);
            break;

            case 16:
            cout<<"enter pos after which you want to delete the data "<<endl;
            cin>>pos;

            deleteafterpos(start,pos);
            break;

            case 17:
            cout<<"enter pos before which you want to delete the data "<<endl;
            cin>>pos;

            start=deletebeforepos(start,pos);
            break;

            case 18:
            start=reverse(start);
            break;

            case 19:
            cout<<"you have choosen exit"<<endl;
            exit(1);

            default:
            cout<<"wrong choice entered"<<endl;
                
        }
    }
}