class Solution {
    public boolean canPartition(int[] nums) {
        int sum = 0, target = 0;

        for(int x : nums) sum += x;

        if(sum % 2 != 0) return false;

        target = sum / 2;

        // saving only half as other half is redundant
        boolean [] reachableSums = new boolean[target+1];
        reachableSums[0] = true; // empty set

        for(int i : nums) {
            for(int j = target; j >= i; j--) { 
                reachableSums[j] = reachableSums[j] || reachableSums[j - i];
            }
        }

        return reachableSums[target];
    }
}