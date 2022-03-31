/*EL2208 Praktikum Pemecahan Masalah dengan C 2021/2022
*Modul            : 6 - Linked List
*Percobaan        : 1
*Hari dan Tanggal : Kamis, 31 Maret 2022
*Nama (NIM)       : Eraraya Morenzo Muten (18320003)
*Asisten (NIM)    : Agape D'sky (13219010)
*Nama File        : soal-01.c
*Deskripsi        : Program akan menerima tiga input urutan angka
*                   dari paling kecil, membuat tiga linked list dari
*                   urutan tersebut, kemudian menampilkan satu linked
*                   list gabungan dari tiga linked list input secara
*                   terurut dari paling kecil.
*/

#include<stdio.h>
#include<stdlib.h>
  
//Struct Node Linked List
struct Node {
	int data;
	struct Node* next;
} Node;

/*
* fungsi untuk menambah data ke dalam linked list
*
* @param head: pointer to pointer to head node ke linked list
* @param element: integer data node baru
*/
void add(struct Node **head, int element);

int main()
{
    int n;  // jumlah elemen list
    int i;  // variabel iterasi
    int e;  // variabel nilai elemen (data)
    
    // Membuat node sementara untuk membebaskan alokasi memori
    struct Node* temp;
    
    // Membuat linked list
    struct Node* head1 = NULL;
    struct Node* head2 = NULL;
    struct Node* head3 = NULL;
    int data1, data2, data3;
    
    //input linked list pertama
    printf("Masukkan jumlah elemen linked list pertama: ");
    scanf("%d", &n);
    
    // Menerima input elemen dan membuat linked list pertama
    printf("Masukkan elemen-elemen linked list pertama: ");
    for(i=0; i<n; ++i){
        scanf("%d", &e);
        add(&head1, e);
    }
	
    //input linked list kedua
    printf("Masukkan jumlah elemen linked list kedua: ");
    scanf("%d", &n);
	
    // Menerima input elemen dan membuat linked list kedua
    printf("Masukkan elemen-elemen linked list kedua: ");
    for(i=0; i<n; ++i){
        scanf("%d", &e);
        add(&head2, e);
    }
	
    //input linked list ketiga
    printf("Masukkan jumlah elemen linked list ketiga: ");
    scanf("%d", &n);
	
    // Menerima input elemen dan membuat linked list ketiga
    printf("Masukkan elemen-elemen linked list ketiga: ");
    for(i=0; i<n; ++i){
        scanf("%d", &e);
        add(&head3, e);
    }
    
	//Cetak output berupa urutan integer hingga akhir semua linked list
	printf("\nHasil urutan gabungan ketiga linked list: ");
    while((head1!=NULL)||(head2!=NULL)||(head3!=NULL)){
        // Mengambil data linked list pertama
        if(head1!=NULL){
            data1 = head1->data;
        // Jika sudah sampai akhir, assign dengan nilai INT_MAX agar tidak terpilih
        } else{
            data1 = 0x7FFFFFFF;
        }
        
        // Mengambil data linked list kedua
        if(head2!=NULL){
            data2 = head2->data;
        // Jika sudah sampai akhir, assign dengan nilai INT_MAX agar tidak terpilih
        } else{
            data2 = 0x7FFFFFFF;
        }
        
        // Mengambil data linked list ketiga
        if(head3!=NULL){
            data3 = head3->data;
        // Jika sudah sampai akhir, assign dengan nilai INT_MAX agar tidak terpilih
        } else{
            data3 = 0x7FFFFFFF;
        }
        
        // Jika data linked list pertama paling kecil,
        // tampilkan data dan lanjut node berikutnya
        if((data1<=data2)&&(data1<=data3)){
            printf("%d ", data1);
            
            // Membuat pointer yang menunjuk alamat memori head
            temp = head1;
            
            // Memindahkan head ke node berikutnya
            head1 = head1->next;
            
            // Menghapus alokasi memori head sebelumnya
            free(temp);
            
        // Jika data linked list kedua paling kecil,
        // tampilkan data dan lanjut node berikutnya
        } else if((data2<=data1)&&(data2<=data3)){
            printf("%d ", data2);
            
            // Membuat pointer yang menunjuk alamat memori head
            temp = head2;
            
            // Memindahkan head ke node berikutnya
            head2 = head2->next;
            
            // Menghapus alokasi memori head sebelumnya
            free(temp);
            
        // Jika data linked list ketiga paling kecil,
        // tampilkan data dan lanjut node berikutnya
        } else if((data3<=data1)&&(data3<=data2)){
            printf("%d ", data3);
            
            // Membuat pointer yang menunjuk alamat memori head
            temp = head3;
            
            // Memindahkan head ke node berikutnya
            head3 = head3->next;
            
            // Menghapus alokasi memori head sebelumnya
            free(temp);
        }
    }
	printf("\n");

	return 0;
}

void add(struct Node **head, int element){
    // Mengalokasikan memori node baru
    struct Node* new = (struct Node*) malloc(sizeof(struct Node));
    
    // Mengisi node baru
    new->data = element;
    new->next = NULL; 
    
    // Jika head kosong, assign new sebagai head
    if((*head)==NULL){
        (*head) = new;
    } else{
        // Membuat struct sementara untuk menyusuri linked list
        struct Node* temp = *head;
        
        // Menyusuri linked list hingga node terakhir
        while(temp->next!=NULL){
            temp = temp->next;
        }
        
        // Menghubungkan node terakhir dengan node baru
        temp->next = new;
    }
    
    return;
}