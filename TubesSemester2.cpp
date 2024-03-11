#include <iostream>
#include <string>
#include <iomanip>
using namespace std;

/* Nama   : Muhammad Azhar Rabbani
   NIM    : 4522210098
   Kelas  : A
   Materi : 1. Struktur
            2. Pointer
            3. ADT - SDL - Linear Single Linked List
            4. SDL - Stack
            5. Graph DFS
            6. Hash Table
*/

// Struct penyimpanan data pengguna
struct DataPelanggan_Azhar{
    string Nama_Azhar;
    int NoPelanggan_Azhar;
    string Alamat_Azhar;
    double KWH_Azhar;
    int Pemakaian_Azhar;
    int Tagihan_Azhar;
};

// Struct membuat Simpul Link Listed
struct Node_Azhar{
    DataPelanggan_Azhar Data_Azhar;
    Node_Azhar *LINK;
};
Node_Azhar *A, *FIRST, *LAST, *Z;

// Class Membuat Single Link Listed
class LinkListed_Azhar{
    private:
    Node_Azhar* head_Azhar; 

    public:
    LinkListed_Azhar(){
    head_Azhar = NULL;
    }

// Function Buat Simpul
void BuatSimpul_Azhar(string Nama_Azhar, int NoPelanggan_Azhar, string Alamat_Azhar, double KWH_Azhar, int Pemakaian_Azhar){
    A = new Node_Azhar;
    if(A != NULL)
    {
        A -> Data_Azhar.Nama_Azhar = Nama_Azhar;
        A -> Data_Azhar.NoPelanggan_Azhar = NoPelanggan_Azhar;
        A -> Data_Azhar.Alamat_Azhar = Alamat_Azhar;
        A -> Data_Azhar.KWH_Azhar = KWH_Azhar;
        A -> Data_Azhar.Pemakaian_Azhar = Pemakaian_Azhar;

        if(head_Azhar == NULL)
        {
            head_Azhar = A;
        }
        else
        {
            Node_Azhar* temp_Azhar = head_Azhar;
            while(temp_Azhar -> LINK != NULL)
            {
                temp_Azhar = temp_Azhar -> LINK;
            }
            temp_Azhar -> LINK = A;
        }
    }
    else
    {
        cout << "Pembuatan Simpul Gagal \n ";
        cin.get();
        exit(1);
    }
}

void Awal_Azhar(){
    FIRST = A;
    LAST = A;
    A -> LINK = NULL;
}

// Function Menambahkan data ke simpul
void INSERT_Azhar(){
    LAST -> LINK = A;
    LAST = A;
    A -> LINK = NULL;
}

// Function Mencetak Simpul
void CetakSimpulAzhar(){
    Node_Azhar* temp_Azhar = head_Azhar;
    cout << "|============================================| \n";
    cout << "|     DAFTAR PENGGUNA LISTRIK PANCASILA      | \n";
    cout << "|--------------------------------------------| \n";
    while (temp_Azhar != NULL)
    {
        cout << "| Nama             : " << temp_Azhar -> Data_Azhar.Nama_Azhar << "\t"<< setw(15) << " |\n";
        cout << "| ID               : " << temp_Azhar -> Data_Azhar.NoPelanggan_Azhar << setw(18) << "\t     |\n";
        cout << "| Alamat           : " << temp_Azhar -> Data_Azhar.Alamat_Azhar << "\t"<< setw(7) << " |\n";
        cout << "| KWH              : " << temp_Azhar -> Data_Azhar.KWH_Azhar << setw(21) << "\t     |\n";
        cout << "| Pemakaian (Hari) : " << temp_Azhar -> Data_Azhar.Pemakaian_Azhar << setw(21) << "\t     |\n";
        cout << "|--------------------------------------------| \n";
        temp_Azhar = temp_Azhar -> LINK;
    }
    cout << "\n\n";
}

//Function Mencari Data Pelanggan
void MencariPelanggan_Azhar(int NoPelanggan_Azhar){
    Node_Azhar* temp_Azhar = FIRST;
    int Bulan_Azhar = 1;
    while (temp_Azhar != NULL)
    {
        if (temp_Azhar -> Data_Azhar.NoPelanggan_Azhar == NoPelanggan_Azhar)
        {
            cout << "|====================================| \n";
            cout << "|        PELANGGAN DITEMUKAN         | \n";
            cout << "|====================================| \n";
            cout << "| Nama   : " << temp_Azhar -> Data_Azhar.Nama_Azhar << "\t"<< setw(15) << " |\n";
            cout << "| ID     : " << temp_Azhar -> Data_Azhar.NoPelanggan_Azhar << setw(25) << "\t     |\n";
            cout << "| Alamat : " << temp_Azhar -> Data_Azhar.Alamat_Azhar << "\t"<< setw(7) << "|\n";
            cout << "| KWH    : " << temp_Azhar -> Data_Azhar.KWH_Azhar << setw(21) << "\t     |\n";
            cout << "|====================================| \n";
            return;
        }
        temp_Azhar = temp_Azhar -> LINK;
    }
    cout << "Pelanggan dengan ID yang Dicari Tidak Ditemukan \n";
}



Node_Azhar* Akseshead_Azhar(){
    return head_Azhar;
}

}; 

