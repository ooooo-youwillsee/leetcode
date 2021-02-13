package main

func findDisappearedNumbers(nums []int) []int {
	for i := 0; i < len(nums); {
		num := nums[i]
		if num != i+1 && nums[i] != nums[num-1] {
			nums[i], nums[num-1] = nums[num-1], nums[i]
		} else {
			i++
		}
	}

	ans := make([]int, 0)
	for i := 0; i < len(nums); i++ {
		if nums[i] != i+1 {
			ans = append(ans, i+1)
		}
	}
	return ans
}

func main() {

}
