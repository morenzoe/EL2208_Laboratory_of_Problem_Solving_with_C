/*EL2208 Praktikum Pemecahan Masalah dengan C 2021/2022
*Modul            : 6 - Linked List
*Percobaan        : TP
*Hari dan Tanggal : Kamis, 31 Maret 2022
*Nama (NIM)       : Eraraya Morenzo Muten (18320003)
*Asisten (NIM)    : Agape D'sky (13219010)
*Nama File        : linkedListOps.c
*Deskripsi        : 
*					
*					
*/

#include <stdio.h>
#include <stdlib.h>

typedef struct Node{
    int nim;
    int nilai;
    struct Node* next;
}Node;

/*
* fungsi untuk menambah data ke dalam linked list
**
@param head: pointer to pointer to head node ke linked list
* @param nim: NIM mahasiswa
* @param nilai: nilai mahasiswa
*/
void add(Node **head, int nim, int nilai);
/*
* fungsi untuk mencetak data dari linked list
**
@param head: pointer to head node ke linked list
*/
void print(Node* head);
/*
* fungsi untuk mencari data nilai tertinggi dari linked list kemudian mencetak
nilainya
**
@param head: pointer to head node ke linked list
*/
void searchMax(Node* head);
/*
* fungsi untuk mencari data nilai terendah dari linked list kemudian mencetak
nilainya
**
@param head: pointer to head node ke linked list
*/
void searchMin(Node* head);

int main()
{
    Node* head = NULL;
    add(&head, 10018001,90);
    printf("%d", head->nim);
    /*
    add(&head, 10018002,80);
    add(&head, 10018003,68);
    add(&head, 10018004,89);
    add(&head, 10018005,92);
    add(&head, 10018006,80);
    print(head);
    searchMax(head);
    searchMin(head);
    */
    free(head);
    return 0;
}

void add(Node** head, int nim, int nilai){
    // Mengalokasikan memori
    struct Node* temp = (struct Node*) malloc(sizeof(struct Node));
    
    // Mengisi node baru
    temp->nim = nim;
    temp->nilai = nilai;
    temp->next = NULL;
    
    // Memasukkan elemen pertama
    if(*head == NULL){
        printf("null\n");
        *head = temp;
    }
    //free(temp);
}
/*
void print(Node* head){
}

void searchMax(Node* head){
}

void searchMin(Node* head){
}
*/