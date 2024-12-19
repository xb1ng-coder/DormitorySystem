#pragma once

#include "Student_Info.h"
#include "Repair_Info.h"
#include "Student_Login.h"
#include "Dorm_Master.h"
#include <string>

#define SQL_MAX 256 //sql����ַ��������ֵ
class SQLinterface
{
public:
	MYSQL_RES* res;//result
	MYSQL_ROW row;//���д洢
	MYSQL mysqlCon;
	char sql[SQL_MAX];//���ڴ洢SQL���

	bool ConnectMysql();//�������ݿ�
	vector<Student_Info> Get_AllStu_info();//��ѯȫ��ѧ����Ϣ
	vector<Student_Info> Get_SameStuID_info(CString id);//����ID��ѯ���������Ϣ
	vector<Student_Info> Search_StuID_info(CString id);//����ID��ѯѧ��

	vector<Repair_Info> Get_AllRepair_info();//��ѯȫ��������Ϣ
	vector<Repair_Info> Search_StuRepair_info(CString id);//����ID��ѯ������Ϣ

	bool Add_Stu_info(Student_Info Info);//���ѧ����Ϣ
	bool Add_Repair_info(Repair_Info &Info);//��ӱ�����Ϣ
	bool Add_Stu_Account(Student_Login Login);//���ѧ���˻�

	bool Delet_Stu_info(CString id);//ɾ��ѧ����Ϣ
	bool Delet_Repair_info(CString id);//ɾ��������Ϣ
	bool Delete_Stu_Account(CString id);//ɾ��ѧ���˻�

	bool Update_Stu_info(Student_Info Info);//�޸�ѧ����Ϣ
	bool Update_Repair_info(CString situation, CString id);//�޸ı���״̬
	bool Update_Stu_Login(CString id, CString password);//�޸�ѧ����¼��Ϣ
	bool Update_Dorm_Login(CString id, CString password);//�޸��޹�Ա��¼��Ϣ


	vector<Student_Login> Get_AllLogin_info();//��ѯȫ��ѧ����¼��Ϣ
	vector<Dorm_Master> Get_AllMasterLogin_info();//��ѯȫ���޹�Ա��¼��Ϣ

};

