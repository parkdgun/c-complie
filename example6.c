#include <iostream>

struct Node{

    Node* prev;
    Node* next;

    void* data;
};

struct List{
    Node* head;
};

List* createList(){

    Node* head = new Node;
    head->prev = head;
    head->next = head;
    head->data = 0;

    List* list = new List;
    list->head = head;

    return list;
}

void insertNodeAfter(Node* node, void* data){
    
    Node* before = node;
    Node* after = node->next;

    Node* newNode = new Node;
    newNode->data = data;
    newNode->next = after;
    newNode->prev = before;

    after->prev = newNode;
    before->next = newNode;
}

void removeNode(Node* node, bool deleteData){

    Node* before = node->prev;
    Node* after = node->next;

    before->next = after;
    after->prev = before;

    if (deleteData)
        delete node->data;
    delete node;
}

void RemoveList(List* list, bool deleteData){
    
    Node* current = list->head;

    do{
        Node* next = current->next;
        if (deleteData)
            delete current->data;
        delete current;

        current = next;

    } while (current != list->head);

    delete list;
}