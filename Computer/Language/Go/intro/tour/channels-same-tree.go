package main

import (
	"golang.org/x/tour/tree"
	"fmt"
)
// 存在一些问题, 就是一棵树遍历完了, 另一个棵树没遍历完算不算相同?

//  发送value，结束后关闭channel
func Walk(t *tree.Tree, ch chan int){
    sendValue(t,ch)
    close(ch)
}
//  递归向channel传值
func sendValue(t *tree.Tree, ch chan int){
    if t != nil {
        sendValue(t.Left, ch)
        ch <- t.Value
        sendValue(t.Right, ch)
   }
}

// 使用写好的Walk函数来确定两个tree对象  是否一样 原理还是判断value值
func Same(t1, t2 *tree.Tree) bool {
       ch1 := make(chan int)
       ch2 := make(chan int)
       go Walk(t1,ch1)
       go Walk(t2,ch2)
	   for i := range ch1 {   // ch1 关闭后   for循环自动跳出
               v, isClose := <- ch2
               if !isClose && i!= v {
                    return false
               }
	   }
	   
	   _, isClose := <- ch2
	   if isClose {
			return true
	   } else {
		   return false
	   }
}

func main() {
	

    // 打印 tree.New(1)的值
    var ch = make(chan int)
    go Walk(tree.New(1),ch)
    for v := range ch {
          fmt.Println(v)
    }

    //  比较两个tree的value值是否相等
    fmt.Println(Same(tree.New(1), tree.New(1)))
    fmt.Println(Same(tree.New(1), tree.New(2)))
}
