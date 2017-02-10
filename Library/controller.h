#ifndef _CONTROLLER_H_
#define _CONTROLLER_H_
#include"BOOK.h"
#include"mysql.h"
#include"User.h"
#include<string>
using namespace std;

class controller {
private:
	string interpret(BookQuery & q) {
		if (q.book_id.empty() && q.name.empty() && q.author.empty() && q.publisher.empty() && q.publisher.empty() && (!q.begin_year)
			&& (!q.end_year) && (q.low_price < 0) && (q.high_price < 0) && (q.type.empty()))
		{
			if (q.have_stock)
				return "select * from book where stock > 0;";
			else return "select * from book;";
		}
		string query = "select * from book where ";

		if (!q.book_id.empty()) {
			query += " book_id= '" + q.book_id + "' and";
		}
		if (!q.name.empty()) {
			query += " name= '" + q.name + "' and";
		}
		if (!q.author.empty()) {
			query += " author_name = '" + q.author + "' and";
		}
		if (!q.publisher.empty()) {
			query += " publisher= '" + q.publisher + "' and";
		}
		if (q.begin_year) {
			char tem[10];
			sprintf(tem, "%d", q.begin_year);
			string tem1 = tem;
			query += " publish_year>= " + tem1 + " and";
		}
		if (q.end_year) {
			char tem[10];
			sprintf(tem, "%d", q.end_year);
			string tem1 = tem;
			query += " publish_year<= " + tem1 + " and";
		}
		if (q.low_price) {
			char tem[10];
			sprintf(tem, "%lf", q.low_price);
			string tem1 = tem;
			query += " price >= " + tem1 + " and";
		}
		if (q.high_price > 0 && q.high_price >= q.low_price) {
			char tem[10];
			sprintf(tem, "%lf", q.high_price);
			string tem1 = tem;
			query += " price <= " + tem1 + " and";
		}
		if (q.have_stock) {
			query += " stock > 0 and";
		}
		if (!q.type.empty()) {
			query += " type = '" + q.type + "' and";
		}
		query.erase(query.size() - 3, 3);
		query += ";";
		return query;
	}
	string interpret9(BookQuery & q) {
		if (q.book_id.empty() && q.name.empty() && q.author.empty() && q.publisher.empty() && q.publisher.empty() && (!q.begin_year)
			&& (!q.end_year) && (q.low_price < 0) && (q.high_price < 0) && (q.type.empty()))
		{
			return "";
		}
		string query = "select * from book where ";

		if (!q.book_id.empty()) {
			query += " book_id= '" + q.book_id + "' and";
		}
		if (!q.name.empty()) {
			query += " name= '" + q.name + "' and";
		}
		if (!q.author.empty()) {
			query += " author_name = '" + q.author + "' and";
		}
		if (!q.publisher.empty()) {
			query += " publisher= '" + q.publisher + "' and";
		}
		if (q.begin_year) {
			char tem[10];
			sprintf(tem, "%d", q.begin_year);
			string tem1 = tem;
			query += " publish_year>= " + tem1 + " and";
		}
		if (q.end_year) {
			char tem[10];
			sprintf(tem, "%d", q.end_year);
			string tem1 = tem;
			query += " publish_year<= " + tem1 + " and";
		}
		if (q.low_price >= 0) {
			char tem[10];
			sprintf(tem, "%lf", q.low_price);
			string tem1 = tem;
			query += " price >= " + tem1 + " and";
		}
		if (q.high_price > 0 && q.high_price >= q.low_price) {
			char tem[10];
			sprintf(tem, "%lf", q.high_price);
			string tem1 = tem;
			query += " price <= " + tem1 + " and";
		}
		if (q.have_stock) {
			query += " stock > 0 and";
		}
		if (q.type != " ") {
			query += " type = '" + q.type + "' and";
		}
		query.erase(query.size() - 3, 3);
		query += ";";
		return query;
	}
	int type;
public:
	void select(BookQuery & q, MYSQL& sql) {
		q.Catalog.clear();
		MYSQL_RES *res_ptr;
		MYSQL_ROW result_row;
		Book tem;
		int column, row;
		string query = interpret(q);
		if (query.size() > 0)
		{
			mysql_query(&sql, query.c_str());
			res_ptr = mysql_store_result(&sql);
			column = mysql_num_fields(res_ptr);
			row = mysql_num_rows(res_ptr) + 1;
			for (int i = 1; i < row; i++) {
				result_row = mysql_fetch_row(res_ptr);
				tem.book_id = result_row[0];
				tem.name = result_row[1];
				tem.author = result_row[2];
				tem.price = atof(result_row[3]);
				tem.num = atoi(result_row[4]);
				tem.stock = atoi(result_row[5]);
				tem.publisher = result_row[6];
				tem.publish_date = result_row[7];
				tem.type = result_row[8];
				q.Catalog.push_back(tem);
			}
		}
	}
	void select9(BookQuery & q, MYSQL& sql) {
		q.Catalog.clear();
		MYSQL_RES *res_ptr;
		MYSQL_ROW result_row;
		Book tem;
		int column, row;
		string query = interpret9(q);
		if (query != "select * from book whe;")
		{
			mysql_query(&sql, query.c_str());
			res_ptr = mysql_store_result(&sql);
			column = mysql_num_fields(res_ptr);
			row = mysql_num_rows(res_ptr) + 1;
			for (int i = 1; i < row; i++) {
				result_row = mysql_fetch_row(res_ptr);
				tem.book_id = result_row[0];
				tem.name = result_row[1];
				tem.author = result_row[2];
				tem.price = atof(result_row[3]);
				tem.num = atoi(result_row[4]);
				tem.stock = atoi(result_row[5]);
				tem.publisher = result_row[6];
				tem.publish_date = result_row[7];
				tem.type = result_row[8];
				q.Catalog.push_back(tem);
			}
		}
	}
	int insert(Book& q, MYSQL& sql) {
		MYSQL_RES *res_ptr;
		MYSQL_ROW result_row;
		string query = "select * from book where book_id ='" + q.book_id + "';";
		mysql_query(&sql, query.c_str());
		res_ptr = mysql_store_result(&sql);
		result_row = mysql_fetch_row(res_ptr);
		//row = mysql_num_rows(res_ptr);
		if (result_row == NULL) {
			query = "insert into book values('";
			char tem[10];
			sprintf(tem, "%lf", q.price);
			string tem1 = tem;
			query += q.book_id + "','" + q.name + "','" + q.author + "'," + tem1;
			sprintf(tem, "%d", q.num);
			tem1 = tem;
			query += "," + tem1 + ",";
			sprintf(tem, "%d", q.stock);
			tem1 = tem;
			query += tem1 + ",'" + q.publisher + "',";
			/*sprintf(tem, "%d", q.publish_date);
			tem1 = tem;*/
			query += q.publish_date + ",'" + q.type + "');";
			int x = mysql_query(&sql, query.c_str());
			return x;
		}
		else {
			string tem1, tem2;
			char tem[10];
			sprintf(tem, "%d", q.num);
			tem1 = tem;
			sprintf(tem, "%d", q.stock);
			tem2 = tem;
			query = "UPDATE book SET num = num+" + tem1 + " ,stock=stock+" + tem2 + " WHERE book_id = '" + q.book_id + "' ;";
			int x = mysql_query(&sql, query.c_str());
			return x;
		}
	}
	bool insertuser(User & _user, MYSQL &sql) {
		string query;
		query = "insert into user values('" + _user.id + "','" + _user.name + "','" + _user.password + "');";
		int r = mysql_query(&sql, query.c_str());
		return r == 0;
	}
	bool selectUser(User &_user, MYSQL &sql) {
		string query, query2;
		MYSQL_RES *res_ptr, *res_ptr1;
		MYSQL_ROW result_row, result_row1;
		int row;
		query = "select * from user where id='" + _user.id + "';";
		query2 = "select count(*) from borrow where user_id ='" + _user.id + "';";
		mysql_query(&sql, query.c_str());
		res_ptr = mysql_store_result(&sql);
		row = mysql_num_rows(res_ptr);
		mysql_query(&sql, query2.c_str());
		res_ptr1 = mysql_store_result(&sql);
		result_row1 = mysql_fetch_row(res_ptr1);
		_user.booknum = atoi(result_row1[0]);
		if (row == NULL) return 0;
		else {
			result_row = mysql_fetch_row(res_ptr);
			_user.name = result_row[1];
			_user.password = result_row[2];
			return 1;
		}
	}
	bool selectManager(Manager &_manager, MYSQL &sql) {
		string query;
		MYSQL_RES *res_ptr;
		MYSQL_ROW result_row;
		int row;
		query = "select * from manager where id='" + _manager.id + "';";
		mysql_query(&sql, query.c_str());
		res_ptr = mysql_store_result(&sql);
		row = mysql_num_rows(res_ptr);
		if (row == NULL) return 0;
		else {
			result_row = mysql_fetch_row(res_ptr);
			_manager.name = result_row[1];
			_manager.password = result_row[2];
			return 1;
		}
	}

