#include <bits/stdc++.h>
using namespace std;

struct node
{
	int data;
	node* small;
	node* large;
};
typedef struct node* Node;
static Node newNode(int data) {
    Node node = (Node) malloc(sizeof(struct node));
    node->data = data;
    node->small = NULL;
    node->large = NULL;
    return(node);
}
static void treeInsert(Node* rootRef, int data) {
    Node root = *rootRef;
    if (root == NULL) *rootRef = newNode(data);
    else {
        if (data <= root->data) treeInsert(&(root->small), data);
        else treeInsert(&(root->large), data);
    }
}
static void printList(Node head) {
    Node current = head;
    
    while(current != NULL) {
        printf("%d ", current->data);
        current = current->large;
        if (current == head) break;
    }
    printf("\n");
}
static Node treeToList(Node root)
{
	if(root == NULL)
		return NULL;
	Node right = root->small;
	Node left = root->large;
	Node aleft = treeToList(left);
	Node aright = treeToList(right);
    if(aleft != NULL)
    {
        root->small = aleft;
        aleft->small->large = root;
        aleft->small = root;
        root->large = aleft;
    }
    else
    {
        root->large = root;
        root->small = root;
    }
    Node head = root;
    if(aright != NULL)
    {
        (aright->small)->large = head;
        Node as = head->small;
        head->small = aright->small;
        aright->small = as;
        as->large = aright;
        head = aright;
    }
    return head;
}
int main()
{
    Node root = NULL;
    Node head;
    
    treeInsert(&root, 4);
    treeInsert(&root, 2);
    treeInsert(&root, 1);
    treeInsert(&root, 3);
    treeInsert(&root, 5);
    
    head = treeToList(root);
    
    printList(head);    /* prints: 1 2 3 4 5  */
    
    return(0);
}