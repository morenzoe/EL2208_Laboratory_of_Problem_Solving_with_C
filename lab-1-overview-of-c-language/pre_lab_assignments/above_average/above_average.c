/** EL2208 Praktikum Pemecahan Masalah dengan C 2021/2022
*   Modul               : 1
*   Percobaan           : Tugas Pendahuluan
*   Hari dan Tanggal    : Kamis, 17 Februari 2022
*   Nama (NIM)          : Eraraya Morenzo Muten (18320003)
*   Asisten (NIM)       : Dhanurangga Al Fadh (13218005)
*   Nama File           : above_average.c
*   Deskripsi           : Program menghitung rata-rata nilai (0-100)
*                         dari mahasiswa sejumlah integer positif N
*                         dan menampilkan nilai yang di atas rata-rata.
*/

#include <stdio.h>
#include <stdlib.h>

int main() {
	// Deklarasi variabel
	int N;
	int i;
	int sum = 0;
	int score[N];
	
	scanf("%d",&N);
	
	for (i=0; i<N; ++i){
		scanf("%d", &score[i]);
		sum+=score[i];
	}

	//printf("%d\n", sum/N); // Memeriksa rata-rata semua nilai

	for (i=0; i<N; ++i){
		if (score[i]>(sum/N)){
			printf("%d\n", score[i]);
		}
	}

   return 0;
}
