/*************************************************************************************************/
#include <iostream>
#include <string>
#include <assert.h>
using namespace std;

struct Node
{
    string element;
    struct Node *next;
    struct Node *prev;
};

class SDLL {
private:
    int size;
    struct Node *head;
    
public:
    SDLL();
    ~SDLL();
    bool isEmpty()const;
    void addToHead(string element);
    void addToTail(string element);
    string deleteFromHead();
    string deleteFromTail();
    void deleteNode(string element);
    bool isInList(string val)const;
    void printAll()const;
    void removeDuplicates();
    void reverse();
    int getSize();
    string& operator[](const int i);
};

SDLL::SDLL() {
    head = NULL;
    size = 0;
}

SDLL::~SDLL() {
    struct Node *temp;
    while(head!=NULL) {
        temp = head;
        head = head->next;
        delete temp;
    }
    head = NULL;
    size = 0;
}

bool SDLL::isEmpty() const{
    if(size == 0){
        return true;
    }else{
        return false;
    }
}

void SDLL::addToHead(string element) {
    struct Node *temp;
    temp = new(struct Node);
    temp->prev = NULL;
    temp->element = element;
    if (head == NULL)
    {
        head = temp;
        return;
    }
    temp->next = head;
    head->prev = temp;
    head = temp;
    cout<<"Element Inserted at Head"<<endl;
}

void SDLL::addToTail(string element) {
    struct Node *temp, *travesal;
    temp = new(struct Node);
    temp->next = NULL;
    temp->element = element;
    if (head == NULL)
    {
        head = temp;
        size++;
        return;
    }
    travesal = head;
    while(travesal->next !=NULL) {
        travesal = travesal->next;
    }
    travesal->next = temp;
    temp->prev = travesal;
    size++;
    cout<<"Element Inserted at Tail"<<endl;
}

string SDLL::deleteFromHead() {
    if (head == NULL)
    {
        cout<<"list is empty."<<endl;
        return NULL;
    }
    
    struct Node *temp;
    temp = head;
    head = head->next;
    head->prev = NULL;
    
    string element = temp->element;
    delete temp;
    size--;
    cout<<"Element deleted at Head"<<endl;
    return element;
}

string SDLL::deleteFromTail() {
    if (head == NULL)
    {
        cout<<"list is empty."<<endl;
        return NULL;
    }
    struct Node *temp, *travesal;
    travesal = head;
    while(travesal->next !=NULL) {
        travesal = travesal->next;
    }
    temp = travesal->prev;
    temp->next = NULL;
    
    string element = travesal->element;
    delete travesal;
    size--;
    cout<<"Element deleted at Tail"<<endl;
    return element;
}

void SDLL::deleteNode(string element) {
    struct Node *temp, *q;
    
    /*first element deletion*/
    if (head->element == element)
    {
        temp = head;
        head = head->next;
        head->prev = NULL;
        cout<<"Element Deleted"<<endl;
        free(temp);
        size--;
        return;
    }
    
    q = head;
    while (head->next->next != NULL)
    {
        /*Element deleted in between*/
        if (q->next->element == element)
        {
            temp = q->next;
            q->next = temp->next;
            temp->next->prev = q;
            
            cout<<"Element Deleted"<<endl;
            free(temp);
            size--;
            return;
        }
        q = q->next;
    }
    
    /*last element deleted*/
    if (q->next->element == element)
    {
        temp = q->next;
        free(temp);
        size--;
        q->next = NULL;
        cout<<"Element Deleted"<<endl;
        return;
    }
    
    cout<<"Element "<<element<<" not found"<<endl;
}

bool SDLL::isInList(string val)const {
    struct Node *temp;
    temp = head;
    while(temp!=NULL) {
        if(temp->element == val) {
            return true;
        }
        temp= temp->next;
    }
    return false;
}

void SDLL::printAll()const {
    struct Node *temp;
    temp = head;
    while(temp!=NULL) {
        cout<< temp->element <<endl;
        temp = temp->next;
    }
}
void SDLL::removeDuplicates() {
    struct Node *temp1, *temp2, *dup;
    temp1 = head;
    
    while (temp1 != NULL && temp1->next != NULL)
    {
        temp2 = temp1;
        
        while (temp2->next != NULL)
        {
            if (temp1->element == temp2->next->element)
            {
                dup = temp2->next;
                temp2->next = temp2->next->next;
                if(temp2->next!=NULL) {
                    temp2->next->prev = temp2;
                }
                delete(dup);
            }
            else
                temp2 = temp2->next;
        }
        temp1 = temp1->next;
    }
}

void SDLL::reverse() {
    struct Node *first, *second;
    first = head;
    second = first->next;
    first->next = NULL;
    first->prev = second;
    while (second != NULL)
    {
        second->prev = second->next;
        second->next = first;
        first = second;
        second = second->prev;
    }
    head = first;
    cout<<"List Reversed"<<endl;
}

int SDLL::getSize() {
    return size;
}
string& SDLL::operator[](const int i) {
    assert (("Invalid Range",i>0 && i<size));
    
    struct Node *temp;
    temp = head;
    int ctr=0;
    
    for(;ctr<i;ctr++){
        temp=temp->next;
    }
    return temp->element;
}

int main()
{
    int option;
    int index;
    string element;
    SDLL *sdll = NULL;
    while (true)
    {
       
        cout<<endl<<"1.Create a new String Doubly Link List"<<endl;
        cout<<"2.Get size: current number of Nodes in the list"<<endl;
        cout<<"3.Insert new element at Head"<<endl;
        cout<<"4.Insert new element at Tail"<<endl;
        cout<<"5.Delete first Node"<<endl;
        cout<<"6.Delete last Node"<<endl;
        cout<<"7.Delete specific Node"<<endl;
        cout<<"8.Search for string value"<<endl;
        cout<<"9.Reverse the list"<<endl;
        cout<<"10.Remove any duplicates"<<endl;
        cout<<"11.Print all elements"<<endl;
        cout<<"0.Quit the program"<<endl;
        cout<<"Enter your choice : ";
        cin>>option;
        switch (option)
        {
            case 1:
                delete sdll;
                sdll = new SDLL();
                cout<<"New String Doubly Link List Created";
                break;
            case 2:
                cout<<"Size of SDLL :"<<sdll->getSize()<<endl;
                break;
            case 3:
                cout<<"Enter the element: ";
                cin>>element;
                sdll->addToHead(element);
                cout<<endl;
                break;
            case 4:
                cout<<"Enter the element: ";
                cin>>element;
                sdll->addToTail(element);
                cout<<endl;
                break;
            case 5:
                sdll->deleteFromHead();
                cout<<endl;
                break;
            case 6:
                sdll->deleteFromTail();
                cout<<endl;
                break;
            case 7:
                cout<<"Enter the element: ";
                cin>>element;
                sdll->deleteNode(element);
                cout<<endl;
                break;
            case 8:
                cout<<"Enter the element: ";
                cin>>element;
                if(sdll->isInList(element)) {
                    cout<<"Element Found ";
                }
                else {
                    cout<<"Element not found";
                }
                cout<<endl;
                break;
            case 9:
                sdll->reverse();
                cout<<endl;
                break;
            case 10:
                sdll->removeDuplicates();
                cout<<"Duplicates removed";
                cout<<endl;
                break;
            case 11:
                sdll->printAll();
                cout<<endl;
                break;
            case 0:
                exit(1);
                break;
            default:
                cout<<"Wrong choice"<<endl;
        }
    }
    return 0;
}
/**************************************************************************************************************/
