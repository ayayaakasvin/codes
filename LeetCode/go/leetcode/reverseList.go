package leetcode

/**
 * Definition for singly-linked list.
 * type ListNode struct {
 *     Val int
 *     Next *ListNode
 * }
 */
 
func reverseList(head *ListNode) *ListNode {
    var result *ListNode = &ListNode{}
	var current *ListNode = head
	
	for  ; current != nil ; {
		var forward *ListNode = current.Next
		current.Next = result
		result = current
		current = forward
	}

	return result
}