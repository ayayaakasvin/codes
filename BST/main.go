package main

import "fmt"

//Binary tree node struct
type BinaryNode struct {
	Value any
	Left *BinaryNode
	Right *BinaryNode
}

type PostOrderTraversalSlice []any

func initBaseBinaryTree () *BinaryNode {
	var base *BinaryNode = &BinaryNode{Value: 1}
	base.Left = &BinaryNode{Value: 2}
	base.Right = &BinaryNode{Value: 3}

	// left
	baseLeft := base.Left
	baseLeft.Left = &BinaryNode{Value: 4}
	baseLeft.Right = &BinaryNode{Value: 5}

	//right
	baseRight := base.Right
	baseRight.Right = &BinaryNode{Value: 8}

	//left right
	baseLeftRight := baseLeft.Right
	baseLeftRight.Left = &BinaryNode{Value: 6}
	baseLeftRight.Right = &BinaryNode{Value: 7}

	//right right
	baseRightRight := baseRight.Right
	baseRightRight.Left = &BinaryNode{Value: 9}

	return base
}


func (head *BinaryNode) PostOrderTraversal() PostOrderTraversalSlice {
	if head == nil {
		return PostOrderTraversalSlice{}
	}

	var result PostOrderTraversalSlice

	result = append(result, head.Left.PostOrderTraversal()...)

	result = append(result, head.Right.PostOrderTraversal()...)

	result = append(result, head.Value)

	return result
}

func (TreeAsSlice *PostOrderTraversalSlice) PrintSlice () {
	fmt.Println("PostOrder Traversal:")

	for _, Value := range *TreeAsSlice {
		fmt.Printf("%v ", Value)		
	}
}

func main() {
	var Tree *BinaryNode = initBaseBinaryTree()

	var ResultOfTraversal PostOrderTraversalSlice = Tree.PostOrderTraversal()

	ResultOfTraversal.PrintSlice()
}