// Struct Penyimpanan Data Pengguna dalam riwayat
struct RiwayatPemabayaran_Azhar{
    int NoPelanggan_Azhar;
    string Nama_Azhar;
    int Tagihan_Azhar;
    double KWH_Azhar;
    RiwayatPemabayaran_Azhar* LINK;
};

// Struct untuk membuat stack
struct Node_RiwayatPembayaran_Azhar{
    RiwayatPemabayaran_Azhar History_Azhar;
    Node_RiwayatPembayaran_Azhar* LINK;
};

// Class Membuat stack
class Stack_RiwayatPembayaran_Azhar{
    private:
    Node_RiwayatPembayaran_Azhar* top_Azhar;

    public:
    Stack_RiwayatPembayaran_Azhar(){
        top_Azhar = NULL;
    }

    bool ApakahKosong_Azhar(){
        return top_Azhar == NULL;
    }

    // Function memasukkan data ke dalam Stack
    void Push_Azhar(RiwayatPemabayaran_Azhar Histrory_Azhar){
        Node_RiwayatPembayaran_Azhar* newNode_Azhar = new Node_RiwayatPembayaran_Azhar;
        newNode_Azhar -> History_Azhar = Histrory_Azhar;
        newNode_Azhar -> LINK = top_Azhar;
        top_Azhar = newNode_Azhar;
    }

    // Function Menghapus data dalam stack
    void Pop_Azhar(){
        if (!ApakahKosong_Azhar())
        {
            Node_RiwayatPembayaran_Azhar* temp_Azhar = top_Azhar;
            top_Azhar = top_Azhar -> LINK;
            delete temp_Azhar;
        }
    }

    // Function Menghitung Tagihan
void Pembayaran_Azhar(int NoPelanggan_Azhar, Stack_RiwayatPembayaran_Azhar& Stack_RiwayatPembayaran_Azhar){
    char Penentu;
    int Bulan_Azhar = 1;
    cout << "             TAGIHAN LISTRIK \n";
    cout << "=========================================== \n";
    Node_Azhar* temp_Azhar = FIRST;
    while (temp_Azhar != NULL)
    {
    if (temp_Azhar -> Data_Azhar.NoPelanggan_Azhar == NoPelanggan_Azhar)
    { 
        while (temp_Azhar != NULL)
        {
            cout << "Nama             : " << temp_Azhar -> Data_Azhar.Nama_Azhar << endl;
            cout << "No               : " << temp_Azhar -> Data_Azhar.NoPelanggan_Azhar << endl;
            cout << "Alamat           : " << temp_Azhar -> Data_Azhar.Alamat_Azhar << endl;
            cout << "KWH              : " << temp_Azhar -> Data_Azhar.KWH_Azhar << endl;
            cout << "Pemakaian (Hari) : " << temp_Azhar -> Data_Azhar.Pemakaian_Azhar << endl;
            if (temp_Azhar -> Data_Azhar.KWH_Azhar > 0 && temp_Azhar -> Data_Azhar.KWH_Azhar <= 100)
            {
                Penentu = 'A';
            }
            else if (temp_Azhar -> Data_Azhar.KWH_Azhar > 100 && temp_Azhar -> Data_Azhar.KWH_Azhar <= 200)
            {
                Penentu = 'B';
            }
            else if (temp_Azhar -> Data_Azhar.KWH_Azhar > 200 && temp_Azhar -> Data_Azhar.KWH_Azhar <= 300)
            {
                Penentu = 'C';
            }
            else if (temp_Azhar -> Data_Azhar.KWH_Azhar > 300 && temp_Azhar -> Data_Azhar.KWH_Azhar <= 500)
            {
                Penentu = 'D';
            }
            else
            {
                Penentu = 'E';
            }
            cout << endl;
            int Tagihan_Azhar = 0;
            switch(Penentu)
            {
                case 'A' : Tagihan_Azhar = 20000 * temp_Azhar -> Data_Azhar.Pemakaian_Azhar;
                           break;

                case 'B' : Tagihan_Azhar = 30000 * temp_Azhar -> Data_Azhar.Pemakaian_Azhar;
                           break;

                case 'C' : Tagihan_Azhar = 50000 * temp_Azhar -> Data_Azhar.Pemakaian_Azhar;
                           break;

                case 'D' : Tagihan_Azhar = 80000 * temp_Azhar -> Data_Azhar.Pemakaian_Azhar;
                           break;

                case 'E' : Tagihan_Azhar = 150000 * temp_Azhar -> Data_Azhar.Pemakaian_Azhar;
                           break;
            } 
            cout << "Jumlah Tagihan yang Dibayar = Rp. " << Tagihan_Azhar << "\n\n\n";
            RiwayatPemabayaran_Azhar History_Azhar;
            History_Azhar.NoPelanggan_Azhar = temp_Azhar -> Data_Azhar.NoPelanggan_Azhar;
            History_Azhar.Nama_Azhar = temp_Azhar -> Data_Azhar.Nama_Azhar;
            History_Azhar.KWH_Azhar = temp_Azhar -> Data_Azhar.KWH_Azhar;
            temp_Azhar -> Data_Azhar.Tagihan_Azhar = Tagihan_Azhar;
            History_Azhar.Tagihan_Azhar = temp_Azhar -> Data_Azhar.Tagihan_Azhar;
            Stack_RiwayatPembayaran_Azhar.Push_Azhar(History_Azhar);
            return;
        } 
    }
        temp_Azhar = temp_Azhar -> LINK;
    }
    cout << "No Pelanggan Tidak ada \n\n";
}

