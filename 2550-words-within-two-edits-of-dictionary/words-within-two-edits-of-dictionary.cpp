class Solution {
public:
    vector<string> twoEditWords(vector<string>& queries, vector<string>& dictionary) {
        vector<string> res;

        for (string& word : queries) {
            int wLen = word.size();

            for (string& dict_word : dictionary) {
                int dLen = dict_word.size();

                if (wLen == dLen) {
                    int diff = 0;
                    for (int i = 0; i < wLen; i++) {
                        if (word[i] != dict_word[i]) {
                            diff++;
                        }

                        if (diff > 2) {
                            break;
                        }
                    }

                    if (diff <= 2) {
                        res.push_back(word);
                        break;
                    }
                }
            }
        }

        return res;
    }
};