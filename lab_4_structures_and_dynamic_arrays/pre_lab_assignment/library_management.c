/*EL2208 Praktikum Pemecahan Masalah dengan C 2021/2022
*Modul            : 4 - Structures and Dynamic Arrays
*Percobaan        : TP
*Hari dan Tanggal : Kamis, 24 Februari 2022
*Nama (NIM)       : Eraraya Morenzo Muten (18320003)
*Asisten (NIM)    : Gala Ramadhan Ilham Warno Putra (13218076)
*Nama File        : library_management.c
*Deskripsi        : Program akan menambahkan nomor jenis buku dan
*					jumlah buku yang ada di dalam perpustakaan
*					kemudian menampilkan data tersebut kembali.
*/

#include <stdio.h>
#include <stdlib.h>

typedef struct book{
	int jenis_buku;
	int jumlah_buku;
}buku;

void addjenisbuku(int jenis, int jumlah, buku* perpustakaan, int *count){
	perpustakaan[*count].jenis_buku = jenis;
	perpustakaan[*count].jumlah_buku = jumlah;
	
	*count += 1;
}

void print(int count, buku* perpustakaan){
	int i;
	
	for(i=0; i<count; ++i){
		printf("jenis: %d, jumlah: %d\n", perpustakaan[i].jenis_buku, perpustakaan[i].jumlah_buku);
	}
}

int main(){
	buku* perpus=(buku*) malloc(sizeof(buku));
	int banyak_jenis_buku = 0;
	
	addjenisbuku(1,5,perpus,&banyak_jenis_buku);
	addjenisbuku(2,8,perpus,&banyak_jenis_buku);
	addjenisbuku(6,20,perpus,&banyak_jenis_buku);
	
	print(banyak_jenis_buku, perpus);
	
	free(perpus);
	return 0;
}