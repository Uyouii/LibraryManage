#ifndef LIBRARY_H
#define LIBRARY_H
#include <QObject>
#include <QString>
#include <QWidget>
#include <QTabWidget>
#include <QVBoxLayout>
#include <QTabWidget>
#include <QTextEdit>
#include <QPalette>
#include <QDir>
#include <QBrush>
#include <QPixmap>
#include <QPushButton>
#include <QTreeWidget>
#include <QTreeWidgetItem>
#include <QStringList>
#include <QTextCodec>
#include <QTableWidget>
#include <QTableWidgetItem>
#include <QAbstractItemView>
#include <QGridLayout>
#include <QComboBox>
#include <QLabel>
#include <QLineEdit>
#include <QGroupBox>
#include <QCheckBox>
#include <QRadioButton>
#include <QDateTime>
#include <QTimer>
#include <QMessageBox>
#include <QFileDialog>
#include <QIODevice>
#include <QTextStream>
#include "mysql.h"
#include "controller.h"

#pragma comment(lib, "ws2_32.lib")
#pragma comment(lib, "libmysql.lib")


class Library : public QObject
{
    Q_OBJECT

public:
	Library(QObject* parent = 0);
	~Library();

/*
三种权限：
0 manager 可以查询借书还书，入库出库
1 user 可以查询，借书还书
2 visitor 可以查询
*/
private:
	enum { MANAGER, USER, VISITOR};
	QString userName;
	QString userID;
	QString userPassword;
	int user_type;//人员的类型: user, visitor, manager
	MYSQL sql;
	controller Control;


	QWidget *WholeWindow;
	QVBoxLayout* VlayoutWhole;
	QTabWidget* WholeTabwidget;	//下方的工作区

	QWidget *Title;
	QVBoxLayout* VLayoutTitle1;
	QHBoxLayout* HLayoutTitle1;
	QPushButton* Longon_in;
	QPushButton* Longon_out;
	QTimer* timer;
	QLabel* titlelabel;
	
	/*窗口1的控件*/
    QWidget *window1;	//查询窗口，图书搜索
	int numitem1 = 0;
	int numbook1 = 0;
	QTreeWidget* tree1;
	QTreeWidgetItem* root1;
	QTableWidgetItem** Tablecheckitem1;
	QHBoxLayout* HLayout11;
	QHBoxLayout* HLayout12;
	QVBoxLayout* VLayout12;
	QVBoxLayout* VLayout13;
	QVBoxLayout* VLayout14;
	QHBoxLayout* HLayout13;
	QTableWidget* Table1;
	QGridLayout* GLayout11;
	QLabel* label1;
	QLineEdit* bookname;
	QLineEdit* author;
	QLineEdit* publisher;
	QLineEdit* bookID;
	QLineEdit* price1;
	QLineEdit* price2;
	QComboBox* date1;
	QComboBox* date2;
	QPushButton* Searchbutton;
	QPushButton* Borrowbutton;
	QGroupBox* group11;
	QGroupBox* group12;
	QCheckBox* check1;

	/*窗口二中的控件*/
    QWidget *window2;	//用户借阅情况
	int num2 = 0;
	int numbook2 = 0;
	QVBoxLayout* VLayout21;
	QHBoxLayout* HLayout21;
	QTableWidget* Table2;
	QTableWidgetItem** Tablecheckitem2;	//勾选框
	QPushButton* ReturnButton;
	QPushButton* Button21;

	/*窗口三中的控件*/
	QWidget *window3;	//用户管理
	int num3 = 0;
	int numuser3 = 0;
	QTableWidget* Table3;
	QTableWidgetItem** Tablecheckitem3;	//勾选框
	QPushButton* DeleteButton2;	//删除用户信息
	QPushButton* DeleteButton1;	//删除用户权限
	QPushButton* Adduser;
	QPushButton* Search31;
	QVBoxLayout* VLayout31;
	QVBoxLayout* VLayout32;
	QVBoxLayout* VLayout33;
	QVBoxLayout* VLayout34;
	QHBoxLayout* HLayout31;
	QHBoxLayout* HLayout32;
	QHBoxLayout* HLayout33;
	QHBoxLayout* HLayout34;
	QHBoxLayout* HLayout35;
	QGroupBox* group31;
	QGroupBox* group32;
	QGridLayout* GLayout31;
	QLineEdit* Line31;

	/*窗口4中的控件*/
	QWidget* window4;	//用户详细信息
	int num4 = 0;
	int numbook4 = 0;
	QGroupBox* group41;
	QTableWidget* Table4;
	QLineEdit* line41;
	QLineEdit* line42;
	QLineEdit* line43;
	QLineEdit* line44;
	QLineEdit* line45;
	QVBoxLayout* VLayout41;
	QGridLayout* GLayout41;
	QHBoxLayout* HLayout41;
	QPushButton* DeleteButton4;

