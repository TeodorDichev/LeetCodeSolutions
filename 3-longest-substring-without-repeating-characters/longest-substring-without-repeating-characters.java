class Solution {
    public int lengthOfLongestSubstring(String s) {
        String res = "";

        for(int i = 0; i < s.length(); i++) {
            StringBuilder currStr = new StringBuilder();
            for(int j = i; j < s.length(); j++) {
                if(currStr.lastIndexOf(Character.toString(s.charAt(j))) != -1) {
                    break;
                }
                
                currStr.append(s.charAt(j));
            }

            if(currStr.length() > res.length()) {
                res = currStr.toString();
            }
        }

        return res.length();
    }
}