#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>
#include "train.h"
#include <string.h>
#include "utils.h"
#include <direct.h>

//自动创建一个文件夹
void ensureDataFolderExists() 
{
    if (_mkdir("./Data") == 0) 
    {
        printf("创建 Data 文件夹成功。\n");
    }
}

// 录入火车时刻信息
void addTrainInfo()
{
    FILE* file = fopen(FILE_PATH, "ab"); // 打开文件以追加模式
    if (file == NULL)
    {
        printf("无法打开文件！\n");
        return;
    }

    Train train;
    printf("\n请输入火车时刻信息：\n");
    printf("车次：");
    scanf("%s", train.trainNumber);

    getValidatedInput("请输入日期 (YYYY-MM-DD)：", train.date, isValidDate);

    printf("起点：");
    scanf("%s", train.origin);
    printf("终点：");
    scanf("%s", train.destination);

    getValidatedInput("请输入开车时间 (HH:MM)：", train.departureTime, isValidTime);
    getValidatedInput("请输到达时间 (HH:MM)：", train.arrivalTime, isValidTime);

    printf("票价：");
    scanf("%f", &train.ticketPrice);

    // 将火车信息写入文件
    fwrite(&train, sizeof(Train), 1, file);
    fclose(file);
    printf("火车时刻信息录入成功！\n");
}

// 按车次查询火车信息
void queryByTrainNumber()
{
    char trainNumber[10]; // 存储用户输入的车次
    printf("请输入车次：");
    scanf("%s", trainNumber);

    // 打开数据文件，采用二进制读模式
    FILE* file = fopen(FILE_PATH, "rb");
    if (file == NULL) // 文件不存在或无法读取时处理
    {
        printf("文件不存在或无法读取。\n");
        return;
    }

    Train train; // 用于存储从文件读取的火车信息
    int found = 0; // 标记是否找到匹配的车次
    while (fread(&train, sizeof(Train), 1, file)) // 逐条读取火车信息
    {
        if (strcmp(train.trainNumber, trainNumber) == 0) // 判断车次是否匹配
        {
            // 输出匹配的火车信息
            printf("车次：%s\n 日期：%s\n 起点：%s\n 终点：%s\n 开车时间：%s\n 到达时间：%s\n 票价：%.2f\n",
                train.trainNumber, train.date, train.origin, train.destination,
                train.departureTime, train.arrivalTime, train.ticketPrice);
            found = 1; // 标记为找到匹配项
            break;
        }
    }

    if (!found) // 如果未找到匹配的车次信息
    {
        printf("未找到对应车次的信息。\n");
    }
    fclose(file); // 关闭文件
}

// 按起点查询火车信息
void queryOrigin()
{
    char origin[30]; // 存储用户输入的起点
    printf("请输入起点：");
    scanf("%s", origin);

    // 打开数据文件，采用二进制读模式
    FILE* file = fopen(FILE_PATH, "rb");
    if (file == NULL) // 文件不存在或无法读取时处理
    {
        printf("文件不存在或无法读取。\n");
        return;
    }

    Train train; // 用于存储从文件读取的火车信息
    int found = 0; // 标记是否找到匹配的起点
    printf("\n=== 按起点查询结果 ===\n");
    while (fread(&train, sizeof(Train), 1, file)) // 逐条读取火车信息
    {
        if (strcmp(train.origin, origin) == 0) // 判断起点是否匹配
        {
            // 输出匹配的火车信息
            printf(" 车次：%s\n 日期：%s\n 起点：%s\n 终点：%s\n 开车时间：%s\n 到达时间：%s\n 票价：%.2f\n",
                train.trainNumber, train.date, train.origin, train.destination,
                train.departureTime, train.arrivalTime, train.ticketPrice);
            found = 1; // 标记为找到匹配项
        }
    }

    if (!found) // 如果未找到匹配的终点信息
    {
        printf("未找到起点为 %s 的火车信息。\n", origin);
    }
    fclose(file); // 关闭文件
}