	bool displayUser(UserQuery &q, MYSQL &sql) {
		string query, query2;
		MYSQL_RES *res_ptr, *res_ptr1;
		MYSQL_ROW result_row, result_row1;
		int row;
		query = "select * from user;";
		query2 = "select count(*) from borrow where user_id ='";
		int r = mysql_query(&sql, query.c_str());
		if (r != 0)return 0;
		else 
		{
			res_ptr = mysql_store_result(&sql);
			row = mysql_num_rows(res_ptr) + 1;
			User tem;
			for (int i = 1; i < row; i++) {
				result_row = mysql_fetch_row(res_ptr);
				tem.id = result_row[0];
				tem.name = result_row[1];
				tem.password = result_row[2];
				tem.priv = 1;
				query2 = "select count(*) from borrow where user_id ='";
				query2 += tem.id + "';";
				mysql_query(&sql, query2.c_str());
				res_ptr1 = mysql_store_result(&sql);
				result_row1 = mysql_fetch_row(res_ptr1);
				tem.booknum = atoi(result_row1[0]);
				q.Users.push_back(tem);//将查询信息压到vector中，主要查询信息为借书数量
			}
			return true;
		}
	}
	void displayborrow(string user_id, BookQuery &q, MYSQL& sql) {
		string query;
		MYSQL_RES *res_ptr, *res_ptr1;
		MYSQL_ROW result_row;
		q.Catalog.clear();
		query = "select * from user where id='" + user_id + "';";
		mysql_query(&sql, query.c_str());
		res_ptr = mysql_store_result(&sql);
		result_row = mysql_fetch_row(res_ptr);
		if (result_row == NULL) {
			q.Catalog.clear();
			return;
		}
		query = "select book_id from borrow where user_id='" + user_id + "'";
		mysql_query(&sql, query.c_str());
		res_ptr = mysql_store_result(&sql);
		int  row;
		row = mysql_num_rows(res_ptr);
		for (int i = 1; i < row + 1; i++) {
			result_row = mysql_fetch_row(res_ptr);
			string book_id = result_row[0];
			query = "select * from book where book_id='" + book_id + "'";
			mysql_query(&sql, query.c_str());
			res_ptr1 = mysql_store_result(&sql);
			result_row = mysql_fetch_row(res_ptr1);
			Book tem;
			tem.book_id = result_row[0];
			tem.name = result_row[1];
			tem.author = result_row[2];
			tem.price = atof(result_row[3]);
			tem.num = atoi(result_row[4]);
			tem.stock = atoi(result_row[5]);
			tem.publisher = result_row[6];
			tem.publish_date = result_row[7];
			tem.type = result_row[8];
			q.Catalog.push_back(tem);
		}
	}

