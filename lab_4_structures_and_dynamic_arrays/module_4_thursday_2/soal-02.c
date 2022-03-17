/*EL2208 Praktikum Pemecahan Masalah dengan C 2021/2022
*Modul            : 4 - Structures and Dynamic Arrays
*Percobaan        : 2
*Hari dan Tanggal : Kamis, 17 Maret 2022
*Nama (NIM)       : Eraraya Morenzo Muten (18320003)
*Asisten (NIM)    : Gala Ramadhan Ilham Warno Putra (13218076)
*Nama File        : soal-02.c
*Deskripsi        : Program menerima matriks sebesar m kali n,
*					melakukan transpos konjugat, memeriksa sifat
*					matriks, dan menampilkan sifat tersebut.
*/

// Deklarasi
#include <stdio.h>
#include <stdlib.h>

typedef struct complex {
	int real;
	int imag;
} complex;

void conjugateTranspose(int row, int column, complex* matriks, complex* matriksH){
    // Deskripsi: Prosedur untuk melakukan transpos konjuga
	// Deklarasi
	int i, j; // variabel iterasi
		
	// Program
    // Melakukan transpos pada tiap elemen matriks dan menyalin ke matriks lain
	for(i=0; i<row; ++i){
		for(j=0; j<column; ++j){
			matriksH[j*row+i].real = matriks[i*column+j].real;
			// Melakukan konjugat dengan membalik tanda nilai imajiner
			matriksH[j*row+i].imag = -1*matriks[i*column+j].imag;
		}
	}
}

void hermitianCheck(int row, int column, int* hermitian, int* skew_hermitian, complex* matrix, complex* matrixH){
    // Deskripsi: 
	// Deklarasi
	int i, j; // variabel iterasi
	
	// Program
	// Memeriksa setiap elemen matriks
    for(i=0; i<row; ++i){
		for(j=0; j<column; ++j){
			// Jika ada nilai yang berbeda, matriks bukan hermitian
			if((matrixH[i*row+j].real != matrix[i*row+j].real)&&(matrixH[i*row+j].imag != matrix[i*row+j].imag)){
			    *hermitian = 0;
			}
			// Jika nilai merupakan negatifnya, matriks skew hermitian
			if((matrixH[i*row+j].real == -1*matrix[i*row+j].real)&&(matrixH[i*row+j].imag == -1*matrix[i*row+j].imag)){
				*skew_hermitian = 1;
			} else {
				*skew_hermitian = 0;
				break;
			}
		}
	}
}

int main() {
	//insert code here 
	int m, n; 				// row, column
	int i, j; 				// variabel iterasi
	int hermitian = 1; 		// variabel boolean
	int skew_hermitian = 0;	// variabel boolean
	
	// Membaca dua angka pertama dari input
	scanf("%d", &m);
    scanf("%d", &n);
    
	// Membuat dua pointer
    complex* matrix = (complex*) malloc(m*n*sizeof(complex));	// memastikan memori cukup untuk matriks
	complex* matrixH = (complex*) malloc(m*n*sizeof(complex));
	
	// Membaca nilai matriks
	for(i=0; i<m; ++i){
		for(j=0; j<n; ++j){
			scanf("%d", &matrix[i*n+j].real);
			scanf("%d", &matrix[i*n+j].imag);
		}
	}
	
	// Jika bukan matriks persegi, matriks bukan keduanya
	if(m!=n){
        printf("Matriks bukan merupakan keduanya\n");
        return 0;
    }
	
	// Melakukan transpos konjugat
    conjugateTranspose(m, n, matrix, matrixH);
	
	// Memeriksa sifat matriks
    hermitianCheck(m, n, &hermitian, &skew_hermitian, matrix, matrixH);
    
	//template output :
	// Menampilkan sifat matriks
    if(hermitian&&skew_hermitian){
        printf("Matriks merupakan matriks skew hermitian dan matriks hermitian\n");
    } else if (hermitian){
        printf("Matriks merupakan matriks hermitian\n");
    } else if (skew_hermitian){
        printf("Matriks merupakan matriks skew hermitian\n");
    } else {
        printf("Matriks bukan merupakan keduanya\n");
    }
}
