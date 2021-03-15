// 58. Length of Last Word (Easy)

#include <iostream>
#include <string>
using namespace std; 

class Solution {
public:
    int lengthOfLastWord(string s) {
        int size = s.size();
        int length = 0;
        for (int i = size-1; i >= 0; --i){
            if (isalpha(s.at(i))){
                if (length == 0)
                    length = 1;
                else
                    length += 1;
            }
            else{
                if (length == 0)
                    continue;
                else
                    break;
            }
        }

        return length;
    }
};