/*
Idea here is to reverse each row and xor everybit with 1.
TIME: O(m.n)
SPACE: O(1)
*/
class Solution {
public:
    vector<vector<int>> 
        flipAndInvertImage(vector<vector<int>>& image) {
        for (auto& vec: image) reverse(vec.begin(), vec.end());
        for (int i=0; i<image.size(); i++){
            for (int j=0; j <image[0].size(); j++){
                image[i][j] ^= 1;
            }
        }
        return image;
    }
};
