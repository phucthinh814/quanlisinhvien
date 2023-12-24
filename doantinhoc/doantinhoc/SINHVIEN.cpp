#include "Header.h"
void khoitao(danh_Sach_SV&dssv)
{
	dssv.phead = NULL;
	dssv.ptail = NULL;
}
void giaiPhong(danh_Sach_SV& dssv)
{
	node_sv* p = NULL;
	while (dssv.phead != NULL)
	{
		p = dssv.phead;
		dssv.phead = dssv.phead->pnext;
		delete p;
	}
}
void nhapSV(SV& a, danh_Sach_KH& dsk, danh_Sach_SV& dssv) 
{
	
	do {
		cout << "Nhap ma khoa:"; getline(cin, a.ds_khoa.ma_khoa);
	} while (!xuatTenKhoa(a.ds_khoa.ma_khoa, dsk));
	cout << endl;

	do {
		cout << "NHAP MSSV: "; getline(cin, a.ma_sv);
	} while (kiemTraMaSVTrung(a.ma_sv, dssv));

	cout << "NHAP HO ( TEN LOT ): "; getline(cin, a.ho);
	cout << "NHAP TEN :"; getline(cin, a.ten);

	// Nhập và chuyển đổi giới tính
	int gioiTinhInput;
	do {
		cout << "NHAP GIOI TINH (0: Nam, 1: Nu): "; cin >> gioiTinhInput;
		cin.ignore(numeric_limits<streamsize>::max(), '\n');
	} while (gioiTinhInput < 0 || gioiTinhInput > 1);

	a.phai = (gioiTinhInput == 0) ? "Nam" : "Nu";

	cout << "NHAP SDT :"; getline(cin, a.sodt);
	cout << "NHAP NAM SINH :"; getline(cin, a.namsinh);

	cout << "NHAP DIEM TOAN: "; cin >> a.ds_diem.toan;
	cout << "NHAP DIEM KTLT: "; cin >> a.ds_diem.ktlt;
	cout << "NHAP DIEM CSDL: "; cin >> a.ds_diem.csdl;

	a.ds_diem.diemTB = ((a.ds_diem.toan + a.ds_diem.ktlt + a.ds_diem.csdl) / 3);
}

node_sv* khoiTaoNode(SV x)//x luu data nguoi dung nhap vao
{
	node_sv* p = new node_sv;
	p->data = x;
	p->pnext = NULL;
	return p;
}
void themSV(danh_sach_sv &dssv, SV x)
{
	node_sv* p = khoiTaoNode(x);
	if (dssv.phead == NULL)//rong dau cuoi
	{
		dssv.phead = dssv.ptail = p;
	}
	else //n phan tu them cuoi 
	{
		dssv.ptail->pnext = p;
		dssv.ptail = p;
	}
}
void xuat(danh_sach_sv dssv, danh_Sach_KH dsk, const string& targetMaKhoa)
{
	int sttKhoa = 1; // Biến này để theo dõi số thứ tự của khoa
	string currentMaKhoa = "";
	for (node_sv* k = dssv.phead; k != NULL; k = k->pnext)
	{
		if (currentMaKhoa != k->data.ds_khoa.ma_khoa)
		{
			if (k->data.ds_khoa.ma_khoa == targetMaKhoa)
			{
				cout << left << setw(5) << "STT";
				cout << left << setw(20) << "TEN KHOA";
				cout << left << setw(15) << "MASSV"
				    << left << setw(20) << "HO"
					<< left << setw(20) << "TEN"
				    << left << setw(10) << "GIOITINH"
					<< left << setw(15) << "SDT"
					<< left << setw(15) << "NAMSINH"
					<< left << setw(10) << "TOAN"
					<< left << setw(10) << "KTLT"
					<< left << setw(10) << "CSDL"
					<< left << setw(10) << "DIEM TB" << endl;

				currentMaKhoa = k->data.ds_khoa.ma_khoa;
				sttKhoa = 1;
			}
		}

		if (k->data.ds_khoa.ma_khoa == targetMaKhoa)
		{
			cout << left << setw(5) << sttKhoa++;
			xuatTenKhoa2(k->data.ds_khoa.ma_khoa, dsk);
			cout << left << setw(15) << k->data.ma_sv
				<< left << setw(20) << k->data.ho
				<< left << setw(20) << k->data.ten
				<< left << setw(10) << k->data.phai
				<< left << setw(15) << k->data.sodt
				<< left << setw(15) << k->data.namsinh
				<< left << setw(10) << k->data.ds_diem.toan
				<< left << setw(10) << k->data.ds_diem.ktlt
				<< left << setw(10) << k->data.ds_diem.csdl
				<< left << setw(10) << k->data.ds_diem.diemTB << endl;
		}
	}
}
void xuatTheoTatCaKhoa(danh_sach_sv dssv, danh_Sach_KH dsk)
{
	for (node_k* kh = dsk.phead; kh != NULL; kh = kh->pnext)
	{
		cout << "-----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------" << endl;
		cout << "\nDanh sach sinh vien khoa " << kh->data.tenkhoa << ":\n";
		xuat(dssv, dsk, kh->data.ma_khoa);
		cout << "-----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------" << endl;
	}
}

