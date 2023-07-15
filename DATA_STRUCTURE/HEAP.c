#include <stdio.h>
#define MAX_ELEMENT 200

typedef struct
{
	int key;
}element;

typedef struct
{
	element heap[MAX_ELEMENT];
	int heap_size;
}HeapType;

HeapType heap1;
/*현재 요소의 개수가 heap_size인 힙 h에 item을 삽입한다.*/
void insert_max_heap(HeapType* h, element item)
{
	int i;
	i = ++(h->heap_size); //힙 크기를 하나 증가

	/*트리를 거슬러 올라가면서 부모 노드와 비교하는 과정*/
	//i가 루트노드가 아니고, 삽입할 tiem의 값이 i의 부모노드보다 크면
	while ((i != 1) && (item.key > h->heap[i / 2].key))
	{
		//i번째 노드와 부모노드를 교환
		h->heap[i] = h->heap[i / 2];
		//한 레벨 위로 올라감
		i /= 2;
	}
	h->heap[i] = item;
}

element delete_max_heap(HeapType* h)
{
	int parent, child;
	element item, temp;

	item = h->heap[1];
	temp = h->heap[(h->heap_size)--];
	parent = 1;
	child = 2;

	while (child <= h->heap_size)
	{
		//현재 노드의 자식 노드 중 더 큰 자식 노드를 찾는다.
		if ((child < h->heap_size) && ((h->heap[child].key) < h->heap[child + 1].key))
		{
			child++;
		}
		//더 큰 자식노드보다 마지막 노드가 크면,while문 중지
		if (temp.key >= h->heap[child].key)
			break;


		h->heap[parent] = h->heap[child];
		//한 단계 아래로 이동
		parent = child;
		child *= 2;
	}
	//마지막 노드를 재구성한 위치에 삽입
	h->heap[parent] = temp;

	return item;
}
