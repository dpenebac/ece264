// ***
// *** You MUST modify this file
// ***

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "tree.h"

TreeNode* newNode(int val);
int findVal (int arr[], int, int, int);
TreeNode* build(int inArr[], int postArr[], int);
TreeNode* recursiveBuild(int inArr[], int postArr[], int, int, int*);

// DO NOT MODIFY FROM HERE --->>>
void deleteTreeNode(TreeNode * tr)
{
  if (tr == NULL)
    {
      return;
    }
  deleteTreeNode (tr -> left);
  deleteTreeNode (tr -> right);
  free (tr);
}

void freeTree(Tree * tr)
{
  if (tr == NULL)
    {
      // nothing to delete
      return;
    }
  deleteTreeNode (tr -> root);
  free (tr);
}

static void preOrderNode(TreeNode * tn, FILE * fptr)
{
  if (tn == NULL)
    {
      return;
    }
  fprintf(fptr, "%d\n", tn -> value);
  preOrderNode(tn -> left, fptr);
  preOrderNode(tn -> right, fptr);
}

void preOrder(Tree * tr, char * filename)
{
  if (tr == NULL)
    {
      return;
    }
  FILE * fptr = fopen(filename, "w");
  preOrderNode(tr -> root, fptr);
  fclose (fptr);
}
// <<<--- UNTIL HERE

// ***
// *** You MUST modify the follow function
// ***

#ifdef TEST_BUILDTREE
// Consider the algorithm posted on
// https://www.geeksforgeeks.org/construct-a-binary-tree-from-postorder-and-inorder/

Tree * buildTree(int * inArray, int * postArray, int size)
{
  //Tree *tr = malloc(size);
  //TreeNode *n = newNode(5);
  //tr->root = n;
  //printf("%d",tr->root->value);
  
	TreeNode *r = build(inArray, postArray, size);
  Tree *tr = malloc(sizeof(Tree));
  tr->root = r;

	return(tr);
}

TreeNode *newNode(int val)
{
	TreeNode *node = (TreeNode*)malloc(sizeof(TreeNode));
	node->value = val;
  node->left = node->right = NULL;
  return(node);
}

int findVal(int arr[], int start, int end, int val)
{
  int i;
  for (i = start; i <= end; i++)
  {
    if (arr[i] == val)
		{
			break;
		}
  }
  return(i);
}

TreeNode* build(int inArr[], int postArr[], int size)
{
	int pIndex = size - 1;
  return(recursiveBuild(inArr,postArr,0,size - 1,&pIndex));
}

TreeNode* recursiveBuild(int inArr[], int postArr[], int start, int end, int *pIndex)
{
  if (start > end)
  {
		return(NULL);
	}
  
	TreeNode* node = newNode(postArr[*pIndex]);
  (*pIndex)--;

  if (start == end)
  {
    return(node);
  }

	int index = findVal(inArr, start, end, node->value);
  
  node->right = recursiveBuild(inArr, postArr, index + 1, end, pIndex);
  node->left = recursiveBuild(inArr, postArr, start, index - 1, pIndex);

  return(node);
}
#endif