void load_file(danh_Sach_SV& dssv) {
	ifstream filein("danhsachsinhvien.txt");
	if (!filein.is_open()) {
		cout << "Khong the mo file.\n";
		return;
	}

	while (!filein.eof()) {
		SV a;
		getline(filein, a.ds_khoa.ma_khoa, ',');
		getline(filein, a.ma_sv, ',');
		getline(filein, a.ho, ',');
		getline(filein, a.ten, ',');
		getline(filein, a.phai, ',');
		getline(filein, a.sodt, ',');
		getline(filein, a.namsinh, ',');
		filein >> a.ds_diem.toan;
		filein.ignore();
		filein >> a.ds_diem.ktlt;
		filein.ignore();
		filein >> a.ds_diem.csdl;
		filein.ignore();
		filein >> a.ds_diem.diemTB;
		filein.ignore();

		if (!a.ds_khoa.ma_khoa.empty() && !a.ma_sv.empty() && !a.ho.empty() && !a.ten.empty() &&
			!a.phai.empty() && !a.sodt.empty() && !a.namsinh.empty()) {
			themSV(dssv, a);
		}
	}

	filein.close();
}

void ghi_file(danh_Sach_SV& dssv) {
	ofstream outfile("danhsachsinhvien.txt");
	if (!outfile.is_open()) {
		cout << "Khong the mo file.\n";
		return;
	}

	for (node_sv* k = dssv.phead; k != nullptr; k = k->pnext) {
		outfile << k->data.ds_khoa.ma_khoa << ",";
		outfile << k->data.ma_sv << ",";
		outfile << k->data.ho << ",";
		outfile << k->data.ten << ",";
		outfile << k->data.phai << ",";
		outfile << k->data.sodt << ",";
		outfile << k->data.namsinh << ",";
		outfile << k->data.ds_diem.toan << ",";
		outfile << k->data.ds_diem.ktlt << ",";
		outfile << k->data.ds_diem.csdl << ",";
		outfile << k->data.ds_diem.diemTB << endl;
	}

	outfile.close();
}


void xoa_SV(danh_sach_sv& dssv, string vt)
{
	node_sv* h = NULL;
	for (node_sv* k = dssv.phead;k != NULL;)
	{
		if (_stricmp(k->data.ma_sv.c_str(), vt.c_str()) == 0 && k == dssv.phead)//---vt o vi tri dau
		{
			dssv.phead = dssv.phead->pnext;
			delete k;
			k = dssv.phead;
		}
		else
		{
			if (_stricmp(k->data.ma_sv.c_str(), vt.c_str()) == 0)//so sanh khong phan biet (xau)
			{
				h->pnext = k->pnext;// h lien ket voi ptu o phia sau k
				delete k;//xoa k di 
				k = h;// k vo dinh vaf duoc gan lai bang h
				if (h->pnext == NULL)//h dang la cuoi chung ta vua xoa cuoi 
				{
					dssv.ptail = h;
					return;
				}
			}
			h = k;
			k = k->pnext;
		}

	}
}

