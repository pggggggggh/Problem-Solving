
class Solution {
    public int lengthOfLongestSubstring(String s) {
        int lo = 0, hi = s.length() + 1;
        while (lo + 1 < hi) {
            int mid = (lo + hi) / 2;
            int[] cnt = new int[200];
            boolean good = false;
            for (int i = 0; i < s.length(); i++) {
                if (i >= mid) cnt[s.charAt(i - mid)]--;
                cnt[s.charAt(i)]++;
                boolean localGood = true;
                for (int j = 0; j < 200; j++) {
                    if (cnt[j] > 1) {
                        localGood = false;
                        break;
                    }
                }
                if (i >= mid - 1 && localGood) {
                    good = true;
                    break;
                }
            }
            if (good) lo = mid;
            else hi = mid;
        }
        return lo;
    }
}