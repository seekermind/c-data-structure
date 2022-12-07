#include <stdio.h>
#include <stdlib.h>

typedef struct node Node;
struct node {
	int data;
	Node *left, *right;
};

Node *creatNode(int item){
	Node *newNode = malloc(sizeof(Node));
	if (newNode == NULL) {
		return NULL;
	}
	newNode->data = item;
	newNode->left = NULL;
	newNode->right = NULL;
	return newNode;
}

Node *creatTree(){
	Node *root = creatNode(10);
	root->left = creatNode(5);
	root->left->left = creatNode(3);
	root->left->left->left = creatNode(2);
	root->left->left->right = creatNode(11);
	root->right = creatNode(7);
	root->right->left = creatNode(1);
	root->right->left->left = creatNode(13);
	root->right->left->right = creatNode(9);
	root->right->right = creatNode(12);
	return root;
}

Node *deleteTree(Node **root){
	Node *tmp = *root;
	*root = NULL;
	return tmp;
}

void printInorderTree(Node *root){
	if (root == NULL) {
		return;
	}
	printInorderTree(root->left);
	printf("%d, ", root->data);
	printInorderTree(root->right);
}
void printTree(Node *root){
	if (root == NULL) {
		return;
	}
	printf("%d, ", root->data);
	printTree(root->left);
	printTree(root->right);
}

void main(){
	Node *node = creatTree();
	printTree(node);
	printf("\n");
	Node *del = deleteTree(&node->right->left);
	printTree(node);
	printf("\n");
	printTree(del);
}
