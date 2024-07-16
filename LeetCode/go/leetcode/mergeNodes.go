package leetcode

/**
 * Definition for singly-linked list.
 * type ListNode struct {
 *     Val int
 *     Next *ListNode
 * }
 */

func mergeNodes(head *ListNode) *ListNode {
	var result *ListNode
	var node *ListNode
	var counter int

	for i := head.Next; i != nil; i = i.Next {
		if i.Val == 0 {
			if result == nil {
				result = &ListNode{Val: counter}
				node = result
			} else {
				node.Next = &ListNode{Val: counter}
				node = node.Next
			}
			
			counter = 0
		} else {
			counter += i.Val
		}
	}

	return result
}