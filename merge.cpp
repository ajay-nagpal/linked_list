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

node * create(node * start){
    int n,data;
    cout<<"enter the number of nodes i the list"<<endl;
    cin>>n;
    for(int i=1;i<=n;i++){
        cout<<"enter the data"<<endl;
        cin >>data;
        start=insertsort(start,data);
    }
      return start;
}
node * insert(node *start,int data){
    node * n=new node;
    n->data=data;
    n->link=NULL;

    if(start==NULL){
        start=n;
        return start;
    }
    node * temp=start;
    while(temp->link!=NULL){
        temp=temp->link;
    }
    temp->link=n;
    return start;

}
// node * merge(node * p1,node * p2){
//     node * start3=NULL;

//     while(p1!=NULL && p2 !=NULL){
//         if(p1->data<p2->data){
//             start3=insert(start3,p1->data);
//             p1=p1->link;
//         }
//         else if(p1->data>p2->data){
//             start3=insert(start3,p2->data);
//             p2=p2->link;
//         }
//         else if(p1->data==p2->data){
//             start3=insert(start3,p1->data);
//             p1=p1->link;
//             p2=p2->link;
//         }
//     }
//     while(p1!=NULL){
//         start3=insert(start3,p1->data);
//         p1=p1->link;
//     }
//     while(p2!=NULL){
//         start3=insert(start3,p2->data);
//         p2=p2->link;
//     }
//     cout<<"merge list is"<<endl;
//     display(start3);
//     return start3;
// }

node * merge(node * p1,node * p2){
    node * start3=NULL;

    while(p1!=NULL && p2 !=NULL){
        if(p1->data<p2->data){
            start3=insert(start3,p1->data);
            p1=p1->link;
        }
        else if(p1->data>p2->data){
            start3=insert(start3,p2->data);
            p2=p2->link;
        }
        else if(p1->data==p2->data){
            start3=insert(start3,p1->data);
            start3=insert(start3,p2->data);

            p1=p1->link;
            p2=p2->link;
        }
    }
    while(p1!=NULL){
        start3=insert(start3,p1->data);
        p1=p1->link;
    }
    while(p2!=NULL){
        start3=insert(start3,p2->data);
        p2=p2->link;
    }
    cout<<"merge list is"<<endl;
    display(start3);
    return start3;
}
node * concat(node * start1, node * start2){
    if(start1==NULL && start2==NULL){
        return start1;
    }
    if(start2==NULL){
        return start1;
    }
    if(start1==NULL){
        return start2;
    }
    node * temp=start1;
    while(temp->link!=NULL)
        temp=temp->link;

        temp->link=start2;
        return start1;
}
int main(){
    int data,choice,pos,item;
    node *start1=NULL,*start2=NULL,*start3=NULL;
    while(1){
        cout<<endl;
        cout<<"given choices"<<endl;
        cout<<endl;
        cout<<"01 for create list"<<endl;
        cout<<"02 for display"<<endl;
       
        cout<<"03 for merge "<<endl;
        cout<<"04 for concat "<<endl;

        cout<<"05 for quit"<<endl;
        cout<<endl;
        cout<<"enter your choice"<<endl;
        cin>>choice;
        cout<<endl;

        switch(choice){
            case 1:
            
            start1=create(start1);
            start2=create(start2);
            break;

            case 2:
            cout<<"list 1 is"<<endl;
            display(start1);
            cout<<endl;
            cout<<"list 2 is"<<endl;
            display(start2);
            
            break;

            case 3:
            start3=merge(start1,start2);
            break;

            case 4:
            start1=concat(start1,start2);
            break;

            case 5:
            cout<<"you have choosen exit"<<endl;
            exit(1);

            default:
            cout<<"wrong choice entered"<<endl;
                
        }
    }
}