void sapXep(danh_sach_sv& dssv)
{
	for (node_sv* k = dssv.phead;k->pnext != NULL;k = k->pnext)//ap cuoi
	{
		for (node_sv* h = k->pnext;h != NULL;h = h->pnext)//den cuoi
		{
			if (_stricmp(h->data.ten.c_str(), k->data.ten.c_str()) < 0)
			{
				swap(k->data, h->data);
			}
			else if (_stricmp(h->data.ten.c_str(), k->data.ten.c_str()) == 0)
			{
				if (_stricmp(h->data.ho.c_str(), k->data.ho.c_str()) < 0)
				{
					swap(k->data, h->data);
				}
			}
		}
	}
}
int timKiem(danh_sach_sv dssv, string vt, danh_Sach_KH dsk)
{
	int i = 1;
	bool found = false;

	cout << left << setw(5) << "STT";
	cout << left << setw(20) << "TEN KHOA";
	cout << left << setw(15) << "MASSV"
		<< left << setw(20) << "HO"
		<< left << setw(20) << "TEN"
		<< left << setw(10) << "GIOITINH"
		<< left << setw(15) << "SDT"
		<< left << setw(15) << "NAMSINH"
		<< left << setw(10) << "TOAN"
		<< left << setw(10) << "KTLT"
		<< left << setw(10) << "CSDL"
		<< left << setw(10) << "DIEM TB" << endl;

	for (node_sv* k = dssv.phead; k != NULL; k = k->pnext)
	{
		if (_stricmp(k->data.ma_sv.c_str(), vt.c_str()) == 0)
		{
			found = true;
			cout << left << setw(5) << i++;
			xuatTenKhoa2(k->data.ds_khoa.ma_khoa, dsk);
			cout<< left << setw(15) << k->data.ma_sv
				<< left << setw(20) << k->data.ho
				<< left << setw(20) << k->data.ten
				<< left << setw(10) << k->data.phai
				<< left << setw(15) << k->data.sodt
				<< left << setw(15) << k->data.namsinh
				<< left << setw(10) << k->data.ds_diem.toan
				<< left << setw(10) << k->data.ds_diem.ktlt
				<< left << setw(10) << k->data.ds_diem.csdl
				<< left << setw(10) << k->data.ds_diem.diemTB << endl;
		}
	}

	if (!found)
	{
		cout << "Khong co sinh vien trong danh sach" << endl;
		return -1;
	}

	return 0;
}

