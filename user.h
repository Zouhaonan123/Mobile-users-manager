#include <stdlib.h>
#include <stdio.h>
#include <string.h>

#ifndef _USER				//条件编译
#define _USER
#define NUM 20				//定义用户人数常量
struct User 				//用户记录的数据域
{
	char name[20];			//姓名
	char sex;				//性别
	int age;       			//年龄
	char ID[20];			//身份证号
	double phonenum[3];		//每个人最多三条电话号码
	char profession[20];	//职业
	char address[20];		//家庭住址
	int rank;				//排名
};
typedef struct User User;
#define sizeUser sizeof(User)	//一个用户记录所需要的内存空间大小
//user头文件
int readUser(User *us, int n);  //读入用户记录，返回读入记录条数，最多记录n条数据
void printUser(User *us, int n); //输出所有用户信息
int equal(User u1, User u2, int condition); //根据condition判断两个User数据是否相等
int equalphone(User u1, User u2);           //比较两个数组大小
int larger(User u1, User u2, int condition); //根据condition比较两个User的大小
void reverse(User *us, int n);			//用户数组元素逆置
void sortUser(User *us, int n, int condition); //根据condition从小到大对数组进行排序
int searchUser(User *us, int n, User use, int condition, int *f); //根据condition进行查找与use相同的元素， 下标置于数组f中， 因为可能有多个元素符合条件
void modifyUser(User *u1);   //修改用户数据
int addUser(User *us, int n, User use); //向数组尾部增加一个元素按姓名排序
int deleteUser(User *us, int n, User use); //从数组中删除一个指定姓名的元素
void cancelphone(User *us, int n, User use);//注销指定用户的手机号
void addPhoneNum(User *us, User use);//增加指定用户的手机号

//file头文件
int createFile(User *us);           //创建文件存储数据
int readFile(User *us);             //读取文件中数据
void saveFile(User *us, int n);     //保存数据

//main头文件
void menu();    			//顶层菜单函数
int runMain(User *us, int n, int choice);  //主控模块，对应于一级菜单下各功能选择执行
void menuBase();			//基本信息管理菜单程序
int baseManage(User *us, int n);		//该函数完成基本信息管理
void menuSearch();		//根据条件查询菜单函数
void searchManage(User *us, int n);	//该函数完成根据条件查询功能
void menuSort();            //根据条件排序菜单函数
void sortManage(User *us, int n);        //该函数完成按条件排序功能
#endif

