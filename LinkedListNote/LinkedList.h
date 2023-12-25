#pragma once

#include <stdio.h>
#include <stdlib.h>

typedef int ElementType;

typedef struct tagNode
{
	ElementType Data;
	struct tagNode* NextNode;
}Node;

// �Լ� ���� ����
Node* SLL_CreateNode(ElementType NewData);						   // ��� ����
void  SLL_DestroyNode(Node* Node);								   // ��� �Ҹ�
void  SLL_DestroyAllNode(Node** List);							   // ��� ��� �Ҹ�
void  SLL_AppendNode(Node** Head, Node* NewNode);				   // ��� �߰�
void  SLL_InsertBefore(Node** Head, Node* Current, Node* NewNode); // ��� �տ� ����
void  SLL_InsertAfter(Node* Current, Node* NewNode);			   // ��� �ڿ� ����
void  SLL_InsertNewHead(Node** Head, Node* NewHead);			   // ��� ��� ����
void  SLL_RemoveNode(Node** Head, Node* Remove);				   // ��� ����
Node* SLL_GetNodeAt(Node* Head, int Location);					   // ��� Ž��
int	  SLL_GetNodeCount(Node* Head);								   // ��� ���� ����