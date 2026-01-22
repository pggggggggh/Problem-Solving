/**
 * // This is the Master's API interface.
 * // You should not implement it, or speculate about its implementation
 * class Master {
 *   public:
 *     int guess(string word);
 * };
 */
class Solution {
public:
    void findSecretWord(vector<string>& words, Master& master) {
        unordered_set<string> remaining;
        for (string &word:words) remaining.insert(word);

        while (!remaining.empty()) {
            string s = *(remaining.begin());
            int result = master.guess(s);
            if (result == 6) break;
            
            unordered_set<string>::iterator it = remaining.begin();
            while (it != remaining.end()) {
                int sameCnt = 0;
                for (int i=0;i<6;i++) {
                    if ((*it)[i] == s[i]) sameCnt++;
                }
                if (sameCnt != result) it = remaining.erase(it);
                else it = next(it);
            }
        }
    }
};