void updateThongTinSV(danh_sach_sv& dssv, string vt, SV a)
{
	for (node_sv* k = dssv.phead; k != NULL; k = k->pnext)
	{
		if (_stricmp(k->data.ma_sv.c_str(), vt.c_str()) == 0)
		{
			// Kiểm tra từng thuộc tính để quyết định sửa hay không

			cout << "ban co muon sua HO khong (y/n): ";
			char updateHo;
			cin >> updateHo;
			cin.ignore(); // Xóa bộ nhớ đệm của cin

			if (updateHo == 'y' || updateHo == 'Y')
			{
				cout << "SUA HO: ";
				getline(cin, k->data.ho);
			}

			cout << "ban co muon sua TEN khong ? (y/n): ";
			char updateTen;
			cin >> updateTen;
			cin.ignore(); // Xóa bộ nhớ đệm của cin

			if (updateTen == 'y' || updateTen == 'Y')
			{
				cout << "SUA TEN: ";
				getline(cin, k->data.ten);
			}
			cout << "ban co muon sua PHAI khong ? (y/n): ";
			char updatePhai;
			cin >> updatePhai;
			cin.ignore(); // Xóa bộ nhớ đệm của cin

			if (updatePhai == 'y' || updatePhai == 'Y')
			{
				cout << "SUA PHAI : ";
				getline(cin, k->data.phai);
			}
			cout << "ban co muon sua SDT khong ? (y/n): ";
			char updateSDT;
			cin >> updateSDT;
			cin.ignore(); // Xóa bộ nhớ đệm của cin

			if (updateSDT == 'y' || updateSDT == 'Y')
			{
				cout << "SUA SDT : ";
				getline(cin, k->data.sodt);
			}
			cout << "ban co muon sua NAM SINH khong ? (y/n): ";
			char updateNAM;
			cin >> updateNAM;
			cin.ignore(); // Xóa bộ nhớ đệm của cin

			if (updateNAM == 'y' || updateNAM == 'Y')
			{
				cout << "SUA SDT : ";
				getline(cin, k->data.namsinh);
			}
			cout << "ban co muon sua DIEM TOAN khong ? (y/n): ";
			char updateTOAN;
			cin >> updateTOAN;
			cin.ignore(); // Xóa bộ nhớ đệm của cin

			if (updateTOAN == 'y' || updateTOAN == 'Y')
			{
				cout << "SUA DIEM TOAN : ";
				cin>> k->data.ds_diem.toan;
				k->data.ds_diem.diemTB = ((k->data.ds_diem.toan + k->data.ds_diem.ktlt + k->data.ds_diem.csdl) / 3);
				
			}
			cout << "ban co muon sua DIEM KTLT khong ? (y/n): ";
			char updateKT;
			cin >> updateKT;
			cin.ignore(); // Xóa bộ nhớ đệm của cin

			if (updateKT == 'y' || updateKT == 'Y')
			{
				cout << "SUA DIEM KTLT : ";
				cin >> k->data.ds_diem.ktlt;
				k->data.ds_diem.diemTB = ((k->data.ds_diem.toan + k->data.ds_diem.ktlt + k->data.ds_diem.csdl) / 3);
				
			}
			cout << "ban co muon sua DIEM CSDL khong ? (y/n): ";
			char updateCS;
			cin >> updateCS;
			cin.ignore(); // Xóa bộ nhớ đệm của cin

			if (updateCS == 'y' || updateCS == 'Y')
			{
				cout << "SUA DIEM CSDL : ";
				cin >> k->data.ds_diem.csdl;
				k->data.ds_diem.diemTB = ((k->data.ds_diem.toan + k->data.ds_diem.ktlt + k->data.ds_diem.csdl) / 3);

			}
			// Tương tự, bạn có thể thêm các điều kiện kiểm tra cho các thuộc tính khác.

			return;
		}
	}
	cout << "Khong co sinh vien trong danh sach" << endl;
}

void xuatSVLoaigioi(danh_Sach_SV dssv,danh_Sach_KH dsk)
{
	int i = 1;
	cout << left << setw(5) << "STT";
	cout << left << setw(20) << "TEN KHOA";
	cout<< left << setw(15) << "MASSV"
		<< left << setw(20) << "HO"
		<< left << setw(20) << "TEN"
		<< left << setw(10) << "GIOITINH"
		<< left << setw(15) << "SDT"
		<< left << setw(15) << "NAMSINH"
		<< left << setw(10) << "TOAN"
		<< left << setw(10) << "KTLT"
		<< left << setw(10) << "CSDL"
		<< left << setw(10) << "DIEM TB" << endl;
	for (node_sv* h = dssv.phead;h != NULL;h = h->pnext)
	{
		if (h->data.ds_diem.diemTB >= 8.0)
		{
			cout << left << setw(5) << i++;
			xuatTenKhoa2(h->data.ds_khoa.ma_khoa, dsk);
			cout<< left << setw(15) << h->data.ma_sv
				<< left << setw(20) << h->data.ho
				<< left << setw(20) << h->data.ten
				<< left << setw(10) << h->data.phai
				<< left << setw(15) << h->data.sodt
				<< left << setw(15) << h->data.namsinh
				<< left << setw(10) << h->data.ds_diem.toan
				<< left << setw(10) << h->data.ds_diem.ktlt
				<< left << setw(10) << h->data.ds_diem.csdl
				<< left << setw(10) << h->data.ds_diem.diemTB << endl;
			
		}
	}
}