    // Function Mencetak Stack
    void CetakStack_Azhar(){
        int Bulan_Azhar = 1;
        if (ApakahKosong_Azhar())
        {
            cout << "Riwayat Pemabayaran Kosong \n";
        }
        else
        {
            cout << endl;
            cout << "=============================================================================" << endl;
            cout << "|                          TAGIHAN PARA PELANGGAN                            |" << endl;
            cout << "-----------------------------------------------------------------------------" << endl;
            Node_RiwayatPembayaran_Azhar* current_Azhar = top_Azhar;
            while (current_Azhar != NULL)
            {
                if (current_Azhar -> History_Azhar.NoPelanggan_Azhar != 0 && !current_Azhar -> History_Azhar.Nama_Azhar.empty())
                {
                    cout << "| No Pelanggan : " << current_Azhar -> History_Azhar.NoPelanggan_Azhar << setw(58) << "\t    |\n";
                    cout << "| Nama         : " << current_Azhar -> History_Azhar.Nama_Azhar << "\t"<< setw(54) << " |\n";
                    cout << "| KWH          : " << current_Azhar -> History_Azhar.KWH_Azhar << setw(58) << "\t    |\n";
                    cout << "| Tagihan      : Rp. " << current_Azhar -> History_Azhar.Tagihan_Azhar << setw(50) << "\t    |\n";
                    cout << "|---------------------------------------------------------------------------|  \n";
                }
                DataPelanggan_Azhar Data;
                current_Azhar = current_Azhar -> LINK;
            }
        }
    }
};

const int TABLESIZE_Azhar = 100;

struct Pelanggan_Azhar{
    string Nama_Azhar;
    int NOPelanggan_Azhar;
    string Alamat_Azhar;
    double KWH_Azhar;
    int Pemakaian_Azhar;
    int Tagihan_Azhar;
};

struct HashNode_Azhar{
    Pelanggan_Azhar DataHash_Azhar;
    HashNode_Azhar* LINK;
};

class HashTable_Azhar{
    private:
    HashNode_Azhar* Table_Azhar[TABLESIZE_Azhar];

    public:
    HashTable_Azhar(){
        for (int i = 0; i < TABLESIZE_Azhar; i++)
        {
            Table_Azhar[i] = NULL;
        }
    }

    // Function Menghitung Hash Value 
    int HashFunction_Azhar(int NoPelanggan_Azhar){
        return NoPelanggan_Azhar % TABLESIZE_Azhar;
    }

