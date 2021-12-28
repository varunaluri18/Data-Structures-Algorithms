#include<stdio.h>
#include<stdlib.h>
struct BTnode
{
int keyVal;
struct BTnode *leftNode;
struct BTnode *rightNode;
};
struct BTnode *getNode(int value)
{
struct BTnode *newNode = malloc(sizeof(struct BTnode));
newNode->keyVal = value;
newNode->leftNode = NULL;
newNode->rightNode = NULL;
return newNode;
}
struct BTnode *insert(struct BTnode *rootNode, int value)
{
if(rootNode == NULL)
return getNode(value);
if(rootNode->keyVal < value)
rootNode->rightNode = insert(rootNode->rightNode,value);
else if(rootNode->keyVal > value)
rootNode->leftNode = insert(rootNode->leftNode,value);
return rootNode;
}
void insertorder(struct BTnode *rootNode)
{
if(rootNode == NULL)
return;
insertorder(rootNode->leftNode);
printf("%d ",rootNode->keyVal);
insertorder(rootNode->rightNode);
}
int main()
{
struct BTnode *rootNode = NULL;
rootNode = insert(rootNode,7);
rootNode = insert(rootNode,4);
rootNode = insert(rootNode,8);
rootNode = insert(rootNode,1);
rootNode = insert(rootNode,5);
rootNode = insert(rootNode,2);
rootNode = insert(rootNode,9);
rootNode = insert(rootNode,3);
insertorder(rootNode);
return 0;
}


/** In-order,Pre-Order,Post-Order

#include <stdio.h>
#include <stdlib.h>
struct BTnode {
int data;
struct BTnode* leftNode;
struct BTnode* rightNode;
};
void inorder(struct BTnode* rootNode) {
if (rootNode == NULL) return;
inorder(rootNode->leftNode);
printf("%d ->", rootNode->data);
inorder(rootNode->rightNode);
}
void preorder(struct BTnode* rootNode) {
if (rootNode == NULL) return;
printf("%d ->", rootNode->data);
preorder(rootNode->leftNode);
preorder(rootNode->rightNode);
}
void postorder(struct BTnode* rootNode) {
if (rootNode == NULL) return;
postorder(rootNode->leftNode);
postorder(rootNode->rightNode);
printf("%d ->", rootNode->data);
}
struct BTnode* createNode(value) {
struct BTnode* newNode = malloc(sizeof(struct BTnode));
newNode->data = value;
newNode->leftNode = NULL;
newNode->rightNode = NULL;
return newNode;
}
struct BTnode* insertLeftNode(struct BTnode* rootNode, int value) {
rootNode->leftNode = createNode(value);
return rootNode->leftNode;
}
struct BTnode* insertRightNode(struct BTnode* rootNode, int value) {
rootNode->rightNode = createNode(value);
return rootNode->rightNode;
}
int main() {
struct BTnode* rootNode = createNode(7);
insertLeftNode(rootNode, 4);
insertRightNode(rootNode, 8);
insertLeftNode(rootNode->leftNode, 1);
insertRightNode(rootNode->rightNode, 5);
insertLeftNode(rootNode->leftNode, 6);
insertRightNode(rootNode->rightNode, 3);
printf("Inorder \n");
inorder(rootNode);
printf("\nPreorder \n");
preorder(rootNode);
printf("\nPostorder \n");
postorder(rootNode);
}