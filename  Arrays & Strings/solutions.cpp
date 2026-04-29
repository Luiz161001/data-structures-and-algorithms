#include <string>
#include <unordered_map>

int lengthOfLongestSubstring(std::string s) {
    int size = s.length();

    int ans = 0;

    // hashmap to track the index of each character
    std::unordered_map<char, int> mp;

    // left pointer
    int i = 0;

    // loop for right pointer
    for(int j = 0; j < size; j++){
        // if the char is already in the hashmap
        if(mp.find(s[j])!=mp.end()){
            // advance left pointer past the previous occurrence of this character
            i = std::max(mp[s[j]], i);
        }

        // the answer should be the longest substring
        // j(right) - i(left) + 1
        ans = std::max(ans, j - i + 1);

        // store j+1 so i can jump directly past the duplicate
        mp[s[j]]= j+1;
    }

    return ans;
}