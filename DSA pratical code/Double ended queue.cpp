#include<iostream>
using namespace std;

#define SIZE 5
int dq_arr[SIZE];
int front=-1;
int rear=-1;

void enqueue_front(int val){
    if((front==0&&rear==SIZE-1)||front==rear+1){
        cout<<"Queue is Full."<<endl;
        return;
    }
    if(front==-1){
        front=rear=0;
    }else if(front==0){
        front=SIZE-1;
    }else{
        front--;
    }
    dq_arr[front]=val;
    cout<<val<<" is inserted."<<endl;
}

void enqueue_rear(int val){
    if((front==0&&rear==SIZE-1)||front==rear+1){
        cout<<"Queue is Full."<<endl;
        return;
    }
    if(front==-1){
        front=rear=0;
    }else if(rear==SIZE-1){
        rear=0;
    }else{
        rear++;
    }
    dq_arr[rear]=val;
    cout<<val<<" is inserted."<<endl;
}

void dequeue_front(){
    if(front==-1){
        cout<<"Queue is Empty."<<endl;
        return;
    }
    cout<<dq_arr[front]<<" is deleated."<<endl;
    if(front==rear){
        front=rear=-1;
    }else if(front==SIZE-1){
        front=0;
    }else{
        front++;
    }
}

void dequeue_rear(){
    if(front==-1){
        cout<<"Queue is Empty."<<endl;
        return;
    }
    cout<<dq_arr[rear]<<" is deleated."<<endl;
    if(front==rear){
        front=rear=-1;
    }else if(rear==0){
        rear=SIZE-1;
    }else{
        rear--;
    }
}

void display(){
    if(front==-1){
        cout<<"Queue is Empty."<<endl;
        return;
    }
    for(int i=front;;i=(i+1)%SIZE){
        cout<<dq_arr[i]<<" ";
        if(i==rear) break;
    }
    cout<<endl;
}

int main(){
    int choice;
    do {
        cout<<"\n--- Menu ---\n";
        cout<<"1. Enqueue Front\n";
        cout<<"2. Enqueue Rear\n";
        cout<<"3. Dequeue Front\n";
        cout<<"4. Dequeue Rear\n";
        cout<<"5. Display\n";
        cout<<"6. Exit\n";
        cout<<"Enter choice: ";

        if(!(cin >> choice)){                
            cin.clear();
            cin.ignore(10000,'\n');
            cout<<"Invalid input. Try again."<<endl;
            continue;
        }

        switch(choice){
            case 1: {
                int val;
                cout<<"Enter value to insert at front: ";
                if(!(cin>>val)){
                    cin.clear();
                    cin.ignore(10000,'\n');
                    cout<<"Invalid input."<<endl;
                } else {
                    enqueue_front(val);
                }
                break;
            }
            case 2: {
                int val;
                cout<<"Enter value to insert at rear: ";
                if(!(cin>>val)){
                    cin.clear();
                    cin.ignore(10000,'\n');
                    cout<<"Invalid input."<<endl;
                } else {
                    enqueue_rear(val);
                }
                break;
            }
            case 3:
                dequeue_front();
                break;
            case 4:
                dequeue_rear();
                break;
            case 5:
                display();
                break;
            case 6:
                cout<<"Exiting."<<endl;
                break;
            default:
                cout<<"Invalid choice."<<endl;
        }
    } while(choice!=6);

    return 0;
}


/*

--- Menu ---
1. Enqueue Front
2. Enqueue Rear
3. Dequeue Front
4. Dequeue Rear
5. Display
6. Exit
Enter choice: 1
Enter value to insert at front: 45
45 is inserted.

--- Menu ---
1. Enqueue Front
2. Enqueue Rear
3. Dequeue Front
4. Dequeue Rear
5. Display
6. Exit
Enter choice: 2
Enter value to insert at rear: 65
65 is inserted.

--- Menu ---
1. Enqueue Front
2. Enqueue Rear
3. Dequeue Front
4. Dequeue Rear
5. Display
6. Exit
Enter choice: 1
Enter value to insert at front: 85
85 is inserted.

--- Menu ---
1. Enqueue Front
2. Enqueue Rear
3. Dequeue Front
4. Dequeue Rear
5. Display
6. Exit
Enter choice: 2
Enter value to insert at rear: 95
95 is inserted.

--- Menu ---
1. Enqueue Front
2. Enqueue Rear
3. Dequeue Front
4. Dequeue Rear
5. Display
6. Exit
Enter choice: 5
85 45 65 95

--- Menu ---
1. Enqueue Front
2. Enqueue Rear
3. Dequeue Front
4. Dequeue Rear
5. Display
6. Exit
Enter choice: 4
95 is deleated.

--- Menu ---
1. Enqueue Front
2. Enqueue Rear
3. Dequeue Front
4. Dequeue Rear
5. Display
6. Exit
Enter choice: 3
85 is deleated.

--- Menu ---
1. Enqueue Front
2. Enqueue Rear
3. Dequeue Front
4. Dequeue Rear
5. Display
6. Exit
Enter choice: 5
45 65

--- Menu ---
1. Enqueue Front
2. Enqueue Rear
3. Dequeue Front
4. Dequeue Rear
5. Display
6. Exit
Enter choice: 6
Exiting.
*/
