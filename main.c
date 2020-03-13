//main.c
#include "user.h"
void menu()				//����˵�����
{
	printf("-------------------- 1. ��ʾ������Ϣ --------------------\n");
	printf("-------------------- 2. ������Ϣ���� --------------------\n");
	printf("-------------------- 3. ����������ѯ --------------------\n");
	printf("-------------------- 4. ������������ --------------------\n");
	printf("-------------------- 0. �˳�         --------------------\n");
}
void menuBase()			//������Ϣ����˵�����
{
	printf("-------------------- 1. �����û�     --------------------\n");
	printf("-------------------- 2. ɾ���û�     --------------------\n");
	printf("-------------------- 3. �޸��û�     --------------------\n");
	printf("-------------------- 4. ע���û����� --------------------\n");
	printf("-------------------- 5. �����û����� --------------------\n");
	printf("-------------------- 0. �����ϲ�˵� --------------------\n");
}
void menuSearch()		//����������ѯ�˵�����
{
	printf("-------------------- 1. ���绰�����ѯ --------------------\n");
	printf("-------------------- 2. ��������ѯ     --------------------\n");
	printf("-------------------- 3. �����֤�Ų�ѯ --------------------\n");
	printf("-------------------- 0. �����ϲ�˵�   --------------------\n");
}
void menuSort()            //������������˵�����
{
    printf("-------------------- 1. ����������     --------------------\n");
	printf("-------------------- 2. ����������     --------------------\n");
	printf("-------------------- 3. �����֤������ --------------------\n");
	printf("-------------------- 0. �����ϲ�˵�   --------------------\n");
}
int main ()
{
	User us[30];					//����ʵ��һά�����¼�û���Ϣ
	int choice, n;
	n = readFile(us);				//���ȶ�ȡ�ļ������ؼ�¼����
	printf("                  * ��ӭʹ���ƶ��û�����ϵͳ *                  \n");
	if(!n)
        n = createFile(us);			//���ԭ���ļ�δ�գ���Ҫ�Ƚ����ļ�
 	do{
        //system("cls");
		menu();						//��ʾ���˵�
		printf("���������ѡ��: ");
		scanf("%d", &choice);
		getchar();
		if(choice>=0 && choice <=4)
		{
            sortUser(us, n, 2);					//������˳�������¼
			n = runMain(us, n, choice); //ͨ�����ô˺�������һ���������ѡ��ִ��
		}
        else
		{
            printf("������������������ѡ����ţ���\n");
			choice = 10;
        }
    }while(choice);
	sortUser(us, n, 2);  			//�����ļ�ǰ����������
	saveFile(us, n);				//��������ļ�
	return 0;
}
int runMain(User *us, int n, int choice) 		//����ģ�飬��Ӧ��һ���˵��¸�����ѡ��ִ��
{
    switch(choice)
	{
        case 1 :
            system("cls");
            printUser(us, n);					//�����¼
			break;
        case 2 :
            system("cls");
            n = baseManage(us, n);				//������Ϣ����
            break;
        case 3 :
            system("cls");
            searchManage(us, n);				//����������ѯ
            break;
        case 4 :
            system("cls");                              //������������
            sortManage(us, n);
        case 0 :
            printf("\n$$$$$$$$$$$$$��л����ʹ�ã�$$$$$$$$$$$$$\n\n");
			break;
	
        }
	return n;
}

