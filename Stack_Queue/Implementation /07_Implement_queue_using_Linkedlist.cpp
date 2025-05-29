/*
Implement a First-In-First-Out (FIFO) queue using a singly linked list. 
Link : https://takeuforward.org/plus/dsa/stack-and-queues/implementation/implement-queue-using-linkedlist
*/
class Node{
    public:
    int val ;
    Node * next;
    Node(int data){
        val = data;
        next = nullptr;
    }
};
class LinkedListQueue {
    Node* front;
    Node * rear;
    int size;
public:
    LinkedListQueue() {
        front = nullptr;
        rear = nullptr;
        size = 0;
    }
    
    void push(int x) {
        Node * newNode = new Node(x);
        if(isEmpty()){
            front = newNode;
            rear = newNode;
        }
        else{
            rear->next = newNode;
            rear = rear->next;
        }
        size++;
    }
    
    int pop() {
        // check is queue already empty.
        if(isEmpty()){
            throw underflow_error("Queue underflow!");
        }

        // value to be return.
        int data = front->val;
        
        // temp node to delete memory space of poped node.
        Node * temp = front;

        front = front->next;
        if(front==nullptr)rear = nullptr;
        delete temp;
        // update the size of the queueu.
        size--;
        return data;
    }
    
    int peek() {
        // check is queue already empty.
        if(isEmpty()){
            throw underflow_error("Queue underflow!");
        }
        return front->val;
    }
    
    bool isEmpty() {
        return size==0;
    }
};
