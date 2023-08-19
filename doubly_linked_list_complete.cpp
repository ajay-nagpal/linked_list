#include<iostream>
#include<cstdlib> 

using namespace std;

class node{
    public:

    int data;
    node *next;
    node *prev;
};
node * addtoempty(node * start,int data){
    node * n=new node;

    n->data=data;
    n->next=NULL;
    n->prev=NULL;

    start=n;
    return start;
}

node * addatbeg(node * start,int data){
    node * n=new node;

    n->data=data;
    n->next=start;
    n->prev=NULL;

    start->prev=n;
    start=n;
    return start;
}

void addatend(node * start,int data){
    node * n=new node;
    n->data=data;
    n->next=NULL;
    n->prev=NULL;

    node * temp=start;
    while(temp->next!=NULL){
        temp=temp->next;
    }
    temp->next=n;
    n->prev=temp;
}

node *create(node * start,int data){
    if(start==NULL){
        cout<<"list is empty so node will be addded at beg"<<endl;
        
        start=addtoempty(start,data);
        return start;
    }
    cout<<"node will be added at end"<<endl;
    addatend(start,data);

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
        temp=temp->next;
    }
    cout<<endl;
}

int count(node *start){
    int c=0;
    
    node *temp=start;
    while(temp!=NULL){
        c++;
        temp=temp->next;
    }
    
    cout<<" up to this moment count is "<<c<<endl; 
    return c;  
}

void search(node *start,int data){
    node * temp=start;
    while(temp!=NULL){
        if(temp->data==data){
            cout<<"data found"<<endl;
            return;
        }
        temp=temp->next;       
    }
    cout<<"data not found"<<endl;
}

void addafter(node * start,int data,int item){
    node * n=new node;

    n->data=data;

    node * temp=start;
    while(temp!=NULL){
        if(temp->data==item){
             n->next=temp->next;

            if(temp->next!=NULL)
                temp->next->prev=n;

             temp->next=n;
             n->prev=temp;
             return;
        }
        temp=temp->next;
    }
    cout<<"data not found"<<endl;
}

node * addbefore(node * start,int data,int item){
    node * n=new node;

    n->data=data;

    node * temp=start;
    while(temp!=NULL){
        if(temp->data==item){
             if(temp->prev!=NULL)
                temp->prev->next=n;
            else
                start=n;

             n->prev=temp->prev;
             n->next=temp;
             temp->prev=n;

             return start;
        }
        temp=temp->next;
    }
    cout<<"data not found"<<endl;
    return start;
}

node * addatpos(node * start,int data ,int pos){
    if(start==NULL){
        cout<<"list is empty"<<endl;
        return start;
    }
    if(pos==1 ){
        cout<<"list only has one node so new node will become start"<<endl;
        start=addatbeg(start,data);
        return start;
    }
    
    int point=2;

    node *n=new node;
    n->data=data;

    node * temp=start->next;
    while(temp!=NULL){
        if(pos==count(start)+1){
           addatend(start,data);
           return start;
        }
        if(point==pos){
           n->prev=temp->prev;
           temp->prev->next=n;
           n->next=temp;
           temp->prev=n;
           
            return start;
        }
       
        point++;
        temp=temp->next;   
    }
    cout<<"pos not found"<<endl;
    return start;
}

void addafterpos(node * start,int data ,int pos){
    if(start==NULL){
        cout<<"list is empty"<<endl;
        return ;
    }
    
    int point=1;

    node *n=new node;
    n->data=data;

    node * temp=start;
    while(temp!=NULL){

        if(point==pos){
            n->next=temp->next;
            n->prev=temp;
            if(temp->next!=NULL)
                n->next->prev=n;
           temp->next=n;
           return ;
        }
       
        point++;
        temp=temp->next;   
    }
    cout<<"pos not found"<<endl;
}

node * addbeforepos(node * start,int data ,int pos){
    if(start==NULL){
        cout<<"list is empty"<<endl;
        return start;
    }
    if(pos==1 ){
        cout<<"list only has one node so new node will become start"<<endl;
        start=addatbeg(start,data);
        return start;
    }
    
    int point=1;

    // node *n=new node;
    // n->data=data;

    node *n=new node;
    n->data=data;

    int c=count(start);
    node * temp=start;
    while(temp!=NULL){
        if(pos>c){
            cout<<"this pos is not in list"<<endl;
            return start;
        }
        if(point==pos-1){
             n->next=temp->next;
            n->prev=temp;
            if(temp->next!=NULL)
                n->next->prev=n;
           temp->next=n;
            return start;
        }

        point++;
        temp=temp->next;   
    }
    cout<<"pos not found"<<endl;
    return start;
}

