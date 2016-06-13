#include<stdio.h>
#include<stdlib.h>
struct node
{    
       int key,length;
	node *right,*left;
};
node* rr(node*);     //to rotate right
node* lr(node*);     //to rotate left
node*insert(node*,int);     //to insert new node
node*rotate(node*,int);    //to check equality and rotate
int check(node*);       //to calculate diff b/w left and right children
int total(node*);     //to calculate total length

node* newnode(int key)
{   
        node* new;
	new->key=key;
	new->left=new->right=NULL;
	new->length=1;
	return new;
}
int total(node* new)
{    
        if(!new)
	 return 0;
	
        else
	 return new->length;
}
int check(struct node *a)
{   
	int b;
	if(!a)
		return 0;
	else
	{    
		b=total(a->left)-total(a->right);
		return b;
	}
}
node* insert(node *new, int key)
{    
	if(!new)
		return(newnode,key)
	if(key<new->key)
		new->left=insert(new->left,key)
	else
		new->right=insert(new->right,key)
        int a=total(new->left);
	int b=total(new->right);
	
        if(a>b)
		new->length=a;
	else
		new->length=b;

	node* rotated=rotate(new,key);
	return rotated;
}
node* rotate(node *new, int key)
{   
	a=check(new);
	if(a>1 && key<new->left->key)
		return rr(new);
	else if(a>1 && key>new->left->key)
	{    
		new->left=lr(new->left);
		return rr(new);
	}
	else if(a<-1 && key>new->right->key)
		return lr(new);
	else if(a<-1 && key<new->right->key)
	{    
		new->right=rr(new->length);
		return lr(new);
	}
	else
		return new;
}
node *rr(node *old)
{    node* t1,t2;
	t1=old->left;
	t2=t1->right;
	t1->right=old;
	old->left=temp2;
	int a=total(old->left);
	int b=total(old->right);
	if(a>b)
		old->length=a;
	else
		old->length=b;
	a=total(t1->left);
	b=total(t1->right);
	if(a>b)
		t1->length=a;
	else
		t1->length=b;
	return t1;
}
node* lr( node* old)
{    
	node* t1,t2;
	t1=old->right;
	t2=t1->left;
	t1->left=old;
	old->right=t2;
	int a=total(old->left);
	int b=total(old->right);
	if(a>b)
		old->length=a;
	else
		old->length=b;
	a=total(t1->left);
	b=total(t1->right);
	if(a>b)
		t1->length=a;
	else
		t1->length=b;
	return t1;
}
int main()
    {    
    node* root=NULL;
    int n,key;
    printf("Enter no. of nodes\n");
    scanf("%d",&n);
    printf("\n Enter %d no.of keys to be inserted:\n",n);
    for(int i=0; i<n; i++)
    {    
	scanf("%d",&key);
        root=insert(root,key);
    }
    //display final tree
    return 0;
    }
