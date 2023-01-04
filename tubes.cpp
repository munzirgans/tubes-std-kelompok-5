#include "tubes.h"

void createListUser(ListUser &L){
    first(L) = nil;
}

void createListOperator(ListOperator &L){
    first(L) = nil;
}

adr_user createElmUser(infotype_user x){
    adr_user p = new elmUser;
    info(p).nik = x.nik;
    info(p).nama = x.nama;
    info(p).nomorHP = x.nomorHP;
    next(p) = nil;
    Operator(p) = nil;
    return p;
}

adr_operator createElmOperator(infotype_operator x){
    adr_operator q = new elmOperator;
    info(q) = x;
    next(q) = nil;
    return q;
}

adr_user searchUser(ListUser L, string nik){
    adr_user p = first(L);
    while(p != nil && info(p).nik != nik){
        p = next(p);
    }
    return p;
}

adr_operator searchOperator(ListOperator L, string namaOP){
    adr_operator p = first(L);
    while(p != nil && info(p) != namaOP){
        p = next(p);
    }
    return p;
}

void insertUser(ListUser &L, adr_user p){
    if(first(L) == nil){
        first(L) = p;
    }else{
        adr_user a = first(L);
        while(next(a) != nil){
            a = next(a);
        }
        next(a) = p;
    }
}

void insertOperator(ListOperator &L, adr_operator p){
    if(first(L) == nil){
        first(L) = p;
    }else{
        adr_operator a = first(L);
        while(next(a) != nil){
            a = next(a);
        }
        next(a) = p;
    }
}

void addOperator(ListUser L, ListOperator L2, string nik, string namaOP){
    adr_operator q = searchOperator(L2, namaOP);
    if(q == nil){
        cout << "Data operator tidak dapat ditemukan. Harap input data operator" << endl;
    }else{
        adr_user p = searchUser(L, nik);
        if(p == nil){
            cout << "Data user tidak dapat ditemukan. Harap input data user" << endl;
        }else{
            adr_operator r = Operator(p);
            if(r == nil){
                adr_operator s = createElmOperator(info(q));
                Operator(p) = s;
            }else{
                int i = 1;
                while(next(r) != nil){
                    r = next(r);
                    i++;
                }
                if(i == 3){
                    cout << "Tidak dapat menambah data kartu operator karena telah melibihi batas maksimal" << endl;
                }else{
                    adr_operator s = createElmOperator(info(q));
                    next(r) = s;
                }
            }
        }
    }
}

void delOperatorUser(ListUser L, ListOperator L2, string nik, string namaOP){
    adr_operator p = searchOperator(L2, namaOP);
    if(p == nil){
        cout << "Data operator tidak dapat ditemukan" << endl;
    }else{
        adr_user q = searchUser(L, nik);
        if(q == nil){
            cout << "Data user tidak dapat ditemukan" << endl;
        }else{
            adr_operator r = Operator(q);
            while(r != nil && info(r) != namaOP){
                r = next(r);
            }
            if(r == nil){
                cout << "Data operator tidak dapat ditemukan dalam user " << info(q).nama << endl;
            }else{
                if(r == Operator(q)){
                    Operator(q) = next(r);
                }else{
                    adr_operator prec = Operator(q);
                    while(next(prec) != r){
                        prec = next(prec);
                    }
                    adr_operator s = next(r);
                    next(prec) = s;
                }
            }
        }
    }
}

void showAllOperator(ListOperator L){
    if(first(L) == nil){
        cout << "Data operator kosong!" << endl;
    }else{
        int i = 0;
        cout << "DATA OPERATOR:" << endl;
        adr_operator a = first(L);
        while(a != nil){
            cout << i + 1 << ". " << info(a) << endl;
            a = next(a);
            i++;
        }
    }
}

void showAllUserWithOperator(ListUser L){
    if(first(L) == nil){
        cout << "Data user kosong!" << endl;
    }else{
        int i = 0;
        cout << "DATA USER:" << endl;
        adr_user a = first(L);
        while(a != nil){
            cout << "Data ke-" << i + 1 << ": " << endl;
            cout << "NIK\t\t: " << info(a).nik << endl;
            cout << "Nama\t\t: " << info(a).nama << endl;
            cout << "Nomor HP\t: " << info(a).nomorHP << endl;
            cout << "Kartu Operator\t: ";
            adr_operator b = Operator(a);
            if(b == nil){
                cout << "User ini tidak memiliki kartu operator" << endl;
            }else{
                string operators = "";
                while(b != nil){
                    operators += info(b) + ", ";
                    b = next(b);
                }
                int total = 0;
                for(int i = 0; i < operators.size();i++){
                    total++;
                }
                cout << operators.substr(0, total - 2) << endl;
            }
            cout << endl;
            a = next(a);
            i++;
        }
    }
}

void delOperator(ListOperator &L, ListUser &L2, string namaOP){
    adr_operator p = searchOperator(L, namaOP);
    if(p == nil){
        cout << "Data operator tidak dapat ditemukan" << endl;
    }else{
        adr_user q = first(L2);
        while(q != nil){
            bool stat = false;
            adr_operator r = Operator(q);
            adr_operator z = Operator(q);
            while(r != nil){
                if(info(r) == namaOP){
                    if(r == z){
                        if(next(r) == nil){
                            Operator(q) = nil;
                        }else{
                            Operator(q) = next(r);
                        }
                    }else{
                        adr_operator s = Operator(q);
                        while(next(s) != r){
                            s = next(s);
                        }
                        adr_operator t = next(r);
                        next(s) = t;
                    }
                }
                r = next(r);
            }
            q = next(q);
        }
        if(p == first(L)){
            if(next(p) == nil){
                first(L) = nil;
                next(p) = nil;
            }else{
                first(L) = next(p);
                next(p) = nil;
            }
        }else{
            adr_operator u = first(L);
            while(next(u) != p){
                u = next(u);
            }
            adr_operator v = next(p);
            next(u) = v;
            next(p) = nil;
        }
    }
}
