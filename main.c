#include <stdio.h>
#include <string.h>

#define MAX_CHAR 128 // 假设是ASCII字符集

int lengthOfLongestSubstring(char *s)
{
    int charIndex[MAX_CHAR]; // 存储每个字符最后一次出现的位置
    for (int i = 0; i < MAX_CHAR; i++)
    {
        charIndex[i] = -1; // 初始化为 -1，表示未出现过
    }

    int left = 0;      // 左指针
    int maxLength = 0; // 最长子串长度

    for (int right = 0; s[right] != '\0'; right++)
    {
        char currentChar = s[right];

        // 如果该字符已经出现过，并且在当前窗口内
        if (charIndex[currentChar] >= left)
        {
            // 移动左指针到重复字符的下一个位置
            left = charIndex[currentChar] + 1;
        }

        // 更新该字符的最新位置
        charIndex[currentChar] = right;

        // 计算当前窗口长度并更新最大值
        if (right - left + 1 > maxLength)
        {
            maxLength = right - left + 1;
        }
    }

    return maxLength;
}

// 测试函数
int main()
{
    char s[] = "abcabcbb";
    int result = lengthOfLongestSubstring(s);
    printf("最长无重复子串的长度是: %d\n", result); // 输出应为 3
    return 0;
}