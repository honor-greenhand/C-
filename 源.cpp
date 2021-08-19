#include "标头.h"

//定义一个通讯录的结构体
struct People {
	string name;
	string sex;
	string phone_number ;
	string address;
}person[1000] = {};

extern int point = 0;

int main() {
	menu();
	while (1 ) {
		cout << "请选择服务： " << endl;
		cout <<"通讯录目前有 " <<point <<" 人"<< endl;
		int select;
		cin >> select;
		
		//进入面板
		if (select == 1) {
			cout << "1. 添加联系人：" << endl;
			q1addperson();
			
			menu();
			continue;
		}
		else if (select == 2) {
			cout << "2. 显示联系人：" << endl;

			q2display();
			menu();
			continue;
		}
		else if (select == 3) {
			cout << "3. 删除联系人：" << endl;
			q3delete;
			menu();
			continue;
		}
		else if (select == 4) {
			cout << "4. 查找联系人：" << endl;
			q4lookup;
			menu();
			continue;
		}
		else if (select == 5) {
			cout << "5. 修改联系人：" << endl;
			q5amend;
			menu();
			continue;
		}
		else if (select == 6) {
			cout << "6. 清空联系人：" << endl;
			q6clear;
			menu();
			continue;
		}
		else if (select == 0) {
			cout << "0. 退出通讯录：" << endl;
			cout << "退出通讯录！" << endl;
			break;
		}
	
	}

}


//目录的函数
void menu() {
	system("cls");
	cout << "1. 添加联系人：" << endl;
	cout << "2. 显示联系人：" << endl;
	cout << "3. 删除联系人：" << endl;
	cout << "4. 查找联系人：" << endl;
	cout << "5. 修改联系人：" << endl;
	cout << "6. 清空联系人：" << endl;
	cout << "0. 退出通讯录：" << endl;
	cout << "---------------------------：" << endl;
}
//1.添加联系人的函数
void q1addperson() {
	cout << "请输入联系人姓名：" << endl;
	cin >> (person + point)->name;
	cout << "请输入联系人性别：" << endl;
	cin >> (person + point)->sex;
	cout << "请输入联系人电话：" << endl;
	cin >> (person + point)->phone_number;
	cout << "请输入联系人地址：" << endl;
	cin >> (person + point)->address;
	point+=1;
}
//2. 显示联系人的函数
void q2display() {
	if (point == 0) {
		cout << "通讯录中没有任何信息！" << endl;
	}
	else {
		for (int i = 0; i < point; i++) {
			cout << "联系人姓名：" 
				<< (person + i)->name<<"\t"
				<< "性别：" 
				<< (person + i)->sex << "\t"
				<< "电话：" 
				<< (person + i)->phone_number << "\t"
				<< "地址：" 
				<< (person + i)->address << "\t" << endl;
		}
	}
	system("pause");
}
//3. 删除联系人
void q3delete() {
	string index;
	cin >> index;
	for (int i = 0; i < point; i++) {
		if ((person + i)->name == index) {
			for (int j = 0; j < point - i; j++) {
				*(person + j) = *(person + j + 1);
			}
		}
	}
	point--;
	system("pause");
}

//4. 查找联系人
void q4lookup() {
	string index;
	cin >> index;
	for (int i = 0; i < point; i++) {
		if ((person + i)->name == index) {
			cout << "联系人姓名："
				<< (person + i)->name << "\t"
				<< "性别："
				<< (person + i)->sex << "\t"
				<< "电话："
				<< (person + point)->phone_number << "\t"
				<< "地址："
				<< (person + point)->address << endl;
			system("pause");
		}
	}
}
//5. 修改联系人
void q5amend() {
	string index;
	cin >> index;
	for (int i = 0; i < point; i++) {
		if ((person + i)->name == index) {
			cout << "请输入联系人姓名：" << endl;
			cin >> (person + i)->name;
			cout << "请输入联系人性别：" << endl;
			cin >> (person + i)->sex;
			cout << "请输入联系人电话：" << endl;
			cin >> (person + i)->phone_number;
			cout << "请输入联系人地址：" << endl;
			cin >> (person + i)->address;

		}
	}
	cout << "更改成功！";
	system("pause");
}
//6. 清空联系人
void q6clear() {
	cout << "是否确认清空通讯录？  1:确定   0:取消";
	int biaoji;
	cin >> biaoji;
	if (biaoji == 1) {
		for (int i = 0; i < point; i++) {
			(person + i)->name = "";
			(person + i)->sex = "";
			(person + i)->phone_number = "";
			(person + point)->address = "";
		}
		point = 0;
	}
	cout << "删除成功！";
	system("pause");
}