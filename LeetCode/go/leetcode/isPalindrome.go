package leetcode

import "strconv"

type ListNode struct {
    Val int
    Next *ListNode
}


func isPalindrome(head *ListNode) bool {
	var strList string

	for i := head; i != nil; i = i.Next{
		strList += strconv.FormatInt(int64(i.Val), 10)
	}

	return true
}