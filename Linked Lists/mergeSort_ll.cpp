#include <iostream>
using namespace std;

struct ListNode{
    int data;
    ListNode* next;
    ListNode(int val){
        data=val;
        next=NULL;
    }
};

void insertAtHead(ListNode* &head, int val){
    ListNode* n = new ListNode(val);
    n->next = head->next;
    head = n;
}

void append(ListNode* &head, int val){
    if(head==NULL){
        insertAtHead(head,val);
        return;
    }

    ListNode* n = new ListNode(val);
    ListNode* temp = head;
    while(temp->next!=NULL){
        temp = temp->next;
    }
    temp->next = n;
}

void display(ListNode* head){
    while(head!=NULL){
        cout<<head->data<<" ";
        head = head->next;
    }
    cout<<endl;
}

ListNode* findMid(ListNode* start, ListNode* end){
    ListNode* slow = start;
    ListNode* fast = start;
    while(fast!=end && fast->next!=end){
        fast = fast->next->next;
        slow = slow->next;
    }
    return slow;
}

ListNode* merge(ListNode* ll1,ListNode* ll2){
    ListNode* sortedList = new ListNode(0);
    ListNode* start = sortedList;
    while(ll1!=NULL && ll2!=NULL){
        if(ll1->data < ll2->data){
            sortedList->next = ll1;
            ll1 = ll1->next;
        }
        else{
            sortedList->next = ll2;
            ll2 = ll2->next;
        }
        sortedList=sortedList->next;
        // display(start->next);
    }
    while(ll1!=NULL){
        sortedList->next = ll1;
        ll1 = ll1->next;
        sortedList = sortedList->next;
    }
    while(ll2!=NULL){
        sortedList->next = ll2;
        ll2 = ll2->next;
        sortedList = sortedList->next;
    }
    sortedList->next = NULL;
    return start->next;
}

ListNode* mergeSort(ListNode* &start, ListNode* &end){
    if(start==end){
        ListNode* n = new ListNode(start->data);
        return n;
    }
    // display(start);
    ListNode* mid = findMid(start, end);
    ListNode* firstHalf = mergeSort(start,mid);
    ListNode* secondHalf = mergeSort(mid->next,end);
    ListNode* sortedList = merge(firstHalf,secondHalf);
    return sortedList;

}

int main(){
    ListNode* head = new ListNode(14);
    append(head,7);
    append(head,3);
    append(head,12);
    append(head,9);
    append(head,11);
    append(head,6);
    append(head,2);
    display(head);

    // ListNode* head1 = new ListNode(14);
    // append(head1,7);
    // append(head1,3);
    // append(head1,12);

    // ListNode* head2 = new ListNode(9);
    // append(head2,11);
    // append(head2,6);
    // append(head2,2);
    ListNode* tail=head;
    while(tail->next!=NULL){
        tail = tail->next;
    }
    // ListNode* mid = findMid(head,tail);
    // cout<<mid->data;
    ListNode* merged = mergeSort(head, tail);
    display(merged);
    return 0;
}