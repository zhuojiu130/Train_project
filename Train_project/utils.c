#define _CRT_SECURE_NO_WARNINGS 1
#include <ctype.h>
#include <string.h>
#include "utils.h"
#include <stdio.h>

// 校验日期格式是否为 YYYY-MM-DD
int isValidDate(const char* date)
{
    if (strlen(date) != 10 || date[4] != '-' || date[7] != '-')
    {
        return 0; // 长度或分隔符不匹配
    }
    for (int i = 0; i < 10; i++)
    {
        if (i == 4 || i == 7) continue; // 跳过分隔符
        if (!isdigit(date[i])) return 0; // 非数字字符
    }
    return 1; // 格式有效
}

// 校验时间格式是否为 HH:MM
int isValidTime(const char* time)
{
    if (strlen(time) != 5 || time[2] != ':')
    {
        return 0; // 长度或分隔符不匹配
    }
    if (!isdigit(time[0]) || !isdigit(time[1]) ||
        !isdigit(time[3]) || !isdigit(time[4]))
    {
        return 0; // 非数字字符
    }
    int hour = (time[0] - '0') * 10 + (time[1] - '0'); // 提取小时
    int minute = (time[3] - '0') * 10 + (time[4] - '0'); // 提取分钟
    return hour >= 0 && hour < 24 && minute >= 0 && minute < 60; // 时间范围校验
}

void getInput(const char* prompt, char* buffer, int (*validate)(const char*))
{
    do {
        printf("%s", prompt);
        scanf("%s", buffer);
        if (!validate(buffer))
        {
            printf("输入格式无效，请重试。\n");
        }
    } while (!validate(buffer));
}

//通用工具函数
void getValidatedInput(const char* prompt, char* buffer, int (*validate)(const char*)) {
    do {
        printf("%s", prompt);
        scanf("%s", buffer);
        if (!validate(buffer)) {
            printf("输入格式无效，请重试。\n");
        }
    } while (!validate(buffer));
}

