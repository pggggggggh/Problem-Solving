
class Solution {
    public int[] twoSum(int[] nums, int target) {
        Map<Integer, ArrayList<Integer>> mp = new HashMap<>();
        for (int i = 0; i < nums.length; i++) {
            if (!mp.containsKey(nums[i])) mp.put(nums[i], new ArrayList<>());
            mp.get(nums[i]).add(i);
        }
        for (int i = 0; i < nums.length; i++) {
            ArrayList<Integer> ar = mp.getOrDefault(target - nums[i], new ArrayList<>());
            for (int j = 0; j < ar.size(); j++) {
                if (i != ar.get(j)) return new int[]{i, ar.get(j)};
            }
        }
        return new int[]{0, 0};
    }
}