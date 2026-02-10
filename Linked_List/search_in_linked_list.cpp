 /* 
 Question
 https://www.naukri.com/code360/problems/search-in-a-linked-list_975381?interviewProblemRedirection=true&search=Search%20in%20a%20linked%20list&leftPanelTabValue=PROBLEM
Search in a Linked List
Given the head of a singly linked list and an integer K,
check whether a node with value K exists.
👉 Return 1 if found
👉 Return 0 otherwise


*/
int searchInLinkedList(Node<int>* head, int k) {

    Node<int>* temp = head;

    while (temp != NULL) {

        if (temp->data == k)
            return 1;

        temp = temp->next;
    }

    return 0;
}