	int borrowbook(string user_id, string book_id, MYSQL &sql) { //user manager
		MYSQL_RES *res_ptr;
		MYSQL_ROW result_row;
		int y;
		string query = "select * from book where book_id ='" + book_id + "';";
		y = mysql_query(&sql, query.c_str());
		res_ptr = mysql_store_result(&sql);
		result_row = mysql_fetch_row(res_ptr);
		if (result_row[5] == "0")
		{
			return 0;//没有库存
		}
		else
		{
			query = "update book set stock=stock-1 where book_id = '" + book_id + "';";
			y = mysql_query(&sql, query.c_str());
			if (y == 1) return 1;	//没有更新成功
			QDateTime current_date_time = QDateTime::currentDateTime();
			string borrow_date = (current_date_time.toString("yyyy-MM-dd  hh:mm:ss")).toStdString();
			string final_date = (current_date_time.addDays(30).toString("yyyy-MM-dd  hh:mm:ss")).toStdString();
			query = "insert into borrow values('" + user_id + "','" + book_id + "','" + 
				borrow_date.substr(0,10) + "','" + final_date.substr(0,10) + "');";
			y = mysql_query(&sql, query.c_str());
			if (y == 1) {
				query = "update book set stock=stock+1 where book_id = '" + book_id + "';";
				mysql_query(&sql, query.c_str());
				return 2;	//没有更新书的stock成功
			}
			else return 3;	//借阅成功
		}
	}
	int returnbook(string & user_id,string & book_id, MYSQL &sql) {  //user manager

		string query;

		query = "delete from borrow where user_id='" + user_id + "'and book_id = '" + book_id + "';";
		int y = mysql_query(&sql, query.c_str());
		if (y == 0)
		{
			query = "update book set stock=stock+1 where book_id = '" + book_id + "';";
			y = mysql_query(&sql, query.c_str());
			return y == 0;
		}
		else return y == 0;

	}
	bool deleteuser(User & _user, MYSQL &sql) {        //manager
		string query;
		query = "delete from user where id = '" + _user.id + "';";
		int r = mysql_query(&sql, query.c_str());
		return r == 0;
	}
	bool deletebook(string& book_id, MYSQL& sql) {            //manager
		MYSQL_RES *res_ptr;
		MYSQL_ROW result_row;
		int  y;
		string query = "select * from borrow where book_id ='" + book_id + "';";
		y = mysql_query(&sql, query.c_str());
		res_ptr = mysql_store_result(&sql);
		result_row = mysql_fetch_row(res_ptr);
		//row = mysql_num_rows(res_ptr);
		if (result_row == NULL) {
			query = "delete from book where book_id = '" + book_id + "';";
			int x = mysql_query(&sql, query.c_str());
			return x == 0;
		}
		else return false;
	}