void xuatSVLoaiKha(danh_Sach_SV dssv, danh_Sach_KH dsk)
{
	int i = 1;
	cout << left << setw(5) << "STT";
	cout << left << setw(20) << "TEN KHOA";
	cout<< left << setw(15) << "MASSV"
		<< left << setw(20) << "HO"
		<< left << setw(20) << "TEN"
		<< left << setw(10) << "GIOITINH"
		<< left << setw(15) << "SDT"
		<< left << setw(15) << "NAMSINH"
		<< left << setw(10) << "TOAN"
		<< left << setw(10) << "KTLT"
		<< left << setw(10) << "CSDL"
		<< left << setw(10) << "DIEM TB" << endl;
	for (node_sv* h = dssv.phead;h != NULL;h = h->pnext)
	{
		if (h->data.ds_diem.diemTB <8.0 && h->data.ds_diem.diemTB >= 6.5)
		{
			
			cout << left << setw(5) << i++;
			xuatTenKhoa2(h->data.ds_khoa.ma_khoa, dsk);
			cout << left << setw(15) << h->data.ma_sv
				<< left << setw(20) << h->data.ho
				<< left << setw(20) << h->data.ten
				<< left << setw(10) << h->data.phai
				<< left << setw(15) << h->data.sodt
				<< left << setw(15) << h->data.namsinh
				<< left << setw(10) << h->data.ds_diem.toan
				<< left << setw(10) << h->data.ds_diem.ktlt
				<< left << setw(10) << h->data.ds_diem.csdl
				<< left << setw(10) << h->data.ds_diem.diemTB << endl;
			
			
		}
	}
}
void xuatSVLoaiTB(danh_Sach_SV dssv, danh_Sach_KH dsk)
{
	int i = 1;
	cout << left << setw(5) << "STT";
	cout << left << setw(20) << "TEN KHOA";
	cout<< left << setw(15) << "MASSV"
		<< left << setw(20) << "HO"
		<< left << setw(20) << "TEN"
		<< left << setw(10) << "GIOITINH"
		<< left << setw(15) << "SDT"
		<< left << setw(15) << "NAMSINH"
		<< left << setw(10) << "TOAN"
		<< left << setw(10) << "KTLT"
		<< left << setw(10) << "CSDL"
		<< left << setw(10) << "DIEM TB" << endl;
	for (node_sv* h = dssv.phead;h != NULL;h = h->pnext)
	{
		if (h->data.ds_diem.diemTB < 6.5 && h->data.ds_diem.diemTB >= 5.0)
		{
			
			cout << left << setw(5) << i++;
			xuatTenKhoa2(h->data.ds_khoa.ma_khoa, dsk);
			cout << left << setw(15) << h->data.ma_sv
				<< left << setw(20) << h->data.ho
				<< left << setw(20) << h->data.ten
				<< left << setw(10) << h->data.phai
				<< left << setw(15) << h->data.sodt
				<< left << setw(15) << h->data.namsinh
				<< left << setw(10) << h->data.ds_diem.toan
				<< left << setw(10) << h->data.ds_diem.ktlt
				<< left << setw(10) << h->data.ds_diem.csdl
				<< left << setw(10) << h->data.ds_diem.diemTB << endl;
			
		}
	}
}
void xuatSVLoaiYEU(danh_Sach_SV dssv, danh_Sach_KH dsk)
{
	int i = 1;
	cout << left << setw(5) << "STT";
	cout << left << setw(20) << "TEN KHOA";
	cout<< left << setw(15) << "MASSV"
		<< left << setw(20) << "HO"
		<< left << setw(20) << "TEN"
		<< left << setw(10) << "GIOITINH"
		<< left << setw(15) << "SDT"
		<< left << setw(15) << "NAMSINH"
		<< left << setw(10) << "TOAN"
		<< left << setw(10) << "KTLT"
		<< left << setw(10) << "CSDL"
		<< left << setw(10) << "DIEM TB" << endl;
	for (node_sv* h = dssv.phead;h != NULL;h = h->pnext)
	{
		if (h->data.ds_diem.diemTB < 5)
		{
			

			cout << left << setw(5) << i++;
			xuatTenKhoa2(h->data.ds_khoa.ma_khoa, dsk);
			cout << left << setw(15) << h->data.ma_sv
				<< left << setw(20) << h->data.ho
				<< left << setw(20) << h->data.ten
				<< left << setw(10) << h->data.phai
				<< left << setw(15) << h->data.sodt
				<< left << setw(15) << h->data.namsinh
				<< left << setw(10) << h->data.ds_diem.toan
				<< left << setw(10) << h->data.ds_diem.ktlt
				<< left << setw(10) << h->data.ds_diem.csdl
				<< left << setw(10) << h->data.ds_diem.diemTB << endl;
	
			
		}
	}
}
float diemTBMax(danh_Sach_SV dssv)
{
	float max = 0;
	for (node_sv* h = dssv.phead;h != NULL;h = h->pnext)
	{
		if (h->data.ds_diem.diemTB > max)
			max = h->data.ds_diem.diemTB;
	}
	return max;
}

