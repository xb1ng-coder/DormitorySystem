#include "pch.h"
#include "SQLinterface.h"

bool SQLinterface::ConnectMysql()
{
	mysql_init(&mysqlCon);
	//mysqlCon���ݿ�ṹlocalhost������ root �û��� ""����  ���ݿ� �˿�
	//�˴���ע�⣬ʹ�����Լ������ݿ���Ϣ
	if (!mysql_real_connect(&mysqlCon, "127.0.0.1", "*****", "*********", "dormitory_system", 3307, NULL, 0))
	{
		//AfxMessageBox(_T("�������ݿ�ʧ�ܣ������������ݿ����ã�"));
		return false;
	}
	else
	{
		//AfxMessageBox(_T("�������ݿ�ɹ���"));
		//�����ַ�����ʹ����֧������
		mysql_query(&mysqlCon, "SET NAMES 'GB2312'");//��������ݿ��ж�ȡ���ݺ���������ʾ������

	}
	return true;
}

vector<Student_Info> SQLinterface::Get_AllStu_info()
{
	vector<Student_Info> Info;
	
	//C��������ַ���

	snprintf(sql, SQL_MAX, "select* from student");
	//��ѯ����
	int ret = mysql_real_query(&mysqlCon, sql, (unsigned long)strlen(sql));
	//�жϲ�ѯ���

	if (ret) {
		AfxMessageBox(_T("����ѧ����Ϣʧ�ܣ�"));
		return Info;
	}
	//��ȡ�����

	res = mysql_store_result(&mysqlCon);
	//��ȡ��ѯ����һ������
	//��row��ֵ���ж�row�Ƿ�Ϊ�գ���Ϊ�վʹ�ӡ����
	while (row = mysql_fetch_row(res)) {
		Student_Info Stuinfo = Student_Info(row[0], row[1], row[2], row[3], row[4], row[5], row[6], row[7]);
		Info.push_back(Stuinfo);
	}
	// �ͷŽ����
	mysql_free_result(res);
	return Info;

}

vector<Student_Info> SQLinterface::Get_SameStuID_info(CString id)
{
	vector<Student_Info> Info;

	//C��������ַ���
	//snprintf(sql, SQL_MAX, "select* from student where studentID = %s ", id);
	//snprintf(sql, SQL_MAX, "SELECT * FROM student WHERE (dormBuilding, dormitoryNumber) IN "
	//	"(SELECT dormBuilding, dormitoryNumber FROM student WHERE studentID = '%s')", id, id);
	snprintf(sql, SQL_MAX, "SELECT * FROM student WHERE (dormBuilding, dormitoryNumber) IN "
		"(SELECT dormBuilding, dormitoryNumber FROM student WHERE studentID = '%s')", id);

	//��ѯ����
	int ret = mysql_real_query(&mysqlCon, sql, (unsigned long)strlen(sql));
	//�жϲ�ѯ���
	if (ret) {
		AfxMessageBox(_T("��ѯʧ�ܣ�"));
		return Info;
	}
	//��ȡ�����
	res = mysql_store_result(&mysqlCon);
	//��ȡ��ѯ����һ������
	//��row��ֵ���ж�row�Ƿ�Ϊ�գ���Ϊ�վʹ�ӡ����
	while (row = mysql_fetch_row(res)) {
		Student_Info Stuinfo = Student_Info(row[0], row[1], row[2], row[3], row[4], row[5], row[6], row[7]);
		Info.push_back(Stuinfo);
	}
	// �ͷŽ����
	mysql_free_result(res);
	return Info;
}

vector<Student_Info> SQLinterface::Search_StuID_info(CString id)
{
	vector<Student_Info> Info;
	snprintf(sql, SQL_MAX, "SELECT * FROM student WHERE studentID = '%s'", id);

	//��ѯ����
	int ret = mysql_real_query(&mysqlCon, sql, (unsigned long)strlen(sql));
	//�жϲ�ѯ���
	//if (ret) {
	//	AfxMessageBox(_T("��ѯʧ�ܣ�"));
	//	return Info;
	//}
	if (ret != 0) {
		const char* error_message = mysql_error(&mysqlCon);
		// ��������Ϣ��ʾ�������߽�����������
		AfxMessageBox(CString(error_message)); // ��C�ַ���ת��ΪMFC��CString���ͽ�����ʾ
		return Info;
	}
	//��ȡ�����
	res = mysql_store_result(&mysqlCon);
	//��ȡ��ѯ����һ������
	//��row��ֵ���ж�row�Ƿ�Ϊ�գ���Ϊ�վʹ�ӡ����
	while (row = mysql_fetch_row(res)) {
		Student_Info Stuinfo = Student_Info(row[0], row[1], row[2], row[3], row[4], row[5], row[6], row[7]);
		Info.push_back(Stuinfo);
	}
	// �ͷŽ����
	mysql_free_result(res);
	return Info;
}

