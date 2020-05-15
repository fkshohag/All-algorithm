package main

import "fmt"

func partition(list []int, low int, high int) (int, []int) {
	counter, pivot := low-1, list[high]
	for i := low; i < high; i++ {
		if list[i] <= pivot {
			counter++
			list[counter], list[i] = list[i], list[counter]
		}
	}
	list[counter+1], list[high] = list[high], list[counter+1]
	return counter + 1, list
}

func quickSort(list []int, low int, high int) []int {
	if low < high {
		mid, list := partition(list, low, high)
		quickSort(list, low, mid-1)
		quickSort(list, mid+1, high)
	}
	return list
}

func main() {
	var list = []int{1, -34, 4, 34, -3, 43, 5, 56, 3}
	result := quickSort(list, 0, len(list)-1)
	fmt.Println(result)
}
