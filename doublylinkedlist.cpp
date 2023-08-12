#include<iostream>
#include<stdio.h>
using namespace std;
struct node{
	struct node* pre;
	int data;
	struct node* next;
};
struct node* head;
void insert(){
	struct node* temp,*ptr;
	temp=(struct node*)malloc(sizeof(struct node));
	int value,pos;

	if(temp==NULL){
		cout<<"overflow";
	}
	else{
		cout<<"Enter Node Data-:";
		cin>>value;
		temp->data=value;
		temp->pre=NULL;
		if(head==NULL){
			temp->next=NULL;
			head=temp;
			cout<<"Inserted Value";
		}
		else{
			temp->next=head;
			head->pre=temp;
			head=temp;
			cout<<"Inserted Value";
		}
	}
}
void del(){
struct node* temp,*ptr;
	int x;
	cout<<"Enter Deletion Node Postion ";
	cin>>x;
	if(head==NULL){
		cout<<"Node are Empty";
	}
	else{
		ptr=head;
		for(int i=0;i<x;i++){
			temp=ptr;
			ptr=ptr->next;
		}
		temp->next=ptr->next;
		free(ptr);
	}
}
void show(){
	struct node*ptr,*temp;
	temp=head;
	while(temp->next!=NULL){
			ptr=temp;
		temp=temp->next;
	
		cout<<ptr->data;
	}
	cout<<temp->data;
}
int main(){
	int choice =0;  
    while(choice != 9)   
    {  
        cout<<"\nChoose one option from the following list ...\n";  
        cout<<"\n1.Insert\n2.Delete\n3.Show\n4.Exit";  
        cout<<"\nEnter your choice?\n";         
        cin>>choice;  
        switch(choice)  
        {  
            case 1:
            	insert();
            	break;
            case 2:
        		del();
        		break;
        	case 3:
    			show();
				break;
            case 4:  
                exit(0);  
                break;  
            default:  
            cout<<"Please enter valid choice..";
   }
  }
  return 0;
}