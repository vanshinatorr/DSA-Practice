/* Question
https://www.naukri.com/code360/problems/length-of-ll_5884

Count nodes of a singly linked list
Given the head of a linked list, return the total number of nodes.

Approach (1-line idea)
Traverse the list → count each node → stop at NULL.

*/



int length(Node* head) {

    int count = 0;
    Node* temp = head;

    while (temp != NULL) {
        count++;
        temp = temp->next;
    }

    return count;
}
