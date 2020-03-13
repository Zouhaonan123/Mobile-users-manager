//main.c
#include "user.h"
void menu()				//顶层菜单函数
{
	printf("-------------------- 1. 显示基本信息 --------------------\n");
	printf("-------------------- 2. 基本信息管理 --------------------\n");
	printf("-------------------- 3. 根据条件查询 --------------------\n");
	printf("-------------------- 4. 根据条件排序 --------------------\n");
	printf("-------------------- 0. 退出         --------------------\n");
}
void menuBase()			//基本信息管理菜单程序
{
	printf("-------------------- 1. 增加用户     --------------------\n");
	printf("-------------------- 2. 删除用户     --------------------\n");
	printf("-------------------- 3. 修改用户     --------------------\n");
	printf("-------------------- 4. 注销用户号码 --------------------\n");
	printf("-------------------- 5. 增加用户号码 --------------------\n");
	printf("-------------------- 0. 返回上层菜单 --------------------\n");
}
void menuSearch()		//根据条件查询菜单函数
{
	printf("-------------------- 1. 按电话号码查询 --------------------\n");
	printf("-------------------- 2. 按姓名查询     --------------------\n");
	printf("-------------------- 3. 按身份证号查询 --------------------\n");
	printf("-------------------- 0. 返回上层菜单   --------------------\n");
}
void menuSort()            //根据条件排序菜单函数
{
    printf("-------------------- 1. 按年龄排序     --------------------\n");
	printf("-------------------- 2. 按姓名排序     --------------------\n");
	printf("-------------------- 3. 按身份证号排序 --------------------\n");
	printf("-------------------- 0. 返回上层菜单   --------------------\n");
}
int main ()
{
	User us[30];					//定义实参一维数组记录用户信息
	int choice, n;
	n = readFile(us);				//首先读取文件，返回记录条数
	printf("                  * 欢迎使用移动用户管理系统 *                  \n");
	if(!n)
        n = createFile(us);			//如果原来文件未空，则要先建立文件
 	do{
        //system("cls");
		menu();						//显示主菜单
		printf("请输入你的选择: ");
		scanf("%d", &choice);
		getchar();
		if(choice>=0 && choice <=4)
		{
            sortUser(us, n, 2);					//按姓名顺序排序记录
			n = runMain(us, n, choice); //通过调用此函数进行一级功能项的选择执行
		}
        else
		{
            printf("输入有误，请重新输入选择（序号）！\n");
			choice = 10;
        }
    }while(choice);
	sortUser(us, n, 2);  			//存入文件前按姓名排序
	saveFile(us, n);				//结果存入文件
	return 0;
}
int runMain(User *us, int n, int choice) 		//主控模块，对应于一级菜单下各功能选择执行
{
    switch(choice)
	{
        case 1 :
            system("cls");
            printUser(us, n);					//输出记录
			break;
        case 2 :
            system("cls");
            n = baseManage(us, n);				//基本信息管理
            break;
        case 3 :
            system("cls");
            searchManage(us, n);				//根据条件查询
            break;
        case 4 :
            system("cls");                              //根据条件排序
            sortManage(us, n);
        case 0 :
            printf("\n$$$$$$$$$$$$$感谢您的使用！$$$$$$$$$$$$$\n\n");
			break;
	
        }
	return n;
}

int baseManage(User *us, int n)			//该函数完成基本信息管理
{
	int choice, find[NUM];
	int temp, judge;
	User use;
	do{
		menuBase();
		do{
            printf("请输入你的选择(序号):");
            scanf("%d", &choice);//读入选项
            getchar();
			if(choice<0 || choice>5)
				printf("输入有误，请重新输入选择（序号）！\n");
		}while(choice<0 || choice>5);


		switch(choice)
		{
			case 1 :
				readUser(&use, 1);		//读入一条待插入的用户信息
				printUser(&use, 1);
				n = addUser(us, n, use);  //调用函数插入用户记录
				break;
			case 2 :
				printf("请输入待删除用户的身份证号:");
				scanf("%s", use.ID);			//读入一个待删除的用户身份证号
				n = deleteUser(us, n, use);	//调用函数删除指定身份证号的用户记录
				break;
			case 3 :
				printf("请输入待修改用户的电话号码:");
				scanf("%lf", &use.phonenum[0]);
				temp = searchUser(us, n, use, 1, find);
				if(temp)
				{
					modifyUser(&us[find[0]]);	//如果找到该记录则进行修改程序
				}
				else
					printf("此用户不存在，无法进行修改\n");
				break;
            case 4 :
                printf("请输入需要取消的电话号码:");
                scanf("%lf", &use.phonenum[0]);
                cancelphone(us, n, use);
                break;
            case 5 :
                printf("请输入需要增加号码的用户身份证号:");
                scanf("%s", use.ID);
                getchar();
                printf("请输入需要增加的号码:");
                scanf("%lf", &use.phonenum[0]);
                getchar();
                judge = searchUser(us, n, use, 1, find);
                if(!judge)
				{
                    temp = searchUser(us, n, use, 3, find);
                    if(temp)
                        addPhoneNum(&us[find[0]], use);	//如果找到该记录则进行增加号码操作
                    else
                        printf("该用户不存在，无法进行操作\n");
                }
                else
                    printf("该号码已存在 !\n");
                break;
			case 0 :
			    system("cls");
				printf("感谢您的使用！\n");
				break;
		}
	}while(choice);
	return n;						//返回当前操作结束后的实际记录条数
}
void searchManage(User *us, int n)	//该函数完成根据条件查询功能
{
	int i, choice, findnum, f[NUM];
	User use;
	do
	{
		menuSearch();				//显示对应的二级菜单
		do
		{
            printf("请输入你的选择(序号):");
            scanf("%d", &choice);
            getchar();
			if(choice < 1 || choice > 3)
				printf("输入有误，请重新输入选择（序号）！\n");
		}while(choice<0 || choice>3);

		switch(choice)
		{
			case 1 :
				printf("输入查待询用户的电话 :");
				scanf("%lf", &use.phonenum[0]);	//输入待查询用户的电话号码
				break;
			case 2 :
				printf("输入查待询用户的姓名 :");
				scanf("%s", use.name);			//输入待查询用户的姓名
				break;
			case 3 :
				printf("输入查待询用户的身份证号码 :");
				scanf("%s", use.ID);			//输入待查询用户的ID
				break;
			case 0 :
			    system("cls");
				break;
		}
		if(choice >= 1 && choice <= 3)
		{
			
			findnum = searchUser(us, n, use, choice, f);   //查找的符合元素的下标存于f数组中
			if(findnum)
			{				//如果查找成功
				for(i=0; i<findnum; i++)//循环控制f数组的下标
					printUser(&us[f[i]], 1); //每次输出一条记录
			}
			else
				printf("这个数据记录不存在 ! \n");		//如果查找不到元素，则输出提示信息
		}
	}while(choice);
}
void sortManage(User *us, int n)                //该函数完成按条件排序功能
{
    int choice;
	do
	{
		menuSort();				//显示对应的二级菜单
		do
		{
            printf("请输入你的选择(序号):");
            scanf("%d", &choice);
            getchar();			//读入选项
		    if(choice<0 || choice>3); 
				printf("输入有误，请重新输入选择（序号）！\n");
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