	bool SelectBorrow(Borrow& q, MYSQL& sql) {
		string query;
		MYSQL_RES *res_ptr;
		MYSQL_ROW result_row;
		int row;
		query = "select borrow_date,return_date from borrow where user_id='" + q.user_id + "'and book_id='" + q.book_id + "';";
		mysql_query(&sql, query.c_str());
		res_ptr = mysql_store_result(&sql);
		row = mysql_num_rows(res_ptr);
		if (row == NULL) return 0;
		else {
			result_row = mysql_fetch_row(res_ptr);
			q.borrow_date = result_row[0];
			q.return_date = result_row[1];
			return 1;
		}
	}

	void AddFile(string& info, vector<Book>& book, MYSQL& sql)
	{
		Book temp;
		int n = 0, j = 0;
		string str = info;
		for (int i = 0; i < str.size(); i++)
		{
			if (str[i] != '\n'&& str[i] != ' ')
				n++;
			else if (str[i] == ' '){
				if (n == 0){
					i = -1;
					str.erase(n, n + 1);
					continue;
				}
				if (j == 0){
					temp.book_id = str.substr(0, n);
					str.erase(0, n + 1);
					i = -1;
				}
				else if (j == 1){
					temp.name = str.substr(0, n);
					str.erase(0, n + 1);
					i = -1;
				}
				else if (j == 2){
					temp.price = atof(str.substr(0, n).c_str());
					str.erase(0, n + 1);
					i = -1;
				}
				else if (j == 3){
					temp.num = atoi(str.substr(0, n).c_str());
					temp.stock = temp.num;
					str.erase(0, n + 1);
					i = -1;
				}
				else if (j == 4){
					temp.type = str.substr(0, n);
					str.erase(0, n + 1);
					i = -1;
				}
				else if (j == 5)
				{
					temp.publisher = str.substr(0, n);
					str.erase(0, n + 1);
					i = -1;
				}
				else if (j == 6){
					temp.publish_date = str.substr(0, n);
					str.erase(0, n + 1);
					i = -1;
				}
				else if (j == 7){
					temp.author = str.substr(0, n);
					str.erase(0, n + 1);
					i = -1;
					book.push_back(temp);
				}
				n = 0;
				j++;
				if (j>7) j = 0;
			}
			else{
				if (j == 7 && n != 0)  //\n只是分隔符
				{
					temp.author = str.substr(0, n);
					str.erase(0, n + 1);
					i = -1;
					n = 0;
					j = 0;
					book.push_back(temp);
				}
				else        //数量不够
				{
					if (j == 0 && n == 0){
						i = -1;
						str.erase(n, n + 1);

					}
					else{
						return ;
					}
				}
			}
		}
	}
};

#endif // !_controller_H_
