#include "��ͷ.h"

//����һ��ͨѶ¼�Ľṹ��
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
		cout << "��ѡ����� " << endl;
		cout <<"ͨѶ¼Ŀǰ�� " <<point <<" ��"<< endl;
		int select;
		cin >> select;
		
		//�������
		if (select == 1) {
			cout << "1. �����ϵ�ˣ�" << endl;
			q1addperson();
			
			menu();
			continue;
		}
		else if (select == 2) {
			cout << "2. ��ʾ��ϵ�ˣ�" << endl;

			q2display();
			menu();
			continue;
		}
		else if (select == 3) {
			cout << "3. ɾ����ϵ�ˣ�" << endl;
			q3delete;
			menu();
			continue;
		}
		else if (select == 4) {
			cout << "4. ������ϵ�ˣ�" << endl;
			q4lookup;
			menu();
			continue;
		}
		else if (select == 5) {
			cout << "5. �޸���ϵ�ˣ�" << endl;
			q5amend;
			menu();
			continue;
		}
		else if (select == 6) {
			cout << "6. �����ϵ�ˣ�" << endl;
			q6clear;
			menu();
			continue;
		}
		else if (select == 0) {
			cout << "0. �˳�ͨѶ¼��" << endl;
			cout << "�˳�ͨѶ¼��" << endl;
			break;
		}
	
	}

}


//Ŀ¼�ĺ���
void menu() {
	system("cls");
	cout << "1. �����ϵ�ˣ�" << endl;
	cout << "2. ��ʾ��ϵ�ˣ�" << endl;
	cout << "3. ɾ����ϵ�ˣ�" << endl;
	cout << "4. ������ϵ�ˣ�" << endl;
	cout << "5. �޸���ϵ�ˣ�" << endl;
	cout << "6. �����ϵ�ˣ�" << endl;
	cout << "0. �˳�ͨѶ¼��" << endl;
	cout << "---------------------------��" << endl;
}
//1.�����ϵ�˵ĺ���
void q1addperson() {
	cout << "��������ϵ��������" << endl;
	cin >> (person + point)->name;
	cout << "��������ϵ���Ա�" << endl;
	cin >> (person + point)->sex;
	cout << "��������ϵ�˵绰��" << endl;
	cin >> (person + point)->phone_number;
	cout << "��������ϵ�˵�ַ��" << endl;
	cin >> (person + point)->address;
	point+=1;
}
//2. ��ʾ��ϵ�˵ĺ���
void q2display() {
	if (point == 0) {
		cout << "ͨѶ¼��û���κ���Ϣ��" << endl;
	}
	else {
		for (int i = 0; i < point; i++) {
			cout << "��ϵ��������" 
				<< (person + i)->name<<"\t"
				<< "�Ա�" 
				<< (person + i)->sex << "\t"
				<< "�绰��" 
				<< (person + i)->phone_number << "\t"
				<< "��ַ��" 
				<< (person + i)->address << "\t" << endl;
		}
	}
	system("pause");
}
//3. ɾ����ϵ��
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

//4. ������ϵ��
void q4lookup() {
	string index;
	cin >> index;
	for (int i = 0; i < point; i++) {
		if ((person + i)->name == index) {
			cout << "��ϵ��������"
				<< (person + i)->name << "\t"
				<< "�Ա�"
				<< (person + i)->sex << "\t"
				<< "�绰��"
				<< (person + point)->phone_number << "\t"
				<< "��ַ��"
				<< (person + point)->address << endl;
			system("pause");
		}
	}
}
//5. �޸���ϵ��
void q5amend() {
	string index;
	cin >> index;
	for (int i = 0; i < point; i++) {
		if ((person + i)->name == index) {
			cout << "��������ϵ��������" << endl;
			cin >> (person + i)->name;
			cout << "��������ϵ���Ա�" << endl;
			cin >> (person + i)->sex;
			cout << "��������ϵ�˵绰��" << endl;
			cin >> (person + i)->phone_number;
			cout << "��������ϵ�˵�ַ��" << endl;
			cin >> (person + i)->address;

		}
	}
	cout << "���ĳɹ���";
	system("pause");
}
//6. �����ϵ��
void q6clear() {
	cout << "�Ƿ�ȷ�����ͨѶ¼��  1:ȷ��   0:ȡ��";
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
	cout << "ɾ���ɹ���";
	system("pause");
}