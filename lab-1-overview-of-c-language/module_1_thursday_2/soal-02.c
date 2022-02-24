/*EL2208 Praktikum Pemecahan Masalah dengan C 2021/2022
*Modul            : Overview of C Language
*Percobaan        : 2
*Hari dan Tanggal : Kamis, 17 Februari 2022
*Nama (NIM)       : Eraraya Morenzo Muten (18320003)
*Asisten (NIM)    : Dhanurangga Al Fadh (13218005)
*Nama File        : soal-02.c
*Deskripsi        : Program untuk mencetak histogram dan LBP dari citra 3x3 pixel
*/

#include <stdio.h>
#include <stdlib.h>

int main(){
	// Deklarasi variabel
	int i, j;			// iterasi
	int image[3][3];	// matriks citra
	int bin[5] = {0};	// array frekuensi nilai pixel
	char hist[10][5];	// matriks histogram
	
	// Mengisi matriks citra 3x3 pixel
	// sekaligus menghitung frekuensi nilai pixel
	for (i=0; i<3; ++i){
		for (j=0; j<3; ++j){
			printf("masukkan data ke - [%d][%d] ", i, j);
			scanf("%d", &image[i][j]);
			
			if (image[i][j]>=0 && image[i][j]<=10) {
				bin[0]+=1;
			} else if (image[i][j]>=11 && image[i][j]<=20){
				bin[1]+=1;
			} else if (image[i][j]>=21 && image[i][j]<=30){
				bin[2]+=1;
			} else if (image[i][j]>=31 && image[i][j]<=40){
				bin[3]+=1;
			} else if (image[i][j]>=41 && image[i][j]<=50){
				bin[4]+=1;
			}
		}
	}
	
	// Mengisi histogram dengan spasi
	for (i=0; i<10; ++i){
		for (j=0; j<5; ++j){
			hist[i][j] = ' ';
		}
	}
	
	// Mengisi histogram sesuai frekuensi input
	for (j=0; j<5; ++j){
		for (i=9; i>(9-bin[j]); --i){
			hist[i][j] = '1';
		}
	}
	
	//template output
	printf("histogram matriks adalah :\n");
	
	// Mencetak setiap elemen matriks histogram
	for (i=0; i<10; ++i){
		for (j=0; j<5; ++j){
			printf("%c", hist[i][j]);
		}
		printf("\n");
	}
	
	printf("lbp matriks adalah :\n");
	
	// Mencetak lbp sesuai perbandingan
	for (i=0; i<3; ++i){
		for (j=0; j<3; ++j){
		    if (i!=1||j!=1){
		        if (image[i][j]>=image[1][1]){
					printf("%d", 1);
				} else {
					printf("%d", 0);
				}
		    }
		}
    }
	
	return 0;
}