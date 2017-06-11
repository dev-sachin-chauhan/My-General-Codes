/*****************************************************************************************/
#include <iostream>
#include <exception>
#include <limits.h>
#include <new>
using namespace std;

#ifndef STACK_H
#define STACK_H
class StackEmpty: public exception
{
    // Exception class - throw an object of this type when stack is empty
    // Hint: there is no code for exception classes
    virtual const char* what() const throw()
    {
        return "Stack is Empty Exception";
    }
};

class StackFull: public exception
{
    // Exception class - throw an object of this type when stack is full
    virtual const char* what() const throw()
    {
        return "Stack is Full Exception";
    }
};
class StackInvalidPeek: public exception
{
    // Exception class - throw an object of this type when invalid peek position is used
    virtual const char* what() const throw()
    {
        return "Stack Invalid Peek Excpetion";
    }
};

class Stack                // Models stack of integers ADT implemented as a dynamically allocated array
{
private:
    int* array;            // Points to the stack array
    int  num;              // Holds max number of elements that may be stored in stack array
    int  top;              // Holds the index of the top data value stored on the stack
    void Resize(int n);    // Attempts to increase size of stack array to 2*num and then push n onto stack
    // If unable to resize, throw StackFull exception
    
public:
    Stack(int n);          // Parameterized constructor dynamically allocates an empty stack array
    // that may hold no more than n elements and initializes other private variables
    
    ~Stack();              // Destructor deallocates all dynamically-allocated memory
    // associated with the object
    void Push(int n);      // Pushes integer n onto top of stack.  If stack is full, attempts to
    // resize stack and then push n.  If unable to resize, throws StackFull exception.
    void Pop();            // Removes top integer from stack
    // If stack is empty, throws StackEmpty exception
    bool IsEmpty() const;  // Returns true if stack is empty; false otherwise
    
    bool IsFull() const;   // Returns true if stack is full; false otherwise
    
    void MakeEmpty();      // Removes all items from stack leaving an empty, but usable stack with capacity num
    // If stack is already empty, MakeEmpty() does nothing
    
    int Top() const;       // Returns value of top integer on stack WITHOUT modifying the stack
    // If stack is empty, throws StackEmpty exception
    int Size() const;      // Returns number of items on stack WITHOUT modifying the stack
    
    int Max() const;       // Returns value of largest integer on stack WITHOUT modifying the stack
    // If stack is empty, throws StackEmpty
    int Min() const;       // Returns value of smallest integer on stack WITHOUT modifying the stack
    // If stack is empty, throws StackEmpty
    int Peek(unsigned int n) const; // Returns stack value n levels down from top of stack. Peek(0) = Top()
    // If position n does not exist, throws StackInvalidPeek
    
    int Capacity() const;  // Returns total num of elements that maybe stored in stack array
    
    /*******  DO NOT MODIFY ANY OF THE CODE FOR PRINT()             *******/
    /******   DO NOT PLACE A COPY OF PRINT() CODE IN STACK.CPP!!!   *******/
    
    void Print() const     // Writes stack contents to stdout, separated by a space, followed by endl
    {
        int index = top;
        cout << "Top { ";
        
        while (index != -1)
        {
            cout << array[index] << " ";
            index--;
        }
        cout << "} Bottom" << endl;
    } // End Print()
    
};  // End Class Stack

void Stack::Resize(int n) {
    int *temp = NULL;
    try {
        temp = new int[2*num];
    } catch (std::bad_alloc& bd) {
        throw StackFull();
        return;
    }
    
    for(int i=0;i<num;i++){
        temp[i] = array[i];
    }
    temp[num] = n;
    top = num;
    num = 2*num;
    delete [] array;
    array = temp;
}

Stack::Stack(int n) {
    num = n;
    array = new int[n];
    top = -1;
}

Stack::~Stack(void) {
    delete [] array;
}

void Stack::Push(int n) {
    if(IsFull()){
        Resize(n);
    }else{
        array[++top] = n;
    }
}

void Stack::Pop() {
    if(IsEmpty()){
        throw StackEmpty();
    }else{
        top--;
    }
}

bool Stack::IsEmpty() const{
    if(top == -1){
        return true;
    }else{
        return false;
    }
}

bool Stack::IsFull() const{
    if(top == num-1){
        return true;
    }else{
        return false;
    }
}

void Stack::MakeEmpty() {
    if(IsEmpty()){
        return;
    }
    top = -1;
}

int Stack::Top() const{
    if(IsEmpty()) {
        throw StackEmpty();
    }else{
        return array[top];
    }
    return -1;
}

int Stack::Size() const {
    return top+1;
}

int Stack::Max() const{
    int max=INT_MIN;
    if(IsEmpty()) {
        throw StackEmpty();
    }
    for(int i=0;i<=top;i++){
        if(array[i]>max){
            max = array[i];
        }
    }
    return max;
    
}

int Stack::Min() const{
    int min=INT_MAX;
    if(IsEmpty()) {
        throw StackEmpty();
    }
    for(int i=0;i<=top;i++){
        if(array[i]<min){
            min = array[i];
        }
    }
    return min;
}

int Stack::Peek(unsigned int n) const{
    if(top+1 <= n){
        throw StackInvalidPeek();
        return -1;
    }else{
        return array[top-n];
    }
}

int Stack::Capacity() const {
    return num;
}

#endif
/*********************************************************************************************/
