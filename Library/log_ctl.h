#ifndef _LOG_CTL_H_
#define _LOG_CTL_H

/*使用说明：	MYSQL sql;
log_ctl log("localhost", "root", "310611", "library");
if (log.log(sql)){
printf("连接成功！");
}*/

#include<string>
#include<mysql.h>
using namespace std;

class log_ctl {
public:
	log_ctl(string host, string username, string password, string db) {
		this->host = host;
		this->username = username;
		this->password = password;
		this->db = db;
	}
	bool log(MYSQL& sql) {
		mysql_init(&sql);
		if (mysql_real_connect(&sql, host.c_str(), username.c_str(), password.c_str(),
			db.c_str(), 0, NULL, CLIENT_FOUND_ROWS)) {
			mysql_query(&sql, "set names 'GBK'");	//将mysql设置成为可以处理中文的模式
			string tem = db;
			string query = "use " + tem;
			mysql_query(&sql, query.c_str());
			return true;
		}
		else
			return false;
	}
private:
	string host;
	string username;
	string password;
	string db;
};


#endif // !_LOG_CTL_H_
