package leetcode

import "fmt"

// type MyQueue struct {
// 	Data int
// 	Next *MyQueue
// }

// func Constructor() MyQueue {
// 	return MyQueue{}
// }

// func (this *MyQueue) Push(x int) {
// 	var newNode *MyQueue = &MyQueue{Data: x}

// 	if this == nil {
// 		this = newNode
// 	} else {
// 		var tempQueue *MyQueue = this
// 		for tempQueue.Next != nil {
// 			tempQueue = tempQueue.Next
// 		}

// 		tempQueue.Next = newNode
// 	}
// }

// func (this *MyQueue) Pop() int {
// 	var result int = this.Data

// 	this = this.Next

// 	return result
// }

// func (this *MyQueue) Peek() int {
// 	return this.Data
// }

// func (this *MyQueue) Empty() bool {
// 	if this == nil {
// 		return true
// 	}

// 	return false
// }

// func (this *MyQueue) Show() {
// 	for this != nil {
// 		fmt.Println(this.Data)
// 		this = this.Next
// 	}
// }


type MyQueue struct {
	Data int
	Next *MyQueue
}

func Constructor() MyQueue {
	return MyQueue{}
}

func (this *MyQueue) Push(x int) {
	var newNode *MyQueue = &MyQueue{Data: x}

	if this == nil {
		this = newNode
	} else {
		var tempQueue *MyQueue = this
		for tempQueue.Next != nil {
			tempQueue = tempQueue.Next
		}

		tempQueue.Next = newNode
	}
}

func (this *MyQueue) Pop() int {
	var result int = this.Data

	this = this.Next

	return result
}

func (this *MyQueue) Peek() int {
	return this.Data
}

func (this *MyQueue) Empty() bool {
	if this == nil {
		return true
	}

	return false
}

func (this *MyQueue) Show() {
	for this != nil {
		fmt.Println(this.Data)
		this = this.Next
	}
}

/**
 * Your MyQueue object will be instantiated and called as such:
 * obj := Constructor();
 * obj.Push(x);
 * param_2 := obj.Pop();
 * param_3 := obj.Peek();
 * param_4 := obj.Empty();
 */