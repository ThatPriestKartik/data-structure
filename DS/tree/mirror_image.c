#include<stdio.h>
#include<stdlib.h>
#include<malloc.h>
int sum=0;
/***************************************************/
int MAX(int x,int y)
{
	if(x>y)
	    return x;
	else
	    return y;
}
/****************************************************/
struct node{
	int data;
	struct node *left;
	struct node *right;
};
/****************************************************/
struct node *makenode(int x)
{
	struct node *p;
	p=(struct node*)malloc(sizeof(struct node));
	p->data=x;
	p->left=NULL;
	p->right=NULL;
	return p;
}
/****************************************************/
int insert(struct node **t,int x)
{
	struct node *p,*q;
	p=(*t);
	q=NULL;
	while(p!=NULL){
		q=p;
		if(x<p->data)
		    p=p->left;
		else
		    p=p->right;
	}
	if(x<q->data)
	    q->left=makenode(x);
	else
	    q->right=makenode(x);
}
/****************************************************/
struct node *BSTrecursive(struct node *t,int x)
{
	if(t!=NULL)
	    t=makenode(x);
	else{
		if(x<t->data)
		    t->left=BSTrecursive(t->left,x);
		else
		    t->right=BSTrecursive(t->right,x);
	}
	return t;
}
/***************************************************/
struct node *search(struct node *t,int key)
{
	struct node *p;
	p=t;
	while(p!=NULL){
		if(key==p->data)
		    return p;
		else if(key<p->data)
		    p=p->left;
		else
		    p=p->right;
	}
	return NULL;
}
/***************************************************/
int preorder(struct node *t)
{
	if(t!=NULL){
		printf("%d ",t->data);
		preorder(t->left);
		preorder(t->right);
	}
}
/**************************************************/
int inorder(struct node *t)
{
	if(t!=NULL){
		inorder(t->left);
		printf("%d ",t->data);
		inorder(t->right);
	}
}
/**************************************************/
int postorder(struct node *t)
{
	if(t!=NULL){
		postorder(t->left);
		postorder(t->right);
		printf("%d ",t->data);
	}
}
/*************************************************/

int main()
{
	printf("\n");
	printf("***********************************************");
	printf("\n");
	struct node *tree;
	tree=NULL;
	tree=makenode(120);
	insert(&tree,100);
	insert(&tree,110);
	insert(&tree,200);
	insert(&tree,150);
	insert(&tree,80);
	insert(&tree,90);
	insert(&tree,60);
	printf("preorder traverse : ");
	preorder(tree);
	printf("\n");
	printf("inorder traverse : ");
	inorder(tree);
	printf("\n");
	printf("postorder traverse : ");


}