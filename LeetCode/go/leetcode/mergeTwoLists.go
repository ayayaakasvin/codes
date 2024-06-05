package leetcode

/**
 * Definition for singly-linked list.
 * type ListNode struct {
 *     Val int
 *     Next *ListNode
 * }
 */

func mergeTwoLists(list1 *ListNode, list2 *ListNode) *ListNode {
    var buffer, temp *ListNode
    buffer = &ListNode{}
    temp = buffer

    for list1 != nil && list2 != nil {
        if list1.Val > list2.Val {
            temp.Next = list2
            list2 = list2.Next
        } else {
            temp.Next = list1
            list1 = list1.Next
        }
        
        temp = temp.Next
    }

    if list1 == nil {
        temp.Next = list2
    } else {
        temp.Next = list1
    }

    return buffer.Next
}