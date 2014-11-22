#include <bits/stdc++.h>
using namespace std;

struct node
{
	int data;
	node* left;
	node* right;
};
struct node* newNode(int data)
 
{
  struct node* node = (struct node*)
                       malloc(sizeof(struct node));
  node->data = data;
  node->left = NULL;
  node->right = NULL;
   
  return(node);
}
void mirror(node* h)
{
	if(h == NULL)
		return ;
	if(h->left == NULL && h->right == NULL)
		return ;
	swap(h->left,h->right);
	mirror(h->left);
	mirror(h->right);
}

void inOrder(node* n)
{
  if (n == NULL)
    return;
   
  inOrder(n->left);
  printf("%d ", n->data);
 
  inOrder(n->right);
}  
int main()
{
	  struct node *root = newNode(1);
	  root->left        = newNode(2);
	  root->right       = newNode(3);
	  root->left->left  = newNode(4);
	  root->left->right = newNode(5); 
	   
	  /* Print inorder traversal of the input tree */
	  printf("Inorder traversal of the constructed tree is ");
	  inOrder(root);
	   printf("\n");
	  /* Convert tree to its mirror */
	  mirror(root); 
	   
	  /* Print inorder traversal of the mirror tree */
	  printf("Inorder traversal of the mirror tree is ");  
	  inOrder(root);
	  printf("\n");

}