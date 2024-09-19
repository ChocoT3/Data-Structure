#define	_CRT_SECURE_NO_WARNINGS
#include"BinaryTree.h"
void PrevOrder(BTNode* root)
{
	if (root == NULL)
	{
		printf("NULL ");
		return;
	}
	printf("%c ", root->data);
	PrevOrder(root->left);
	PrevOrder(root->right);
}
void InOrder(BTNode* root)
{
	if (root == NULL)
	{
		printf("NULL ");
		return;
	}
	InOrder(root->left);
	printf("%c ", root->data);
	InOrder(root->right);
}
void PostOrder(BTNode* root)
{
	if (root == NULL)
	{
		printf("NULL ");
		return;
	}
	PostOrder(root->left);
	PostOrder(root->right);
	printf("%c ", root->data);
}
int TreeSize(BTNode* root)
{
	return root == NULL ? 0 : TreeSize(root->left) + TreeSize(root->right) + 1;
}
int TreeLeafSize(BTNode* root)
{
	if (root == NULL)
		return 0;
	if (root->left == NULL && root->right == NULL)
		return 1;
	return TreeLeafSize(root->left) + TreeLeafSize(root->right);
}
void LevelOrder(BTNode* root)
{
	Queue q;
	QueueInit(&q);
	
	if (root)
		QueuePush(&q, root);
	while (!QueueEmpty(&q))
	{
		QDataType front = QueueFront(&q);
		QueuePop(&q);
		printf("%c ", front->data);
		if (root->left)
			QueuePush(&q, front->left);
		if (root->right)
			QueuePush(&q, front->right);
	}
	printf("\n");
	QueueDestory(&q);
}
