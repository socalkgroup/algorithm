package main

import (
	"fmt"
	"sort"
)
type twodimension [][]int


func (twa twodimension) Len() int { return len(twa) }
func (twa twodimension) Swap(i,j int) {twa[i],twa[j] = twa[j],twa[i] }
func (twa twodimension) Less(i, j int) bool { 
	if (twa[i][0] < twa[j][0]) {
		return true
	} else if (twa[i][0] == twa[j][0])  {
		if  twa[i][1] <= twa[j][1] {
			return false
		} else {
			return true
		}
	} else {
		return false
	}
}


func calintersect(inputarray []int) int {
	var events twodimension
	for index,element:= range inputarray{
		events=append(events,[]int{index-element,1})
		events=append(events,[]int{index+element,-1})
	}
	sort.Sort(events)

	intersections, active_circles := 0, 0
	// active circles is being calculated with secdon element of array elment. 
	// Whenever new disk is added, calculate intersections. 
	
	for _, circle_delta_count:= range events {
		if circle_delta_count[1] > 0 {
			intersections += active_circles * circle_delta_count[1]
		}
		active_circles += circle_delta_count[1]
	}
	return intersections
}

func main() {	
	values := []int{1,5,2,1,4,0}
	fmt.Println(calintersect(values))
	// get the lef values
	
}