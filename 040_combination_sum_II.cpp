#include "leetcode.h"

class Solution {
public:
	vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
		sort(candidates.begin(), candidates.end());
		int candi_size = candidates.size();
		vector<vector<int>> ans;
		//vector<int> a;
		for (int i = candi_size - 1; i >= 0; i--) {
			if (target >= candidates[i]) {
				vector<int> a;
				comsum(candidates, target, i + 1, a, ans);
			}
			else {
				continue;
			}
		}

		return ans;
	}

	void comsum(vector<int>& candidates, int target, int k, vector<int>& temp_vector, vector<vector<int>>& temp_ans) {
		if (k == 0) return;

		if (target - candidates[k - 1] > 0) {
			temp_vector.push_back(candidates[k - 1]);
			comsum(candidates, target - candidates[k - 1], k - 1, temp_vector, temp_ans);

			for (int i = 2; i < =k; i++) {
				if(candidates[k-i])
			}
		}









		if (target - candidates[k - 1] > 0) {
			temp_vector.push_back(candidates[k - 1]);
			comsum(candidates, target - candidates[k - 1], k-1, temp_vector, temp_ans);

			if (temp_vector.size() >= 2) {
				temp_vector.pop_back();
				comsum(candidates, target, k - 1, temp_vector, temp_ans);
			}

		}
		else if (target - candidates[k - 1] == 0) {
			temp_vector.push_back(candidates[k - 1]);
			temp_ans.push_back(temp_vector);
			if (temp_vector.size() != 1) {
				temp_vector.pop_back();
				comsum(candidates, target, k - 1, temp_vector, temp_ans);
			}
		}
		else {
			//targer-candidates[k-1]<0
			comsum(candidates, target, k - 1, temp_vector, temp_ans);
		}

	}
};