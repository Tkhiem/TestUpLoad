#include<iostream>
#include<string>
using namespace std;
struct SinhVien {
	string name, id;
	double gpa;
};
istream& operator>>(istream& is, SinhVien& sv) {
	cout << "Nhap Thong Tin Sinhien: "<<endl;
	cout << "Nhap ID: ";
	is >> sv.id;
	is.ignore();
	cout << "\nNhap Name:";
	getline(is, sv.name);
	cout << "\nNhap GPA: ";
	is >> sv.gpa;
	return is;
}

ostream& operator<<(ostream& os, SinhVien sv) {
	os << "ID: " << sv.id << endl;
	os << "Name: " << sv.name << endl;
	os << "GPA: " << sv.gpa << endl;
	return os;
}
struct Node {
	SinhVien data;
	Node* next;
};

typedef struct Node* node;

node MakeNode(SinhVien sv) {
	node p = new Node;
	p->data = sv;
	p->next = NULL;
	return p;
}

void ThemVaoDau(node& head, SinhVien sv) {
	node p = MakeNode(sv);
	if (head == NULL) {
		head = p;
	}
	else {
		p->next = head;
		head = p;
	}
}

void ThemVaoCuoi(node& head, SinhVien sv) {
	node p = MakeNode(sv);
	if (head == NULL) {
		head = p;
	}
	else {
		node tmp = head;
		while (tmp->next != NULL) {
			tmp = tmp->next;
		}
		tmp->next = p;
	}
}
int size(node head) {
	int cnt = 0;
	while (head != NULL) {
		cnt++;
		head = head->next;
	}
	return cnt;
}
void ThemVaoGiua(node& head, SinhVien sv, int vitri) {
	int n = size(head);
	if (vitri <= 0 || vitri > n + 1) {
		return;
	}
	else if (vitri == 1) {
		ThemVaoDau(head,sv);
		return;
	}
	else if (vitri == n + 1) {
		ThemVaoCuoi(head,sv);
		return;
	}
	node p = MakeNode(sv);
	node tmp = head;
	for (int i = 1; i < vitri - 1; i++) {
		tmp = tmp->next;
	}
	p->next = tmp->next;
	tmp->next = p;
}
void XoaDau(node& head) {
	if (head == NULL) return;
	else {
		head = head->next;
	}
}

void XoaCuoi(node& head) {
	if (head == NULL) { return; }
	else {
		node truoc = NULL, sau = head;
		while (sau->next != NULL) {
			truoc = sau;
			sau = sau->next;
		}
		if (truoc == NULL) { head =head->next; }
		else { truoc->next = NULL; }
	}
}

void XoaGiua(node& head, int vitri) {
	int n = size(head);
	if (vitri <= 0 || vitri > n) return;
	else if (vitri == 1) XoaDau(head);
	else if (vitri == n) XoaCuoi(head);
	else {
		node truoc = NULL, sau = head;
		for (int i = 1; i < vitri; i++) {
			truoc = sau;
			sau = sau->next;
		}
		if (truoc == NULL) head = head->next;
		else {
			truoc->next = sau->next;
		}
	}
}

void XuatSV(SinhVien sv) {
	cout << "ID: " << sv.id << endl;
	cout << "Name: " << sv.name << endl;
	cout << "GPA: " << sv.gpa << endl;
}
void InDSSV(node head) {
	while (head != NULL) {
		XuatSV(head->data);
		head = head->next;
		cout << endl;
	}
}
int main() {
	node head = NULL;
	int n;
	cin >> n;
	for (int i = 0; i < n; i++) {
		SinhVien sv;
		cin >> sv;
		ThemVaoDau(head,sv);
	}
	InDSSV(head);

	return 0;
}