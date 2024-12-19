#pragma once

#include "Student_Info.h"
#include "Repair_Info.h"
#include "Student_Login.h"
#include "Dorm_Master.h"
#include <string>

#define SQL_MAX 256 //sql语句字符数组最大值
class SQLinterface
{
public:
	MYSQL_RES* res;//result
	MYSQL_ROW row;//按行存储
	MYSQL mysqlCon;
	char sql[SQL_MAX];//用于存储SQL语句

	bool ConnectMysql();//连接数据库
	vector<Student_Info> Get_AllStu_info();//查询全部学生信息
	vector<Student_Info> Get_SameStuID_info(CString id);//根据ID查询相关宿舍信息
	vector<Student_Info> Search_StuID_info(CString id);//根据ID查询学生

	vector<Repair_Info> Get_AllRepair_info();//查询全部报修信息
	vector<Repair_Info> Search_StuRepair_info(CString id);//根据ID查询报修信息

	bool Add_Stu_info(Student_Info Info);//添加学生信息
	bool Add_Repair_info(Repair_Info &Info);//添加报修信息
	bool Add_Stu_Account(Student_Login Login);//添加学生账户

	bool Delet_Stu_info(CString id);//删除学生信息
	bool Delet_Repair_info(CString id);//删除报修信息
	bool Delete_Stu_Account(CString id);//删除学生账户

	bool Update_Stu_info(Student_Info Info);//修改学生信息
	bool Update_Repair_info(CString situation, CString id);//修改报修状态
	bool Update_Stu_Login(CString id, CString password);//修改学生登录信息
	bool Update_Dorm_Login(CString id, CString password);//修改宿管员登录信息


	vector<Student_Login> Get_AllLogin_info();//查询全部学生登录信息
	vector<Dorm_Master> Get_AllMasterLogin_info();//查询全部宿管员登录信息

};

