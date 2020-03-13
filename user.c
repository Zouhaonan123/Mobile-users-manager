//user.c
#include "user.h"
int readUser(User *us, int n)		//�����û���¼��������n����¼������Ĭ��11λ
{
	int i=0, j=0; //i��¼�����û�������
	char ch1, ch2;
    do{
        printf("�������û�������\n");
        scanf("%s", us[i].name);
        for(j=0; j<3; j++)
            us[i].phonenum[j] = 0;
		for(j=0; j<3; j++)
		{
            printf("�������û��绰���루11λ���֣�:\n");
            scanf("%lf", &us[i].phonenum[j]);
            fflush(stdin);
			printf("������������û��绰��(y/n)��\n");
            scanf("%c", &ch1);
            fflush(stdin);
            if(ch1 != 'y' )
                break;
        }
		printf("�������û��Ա�(m/f)��\n");
		scanf("%c", &us[i].sex);
        fflush(stdin);
        printf("�������û����䣺\n" );
        scanf("%d", &us[i].age);
        fflush(stdin);
        printf("�������û����֤���룺\n");
        scanf("%s", us[i].ID);
        fflush(stdin);
        printf("�������û�ְҵ��\n" );
        scanf("%s", us[i].profession);
        fflush(stdin);
        printf("�������û���ַ��\n" );
        scanf("%s", us[i].address);
        fflush(stdin);
        us[i].rank = 0;
        i++;
        if(i >= n)
            return i;
        printf("��Ҫ���������û������𣿣�y/n��\n");
        scanf("%c", &ch2);
    }while(ch2 == 'y' || ch2 == 'Y');
	return i;						//����ʵ�ʶ���ļ�¼��
}
int equalphone(User u1, User u2)
{
    int i, j, flag=0;
    for(i=0; i<3; i++)
	{
        if(u1.phonenum[i] != 0 )
		{
            for(j=0; j<3; j++)
			{
                if(u1.phonenum[i] == u2.phonenum[j])
				{
					flag = 1;
                    break;
				}
            }
        }
    }
    return flag;
}
int eqaul(User u1, User u2, int condition)  //�ж������������
{
	if (condition == 1)						//���conditionΪ1���Ƚϵ绰����
		return equalphone(u1, u2);
	else if (condition == 2) 
	{
		if(strcmp(u1.name, u2.name) == 0)
			return 1;
		else
			return 0;
	}   			//���conditionΪ2����Ƚ�����
	else if (condition == 3)
	{			//���conditionΪ3����Ƚ����֤��
		if(strcmp(u1.ID, u2.ID) == 0)
		{
			return 1;
		}
		else
			return 0;
	}
	else return 1;					//�����������1��
}
int larger(User u1, User u2, int condition) //����condition�Ƚ�����User���ݵĴ�С
{
    if(condition == 4)
	{
        return u1.age > u2.age;
    }
    else if(condition == 2)
	{
		return strcmp(u1.name, u2.name);
	}
	else if(condition == 3)
		return strcmp(u1.ID, u2.ID);
    else return 1;
}

void printUser(User *us, int n)		//��������û�ֵ
{
	int i, j;
	printf("&&-------------------------------------------------------------------------------------------------&&\n");
	printf("  %-6s%-6s%-6s%-19s%-12s%-12s%-12s%-10s%-10s%-4s\n","���� ","�Ա�","����","���֤��","�绰����1","�绰����2","�绰����3","ְҵ","��ַ","����");
	for(i=0; i<n; i++)
	{
		printf("  %-6s", us[i].name );
		
		if(us[i].sex == 'm')
            printf("%-6s", "��" );
        else
            printf("%-6s", "Ů" );
		
		printf("%-6d", us[i].age );
		printf("%-19s", us[i].ID );
		
		for(j=0; j<3; j++)
            printf("%-11.0f ", us[i].phonenum[j] );

		printf("%-10s", us[i].profession );
		printf("%-10s", us[i].address );
		printf("%-4d", us[i].rank );
		printf("\n");
	}
	printf("&&-------------------------------------------------------------------------------------------------&&\n");
}
void sortUser(User *us, int n, int condition) //ʹ��ѡ�����򣬰�condition��С������
{
	int i, j, minpos;     		//minpos�����洢������СԪ�����ڵ��±�
	User temp;
	for(i=0; i< n-1; i++)
	{
		minpos = i;
		for(j=i+1; j<n; j++)//Ѱ�ұ�����СԪ��
		{	
			if (larger(us[minpos], us[j], condition) > 0)
				minpos = j;
		}
		if(i != minpos)
		{		//��֤������СԪ�ص����±�Ϊiλ��
			temp = us[i];
			us[i] = us[minpos];
			us[minpos] = temp;
		}
		us[i].rank = i+1;
	}
	us[i].rank = n;
}

