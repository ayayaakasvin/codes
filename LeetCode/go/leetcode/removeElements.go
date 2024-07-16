package leetcode

/**
 * Definition for singly-linked list.
 * type ListNode struct {
 *     Val int
 *     Next *ListNode
 * }
 */
func removeElements(head *ListNode, val int) *ListNode {
	var result *ListNode = head
    var current *ListNode = result

	for result != nil && result.Val == val {
		result = result.Next
	}

	for current != nil && current.Next != nil {
		if current.Next.Val == val {
			current.Next = current.Next.Next
		} else {
			current = current.Next			
		}
		
	}

	return result
}