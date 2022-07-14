#include <stdio.h>
#include <stdlib.h>

struct node {
	int data;
	struct node *left, *right;
};

void printLeaves(struct node* root)
{
	if (root == NULL)
		return;

	printLeaves(root->left);
	if (!(root->left) && !(root->right))
		printf("%d ", root->data);

	printLeaves(root->right);
}

void printBoundaryLeft(struct node* root)
{
	if (root == NULL)
		return;

	if (root->left) {
		printf("%d ", root->data);
		printBoundaryLeft(root->left);
	}
	else if (root->right) {
		printf("%d ", root->data);
		printBoundaryLeft(root->right);
	}
}
void printBoundaryRight(struct node* root)
{
	if (root == NULL)
		return;

	if (root->right) {
		printBoundaryRight(root->right);
		printf("%d ", root->data);
	}
	else if (root->left) {
		printBoundaryRight(root->left);
		printf("%d ", root->data);
	}
}

void printBoundary(struct node* root)
{
	if (root == NULL)
		return;
	printf("%d ", root->data);
	printBoundaryLeft(root->left);
	printLeaves(root->left);
	printLeaves(root->right);
	// printBoundaryRight(root->right);
}

struct node* newNode(int data)
{
	struct node* temp = (struct node*)malloc(sizeof(struct node));

	temp->data = data;
	temp->left = temp->right = NULL;

	return temp;
}

int main()
{
	struct node* root = newNode(20);
	root->left = newNode(8);
	root->left->left = newNode(4);
	root->left->right = newNode(12);
	root->left->right->left = newNode(10);
	root->left->right->right = newNode(14);
	root->right = newNode(22);
	root->right->right = newNode(25);
	printBoundary(root);
	return 0;
}
