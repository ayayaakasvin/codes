package leetcode

/**
 * Definition for singly-linked list.
 * type ListNode struct {
 *     Val int
 *     Next *ListNode
 * }
 */

func deleteDuplicates(head *ListNode) *ListNode {
	var result *ListNode = head
	var current *ListNode = result

	for ; current != nil && current.Next != nil ; {
		if current.Val == current.Next.Val{
			current.Next = current.Next.Next
		} else {
			current = current.Next
		}
	}

	return result
}