#include <iostream>
#include <vector>
#include <string>
#include <ctime>
#include <cstdlib>

using namespace std;

int main()
{
    srand(static_cast<unsigned int>(time(0)));
    vector<int>::iterator penunjuk;
    vector< vector<string> > items{
        {"Pedang",  "8"},
        {"Panah",   "5"},
        {"Pisau",   "7"},
        {"Sniper",  "10"},
        {"Pistol",  "9"},
        {"Shotgun", "10"},
    };
    vector<int> inventory;

    int menu;
    int maksimun;
    int item;
    int hapus;

    cout << "Jumlah Items : " << items.size() << endl;
    cout << "Maksimal Inventory : ";
    cin >> maksimun;

    while(true){
        cout << "\n";
        cout << "Inventory System" << endl;
        cout << "1. Tampilkan Inventory" << endl;
        cout << "2. Hapus Item" << endl;
        cout << "3. Tambah Item" << endl;
        cout << "4. Keluar" << endl;
        cout << "Masukan Pilihan Anda : "; cin >> menu;

        item = 0;
        switch(menu){
            case 1 :
                if(!inventory.empty()){
                    for(penunjuk=inventory.begin(); penunjuk!=inventory.end(); penunjuk++){
                        cout << items[*penunjuk][0] << ", stat : " << items[*penunjuk][1] << endl;
                    }
                }else{
                    cout << ">> Inventory Kosong" << endl;
                }
                break;
            case 2 :
                if(!inventory.empty()){
                    int nomor = 1;
                    for(penunjuk=inventory.begin(); penunjuk!=inventory.end(); penunjuk++){
                        cout << nomor << ".  ";
                        cout << items[*penunjuk][0] << ", stat : " << items[*penunjuk][1] << endl;
                        nomor++;
                    }
                    cout << ">> Hapus Item Ke - : "; cin >> hapus;
                    if(hapus <= inventory.size() && hapus > 0){
                        inventory.erase(inventory.begin()+(hapus-1));
                        cout << ">> Jumlah Inventory Sekarang : " << inventory.size() << endl;
                    }else{
                        cout << "!!! Menu tidak tersedia" << endl;
                    }
                }else{
                    cout << ">> Inventory kosong" << endl;
                }
                break;
            case 3 :
                if(inventory.size() < maksimun){
                    item = rand() % items.size();
                    inventory.push_back(item);
                    cout << ">> Anda mendapat : " << items[item][0] << endl;
                    cout << ">> stat : " << items[item][1] << endl;
                    cout << ">> Jumlah inventory sekarang : " << inventory.size() << endl;
                }else{
                    cout << ">> Inventory Anda Penuh" << endl;
                }
                break;
            case 4 :
                return false;
                break;
            default :
                cout << "!!! Menu tidak tersedia" << endl;
                break;
        }

    }

    return 0;
}
