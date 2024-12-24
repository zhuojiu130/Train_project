#pragma once
#ifndef UTILS_H
#define UTILS_H

// 日期校验函数
int isValidDate(const char* date);

// 时间校验函数
int isValidTime(const char* time);

//通用工具函数
void getValidatedInput(const char* prompt, char* buffer, int (*validate)(const char*));

#endif // UTILS_H