int baseManage(User *us, int n)			//�ú�����ɻ�����Ϣ����
{
	int choice, find[NUM];
	int temp, judge;
	User use;
	do{
		menuBase();
		do{
            printf("���������ѡ��(���):");
            scanf("%d", &choice);//����ѡ��
            getchar();
			if(choice<0 || choice>5)
				printf("������������������ѡ����ţ���\n");
		}while(choice<0 || choice>5);


		switch(choice)
		{
			case 1 :
				readUser(&use, 1);		//����һ����������û���Ϣ
				printUser(&use, 1);
				n = addUser(us, n, use);  //���ú��������û���¼
				break;
			case 2 :
				printf("�������ɾ���û������֤��:");
				scanf("%s", use.ID);			//����һ����ɾ�����û����֤��
				n = deleteUser(us, n, use);	//���ú���ɾ��ָ�����֤�ŵ��û���¼
				break;
			case 3 :
				printf("��������޸��û��ĵ绰����:");
				scanf("%lf", &use.phonenum[0]);
				temp = searchUser(us, n, use, 1, find);
				if(temp)
				{
					modifyUser(&us[find[0]]);	//����ҵ��ü�¼������޸ĳ���
				}
				else
					printf("���û������ڣ��޷������޸�\n");
				break;
            case 4 :
                printf("��������Ҫȡ���ĵ绰����:");
                scanf("%lf", &use.phonenum[0]);
                cancelphone(us, n, use);
                break;
            case 5 :
                printf("��������Ҫ���Ӻ�����û����֤��:");
                scanf("%s", use.ID);
                getchar();
                printf("��������Ҫ���ӵĺ���:");
                scanf("%lf", &use.phonenum[0]);
                getchar();
                judge = searchUser(us, n, use, 1, find);
                if(!judge)
				{
                    temp = searchUser(us, n, use, 3, find);
                    if(temp)
                        addPhoneNum(&us[find[0]], use);	//����ҵ��ü�¼��������Ӻ������
                    else
                        printf("���û������ڣ��޷����в���\n");
                }
                else
                    printf("�ú����Ѵ��� !\n");
                break;
			case 0 :
			    system("cls");
				printf("��л����ʹ�ã�\n");
				break;
		}
	}while(choice);
	return n;						//���ص�ǰ�����������ʵ�ʼ�¼����
}
void searchManage(User *us, int n)	//�ú�����ɸ���������ѯ����
{
	int i, choice, findnum, f[NUM];
	User use;
	do
	{
		menuSearch();				//��ʾ��Ӧ�Ķ����˵�
		do
		{
            printf("���������ѡ��(���):");
            scanf("%d", &choice);
            getchar();
			if(choice < 1 || choice > 3)
				printf("������������������ѡ����ţ���\n");
		}while(choice<0 || choice>3);

		switch(choice)
		{
			case 1 :
				printf("������ѯ�û��ĵ绰 :");
				scanf("%lf", &use.phonenum[0]);	//�������ѯ�û��ĵ绰����
				break;
			case 2 :
				printf("������ѯ�û������� :");
				scanf("%s", use.name);			//�������ѯ�û�������
				break;
			case 3 :
				printf("������ѯ�û������֤���� :");
				scanf("%s", use.ID);			//�������ѯ�û���ID
				break;
			case 0 :
			    system("cls");
				break;
		}
		if(choice >= 1 && choice <= 3)
		{
			
			findnum = searchUser(us, n, use, choice, f);   //���ҵķ���Ԫ�ص��±����f������
			if(findnum)
			{				//������ҳɹ�
				for(i=0; i<findnum; i++)//ѭ������f������±�
					printUser(&us[f[i]], 1); //ÿ�����һ����¼
			}
			else
				printf("������ݼ�¼������ ! \n");		//������Ҳ���Ԫ�أ��������ʾ��Ϣ
		}
	}while(choice);
}
void sortManage(User *us, int n)                //�ú�����ɰ�����������
{
    int choice;
	do
	{
		menuSort();				//��ʾ��Ӧ�Ķ����˵�
		do
		{
            printf("���������ѡ��(���):");
            scanf("%d", &choice);
            getchar();			//����ѡ��
		    if(choice<0 || choice>3); 
				printf("������������������ѡ����ţ���\n");
		}while(choice<0 || choice>3);

		switch(choice)
		{
			case 1 :
			    system("cls");
				sortUser(us, n, 4);
				break;
			case 2 :
			    system("cls");
                sortUser(us, n, 2);
				break;
			case 3 :
			    system("cls");
                sortUser(us, n, 3);
				break;
            case 0 :
                system("cls");
				break;
		}
		printUser(us, n);
	}while(choice);
}