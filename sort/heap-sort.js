function swap(nums, i, j) {
  let temp = nums[i]
  nums[i] = nums[j]
  nums[j] = temp
}

function heapify(arr, n, i) {
  let largest = i
  let l = 2 * i + 1
  let r = 2 * i + 2
  if (l < n && arr[l] > arr[largest]) {
    largest = l
  }
  if (r < n && arr[r] > arr[largest]) {
    largest = r
  }
  if (largest !== i) {
    swap(arr, i, largest)
    heapify(arr, n, largest)
  }
}

function heapSort(arr) {
  for (let i = (arr.length / 2 - 1) | 0; i >=0; i--)  {
    heapify(arr, arr.length, i)
  }
  for (let i = arr.length - 1; i >= 0 ; i--) {
    swap(arr, 0, i)
    heapify(arr, arr.length, i)
  }
}

let arr = [3, 2, 1]
heapSort(arr)
console.log(arr)
