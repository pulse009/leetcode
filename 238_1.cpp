/*Given an integer array nums, return an array answer such that answer[i] is equal to the product of all the elements of nums except nums[i].

The product of any prefix or suffix of nums is guaranteed to fit in a 32-bit integer.

You must write an algorithm that runs in O(n) time and without using the division operation.

Input: nums = [1,2,3,4]
Output: [24,12,8,6]

*/

#include <vector>
#include <string>
#include <iostream>

class Solution {
public:
    std::vector<int> productExceptSelf(std::vector<int>& nums) {
        std::vector<int> answer;
        /*for (int i = 0; i < nums.size(); i++){
            int product = 1;
            for (int j = 0; j < i; j++)
                product*=nums[j];
            for (int j=i+1; j < nums.size(); j++)
                product*=nums[j];
            if (nums.size()==0){
                return (answer);
            }
            answer.push_back(product);
        }*/
        int left_corner, right_corner;
        left_corner=1;
        right_corner=nums[1];
        for (int i=2; i < nums.size(); i++){
            right_corner*=nums[i];
        }
        answer.push_back(left_corner*right_corner);
        for (int i=1; i < nums.size(); i++) {
            if (left_corner==0 || right_corner==0){
                answer.push_back(0);
            }
            else{
                right_corner/=nums[i];
                left_corner*=nums[i-1];
                answer.push_back(left_corner*right_corner);
            }
        }
        return answer;
    }
};

int main(){
    Solution s;
    std::vector<int> test;
    test.push_back(-1);
    test.push_back(1);
    test.push_back(0);
    test.push_back(-3);
    test.push_back(3);
    std::vector<int> answer=s.productExceptSelf(test);
    for (int i=0; i<answer.size(); i++){
        std::cout<<answer[i]<<" ";
    }
}