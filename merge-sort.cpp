#include <vector>
#include <iostream>

using namespace std;

void merge(vector<int> &nums, int left, int middle, int right) {
  vector<int> leftArray(nums.begin() + left, nums.begin() + middle);
  vector<int> rightArray(nums.begin() + middle, nums.begin() + right + 1);

  int i = 0, j = 0, k = left;
  while(i < leftArray.size() && j < rightArray.size()){
    if (leftArray[i] <= rightArray[j]) {
      nums[k] = leftArray[i];
      i++;
    } else {
      nums[k] = rightArray[j];
      j++;
    }
    k++;
  }
  
  while(i < leftArray.size()){
    nums[k] = leftArray[i];
    i++;
    k++;
  }

  while(j < rightArray[j]){
    /* code */
    nums[k] = rightArray[j];
    j++;
    k++;
  }
}

void mergeSort(vector<int> &nums, int left, int right) {
  if (left < right) {
    int middle = left + (right - left) / 2;
    mergeSort(nums, left, middle);
    mergeSort(nums, middle, right);
    merge(nums, left, middle, right);
  }
  return;
}

void sort(vector<int> &nums) {
  mergeSort(nums, 0, nums.size() - 1);
}

int main() {
  vector<int> nums;
  nums.push_back(3);
  nums.push_back(2);
  sort(nums);
}