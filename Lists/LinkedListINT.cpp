/* written by Shivansh Ananad                */
/* on CodeBlocks for Linux ( Elementary OS ) */

#include <iostream>
using namespace std;

class LinkedListINT { /*linked list for int values*/
    private:
        struct Node {
            int data;
            Node* next;
        };

        Node* head;
        Node* curr;

    public:
        LinkedListINT() {
            head = NULL;
            curr = NULL;
        }

    public:
        /*adds elements to the list*/
        void add(int data) {
            Node* temp = new Node;
            temp->data = data;
            temp->next = NULL;
            if(head==NULL) {
                head = temp;
            } else {
                curr = head;
                while(curr->next!=NULL) {
                    curr = curr->next;
                } curr->next = temp;
            }
        }


    public:
    /*removes all the elements of the list*/
        void clear() {
            head = NULL;
        }

    public:
    /*removes the last element*/
        void pop() {
            curr = head;
            while(curr->next->next!=NULL) {
                curr=curr->next;
            }
            delete (curr->next);
            curr->next = NULL;

        }

    public:
    /*removes the element at a particular index*/
        void remove(int index) {
            if(!(index<0||index>(size()-1))) {
                int c = 0;
                curr = head;
                Node* trail = head;
                Node* none = NULL;
                while(curr!=NULL && c!=index) {
                    trail = curr;
                    curr = curr->next;
                    c+=1;
                }
                if(curr==NULL) {
                    /*element not found, do appropriate thing*/
                }
                if(c==index) {
                    none = curr;
                    curr = curr->next;
                    trail->next = curr;
                    delete none;
                }
            }
        }


    public:
    /*prints the whole list*/
        void printList() {
            cout << "\nList : ";
            curr = head;
            while(curr!=NULL){
             cout << curr->data << " ";
             curr = curr->next;
            }
            cout << endl;
        }

    public:
    /*returns the size of the list*/
        int size() {
            curr = head;
            int s = 0;
            while(curr!=NULL) {
                s+=1;
                curr=curr->next;
            }
            return s;
        }

    public:
    /*return true if list is empty*/
        bool isEmpty() {
            return head==NULL;
        }

    public:
    /*checks if the list contaisn the query element*/
        bool contains(int data) {
            curr = head;
            while(curr!=NULL) {
                if(curr->data == data)
                    return true;
                curr = curr->next;
            }
            return false;
        }

    public:
    /*returns element at a particular index*/
        int get(int index) {
            if(index<0||index>(size()-1)){
                return NULL;
            }
            int c = 0;
            curr = head;
            while(curr!=NULL) {
                if(c==index)
                    return curr->data;
                c+=1;
                curr = curr->next;
            }
            return NULL;
        }
};


int main() {
    /* do whatever you want to do with the list class, sample code belo*/
    ListInt list;
    list.add(1);
    list.printList();
    cout << list.size();
    return 0;
}
