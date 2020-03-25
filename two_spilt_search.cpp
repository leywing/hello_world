#include "leetcode.h"

int two_spilt_search(vector<int>& nums, int target) {
	int nums_size = nums.size();

	int left = 0;
	int right = nums_size - 1;

	if (nums_size == 0) return -1;
	else if (nums_size == 1) return (nums[0] == target ? 0 : -1);
	else {
		//nums_size>=2
		int mid = (left + right + 1) / 2 - 1;
		while (1) {
			if (nums[mid] == target) return mid;
			else if (nums[mid + 1] == target) return mid + 1;
			else if (target < nums[mid]) {
				right = mid - 1;
			}
			else {
				//nums[mid]<target
				left = mid + 1;
			}

			if (left > right) { return -1; }
			if (right - left == 1) {
				if (nums[left] == target) return left;
				else if (nums[right] == target) return right;
				else return -1;
			}
			if (right == left) {
				if (nums[left] == target) return left;
				else return -1;
			}

			mid = (left + right + 1) / 2 - 1;

		}

	}
}