// ***
// *** You MUST modify this file
// ***

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "tree.h"
#include <stdbool.h>

TreeNode* newNode(int val);
int findVal (int arr[], int, int, int);
TreeNode* build(int inArr[], int postArr[], int);
TreeNode* recursiveBuild(int inArr[], int postArr[], int, int, int*);
bool checkPath(TreeNode*, int arr[], int);
void del(int arr[]);
void add(int arr[], int val);
void printArr (int arr[]);

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

#ifdef TEST_PRINTPATH
void printPath(Tree *tr, int val)
{
  int arr[20];
  int i;
  for (i = 0; i < 20; i++)
  {
		arr[i] = 0;
  }
	
	if (checkPath(tr->root,arr,val) == true)
	{
		for (i = 20; i > 0; i--)
		{
			if (arr[i] < 10000 && arr[i] != 0)
			{
				printf("%d\n",arr[i]);
			}		
		}
	}
  printf("%d\n",tr->root->value);
  
	return;
}

bool checkPath(TreeNode* r, int arr[], int val)
{
	if (r == NULL)
	{
		return false;
	}
	
	add(arr,r->value);

	if (r->value == val)
	{
		return true;
	}		

	if (checkPath(r->left, arr, val) == true || checkPath(r->right,arr,val) == true)
	{
		return true;
	}

	del(arr);
	return false;
}
void del(int arr[])
{
	int i;
	for (i = 0; i < 20; i++)
	{
		if (arr[i] == 0)
		{
			arr[i - 1] = 0;			
			return;
		}
	}
	return;
}
void add(int arr[], int val)
{
	int i;
	for (i = 0; i < 20; i++)
	{
		if (arr[i] == 0)
		{
			arr[i] = val;		
			return;
		}
	}
	return;
}
void printArr (int arr[])
{
		for (int i = 0; i < 20; i++)
		{
			printf("%d ", arr[i]);
		}
		printf("\n");
}
#endif





























