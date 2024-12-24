#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>
#include "train.h"
#include <string.h>
#include "utils.h"
#include <direct.h>

//�Զ�����һ���ļ���
void ensureDataFolderExists() 
{
    if (_mkdir("./Data") == 0) 
    {
        printf("���� Data �ļ��гɹ���\n");
    }
}

// ¼���ʱ����Ϣ
void addTrainInfo()
{
    FILE* file = fopen(FILE_PATH, "ab"); // ���ļ���׷��ģʽ
    if (file == NULL)
    {
        printf("�޷����ļ���\n");
        return;
    }

    Train train;
    printf("\n�������ʱ����Ϣ��\n");
    printf("���Σ�");
    scanf("%s", train.trainNumber);

    getValidatedInput("���������� (YYYY-MM-DD)��", train.date, isValidDate);

    printf("��㣺");
    scanf("%s", train.origin);
    printf("�յ㣺");
    scanf("%s", train.destination);

    getValidatedInput("�����뿪��ʱ�� (HH:MM)��", train.departureTime, isValidTime);
    getValidatedInput("���䵽��ʱ�� (HH:MM)��", train.arrivalTime, isValidTime);

    printf("Ʊ�ۣ�");
    scanf("%f", &train.ticketPrice);

    // ������Ϣд���ļ�
    fwrite(&train, sizeof(Train), 1, file);
    fclose(file);
    printf("��ʱ����Ϣ¼��ɹ���\n");
}

// �����β�ѯ����Ϣ
void queryByTrainNumber()
{
    char trainNumber[10]; // �洢�û�����ĳ���
    printf("�����복�Σ�");
    scanf("%s", trainNumber);

    // �������ļ������ö����ƶ�ģʽ
    FILE* file = fopen(FILE_PATH, "rb");
    if (file == NULL) // �ļ������ڻ��޷���ȡʱ����
    {
        printf("�ļ������ڻ��޷���ȡ��\n");
        return;
    }

    Train train; // ���ڴ洢���ļ���ȡ�Ļ���Ϣ
    int found = 0; // ����Ƿ��ҵ�ƥ��ĳ���
    while (fread(&train, sizeof(Train), 1, file)) // ������ȡ����Ϣ
    {
        if (strcmp(train.trainNumber, trainNumber) == 0) // �жϳ����Ƿ�ƥ��
        {
            // ���ƥ��Ļ���Ϣ
            printf("���Σ�%s\n ���ڣ�%s\n ��㣺%s\n �յ㣺%s\n ����ʱ�䣺%s\n ����ʱ�䣺%s\n Ʊ�ۣ�%.2f\n",
                train.trainNumber, train.date, train.origin, train.destination,
                train.departureTime, train.arrivalTime, train.ticketPrice);
            found = 1; // ���Ϊ�ҵ�ƥ����
            break;
        }
    }

    if (!found) // ���δ�ҵ�ƥ��ĳ�����Ϣ
    {
        printf("δ�ҵ���Ӧ���ε���Ϣ��\n");
    }
    fclose(file); // �ر��ļ�
}

// ������ѯ����Ϣ
void queryOrigin()
{
    char origin[30]; // �洢�û���������
    printf("��������㣺");
    scanf("%s", origin);

    // �������ļ������ö����ƶ�ģʽ
    FILE* file = fopen(FILE_PATH, "rb");
    if (file == NULL) // �ļ������ڻ��޷���ȡʱ����
    {
        printf("�ļ������ڻ��޷���ȡ��\n");
        return;
    }

    Train train; // ���ڴ洢���ļ���ȡ�Ļ���Ϣ
    int found = 0; // ����Ƿ��ҵ�ƥ������
    printf("\n=== ������ѯ��� ===\n");
    while (fread(&train, sizeof(Train), 1, file)) // ������ȡ����Ϣ
    {
        if (strcmp(train.origin, origin) == 0) // �ж�����Ƿ�ƥ��
        {
            // ���ƥ��Ļ���Ϣ
            printf(" ���Σ�%s\n ���ڣ�%s\n ��㣺%s\n �յ㣺%s\n ����ʱ�䣺%s\n ����ʱ�䣺%s\n Ʊ�ۣ�%.2f\n",
                train.trainNumber, train.date, train.origin, train.destination,
                train.departureTime, train.arrivalTime, train.ticketPrice);
            found = 1; // ���Ϊ�ҵ�ƥ����
        }
    }

    if (!found) // ���δ�ҵ�ƥ����յ���Ϣ
    {
        printf("δ�ҵ����Ϊ %s �Ļ���Ϣ��\n", origin);
    }
    fclose(file); // �ر��ļ�
}