node * delete1(node * start,int data){
    if(start->next==NULL && start->data==data){
        cout<<"there is only one node in list to delete"<<endl;
        start=NULL;
        return start;
    }
    if(start->next!=NULL && start->data==data){
        cout<<"1st node will be deleted"<<endl;
        start->next->prev=NULL;
        start=start->next;
        return start;
    }
    node * temp=start;
    while(1){
        if(temp->data==data){
            temp->prev->next=temp->next;
            if(temp->next!=NULL)
                temp->next->prev=temp->prev;
            temp->prev=NULL;    

            return start;
        }
        temp=temp->next;
    }
    cout<<"no data found"<<endl;
    return start;
}

void deleteafter(node * start,int data){
    if(start==NULL ){
        cout<<"there is mo node to delete"<<endl;
        return ;
    }
    if(start->next==NULL && start->data==data ){
        cout<<"there is mo node to delete"<<endl;
        return ;
    }


    node * temp=start;
    // while(temp->data!=data)
    //     temp=temp->next;
    // temp=temp->next;

    // temp->prev->next=temp->next;
    // if(temp->next!=NULL)
    //     temp->next->prev=temp->prev;
    // temp->prev=NULL;    

    while(temp!=NULL){
        if(temp->data==data && temp->next!=NULL){
            temp=temp->next;

            temp->prev->next=temp->next;
            if(temp->next!=NULL)
                temp->next->prev=temp->prev;
            temp->prev=NULL;    

            return;
        }
        temp=temp->next;
    }
    cout<<"no data found"<<endl;
}

node * deletebefore(node * start,int data){
    if(start->data==data ){
        cout<<"there is mo node to delete"<<endl;
        return start ;
    }

    node * temp=start;
    while(temp!=NULL){
        if(temp->data==data){
            temp=temp->prev;
            if(temp==start){
                cout<<"1st node will be deleted"<<endl;

            start->next->prev=NULL;
            start=start->next;

            return start;
            }
            else{
                temp->prev->next=temp->next;
                if(temp->next!=NULL)
                    temp->next->prev=temp->prev;
                temp->prev=NULL;    

                return start;
            }  
        }
        temp=temp->next;
    }
    cout<<"no data found"<<endl;
    return start;
}

node * deleteatpos(node * start,int pos){
    if(start->next==NULL && pos==1){
        cout<<"there is only one node in list to delete"<<endl;
        start=NULL;
        return start;
    }
    if(start->next!=NULL && pos==1){
        cout<<"1st node will be deleted"<<endl;
        start->next->prev=NULL;
        start=start->next;
        return start;
    }
    node * temp=start;
    int point=1;

    while(temp!=NULL){
        if(point==pos){
            temp->prev->next=temp->next;
            if(temp->next!=NULL)
                temp->next->prev=temp->prev;
            temp->prev=NULL;    

            return start;
        }
        point++;
        temp=temp->next;
    }
    cout<<"no pos found"<<endl;
    return start;
}

void deleteafterpos(node * start,int pos){
    if(start==NULL ){
        cout<<"there is mo node to delete"<<endl;
        return ;
    }
    if(start->next==NULL && pos==1){
        cout<<"there is mo node to delete"<<endl;
        return ;
    }


    node * temp=start;
    // while(temp->data!=data)
    //     temp=temp->next;
    // temp=temp->next;

    // temp->prev->next=temp->next;
    // if(temp->next!=NULL)
    //     temp->next->prev=temp->prev;
    // temp->prev=NULL;    

    int point=1;

    while(temp!=NULL){
        if(point==pos && pos<count(start)){
            temp=temp->next;

            temp->prev->next=temp->next;
            if(temp->next!=NULL)
                temp->next->prev=temp->prev;
            temp->prev=NULL;    

            return;
        }
        temp=temp->next;
        point++;
    }
    cout<<"no pos found or nothing to delete"<<endl;
}

node * deletebeforepos(node * start,int pos){
    if((start->next==NULL||start->next!=NULL) && pos==1){
        cout<<"there is no node to delete"<<endl;
        return start;
    }
    
    node * temp=start;
    int point=1;

    while(temp!=NULL){
        if(point==pos-1){
            temp->prev->next=temp->next;
            if(temp->next!=NULL)
                temp->next->prev=temp->prev;
            temp->prev=NULL;    

            return start;
        }
        point++;
        temp=temp->next;
    }
    cout<<"no pos found"<<endl;
    return start;
}

node * reverse(node * start){
    
}

int main(){
    int data,choice,pos,item,c;
    node *start;
    while(1){
        cout<<endl;
        cout<<"given choices"<<endl;
        cout<<endl;
        cout<<"01 for create list"<<endl;
        cout<<"02 for display"<<endl;
        cout<<"03 for count"<<endl;
        cout<<"04 for search "<<endl;
        cout<<"05 for add at beg"<<endl;
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
            cout<<"enter data to add"<<endl;
            cin>>data;
            start=create(start,data);
            break;

            case 2:
            display(start);
            break;

            case 3:
            c=count(start);
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