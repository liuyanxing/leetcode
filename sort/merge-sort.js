function mergeSort(nums, left, right) {
  if (left < right) {
    const middle = left + Math.floor((right - left) / 2)
    mergeSort(nums, left, middle)
    mergeSort(nums, middle + 1, right)
    merge(nums, left, middle, right)
  }
}

function merge(nums, left, middle, right) {
  console.log('left', left, 'middle', middle, 'right', right)
  const leftArray = nums.slice(left, middle)
  const rightArray = nums.slice(middle, right + 1)
  let i = 0, j = 0, k = left
  while (i < leftArray.length && j < rightArray.length) {
    if (leftArray[i] <= rightArray[j]) {
      nums[k] = leftArray[i]
      i++
    } else {
      nums[k] = rightArray[j]
      j++
    }
    k++
  }
  while (i < leftArray.length) {
    nums[k] = leftArray[i]
    i++
    k++
  }
  while (j < rightArray.length) {
    nums[k] = rightArray[j]
    j++
    k++
  }
}

const nums = [3, 2, 1]
mergeSort(nums, 0 , nums.length - 1)
console.log(nums)