void hocSinhXuatSac(danh_Sach_SV dssv, danh_Sach_KH dsk)
{
	int i = 1;
	cout << left << setw(5) << "STT";
	cout << left << setw(20) << "TEN KHOA";
	cout<< left << setw(15) << "MASSV"
		<< left << setw(20) << "HO"
		<< left << setw(20) << "TEN"
		<< left << setw(10) << "GIOITINH"
		<< left << setw(15) << "SDT"
		<< left << setw(15) << "NAMSINH"
		<< left << setw(10) << "TOAN"
		<< left << setw(10) << "KTLT"
		<< left << setw(10) << "CSDL"
		<< left << setw(10) << "DIEM TB" << endl;
	for (node_sv* h = dssv.phead;h != NULL;h = h->pnext)
	{
		if (h->data.ds_diem.diemTB == diemTBMax(dssv))
		{
			cout << left << setw(5) << i++;
			xuatTenKhoa2(h->data.ds_khoa.ma_khoa, dsk);
			cout << left << setw(15) << h->data.ma_sv
				<< left << setw(20) << h->data.ho
				<< left << setw(20) << h->data.ten
				<< left << setw(10) << h->data.phai
				<< left << setw(15) << h->data.sodt
				<< left << setw(15) << h->data.namsinh
				<< left << setw(10) << h->data.ds_diem.toan
				<< left << setw(10) << h->data.ds_diem.ktlt
				<< left << setw(10) << h->data.ds_diem.csdl
				<< left << setw(10) << h->data.ds_diem.diemTB << endl;
		}
	}
}
bool xuatTenKhoa(string ma_khoa, danh_sach_KH dsk) {
	node_k* p = dsk.phead;
	while (p != NULL) {
		if (_stricmp(p->data.ma_khoa.c_str(), ma_khoa.c_str()) == 0) {
			cout << left << setw(20) << p->data.tenkhoa;
			return true;
		}
		p = p->pnext;
	}
	cout << "Khoa khong ton tai!" << endl;
	return false;
}
void xuatTenKhoa2(string ma_khoa, danh_sach_KH dsk) {
	node_k* p = dsk.phead;
	while (p != NULL) {
		if (_stricmp(p->data.ma_khoa.c_str(), ma_khoa.c_str()) == 0) {
			cout << left << setw(20) << p->data.tenkhoa;	
		}
		p = p->pnext;
	}
}
void xuatSinhVienTheoKhoa(danh_Sach_SV dssv, danh_Sach_KH dsk,string vt)
{
	int i = 1;
	cout << left << setw(5) << "STT";
	cout << left << setw(20) << "TEN KHOA";
	cout << left << setw(15) << "MASSV"
		<< left << setw(20) << "HO"
		<< left << setw(20) << "TEN"
		<< left << setw(10) << "GIOITINH"
		<< left << setw(15) << "SDT"
		<< left << setw(15) << "NAMSINH"
		<< left << setw(10) << "TOAN"
		<< left << setw(10) << "KTLT"
		<< left << setw(10) << "CSDL"
		<< left << setw(10) << "DIEM TB" << endl;
	for (node_sv* h = dssv.phead;h != NULL;h = h->pnext)
	{
		if (_stricmp(h->data.ds_khoa.ma_khoa.c_str(), vt.c_str()) == 0)
		{
			cout << left << setw(5) << i++;
			xuatTenKhoa2(h->data.ds_khoa.ma_khoa, dsk);
			cout << left << setw(15) << h->data.ma_sv
				<< left << setw(20) << h->data.ho
				<< left << setw(20) << h->data.ten
				<< left << setw(10) << h->data.phai
				<< left << setw(15) << h->data.sodt
				<< left << setw(15) << h->data.namsinh
				<< left << setw(10) << h->data.ds_diem.toan
				<< left << setw(10) << h->data.ds_diem.ktlt
				<< left << setw(10) << h->data.ds_diem.csdl
				<< left << setw(10) << h->data.ds_diem.diemTB << endl;
		}
	}
}
void xuatSinhVienLoaiGioiTheoKhoa(danh_Sach_SV dssv, danh_Sach_KH dsk, string vt)
{
	int i = 1;
	cout << left << setw(5) << "STT";
	cout << left << setw(20) << "TEN KHOA";
	cout<< left << setw(15) << "MASSV"
		<< left << setw(20) << "HO"
		<< left << setw(20) << "TEN"
		<< left << setw(10) << "GIOITINH"
		<< left << setw(15) << "SDT"
		<< left << setw(15) << "NAMSINH"
		<< left << setw(10) << "TOAN"
		<< left << setw(10) << "KTLT"
		<< left << setw(10) << "CSDL"
		<< left << setw(10) << "DIEM TB" << endl;
	for (node_sv* h = dssv.phead;h != NULL;h = h->pnext)
	{
		if (_stricmp(h->data.ds_khoa.ma_khoa.c_str(), vt.c_str()) == 0)
		{
			if (h->data.ds_diem.diemTB >= 8.0)
			{
				cout << left << setw(5) << i++;
				xuatTenKhoa2(h->data.ds_khoa.ma_khoa, dsk);
				cout << left << setw(15) << h->data.ma_sv
					<< left << setw(20) << h->data.ho
					<< left << setw(20) << h->data.ten
					<< left << setw(10) << h->data.phai
					<< left << setw(15) << h->data.sodt
					<< left << setw(15) << h->data.namsinh
					<< left << setw(10) << h->data.ds_diem.toan
					<< left << setw(10) << h->data.ds_diem.ktlt
					<< left << setw(10) << h->data.ds_diem.csdl
					<< left << setw(10) << h->data.ds_diem.diemTB << endl;
			}
		}
	}
}