vector<Repair_Info> SQLinterface::Get_AllRepair_info()
{
	vector<Repair_Info> Info;

	//C��������ַ���
	snprintf(sql, SQL_MAX, "select* from repair_report");
	//��ѯ����
	int ret = mysql_real_query(&mysqlCon, sql, (unsigned long)strlen(sql));
	//�жϲ�ѯ���
	if (ret) {
		AfxMessageBox(_T("���뱨����Ϣʧ�ܣ�"));
		return Info;
	}
	//��ȡ�����
	res = mysql_store_result(&mysqlCon);
	//��ȡ��ѯ����һ������
	//��row��ֵ���ж�row�Ƿ�Ϊ�գ���Ϊ�վʹ�ӡ����
	while (row = mysql_fetch_row(res)) {
		Repair_Info Rpainfo = Repair_Info(row[0], row[1], row[2], row[3], row[4], row[5]);
		Info.push_back(Rpainfo);
	}
	// �ͷŽ����
	mysql_free_result(res);
	return Info;
}

vector<Repair_Info> SQLinterface::Search_StuRepair_info(CString id)
{
	vector<Repair_Info> Info;

	//C��������ַ���
	snprintf(sql, SQL_MAX, "select* from repair_report where (dormBuilding,dormitoryNumber) in" 
		"(select dormbuilding ,dormitoryNumber from student where studentID = '%s')",id);
	//��ѯ����
	int ret = mysql_real_query(&mysqlCon, sql, (unsigned long)strlen(sql));
	//�жϲ�ѯ���
	if (ret) {
		AfxMessageBox(_T("���뱨����Ϣʧ�ܣ�"));
		return Info;
	}
	//��ȡ�����
	res = mysql_store_result(&mysqlCon);
	//��ȡ��ѯ����һ������
	//��row��ֵ���ж�row�Ƿ�Ϊ�գ���Ϊ�վʹ�ӡ����
	while (row = mysql_fetch_row(res)) {
		Repair_Info Rpainfo = Repair_Info(row[0], row[1], row[2], row[3], row[4], row[5]);
		Info.push_back(Rpainfo);
	}
	// �ͷŽ����
	mysql_free_result(res);
	return Info;
}

bool SQLinterface::Add_Stu_info(Student_Info Info)
{
	//int BufferLength=800;
	//char* nsql = (char*)VirtualAlloc(NULL, BufferLength, MEM_COMMIT | MEM_RESERVE, PAGE_READWRITE);
	//ִ�в������
	//C��������ַ���
	snprintf(sql, SQL_MAX, "insert into student values('%s','%s','%s','%s','%s','%s','%s','%s')",
		Info._studentID.c_str(), Info._name.c_str(), Info._sex.c_str(), Info._major.c_str(),
		Info._stuclass.c_str(), Info._dormitoryNumber.c_str(),Info._dormBuilding.c_str(), Info._phone.c_str());

	printf("Generated SQL: %s\n", sql);
	//��ѯ����
	int ret = mysql_real_query(&mysqlCon, sql, (unsigned long)strlen(sql));
	//�жϲ�ѯ���
	if (ret) {
		AfxMessageBox(_T("����ѧ����Ϣʧ�ܣ�"));
		return false;
	}

	return true;
}

bool SQLinterface::Add_Repair_info(Repair_Info &Info)
{

	////��ȡ���һ�еı������
	string _newrow;
	int newrow = 0;
	snprintf(sql, SQL_MAX, "SELECT repairNumber FROM repair_report ORDER BY repairNumber DESC LIMIT 1");

	int ret = mysql_real_query(&mysqlCon, sql, (unsigned long)strlen(sql));

	if (ret == 0) {
		MYSQL_RES* result = mysql_store_result(&mysqlCon);

		if (result != NULL) {
			MYSQL_ROW row = mysql_fetch_row(result);
			if (row != NULL) {
				// Convert the row[0] to integer
				newrow = std::stoi(row[0]) + 1;
				_newrow=std::to_string(newrow);
				Info.set_repairNumber(_newrow);
				//_newrow.Format(_T("%d"), newrow);//ʹ�ô������cstring��_newrow������intת��Ϊcstring��newrow
			}
			mysql_free_result(result);
		}
		else {
			newrow++;
			_newrow = std::to_string(newrow);
			 Info.set_repairNumber(_newrow);
			//_newrow.Format(_T("%d"), newrow);
		}
	}
	else {
		AfxMessageBox(_T("��ȡ������Ϣʧ�ܣ�"));
	}
	
	Info.set_situation("�ȴ�����");

	//ִ�в������
	//C��������ַ���
	snprintf(sql, SQL_MAX, "insert into repair_report values('%s','%s','%s','%s','%s','%s')", 
		Info._repairNumber.c_str(), Info._dormBuilding.c_str(), Info._dormitoryNumber.c_str(), Info._repair_time.c_str(),
		Info._question.c_str(), Info._situation.c_str());
	//��ѯ����
	ret = mysql_real_query(&mysqlCon, sql, (unsigned long)strlen(sql));
	//�жϲ�ѯ���
	if (ret) {
		AfxMessageBox(_T("���뱨����Ϣʧ�ܣ�"));
		return false;
	}

	return true;
}