// 按终点查询火车信息
void queryByDestination()
{
    char destination[30]; // 存储用户输入的终点
    printf("请输入终点：");
    scanf("%s", destination);

    // 打开数据文件，采用二进制读模式
    FILE* file = fopen(FILE_PATH, "rb");
    if (file == NULL) // 文件不存在或无法读取时处理
    {
        printf("文件不存在或无法读取。\n");
        return;
    }

    Train train; // 用于存储从文件读取的火车信息
    int found = 0; // 标记是否找到匹配的终点
    printf("\n=== 按终点查询结果 ===\n");
    while (fread(&train, sizeof(Train), 1, file)) // 逐条读取火车信息
    {
        if (strcmp(train.destination, destination) == 0) // 判断终点是否匹配
        {
            // 输出匹配的火车信息
            printf(" 车次：%s\n 日期：%s\n 起点：%s\n 终点：%s\n 开车时间：%s\n 到达时间：%s\n 票价：%.2f\n",
                train.trainNumber, train.date, train.origin, train.destination,
                train.departureTime, train.arrivalTime, train.ticketPrice);
            found = 1; // 标记为找到匹配项
        }
    }

    if (!found) // 如果未找到匹配的终点信息
    {
        printf("未找到终点为 %s 的火车信息。\n", destination);
    }
    fclose(file); // 关闭文件
}

// 按起点和日期查询火车信息
void queryOriginDate()
{
    char origin[30], date[12]; // 分别存储用户输入的终点和日期
    printf("请输入终点：");
    scanf("%s", origin);
    getValidatedInput("请输入日期 (YYYY-MM-DD)：", &date, isValidDate);

    // 打开数据文件，采用二进制读模式
    FILE* file = fopen(FILE_PATH, "rb");
    if (file == NULL) // 文件不存在或无法读取时处理
    {
        printf("文件不存在或无法读取。\n");
        return;
    }

    Train train; // 用于存储从文件读取的火车信息
    int found = 0; // 标记是否找到匹配的终点和日期
    printf("\n=== 按终点和日期查询结果 ===\n");
    while (fread(&train, sizeof(Train), 1, file)) // 逐条读取火车信息
    {
        if (strcmp(train.destination, origin) == 0 && strcmp(train.date, date) == 0) // 判断终点和日期是否同时匹配
        {
            // 输出匹配的火车信息
            printf(" 车次：%s\n 日期：%s\n 起点：%s\n 终点：%s\n 开车时间：%s\n 到达时间：%s\n 票价：%.2f\n",
                train.trainNumber, train.date, train.origin, train.destination,
                train.departureTime, train.arrivalTime, train.ticketPrice);
            found = 1; // 标记为找到匹配项
        }
    }

    if (!found) // 如果未找到匹配的终点和日期信息
    {
        printf("未找到终点为 %s 且日期为 %s 的火车信息。\n", origin, date);
    }
    fclose(file); // 关闭文件
}

// 按终点和日期查询火车信息
void queryByDestinationAndDate()
{
    char destination[30], date[12]; // 分别存储用户输入的终点和日期
    printf("请输入终点：");
    scanf("%s", destination);
    getValidatedInput("请输入日期 (YYYY-MM-DD)：", &date, isValidDate);

    // 打开数据文件，采用二进制读模式
    FILE* file = fopen(FILE_PATH, "rb");
    if (file == NULL) // 文件不存在或无法读取时处理
    {
        printf("文件不存在或无法读取。\n");
        return;
    }

    Train train; // 用于存储从文件读取的火车信息
    int found = 0; // 标记是否找到匹配的终点和日期
    printf("\n=== 按终点和日期查询结果 ===\n");
    while (fread(&train, sizeof(Train), 1, file)) // 逐条读取火车信息
    {
        if (strcmp(train.destination, destination) == 0 && strcmp(train.date, date) == 0) // 判断终点和日期是否同时匹配
        {
            // 输出匹配的火车信息
            printf(" 车次：%s\n 日期：%s\n 起点：%s\n 终点：%s\n 开车时间：%s\n 到达时间：%s\n 票价：%.2f\n",
                train.trainNumber, train.date, train.origin, train.destination,
                train.departureTime, train.arrivalTime, train.ticketPrice);
            found = 1; // 标记为找到匹配项
        }
    }

    if (!found) // 如果未找到匹配的终点和日期信息
    {
        printf("未找到终点为 %s 且日期为 %s 的火车信息。\n", destination, date);
    }
    fclose(file); // 关闭文件
}

