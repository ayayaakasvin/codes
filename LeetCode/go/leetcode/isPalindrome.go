package leetcode

import "strconv"
import "fmt"

type ListNode struct {
    Val int
    Next *ListNode
}

func (Node *ListNode) Display () {
	var current *ListNode = Node
	for ;current != nil ; {
		fmt.Printf("%d -> ", current.Val)
	}
}


func isPalindrome(head *ListNode) bool {
	var strList string

	for i := head; i != nil; i = i.Next{
		strList += strconv.FormatInt(int64(i.Val), 10)
	}

	return true
}