#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

class Vemaybay {
public:
    string tenchuyen;
    string ngaybay;
    float giave;

    Vemaybay() {
        tenchuyen = "";
        ngaybay = "";
        giave = 0.0;
    }

    ~Vemaybay() {}

    void Nhap() {
        cout << "Nhap ten chuyen: ";
        cin.ignore();
        getline(cin, tenchuyen);

        cout << "Nhap ngay bay: ";
        getline(cin, ngaybay);

        cout << "Nhap gia ve: ";
        cin >> giave;
    }

    void Xuat() {
        cout << "Ten chuyen: " << tenchuyen << endl;
        cout << "Ngay bay: " << ngaybay << endl;
        cout << "Gia ve: " << giave << endl;
    }

    float getgiave() {
        return giave;
    }
};

class Nguoi {
public:
    string hoten;
    string gioitinh;
    int tuoi;

    Nguoi() {
        hoten = "";
        gioitinh = "";
        tuoi = 0;
    }

    ~Nguoi() {}

    void Nhap() {
        cout << "Nhap ho ten: ";
        cin.ignore();
        getline(cin, hoten);

        cout << "Nhap gioi tinh: ";
        getline(cin, gioitinh);

        cout << "Nhap tuoi: ";
        cin >> tuoi;
    }

    void Xuat() {
        cout << "Ho ten: " << hoten << endl;
        cout << "Gioi tinh: " << gioitinh << endl;
        cout << "Tuoi: " << tuoi << endl;
    }
};

class HanhKhach : public Nguoi {
public:
    Vemaybay* ve;
    int soluong;

    HanhKhach() {
        ve = nullptr;
        soluong = 0;
    }

    ~HanhKhach() {
        delete[] ve;
    }

    void Nhap() {
        Nguoi::Nhap();

        cout << "Nhap so luong ve: ";
        cin >> soluong;

        ve = new Vemaybay[soluong];
        for (int i = 0; i < soluong; ++i) {
            cout << "Nhap thong tin ve thu " << i + 1 << ":" << endl;
            ve[i].Nhap();
        }
    }

    void Xuat() {
        Nguoi::Xuat();

        cout << "So luong ve: " << soluong << endl;
        for (int i = 0; i < soluong; ++i) {
            cout << "Thong tin ve thu " << i + 1 << ":" << endl;
            ve[i].Xuat();
        }
    }

    float tongtien() {
        float total = 0.0;
        for (int i = 0; i < soluong; ++i) {
            total += ve[i].getgiave();
        }
        return total;
    }
};

int main() {
    int n;

    cout << "Nhap so luong hanh khach: ";
    cin >> n;

    HanhKhach* danhSachHanhKhach = new HanhKhach[n];

    for (int i = 0; i < n; ++i) {
        cout << "Nhap thong tin hanh khach thu " << i + 1 << ":" << endl;
        danhSachHanhKhach[i].Nhap();
    }

    cout << "Danh sach hanh khach va so tien phai tra:" << endl;

    // Sắp xếp danh sách theo chiều giảm dần của Tổng tiền
    sort(danhSachHanhKhach, danhSachHanhKhach + n, [](const HanhKhach& a, const HanhKhach& b) {
        return a.tongtien() > b.tongtien();
    });

    for (int i = 0; i < n; ++i) {
        cout << "Thong tin hanh khach thu " << i + 1 << ":" << endl;
        danhSachHanhKhach[i].Xuat();
        cout << "Tong tien phai tra: " << danhSachHanhKhach[i].tongtien() << endl;
    }

    delete[] danhSachHanhKhach;

    return 0;
}