bool SQLinterface::Add_Stu_Account(Student_Login Login)
{
	snprintf(sql, SQL_MAX, "insert into housemaster values('%s','%s')",
		Login._account.c_str(), Login._password.c_str());
	//��ѯ����
	int ret = mysql_real_query(&mysqlCon, sql, (unsigned long)strlen(sql));
	//�жϲ�ѯ���
	if (ret) {
		AfxMessageBox(_T("����ѧ����¼�˻�ʧ�ܣ�"));
		return false;
	}

	return true;
}

bool SQLinterface::Delet_Stu_info(CString id)
{

	snprintf(sql, SQL_MAX, "delete  FROM student WHERE studentID = '%s'", id);

	//��ѯ����
	int ret = mysql_real_query(&mysqlCon, sql, (unsigned long)strlen(sql));

	if (ret != 0) {
		const char* error_message = mysql_error(&mysqlCon);
		// ��������Ϣ��ʾ�������߽�����������
		AfxMessageBox(CString(error_message)); // ��C�ַ���ת��ΪMFC��CString���ͽ�����ʾ
		return false;
	}

	return true;
}

bool SQLinterface::Delet_Repair_info(CString id)
{
	////��ȡ���һ�еı������
	string _newrow;
	int newrow = 0;
	snprintf(sql, SQL_MAX, "SELECT repairNumber FROM repair_report ORDER BY repairNumber DESC LIMIT 1");

	int ret = mysql_real_query(&mysqlCon, sql, (unsigned long)strlen(sql));

	if (ret == 0) {
		MYSQL_RES* result = mysql_store_result(&mysqlCon);

		if (result != NULL) {
			MYSQL_ROW row = mysql_fetch_row(result);
			if (row != NULL) {
				// Convert the row[0] to integer
				newrow = std::stoi(row[0]) + 1;
				_newrow = std::to_string(newrow);
				if (newrow < atoi(id))
				{
					AfxMessageBox(_T("������ı�����Ų����ڣ�"));
					return false;
				}
				//_newrow.Format(_T("%d"), newrow);//ʹ�ô������cstring��_newrow������intת��Ϊcstring��newrow
			}
			mysql_free_result(result);
		}
	}
	else {
		AfxMessageBox(_T("��ȡ������Ϣʧ�ܣ�"));
	}

	snprintf(sql, SQL_MAX, "delete  FROM repair_report WHERE repairNumber = '%s'", id);

	//��ѯ����
	 ret = mysql_real_query(&mysqlCon, sql, (unsigned long)strlen(sql));

	if (ret != 0) {
		const char* error_message = mysql_error(&mysqlCon);
		// ��������Ϣ��ʾ�������߽�����������
		AfxMessageBox(CString(error_message)); // ��C�ַ���ת��ΪMFC��CString���ͽ�����ʾ
		return false;
	}

	return true;
}

bool SQLinterface::Delete_Stu_Account(CString id)
{
	snprintf(sql, SQL_MAX, "delete FROM housemaster where h_account = '%s'",id);
	//��ѯ����
	int ret = mysql_real_query(&mysqlCon, sql, (unsigned long)strlen(sql));
	//�жϲ�ѯ���
	if (ret) {
		AfxMessageBox(_T("ɾ��ѧ����¼�˻�ʧ�ܣ�"));
		return false;
	}

	return true;
}

