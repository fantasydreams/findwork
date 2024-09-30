package priority_queue

import (
	"testing"

	"github.com/stretchr/testify/require"
)

func TestHeap(t *testing.T) {
	pq := &PriorityQueue{}
	*pq = append(*pq, &PriorityQueueItem{
		ticker: 6,
		val:    1,
	})
	*pq = append(*pq, &PriorityQueueItem{
		ticker: 5,
		val:    2,
	})

	*pq = append(*pq, &PriorityQueueItem{
		ticker: 4,
		val:    5,
	})

	pq.Init()
	item := pq.HeapPeek()
	elem, ok := item.(*PriorityQueueItem)
	require.True(t, ok && elem.ticker == 4 && elem.val == 5)

	item = pq.HeapPop()
	elem, ok = item.(*PriorityQueueItem)
	require.True(t, ok && elem.ticker == 4 && elem.val == 5)

	item = pq.HeapPeek()
	elem, ok = item.(*PriorityQueueItem)
	require.True(t, ok && elem.ticker == 5 && elem.val == 2)

	item = pq.HeapPop()
	elem, ok = item.(*PriorityQueueItem)
	require.True(t, ok && elem.ticker == 5 && elem.val == 2)

	pq.HeapPush(&PriorityQueueItem{
		ticker: 3,
		val:    4,
	})

	item = pq.HeapPeek()
	elem, ok = item.(*PriorityQueueItem)
	require.True(t, ok && elem.ticker == 3 && elem.val == 4)

	item = pq.HeapPop()
	elem, ok = item.(*PriorityQueueItem)
	require.True(t, ok && elem.ticker == 3 && elem.val == 4)

	item = pq.HeapPeek()
	elem, ok = item.(*PriorityQueueItem)
	require.True(t, ok && elem.ticker == 6 && elem.val == 1)

	item = pq.HeapPop()
	elem, ok = item.(*PriorityQueueItem)
	require.True(t, ok && elem.ticker == 6 && elem.val == 1)
}
