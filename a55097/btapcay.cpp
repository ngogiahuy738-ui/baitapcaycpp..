
#include <iostream>
#include <cstring>
using namespace std;

struct Node {
    int id;
    char content[100];
    int isLeaf;
    Node *left;
    Node *right;
};

Node* taoNut(int id, const char content[], int isLeaf) {
    Node *p = new Node;

    p->id = id;
    strcpy(p->content, content);
    p->isLeaf = isLeaf;
    p->left = NULL;
    p->right = NULL;

    return p;
}
Node* khoiTao() {
    Node *root = taoNut(1, "DTB < 2.0?", 0);

    root->left = taoNut(2, "No >= 12 tin chi?", 0);
    root->right = taoNut(3, "DTB >= 3.2?", 0);

    root->left->left =
        taoNut(4, "Canh bao muc 2", 1);

    root->left->right =
        taoNut(5, "Canh bao muc 1", 1);

    root->right->left =
        taoNut(6, "Khen thuong", 1);

    root->right->right =
        taoNut(7, "Theo doi binh thuong", 1);

    return root;
}

void tienTu(Node *p) {
    if (p == NULL)
        return;

    cout << p->id << " - " << p->content << endl;

    tienTu(p->left);
    tienTu(p->right);
}

void trungTu(Node *p) {
    if (p == NULL)
        return;

    trungTu(p->left);

    cout << p->id << " - " << p->content << endl;

    trungTu(p->right);
}

void hauTu(Node *p) {
    if (p == NULL)
        return;

    hauTu(p->left);
    hauTu(p->right);

    cout << p->id << " - " << p->content << endl;
}

Node* timNut(Node *p, int id) {
    if (p == NULL)
        return NULL;

    if (p->id == id)
        return p;

    Node *kq = timNut(p->left, id);

    if (kq != NULL)
        return kq;

    return timNut(p->right, id);
}

int chieuCao(Node *p) {
    if (p == NULL)
        return 0;

    int trai = chieuCao(p->left);
    int phai = chieuCao(p->right);

    if (trai > phai)
        return trai + 1;

    return phai + 1;
}
int demNutLa(Node *p) {
    if (p == NULL)
        return 0;

    if (p->left == NULL && p->right == NULL)
        return 1;

    return demNutLa(p->left)
         + demNutLa(p->right);
}

void tuVan(Node *p) {
    char chon;

    while (p != NULL && p->isLeaf == 0) {
        cout << p->content << endl;
        cout << "Nhap y neu Co, n neu Khong: ";
        cin >> chon;

        if (chon == 'y' || chon == 'Y') {
            p = p->left;
        }
        else if (chon == 'n' || chon == 'N') {
            p = p->right;
        }
        else {
            cout << "Chi nhap y hoac n!" << endl;
        }
    }

    if (p != NULL)
        cout << "Ket luan: " << p->content << endl;
}

void giaiPhong(Node *p) {
    if (p == NULL)
        return;

    giaiPhong(p->left);
    giaiPhong(p->right);

    delete p;
}

int main() {
    Node *root = NULL;
    Node *p;

    int chon, id;

    do {
        cout << "\n========== MENU ==========" << endl;
        cout << "1. Khoi tao cay mau" << endl;
        cout << "2. Duyet tien tu" << endl;
        cout << "3. Duyet trung tu" << endl;
        cout << "4. Duyet hau tu" << endl;
        cout << "5. Tim nut theo ID" << endl;
        cout << "6. Tinh chieu cao cay" << endl;
        cout << "7. Dem nut la" << endl;
        cout << "8. Tu van hoc vu" << endl;
        cout << "0. Thoat" << endl;
        cout << "Nhap lua chon: ";
        cin >> chon;

        switch (chon) {
            case 1:
                if (root != NULL)
                    giaiPhong(root);

                root = khoiTao();
                cout << "Khoi tao cay thanh cong!" << endl;
                break;

            case 2:
                if (root == NULL)
                    cout << "Hay khoi tao cay truoc!" << endl;
                else {
                    cout << "Duyet tien tu:" << endl;
                    tienTu(root);
                }
                break;

            case 3:
                if (root == NULL)
                    cout << "Hay khoi tao cay truoc!" << endl;
                else {
                    cout << "Duyet trung tu:" << endl;
                    trungTu(root);
                }
                break;

            case 4:
                if (root == NULL)
                    cout << "Hay khoi tao cay truoc!" << endl;
                else {
                    cout << "Duyet hau tu:" << endl;
                    hauTu(root);
                }
                break;

            case 5:
                if (root == NULL) {
                    cout << "Hay khoi tao cay truoc!" << endl;
                    break;
                }

                cout << "Nhap ID can tim: ";
                cin >> id;

                p = timNut(root, id);

                if (p == NULL)
                    cout << "Khong tim thay nut!" << endl;
                else
                    cout << "Tim thay: " << p->content << endl;

                break;

            case 6:
                if (root == NULL)
                    cout << "Hay khoi tao cay truoc!" << endl;
                else
                    cout << "Chieu cao cay: "
                         << chieuCao(root) << " muc" << endl;
                break;

            case 7:
                if (root == NULL)
                    cout << "Hay khoi tao cay truoc!" << endl;
                else
                    cout << "So nut la: "
                         << demNutLa(root) << endl;
                break;

            case 8:
                if (root == NULL)
                    cout << "Hay khoi tao cay truoc!" << endl;
                else
                    tuVan(root);
                break;

            case 0:
                giaiPhong(root);
                root = NULL;
                cout << "Ket thuc chuong trinh!" << endl;
                break;

            default:
                cout << "Lua chon khong hop le!" << endl;
        }

    } while (chon != 0);

    return 0;
}
