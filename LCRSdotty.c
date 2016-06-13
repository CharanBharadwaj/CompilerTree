#include<stdio.h>
#include<stdlib.h>


static int gName=0;
FILE *outputFile;
//------------------NODE STRUCTURE-----------------
struct node
{
	int key;
	struct node *left;
	struct node *right;
}*root=NULL;
//--------------------------------------------------

int lefttrav(int b,struct node* tempo,int level);
int righttrav(int b,struct node* temp2,int level);

//--------------------------------------------------
//                        CREATION
//                        ````````
void create(int c, struct node *t)
{
	int k;
	int n,i;
	printf("Enter the no. of children of %d:\n",c);
	scanf("%d",&n);
	if(n>0)
	{
		for(i=1;i<=n;i++)
		{
			printf("enter the child of %d:\n",c);
			scanf("%d",&k);
			struct node *temp=(struct node *)malloc(sizeof(struct node));
			temp->key=k;
			if(t->left==NULL)
				t->left=temp;
			else
			{
				if(t->left->right==NULL)
					t->left->right=temp;
				else
				{
					t=t->left;
					while(t->right!=NULL)
						t=t->right;
					t->right=temp;
				}
			}
			create(temp->key,temp);
		}
	}
}
//----------------------------TRAVERSAL----------------------------
void traverse(struct node *f)
{
	if(f)
	{
		printf("%d\n",f->key);
		traverse(f->left);
		traverse(f->right);
	}
}
//--------------------------------------------------------------------------------
void preorderDotDump (struct node* root, FILE* outputFile)

{

	if (root != NULL) 

	{

		fprintf (outputFile, "%d [label=%d,color=black];\n",root->key, root->key);

		if (root->left != NULL) 

			fprintf (outputFile, "%d -> %d ;\n", root->key, (root->left)->key);



		if (root->right != NULL)

			fprintf (outputFile, "%d -> %d;\n", root->key, root->right->key);

		//	if (root->pptr != NULL)

		//   		fprintf (outputFile, "%d -> %d [style = dashed];\n", root->info, (root->pptr)->info);

		preorderDotDump (root->right, outputFile);

		preorderDotDump (root->left, outputFile);

	}

}
//----------------------------------------------------------------------------
void dotDump(struct node* root, FILE *outFile)

{

	gName++;

	fprintf(outFile,"digraph LCRS {\n",gName);



	preorderDotDump (root, outFile);

	fprintf (outFile, "}\n");

}


//------------------------------MAIN------------------------------------------
int main()
{
	FILE *pipe;
	int key,lev1,lev2,c,d,level=0,FLAG;
	outputFile = fopen ("LCRS.dot", "w");
	fclose (outputFile);
	printf("Enter the root:\n");
	scanf("%d",&key);
	struct node* root=(struct node*)malloc(sizeof(struct node));
	root->key=key;
	create(root->key,root);
	outputFile = fopen ("LCRS.dot", "a");

	if (outputFile != NULL) 

	{



		dotDump (root,  outputFile);

	}

	fclose (outputFile);
	printf("\n\nTraversal\n");
	traverse(root);
	pipe=popen("dot -Tps LCRS.dot -o LCRS.ps","w");

	pclose(pipe);	

	pipe=popen("evince LCRS.ps","r"); 

	pclose(pipe);
	return 0;
}
