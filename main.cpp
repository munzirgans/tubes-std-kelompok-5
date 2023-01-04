#include "tubes.h"

int main()
{
    cout << "----------[ TUBES STD KELOMPOK 5 MLL N TO N]----------" << endl;
    cout << "Nama\t\t: Muhammad Munzir & Fakhran Al-anshari" << endl;
    cout << "NIM\t\t: 1301213167 & 1301213021" << endl;
    cout << "Kelas\t\t: IF-45-02" << endl;
    cout << "Studi Kasus\t: Setiap user dapat memiliki kartu operator maksimal 3" << endl;
    cout << "------------[ Data Operator di Indonesia ]------------" << endl << endl;
    ListOperator L1;
    ListUser L2;
    adr_user p;
    adr_operator q;
    infotype_operator x;
    infotype_user y;
    int n = 0;
    createListOperator(L1);
    createListUser(L2);
    cout << "Berapa data operator yang ingin diinput?: ";
    cin >> n;
    for(int i = 0; i < n; i++){
        cout << "Data ke-" << i+1 << ":" << endl;
        cout << "Nama Operator\t: ";
        cin >> x;
        q = createElmOperator(x);
        insertOperator(L1, q);
    }
    cout << endl;
    cout << "Berapa data user yang ingin diinput?: ";
    cin >> n;
    for(int idx = 0; idx < n; idx++){
        cout << "Data ke-" << idx+1 << ":" << endl;
        cout << "NIK\t\t:";
        cin >> y.nik;
        cout << "Nama\t\t:";
        cin >> y.nama;
        cout << "Nomor HP\t:";
        cin >> y.nomorHP;
        p = createElmUser(y);
        insertUser(L2, p);
    }
    cout << endl << endl;
    showAllOperator(L1);
    cout << endl;
    cout << "---[ DATA USER SEBELUM DITAMBAHKAN DATA OPERATOR ]---" << endl << endl;
    showAllUserWithOperator(L2);
    cout << endl;

    cout << "---[ DATA USER SETELAH DITAMBAHKAN DATA OPERATOR ]---" << endl << endl;
    addOperator(L2,L1,"3175041612030008", "Telkomsel");
    addOperator(L2,L1,"3175041612030008", "Smartfren");
    addOperator(L2,L1,"3175041612030008", "XL");
    addOperator(L2,L1,"1310021001020002", "Indosat");
    addOperator(L2,L1,"1310021001020002", "Three");
    addOperator(L2,L1,"3576447103910003", "Smartfren");
    addOperator(L2,L1,"3576447103910003", "Telkomsel");
    addOperator(L2,L1,"3576447103910003", "XL");
    addOperator(L2,L1,"0167976544336836", "Indosat");
    addOperator(L2,L1,"3202080504910003", "Indosat");
    addOperator(L2,L1,"3202080504910003", "Telkomsel");
    addOperator(L2,L1,"3202080504910003", "Telkomsel");
    showAllUserWithOperator(L2);
    cout << endl;

    cout << "---[ DATA USER SETELAH DIHAPUS BEBERAPA KARTU OPERATORNYA ]---" << endl << endl;
    cout << "Data user dengan operatornya yang akan dihapus:" << endl;
    cout << "Muhammad Munzir\t\t: Telkomsel, XL" << endl;
    cout << "Fakhran Al-Anshari\t: Three" << endl;
    cout << "Mc Gregor\t\t: Smartfren" << endl;
    cout << "Sudjiwo Tejo\t\t: Indosat" << endl;
    cout << "Bambang Pamungkas\t: Telkomsel, Telkomsel" << endl;
    cout << endl;
    delOperatorUser(L2, L1, "3175041612030008", "Telkomsel");
    delOperatorUser(L2, L1, "3175041612030008", "XL");
    delOperatorUser(L2, L1, "1310021001020002", "Three");
    delOperatorUser(L2, L1, "3576447103910003", "Smartfren");
    delOperatorUser(L2, L1, "0167976544336836", "Indosat");
    delOperatorUser(L2, L1, "3202080504910003", "Telkomsel");
    delOperatorUser(L2, L1, "3202080504910003", "Telkomsel");
    showAllUserWithOperator(L2);
    cout << endl;

    cout << "---[ DATA USER & OPERATOR SETELAH DATA OPERATOR DIHAPUS ]---" << endl << endl;
    cout << "Operator yang akan dihapus:" << endl;
    cout << "1. Indosat" << endl;
    cout << "2. XL" << endl << endl;
    delOperator(L1, L2, "Indosat");
    delOperator(L1, L2, "XL");
    showAllUserWithOperator(L2);
    cout << endl;
    showAllOperator(L1);
    return 0;
}