    void TambahPelanggan_Azhar(const Pelanggan_Azhar& pelanggan_Azhar){
        int hashValue_Azhar = pelanggan_Azhar.NOPelanggan_Azhar % TABLESIZE_Azhar;

        //Membuat Simpul Baru
        HashNode_Azhar* newNode_Azhar = new HashNode_Azhar;
        newNode_Azhar -> DataHash_Azhar = pelanggan_Azhar;
        newNode_Azhar -> LINK = NULL;

        //Jika Slot Pada Hash Table Masih Kosong
        if (Table_Azhar[hashValue_Azhar] == NULL)
        {
            Table_Azhar[hashValue_Azhar] = newNode_Azhar;
        }
        else
        {
            HashNode_Azhar* temp_Azhar = Table_Azhar[hashValue_Azhar];
            while (temp_Azhar -> LINK != NULL)
            {
                temp_Azhar = temp_Azhar -> LINK;
            }
            temp_Azhar = temp_Azhar -> LINK;
        }
        //cout << "Pelanggan Ditambahkan \n";
    }

    void ClearHash_Azhar(){
        for (int i = 0; i < TABLESIZE_Azhar; i++)
        {
            Table_Azhar[i] = NULL;
        }
        cout << "Data Sudah Di Hapus \n";
    }

    // Function Menampilkan Semua Pelanggan Yang Tersimpan Di Dalam Hash Table
    void Display_Azhar(){
        cout << "=============================================================================" << endl;
        cout << "|              DAFTAR TAGIHAN PARA PELANGGAN LISTRIK PANCASILA              |" << endl;
        cout << "-----------------------------------------------------------------------------" << endl;

        for (int i = 0; i < TABLESIZE_Azhar; i++)
        {
            if (Table_Azhar[i] != NULL)
            {
                HashNode_Azhar* temp_Azhar = Table_Azhar[i];

                while (temp_Azhar != NULL)
                {
                    cout << "| Nama      : " << temp_Azhar -> DataHash_Azhar.Nama_Azhar << "\t"<< setw(54) << " |\n";
                    cout << "| No        : " << temp_Azhar -> DataHash_Azhar.NOPelanggan_Azhar << setw(58) << "\t    |\n";
                    cout << "| Alamat    : " << temp_Azhar -> DataHash_Azhar.Alamat_Azhar << "\t"<< setw(46) << "|\n";
                    cout << "| KWH       : " << temp_Azhar -> DataHash_Azhar.KWH_Azhar << setw(58) << "\t    |\n";
                    cout << "| Pemakaian : " << temp_Azhar -> DataHash_Azhar.Pemakaian_Azhar << setw(58) << "\t    |\n";
                    cout << "| Tagihan   : " << temp_Azhar -> DataHash_Azhar.Tagihan_Azhar << setw(55) << "\t    |\n";
                    temp_Azhar = temp_Azhar -> LINK;
                }
                cout << "|---------------------------------------------------------------------------|" << endl;
            }
        }
        cout << "|===========================================================================|" << endl;
    }

};



// Function GraphDFS untuk melakukan pencarian KWH Dengan Data yang tersimpan
void GraphDFS_Azhar(Node_Azhar* node_Azhar, double TargetKWH_Azhar){
    if (node_Azhar == NULL)
    {
        return;
    }
    // RiwayatPemabayaran_Azhar History_Azhar;
    if (node_Azhar -> Data_Azhar.KWH_Azhar == TargetKWH_Azhar)
    {   
        cout << "| Nama           : " << node_Azhar -> Data_Azhar.Nama_Azhar << "\t"<< setw(15) << " |\n";
        cout << "| No Pelanggan   : " << node_Azhar -> Data_Azhar.NoPelanggan_Azhar << setw(25) << "\t     |\n";
        cout << "| Alamat         : " << node_Azhar -> Data_Azhar.Alamat_Azhar << "\t"<< setw(7) << "|\n";
        cout << "| KWH            : " << node_Azhar -> Data_Azhar.KWH_Azhar << setw(21) << "\t     |\n";
        cout << "|--------------------------------------------- \n";
        
    }
    GraphDFS_Azhar(node_Azhar -> LINK, TargetKWH_Azhar);
}




