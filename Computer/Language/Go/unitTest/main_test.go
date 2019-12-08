package test

import (
	"testing"
	yl "yalyu.com/mylib"
)

func TestMyTest (t *testing.T){
	yl.MyTest()
	t.Log("the result is ok")
	//t.Fatal("the result is wrong")
}

func max(i, j int) int {
	if i >= j {
		return i
	} else {
		return j
	}
}

func min(i, j int) int {
	if i <= j {
		return i
	} else {
		return j
	}
}
