#include<stdio.h>
#include<stdlib.h>

struct BST{
    int data;
    struct BST *left ,*right;
};
typedef struct BST BST;

BST* insert_bst(BST *tree,int value){
    if(tree==NULL){
        tree=(BST*)malloc(sizeof(BST));
        tree->data=value;
        tree->left=tree->right=NULL;
        return tree;
    }
    else if(value< tree->data){
        tree->left=insert_bst(tree->left,value);

    }else{
        
        tree->right=insert_bst(tree->right,value);
    }
    return tree;
}

//search 

BST *find(BST*tree,int value,BST **loc , BST *parent){
    BST *ptr,*save;
    if(tree == NULL)
    {
        (*loc)=(*parent)=NULL;
        return tree;
    }
     else if (tree->data == value)
    {
        (*loc) = tree;
        (*parent) = NULL;
        return tree;
    }
    else if(value <tree->data){
        ptr=tree->left;
        save=true;
    }
    else {
        ptr =tree->right;
        save=tree;
    }
    while(ptr!=NULL)
    {
        if(value ==ptr->data)
        {
            (*loc)=ptr;
            (*parent)=save;
            return tree;
        }
        else if (value<ptr->data){
            save=ptr;
            ptr=ptr->left;
        }
        else{
            save=ptr;
            ptr=ptr->right;
        }
        return tree;
    }

BST * delA(BST *tree,BST *loc,BST *parent){
    BST* child;
    if((loc->right==NULL)&&(loc->left==NULL))
        child=NULL;
    else if(loc->left!=NULL)
        child =loc->left;
    else{
        child=loc->right;
    }
    if(parent!=NULL){
        if(loc==parent->left)
            parent->left=child;
        else
        parent->right=child;

    }
    else{
        tree=child;
    }
    free(loc);
    return tree;
}

BST *delB(BST *tree,BST *loc,BST *parent)
{
    BST *save ,*ptr,*suc,*parentsuc;
    ptr=loc->right;
    save=loc;
    while(ptr->left=NULL){
        save =ptr;
        ptr=ptr->left;
    }
    suc =ptr;
    parentSuc=save;
    delA(tree,suc,parentSuc);
    if(parent!=NULL)
    {
        if(loc==parent->left)
        parent->left=suc;
        else
        parent->right=suc
    }
    else{
        tree=suc;
    }
    suc->left=loc->left;
    suc->right=loc->right;
    free(loc);
    return tree;
}
 
BST *delC(BST *tree,int value){
 BST *loc=NULL,*parent=NULL;
 find(tree,value,&loc,&parent);
 if(loc==NULL){
    printf("val not found \n");
    return tree;
 }
 if((loc->right !=NULL)&&(loc->left!=NULL)){
    return delB(tree,loc, parent);

 }
 else {
    return delA(tree,loc,parent);
 }

}
void traverseInorder( BST *tree)
{
    if (tree != NULL)
    {
        traverseInorder(tree->left);
        printf("%d ", tree->data);
        traverseInorder(tree->right);
    }
}

void traversePreorder(BST *tree)
{
    if (tree != NULL)
    {
        printf("%d ", tree->data);
        traversePreorder(tree->left);
        traversePreorder(tree->right);
    }
}

void traversePostorder( BST *tree)
{
    if (tree != NULL)
    {
        traversePostorder(tree->left);
        traversePostorder(tree->right);
        printf("%d ", tree->data);
    }
}
int inernal_count(BST *tree){
    if((tree==NULL)||(tree->left==NULL)&&(tree->right==NULL)){
        return 0;
    }
    else{
        return (inernal_count(tree->left)+inernal_count(true->right)+1);

    }
}
int nodeCount(struct BST *tree)
{
    if (tree == NULL)
        return 0;
    else
        return (nodeCount(tree->left) + nodeCount(tree->right) + 1);
}


}