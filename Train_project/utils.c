#define _CRT_SECURE_NO_WARNINGS 1
#include <ctype.h>
#include <string.h>
#include "utils.h"
#include <stdio.h>

// У�����ڸ�ʽ�Ƿ�Ϊ YYYY-MM-DD
int isValidDate(const char* date)
{
    if (strlen(date) != 10 || date[4] != '-' || date[7] != '-')
    {
        return 0; // ���Ȼ�ָ�����ƥ��
    }
    for (int i = 0; i < 10; i++)
    {
        if (i == 4 || i == 7) continue; // �����ָ���
        if (!isdigit(date[i])) return 0; // �������ַ�
    }
    return 1; // ��ʽ��Ч
}

// У��ʱ���ʽ�Ƿ�Ϊ HH:MM
int isValidTime(const char* time)
{
    if (strlen(time) != 5 || time[2] != ':')
    {
        return 0; // ���Ȼ�ָ�����ƥ��
    }
    if (!isdigit(time[0]) || !isdigit(time[1]) ||
        !isdigit(time[3]) || !isdigit(time[4]))
    {
        return 0; // �������ַ�
    }
    int hour = (time[0] - '0') * 10 + (time[1] - '0'); // ��ȡСʱ
    int minute = (time[3] - '0') * 10 + (time[4] - '0'); // ��ȡ����
    return hour >= 0 && hour < 24 && minute >= 0 && minute < 60; // ʱ�䷶ΧУ��
}

void getInput(const char* prompt, char* buffer, int (*validate)(const char*))
{
    do {
        printf("%s", prompt);
        scanf("%s", buffer);
        if (!validate(buffer))
        {
            printf("�����ʽ��Ч�������ԡ�\n");
        }
    } while (!validate(buffer));
}

//ͨ�ù��ߺ���
void getValidatedInput(const char* prompt, char* buffer, int (*validate)(const char*)) {
    do {
        printf("%s", prompt);
        scanf("%s", buffer);
        if (!validate(buffer)) {
            printf("�����ʽ��Ч�������ԡ�\n");
        }
    } while (!validate(buffer));
}