bool kiemTraMaSVTrung(string ma_sv, danh_Sach_SV& dssv) {
	for (node_sv* k = dssv.phead; k != NULL; k = k->pnext) {
		if (_stricmp(k->data.ma_sv.c_str(), ma_sv.c_str()) == 0) {
			cout << "Ma sinh vien da ton tai. Vui long nhap lai." << endl;
			return true;
		}
	}
	return false;
}


// Hàm chuyển ký tự thành chữ in hoa
char toUpper(char ch) {
	return static_cast<char>(toupper(ch));
}

// Hàm chuyển ký tự thành chữ thường
char toLower(char ch) {
	return static_cast<char>(tolower(ch));
}

// Hàm chuẩn hóa họ tên: in hoa chữ cái đầu và viết thường chữ cái phía sau
void chuanHoaHoTen(string& hoTen) {
	bool capNhat = true; // Biến kiểm soát việc chuyển đổi chữ cái thành chữ in hoa

	for (size_t i = 0; i < hoTen.length(); ++i) {
		if (isspace(hoTen[i]) || hoTen[i] == '-') {
			capNhat = true; // Nếu gặp khoảng trắng hoặc dấu "-", chuyển sang việc in hoa chữ cái
		}
		else {
			if (capNhat) {
				hoTen[i] = toUpper(hoTen[i]); // In hoa chữ cái đầu
				capNhat = false; // Đặt lại trạng thái để không in hoa chữ cái phía sau
			}
			else {
				hoTen[i] = toLower(hoTen[i]); // Viết thường chữ cái phía sau
			}
		}
	}
}