/** EL2208 Praktikum Pemecahan Masalah dengan C 2021/2022
*   Modul               : 2
*   Percobaan           : Tugas Pendahuluan
*   Hari dan Tanggal    : Kamis, 24 Februari 2022
*   Nama (NIM)          : Eraraya Morenzo Muten (18320003)
*   Asisten (NIM)       : Syifa Kushirayati (18319037)
*   Nama File           : item_price.c
*   Deskripsi           : Program membaca data barang yaitu
*                         nama, harga, dan jumlah dari suatu
*                         file. Program kemudian akan 
*                         menampilkan data suatu barang yang
*                         dicari oleh pengguna. Input nama 
*                         oleh pengguna dianggap benar.
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define maxLen 255 // 8-bit

int main(){
	// Deklarasi variabel
	char item[maxLen][maxLen];	// array nama barang
	int amount[maxLen];			// array jumlah barang
	int price[maxLen];			// array harga barang
	char fileLine[maxLen];		// string baris file
	char *token;				// pointer token
	int i, j = 0;				// variabel iterasi
	char search[maxLen];		// kata kunci pencarian
	int found = 0;				// boolean pencarian
	
	// Membuka file
	FILE *file = fopen("barang.txt", "r");
	
	// Membaca file dan menyimpan data pada array yang sesuai
	while(fgets(fileLine, maxLen, file)) {
		// Membaca suatu baris sampai koma untuk menyimpan nama barang
        token = strtok(fileLine, ", ");
		strcpy(item[i], token);
		// Membaca baris yang sama sampai koma untuk menyimpan jumlah barang
		token = strtok(NULL, ", ");
		amount[i] = atoi(token);
		// Membaca baris yang sama sampai akhir baris untuk menyimpan harga barang
		token = strtok(NULL, "\n");
		price[i] = atoi(token);
		// Menambah iterasi
		++i;
	}
	
	// Menutup file
	fclose(file);
	
	// Variabel i sekarang bernilai sejumlah baris pada file
	
	// Meminta input pencarian barang
	printf("Masukkan nama barang: ");
	scanf("%s",search);
	
	// Mencari indeks nama barang pada array 
	while (!found && j<i){
		if (!strcmp(search, item[j])){
			found = 1;
		} else {
			++j;
		}
	}
	
	// Menampilkan informasi barang yang dicari
	printf("%s memiliki harga Rp. %d dengan jumlah barang %d.", item[j], price[j], amount[j]);
}