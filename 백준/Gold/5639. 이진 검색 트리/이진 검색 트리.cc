#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>

typedef struct Tree* tree;
struct Tree {
	int data;
	tree left;
	tree right;
};

void postorder(tree ptr)
{
	if (ptr)
	{
		postorder(ptr->left);
		postorder(ptr->right);
		printf("%d\n", ptr->data);
	}
}

int main(void)
{
	tree root = NULL;
	int num;
	while (scanf("%d", &num) != EOF)
	{
		tree tmp = (tree)malloc(sizeof(*tmp));
		tmp->data = num;
		tmp->left = NULL;
		tmp->right = NULL;
		if (root == NULL)
		{
			root = tmp;
		}
		else
		{
			tree node = root;
			while (node != NULL)
			{
				if (node->data > tmp->data)
				{
					if (node->left == NULL)
					{
						node->left = tmp;
						break;
					}
					else
					{
						node = node->left;
					}
				}
				else
				{
					if (node->right == NULL)
					{
						node->right = tmp;
						break;
					}
					else
					{
						node = node->right;
					}
				}
			}
		}
	}
	postorder(root);
	return 0;
}