// ���յ��ѯ����Ϣ
void queryByDestination()
{
    char destination[30]; // �洢�û�������յ�
    printf("�������յ㣺");
    scanf("%s", destination);

    // �������ļ������ö����ƶ�ģʽ
    FILE* file = fopen(FILE_PATH, "rb");
    if (file == NULL) // �ļ������ڻ��޷���ȡʱ����
    {
        printf("�ļ������ڻ��޷���ȡ��\n");
        return;
    }

    Train train; // ���ڴ洢���ļ���ȡ�Ļ���Ϣ
    int found = 0; // ����Ƿ��ҵ�ƥ����յ�
    printf("\n=== ���յ��ѯ��� ===\n");
    while (fread(&train, sizeof(Train), 1, file)) // ������ȡ����Ϣ
    {
        if (strcmp(train.destination, destination) == 0) // �ж��յ��Ƿ�ƥ��
        {
            // ���ƥ��Ļ���Ϣ
            printf(" ���Σ�%s\n ���ڣ�%s\n ��㣺%s\n �յ㣺%s\n ����ʱ�䣺%s\n ����ʱ�䣺%s\n Ʊ�ۣ�%.2f\n",
                train.trainNumber, train.date, train.origin, train.destination,
                train.departureTime, train.arrivalTime, train.ticketPrice);
            found = 1; // ���Ϊ�ҵ�ƥ����
        }
    }

    if (!found) // ���δ�ҵ�ƥ����յ���Ϣ
    {
        printf("δ�ҵ��յ�Ϊ %s �Ļ���Ϣ��\n", destination);
    }
    fclose(file); // �ر��ļ�
}

// ���������ڲ�ѯ����Ϣ
void queryOriginDate()
{
    char origin[30], date[12]; // �ֱ�洢�û�������յ������
    printf("�������յ㣺");
    scanf("%s", origin);
    getValidatedInput("���������� (YYYY-MM-DD)��", &date, isValidDate);

    // �������ļ������ö����ƶ�ģʽ
    FILE* file = fopen(FILE_PATH, "rb");
    if (file == NULL) // �ļ������ڻ��޷���ȡʱ����
    {
        printf("�ļ������ڻ��޷���ȡ��\n");
        return;
    }

    Train train; // ���ڴ洢���ļ���ȡ�Ļ���Ϣ
    int found = 0; // ����Ƿ��ҵ�ƥ����յ������
    printf("\n=== ���յ�����ڲ�ѯ��� ===\n");
    while (fread(&train, sizeof(Train), 1, file)) // ������ȡ����Ϣ
    {
        if (strcmp(train.destination, origin) == 0 && strcmp(train.date, date) == 0) // �ж��յ�������Ƿ�ͬʱƥ��
        {
            // ���ƥ��Ļ���Ϣ
            printf(" ���Σ�%s\n ���ڣ�%s\n ��㣺%s\n �յ㣺%s\n ����ʱ�䣺%s\n ����ʱ�䣺%s\n Ʊ�ۣ�%.2f\n",
                train.trainNumber, train.date, train.origin, train.destination,
                train.departureTime, train.arrivalTime, train.ticketPrice);
            found = 1; // ���Ϊ�ҵ�ƥ����
        }
    }

    if (!found) // ���δ�ҵ�ƥ����յ��������Ϣ
    {
        printf("δ�ҵ��յ�Ϊ %s ������Ϊ %s �Ļ���Ϣ��\n", origin, date);
    }
    fclose(file); // �ر��ļ�
}

// ���յ�����ڲ�ѯ����Ϣ
void queryByDestinationAndDate()
{
    char destination[30], date[12]; // �ֱ�洢�û�������յ������
    printf("�������յ㣺");
    scanf("%s", destination);
    getValidatedInput("���������� (YYYY-MM-DD)��", &date, isValidDate);

    // �������ļ������ö����ƶ�ģʽ
    FILE* file = fopen(FILE_PATH, "rb");
    if (file == NULL) // �ļ������ڻ��޷���ȡʱ����
    {
        printf("�ļ������ڻ��޷���ȡ��\n");
        return;
    }

    Train train; // ���ڴ洢���ļ���ȡ�Ļ���Ϣ
    int found = 0; // ����Ƿ��ҵ�ƥ����յ������
    printf("\n=== ���յ�����ڲ�ѯ��� ===\n");
    while (fread(&train, sizeof(Train), 1, file)) // ������ȡ����Ϣ
    {
        if (strcmp(train.destination, destination) == 0 && strcmp(train.date, date) == 0) // �ж��յ�������Ƿ�ͬʱƥ��
        {
            // ���ƥ��Ļ���Ϣ
            printf(" ���Σ�%s\n ���ڣ�%s\n ��㣺%s\n �յ㣺%s\n ����ʱ�䣺%s\n ����ʱ�䣺%s\n Ʊ�ۣ�%.2f\n",
                train.trainNumber, train.date, train.origin, train.destination,
                train.departureTime, train.arrivalTime, train.ticketPrice);
            found = 1; // ���Ϊ�ҵ�ƥ����
        }
    }

    if (!found) // ���δ�ҵ�ƥ����յ��������Ϣ
    {
        printf("δ�ҵ��յ�Ϊ %s ������Ϊ %s �Ļ���Ϣ��\n", destination, date);
    }
    fclose(file); // �ر��ļ�
}

