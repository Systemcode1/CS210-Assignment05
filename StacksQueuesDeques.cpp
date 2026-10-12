#include <iostream>       
using namespace std;

class ArrayStack{
private:
int data[10];
int count = 0;

public:
void push(int value){ // add value to the top of the stack
if(count == 10){
cout << "ERROR: stack is full" << endl;//tel user its full
return;

        }

data[count] = value;// put value in the next empty box
    count++;
    }

    void pop(){ /// remove the top item from the stack
        if(count ==0){
cout <<"Error: The stack is empty"<<endl;//tell user empty
return;
    }
count--;
}
int top(){
    if(count == 0){
cout << "ERROR: stack is empty" << endl;
        return -1;
    };return data[count -1];
}
bool isEmpty(){// True  stack has no items.
    return count == 0;
}
void print(){
    for(int i  = 0; i < count; i++)
 cout <<data[i] <<"";

cout << endl;
}
};
class ArrayQueue{
int data[10];// boxes that hold the queue items
int front = 0;
int count = 0;
public:

    void enqueue(int value){  
        if (count == 10){
        cout << "ERROR: queue is full" << endl;
return;
}
int back  = (front + count) % 10;
data[back] = value;
count++;
        }

       void dequeue(){ // Remove the front item
        if (count == 0){
    cout << "Error: Queue is empty"<< endl;
return;
        }
         front =(front + 1 )% 10;     // move fronts to the next item
         count --;
    }
    int peek(){
if(count ==0){
cout <<"Error: queue is empty"<< endl;
            return -1;
        }
return data[front];
    }
    bool isEmpty(){                     // true if the queue has no item
return count == 0;
    }
void print() {                                     
        for (int i = 0; i < count; i++) {              
cout << data[(front + i) % 10] << " ";     
        }
        cout << endl;                                  
}
};

class ArrayDeque{
private:
    int data[10];                    
int front = 0;
int count = 0;                  

public:
    void pushFront(int value){
if (count == 10){
            cout << "ERROR: deque is full" << endl;
            return;
        }
front = (front - 1 + 10) % 10;   
data[front] = value;
count++;
    }

    void pushBack(int value){            
        if (count == 10){
cout << "ERROR: deque is full" << endl;
            return;
        }
        int back = (front + count) % 10;  // next empty box after the last ite
data[back] = value;
        count++;
    }
// Remove the front item.
void popFront(){
        if (count == 0){
cout << "Error: deque is empty" << endl;
return;
        }
        front = (front + 1) % 10;
        count--;
    }

void popBack(){                     
if (count == 0){
cout << "Error: deque is empty" << endl;
return;
        }
        count--;
    }
// Return the front item
    int peekFront(){                     
        if (count == 0){
            cout << "Error: deque is empty" << endl;
return -1;
    }
return data[front];
    }

    int peekBack(){
        if (count == 0){
cout << "Error: deque is empty" << endl;
 return -1;
        }
        return data[(front + count - 1) % 10];
    }

    bool isEmpty(){
        return count == 0;               
    }

    void print(){
        for (int i = 0; i < count; i++){
 cout << data[(front + i) % 10] << " ";
        }
        cout << endl;
    }
};
    struct Node {
    int value;
Node* next;
Node* prev;
};
                                    
class LinkedStack {
    // top node; nullptr means empt
private:
    Node* head = nullptr;

public:
 void push(int value) {
        Node* n = new Node;
 n->value = value;
n->next = head;
        head = n;// new node become the top
    }

    void pop() {
        if (head == nullptr) {
            cout << "ERROR: stack is empty" << endl;
            return;
        }
Node* old = head;
head = head->next;// next node becomes the top
delete old;
    }

    int top() {
        if (head == nullptr) {
cout << "ERROR: stack is empty" << endl;
return -1;
        }
        return head->value;
    }
    // True if there are no nodes.

    bool isEmpty() {
return head == nullptr;
    }

    void print() {
        Node* cur = head;
        while (cur != nullptr) {
            cout << cur->value << " ";
            cur = cur->next;
        }
        cout << endl;
    }
};

class LinkedQueue {
private:
    Node* head = nullptr; // front andback  of the line
    Node* tail = nullptr;

public:
    void enqueue(int value) {
        Node* n = new Node;
        n->value = value; n->next = nullptr;
    if (tail == nullptr) {
            head = n;
 } else {
            tail->next = n;
        }
 tail = n;
    }

    void dequeue() {
        if (head == nullptr) {
 cout << "ERROR: queue is empty" << endl;
            return;
        }
        Node* old = head;
head = head->next;
if (head == nullptr) {  // queue now empty
            tail = nullptr;
        }
        delete old;
    }

    int peek() { //Returns -1 if empty.
        if (head == nullptr) {
    cout << "ERROR: queue is empty" << endl;
return -1;
}
return head->value;
    }

