/* 
 * https://www.naukri.com/code360/problems/remove-duplicates-from-a-sorted-doubly-linked-list_2420283?utm_source=chatgpt.com&leftPanelTabValue=SUBMISSION
 * Problem: Remove duplicates from a sorted Doubly Linked List
 *
 * ------------------------------------------------------------
 * APPROACH:
 *
 * Since the given doubly linked list is sorted,
 * duplicate nodes will always be adjacent.
 *
 * We traverse the list using a pointer `temp`.
 *
 * At each step:
 * 1. Compare temp->data with temp->next->data
 * 2. If equal:
 *      - Store temp->next in a pointer (duplicate)
 *      - Skip the duplicate node by:
 *            temp->next = duplicate->next
 *      - If duplicate->next exists:
 *            update its prev pointer to temp
 *      - Delete duplicate node to free memory
 * 3. Else:
 *      - Move temp forward
 *
 * We stop when temp->next becomes NULL.
 *
 * ------------------------------------------------------------
 * TIME COMPLEXITY:
 * O(n)
 * Each node is visited once.
 *
 * SPACE COMPLEXITY:
 * O(1)
 * No extra data structures used.
 *
 * ------------------------------------------------------------
 */

class Node {
public:
    int data;
    Node *prev;
    Node *next;

    Node() {
        this->data = 0;
        this->prev = NULL;
        this->next = NULL;
    }

    Node(int data) {
        this->data = data;
        this->prev = NULL;
        this->next = NULL;
    }

    Node(int data, Node *next, Node *prev) {
        this->data = data;
        this->prev = prev;
        this->next = next;
    }
};

Node* removeDuplicates(Node* head)
{
    if (head == nullptr) return head;

    Node* temp = head;

    while (temp->next != nullptr)
    {
        if (temp->data == temp->next->data)
        {
            Node* duplicate = temp->next;

            temp->next = duplicate->next;

            if (duplicate->next != nullptr)
                duplicate->next->prev = temp;

            delete duplicate;
        }
        else
        {
            temp = temp->next;
        }
    }

    return head;
}
