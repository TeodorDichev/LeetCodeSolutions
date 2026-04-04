class Solution {
public:
    string decodeCiphertext(string encodedText, int rows) {
        string decoded;
        int cols = encodedText.size() / rows;

        int h = 0;

        for (int i = 0; i < cols; i++) {
            for (int j = 0, h = 0; j < rows; j++, h++) {
                if (i + h < cols) {
                    decoded += encodedText[j * cols + i + h];
                }
            }
        }

        int index = decoded.size();
        for (int i = decoded.size() - 1; i >= 0; i--) {
            if (decoded[i] != ' ') {
                break;
            } else {
                index--;
            }
        }
        
        return decoded.substr(0, index);
    }
};