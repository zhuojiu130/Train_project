#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>
#include "function.h"
#include "utils.h"
#include "train.h"
#include <Windows.h>

void mainMenu();

int main()
{
    ensureDataFolderExists();   //创建数据文件夹
    loadTrainsToMemory();       // 从文件加载火车信息到内存
    mainMenu();	// 显示主菜单
    return 0;
}

//菜单功能函数
void mainMenu()
{
    int choice;
    do {
        system("cls");  // 清屏，增强视觉效果
        printf("\n=== 火车票务系统 ===\n");
        printf("1. 录入火车时刻信息\n");
        printf("2. 按车次查询火车时刻信息\n");
        printf("3. 按起点查询火车时刻信息\n");
        printf("4. 按终点查询火车时刻信息\n");
        printf("5. 按起点和日期查询\n");
        printf("6. 按终点和日期查询\n");
        printf("7. 按起点统计车次数\n");
        printf("8. 按终点统计车次数\n");
        printf("9. 显示所有火车时刻信息\n");
        printf("0. 退出\n");
        printf("请输入您的选择：");
        scanf("%d", &choice);
        getchar();

        switch (choice)
        {
        case 1: addTrainInfo(); break;
        case 2: queryByTrainNumber(); break;
        case 3: queryOrigin(); break;
        case 4: queryByDestination(); break;
        case 5: queryOriginDate(); break;
        case 6: queryByDestinationAndDate(); break;
        case 7: countByOrigin(); break;
        case 8: countByDestination(); break;
        case 9: loadTrainsFromFile(); break;
        case 10: printf("退出系统。\n"); break;
        default: printf("无效的选择，请重新输入。\n");
        }
        if (choice != 10)
        {
            system("pause"); // 等待用户按键
        }
    } while (choice != 10);
}