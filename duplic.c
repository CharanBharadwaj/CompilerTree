#include<stdio.h>
#include<stdlib.h>
struct node
{
	int key;
	struct node* left;
	struct node* right;
	int num;
};
struct node* newnode(int key)
{
	struct node* New=(struct node*)malloc(sizeof(struct node));
	New->key=key;
	New->left=NULL;
	New->right=NULL;
	New->num=1;
	return New;
}

void PrintTree(struct node* nodes)               /*function to print the tree*/
{
	if(nodes==NULL)
		return;

	PrintTree(nodes->left);

	printf("\t%d(count %d)\n",nodes->key,nodes->num);
	printf("\t|\n\tV\n");

	PrintTree(nodes->right);
}

void main()
{

	int n,key,i,j,rootkey,count=2;
	struct node* left=NULL; struct node* right=NULL;
	printf("enter the no. of nodes\n");
	scanf("%d",&n);

	printf("enter the key of the root\n");
	scanf("%d",&rootkey);
	struct node* head;
	head=newnode(rootkey);
	struct node* root=head;


	//LOOP
Y:while(count<=n)
  {
	  printf("Enter the key of children:\n");
	  scanf("%d",&key);
	  struct node* child;
	  child=newnode(key);

X:if(child->key < root->key)
  {
	  if(root->left==NULL)
	  {
		  root->left=child;
		  count++;
		  goto Y;
	  }
	  else
	  {
		  root=root->left;
		  goto X;
	  }
  }
  else if(child->key >root->key)
  {
	  if(root->right==NULL)
	  {
		  root->right=child;
		  count++;
		  goto Y;
	  }
	  else
	  {
		  root=root->right;
		  goto X;
	  }
  }
  else if(child->key==root->key)
  {
	  root->num++;
	  count++;
	  goto Y;
  }
  count++;
  }
  root=head;
  printf("The tree is:\n");
  PrintTree(root);
  printf("\n");
}
