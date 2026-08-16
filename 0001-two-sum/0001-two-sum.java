class Solution {
    public int[] twoSum(int[] nums, int target) {
        int[][] s = new int[nums.length][2];
        for (int i = 0; i < nums.length; i++) {
            s[i][0] = nums[i];
            s[i][1] = i;
        }
        Arrays.sort(s, (a, b) -> Integer.compare(a[0], b[0]));
        int l = 0;
        int r = nums.length - 1;
        while (l < r) {
            if (s[l][0] + s[r][0] == target) return new int[]{s[l][1], s[r][1]};
            if (s[l][0] + s[r][0] > target) r--;
            else l++;
        }
        return new int[]{};
    }
}
