#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <mysql/mysql.h>
#include "cgic.h"

int cgiMain()
{

	fprintf(cgiOut, "Content-type:text/html;charset=utf-8\n\n");

	char cno[9] = "\0";
	char cname[40] = "\0";
	char major[20] = "\0";
	char school[20] = "\0";
	char grade[2] = "\0";
	int status = 0;

	status = cgiFormString("cname", cname, 40);
	if (status != cgiFormSuccess)
	{
		fprintf(cgiOut, "get cname error!\n");
		return 1;
	}

	status = cgiFormString("cno",  cno, 9);
	if (status != cgiFormSuccess)
	{
		fprintf(cgiOut, "get cno error!\n");
		return 1;
	}
	status = cgiFormString("major", major, 20);
	if (status != cgiFormSuccess)
	{
		fprintf(cgiOut, "get major error!\n");
		return 1;
	}
	status = cgiFormString("grade", grade, 20);
	if (status != cgiFormSuccess)
	{
		fprintf(cgiOut, "get grade error!\n");
		return 1;
	}
	status = cgiFormString("school", school, 20);
	if (status != cgiFormSuccess)
	{
		fprintf(cgiOut, "get school error!\n");
		return 1;
	}

	//fprintf(cgiOut, "ssex = %s, sname = %s, sdept = %s, sage = %s, sno = %s\n", ssex,sname, sdept, sage, sno);

	int ret;
	char sql[128] = "\0";
	MYSQL *db;

	//初始化
	db = mysql_init(NULL);
	if (db == NULL)
	{
		fprintf(cgiOut,"mysql_init fail:%s\n", mysql_error(db));
		return -1;
	}

	//连接数据库
	db = mysql_real_connect(db, "127.0.0.1", "root", "123456", "stu",  3306, NULL, 0);
	if (db == NULL)
	{
		fprintf(cgiOut,"mysql_real_connect fail:%s\n", mysql_error(db));
		mysql_close(db);
		return -1;
	}



	strcpy(sql, "create table school(cno char(9) not null peimary key,cname char(40) not null,grage char(2),major char(20) not null,school char(20) not null");
	if ((ret = mysql_real_query(db, sql, strlen(sql) + 1)) != 0)
	{
		if (ret != 1)
		{
			fprintf(cgiOut,"mysql_real_query fail:%s\n", mysql_error(db));
			mysql_close(db);
			return -1;
		}
	}



	sprintf(sql, "insert into school values('%s', '%s','%s','%s','%s')", cno,cname,grade,major,school);

	if (mysql_real_query(db, sql, strlen(sql) + 1) != 0)
	{
		fprintf(cgiOut, "%s\n", mysql_error(db));
		mysql_close(db);
		return -1;
	}

	fprintf(cgiOut, "add 课程 ok!\n");
	mysql_close(db);
	return 0;
}
