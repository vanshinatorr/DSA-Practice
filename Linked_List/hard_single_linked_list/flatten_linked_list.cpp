
/*

Problem: Flatten a Linked List (Striver / Code360) ( medium )
https://www.naukri.com/code360/problems/flatten-a-linked-list_1112655?leftPanelTabValue=SUBMISSION






Approach:

1. Each node has two pointers:

   * next → points to next list
   * child → points to sorted vertical list.
2. Idea is similar to **Merge K Sorted Linked Lists**.
3. Use recursion to flatten the right side lists first.
4. Then merge the current vertical list with the already flattened list.
5. The merge function works like **merge of two sorted linked lists** but uses the `child` pointer.

Steps:

* Recursively flatten the list on the right: `flattenLinkedList(head->next)`
* Merge current list and flattened right list
* Return merged head.

Time Complexity:
O(N * M)
(N = number of lists, M = average nodes in each list)

Space Complexity:
O(N) recursion stack

---


* Definition for linked list.
* class Node {
* public:
* ```
   int data;
  ```
* ```
   Node *next;
  ```
* ```
   Node *child;
  ```
* ```
   Node() : data(0), next(nullptr), child(nullptr){};
  ```
* ```
   Node(int x) : data(x), next(nullptr), child(nullptr) {}
  ```
* ```
   Node(int x, Node *next, Node *child) : data(x), next(next), child(child) {}
  ```
* };
  */

Node* merge(Node* list1, Node* list2) {

```
Node* dummy = new Node(-1);
Node* temp = dummy;

while(list1 && list2){

    if(list1->data < list2->data){
        temp->child = list1;
        list1 = list1->child;
    }
    else{
        temp->child = list2;
        list2 = list2->child;
    }

    temp = temp->child;

    // remove horizontal links
    temp->next = NULL;
}

// attach remaining nodes
if(list1) temp->child = list1;
else temp->child = list2;

return dummy->child;
```

}

Node* flattenLinkedList(Node* head){

```
// base case
if(head == NULL || head->next == NULL)
    return head;

// flatten the right side
Node* mergedHead = flattenLinkedList(head->next);

// merge current list with flattened right list
head = merge(head , mergedHead);

return head;
```

}
