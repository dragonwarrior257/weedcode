/*
* adhoc solution.
* TIME: O(n)
* SPACE: O(n)*/
class Solution {
public:
    vector<int> plusOne(vector<int>& digits) {
        vector<int> result;
        int sum = digits[digits.size()-1] + 1;
        int carry = sum / 10;
        int rem = sum % 10;
        result.push_back(rem);
        
        for(int i=digits.size()-2; i >=0 ; i--){
            sum = digits[i] + carry;
            carry = sum / 10;
            rem = sum % 10;
            result.push_back(rem);
        }
        if (carry != 0) result.push_back(carry);
        reverse(result.begin(), result.end());
        return result;
    }
};
