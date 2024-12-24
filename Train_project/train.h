#pragma once
#ifndef TRAIN_H
#define TRAIN_H

// 定义火车时刻结构体
typedef struct
{
    char trainNumber[10];   // 车次
    char date[12];          // 日期
    char origin[30];        // 起点
    char destination[30];   // 终点
    char departureTime[10]; // 开车时间
    char arrivalTime[10];   // 到达时间
    float ticketPrice;      // 票价
}Train;

//函数声明
void addTrainInfo(); //火车信息录入


// 数据文件路径
#define FILE_PATH "./Data/data.txt"

#endif // TRAIN_H