class Solution {
public:
    void swap(int *a, int *b){
	int tmp = *a;
	*a = *b;
	*b = tmp;
}
int partition(vector<int>& nums, int start, int end){
	int pivot = nums[start];
	int i = start + 1;
	for (int j = start + 1; j <= end; j++){
		if (nums[j] < pivot){
			swap(&nums[i], &nums[j]);
			i++;
		}
	}
	swap(&nums[start], &nums[i - 1]);
	return i - 1;
}
int qsort(vector<int>& nums, int start, int end, int k){
	if (start<=end){
		int pivot = partition(nums, start, end);
		if (pivot == k){
			return nums[k];
		}
		else if (pivot>k){
			return qsort(nums, start, pivot - 1, k);
		}
		else{
			return qsort(nums, pivot + 1, end, k);
		}
	}
	return -1;
}
int findKthLargest(vector<int>& nums, int k) {
	int n = nums.size();

	k = n - k;
	return qsort(nums, 0, n - 1, k);
}
};
