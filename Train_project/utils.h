#pragma once
#ifndef UTILS_H
#define UTILS_H

// ����У�麯��
int isValidDate(const char* date);

// ʱ��У�麯��
int isValidTime(const char* time);

//ͨ�ù��ߺ���
void getValidatedInput(const char* prompt, char* buffer, int (*validate)(const char*));

#endif // UTILS_H