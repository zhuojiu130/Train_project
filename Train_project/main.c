#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>
#include "function.h"
#include "utils.h"
#include "train.h"
#include <Windows.h>

void mainMenu();

int main()
{
    ensureDataFolderExists();   //���������ļ���
    loadTrainsToMemory();       // ���ļ����ػ���Ϣ���ڴ�
    mainMenu();	// ��ʾ���˵�
    return 0;
}

//�˵����ܺ���
void mainMenu()
{
    int choice;
    do {
        system("cls");  // ��������ǿ�Ӿ�Ч��
        printf("\n=== ��Ʊ��ϵͳ ===\n");
        printf("1. ¼���ʱ����Ϣ\n");
        printf("2. �����β�ѯ��ʱ����Ϣ\n");
        printf("3. ������ѯ��ʱ����Ϣ\n");
        printf("4. ���յ��ѯ��ʱ����Ϣ\n");
        printf("5. ���������ڲ�ѯ\n");
        printf("6. ���յ�����ڲ�ѯ\n");
        printf("7. �����ͳ�Ƴ�����\n");
        printf("8. ���յ�ͳ�Ƴ�����\n");
        printf("9. ��ʾ���л�ʱ����Ϣ\n");
        printf("0. �˳�\n");
        printf("����������ѡ��");
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
        case 10: printf("�˳�ϵͳ��\n"); break;
        default: printf("��Ч��ѡ�����������롣\n");
        }
        if (choice != 10)
        {
            system("pause"); // �ȴ��û�����
        }
    } while (choice != 10);
}