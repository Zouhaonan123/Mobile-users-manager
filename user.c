//user.c
#include "user.h"
int readUser(User *us, int n)		//读入用户记录，最多读入n条记录，号码默认11位
{
	int i=0, j=0; //i记录读入用户人数，
	char ch1, ch2;
    do{
        printf("请输入用户姓名：\n");
        scanf("%s", us[i].name);
        for(j=0; j<3; j++)
            us[i].phonenum[j] = 0;
		for(j=0; j<3; j++)
		{
            printf("请输入用户电话号码（11位数字）:\n");
            scanf("%lf", &us[i].phonenum[j]);
            fflush(stdin);
			printf("还继续输入该用户电话吗？(y/n)：\n");
            scanf("%c", &ch1);
            fflush(stdin);
            if(ch1 != 'y' )
                break;
        }
		printf("请输入用户性别(m/f)：\n");
		scanf("%c", &us[i].sex);
        fflush(stdin);
        printf("请输入用户年龄：\n" );
        scanf("%d", &us[i].age);
        fflush(stdin);
        printf("请输入用户身份证号码：\n");
        scanf("%s", us[i].ID);
        fflush(stdin);
        printf("请输入用户职业：\n" );
        scanf("%s", us[i].profession);
        fflush(stdin);
        printf("请输入用户地址：\n" );
        scanf("%s", us[i].address);
        fflush(stdin);
        us[i].rank = 0;
        i++;
        if(i >= n)
            return i;
        printf("还要继续输入用户数据吗？（y/n）\n");
        scanf("%c", &ch2);
    }while(ch2 == 'y' || ch2 == 'Y');
	return i;						//返回实际读入的记录数
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
int eqaul(User u1, User u2, int condition)  //判断两个数据相等
{
	if (condition == 1)						//如果condition为1，比较电话号码
		return equalphone(u1, u2);
	else if (condition == 2) 
	{
		if(strcmp(u1.name, u2.name) == 0)
			return 1;
		else
			return 0;
	}   			//如果condition为2，则比较姓名
	else if (condition == 3)
	{			//如果condition为3，则比较身份证号
		if(strcmp(u1.ID, u2.ID) == 0)
		{
			return 1;
		}
		else
			return 0;
	}
	else return 1;					//其余情况返回1；
}
int larger(User u1, User u2, int condition) //根据condition比较两个User数据的大小
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

void printUser(User *us, int n)		//输出所有用户值
{
	int i, j;
	printf("&&-------------------------------------------------------------------------------------------------&&\n");
	printf("  %-6s%-6s%-6s%-19s%-12s%-12s%-12s%-10s%-10s%-4s\n","姓名 ","性别","年龄","身份证号","电话号码1","电话号码2","电话号码3","职业","地址","名次");
	for(i=0; i<n; i++)
	{
		printf("  %-6s", us[i].name );
		
		if(us[i].sex == 'm')
            printf("%-6s", "男" );
        else
            printf("%-6s", "女" );
		
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
void sortUser(User *us, int n, int condition) //使用选择法排序，按condition从小到大排
{
	int i, j, minpos;     		//minpos用来存储本趟最小元素所在的下标
	User temp;
	for(i=0; i< n-1; i++)
	{
		minpos = i;
		for(j=i+1; j<n; j++)//寻找本趟最小元素
		{	
			if (larger(us[minpos], us[j], condition) > 0)
				minpos = j;
		}
		if(i != minpos)
		{		//保证本趟最小元素到达下标为i位置
			temp = us[i];
			us[i] = us[minpos];
			us[minpos] = temp;
		}
		us[i].rank = i+1;
	}
	us[i].rank = n;
}

int searchUser(User *us, int n, User use, int condition, int *f) //依据condition查找，可能符合条件的数据不只一条，因此将元素下标存在数组f中
{
	int i, j=0, find=0;
	for(i=0; i<n; i++)
	{
		if(eqaul(us[i], use, condition))
		{
			f[j++] = i;						//找到了相等元素，将下标置于f数组中
			find++;							//统计找到了的元素个数
		}
	}
	return find;							//返回find 值，若值为0，则表示没找到
}

void modifyUser(User *u1)
{
    printf("请输入用户姓名：");
    scanf("%s", u1->name);
    getchar();

    printf("请输入用户性别(m/f)：");
    scanf("%c", &u1->sex);
	
    getchar();

    printf("请输入用户年龄：" );
    scanf("%d", &u1->age);
    getchar();

    printf("请输入用户身份证号码：");
    scanf("%s", u1->ID);
    getchar();

    printf("请输入用户职业：" );
    scanf("%s", u1->profession);
    getchar();

    printf("请输入用户地址：" );
    scanf("%s", u1->address);
    getchar();

    

}

int addUser(User *us, int n, User use)   //向数组元素依身份证号递增插入一个元素
{
	int i;
	sortUser(us, n, 3); 					//先按身份证号排序
	for(i=0; i<n; i++)
	{
		if(eqaul(us[i], use, 3)||eqaul(us[i], use, 1))
		{
			printf("此用户已存在，请重新输入!\n");
			return n;
		}			//如果身份证号相同则不允许插入， 保证身份证号的唯一性
		else if(eqaul(us[i], use, 2))
			break;
	}
    
    us[n] = use;                      //在下标第n处插入元素use
    n++;								//元素个数加一
    return n;
}

int deleteUser(User *us, int n, User use)	//从数组中删除指定身份证号的一个元素
{
	int i, j;
	for(i=0; i<n; i++)
		if(eqaul(us[i], use, 3))	//寻找待删除元素
			break;					//如果找不到相等相等元素就退出循环
	if(i == n)
	{
		printf("此记录不存在，请重新输入！\n"); //给出提示信息后返回
		return n;
	}

	if(us[i].phonenum[0]==0 && us[i].phonenum[1]==0 && us[i].phonenum[2]==0)
	{
        for(j=i; j<n-1; j++)
            us[j] = us[j+1];           //通过移动覆盖下标为i的元素
            printf("删除成功！\n");
        n--; 							//元素个数减一
	}
    else
        printf("请先注销用户所有电话号码!\n");
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
					printf("********注销成功！********\n");
				    return;
				}
			}
		}
	}	
    if( i == n )
        printf("未找到此电话号码！此电话号码记录不存在！\n");
}

void addPhoneNum(User *u1, User use)
{
    int i, flag=0;
   
    for(i=0; i<3; i++)
	{
        if(!(u1->phonenum[i]))
		{
            u1->phonenum[i] = use.phonenum[0];
            printf("增加成功！\n");
            flag = 1;
            break;
        }
    }
    
    if(!flag)
        printf("电话号码已满，无法增加！\n");
}