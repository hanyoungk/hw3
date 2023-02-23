#include <iostream>
#include <fstream>
#include <functional>
#include "llrec.h"
using namespace std;

/**
 * Reads integers (separated by whitespace) from a file
 * into a linked list.
 *
 * @param[in] filename
 *  The name of the file containing the data to read
 * @return
 *  Pointer to the linked list (or NULL if empty or the
 *  file is invalid)
 */
Node* readList(const char* filename);

/**
 * Prints the integers in a linked list pointed to
 * by head.
 */
void print(Node* head);

/**
 * Deallocates the linked list nodes
 */
void dealloc(Node* head);


Node* readList(const char* filename)
{
    Node* h = NULL;
    ifstream ifile(filename);
    int v;
    if( ! (ifile >> v) ) return h;
    h = new Node(v, NULL);
    Node *t = h;
    while ( ifile >> v ) {
        t->next = new Node(v, NULL);
        t = t->next;
    }
    return h;
}

void print(Node* head)
{
    while(head) {
        cout << head->val << " ";
        head = head->next;
    }
    cout << endl;
}

void dealloc(Node* head)
{
    Node* temp;
    while(head) {
        temp = head->next;
        delete head;
        head = temp;
    }
}

// -----------------------------------------------
//   Add any helper functions or
//   function object struct declarations
// -----------------------------------------------

//returns true if the value is odd
struct isOdd {
    bool operator()(int num) {
        return (num % 2) != 0;
    }
};



int main(int argc, char* argv[])
{
    if(argc < 2) {
        cout << "Please provide an input file" << endl;
        return 1;
    }

    // -----------------------------------------------
    // Feel free to update any code below this point
    // -----------------------------------------------
    Node* head = readList(argv[1]);
    Node* small = (Node*) &head;
    Node* large = (Node*) &head;

    cout << "Original list: ";
    print(head);

    // Test out your linked list code

    llpivot(head, small, large, 5);

    cout << "values that are smaller than 5: ";
    print(small);
    cout << "bigger than 5: ";
    print(large);
    cout << "original list: ";
    print(head);
    cout << endl;


    // Node* test = llfilter(head, isOdd());
    // cout << "not odd: ";
    // print(test);
    // cout << endl;

    // Node* smaller;
    // Node* larger;
    // llpivot(head, smaller, larger, 9);

    // // llfilter()

    // cout << "values that are smaller than 9: ";
    // print(smaller);
    // cout << "bigger than 9: ";
    // print(larger);
    // cout << endl;


    // cout << "Head: ";
    // print(head);

    // cout << "Smaller: ";
    // print(smaller);

    // cout << "Larger: ";
    // print(larger);


    
    return 0;

}
