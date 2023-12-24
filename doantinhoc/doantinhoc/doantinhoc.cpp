#include"Header.h"
int main()
{
	MENUCHINH();
	system("pause");
}
void MENUCHINH()
{
	int n;
	do {
		cout << "---------------------------[  MENU  ]" << "---------------------------------------" << endl;
		cout << "[1.QUAN LI KHOA]" << endl;
		cout << "[-----------------------------------------------------------------------" << endl;
		cout << "[2.QUAN LI SINH VIEN]" << endl;
		cout << "[-----------------------------------------------------------------------" << endl;
		cout << "[NHAP LUA CHON]: ";
		cin >> n;
	} while (n < 0 || n>2);
	if (n == 1)
	{
		MENU();
	}
	else if (n == 2)
	{
		MENU1();
	}
}
void MENU()
{
	//setting
	danh_Sach_SV dssv;
	danh_Sach_KH dsk;
	load_fileKH(dsk);
	load_file(dssv);
	//menu
	bool kt_menu = true;
	while (kt_menu == true)
	{
		system("cls");
		cout << "--------------------------[ MENU QUAN LI KHOA ] " << "----------------------------" << endl;
		cout << "[" << "[ 1. NHAP KHOA ] " << endl;
		cout << "[-----------------------------------------------------------------------------------" << endl;
		cout << "[" << "[ 2. XUAT  DS KHOA ] " << endl;
		cout << "[-----------------------------------------------------------------------------------" << endl;
		cout << "[" << "[ 3. XOA KHOA ] " << endl;
		cout << "[-----------------------------------------------------------------------------------" << endl;
		cout << "[" << "[ 4. SAP XEP KHOA ] " << endl;
		cout << "[-----------------------------------------------------------------------------------" << endl;
		cout << "[" << "[ 5.LUU DANH SACH KHOA ]" << endl;
		cout << "[-----------------------------------------------------------------------------------" << endl;
		cout << "[" << "[ 6.TIM KHOA TRONG DANH SACH ]" << endl;
		cout << "[-----------------------------------------------------------------------------------" << endl;
		cout << "[" << "[ 7.CAP NHAT KHOA ]" << endl;
		cout << "[-----------------------------------------------------------------------------------" << endl;
		cout << "[" << "[ 0. EXIT ] " << endl;
		cout << "-------------------------------------------------------------------------------" << endl;
		int lc;
		cout << "[NHAP LUA CHON]: ";
		cin >> lc;
		switch (lc)
		{
		case 1:
		{
			char continueInput;
			do {
				cout << "\t\t--------Nhap khoa------" << endl;
				KH x;
				cin.ignore();
				nhapKH(x, dsk);
				themKHOA(dsk, x);
				cout << "Nhap them khoa ? (y/n): ";
				cin >> continueInput;
				cin.ignore();
			} while (continueInput == 'y' || continueInput == 'Y');
			ghi_fileKH(dsk);
			break;
		}
			
			
		case 2:
		{
			xuatsoluongsinhvientungkhoa(dssv, dsk);
			xuatKHOA(dsk);
			system("pause");
			break;
		}
		case 3:
		{
			string vt;
			cin.ignore();
			cout << "nhap ma khoa can xoa: ";
			getline(cin, vt);
			xoaKhoa(dsk, dssv,vt);
			ghi_fileKH(dsk);
			cout << "da xoa !!!" << endl;
			break;
		}
		case 4:
		{
			sapXepKH(dsk);
			cout << "Da Sap Xep Xong A-Z !!!" << endl;
			system("pause");

			break;
		}
		case 5:
		{
			ghi_fileKH(dsk);
			cout << "Da Luu !!!" << endl;
			system("pause");

			break;
		}
		case 6:
		{
			string vt;
			cin.ignore();
			cout << "nhap ma khoa can tim kiem: ";
			getline(cin, vt);
			timKiemKH(dsk, vt);
			system("pause");

			break;
		}
		case 7:
		{
			string vt;
			KH a;
			do {
				cin.ignore();
				cout << "nhap ma khoa can sua: ";
				getline(cin, vt);
			} while (timKiemKH(dsk, vt) == -1);
			cout << "Da tim Thay khoa can sua !" << endl;
			updateThongTinKH(dsk, vt, a);
			ghi_fileKH(dsk);
			cout << "da sua xong bam phim 2 de kiem tra !!!" << endl;
			system("pause");
			break;
		}

		case 0:
		{
			kt_menu = false;
			MENUCHINH();
			break;
		}

		}
	}

}
void MENU1()
{
	//setting
	danh_Sach_KH dsk;
	danh_Sach_SV dssv;
	load_fileKH(dsk);
	load_file(dssv);
	//menu
	bool kt_menu = true;
	while (kt_menu == true)
	{
		system("cls");
		cout << "--------------------------[ MENU QUAN LI SINH VIEN ] " << "----------------------------" << endl;
		cout << "[" << "[ 1.NHAP SINH VIEN ] " << endl;
		cout << "[-----------------------------------------------------------------------------------" << endl;
		cout << "[" << "[ 2. XUAT DS SINH VIEN ] " << endl;
		cout << "[-----------------------------------------------------------------------------------" << endl;
		cout << "[" << "[ 3. XOA SV ] " << endl;;
		cout << "[-----------------------------------------------------------------------------------" << endl;
		cout << "[" << "[ 4. SAP XEP SINH VIEN ] " << endl;
		cout << "[-----------------------------------------------------------------------------------" << endl;
		cout << "[" << "[ 5. DANH SACH SINH VIEN ]" << endl;
		cout << "[-----------------------------------------------------------------------------------" << endl;
		cout << "[" << "[ 6.TIM SINH VIEN ]" << endl;
		cout << "[-----------------------------------------------------------------------------------" << endl;
		cout << "[" << "[ 7.SUA THONG TIN SINH VIEN ]" << endl;
		cout << "[-----------------------------------------------------------------------------------" << endl;
		cout << "[" << "[ 8.PHAN LOAI HOC SINH ]" << endl;
		cout << "[-----------------------------------------------------------------------------------" << endl;
		cout << "[" << "[ 9.SINH VIEN XUAT SAC NHAT ]" << endl;
		cout << "[-----------------------------------------------------------------------------------" << endl;
		cout << "[" << "[ 10.XUAT SINH VIEN THEO KHOA ]" << endl;
		cout << "[-----------------------------------------------------------------------------------" << endl;
		cout << "[" << "[ 11.XUAT SINH VIEN LOAI GIOI THEO KHOA ]" << endl;
		cout << "[-----------------------------------------------------------------------------------" << endl;
		cout << "[" << "[ 0. EXIT ] " << endl;
		cout << "-------------------------------------------------------------------------------" << endl;
		int lc;
		cout << "[NHAP LUA CHON]: ";
		cin >> lc;
		switch (lc)
		{
		case 1:
		{
			char continueInput;
			do {
				cout << "\t\t--------Nhap sinh vien------" << endl;
				SV x;
				cin.ignore();
				nhapSV(x, dsk, dssv);
				themSV(dssv, x);
				cout << "Nhap them sinh vien? (y/n): ";
				cin >> continueInput;
				cin.ignore();
			} while (continueInput == 'y' || continueInput == 'Y');
			node_sv* k = dssv.phead;
			while (k != NULL) {
				chuanHoaHoTen(k->data.ho);
				chuanHoaHoTen(k->data.ten);
				k = k->pnext;
			}
			ghi_file(dssv);
			break;
		}
		case 2:
		{
			cout << "------------------------------------------ " << endl;
			node_sv* k = dssv.phead;
			while (k != NULL) {
				chuanHoaHoTen(k->data.ho);
				chuanHoaHoTen(k->data.ten);
				k= k->pnext;
			}
			xuatTheoTatCaKhoa(dssv, dsk);
			cout << "------------------------------------------ " << endl;
			system("pause");
			break;
		}
		case 3:
		{
			string vt;
			cin.ignore();
			cout << "NHAP MA SV CAN XOA: ";
			getline(cin, vt);
			xoa_SV(dssv, vt);
			ghi_file(dssv);
			break;
		}
		case 4:
		{
			sapXep(dssv);
			cout << "DA SAP XEP XONG " << endl;
			system("pause");
			break;
		}
		case 5:
		{
			ghi_file(dssv);
			cout << "DA LUU" << endl;
			system("pause");
			break;
		}
		case 6:
		{
			string vt;
			cin.ignore();
			cout << "NHAP MA SV CAN TIM: ";
			getline(cin, vt);
			timKiem(dssv, vt, dsk);
			cin.ignore();
			system("pause");
			break;
		}
		case 7:
		{
			string vt;
			SV a;
			do {
				cin.ignore();
				cout << "NHAP MA SINH VIEN CAN SUA : ";
				getline(cin, vt);
			} while (timKiem(dssv, vt, dsk) == -1);
			cout << "Da tim Thay Sinh vien can sua !" << endl;
			updateThongTinSV(dssv, vt, a);
			cout << "da sua xong bam phim 2 de kiem tra !!!" << endl;
			ghi_file(dssv);
			system("pause");
			break;
		}
		case 8:
		{
			cout << "------------------------[HOC SINH GIOI]---------------------------------" << endl;
			xuatSVLoaigioi(dssv, dsk);
			cout << endl;
			cout << "------------------------[HOC SINH KHA] ---------------------------------" << endl;
			xuatSVLoaiKha(dssv, dsk);
			cout << endl;
			cout << "------------------------[HOC SINH TRUNG BINH] --------------------------" << endl;
			xuatSVLoaiTB(dssv, dsk);
			cout << endl;
			cout << "------------------------[HOC SINH YEU] ---------------------------------" << endl;
			xuatSVLoaiYEU(dssv, dsk);
			system("pause");
			break;
		}
		case 9:
		{
			cout << "------------------------[HOC SINH XUAT SAC NHAT] ------------------------" << endl;
			hocSinhXuatSac(dssv, dsk);
			system("pause");
			break;
		}
		case 10:
		{
			string vt;
			cin.ignore();
			cout << "NHAP MA KHOA DE XUAT SINH VIEN: ";
			getline(cin, vt);
			xuatSinhVienTheoKhoa(dssv, dsk, vt);
			system("pause");
			break;
		}
		case 11:
		{
			string vt;
			cin.ignore();
			cout << "NHAP MA KHOA DE XUAT SINH VIEN LOAI GIOI: ";
			getline(cin, vt);
			xuatSinhVienLoaiGioiTheoKhoa(dssv, dsk, vt);
			system("pause");
			break;
		}
		case 0:
		{
			kt_menu = false;
			MENUCHINH();
			break;
		}

		}
	}

}