//�����ͳ�Ƴ�����
void countByOrigin()
{
    char origin[30]; // ���ڴ洢�û���������
    printf("��������㣺");
    scanf("%s", origin);

    // �������ļ������ö����ƶ�ģʽ
    FILE* file = fopen(FILE_PATH, "rb");
    if (file == NULL) // �ļ������ڻ��޷���ȡʱ����
    {
        printf("�ļ������ڻ��޷���ȡ��\n");
        return;
    }

    Train train; // ���ڴ洢���ļ���ȡ�Ļ���Ϣ
    int count = 0; // ͳ�����Ϊָ�����ĳ�������
    while (fread(&train, sizeof(Train), 1, file)) // ������ȡ����Ϣ
    {
        if (strcmp(train.origin, origin) == 0) // �ж�����Ƿ�ƥ��
        {
            count++; // ����
        }
    }

    fclose(file); // �ر��ļ�
    printf("���Ϊ %s ��ÿ�ճ�������%d\n", origin, count); // ���ͳ�ƽ��
}

//���յ�ͳ�Ƴ�����
void countByDestination()
{
    char destination[30]; // ���ڴ洢�û�������յ�
    printf("��������㣺");
    scanf("%s", destination);

    // �������ļ������ö����ƶ�ģʽ
    FILE* file = fopen(FILE_PATH, "rb");
    if (file == NULL) // �ļ������ڻ��޷���ȡʱ����
    {
        printf("�ļ������ڻ��޷���ȡ��\n");
        return;
    }

    Train train; // ���ڴ洢���ļ���ȡ�Ļ���Ϣ
    int count = 0; // ͳ���յ�Ϊָ�����ĳ�������
    while (fread(&train, sizeof(Train), 1, file)) // ������ȡ����Ϣ
    {
        if (strcmp(train.origin, destination) == 0) // �ж��յ��Ƿ�ƥ��
        {
            count++; // ����
        }
    }

    fclose(file); // �ر��ļ�
    printf("�յ�Ϊ %s ��ÿ�ճ�������%d\n", destination, count); // ���ͳ�ƽ��
}

// ��ʾ���л�ʱ����Ϣ
void loadTrainsFromFile()
{
    FILE* file = fopen(FILE_PATH, "rb"); // ��ֻ��ģʽ���ļ�
    if (file == NULL)
    {
        printf("�ļ������ڻ��޷���ȡ��\n");
        return;
    }

    Train train;
    printf("\n=== ��ʱ�̱� ===\n");
    while (fread(&train, sizeof(Train), 1, file))
    {
        printf(" ���Σ�%s\n ���ڣ�%s\n ��㣺%s\n �յ㣺%s\n ����ʱ�䣺%s\n ����ʱ�䣺%s\n Ʊ�ۣ�%.2f\n",
            train.trainNumber, train.date, train.origin, train.destination,
            train.departureTime, train.arrivalTime, train.ticketPrice);
        printf("-------------------------------\n"); // �ָ�ÿ����Ϣ
    }
    fclose(file);
}


Train trains[1000]; // ����һ��ȫ�����飬���ڴ洢����Ϣ
int trainCount = 0; // ȫ�ֱ������洢���ص��ڴ��еĻ�����
//��ȡ�ļ���Ϣ
void loadTrainsToMemory()
{
    FILE* file = fopen(FILE_PATH, "rb"); // �������ļ�
    if (file == NULL) // �ļ��޷���ʱ����
    {
        printf("�޷����ػ���Ϣ��\n");
        return;
    }

    trainCount = 0; // ��ʼ����¼��
    while (fread(&trains[trainCount], sizeof(Train), 1, file)) // ������ȡ����Ϣ����������
    {
        trainCount++; // ���¼�¼��
    }
    fclose(file); // �ر��ļ�
    printf("����Ϣ������ɣ��� %d ����¼��\n", trainCount); // ������ؽ��
}