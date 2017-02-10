#ifndef _BOOK_H_
#define _BOOK_H_

#include<string>
#include<vector>

class Book {
public:
	std::string book_id;
	std::string name;
	std::string author;
	double price;
	int num;	//书的总量
	int stock;
	std::string publisher;
	std::string publish_date;
	std::string type;
};


class BookQuery {
public:
	std::string book_id;
	std::string name;
	std::string author;
	std::string type;
	int begin_year;
	int end_year;
	std::string publisher;
	double low_price;
	double high_price;
	bool have_stock;
	std::vector<Book> Catalog;
};

class Borrow {
public:
	std::string book_id;
	std::string user_id;
	std::string borrow_date;
	std::string return_date;
};

#endif // !_BOOK_H_
