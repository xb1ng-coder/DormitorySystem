#include "pch.h"
#include "SQLinterface.h"

bool SQLinterface::ConnectMysql()
{
	mysql_init(&mysqlCon);
	//mysqlCon数据库结构localhost主机名 root 用户名 ""密码  数据库 端口
	//此处请注意，使用您自己的数据库信息
	if (!mysql_real_connect(&mysqlCon, "127.0.0.1", "*****", "*********", "dormitory_system", 3307, NULL, 0))
	{
		//AfxMessageBox(_T("访问数据库失败！请检查您的数据库配置！"));
		return false;
	}
	else
	{
		//AfxMessageBox(_T("访问数据库成功！"));
		//设置字符集，使程序支持中文
		mysql_query(&mysqlCon, "SET NAMES 'GB2312'");//解决从数据库中读取数据后汉字乱码显示的问题

	}
	return true;
}

vector<Student_Info> SQLinterface::Get_AllStu_info()
{
	vector<Student_Info> Info;
	
	//C语言组合字符串

	snprintf(sql, SQL_MAX, "select* from student");
	//查询数据
	int ret = mysql_real_query(&mysqlCon, sql, (unsigned long)strlen(sql));
	//判断查询结果

	if (ret) {
		AfxMessageBox(_T("载入学生信息失败！"));
		return Info;
	}
	//获取结果集

	res = mysql_store_result(&mysqlCon);
	//获取查询到的一行数据
	//给row赋值，判断row是否为空，不为空就打印数据
	while (row = mysql_fetch_row(res)) {
		Student_Info Stuinfo = Student_Info(row[0], row[1], row[2], row[3], row[4], row[5], row[6], row[7]);
		Info.push_back(Stuinfo);
	}
	// 释放结果集
	mysql_free_result(res);
	return Info;

}

vector<Student_Info> SQLinterface::Get_SameStuID_info(CString id)
{
	vector<Student_Info> Info;

	//C语言组合字符串
	//snprintf(sql, SQL_MAX, "select* from student where studentID = %s ", id);
	//snprintf(sql, SQL_MAX, "SELECT * FROM student WHERE (dormBuilding, dormitoryNumber) IN "
	//	"(SELECT dormBuilding, dormitoryNumber FROM student WHERE studentID = '%s')", id, id);
	snprintf(sql, SQL_MAX, "SELECT * FROM student WHERE (dormBuilding, dormitoryNumber) IN "
		"(SELECT dormBuilding, dormitoryNumber FROM student WHERE studentID = '%s')", id);

	//查询数据
	int ret = mysql_real_query(&mysqlCon, sql, (unsigned long)strlen(sql));
	//判断查询结果
	if (ret) {
		AfxMessageBox(_T("查询失败！"));
		return Info;
	}
	//获取结果集
	res = mysql_store_result(&mysqlCon);
	//获取查询到的一行数据
	//给row赋值，判断row是否为空，不为空就打印数据
	while (row = mysql_fetch_row(res)) {
		Student_Info Stuinfo = Student_Info(row[0], row[1], row[2], row[3], row[4], row[5], row[6], row[7]);
		Info.push_back(Stuinfo);
	}
	// 释放结果集
	mysql_free_result(res);
	return Info;
}

vector<Student_Info> SQLinterface::Search_StuID_info(CString id)
{
	vector<Student_Info> Info;
	snprintf(sql, SQL_MAX, "SELECT * FROM student WHERE studentID = '%s'", id);

	//查询数据
	int ret = mysql_real_query(&mysqlCon, sql, (unsigned long)strlen(sql));
	//判断查询结果
	//if (ret) {
	//	AfxMessageBox(_T("查询失败！"));
	//	return Info;
	//}
	if (ret != 0) {
		const char* error_message = mysql_error(&mysqlCon);
		// 将错误信息显示出来或者进行其他处理
		AfxMessageBox(CString(error_message)); // 将C字符串转换为MFC的CString类型进行显示
		return Info;
	}
	//获取结果集
	res = mysql_store_result(&mysqlCon);
	//获取查询到的一行数据
	//给row赋值，判断row是否为空，不为空就打印数据
	while (row = mysql_fetch_row(res)) {
		Student_Info Stuinfo = Student_Info(row[0], row[1], row[2], row[3], row[4], row[5], row[6], row[7]);
		Info.push_back(Stuinfo);
	}
	// 释放结果集
	mysql_free_result(res);
	return Info;
}

vector<Repair_Info> SQLinterface::Get_AllRepair_info()
{
	vector<Repair_Info> Info;

	//C语言组合字符串
	snprintf(sql, SQL_MAX, "select* from repair_report");
	//查询数据
	int ret = mysql_real_query(&mysqlCon, sql, (unsigned long)strlen(sql));
	//判断查询结果
	if (ret) {
		AfxMessageBox(_T("载入报修信息失败！"));
		return Info;
	}
	//获取结果集
	res = mysql_store_result(&mysqlCon);
	//获取查询到的一行数据
	//给row赋值，判断row是否为空，不为空就打印数据
	while (row = mysql_fetch_row(res)) {
		Repair_Info Rpainfo = Repair_Info(row[0], row[1], row[2], row[3], row[4], row[5]);
		Info.push_back(Rpainfo);
	}
	// 释放结果集
	mysql_free_result(res);
	return Info;
}

