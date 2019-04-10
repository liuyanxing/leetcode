function quickSort(nums, left, right) {
  if (left < right) {
    let partitionIndex = partition(nums, left, right)
    quickSort(nums, left, partitionIndex - 1)
    quickSort(nums, partitionIndex + 1, right)
  }
}

function partition(nums, left, right) {
  let pivot = left
  let index = pivot + 1
  for (let i = index; i <= right; ++i) {
    if (nums[i] < nums[pivot]) {
      swap(index++, i)
    }
  }
  swap(nums, pivot, --index)
  return index
}

function swap(nums, i, j) {
  let temp = nums[i]
  nums[i] = nums[j]
  nums[j] = temp
}

const nums = [3, 1, 2]
quickSort(nums, 0, nums.length - 1)
console.log(nums)