bool SQLinterface::Update_Stu_info(Student_Info Info)
{
	snprintf(sql, SQL_MAX,
		"update student set name = '%s', sex = '%s', major = '%s', class = '%s', "
		"dormitoryNumber = '%s', dormBuilding = '%s', phone = '%s' where studentID = '%s'",
		Info._name.c_str(), Info._sex.c_str(), Info._major.c_str(),
		Info._stuclass.c_str(), Info._dormitoryNumber.c_str(),
		Info._dormBuilding.c_str(), Info._phone.c_str(), Info._studentID.c_str());


	//��ѯ����
	int ret = mysql_real_query(&mysqlCon, sql, (unsigned long)strlen(sql));

	if (ret != 0) {
		const char* error_message = mysql_error(&mysqlCon);
		// ��������Ϣ��ʾ�������߽�����������
		AfxMessageBox(CString(error_message)); // ��C�ַ���ת��ΪMFC��CString���ͽ�����ʾ
		return false;
	}

	return true;
}

bool SQLinterface::Update_Repair_info(CString situation,CString id)
{
	snprintf(sql, SQL_MAX, "update repair_report set situation = '%s' where repairNumber = '%s' ", id, situation);

	//��ѯ����
	int ret = mysql_real_query(&mysqlCon, sql, (unsigned long)strlen(sql));

	if (ret != 0) {
		const char* error_message = mysql_error(&mysqlCon);
		// ��������Ϣ��ʾ�������߽�����������
		AfxMessageBox(CString(error_message)); // ��C�ַ���ת��ΪMFC��CString���ͽ�����ʾ
		return false;
	}

	return true;
}

bool SQLinterface::Update_Stu_Login(CString id, CString password)
{
	snprintf(sql, SQL_MAX, "update housemaster set h_password = '%s' where h_account = '%s' ", password,id);

	//��ѯ����
	int ret = mysql_real_query(&mysqlCon, sql, (unsigned long)strlen(sql));

	if (ret != 0) {
		const char* error_message = mysql_error(&mysqlCon);
		// ��������Ϣ��ʾ�������߽�����������
		AfxMessageBox(CString(error_message)); // ��C�ַ���ת��ΪMFC��CString���ͽ�����ʾ
		return false;
	}

	return true;
}

bool SQLinterface::Update_Dorm_Login(CString id, CString password)
{
	snprintf(sql, SQL_MAX, "update dormitory_manager set d_password = '%s' where d_account = '%s' ", password, id);

	//��ѯ����
	int ret = mysql_real_query(&mysqlCon, sql, (unsigned long)strlen(sql));

	if (ret != 0) {
		const char* error_message = mysql_error(&mysqlCon);
		// ��������Ϣ��ʾ�������߽�����������
		AfxMessageBox(CString(error_message)); // ��C�ַ���ת��ΪMFC��CString���ͽ�����ʾ
		return false;
	}

	return true;
}

vector<Student_Login> SQLinterface::Get_AllLogin_info()
{

	vector<Student_Login> Info;

	//C��������ַ���
	snprintf(sql, SQL_MAX, "select* from housemaster");
	//��ѯ����
	int ret = mysql_real_query(&mysqlCon, sql, (unsigned long)strlen(sql));
	//�жϲ�ѯ���
	if (ret) {
		AfxMessageBox(_T("�����¼�˻�ʧ�ܣ�"));
		return Info;
	}
	//��ȡ�����
	res = mysql_store_result(&mysqlCon);
	//��ȡ��ѯ����һ������
	//��row��ֵ���ж�row�Ƿ�Ϊ�գ���Ϊ�վʹ�ӡ����
	while (row = mysql_fetch_row(res)) {
		Student_Login Loginfo = Student_Login(row[0], row[1]);
		Info.push_back(Loginfo);
	}
	// �ͷŽ����
	mysql_free_result(res);
	return Info;
}

vector<Dorm_Master> SQLinterface::Get_AllMasterLogin_info()
{
	vector<Dorm_Master> Info;

	//C��������ַ���
	snprintf(sql, SQL_MAX, "select* from dormitory_manager");
	//��ѯ����
	int ret = mysql_real_query(&mysqlCon, sql, (unsigned long)strlen(sql));
	//�жϲ�ѯ���
	if (ret) {
		AfxMessageBox(_T("�����¼�˻�ʧ�ܣ�"));
		return Info;
	}
	//��ȡ�����
	res = mysql_store_result(&mysqlCon);
	//��ȡ��ѯ����һ������
	//��row��ֵ���ж�row�Ƿ�Ϊ�գ���Ϊ�վʹ�ӡ����
	while (row = mysql_fetch_row(res)) {
		Dorm_Master Loginfo = Dorm_Master(row[0], row[1]);
		Info.push_back(Loginfo);
	}
	// �ͷŽ����
	mysql_free_result(res);
	return Info;
}
