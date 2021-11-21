// read and write txt file.cpp :

#include <iostream>
#include<string>
#include<fstream>
#include<iomanip>
using namespace std;

struct people {
    string name;
    int age;
    float point;
};

void read_file(ifstream &filein, people arr[],int &number_of_people) {

    filein.open("data.txt", ios_base::in);
    int i = 0;
    while (!filein.eof()) {
        getline(filein, arr[i].name,',');
        filein >> arr[i].age;
char x;
filein >> x;
filein >> arr[i].point;
i++;
    }

    number_of_people = i;
    filein.close();
}

void process(people arr[], int number_of_people) {
    for (int i = 0; i < number_of_people; i++) {
        if (arr[i].name.at(0) == '\n') {
            arr[i].name.erase(arr[i].name.begin());
        }
    }
}
void show(people arr[], int number_of_people) {
    cout << "\tthong tin sinh hoc sinh\n";
    cout << "\t+--------+----------------------------+-----------+-----------+\n";
    cout << "\t|STT     |ho va ten                   |tuoi       |diem       |\n";
    cout << "\t+--------+----------------------------+-----------+-----------+\n";
    for (int i = 0; i < number_of_people; i++) {
        cout << "\t|" << i + 1 << "       |";
        cout << setw(28)<<left << arr[i].name <<"|" <<setw(11)<<left << arr[i].age <<"|"<<setw(11)<<left << arr[i].point<<"|" << endl;
    }
    cout << "\t+--------+----------------------------+-----------+-----------+\n";

}

void add(people arr[], int& number_of_people) {
    cout << "nhap thong tin hoc sinh:\n";
    cout << "\tnhap ten: ";
    cin.ignore();
    getline(cin, arr[number_of_people].name);
    cout << "\tnhap tuoi: ";
    cin >> arr[number_of_people].age;
    cout << "\tnhap diem: ";
    cin >> arr[number_of_people].point;
    number_of_people++;
}

void edit(people arr[]) {
    int i;
    cout << "nhap stt hoc sinh ban muon chinh sua:\n";
    cin >> i;
    cout << "\tsua ten: ";
    cin.ignore();
    getline(cin, arr[i - 1].name);
    cout << "\tsua tuoi: ";
    cin >> arr[i - 1].age;
    cout << "\tsua diem: ";
    cin >> arr[i - 1].point;
}

void deleteinfor(people arr[], int& number_of_people) {
    cout << "nhap so thu tu sinh vien ban  muon xoa:\n";
    int n;
    cin >> n;
    for (int i = n; i < number_of_people; i++) {
        arr[i - 1].name = arr[i].name;
        arr[i - 1].age = arr[i].age;
        arr[i - 1].point = arr[i].point;
    }
    number_of_people--;
}

void backup(ofstream& fileout, people arr[], int number_of_people) {
    fileout.open("data.txt", ios_base::out);

    for (int i = 0; i < number_of_people; i++) {
        if (i == number_of_people - 1) {
            fileout << arr[i].name << "," << arr[i].age << "," << arr[i].point;
        }
        else {
            fileout << arr[i].name << "," << arr[i].age << "," << arr[i].point << endl;
        }
    }
    fileout.close();
}

void statistical(people arr[], int number_of_people) {
    cout << "\tthong ke:\n";
    cout << "\t\tdiem trung binh: ";
    float medium_score = 0;
    float sum = 0;
    for (int i = 0; i < number_of_people; i++) {
        sum += arr[i].point;
    }
    medium_score = sum / number_of_people;
    cout << medium_score << endl;
    cout << "\t\thoc sinh diem cao nhat (";
    float max = arr[0].point;
    int b[100];
    for (int i = 1; i < number_of_people; i++) {
        if (max < arr[i].point) {
            max = arr[i].point;
        }
    }
    cout << max << ")"<<endl;
    for (int i = 0; i < number_of_people; i++) {
        if (arr[i].point == max) {
            cout << "\t\t\t" << arr[i].name << endl;
        }
    }
    int Excellent = 0;
    int good = 0;
    int average = 0;
    for (int i = 0; i < number_of_people; i++) {
        if (arr[i].point >= 8) {
            Excellent++;
        }
        else if(arr[i].point>=6.5&&arr[i].point<8) {
            good++;
        }
        else {
            average++;
        }
    }
    cout << "\t\tso hoc sinh gioi: " << Excellent / number_of_people * 100 << "%" << endl;
    cout << "\t\tso hoc sinh kha: " << good / number_of_people * 100<<"%" << endl;
    cout << "\t\tso hoc sinh trung binh: " << average / number_of_people * 100<<"%" << endl;
}

