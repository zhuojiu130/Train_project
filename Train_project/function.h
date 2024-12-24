#pragma once
#ifndef FUNCTION_H
#define FUNCTION_H

//函数声明
void ensureDataFolderExists();	//创建文件夹函数

void addTrainInfo(); //火车信息录入

void loadTrainsToMemory();	//信息读取

void queryByTrainNumber();	// 按车次查询火车信息

void queryOrigin();	// 按起点查询火车信息

void queryByDestination();	// 按终点查询火车信息

void queryOriginDate();	// 按起点和日期查询火车信息

void queryByDestinationAndDate();	// 按终点和日期查询火车信息

void countByOrigin();	//按起点统计车次数

void countByDestination();	//按终点统计车次数

void loadTrainsFromFile();	// 显示所有火车时刻信息

#endif 