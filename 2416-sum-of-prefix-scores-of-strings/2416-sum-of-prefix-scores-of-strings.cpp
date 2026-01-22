class Solution {
private:
const long MOD = 200560490131LL;

public:
    vector<int> sumPrefixScores(vector<string>& words) {
        unordered_map<long,int> mapOfCnt;
        for (string &word:words) {
            long curHash = 0;
            for (char &c:word) {
                curHash = (curHash*26+(c-'a'+1))%MOD;
                mapOfCnt[curHash]++;
            }
        }
        vector<int> result;
        for (string &word:words) {
            int curCnt = 0;
            long curHash = 0;
            for (char &c:word) {
                curHash = (curHash*26+(c-'a'+1))%MOD;
                curCnt += mapOfCnt[curHash];
            }
            result.push_back(curCnt);
        }
        return result;
    }
};