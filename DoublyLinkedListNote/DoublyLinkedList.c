#include "DoublyLinkedList.h"

// ��� ����
Node* DLL_CreateNode(ElementType NewData)
{
	Node* NewNode = (Node*)malloc(sizeof(Node));

	NewNode->Data = NewData;  // �����͸� �����Ѵ�.
	NewNode->PrevNode = NULL; // ���� ��忡 ���� �����ʹ� NULL�� �ʱ�ȭ�Ѵ�.
	NewNode->NextNode = NULL; // ���� ��忡 ���� �����ʹ� NULL�� �ʱ�ȭ�Ѵ�.

	return NewNode; // ����� �ּҸ� ��ȯ�Ѵ�.
}

// ��� �Ҹ�
void DLL_DestroyNode(Node* Node)
{
	free(Node);
}

// ��� �߰�
void  DLL_AppendNode(Node** Head, Node* NewNode)
{
	// ��� ��尡 NULL�̶�� ���ο� ��尡 Head�� �ȴ�.
	if ((*Head) == NULL)
	{
		*Head = NewNode;
	}
	else
	{
		// ������ ã�� NewNode�� �����Ѵ�.
		Node* Tail = (*Head);
		while (Tail->NextNode != NULL)
		{
			Tail = Tail->NextNode;
		}

		Tail->NextNode = NewNode;
		NewNode->PrevNode = Tail; // ���� ������ ���ο� ������ PrevNode�� ����Ų��.
	}
}

// ��� ����
void DLL_InsertAfter(Node* Current, Node* NewNode)
{
	NewNode->NextNode = Current->NextNode;
	NewNode->PrevNode = Current;

	if (Current->NextNode != NULL)
	{
		Current->NextNode->PrevNode = NewNode;
		Current->NextNode = NewNode;
	}
}

// ��� ����
void DLL_RemoveNode(Node** Head, Node* Remove)
{
	if (*Head == Remove)
	{
		*Head = Remove->NextNode;
		if ((*Head) != NULL)
			(*Head)->PrevNode = NULL;

		Remove->PrevNode = NULL;
		Remove->NextNode = NULL;
	}
	else
	{
		Node* Temp = Remove;

		/*if (Remove->PrevNode != NULL)
			Remove->PrevNode->NextNode = Remove->NextNode;*/ // �ڵ� ����ȭ

		if (Remove->PrevNode != NULL)
			Remove->PrevNode->NextNode = Temp->NextNode;

		if (Remove->NextNode != NULL)
			Remove->NextNode->PrevNode = Temp->PrevNode;

		Remove->PrevNode = NULL;
		Remove->NextNode = NULL;
	}
}

// ��� Ž��
Node* DLL_GetNodeAt(Node* Head, int Location)
{
	Node* Current = Head;

	while (Current != NULL && (--Location) >= 0)
	{
		Current = Current->NextNode;
	}

	return Current;
}

// ��� ���� ����
int	DLL_GetNodeCount(Node* Head)
{
	unsigned int Count = 0;
	Node*		 Current = Head;

	while (Current != NULL)
	{
		Current = Current->NextNode;
		Count++;
	}

	return Count;
}

// ���� ��ũ�� ����Ʈ�� �������� ���
void  PrintReverse(Node* Head)
{
	int Count = DLL_GetNodeCount(Head);
	Node* Current = Head;

	while (Count--)
	{
		Current = DLL_GetNodeAt(Head, Count);
		printf("List[%d] : %d\n", Count, Current->Data);
	}
}

void PrintNode(Node* _Node)
{
	if (_Node->PrevNode == NULL)
		printf("Prev: NULL\n");
	else
		printf("Prev: %d\n", _Node->PrevNode->Data);

	printf("Current: %d\n", _Node->Data);

	if (_Node->NextNode == NULL)
		printf("Next: NULL\n");
	else
		printf("Next: %d\n", _Node->NextNode->Data);
}