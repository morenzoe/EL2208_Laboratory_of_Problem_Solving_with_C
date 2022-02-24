/*EL2208 Praktikum Pemecahan Masalah dengan C 2021/2022
*Modul            : 2 - Strings and External Files
*Percobaan        : 1
*Hari dan Tanggal : Kamis, 24 Februari 2022
*Nama (NIM)       : Eraraya Morenzo Muten (18320003)
*Asisten (NIM)    : Syifa Kushirayati (18319037)
*Nama File        : soal-01.c
*Deskripsi        : Program rekap data BPM (beat per minute) siswa. Program dapat
*					mencari siswa dengan BPM terkecil, mencari nama siswa sesuai input,
*					dan mencari siswa dengan BPM dalam jangkauan input. Diasumsikan
*					tidak ada siswa dengan BPM yang sama.
*/

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <limits.h>

#define maxLen 255 // 8-bit

int main(){
	// Deklarasi variabel
	char filename[maxLen];		// nama file
	char fileLine[maxLen];		// string baris file
	char name[maxLen][maxLen];	// array nama siswa
	int bpm[maxLen];			// array BPM siswa
	char *token;				// pointer token
	int menu;					// menu pilihan
	int min;					// BPM minimum
	int i, j, k, l, m = 0;		// variabel iterasi
	int idx[maxLen] = {-1};		// array indeks yang akan di tampilkan, nilai elemen
								// pertama (-1) sebagai penanda jika array kosong
	char search[maxLen];		// string nama siswa yang dicari
	int found = 0;				// boolean pencarian
	int count = 0;				// jumlah huruf yang sama
	int upper, lower;			// nilai batas atas dan bawah BPM yang dicari
	
	
	// Meminta input nama file
	printf("Masukkan nama file kelas : ");
	scanf("%s",filename);
	
	
	// Membaca file
	FILE* file = fopen(filename, "r");
	
	// Program selesai jika file tidak ada
	if (file==NULL){
		printf("Error : file invalid\n");
		return 0;
	}
	
	// Membaca file dan menyimpan data pada array yang sesuai
	while(fgets(fileLine, maxLen, file)) {
		// Membaca suatu baris sampai koma untuk menyimpan nama siswa
        token = strtok(fileLine, ",");
		strcpy(name[i], token);
		// Membaca baris yang sama sampai akhir baris untuk menyimpan BPM siswa
		token = strtok(NULL, "\n");
		bpm[i] = atoi(token);
		// Menambah iterasi
		++i;
	}
	
	// Menutup file
	fclose(file);
	
	// Variabel i sekarang bernilai sejumlah baris pada file
	
	// Meminta input menu
	printf("Pilihlah nomor menu dibawah ini : \n");
	printf("1. Cari siswa dengan bpm terkecil\n");
	printf("2. Cari siswa dengan nama nya\n");
	printf("3. Cari siswa dengan rentang bpm tertentu\n");
	printf("Masukkan nomor menu 1/2/3 : ");
	scanf("%d", &menu);
	
	// Mencari indeks siswa dengan BPM terkecil
	if (menu==1){
		min = bpm[0];
		
		for (j = 1; j<i; ++j){
			if (bpm[j] < min) {
            min = bpm[j];
            idx[0] = j;
			}
		}
		
		// Batas menampilkan
		idx[1] = -1;
	
	// Mencari indeks siswa dengan nama dari input
	} else if (menu==2){
		printf("Masukkan nama siswa : ");
		scanf("%s",search);
		
		// Mencari nama di seluruh kelas
		for (k = 0; k<i; ++k){
			found = 0;
			m = 0;
			
			// Membandingkan nama search pada nama lengkap dan geser per huruf
			while (!found && m<strlen(name[k])-strlen(search)+1){
				count = 0;
				for (j=0; j<strlen(search);++j){
					// Menjumlahkan huruf yang sama
					count += (name[k][m+j]==search[j]);
				}
				if (count==strlen(search)){
					// Nama ditemukan di siswa ke-k
					found = 1;
					idx[l] = k;
					// Menambah iterasi
					++l;
				}
				// Menambah iterasi
				++m;
			}
		}
		
		// Batas menampilkan
		idx[l] = -1;
		
		// Nama tidak ditemukan di seluruh kelas
		if (idx[0]==-1){
			printf("Hasil pencarian tidak ditemukan :(\n");
		}
	
	// Mencari indeks siswa dengan BPM dalam jangkauan input
	} else if (menu==3){
		printf("Masukkan batas atas bpm : ");
		scanf("%d", &upper);
		
		printf("Masukkan batas bawah bpm : ");
		scanf("%d", &lower);
		
		// Mencari BPM dalam jangkauan di seluruh kelas
		for (j = 0; j<i; ++j){
			if ((bpm[j]>=lower)&&(bpm[j]<=upper)){
				// BPM dalam jangkauan
				idx[k] = j;
				// Menambah iterasi
				++k;
			}
		}
		
		// Batas menampilkan
		idx[k] = -1;
		
		// BPM dalam jangkauan tidak ditemukan di seluruh kelas
		if (idx[0]==-1){
			printf("Hasil pencarian tidak ditemukan :(\n");
		}
	
	// Program selesai jika pilihan menu tidak valid
	} else {
		printf("Error : Nomor menu invalid\n");
		return 0;
	}
	
	// Menampilkan siswa hasil pencarian
	for (i=0; i<maxLen; ++i){
		if (idx[i]>=0){
			printf("Siswa %d\n", i+1);
			printf("Nama siswa : %s\n", name[idx[i]]);
			printf("Bpm siswa : %d\n", bpm[idx[i]]);
		} else {
			// Program selesai jika array kosong
			return 0;
		}
	}
}