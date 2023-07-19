class Solution {
public:
    string maxValue(string n, int x) {
        int nLen = n.length();
        int insertPos = nLen;

        // Determine the position to insert x
        if (n[0] != '-') {
            for (int i = 0; i < nLen; i++) {
                if (n[i] - '0' < x) {
                    insertPos = i;
                    break;
                }
            }
        } else {
            for (int i = 1; i < nLen; i++) {
                if (n[i] - '0' > x) {
                    insertPos = i;
                    break;
                }
            }
        }

        // Insert x at the determined position
        n.insert(insertPos, to_string(x));

        return n;
    }
};