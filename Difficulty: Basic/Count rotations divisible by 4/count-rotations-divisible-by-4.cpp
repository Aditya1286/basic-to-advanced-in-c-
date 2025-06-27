class Solution {
  public:
    int countRotations(string N) {
        int count = 0;
        int len = N.length();
        string rotated = N;

        for (int i = 0; i < len; i++) {
            
            rotated = rotated.substr(1) + rotated[0];

            int lastTwo = 0;
            if (len == 1) {
                lastTwo = rotated[0] - '0';
            } else {
                lastTwo = (rotated[len - 2] - '0') * 10 + (rotated[len - 1] - '0');
            }

            if (lastTwo % 4 == 0) {
                count++;
            }
        }

        return count;
    }
};
