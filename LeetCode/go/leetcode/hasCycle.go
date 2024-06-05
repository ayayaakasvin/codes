package leetcode

/**
 * Definition for singly-linked list.
 * type ListNode struct {
 *     Val int
 *     Next *ListNode
 * }
 */

func isCycled(LinkedList *ListNode) bool {
	var (
		slowPointer, fastPointer *ListNode = LinkedList, LinkedList
	)

	for ; slowPointer.Next != nil && fastPointer.Next != nil && fastPointer.Next.Next != nil ; {
		slowPointer = slowPointer.Next
		fastPointer = fastPointer.Next.Next

		if slowPointer == fastPointer {
			return true
		}
	}

	return false
}

func hasCycle(head *ListNode) bool {    
	if head == nil {
		return false
	}

	return isCycled(head)
}