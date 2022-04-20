class Solution {
public:
		int dp[1001][51];     // To memoize it  
    
    int solve(vector<int>&nums,int idx, int m){
        int n = nums.size(); 
			 // Base case : when the size is equal to 1 i.e. we have to take all the elements. 
			if (m == 1){      
            int sum = 0;
            for(int i = idx; i < n; i++)
                sum += nums[i]; 
            return sum; 
        }
        if (dp[idx][m] != -1)
            return dp[idx][m]; 
        
        int ans =   INT_MAX; 
        int sum = 0; 
        for(int i = idx; i <= n - m; i++){   // Here n-m because we can't take the elements more then m so that it can be further form non-empty subarray
            sum += nums[i]; 
            int next_sum = solve(nums, i+1, m-1);    // Calling for the next maximum sum that can be obtained by spllitting next sequence
            int temp = max(sum, next_sum);   // Here maximum because we have to consider the largest sum among all the splitted sub array
            ans = min(ans, temp);  // Answer would be the smallest in all the possible splittings . 
        }
			return dp[idx][m] = ans; 
    }
    int splitArray(vector<int>& nums, int m) {
        memset(dp, -1, sizeof(dp)); 
        return solve(nums, 0, m); 
    }
};