int searchUser(User *us, int n, User use, int condition, int *f) //����condition���ң����ܷ������������ݲ�ֻһ������˽�Ԫ���±��������f��
{
	int i, j=0, find=0;
	for(i=0; i<n; i++)
	{
		if(eqaul(us[i], use, condition))
		{
			f[j++] = i;						//�ҵ������Ԫ�أ����±�����f������
			find++;							//ͳ���ҵ��˵�Ԫ�ظ���
		}
	}
	return find;							//����find ֵ����ֵΪ0�����ʾû�ҵ�
}

void modifyUser(User *u1)
{
    printf("�������û�������");
    scanf("%s", u1->name);
    getchar();

    printf("�������û��Ա�(m/f)��");
    scanf("%c", &u1->sex);
	
    getchar();

    printf("�������û����䣺" );
    scanf("%d", &u1->age);
    getchar();

    printf("�������û����֤���룺");
    scanf("%s", u1->ID);
    getchar();

    printf("�������û�ְҵ��" );
    scanf("%s", u1->profession);
    getchar();

    printf("�������û���ַ��" );
    scanf("%s", u1->address);
    getchar();

    

}

int addUser(User *us, int n, User use)   //������Ԫ�������֤�ŵ�������һ��Ԫ��
{
	int i;
	sortUser(us, n, 3); 					//�Ȱ����֤������
	for(i=0; i<n; i++)
	{
		if(eqaul(us[i], use, 3)||eqaul(us[i], use, 1))
		{
			printf("���û��Ѵ��ڣ�����������!\n");
			return n;
		}			//������֤����ͬ��������룬 ��֤���֤�ŵ�Ψһ��
		else if(eqaul(us[i], use, 2))
			break;
	}
    
    us[n] = use;                      //���±��n������Ԫ��use
    n++;								//Ԫ�ظ�����һ
    return n;
}

int deleteUser(User *us, int n, User use)	//��������ɾ��ָ�����֤�ŵ�һ��Ԫ��
{
	int i, j;
	for(i=0; i<n; i++)
		if(eqaul(us[i], use, 3))	//Ѱ�Ҵ�ɾ��Ԫ��
			break;					//����Ҳ���������Ԫ�ؾ��˳�ѭ��
	if(i == n)
	{
		printf("�˼�¼�����ڣ����������룡\n"); //������ʾ��Ϣ�󷵻�
		return n;
	}

	if(us[i].phonenum[0]==0 && us[i].phonenum[1]==0 && us[i].phonenum[2]==0)
	{
        for(j=i; j<n-1; j++)
            us[j] = us[j+1];           //ͨ���ƶ������±�Ϊi��Ԫ��
            printf("ɾ���ɹ���\n");
        n--; 							//Ԫ�ظ�����һ
	}
    else
        printf("����ע���û����е绰����!\n");
	return n;
}

void cancelphone(User *us, int n, User use)
{
    int i, j;
    for(i=0; i<n; i++)
	{
		if(eqaul(us[i], use, 1))
		{
			for(j=0; j<3; j++)
			{
				if(us[i].phonenum[j] == use.phonenum[0])
				{
					us[i].phonenum[j] = 0;
					printf("********ע���ɹ���********\n");
				    return;
				}
			}
		}
	}	
    if( i == n )
        printf("δ�ҵ��˵绰���룡�˵绰�����¼�����ڣ�\n");
}

void addPhoneNum(User *u1, User use)
{
    int i, flag=0;
   
    for(i=0; i<3; i++)
	{
        if(!(u1->phonenum[i]))
		{
            u1->phonenum[i] = use.phonenum[0];
            printf("���ӳɹ���\n");
            flag = 1;
            break;
        }
    }
    
    if(!flag)
        printf("�绰�����������޷����ӣ�\n");
}