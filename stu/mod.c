#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <mysql/mysql.h>
#include "cgic.h"

char * headname = "head.html";
char * footname = "footer.html";

int cgiMain()
{
	FILE * fd;
	char ch;

	fprintf(cgiOut, "Content-type:text/html;charset=utf-8\n\n");
	if(!(fd = fopen(headname, "r"))){
		fprintf(cgiOut, "Cannot open file, %s\n", headname);
		return -1;
	}
	ch = fgetc(fd);

	while(ch != EOF){
		fprintf(cgiOut, "%c", ch);
		ch = fgetc(fd);
	}
	fclose(fd);


	//fprintf(cgiOut, "Content-type:text/html;charset=utf-8\n\n");

	char sname[32] = "\0";
	char sage[16] = "\0";
	char sno[32] = "\0";
	char ssex[2] = "\0";
	char sdept[20] = "\0";
	int status = 0;

	status = cgiFormString("sname",  sname, 32);
	if (status != cgiFormSuccess)
	{
		fprintf(cgiOut, "get sname error!\n");
		return 1;
	}

	status = cgiFormString("sage",  sage, 16);
	if (status != cgiFormSuccess)
	{
		fprintf(cgiOut, "get sage error!\n");
		return 1;
	}

	status = cgiFormString("sno",  sno, 32);
	if (status != cgiFormSuccess)
	{
		fprintf(cgiOut, "get sno error!\n");
		return 1;
	}
	status = cgiFormString("ssex",  ssex, 32);
	if (status != cgiFormSuccess)
	{
		fprintf(cgiOut, "get ssex error!\n");
		return 1;
	}
	status = cgiFormString("sdept",  sdept, 32);
	if (status != cgiFormSuccess)
	{
		fprintf(cgiOut, "get sdept error!\n");
		return 1;
	}

	//fprintf(cgiOut, "name = %s, age = %s, stuId = %s\n", name, age, stuId);
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


	sprintf(sql, "update information set sname='%s', sage= '%s',ssex='%s',sdept='%s' where sno = '%s' ", sname, sage, ssex,sdept,sno);
	if ((ret = mysql_real_query(db, sql, strlen(sql) + 1)) != 0)
	{
		fprintf(cgiOut,"mysql_real_query fail:%s\n", mysql_error(db));
		mysql_close(db);
		return -1;
	}



	fprintf(cgiOut, "update student ok!\n");
	mysql_close(db);
	return 0;
}