int main(){
    LinkListed_Azhar Data_Azhar;
    Stack_RiwayatPembayaran_Azhar riwayatPembayaran_StackAzhar;
    RiwayatPemabayaran_Azhar History_Azhar;
    HashTable_Azhar hashTable_Azhar;
    int NoPelanggan_Azhar;

    cout << endl;
    cout << endl;

    // Single Linked List
    Data_Azhar.BuatSimpul_Azhar("Azhar ", 12 , "JL. Olahraga 1 ", 250, 30 );
    Data_Azhar.Awal_Azhar();
    Data_Azhar.INSERT_Azhar();
    Data_Azhar.BuatSimpul_Azhar("Yeza ", 3, "JL. Tembalang ", 250, 30);
    Data_Azhar.INSERT_Azhar();
    Data_Azhar.BuatSimpul_Azhar("Fadil ", 18, "Jl. Kumbang ", 400, 30);
    Data_Azhar.INSERT_Azhar();
    Data_Azhar.BuatSimpul_Azhar("Dinar ", 4, "Jl. Olahraga 2 ", 300, 30);
    Data_Azhar.INSERT_Azhar();
    Data_Azhar.BuatSimpul_Azhar("Isak ", 10, "Lebak Bulus ", 500, 30);
    Data_Azhar.INSERT_Azhar();
    Data_Azhar.CetakSimpulAzhar();
    cout << "Pencarian Pelanggan Dengan ID \n";
    cout << "======================================= \n";
    Data_Azhar.MencariPelanggan_Azhar(12);
    cout << endl;

    // Stack 
    History_Azhar.NoPelanggan_Azhar = 0;
    History_Azhar.Nama_Azhar = "";
    History_Azhar.Tagihan_Azhar = 0;
    riwayatPembayaran_StackAzhar.Push_Azhar(History_Azhar);                     
    riwayatPembayaran_StackAzhar.Pembayaran_Azhar(12, riwayatPembayaran_StackAzhar);
    //riwayatPembayaran_StackAzhar.Pop_Azhar(); // Function Menghapus Data di dalam Stack
    riwayatPembayaran_StackAzhar.Push_Azhar(History_Azhar);
    riwayatPembayaran_StackAzhar.Pembayaran_Azhar(3, riwayatPembayaran_StackAzhar);
    riwayatPembayaran_StackAzhar.Push_Azhar(History_Azhar);
    riwayatPembayaran_StackAzhar.Pembayaran_Azhar(18, riwayatPembayaran_StackAzhar);
    riwayatPembayaran_StackAzhar.Push_Azhar(History_Azhar);
    riwayatPembayaran_StackAzhar.Pembayaran_Azhar(4, riwayatPembayaran_StackAzhar);
    riwayatPembayaran_StackAzhar.Push_Azhar(History_Azhar);
    riwayatPembayaran_StackAzhar.Pembayaran_Azhar(10, riwayatPembayaran_StackAzhar);
    riwayatPembayaran_StackAzhar.CetakStack_Azhar();
    cout << "\n\n";
    Node_Azhar* Head_Azhar = Data_Azhar.Akseshead_Azhar();
    Node_Azhar* temp_Azhar = Head_Azhar;

    // Graph DFS
    int TargetKWH_Azhar = 300;
    if (TargetKWH_Azhar == TargetKWH_Azhar)
    cout << "DAFTAR PELANGGAN YANG MEMILIKI KWH = " << TargetKWH_Azhar << endl;
    cout << "============================================= \n";
    GraphDFS_Azhar(FIRST, TargetKWH_Azhar);
    cout << endl;

    // Hash Table
    while (temp_Azhar != NULL)
    {
        Pelanggan_Azhar pelanggan_Azhar;
        pelanggan_Azhar.Nama_Azhar = temp_Azhar -> Data_Azhar.Nama_Azhar;
        pelanggan_Azhar.NOPelanggan_Azhar = temp_Azhar -> Data_Azhar.NoPelanggan_Azhar;
        pelanggan_Azhar.Alamat_Azhar = temp_Azhar -> Data_Azhar.Alamat_Azhar;
        pelanggan_Azhar.KWH_Azhar = temp_Azhar -> Data_Azhar.KWH_Azhar;
        pelanggan_Azhar.Pemakaian_Azhar = temp_Azhar -> Data_Azhar.Pemakaian_Azhar;
        pelanggan_Azhar.Tagihan_Azhar = temp_Azhar -> Data_Azhar.Tagihan_Azhar;
        hashTable_Azhar.TambahPelanggan_Azhar(pelanggan_Azhar);
        temp_Azhar = temp_Azhar -> LINK;
    }
    cout << endl;
    // hashTable_Azhar.ClearHash_Azhar(); // Function Menghapus Data
    hashTable_Azhar.Display_Azhar();
    return 0; 
}