#include<iostream>
#include<cstdlib>

using namespace std;

class node{
    public :
    int data;
    node *link;
};
node * addtoempty(node * last,int data){
    node *n=new node;
    n->data=data;

    n->link=NULL;
    last=n;
    last->link=last;

    return last;
}

node * addatbeg(node * last,int data){
    node *n=new node;
    n->data=data;

    n->link=last->link;
    last->link=n;
    
    return last;
}

node * addatend(node * last,int data){
    node *n=new node;
    n->data=data;

    n->link=last->link;
    last->link=n;
    last=n;

    return last;
}

node * create(node * last,int data){
    if(last==NULL){
        cout<<"empty list node will become first node"<<endl;
        last=addtoempty( last, data);
        return last;
    }
    cout<<"node will be added at end"<<endl;
    last=addatend(last,data);
    return last;

}

void display(node * last){
    
    if(last==NULL){
        cout<<"empty list"<<endl;
        return;
    }
    node *temp=last->link;
    cout<<"list is"<<endl;
    
    do{
        cout<<temp->data<<" ";
        temp=temp->link;
    }while(temp!=last->link);
    cout<<endl;
}

void count(node *last){
    int c=0;

    if(last==NULL)
        cout<<"empty list count is 0"<<endl;
    else{   
        node *temp=last->link;    
        do{
            c++;
            temp=temp->link;
        }while(temp!=last->link);
        cout<<" count is "<<c<<endl; 
    }  
}

void search(node *last,int data){
    node * temp=last->link;
    if(last==NULL){
        cout<<"empty list "<<endl;
        return;
    }
   do{
        if(temp->data==data){
            cout<<"data found"<<endl;
            return;
        }
        temp=temp->link;       
    } while(temp!=last->link);
    cout<<"data not found"<<endl;
}

node * addatpos(node * last,int data,int pos){
    if(last==NULL ){
        cout<<"empty list"<<endl;
        return last;
    }
    if(pos==1){
        addatbeg(last,data);
        return last;
    }   
    node * temp=last->link;   
    int point=1;

    node *n=new node;
    n->data=data;
    n->link=NULL;

    do{
        if(point==pos-1){
            n->link=temp->link;
            temp->link=n;
            if(temp==last){
               last=n; 
            }
            return last;
        }
        point++;
        temp=temp->link;
    }while(temp!=last->link);

    cout<<"pos not found"<<endl;
    return last;
}

node * delete1(node * last,int data){
    if(last==NULL){
        cout<<"empty list"<<endl;
        return last;
    }
    if(last->data==data && last->link==last){
        cout<<"list hass only one node and it will be deleted"<<endl;
        last=NULL;
        return last;
    }
    node * temp=last->link;
    do{
        if(last->link->data==data){
            last->link=last->link->link;
            return last;
        }
        if(temp->link->data==data){
            temp->link=temp->link->link;
            return last;
        }
        temp=temp->link;
    }while(temp!=last->link);

    cout<<"no data found"<<endl;
    return last;
}

node * deleteatpos(node * last,int pos){
    if(last==NULL){
        cout<<"list is empty no data to delete"<<endl;
        return last;
    }
    if(pos==1 && last->link==last){
            last=NULL;
            return last;
        }

    if(pos==1){
        last->link=last->link->link;
        return last;
    }

    node * temp=last->link;
    int point=1;
    do{
        if(point==pos-1){
            if(temp->link==last){
                temp->link=last->link;
                last=temp;
                return last;
            }
            temp->link=temp->link->link;
            // if(temp->link==last)
            //     last=temp;
            return last;
        }
        temp=temp->link;
        point++;
    }while(temp!=last->link);

    cout<<"no pos found to delete"<<endl;
    return last;
}

int main(){
    int data,choice,pos;
    node *last=NULL;
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
        cout<<"07 for add at pos"<<endl;
        cout<<"08 for delete the node"<<endl;
        cout<<"09 for delete data at pos "<<endl;
        cout<<"10 for reverse the list"<<endl;
        cout<<"11 for quit"<<endl;
        cout<<endl;
        cout<<"enter your choice"<<endl;
        cin>>choice;
        cout<<endl;

        switch(choice){
            case 1:
            cout<<"enter data"<<endl;
            cin>>data;
            last=create(last,data);
            break;

            case 2:
            display(last);
            break;

            case 3:
            count(last);
            break;

            case 4:
            cout<<"enter data to search"<<endl;
            cin>>data;

            search(last,data);
            break;

            case 5:
            cout<<"enter data to add  at beg"<<endl;
            cin>>data;

            last=addatbeg(last,data);
            break;

            case 6:
            cout<<"enter data to add at end"<<endl;
            cin>>data;

            last=addatend(last,data);
            break;

            case 7:
            cout<<"enter data to add at pos"<<endl;
            cin>>data;
            cout<<endl;
            cout<<"enter pos "<<endl;
            cin>>pos;

            last=addatpos(last,data, pos);
            break;

            case 8:
            cout<<"enter data to delete "<<endl;
            cin>>data;

            last=delete1(last, data);
            break;
          
            case 9:
            cout<<"enter pos at which you want to delete the node "<<endl;
            cin>>pos;

            last=deleteatpos(last,pos);
            break;
        
            // case 10:
            // last=reverse(last);
            // break;

            case 11:
            cout<<"you have choosen exit"<<endl;
            exit(1);

            default:
            cout<<"wrong choice entered"<<endl;
                
        }
    }
}