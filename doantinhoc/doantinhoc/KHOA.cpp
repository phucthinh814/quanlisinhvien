#include "Header.h"
void khoitao(danh_Sach_KH& dsk)
{
	dsk.phead = NULL;
	dsk.ptail = NULL;
}
void nhapKH(KH& k,danh_sach_KH&dsk)
{
	
	do {
		cout << "NHAP MA KHOA :";getline(cin, k.ma_khoa);
	} while (maKhoaKhongTrung(k.ma_khoa, dsk) == -1);
	
	
	cout << "NHAP TEN KHOA :";getline(cin, k.tenkhoa);


}
node_k* khoiTaoNode(KH x)//x luu data nguoi dung nhap vao
{
	node_k* p = new node_k;
	p->data = x;
	p->pnext = NULL;
	return p;
}
void giaiPhongKH(danh_Sach_KH& dsk)
{
	node_k* p = NULL;
	while (dsk.phead != NULL)
	{
		p = dsk.phead;
		dsk.phead = dsk.phead->pnext;
		delete p;
	}
}
void themKHOA(danh_sach_KH& dsk, KH x)
{
	node_k* p = khoiTaoNode(x);
	if (dsk.phead == NULL)//rong dau cuoi
	{
		dsk.phead = dsk.ptail = p;
	}
	else //n phan tu them cuoi 
	{
		dsk.ptail->pnext = p;
		dsk.ptail = p;
	}
}
void xuatKHOA(danh_sach_KH dsk)
{
    int i = 1;
    cout << setw(4) << left << "| STT |" << setw(20) << left << "| MAKHOA " << setw(40) << left << "| TEN KHOA " << setw(20) << left << "| SLSV |" << endl;
    cout << setfill('_') << setw(87) << "|" << setfill(' ') << endl;

    for (node_k* k = dsk.phead; k != NULL; k = k->pnext)
    {
        cout << "|" << setw(5) << left << i++ << "|"
             << setw(21) << left << k->data.ma_khoa
             << setw(41) << left << k->data.tenkhoa
             << setw(18) << left << k->data.soLuongSV << "|" << endl;
        cout << "|" << setfill('_') << setw(86) << "|" << setfill(' ') << endl;
    }
}
void load_fileKH(danh_Sach_KH& dsk) {
	ifstream filein("danhsachkhoa.txt");
	if (!filein.is_open()) {
		cout << "Khong the mo file.\n";
		return;
	}

	while (!filein.eof()) {
		KH a;
		getline(filein, a.ma_khoa, ',');
		getline(filein, a.tenkhoa);
		if (!a.ma_khoa.empty() && !a.tenkhoa.empty()) {
			themKHOA(dsk, a);
		}
	}

	filein.close();
}

void ghi_fileKH(danh_Sach_KH& dsk) {
	ofstream outfile("danhsachkhoa.txt");
	if (!outfile.is_open()) {
		cout << "Khong the mo file.\n";
		return;
	}

	for (node_k* k = dsk.phead; k != nullptr; k = k->pnext) {
		outfile << k->data.ma_khoa << ",";
		outfile << k->data.tenkhoa;
		outfile << endl;
	}

	outfile.close();
}
void xoaKhoa(danh_sach_KH& dsk, danh_sach_sv& dssv, const string& maKhoaCanXoa) {
	node_k* k = dsk.phead;
	node_k* p = nullptr;

	while (k != nullptr && _stricmp(k->data.ma_khoa.c_str(), maKhoaCanXoa.c_str())!=0) {
		p = k;
		k = k->pnext;
	}

	if (k == nullptr) {
		cout << "Khong tim thay khoa can xoa.\n";
		return;
	}

	// Kiểm tra số lượng sinh viên trong khoa
	int soLuongSVTrongKhoa = 0;
	node_sv* s = dssv.phead;
	while (s != nullptr) {
		if (_stricmp(s->data.ds_khoa.ma_khoa.c_str(),maKhoaCanXoa.c_str())==0) {
			soLuongSVTrongKhoa++;
		}
		s = s->pnext;
	}

	if (soLuongSVTrongKhoa > 1) {
		char luaChon;
		cout << "Khoa nay co " << soLuongSVTrongKhoa << " sinh vien. Ban co muon xoa khoa? (y/n): ";
		cin >> luaChon;
		cin.ignore(); // Xóa ký tự newline từ bộ đệm

		if (tolower(luaChon) != 'y') {
			cout << "Khoa khong bi xoa.\n";
			return;
		}
	}

	if (p == nullptr) {
		
		dsk.phead = k->pnext;
	}
	else {
		p->pnext = k->pnext;
	}

	delete k;
	cout << "Khoa da duoc xoa.\n";
}


void sapXepKH(danh_sach_KH& dsk)
{
	for (node_k* k = dsk.phead;k->pnext != NULL;k = k->pnext)//ap cuoi
	{
		for (node_k* h = k->pnext;h != NULL;h = h->pnext)//den cuoi
		{
			if (_stricmp(h->data.ma_khoa.c_str(), k->data.ma_khoa.c_str()) < 0)
			{
				swap(k->data, h->data);
			}
		}
	}
}
int timKiemKH(danh_sach_KH dsk, string vt)
{
	for (node_k* k = dsk.phead; k != NULL; k = k->pnext)
	{
		if (_stricmp(k->data.ma_khoa.c_str(), vt.c_str()) == 0)
		{
			cout << "MAKHOA: " << k->data.ma_khoa << endl;
			cout << "TENKHOA: " << k->data.tenkhoa << endl;
			return 1;
		}
	}
	cout << "Khong co khoa nay trong danh sach" << endl;
	return -1;
}
void updateThongTinKH(danh_sach_KH& dsk, string vt, KH a)
{
	for (node_k* k = dsk.phead; k != NULL; k = k->pnext)
	{
		if (_stricmp(k->data.ma_khoa.c_str(), vt.c_str()) == 0)
		{
			cout << "ban co muon sua TEN KHOA khong ? (y/n): ";
			char updateTenK;
			cin >> updateTenK;
			cin.ignore(); // Xóa b? nh? ??m c?a cin

			if (updateTenK == 'y' || updateTenK == 'Y')
			{
				cout << "SUA TEN: ";
				getline(cin, k->data.tenkhoa);
			}
			return;
		}
	}
	cout << "Khong co khoa nay trong danh sach" << endl;
}

int maKhoaKhongTrung(string ma_khoa, danh_sach_KH dsk) {
	node_k* p = dsk.phead;
	while (p != NULL) {
		if (_stricmp(p->data.ma_khoa.c_str(), ma_khoa.c_str()) == 0) {
			cout << "ma khoa da co trong danh sach vui long nhap lai"<<endl;
			return -1;
		}
		p = p->pnext;
	}
}
void nhapK(KH& k)
{
	
	cout << "NHAP MA KHOA :";getline(cin, k.ma_khoa);
	cout << "NHAP TEN KHOA :";getline(cin, k.tenkhoa);

}

void xuatsoluongsinhvientungkhoa( danh_sach_sv& dssv,  danh_sach_KH& dsk) {
	for (node_sv* p = dssv.phead; p != NULL; p = p->pnext) {
		string ma_khoa_sv = p->data.ds_khoa.ma_khoa;
		for (node_k* k = dsk.phead;k != NULL; k = k->pnext) {
			if (_stricmp(k->data.ma_khoa.c_str(), ma_khoa_sv.c_str())==0 )
			{
				k->data.soLuongSV++;
				break;  
			}
		}
	}
}