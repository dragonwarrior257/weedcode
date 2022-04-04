/*
 * First loop will remove non-alphanumeric.
 * second loop will convert all uppercase to lowercase.
 * third loop will compare first and last element using two pointer,
 * and it should be equal if palindrome, else return false.
 * TIME: O(n) firstloop + O(n) secondloop + O(n) thirdloop = O(n)
 * SPACE: O(n) to create new transformed string.
 **/
class Solution {
public:
    bool isPalindrome(string s) {
        std::string temp;
        for(auto ch: s){
            if (std::isalnum(ch)) 
              temp += ch;
        }
        for (auto& ch: temp){
            if (std::isalpha(ch) && std::isupper(ch)) 
              ch = std::tolower(ch);
        }
 
        int i=0;
        int j=temp.size()-1;
        while (i<j){
            if (temp[i++] != temp[j--]) return false;
        }
        return true;
    }
};

class Solution_stl {
public:
    bool isPalindrome(string s) {
        std::string temp;
        // filter only alphanumeric characters.
        std::copy_if(s.begin(), s.end(), 
                     std::back_inserter(temp),
                     [](auto ch){return std::isalnum(ch);});
       
        // change uppercase to lowercase using map transformation.
        std::transform(temp.begin(), temp.end(), 
                       temp.begin(),
                       [](auto ch){
                           return (std::isalpha(ch)&&
                                   std::isupper(ch)) ? std::tolower(ch) : ch;});
        // get the reverse of temp string.
        std::string copy_temp = temp;
        std::reverse(temp.begin(), temp.end());
        // for palindrome string == reverse (string);
        return copy_temp == temp;
    }
};
