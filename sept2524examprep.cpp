#include <iostream>

using namespace std;
struct Node{
    int data;
    Node* next;
};

void swap(Node** head_ref, Node* currX, Node* currY, Node* prevY){
    *head_ref = currY;

    prevY->next = currX;
    
    Node* temp = currY->next;
    currY->next = currX->next;
    currX->next = temp;

}

Node *recursionSelectionSort(Node* head){
    if(head->next == NULL){
        return head;
    }

    Node* min = head;
    Node* beforeMin = NULL;
    Node* ptr;

    for(ptr = head; ptr->next!=NULL; ptr=ptr->next){
        if(ptr->next->data < min->data){
            min = ptr->next;
            beforeMin = ptr;
        }
    }

    if(min!=head){
        swap(&head, head, min, beforeMin);
    }

    head->next = recursionSelectionSort(head->next);
    return head;
}

void sort(Node **head_ref){
    if((*head_ref)==NULL)
        return;

    *head_ref= recursionSelectionSort(*head_ref);
}

void push(Node**head_ref, int num){
    Node* new_node = (Node*)malloc(sizeof(Node));
    new_node->data= num;
    new_node->next = (*head_ref);
    (*head_ref) = new_node;

}

void print(Node* head){
    while(head!=NULL){
        cout << head->data << " ";
        head = head->next;
    }
    cout << endl;
}

int main(){
    int num;
    int n;

    Node* head = NULL;
    cout << "what is n: " << endl;
    cin >> n;
    for (int i = 0; i < n; i++){
        cin >> num;
        push(&head, num);
    }   

    print(head);
    sort(&head);
    print(head);
}