	/*窗口5中的控件*/
	QWidget* window5;	//添加新用户
	QLineEdit* line51;
	QLineEdit* line52;
	QLineEdit* line53;
	QRadioButton* RButton51;
	QRadioButton* RButton52;
	QVBoxLayout* VLayout51;
	QHBoxLayout* HLayout51;
	QHBoxLayout* HLayout52;
	QHBoxLayout* HLayout53;
	QHBoxLayout* HLayout54;
	QHBoxLayout* HLayout55;
	QPushButton* Adduser5;

	/*窗口6的控件*/
	QWidget *window6;	//书籍管理
	QTabWidget* TWidget6;
	QVBoxLayout* VLayout6;

	/*窗口7的控件*/
	QWidget* window7;	//单册入库
	QLineEdit* line71;
	QLineEdit* line72;
	QLineEdit* line73;
	QLineEdit* line74;
	QLineEdit* line75;
	QLineEdit* line76;
	QComboBox* date71;
	QComboBox* type7;
	QPushButton* Button71;
	QPushButton* Button72;
	QPushButton* Button73;
	QGridLayout* GLayout71;
	QVBoxLayout* VLayout71;
	QVBoxLayout* VLayout72;
	QHBoxLayout* HLayout71;
	QHBoxLayout* HLayout72;
	QGroupBox* group71;

	/*窗口8的控件*/
	QWidget* window8;	//多册入库
	int num8 = 0;
	int numitem8;
	QTableWidget* Table8;
	QComboBox** TableComItem81;	//日期
	QComboBox** TableComItem82;	//书籍分类
	QPushButton* Button81;
	QPushButton* Button82;
	QPushButton* Button83;
	QVBoxLayout* VLayout81;
	QHBoxLayout* HLayout81;
	QHBoxLayout* HLayout82;

	/*窗口9的控件*/
	QWidget* window9;	//删除书籍
	QLineEdit* line91;
	QLineEdit* line92;
	QLineEdit* line93;
	QLineEdit* line94;
	QLineEdit* line95;
	QLineEdit* line96;
	QComboBox* date91;
	QComboBox* date92;
	QComboBox* type9;
	QPushButton* Button91;
	QPushButton* Button92;
	//QPushButton* Button93;
	QGridLayout* GLayout91;
	QVBoxLayout* VLayout91;
	QVBoxLayout* VLayout92;
	QHBoxLayout* HLayout91;
	QHBoxLayout* HLayout92;
	QGroupBox* group91;
	
	/*窗口01的控件*/
	QWidget* window01;
	int num01 = 0;
	int numitem01;
	QTableWidget* Table01;
	QPushButton* Button011;
	QPushButton* Button012;
	QTableWidgetItem** Tablecheckitem01;	//勾选框
	QVBoxLayout* VLayout011;
	QHBoxLayout* HLayout011;

	/*窗口02的控件*/
	QWidget* window02;
	QGridLayout* GLayout02;
	QHBoxLayout* HLayout021;
	QVBoxLayout* VLayout021;
	QLineEdit* line021;
	QLineEdit* line022;
	QPushButton* Button021;

private:
    void LayoutWindow();
	void SetTitle();
	void SetMainWidget();
	/*设置不同的窗口格式*/
	void setwindow1();	//查询窗口，图书搜索
	void setwindow2();	//用户借阅情况
	void setwindow3();	//用户管理
	void setwindow6();	//书籍管理
	void setwindow7();	//单册入库
	void setwindow8();	//多册入库
	void setwindow9();	//删除书籍

	

private:
	bool Isselectall01();	//判断表格Table01中的勾选框是否被全选
	bool Isselectall2();	//判断表格Table2中的勾选框是否被全选
	void Island(bool);
	void Longon_inChangeWindow1();
	void Longon_outChangeWindow1();
	void ShowBook2(BookQuery&);
	void ShowUser3(UserQuery&);
	void ShowUser4(string);
	void Query9(BookQuery&);
	void ShowBook8(vector<Book>&);


private slots://信号槽
	void updatetime();
	void setwindow4();	//点开用户详细信息触发窗口
	void setwindow5();	//添加新用户触发窗口
	void setwindow01(); //查看要删除的书籍
	void setwindow02(); //用户登录
	void setbutton011();//全选表格Table01中的勾选框
	void setbutton21(); //全选表格Table2中的勾选框
	void setbutton72();	//清空输入的信息
	void setbutton83();	//清空输入的信息
	void setbutton92();	//清空输入信息
	void Query1();		//窗口1中的查询
	void QueryTree1(QTreeWidgetItem*, int);	//窗口1点击QTreeWidget
	void AddBook7();	//窗口7添加书籍
	void AddUser5();	//窗口5添加用户
	void Logon();		//登录
	void Logon_out();	//注销
	void Borrow_Book();	//借阅选中的书
	void Return_Book();	//归还选中的书
	void DeleteUser3();	//删除选中的用户
	void OpenFile();
	void DeleteBook01();
	void AddBook8();
};


#endif // LIBRARY_H
