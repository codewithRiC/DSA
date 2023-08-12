#include <stdio.h>
#include <iostream>
#include <stdlib.h>
using namespace std;
struct node {
	int info;
	struct node* link;
};
struct node* start = NULL;

void createList()
{
	if (start == NULL) {
		int n;
		cout<<"\nEnter the number of nodes: ";
		cin>>n;
		if (n != 0) {
			int data;
			struct node* newnode;
			struct node* temp;
			newnode =(struct node*) malloc(sizeof(struct node));
			start = newnode;
			temp = start;
			cout<<"\nEnter number to be inserted : ";
			cin>>data;
			start->info = data;

			for (int i = 2; i <= n; i++) {
				newnode =(struct node*) malloc(sizeof(struct node));
				temp->link = newnode;
				cout<<"\nEnter number to be inserted : ";
				cin>>data;
				newnode->info = data;
				temp = temp->link;
			}
		}
		cout<<"\nThe list is created\n";
	}
	else
		cout<<"\nThe list is already created\n";
}

void traverse()
{
	struct node* temp;

	if (start == NULL)
		cout<<"\nList is empty\n";
	else {
		temp = start;
		while (temp != NULL) {
			cout<< temp->info<<" ";
			temp = temp->link;
		}
	}
}
void insertAtFront()
{
	int data;
	struct node* temp;
	temp = (struct node*)malloc(sizeof(struct node));
	cout<<"\nEnter number to be inserted : ";
	cin>>data;
	temp->info = data;

	temp->link = start;
	start = temp;
}

void insertAtEnd()
{
	int data;
	struct node *temp, *head;
	temp = (struct node*)malloc(sizeof(struct node));
	cout<<"\nEnter number to be inserted : ";
	cin>>data;
	temp->link = 0;
	temp->info = data;
	head = start;
	while (head->link != NULL) {
		head = head->link;
	}
	head->link = temp;
}

void insertAtPosition()
{
	struct node *temp, *newnode;
	int pos, data, i = 1;
	newnode = (struct node*)malloc(sizeof(struct node));
	cout<<"\nEnter position and data :";
	cin>>pos>>data;

	temp = start;
	newnode->info = data;
	newnode->link = 0;
	while (i < pos - 1) {
		temp = temp->link;
		i++;
	}
	newnode->link = temp->link;
	temp->link = newnode;
}

void deleteFirst()
{
	struct node* temp;
	if (start == NULL)
		cout<<"\nList is empty\n";
	else {
		temp = start;
		start = start->link;
		free(temp);
	}
}
void deleteEnd()
{
	struct node *temp, *prevnode;
	if (start == NULL)
		cout<<"\nList is Empty\n";
	else {
		temp = start;
		while (temp->link != 0) {
			prevnode = temp;
			temp = temp->link;
		}
		free(temp);
		prevnode->link = 0;
	}
}

void deletePosition()
{
	struct node *temp, *position;
	int i = 1, pos;
	if (start == NULL)
		cout<<"\nList is empty\n";

	else {
		cout<<"\nEnter index : ";
		cin>>pos;
		position = (struct node*)malloc(sizeof(struct node));
		temp = start;

		while (i < pos - 1) {
			temp = temp->link;
			i++;
		}
position = temp->link;
		temp->link = position->link;
		free(position);
	}
}


int main()
{
	int choice;
	while (1) {

		cout<<"\n\t1 To see list\n";
		cout<<"\t2 For insertion at starting\n";
		cout<<"\t3 For insertion at end\n";
		cout<<"\t4 For insertion at any position\n";
		cout<<"\t5 For deletion of first element\n";
        cout<<"\t6 For deletion of last element\n";
		cout<<"\t7 For deletion of element at any position\n";
		cout<<"\t8 To exit\n";
		cout<<"\nEnter Choice :\n";
		cin>>choice;

		switch (choice) {
		case 1:
			traverse();
			break;
		case 2:
			insertAtFront();
			break;
		case 3:
			insertAtEnd();
			break;
		case 4:
			insertAtPosition();
			break;
		case 5:
			deleteFirst();
			break;
		case 6:
			deleteEnd();
			break;
        case 7:
			deletePosition();
			break;
		case 8:
			exit(1);
			break;
		default:
			cout<<"Incorrect Choice\n";
		}
	}
	return 0;
}