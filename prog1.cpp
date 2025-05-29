#include<iostream>
using namespace std;

class Node{
    public:
        int data;
        Node *next;

        Node(int data)
        {
            this->data = data;
            this->next = NULL;
        }
};

class LinkedList{
    private:
        int size;
        Node *head;

    public:
        LinkedList()
        {
            this->head = NULL;
            this->size = 0;
        }

        void InsertAtbeginning(int data)
        {
            Node *newnode = new Node(data);
            newnode->next = this->head;
            this->head = newnode;
            this->size++;
        }

        void viewlist()
        {
            Node *ptr = this->head; 
            cout<<"LInked List is : ";
            while(ptr != NULL)
            {
                cout<<ptr->data<<" ";
                ptr = ptr->next;
            }
            cout<<endl;

        }

        void deleteAtFront()
        {
            Node *ptr = this->head;
            this->head = this->head->next;

            if(this->head = NULL)
            {
                cout<<"The list is empty : ";
                return ;
            }

            else
            {
                this->head = this->head->next;
            }
        }

        void deleteAtIndex(int index) {
        if (index < 0 || this->head == nullptr) {
            cout << "Invalid index or list is empty.\n";
            return;
        }

        if (index == 0) {
            if (this->head == nullptr) {
                cout << "List is empty.\n";
                return;
            }
    
            Node* ptr = this->head;
            this->head = this->head->next;
            delete ptr;
            cout << "Deleted node at start.\n";
            return;
        }

        Node* ptr = this->head;
        int size;
        this->size = 0;

        while (ptr->next != nullptr && this->size < index - 1) {
            ptr = ptr->next;
            this->size++;
        }

        if (ptr->next == nullptr) {
            cout << "Index out of bounds.\n";
        } else {
            Node* toDelete = ptr->next;
            ptr->next = toDelete->next;
            delete toDelete;
            cout << "Deleted node at index " << index << ".\n";
        }
    }
    void ViewLinkedList()
    {
        Node *ptr = this->head;
        cout << "List = ";
        while (ptr != NULL)
        {
            cout << ptr->data << " ";
            ptr = ptr->next;
        }
        cout<<endl;
    }
    void ReversList()
    {
        Node *ptr = this->head;
        cout<<"Reversed List = ";
        for(int i = this->size ; i >1; i--)
        {
            cout << ptr->data << " ";
        }
        cout<<endl;
        
    }
};

int main()
{
    LinkedList obj;

    obj.InsertAtbeginning(10);
    obj.InsertAtbeginning(20);
    obj.InsertAtbeginning(30);
    obj.InsertAtbeginning(40);
    obj.viewlist();
    obj.ViewLinkedList();
    obj.ReversList();
    return 0;
}