    bool isEmpty() {
return head == nullptr;
    }

    void print() {
Node* cur = head;  // Print items from front to back
while (cur != nullptr) {
cout << cur->value << " ";
cur = cur->next;
        }
        cout << endl;
    }
};

class LinkedDeque {
private:
 Node* head = nullptr;//front and back node
Node* tail = nullptr;

public:
    void pushFront(int value) {
        Node* n = new Node;
    n->value = value;
n->prev = nullptr;
n->next = head;
if (head == nullptr) {
tail = n;
} else {
            head->prev = n;
        }
        head = n;
    }

    void pushBack(int value) {
Node* n = new Node;
n->value = value;
n->next = nullptr;
        n->prev = tail; if (tail == nullptr) {
            head = n;
} else {
tail->next = n;
        }
tail = n;
    }

    void popFront() {// Remove the front
    if (head == nullptr) {
cout << "ERROR: deque is empty" << endl;
            return;
        }
 Node* old = head;
        head = head->next;
if (head == nullptr) {
tail = nullptr;
} else {
            head->prev = nullptr;
}
    delete old;
    }

    void popBack() {// Remove the back
        if (tail == nullptr) {
cout << "ERROR: deque is empty" << endl;
return;
        }
 Node* old = tail;
tail = tail->prev;
if (tail == nullptr) {
head = nullptr;
      } else {
tail->next = nullptr;
     }
delete old;
}

    int peekFront() {
        if (head == nullptr) {
            cout << "ERROR: deque is empty" << endl;
            return -1;
        }
       return head->value;
    }
    int peekBack() {
if (tail == nullptr) {
cout << "ERROR: deque is empty" << endl;
return -1;
        }
return tail->value;
    }
// True if there are no nodes
    bool isEmpty() {  return head == nullptr;
    }

void print() {/// the Prints item from front to back.
Node* cur = head;
 while (cur != nullptr) {
cout << cur->value << " ";
            cur = cur->next;
}
cout << endl;
    }
};

int main() {
    cout << "--- Array Stack ---" << endl;
    ArrayStack s;
s.pop();
    s.push(4);
    s.push(6);
 s.push(2);
    s.print();
    cout << "top: " << s.top() << endl;
s.pop();
s.push(9);
s.print();
  s.pop();
s.pop();
s.pop();
s.pop();
cout << "isEmpty: " << s.isEmpty() << endl;
cout << "--- Array Queue -" << endl;
ArrayQueue q;
    q.dequeue();
    q.enqueue(3);
   q.enqueue(7);
q.enqueue(9);   q.print();
    cout << "front: " << q.peek() << endl;
q.dequeue();
 q.enqueue(1);
q.print();    q.dequeue();
q.dequeue();
q.dequeue();
q.dequeue();
    cout << "isEmpty: " << q.isEmpty() << endl;

    cout << "--- Array Deque --" << endl;
    ArrayDeque d; d.popBack();
 d.pushBack(5);
    d.pushBack(6);
    d.pushFront(4);
    d.pushFront(3);
 d.print();
cout << "frot: " << d.peekFront() << ", back: " << d.peekBack() << endl;
d.popBack();
d.popFront();
d.print();
d.popFront();
d.popBack();
d.popFront();
 cout << "isEmpty: " << d.isEmpty() << endl;

    cout << "-- Linked Stack --" << endl;
LinkedStack ls;
    ls.pop();
    ls.push(4);
    ls.push(6);
    ls.push(2);
    ls.print();
    cout << "top: " << ls.top() << endl;
 ls.pop();
    ls.push(9);
    ls.print();
 ls.pop();
    ls.pop();
    ls.pop();    ls.pop();
    cout << "isEmpty: " << ls.isEmpty() << endl;

    cout << "--- Linked Queue --" << endl;
    LinkedQueue lq;
  lq.dequeue();
    lq.enqueue(3);
   lq.enqueue(7);
    lq.enqueue(9);
    lq.print();
    cout << "front: " << lq.peek() << endl;
    lq.dequeue();
    lq.enqueue(1);
 lq.print();
    lq.dequeue();
    lq.dequeue();
    lq.dequeue();
    lq.dequeue();
    cout << "isEmpty: " << lq.isEmpty() << endl;

    cout << "--- Linked Deque ---" << endl;
    LinkedDeque ld;
    ld.popBack();
 ld.pushBack(5);
    ld.pushBack(6);
 ld.pushFront(4);
    ld.pushFront(3);
    ld.print();
    cout << "front: " << ld.peekFront() << ", back: " << ld.peekBack() << endl;
    ld.popBack();
 ld.popFront();
    ld.print();
    ld.popFront();
    ld.popBack();
ld.popFront();
    cout << "isEmpy: " << ld.isEmpty() << endl;

    return 0;
}