#include <iostream>
#include <vector>
using namespace std;

class penerbit;
class buku;
class pengarang {
public:
	string nama;
	vector<penerbit*> daftar_penerbit;
	vector<buku*> daftar_buku;

	pengarang(string pNama) :nama(pNama) {
		cout << "Pengarang \"" << nama << "\"ada\n";
	}
	~pengarang() {
		cout << "Pengarang \"" << nama << "\"tidak ada\n";
	}
	void tambahPenerbit(penerbit*);
	void cetakPenerbit();
	void tambahBuku(buku*);
	void cetakBuku();
};

class penerbit {
public:
	string nama;
	vector<pengarang*> daftar_pengarang;

	penerbit(string pNama) :nama(pNama) {
		cout << "Penerbit \"" << nama << "\" ada\n";
	}
	~penerbit() {
		cout << "Penerbit \"" << nama << "\" tidak ada\n";
	}

	void tambahPengarang(pengarang*);
	void cetakPengarang();
};

class buku {
public:
	string nama;
	vector<pengarang*> daftar_pengarang;
	vector<penerbit*> daftar_penerbit;

	buku(string pNama) :nama(pNama) {
		cout << "Buku \"" << nama << "\" ada\n";
	}
	~buku() {
		cout << "Buku \"" << nama << "\" tidak ada\n";
	}

	void tambahPengarang(pengarang*);
	void cetakPengarang();
	void tambahPenerbit(penerbit*);
	void cetakPenerbit();
};

void pengarang::tambahPenerbit(penerbit* pPenerbit) {
	daftar_penerbit.push_back(pPenerbit);
}
void pengarang::cetakPenerbit() {
	cout << "Daftar penerbit yang diikuti \"" << this->nama << "\":\n";
	for (auto& a : daftar_penerbit) {
		cout << a->nama << "\n";
	}
	cout << endl;
}
void pengarang::tambahBuku(buku* pBuku) {
	daftar_buku.push_back(pBuku);
	pBuku->tambahPengarang(this);
}
void pengarang::cetakBuku() {
	cout << "Daftar buku yang dikarang\"" << this->nama << "\":\n";
	for (auto& a : daftar_buku) {
		cout << a->nama << "\n";
	}
	cout << endl;
}

void penerbit::tambahPengarang(pengarang* pPengarang) {
	daftar_pengarang.push_back(pPengarang);
	pPengarang->tambahPenerbit(this);
}
void penerbit::cetakPengarang() {
	cout << "Daftar pengarang pada penerbit \"" << this->nama << "\":\n";
	for (auto& a : daftar_pengarang) {
		cout << a->nama << "\n";
	}
	cout << endl;
}

void buku::tambahPengarang(pengarang* pPengarang) {
	daftar_pengarang.push_back(pPengarang);
}
void buku::cetakPengarang() {
	cout << "Daftar pengarang pada penerbit \"" << this->nama << "\":\n";
	for (auto& a : daftar_pengarang) {
		cout << a->nama << "\n";
	}
	cout << endl;
}
void buku::tambahPenerbit(penerbit* pPenerbit) {
	daftar_penerbit.push_back(pPenerbit);
}
void buku::cetakPenerbit() {
	cout << "Daftar penerbit yang diikuti \"" << this->nama << "\":\n";
	for (auto& a : daftar_penerbit) {
		cout << a->nama << "\n";
	}
	cout << endl;
}

int main() {

	pengarang* varPengarang = new pengarang("Joko");
	pengarang* varPengarang2 = new pengarang("Lia");
	pengarang* varPengarang3 = new pengarang("Giga");
	pengarang* varPengarang4 = new pengarang("Asroni");

	penerbit* varPenerbit = new penerbit("Gama Press");
	penerbit* varPenerbit2 = new penerbit("Intan Pariwara");

	buku* varBuku = new buku("Fisika");
	buku* varBuku2 = new buku("Algoritma");
	buku* varBuku3 = new buku("Basisdata");
	buku* varBuku4 = new buku("Dasar Pemrograman");
	buku* varBuku5 = new buku("Matematika");
	buku* varBuku6 = new buku("Multimedia 1");

	varPenerbit->tambahPengarang(varPengarang);
	varPenerbit->tambahPengarang(varPengarang2);
	varPenerbit->tambahPengarang(varPengarang3);

	varPenerbit2->tambahPengarang(varPengarang3);
	varPenerbit2->tambahPengarang(varPengarang4);

	varPengarang->tambahBuku(varBuku);
	varPengarang->tambahBuku(varBuku2);
	varPengarang2->tambahBuku(varBuku3);
	varPengarang3->tambahBuku(varBuku4);
	varPengarang4->tambahBuku(varBuku5);
	varPengarang4->tambahBuku(varBuku6);

	varPenerbit->cetakPengarang();
	varPenerbit2->cetakPengarang();

	varPengarang->cetakPenerbit();

	varPengarang->cetakBuku();
	varPengarang2->cetakBuku();
	varPengarang3->cetakBuku();
	varPengarang4->cetakBuku();

	delete varBuku;
	delete varBuku;
	delete varBuku;
	delete varBuku4;
	delete varBuku5;
	delete varBuku6;
	delete varPengarang;
	delete varPengarang2;
	delete varPengarang3;
	delete varPengarang4;
	delete varPenerbit;
	delete varPenerbit2;

	return 0;
}
