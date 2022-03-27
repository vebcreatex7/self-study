
#include <stdio.h>
#include <stdlib.h>
#include <iostream>
using namespace std;



int strlen(const char* str) {
    int size = 0;
    while(*str != '\0')
        str++, size++;
    return size;
}


int strstr(const char *text, const char *pattern)
{
    
    int n = strlen(text);
    int m = strlen(pattern);
    if (m == 0)
        return 0;
    int l = m + n + 1;

    char* merge = (char*)malloc(sizeof(char) * (l + 1)); //new char[n + m + 2]
    int p = 0;
    for (int i = 0; i != m; i++,  p++)
        merge[p] = pattern[i];
    merge[p] = '#';
    p++;
    for (int i = 0; i != n; i++, p++)
        merge[p] = text[i];
    merge[p] = '\0';

    
    int* pi = (int*)malloc(sizeof(int) * l);
    pi[0] = 0;

    int ans = -1;
    for (int i = 1; i < l; i++) {
        int j = pi[i - 1];
        while(j > 0 && merge[i] != merge[j])
            j = pi[j - 1];
        if (merge[i] == merge[j]) ++j;
        pi[i] = j;
        if (pi[i] == m) {
            ans = i - 2 * m;
            break;
        }
            
    }
    free(merge);
    free(pi);
    return ans;
}




int main() {
    const char str[] =  "Text";
    const char pattern[] = "Big Text";
    printf("%d", strstr(str, pattern));



/*
struct test{
    int ret_value;
    const char *text;
    const char *pattern;
};

test tests[] = {
        {0, "", ""}, //0
        {0, "a", ""}, //1
        {0, "a", "a"}, //2
        {-1, "a", "b"}, //3
        {0, "aa", ""}, //4
        {0, "aa", "a"}, //5
        {0, "ab", "a"}, //6
        {1, "ba", "a"}, //7
        {-1, "bb", "a"}, //8
        {0, "aaa", ""}, //9
        {0, "aaa", "a"}, //10
        {1, "abc", "b"}, //11
        {2, "abc", "c"}, //12
        {-1, "abc", "d"}, //13
        {-1, "a", "aa"}, //14
        {-1, "a", "ba"}, //15
        {-1, "a", "ab"}, //16
        {-1, "a", "bb"}, //17
        {-1, "a", "aaa"}, //18
        {-1, "aa", "aaa"}, //19
        {0, "aaa", "aaa"}, //20
        {0, "aaab", "aaa"}, //21
        {1, "baaa", "aaa"}, //22
        {1, "baaaa", "aaa"}, //23
        {1, "baaab", "aaa"}, //24
        {-1, "abd", "abc"}, //25
        {2, "ababc", "abc"}, //26
        {3, "abdabc", "abc"}, //27
        {-1, "", "a"}, //28
        {2, "asasaf", "asaf"}, //29
        {2, "ababac", "abac"} //30
};
    for (int i = 0; i < sizeof(tests) / sizeof(tests[0]); ++i) {
    int ret = strstr(tests[i].text, tests[i].pattern);
    (tests[i].ret_value == ret) ? cout << "OK" : cout << "Failed";
     cout << " : " << i << " (" << tests[i].ret_value << " : " << ret << ")" << endl;
}
*/
}
