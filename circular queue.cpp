#include <iostream>
using namespace std;
int queue[100], n = 100, front = - 1, rear = - 1;
void Insert() {
   int val;
   if ((front==0 && rear == n - 1) || (front==rear +1))
   cout<<"Queue Overflow"<<endl;
   
   else {
      if (front == - 1)
      front = 0;
      cout<<"Insert the element in queue : "<<endl;
      cin>>val;
      rear=(rear+1)%n;
      queue[rear] = val;
   }
}
void Delete() {
   if (front == - 1) {
      cout<<"Queue Underflow ";
      return ;
   } else {
     int val=queue[front];
     if(front==rear){
       front=-1;
       rear=-1;
     }
     else
        front=(front+1)%n;
      cout<<"Element deleted from queue is : "<< val <<endl;
      
   }
}
void Display() {
   if (front == - 1)
   cout<<"Queue is empty"<<endl;
   else {
cout<<"Queue elements are : ";
      for (int i = front; i !=rear; i=(i+1)%n)
      cout<<queue[i]<<" ";
         cout<<endl;
   }
   
}
int main() {
   int ch;
   cout<<"1) Insert element to cir queue"<<endl;
   cout<<"2) Delete element from  cir queue"<<endl;
   cout<<"3) Display all the elements of cir queue"<<endl;
   cout<<"4) Exit"<<endl;
   do {
      cout<<"Enter your choice : "<<endl;
      cin>>ch;
      switch (ch) {
         case 1: Insert();
         break;
         case 2: Delete();
         break;
         case 3: Display();
         break;
         case 4: cout<<"Exitting the program !"<<endl;
         break;
         default: cout<<"Invalid choice"<<endl;
      }
   } while(ch!=4);
return 0;
}