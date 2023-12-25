#include "LinkedList.h"

int main()
{
	int   i		  = 0;
	int   Count   = 0;
	Node* List    = NULL;
	Node* Current = NULL;
	Node* NewNode = NULL;

	// 노드 5개 추가
	printf("Node 5개 추가\n");
	for (i = 0; i < 5; i++)
	{
		NewNode = SLL_CreateNode(i);
		SLL_AppendNode(&List, NewNode);
	}

	NewNode = SLL_CreateNode(-1);
	SLL_InsertNewHead(&List, NewNode);
	
	NewNode = SLL_CreateNode(-2);
	SLL_InsertNewHead(&List, NewNode);

	// 리스트 출력
	printf("Node 리스트 출력\n");
	Count = SLL_GetNodeCount(List);
	for (i = 0; i < Count; i++)
	{
		Current = SLL_GetNodeAt(List, i);
		printf("List[%d] : %d\n", i, Current->Data);
	}

	// 리스트의 세 번째 노드 뒤에 새 노드 삽입
	printf("\nInserting 3000 After [2]...\n\n");

	Current = SLL_GetNodeAt(List, 2);
	NewNode = SLL_CreateNode(3000);

	SLL_InsertAfter(Current, NewNode);

	// 리스트의 세 번째 노드 앞에 새 노드 삽입
	printf("\nInserting 5000 Before [2]...\n\n");
	Current = SLL_GetNodeAt(List, 2);
	NewNode = SLL_CreateNode(5000);

	SLL_InsertBefore(&List, Current, NewNode);

	// 리스트 출력
	printf("Node 리스트 출력\n");
	Count = SLL_GetNodeCount(List);
	for (i = 0; i < Count; i++)
	{
		Current = SLL_GetNodeAt(List, i);
		printf("List[%d] : %d\n", i, Current->Data);
	}

	// 모든 노드를 메모리에서 제거
	printf("\nDestroying List...\n");

	for (i = 0; i < Count; i++)
	{
		Current = SLL_GetNodeAt(List, 0);

		if (Current != NULL)
		{
			SLL_RemoveNode(&List, Current);
			SLL_DestroyNode(Current);
		}
	}

	// 모든 노드를 한번에 메모리에서 제거
	SLL_DestroyAllNode(&List);

	Count = SLL_GetNodeCount(List);

	if (Count <= 0)
	{
		printf("None");
	}

	for (i = 0; i < Count; i++)
	{
		
		Current = SLL_GetNodeAt(List, i);
		printf("List[%d] : %d\n", i, Current->Data);
	}

	return 0;
}