//按起点统计车次数
void countByOrigin()
{
    char origin[30]; // 用于存储用户输入的起点
    printf("请输入起点：");
    scanf("%s", origin);

    // 打开数据文件，采用二进制读模式
    FILE* file = fopen(FILE_PATH, "rb");
    if (file == NULL) // 文件不存在或无法读取时处理
    {
        printf("文件不存在或无法读取。\n");
        return;
    }

    Train train; // 用于存储从文件读取的火车信息
    int count = 0; // 统计起点为指定起点的车次数量
    while (fread(&train, sizeof(Train), 1, file)) // 逐条读取火车信息
    {
        if (strcmp(train.origin, origin) == 0) // 判断起点是否匹配
        {
            count++; // 计数
        }
    }

    fclose(file); // 关闭文件
    printf("起点为 %s 的每日车次数：%d\n", origin, count); // 输出统计结果
}

//按终点统计车次数
void countByDestination()
{
    char destination[30]; // 用于存储用户输入的终点
    printf("请输入起点：");
    scanf("%s", destination);

    // 打开数据文件，采用二进制读模式
    FILE* file = fopen(FILE_PATH, "rb");
    if (file == NULL) // 文件不存在或无法读取时处理
    {
        printf("文件不存在或无法读取。\n");
        return;
    }

    Train train; // 用于存储从文件读取的火车信息
    int count = 0; // 统计终点为指定起点的车次数量
    while (fread(&train, sizeof(Train), 1, file)) // 逐条读取火车信息
    {
        if (strcmp(train.origin, destination) == 0) // 判断终点是否匹配
        {
            count++; // 计数
        }
    }

    fclose(file); // 关闭文件
    printf("终点为 %s 的每日车次数：%d\n", destination, count); // 输出统计结果
}

// 显示所有火车时刻信息
void loadTrainsFromFile()
{
    FILE* file = fopen(FILE_PATH, "rb"); // 以只读模式打开文件
    if (file == NULL)
    {
        printf("文件不存在或无法读取。\n");
        return;
    }

    Train train;
    printf("\n=== 火车时刻表 ===\n");
    while (fread(&train, sizeof(Train), 1, file))
    {
        printf(" 车次：%s\n 日期：%s\n 起点：%s\n 终点：%s\n 开车时间：%s\n 到达时间：%s\n 票价：%.2f\n",
            train.trainNumber, train.date, train.origin, train.destination,
            train.departureTime, train.arrivalTime, train.ticketPrice);
        printf("-------------------------------\n"); // 分隔每条信息
    }
    fclose(file);
}


Train trains[1000]; // 定义一个全局数组，用于存储火车信息
int trainCount = 0; // 全局变量，存储加载到内存中的火车数量
//读取文件信息
void loadTrainsToMemory()
{
    FILE* file = fopen(FILE_PATH, "rb"); // 打开数据文件
    if (file == NULL) // 文件无法打开时处理
    {
        printf("无法加载火车信息。\n");
        return;
    }

    trainCount = 0; // 初始化记录数
    while (fread(&trains[trainCount], sizeof(Train), 1, file)) // 逐条读取火车信息并存入数组
    {
        trainCount++; // 更新记录数
    }
    fclose(file); // 关闭文件
    printf("火车信息加载完成，共 %d 条记录。\n", trainCount); // 输出加载结果
}