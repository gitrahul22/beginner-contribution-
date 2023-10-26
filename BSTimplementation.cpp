/*C++ Program for Searching of Nodes in BST */
#include<iostream>
using namespace std;
/* A binary search tree node has data, pointer to left child 
and a pointer to right child */
struct Node
{
	Node* left;
	Node* right;
	int data;
};
/*For Creating New Node*/
Node* createnewNode(int val)
{
	Node* nn = new Node();
	nn->left = NULL;
	nn->right = NULL;
	nn->data = val;
	return nn;
}
/*Insertion Function*/
Node* insert(Node* rt,int val)
{
	if(rt==NULL)
	{
		rt = createnewNode(val);
	}
	else if(val<=rt->data)
	{
		rt->left = insert(rt->left,val);
	}
	else
	{
		rt->right = insert(rt->right,val);
	}
	return rt;
}
/*Inorder Traversal*/
void inorder(Node* rt)
{
	if(rt!=NULL)
	{
		inorder(rt->left); //left Subtree
		cout<<rt->data<<" ";
		inorder(rt->right);//Right Subtree
	}
}
/*Search Function*/
bool search(Node* rt,int val)
{
	if(rt==NULL)
		return false;
	else if(rt->data == val)
		return true;
	else if(val<=rt->data)
		return search(rt->left,val);
	else
		return search(rt->right,val);
}
/* DRIVER FUNCTION */
int main()
{
	int tar;
	/*Initially the Root is NULL*/
	Node* root = NULL;
	/*In Insert function root is local thus why we are returning and storing root*/
	root = insert(root,12); 
	root = insert(root,7);
	root = insert(root,19);
	root = insert(root,5);
	root = insert(root,9);
	root = insert(root,10);
	/* Inorder Traversal of BST is always in Ascending Order*/
	inorder(root);
	cout<<"\nEnter a Number to Search"<<endl;
	cin>>tar;
	if(search(root,tar))
		cout<<tar<<" is Found"<<endl;
	else
		cout<<tar<<" is not Found"<<endl;
	return 0;
}
