#pragma once
#ifndef TRAIN_H
#define TRAIN_H

// �����ʱ�̽ṹ��
typedef struct
{
    char trainNumber[10];   // ����
    char date[12];          // ����
    char origin[30];        // ���
    char destination[30];   // �յ�
    char departureTime[10]; // ����ʱ��
    char arrivalTime[10];   // ����ʱ��
    float ticketPrice;      // Ʊ��
}Train;

//��������
void addTrainInfo(); //����Ϣ¼��


// �����ļ�·��
#define FILE_PATH "./Data/data.txt"

#endif // TRAIN_H