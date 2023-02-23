#include "llrec.h"

//*********************************************
// Provide your implementation of llpivot below
//*********************************************

void llpivot(Node *&head, Node *&smaller, Node *&larger, int pivot)
{
    if(head == nullptr) {
        smaller = nullptr;
        larger = nullptr;
        return;
    }
    else {
        if(head->val <= pivot) {
            smaller = head;
            head = head->next;
            llpivot(head, smaller->next, larger, pivot);
        }
        else {
            larger = head;
            head = head->next;
            llpivot(head, smaller, larger->next, pivot);
        }
    }

    // if(head == nullptr) {
    //     return;
    // }
    // else {
    //     llpivot(head->next, smaller, larger, pivot); //get to the null/tail pointer
    //     if((head->val <= pivot)) {//smaller if less than equal to pivot
    //         head->next = smaller; //add to the front of the list "smaller"
    //         smaller = head; //assign smaller as head
    //         head = nullptr;
    //     }
    //     else {
    //         head->next = larger;
    //         larger = head;
    //         head = nullptr;
    //     }
    // }
}
