#pragma once
#ifndef FUNCTION_H
#define FUNCTION_H

//��������
void ensureDataFolderExists();	//�����ļ��к���

void addTrainInfo(); //����Ϣ¼��

void loadTrainsToMemory();	//��Ϣ��ȡ

void queryByTrainNumber();	// �����β�ѯ����Ϣ

void queryOrigin();	// ������ѯ����Ϣ

void queryByDestination();	// ���յ��ѯ����Ϣ

void queryOriginDate();	// ���������ڲ�ѯ����Ϣ

void queryByDestinationAndDate();	// ���յ�����ڲ�ѯ����Ϣ

void countByOrigin();	//�����ͳ�Ƴ�����

void countByDestination();	//���յ�ͳ�Ƴ�����

void loadTrainsFromFile();	// ��ʾ���л�ʱ����Ϣ

#endif 