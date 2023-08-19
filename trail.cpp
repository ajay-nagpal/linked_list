#include<iostream>
#include<cstdlib>

using namespace std;

class node{
    public:
    int data;
    node *link;
};

int main(){

    node c1,c2;
    node *start;
    start=NULL;

    
     c1.data=10;
    c2.data=20;

    start=&c1;

    c1.link=&c2;
   
    c2.link=NULL;
    
    cout<<start->link->data<<endl;
}