#include "user.h"
int createFile(User *us)			//������ʼ�������ļ�
{
	FILE *fp=NULL;
	int n;
	if((fp = fopen("C:\\Users\\�ƶ��û�����4\\�û���Ϣ.dat", "wb")) == NULL)
	{	//ָ�����ļ�������д�뷽ʽ��
		printf("�޷����ļ� !\n");		//����ʧ�ܣ��������ʾ��Ϣ
		exit(0);
	}
	
	printf("�������û���Ϣ :\n");
	n = readUser(us, NUM);				//����user.h�еĺ���������
	fwrite(us, sizeUser, n, fp);		//������ļ�¼һ����д���ļ�
    fclose(fp);							//�ر��ļ�
	return n;
	}

int readFile(User *us)				//���ļ��е��������ڽṹ������us��
{
	FILE *fp=NULL;
	int i = 0;
	if((fp = fopen("C:\\Users\\�ƶ��û�����4\\�û���Ϣ.dat", "rb")) == NULL)
	{		//�Զ��ķ�ʽ��ָ���ļ�
		printf("���ļ������ڣ����ȴ������ļ�:\n"); //�����ʧ�ܣ��������ʾ��Ϣ
		return 0;
	}
    fread(&us[i], sizeUser, 1, fp);		//������һ����¼
	while(!feof(fp))
	{
		i++;
		fread(&us[i], sizeUser, 1, fp);//�ٶ�����һ����¼
	}
	fclose(fp);							//�ر��ļ�
	return i;							//���ؼ�¼����
}
void saveFile(User *us, int n)			//���ṹ������д���ļ�
{
	FILE *fp=NULL;
	if((fp = fopen("C:\\Users\\�ƶ��û�����4\\�û���Ϣ.dat", "wb")) == NULL)
	{			//��д�ķ�ʽ��ָ���ļ�
		printf("�޷����ļ� !\n");		//�����ʧ�ܣ��������ʾ��Ϣ
		exit(0);
	}
	fwrite(us, sizeUser, n, fp);
	fclose(fp);
}
