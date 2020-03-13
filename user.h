#include <stdlib.h>
#include <stdio.h>
#include <string.h>

#ifndef _USER				//��������
#define _USER
#define NUM 20				//�����û���������
struct User 				//�û���¼��������
{
	char name[20];			//����
	char sex;				//�Ա�
	int age;       			//����
	char ID[20];			//���֤��
	double phonenum[3];		//ÿ������������绰����
	char profession[20];	//ְҵ
	char address[20];		//��ͥסַ
	int rank;				//����
};
typedef struct User User;
#define sizeUser sizeof(User)	//һ���û���¼����Ҫ���ڴ�ռ��С
//userͷ�ļ�
int readUser(User *us, int n);  //�����û���¼�����ض����¼����������¼n������
void printUser(User *us, int n); //��������û���Ϣ
int equal(User u1, User u2, int condition); //����condition�ж�����User�����Ƿ����
int equalphone(User u1, User u2);           //�Ƚ����������С
int larger(User u1, User u2, int condition); //����condition�Ƚ�����User�Ĵ�С
void reverse(User *us, int n);			//�û�����Ԫ������
void sortUser(User *us, int n, int condition); //����condition��С����������������
int searchUser(User *us, int n, User use, int condition, int *f); //����condition���в�����use��ͬ��Ԫ�أ� �±���������f�У� ��Ϊ�����ж��Ԫ�ط�������
void modifyUser(User *u1);   //�޸��û�����
int addUser(User *us, int n, User use); //������β������һ��Ԫ�ذ���������
int deleteUser(User *us, int n, User use); //��������ɾ��һ��ָ��������Ԫ��
void cancelphone(User *us, int n, User use);//ע��ָ���û����ֻ���
void addPhoneNum(User *us, User use);//����ָ���û����ֻ���

//fileͷ�ļ�
int createFile(User *us);           //�����ļ��洢����
int readFile(User *us);             //��ȡ�ļ�������
void saveFile(User *us, int n);     //��������

//mainͷ�ļ�
void menu();    			//����˵�����
int runMain(User *us, int n, int choice);  //����ģ�飬��Ӧ��һ���˵��¸�����ѡ��ִ��
void menuBase();			//������Ϣ����˵�����
int baseManage(User *us, int n);		//�ú�����ɻ�����Ϣ����
void menuSearch();		//����������ѯ�˵�����
void searchManage(User *us, int n);	//�ú�����ɸ���������ѯ����
void menuSort();            //������������˵�����
void sortManage(User *us, int n);        //�ú�����ɰ�����������
#endif

