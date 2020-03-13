#include "user.h"
int createFile(User *us)			//建立初始的数据文件
{
	FILE *fp=NULL;
	int n;
	if((fp = fopen("C:\\Users\\移动用户管理4\\用户信息.dat", "wb")) == NULL)
	{	//指定好文件名，以写入方式打开
		printf("无法打开文件 !\n");		//若打开失败，则输出提示信息
		exit(0);
	}
	
	printf("请输入用户信息 :\n");
	n = readUser(us, NUM);				//调用user.h中的函数读数据
	fwrite(us, sizeUser, n, fp);		//将读入的记录一次性写入文件
    fclose(fp);							//关闭文件
	return n;
	}

int readFile(User *us)				//将文件中的内容置于结构体数组us中
{
	FILE *fp=NULL;
	int i = 0;
	if((fp = fopen("C:\\Users\\移动用户管理4\\用户信息.dat", "rb")) == NULL)
	{		//以读的方式打开指定文件
		printf("此文件不存在，请先创建该文件:\n"); //如果打开失败，则输出提示信息
		return 0;
	}
    fread(&us[i], sizeUser, 1, fp);		//读出第一条记录
	while(!feof(fp))
	{
		i++;
		fread(&us[i], sizeUser, 1, fp);//再读出下一条记录
	}
	fclose(fp);							//关闭文件
	return i;							//返回记录条数
}
void saveFile(User *us, int n)			//将结构体数组写入文件
{
	FILE *fp=NULL;
	if((fp = fopen("C:\\Users\\移动用户管理4\\用户信息.dat", "wb")) == NULL)
	{			//以写的方式打开指定文件
		printf("无法打开文件 !\n");		//如果打开失败，则输出显示信息
		exit(0);
	}
	fwrite(us, sizeUser, n, fp);
	fclose(fp);
}
