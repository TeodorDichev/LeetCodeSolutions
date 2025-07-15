class Solution {
public:
    bool isValid(string word) {
        if (word.size() < 3) return false;

        bool vowel = false;
        bool consonant = false;

        for (int i = 0; i < word.size(); i++)
        {
            if (isNumber(word[i]))
            {
                continue;
            }
            else if (isUpperCaseLetter(word[i]))
            {
                if(isVowel(toLower(word[i]))) vowel = true;
                else consonant = true;
            }
            else if (isLowerCaseLetter(word[i]))
            {
                if(isVowel(word[i])) vowel = true;
                else consonant = true;
            }
            else
            {
                return false;
            }
        }

        return vowel && consonant;
    }

    bool isNumber(char c)
    {
        return c >= 48 && c <= 57;
    }

    bool isUpperCaseLetter(char c)
    {
        return c >= 65 && c <= 90;
    }

    bool isLowerCaseLetter(char c)
    {
        return c >= 97 && c <= 122;
    }
    bool isVowel(char c)
    {
        return c == 'a' || c == 'e' || c == 'i'|| c == 'o'|| c == 'u';
    }

    char toLower(char c)
    {
        return c + ('a' - 'A');
    }
};