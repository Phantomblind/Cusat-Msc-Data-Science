#include<stdio.h>
#include<stdlib.h>

struct node 
{
	int value;
	struct node *left;
	struct node *right;
}*root = NULL ,*temp=NULL;

struct node *insert (struct node *root,int element)
{
	
	if(root==NULL)
	{	
		temp=(struct node*)malloc(sizeof(struct node));
		temp->value=element;
		temp->right=NULL;
		temp->left=NULL;
		return temp;
	}
	
	if(root->value==element)
	{
		return root;
	}
	if(root->value>element)
	{
		root->left=insert(root->left,element);
	}
	else
	{
		root->right=insert(root->right,element);
	}
	
	return root;
}

void inorder (struct node *root)
{
	if(root!=0)
	{
		inorder(root->left);
		printf("%d ",root->value);
		inorder(root->right);
	}
}

void preorder (struct node *root)
{
	if(root!=0)
	{
		printf("%d ",root->value);
		inorder(root->left);
		inorder(root->right);
	}
}

void postorder (struct node *root)
{
	if(root!=0)
	{
		inorder(root->left);
		inorder(root->right);
		printf("%d ",root->value);
	}
}

void main()
{
	root = insert(root,50);
	root = insert(root,30);
	root = insert(root,55);
	root = insert(root,60);
	root = insert(root,25);
	root = insert(root,40);
	root = insert(root,33);
	
	inorder(root);
	printf("\n");
	preorder(root);
	printf("\n");
	postorder(root);
}
