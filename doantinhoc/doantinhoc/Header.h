#include <iostream>
#include <string>
#include <fstream>
#include <iomanip>
#include <cctype> 
using namespace std;
typedef struct diem
{
	float toan = 0;
	float ktlt = 0;
	float csdl = 0;
	float diemTB = 0;

}diem;
typedef struct Khoa
{
	string ma_khoa;
	string tenkhoa;
	int soLuongSV=0;

}KH;


typedef struct SinhVien
{
	string ma_sv;
	string ten;
	string ho;
	string phai;
	string sodt;
	string namsinh;
	diem ds_diem;
	string xeploai;
	KH ds_khoa;
}SV;

struct node_sv
{
	SV data;
	node_sv* pnext;
};
typedef struct node_sv node_sv;

typedef struct danh_Sach_SV {
	node_sv *phead = NULL;
	node_sv* ptail = NULL;
}danh_sach_sv;

struct node_k
{
	KH data;
	node_k* pnext;
};
typedef struct node_k node_k;

typedef struct danh_Sach_KH {
	node_k* phead = NULL;
	node_k* ptail = NULL;
}danh_sach_KH;

void khoitao(danh_Sach_SV& dssv);
void nhapSV(SV& a, danh_Sach_KH& dsk,danh_Sach_SV& dssv);
//void xuatSV(SV a);
node_sv* khoiTaoNode(SV x);
void themSV(danh_sach_sv& dssv, SV x);
//void xuat(danh_sach_sv dssv);
void xuat(danh_sach_sv dssv, danh_Sach_KH dsk, const string& targetMaKhoa);
void xuatTheoTatCaKhoa(danh_sach_sv dssv, danh_Sach_KH dsk);
void load_file(danh_sach_sv& dssv);
void ghi_file(danh_Sach_SV& dssv);
void xoa_SV(danh_sach_sv& dssv, string vt);
void sapXep(danh_sach_sv& dssv);
int timKiem(danh_sach_sv dssv, string vt,danh_Sach_KH dsk);
void updateThongTinSV(danh_sach_sv& dssv, string vt, SV a);
void xuatSVLoaigioi(danh_Sach_SV dssv, danh_Sach_KH dsk);
void xuatSVLoaiKha(danh_Sach_SV dssv, danh_Sach_KH dsk);
void xuatSVLoaiTB(danh_Sach_SV dssv, danh_Sach_KH dsk);
void xuatSVLoaiYEU(danh_Sach_SV dssv, danh_Sach_KH dsk);
float diemTBMax(danh_Sach_SV dssv);
void hocSinhXuatSac(danh_Sach_SV dssv,danh_Sach_KH dsk);
void xuatSinhVienTheoKhoa(danh_Sach_SV dssv, danh_Sach_KH dsk, string vt);
void xuatSinhVienLoaiGioiTheoKhoa(danh_Sach_SV dssv, danh_Sach_KH dsk, string vt);

////---------------------------------------------------------
void khoitao(danh_Sach_KH& dsk);
node_k* khoiTaoNode(KH x);
void nhapKH(KH& k,danh_Sach_KH&dsk);
void themKHOA(danh_sach_KH& dsk, KH x);
void xuatKHOA(danh_sach_KH dsk);
void load_fileKH(danh_sach_KH& dsk);
//void xoa_khoa(danh_sach_KH& dsk, string vt);
void xoaKhoa(danh_sach_KH& dsk, danh_sach_sv& dssv, const string& maKhoaCanXoa);
void sapXepKH(danh_sach_KH& dsk);
int timKiemKH(danh_sach_KH dsk, string vt);
void updateThongTinKH(danh_sach_KH& dsk, string vt, KH a);
void xoa_khoa(danh_sach_KH& dsk, string vt);
void giaiPhong(danh_Sach_SV& dssv);
void giaiPhongKH(danh_Sach_KH& dsk);
void ghi_fileKH(danh_Sach_KH& dsk);
void nhapK(KH& k);
void xuatsoluongsinhvientungkhoa( danh_sach_sv& dssv,  danh_sach_KH& dsk);
//--------------------------------------------------------------------------------------------
bool xuatTenKhoa(string ma_khoa, danh_sach_KH dsk);
int maKhoaKhongTrung(string ma_khoa, danh_sach_KH dsk);
bool kiemTraMaSVTrung(string ma_sv, danh_Sach_SV& dssv);
void xuatTenKhoa2(string ma_khoa, danh_sach_KH dsk);
//--------------------------------------------------------------------------------------------
void MENUCHINH();
void MENU();
void MENU1();
char toUpper(char ch);
char toLower(char ch);
void chuanHoaHoTen(string& hoTen);