vector<Repair_Info> SQLinterface::Search_StuRepair_info(CString id)
{
	vector<Repair_Info> Info;

	//C语言组合字符串
	snprintf(sql, SQL_MAX, "select* from repair_report where (dormBuilding,dormitoryNumber) in" 
		"(select dormbuilding ,dormitoryNumber from student where studentID = '%s')",id);
	//查询数据
	int ret = mysql_real_query(&mysqlCon, sql, (unsigned long)strlen(sql));
	//判断查询结果
	if (ret) {
		AfxMessageBox(_T("载入报修信息失败！"));
		return Info;
	}
	//获取结果集
	res = mysql_store_result(&mysqlCon);
	//获取查询到的一行数据
	//给row赋值，判断row是否为空，不为空就打印数据
	while (row = mysql_fetch_row(res)) {
		Repair_Info Rpainfo = Repair_Info(row[0], row[1], row[2], row[3], row[4], row[5]);
		Info.push_back(Rpainfo);
	}
	// 释放结果集
	mysql_free_result(res);
	return Info;
}

bool SQLinterface::Add_Stu_info(Student_Info Info)
{
	//int BufferLength=800;
	//char* nsql = (char*)VirtualAlloc(NULL, BufferLength, MEM_COMMIT | MEM_RESERVE, PAGE_READWRITE);
	//执行插入操作
	//C语言组合字符串
	snprintf(sql, SQL_MAX, "insert into student values('%s','%s','%s','%s','%s','%s','%s','%s')",
		Info._studentID.c_str(), Info._name.c_str(), Info._sex.c_str(), Info._major.c_str(),
		Info._stuclass.c_str(), Info._dormitoryNumber.c_str(),Info._dormBuilding.c_str(), Info._phone.c_str());

	printf("Generated SQL: %s\n", sql);
	//查询数据
	int ret = mysql_real_query(&mysqlCon, sql, (unsigned long)strlen(sql));
	//判断查询结果
	if (ret) {
		AfxMessageBox(_T("插入学生信息失败！"));
		return false;
	}

	return true;
}

bool SQLinterface::Add_Repair_info(Repair_Info &Info)
{

	////获取最后一行的报修序号
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
				//_newrow.Format(_T("%d"), newrow);//使用此语句是cstring型_newrow接受由int转换为cstring的newrow
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
		AfxMessageBox(_T("获取报修信息失败！"));
	}
	
	Info.set_situation("等待处理");

	//执行插入操作
	//C语言组合字符串
	snprintf(sql, SQL_MAX, "insert into repair_report values('%s','%s','%s','%s','%s','%s')", 
		Info._repairNumber.c_str(), Info._dormBuilding.c_str(), Info._dormitoryNumber.c_str(), Info._repair_time.c_str(),
		Info._question.c_str(), Info._situation.c_str());
	//查询数据
	ret = mysql_real_query(&mysqlCon, sql, (unsigned long)strlen(sql));
	//判断查询结果
	if (ret) {
		AfxMessageBox(_T("插入报修信息失败！"));
		return false;
	}

	return true;
}

bool SQLinterface::Add_Stu_Account(Student_Login Login)
{
	snprintf(sql, SQL_MAX, "insert into housemaster values('%s','%s')",
		Login._account.c_str(), Login._password.c_str());
	//查询数据
	int ret = mysql_real_query(&mysqlCon, sql, (unsigned long)strlen(sql));
	//判断查询结果
	if (ret) {
		AfxMessageBox(_T("插入学生登录账户失败！"));
		return false;
	}

	return true;
}

bool SQLinterface::Delet_Stu_info(CString id)
{

	snprintf(sql, SQL_MAX, "delete  FROM student WHERE studentID = '%s'", id);

	//查询数据
	int ret = mysql_real_query(&mysqlCon, sql, (unsigned long)strlen(sql));

	if (ret != 0) {
		const char* error_message = mysql_error(&mysqlCon);
		// 将错误信息显示出来或者进行其他处理
		AfxMessageBox(CString(error_message)); // 将C字符串转换为MFC的CString类型进行显示
		return false;
	}

	return true;
}

