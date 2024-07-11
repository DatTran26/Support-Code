#include <iostream>
#include <cmath>
#define MAX 100
using namespace std;

void NhapMang(int* &arr, int& n);
void XuatMang(int* &arr, int n);
void init(int*& arr, int n);
void FreeArr(int*& arr);
void ChinhPhuong(int* arr, int n);
void SoHoanThien(int* arr, int n);
void SoDuong(int* arr, int n);
void SoAm(int* arr, int n);

void init(int*& arr, int n) 
{
	arr = new int[n];
}

void FreeArr(int*& arr) 
{
	if (arr != nullptr)
	{
		delete[] arr;
		arr = nullptr;
	}
}
void NhapMang(int*& arr, int& n)
{
	do
	{
		cout << "Nhap so phan tu cho mang: ";
		cin >> n;
		if (n <= 0 || n > MAX)
			cout << "Nhap lai so phan tu: ";
	} while (n<=0 || n>MAX);
	init(arr, n);
	if (arr != nullptr)
	{
		for (int i = 0; i < n; i++)
		{
			cout << "Nhap gia tri a[" << i << "]= ";
			cin >> arr[i];
		}
	}
}
void XuatMang(int*&arr, int n)
{
	if (arr != nullptr) 
	{
		for (int i = 0; i < n; i++) {
			cout << arr[i] << "\t";
		}
		cout << endl;
	}
}
void ChinhPhuong(int* arr, int n)
{
	int dem = 0;
	if(arr!=nullptr)
	{
		for(int i=0;i<n;i++)
		{
			int so = sqrt(arr[i]);
			if (so * so == arr[i])
				dem++;
		}
	}
	cout << "Co " << dem << " so chinh phuong trong mang. " << endl;
}
int TongSoHoanThien(int n)
{
	int tong = 0;
	for(int i=1;i<n;i++)
	{
		if (n % i == 0)
			tong += i;
	}
	return tong;
}
bool DK_SoHoanThien(int *&arr,int &n)
{
	for (int i = 0; i < n; i++)
	{
		int tong = 0;
		for (int j = 1; j < arr[i]; j++)
		{
			if (arr[i] % j == 0)
				tong += j;
		}
		if (tong == arr[i])
		{
			return true;
		}
	}
	return false;
}
void SoHoanThien(int* arr, int n)
{
	if (arr != nullptr)
	{
		if (DK_SoHoanThien(arr, n))
		{
			cout << "Trong mang co so hoan thien. " << endl;
		}
		else
		{
			cout << "Trong mang khong co so hoan thien. " << endl;
		}
	}
}
void SoDuong(int* arr, int n)
{
	int dem = 0;
	if (arr != nullptr)
	{
		for (int i = 0; i < n; i++)
		{ 
			if (arr[i] > 0)
				dem++;
		}
	}
	if (dem > 0)
		cout << "Trong mang co so duong." << endl;
	else cout << "Trong mang khong co so duong." << endl;
}
void SoAm(int* arr, int n)
{
	int dem = 0;
	if (arr != nullptr)
	{
		for (int i = 0; i < n; i++)
		{
			if (arr[i] < 0)
				dem++;
		}
	}
	if (dem > 0)
		cout << "Trong mang co so am." << endl;
	else cout << "Trong mang khong co so am." << endl;
}
bool DK_SoNguyenTo(int n)
{
	if (n < 2)
		return false;
	for (int i = 2; i <=sqrt(n); i++)
	{
		if (n % i == 0)
			return false;
	}
	return true;
}
void SoNguyenTo(int*&arr,int &n)
{
	if (arr == nullptr || n <= 0) return;
	bool SoNguyenTo = false;
	for(int i=0;i<n;i++)
	{
		if (DK_SoNguyenTo(arr[i]))
		{
			SoNguyenTo = true;
			break;
		}
	}
	if(SoNguyenTo)
	{
		cout << "Trong mang co so nguyen to. " << endl;
	}
	else
	{
		cout << "Trong mang khong co so nguyen to. " << endl;
	}
}
bool DK_SoChinhPhuong(int n)
{
	int so = sqrt(n);
	return so * so == n;
}
int* SoCP_DauTien(int *&arr,int &n)
{
	if(arr!=nullptr)
	{
		for (int i = 0; i < n; i++)
		{
			if (DK_SoChinhPhuong(arr[i]))
				return &arr[i];
		}
	}
	return nullptr;
}
bool DK_SoHoanThien_Final(int n) 
{
	int tong = 0;
	for (int j = 1; j < n; j++) {
		if (n % j == 0)
			tong += j;
	}
	return tong == n;
}
int *SoHT_CuoiCung(int*&arr,int &n)
{
	if(arr!=nullptr)
	{
		for(int i=n-1;i>=0;i--)
		{
			if (DK_SoHoanThien_Final(arr[i]))
				return &arr[i];
		}
	}
return nullptr;
}
int* DC_So_Min_Dau_Tien(int *&arr,int &n)
{
	if (arr == nullptr || n <= 0) return nullptr;
	int GT_Min_Dau = arr[0];
	int *Min_Dau = &arr[0];
	for(int i=0;i<n;i++)
		{
			if (arr[i] < *Min_Dau)
				GT_Min_Dau = arr[i];
				Min_Dau = &arr[i];
		}
	return Min_Dau;
}
int* DC_So_Min_Cuoi_Cung(int*& arr, int n)
{
	int GT_Min_Cuoi = arr[n - 1];
	int* Min_Cuoi = &arr[n-1];
	if (arr != nullptr)
	{
		for (int i = n-2; i >=0; i--)
		{
			if (arr[i] <= *Min_Cuoi)
				GT_Min_Cuoi = arr[i];
				Min_Cuoi = &arr[i];
		}
	}
	return Min_Cuoi;
}
void XoaViTri(int *&arr, int n, int x)
{
	do
	{
		cout << "Moi ban nhap vi tri ban muon xoa: ";
		cin >> x;
		if (x<0 || x>=n || x > MAX)
			cout << "Moi ban nhap lai vi tri ban muon xoa. " << endl;
	} while (x<0 || x>MAX||x>=n);
	for(int i=x;i<n-1;i++)
	{
		arr[i] = arr[i + 1];
	}
	n--;
}
void swap(int &a,int &b)
{
	int tam = a;
	a = b;
	b = tam;
}
//Sap xep giam dan//
void SapXepGiamDan(int *&arr,int start, int end)
{
	for(int i=start;i<=end;i++)
	{
		for (int j = i+1; j < end; j++)
		{
			if (arr[i] < arr[j])
				swap(arr[i], arr[j]);
		}
	}
}
//Sap xep tang dan//
void SapXepTangDan(int *&arr,int start, int end)
{
	for (int i = start; i <= end; i++)
	{
		for (int j = i+1; j <= end; j++)
		{
			if (arr[i] > arr[j])
				swap(arr[i], arr[j]);
		}
	}
}
void SapXepTangDauGiamSau(int *&arr,int n)
{
	if (n < 2) return;
	int mid = n / 2;
	if(arr!=nullptr)
	{
		SapXepTangDan(arr, 0, mid);
		SapXepGiamDan(arr, mid, n );
	}
}
int* GopMang(int *a,int A,int *b,int B)
{
	int* c = new int[A + B];
	if(c!=nullptr)
	{
		int dem = 0;
		for (int i = 0; i < A; i++)
			c[dem++] = a[i];
		for (int i = 0; i < B; i++)
			c[dem++] = b[i];
	}
	return c;
}
int main()
{
	int* a = nullptr, n; int x = 0;
	int* b = nullptr, m;
	int* c = nullptr;
	NhapMang(a, n);
	SapXepTangDan(a, 0, n);
	XuatMang(a, n);
	NhapMang(b, m);
	SapXepTangDan(b, 0, m);
	XuatMang(b, m);
	ChinhPhuong(a, n);
	SoHoanThien(a, n);
	SoDuong(a, n);
	SoAm(a, n);
	SoNguyenTo(a, n);
	int* DC_CP = SoCP_DauTien(a, n);
	if(DC_CP!=nullptr)
	{
		cout << "Dia chi so chinh phuong dau tien la: " << DC_CP << endl;
	}
	else 
	{
		cout << "Khong co so chinh phuong nao trong mang. " << endl;
	}
	int* DC_HT = SoHT_CuoiCung(a, n);
	if (DC_HT != nullptr)
	{
		cout << "Dia chi so hoan thien cuoi cung la: " << DC_HT << endl;
	}
	else
	{
		cout << "Khong co so hoan thien nao trong mang. " << endl;
	}
	int* Min_First = DC_So_Min_Dau_Tien(a, n);
	cout << "Dia chi so nho nhat dau tien cua mang: " << Min_First << endl;
	int* Min_Last = DC_So_Min_Cuoi_Cung(a, n);
	cout << "Dia chi so nho nhat cuoi cung cua mang: " << Min_Last << endl;
	XoaViTri(a, n, x);
	XuatMang(a, n);
	SapXepGiamDan(a,0, n);
	XuatMang(a, n);
	SapXepTangDan(a,0, n);
	XuatMang(a, n);
	SapXepTangDauGiamSau(a, n);
	XuatMang(a, n);
	c= GopMang(a, n, b, m);
	XuatMang(c, n + m);
	SapXepTangDan(c, 0, n + m);
	XuatMang(c, n + m);
	FreeArr(a);
}