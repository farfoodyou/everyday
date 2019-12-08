package main

import (
	"fmt"
	"sync"
	"sort"
	yl "yalyu.com/mylib"
)
type DSType int
const (
	StackType DSType = iota
	QueueType
	PriorityQueueType
	MapType
	V1Type
	V2Type
)

type node struct {
	value Item
	next *node
}

type Item struct {
	v1 int
	v2 int
	v3 int
}

func main(){

	tmp := "This is a var tmp file"

	fmt.Println("Hello, world. \n", tmp)

	mp := make(map[string]string, 10)
	mp["01"] = "are you ok?"

	fmt.Println("Hello, world. \n", tmp, mp)

	// .(type)演示, 不推荐的用法.
	var interfacer interface{}
	interfacer = mp
	switch interfacer.(type) {
	case string:
		fmt.Println("Type is string")
	case map[string]string:
		fmt.Println("Type is map[string]string")
	}

	// 常见初始化方法
	item := Item{1, 2, 3}
	item2 := &Item{
		v1 : 1,
		v2 : 3,
	}

	node_Ptr := &node{
		value: item,
		next: nil,
	}

	head := node{
		value: item,
		next: nil,
	}

	head.next = node_Ptr

	(&head).print()
	head.print()

	fmt.Printf("Head: %+v\n", head)
	fmt.Println("Head: \n", node_Ptr, head, item2)

	newHead := new([3]node)

	fmt.Printf("newHead: %+v\n", newHead)

	// 初始化 n*m的二维切片
	rows := 3
	cols := 4
	dp := make([][]int, rows)
	for i:= 0; i<len(dp); i++ {
		dp[i] = make([]int, cols)
	}
	
	fmt.Printf("newHead: %+v\n", dp)
	printV2(dp)

	dp2 := make([][]int, 3)
	copy(dp2, dp)
	
	printV2(dp2)
	var wg sync.WaitGroup
	wg.Add(1)
	go func(wg *sync.WaitGroup){  
		defer wg.Done()
		fmt.Printf("============================================\n")
	}(&wg)
	wg.Wait()

	cdp := dp2
	printV2(cdp)
	printType(dp2)

	fmt.Printf("====================get[]========================\n")
	printV2(getV2(4,3))

	yl.MyTest()

	// append 
	a := []int{1, 2, 3}
	b := []int{2, 3, 4, 5, 6}
	a = append(a, b...)
	printV1(a)
	sort.Ints(a)
	printV1(a)
	
	v1Ptr := new(V1)
	*v1Ptr = append(*v1Ptr, a...)
	sort.Sort(v1Ptr)
	PrintV1(*v1Ptr)
}	

type V1 []int
func (slice V1)Len()int {
	return len(slice)
}
func (slice V1)Less(i, j int)bool {
	return (slice[i]>slice[j])
}
func (slice V1)Swap(i, j int){
	slice[j], slice[i] = slice[i], slice[j]
}

	
// 打印链表所有的值
func (p *node) print() error{
	for p != nil {
		fmt.Printf("value: %+v\n", p.value)
		p = p.next
	}
	return nil;
}
// 打印1维切片
func PrintV1(vec V1) {
	fmt.Printf("\n")
	for k, v1 := range vec {
		fmt.Printf("%d: %+v \n", k, v1)
	}
}

// 打印1维切片
func printV1(vec2 []int) {
	fmt.Printf("\n")
	for k, v1 := range vec2 {
		fmt.Printf("%d: %+v \n", k, v1)
	}
}

// 打印二维切片
func printV2(vec2 [][]int) {
	for k, v1 := range vec2 {
		fmt.Printf("row %d: %+v\n", k, v1)
	}
}

// 获取一维切片
func getV1(len int)[]int{
	return make([]int, len)
}

// 获取二维切片
func getV2(rows,cols int)[][]int{
	V2 := make([][]int, rows)
	for i:= 0; i<len(V2); i++ {
		V2[i] = make([]int, cols)
	}
	return V2
}

// 判断变量的类型
func printType(i interface{}){
	switch i.(type) {
	case [][]int:
		fmt.Println("Type is [][]int")
	case []int:
		fmt.Println("Type is []int")
	case int:
		fmt.Println("Type is int")
	case string:
		fmt.Println("Type is string")
	case map[string]string:
		fmt.Println("Type is map[string]string")
	}
}

type Element struct {
	value int
}

// 栈
type Stack interface {
	Length() int
	Push() error
	Pop() error
	Size() int
}

// 队列
type Queue interface {
	FrontPush(ele Element) error
	Push(ele Element) error
	Pop() Element
}

// 优先队列
type PriorityQueue interface {
	Top() Element
	Push(ele Element) error
	Pop() Element
}