bool SQLinterface::Delet_Repair_info(CString id)
{
	////获取最后一行的报修序号
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
					AfxMessageBox(_T("您输入的报修序号不存在！"));
					return false;
				}
				//_newrow.Format(_T("%d"), newrow);//使用此语句是cstring型_newrow接受由int转换为cstring的newrow
			}
			mysql_free_result(result);
		}
	}
	else {
		AfxMessageBox(_T("获取报修信息失败！"));
	}

	snprintf(sql, SQL_MAX, "delete  FROM repair_report WHERE repairNumber = '%s'", id);

	//查询数据
	 ret = mysql_real_query(&mysqlCon, sql, (unsigned long)strlen(sql));

	if (ret != 0) {
		const char* error_message = mysql_error(&mysqlCon);
		// 将错误信息显示出来或者进行其他处理
		AfxMessageBox(CString(error_message)); // 将C字符串转换为MFC的CString类型进行显示
		return false;
	}

	return true;
}

bool SQLinterface::Delete_Stu_Account(CString id)
{
	snprintf(sql, SQL_MAX, "delete FROM housemaster where h_account = '%s'",id);
	//查询数据
	int ret = mysql_real_query(&mysqlCon, sql, (unsigned long)strlen(sql));
	//判断查询结果
	if (ret) {
		AfxMessageBox(_T("删除学生登录账户失败！"));
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


	//查询数据
	int ret = mysql_real_query(&mysqlCon, sql, (unsigned long)strlen(sql));

	if (ret != 0) {
		const char* error_message = mysql_error(&mysqlCon);
		// 将错误信息显示出来或者进行其他处理
		AfxMessageBox(CString(error_message)); // 将C字符串转换为MFC的CString类型进行显示
		return false;
	}

	return true;
}

bool SQLinterface::Update_Repair_info(CString situation,CString id)
{
	snprintf(sql, SQL_MAX, "update repair_report set situation = '%s' where repairNumber = '%s' ", id, situation);

	//查询数据
	int ret = mysql_real_query(&mysqlCon, sql, (unsigned long)strlen(sql));

	if (ret != 0) {
		const char* error_message = mysql_error(&mysqlCon);
		// 将错误信息显示出来或者进行其他处理
		AfxMessageBox(CString(error_message)); // 将C字符串转换为MFC的CString类型进行显示
		return false;
	}

	return true;
}

bool SQLinterface::Update_Stu_Login(CString id, CString password)
{
	snprintf(sql, SQL_MAX, "update housemaster set h_password = '%s' where h_account = '%s' ", password,id);

	//查询数据
	int ret = mysql_real_query(&mysqlCon, sql, (unsigned long)strlen(sql));

	if (ret != 0) {
		const char* error_message = mysql_error(&mysqlCon);
		// 将错误信息显示出来或者进行其他处理
		AfxMessageBox(CString(error_message)); // 将C字符串转换为MFC的CString类型进行显示
		return false;
	}

	return true;
}

bool SQLinterface::Update_Dorm_Login(CString id, CString password)
{
	snprintf(sql, SQL_MAX, "update dormitory_manager set d_password = '%s' where d_account = '%s' ", password, id);

	//查询数据
	int ret = mysql_real_query(&mysqlCon, sql, (unsigned long)strlen(sql));

	if (ret != 0) {
		const char* error_message = mysql_error(&mysqlCon);
		// 将错误信息显示出来或者进行其他处理
		AfxMessageBox(CString(error_message)); // 将C字符串转换为MFC的CString类型进行显示
		return false;
	}

	return true;
}

vector<Student_Login> SQLinterface::Get_AllLogin_info()
{

	vector<Student_Login> Info;

	//C语言组合字符串
	snprintf(sql, SQL_MAX, "select* from housemaster");
	//查询数据
	int ret = mysql_real_query(&mysqlCon, sql, (unsigned long)strlen(sql));
	//判断查询结果
	if (ret) {
		AfxMessageBox(_T("载入登录账户失败！"));
		return Info;
	}
	//获取结果集
	res = mysql_store_result(&mysqlCon);
	//获取查询到的一行数据
	//给row赋值，判断row是否为空，不为空就打印数据
	while (row = mysql_fetch_row(res)) {
		Student_Login Loginfo = Student_Login(row[0], row[1]);
		Info.push_back(Loginfo);
	}
	// 释放结果集
	mysql_free_result(res);
	return Info;
}

vector<Dorm_Master> SQLinterface::Get_AllMasterLogin_info()
{
	vector<Dorm_Master> Info;

	//C语言组合字符串
	snprintf(sql, SQL_MAX, "select* from dormitory_manager");
	//查询数据
	int ret = mysql_real_query(&mysqlCon, sql, (unsigned long)strlen(sql));
	//判断查询结果
	if (ret) {
		AfxMessageBox(_T("载入登录账户失败！"));
		return Info;
	}
	//获取结果集
	res = mysql_store_result(&mysqlCon);
	//获取查询到的一行数据
	//给row赋值，判断row是否为空，不为空就打印数据
	while (row = mysql_fetch_row(res)) {
		Dorm_Master Loginfo = Dorm_Master(row[0], row[1]);
		Info.push_back(Loginfo);
	}
	// 释放结果集
	mysql_free_result(res);
	return Info;
}
