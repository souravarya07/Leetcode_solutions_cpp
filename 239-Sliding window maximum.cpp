class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        deque<int> Q;
        vector<int> v;
        int i=0;
        for(i=0;i<k;i++){
            while(!Q.empty() && nums[i]>nums[Q.back()]){
                Q.pop_back();
            }
            Q.push_back(i);
        }
        
        v.push_back(nums[Q.front()]);
        for(i=k;i<nums.size();i++){
            // v.push_back(nums[Q.front()]);
            if(!Q.empty() && Q.front() ==i-k){
                Q.pop_front();
            }
            while(!Q.empty() && nums[i] > nums[Q.back()]){
                Q.pop_back();
            }
            Q.push_back(i);
            v.push_back(nums[Q.front()]);
        }
        
        return v;
    }
};