void find(people arr[], int number_of_people) {
    string check;
    cout << "\tnhap ki tu :";
    cin.ignore();
    getline(cin, check);
    int j = 0;
    cout << "\tthong tin sinh hoc sinh\n";
    cout << "\t+--------+----------------------------+-----------+-----------+\n";
    cout << "\t|STT     |ho va ten                   |tuoi       |diem       |\n";
    cout << "\t+--------+----------------------------+-----------+-----------+\n";
    for (int i = 0; i < number_of_people; i++) {
        if (arr[i].name.find(check) != string::npos) {
            cout << "\t|" << j + 1 << "       |";
            cout << setw(28) << left << arr[i].name << "|" << setw(11) << left << arr[i].age << "|" << setw(11) << left << arr[i].point << "|" << endl;
            cout << "\t+--------+----------------------------+-----------+-----------+\n";
            j++;
        }
    }
}

void sort(people arr[], int number_of_people) {
    cout << "\t1:sap xep theo ten\n";
    cout << "\t2:sap xep theo diem cao nhat-> thap nhat\n";
    cout << "\tnhap lua chon: ";
    int select;
    cin >> select;
    
    if (select == 2) {
        for (int i= 0; i < number_of_people-1 ; i++) {
            for (int j = i + 1; j < number_of_people; j++) {
                if (arr[i].point < arr[j].point) {
                    people c;
                    c.name = arr[i].name;
                    c.age = arr[i].age;
                    c.point = arr[i].point;
                    arr[i].name = arr[j].name;
                    arr[i].age = arr[j].age;
                    arr[i].point = arr[j].point;
                    arr[j].name = c.name;
                    arr[j].age = c.age;
                    arr[j].point = c.point;
                }
            }
        }
        show(arr, number_of_people);
    }
    else {
        for (int i = 0; i < number_of_people-1; i++) {
            for (int j = i + 1; j < number_of_people; j++) {
                if (arr[i].name > arr[j].name) {
                    people c;
                    c.name = arr[i].name;
                    c.age = arr[i].age;
                    c.point = arr[i].point;
                    arr[i].name = arr[j].name;
                    arr[i].age = arr[j].age;
                    arr[i].point = arr[j].point;
                    arr[j].name = c.name;
                    arr[j].age = c.age;
                    arr[j].point = c.point;
                }
            }
        }
        show(arr, number_of_people);
    }
}
int main()
{
    ifstream filein;
    people arr[100];
    int number_of_people;
    read_file(filein, arr,number_of_people);
    process(arr, number_of_people);
    cout << "Danh sach thao tac:\n";
    cout << "1.in danh sach:\n";
    cout << "2.them\n";
    cout << "3.sua\n";
    cout << "4.xoa\n";
    cout << "5.sap xep\n";
    cout << "6.tim kiem\n";
    cout << "7.thong ke \n";
    cout << "8.sao luu\n";
    cout << "9.thoat\n";
    int select;
    do {
        cout << "nhap lenh:\n";
        cin >> select;
        switch (select) {
        case 1: {
            show(arr, number_of_people);
            break;
        }
        case 2: {
            add(arr, number_of_people);
            break;
        }
        case 3: {
            edit(arr);
            break;
        }
        case 4: {
            deleteinfor(arr, number_of_people);
            break;
        }
        case 5: {
            sort(arr, number_of_people);
            break;
        }
        case 6: {
            find(arr, number_of_people);
            break;
        }
        case 7: {
            statistical(arr, number_of_people);
            break;
        }
        case 8: {
            ofstream fileout;
            backup(fileout, arr, number_of_people);
            break;
        }
        case 9: {
            cout << "cam on\n";
            break;
        }
        }
    } while (select != 9);
    return 0;
}