
class Solution {
public:
    TreeNode* genNode(vector<int>& nums, int start, int end){
        int max = -1;
        int max_index;
        
        if (end < start || start > end) {
            return nullptr;
            
        }else {
            for (int i = start; i <= end; ++i) {
                if (nums[i] > max) {
                    max = nums[i];
                    max_index = i;
                }
            }

            struct TreeNode* node = new TreeNode(max, genNode(nums, start, max_index - 1), genNode(nums, max_index + 1, end));

            return node;
            
        }
    }


    TreeNode* constructMaximumBinaryTree(vector<int>& nums) {
        struct TreeNode* head = genNode(nums, 0, nums.size()-1);

        return head;
    }
};