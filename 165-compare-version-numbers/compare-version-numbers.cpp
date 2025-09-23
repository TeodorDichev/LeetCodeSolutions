class Solution {
public:
    int compareVersion(std::string version1, std::string version2) {
        auto ptr1 = version1.begin();
        auto ptr2 = version2.begin();
        
        while (ptr1 != version1.end() || ptr2 != version2.end()) {
            int currVer1 = 0, currVer2 = 0;

            while (ptr1 != version1.end() && *ptr1 != '.') {
                currVer1 = currVer1 * 10 + (*ptr1 - '0');
                ptr1++;
            }

            while (ptr2 != version2.end() && *ptr2 != '.') {
                currVer2 = currVer2 * 10 + (*ptr2 - '0');
                ptr2++;
            }
            
            if (currVer1 < currVer2) return -1;
            if (currVer1 > currVer2) return 1;

            if (ptr1 != version1.end()) ptr1++;
            if (ptr2 != version2.end()) ptr2++;
        }
        return 0;
    }
};
