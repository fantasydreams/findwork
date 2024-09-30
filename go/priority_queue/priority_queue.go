package priority_queue

import (
	"container/heap"
)

type PriorityQueueItem struct {
	ticker uint64
	val    int
}

type PriorityQueue []*PriorityQueueItem

func (pq PriorityQueue) Len() int {
	return len(pq)
}

func (pq PriorityQueue) Less(i, j int) bool {
	return pq[i].ticker < pq[j].ticker
}

func (pq PriorityQueue) Swap(i, j int) {
	pq[i], pq[j] = pq[j], pq[i]
}

func (pq *PriorityQueue) Push(elem interface{}) {
	*pq = append(*pq, elem.(*PriorityQueueItem))
}

func (pq *PriorityQueue) Pop() interface{} {
	old := *pq
	queLen := len(old)
	el := old[queLen-1]
	*pq = old[:queLen-1]
	return el
}

func (pq *PriorityQueue) Peek() interface{} {
	return (*pq)[0]
}

func (pq *PriorityQueue) Init() {
	heap.Init(pq)
}

func (pq *PriorityQueue) HeapPush(elem interface{}) {
	heap.Push(pq, elem)
}

func (pq *PriorityQueue) HeapPop() interface{} {
	elem := heap.Pop(pq)
	return elem
}

func (pq *PriorityQueue) HeapPeek() interface{} {
	return pq.Peek()
}
