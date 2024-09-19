#pragma once
#include<stdio.h>
#include<assert.h>
#include<stdlib.h>
#include"Queue.h"
typedef char BTDataType;
typedef struct BinaruTreeNode
{
	struct BinaruTreeNode* left;
	struct BinaruTreeNode* right;
	BTDataType data;
}BTNode;
void PrevOrder(BTNode* root);
void InOrder(BTNode* root);
void PostOrder(BTNode* root);
int TreeSize(BTNode* root);
int TreeLeafSize(BTNode* root);
void LevelOrder(BTNode* root);
