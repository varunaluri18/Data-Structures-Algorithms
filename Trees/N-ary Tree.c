#include <stdio.h>
#include <stdlib.h>


struct node{
  char *word;
  int depth, children;
  struct node  **child;
};

typedef struct node node;


node *createTree();
node *createNode(char *word,int depth);

int main(int argv,char *argc[]){
   node *root,*current_node;
   root=createNode("root",0);
   char *array[]={"string1","string2","string3"};
   current_node=root;
   printf("root has been created with word: %s \n",current_node->word);
   int i;
   for (i=0; i<3; i++){
      current_node->child[i]=createNode(array[i],(current_node->depth)+1);
      current_node->children++;
      printf("%s  has been inserted to the tree\n",current_node->word);
   }

}



node *createTree(){
   printf("root has been created\n");
   return createNode("",0);    /*creates the first node*/
}

node *createNode(char *word,int depth){
   node *new_node;
   new_node=malloc(sizeof(node));
   new_node->word=word;
   new_node->depth=depth;
   new_node->children=0;
   new_node->child=NULL;
}