#include<iostream>
using namespace std;

class Tree{
	int element;
	Tree *left;
	Tree *right;
}

void MorrisTraversal(struct tNode *root)
{
	struct tNode *current, *pre;
	if(root == NULL)
		return;
	
	current=root;
	while(current != NULL)
	{
		if(current -> left == NULL)
		{
			printf("%d", current->data);
			current = current->right;
		}
		else{
			//left is not null, so replace node from left as root 
			/* Find inorder predecessor of current..*/
			pre = current->left;
			while(pre->right != NULL && pre->right != current)
				pre = pre->right;
			/* Make current as right child of its inorder predecessor */
			if(pre->right == NULL)
			{
				pre->right = current;
				current = current->left;
			}
			//MAGIC of restoring the tree happens here :
			/*
			*Revert the changes made in if part to restore the original trtee, i.e., fix the right child of predecssor
			*/
			else{
				pre->right = NULL;
				printf(" %d", current->data);
				current = current->right;
			}
		}
	}
}
