/*EL2208 Praktikum Pemecahan Masalah dengan C 2021/2022
*Modul            : 3 - Pointers and Functions
*Percobaan        : 2
*Hari dan Tanggal : Jumat, 4 Maret 2022
*Nama (NIM)       : Eraraya Morenzo Muten (18320003)
*Asisten (NIM)    : Harry Purba (13218002)
*Nama File        : soal-02.c
*Deskripsi        : Program akan melakukan konvolusi pada matriks citra 5x5
*					dengan matriks filter 3x3 dan menampilkan hasilnya. 
*					Data input citra dan filter didapatkan dari file eksternal
*					yang diasumsikan benar.
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define INPUT_ROW 5
#define INPUT_COLUMN 5
#define FILTER_ROW 3
#define FILTER_COLUMN 3
#define MAX_STRING 200

// Deklarasi variabel
int inputMatrix[INPUT_ROW*INPUT_COLUMN];
float filterMatrix[FILTER_ROW*FILTER_COLUMN];
float outputMatrix[(INPUT_ROW-FILTER_ROW+1)*(INPUT_COLUMN-FILTER_COLUMN+1)];
int isFileExist = 1;

//----------------------------------- FUNGSI MEMBACA FILE -----------------------------------//
// Deskripsi: mengekstrak informasi dari file eksternal dan menyimpannya ke dalam variabel input dan filter
// Parameter:
// *input : pointer matriks input
// *filter : pointer matriks filter
//---------------------------------------------------------------------------------------//
void getMatrix(int *input, float *filter){
	FILE *filePointer ;
	 
	char filename[MAX_STRING];
	char buffer[MAX_STRING];
	char *token;
	int i = 0;

	printf("Masukkan nama file: ");
	scanf("%s", filename);
 
	filePointer = fopen(filename, "r") ;
	 
	if ( filePointer == NULL )
	{
		printf("File gagal dibuka.\n");
		isFileExist = 0;
	}
	else
	{
		fgets (buffer, MAX_STRING, filePointer);
		token = strtok(buffer, ",");
		while(token != NULL){
			*(input+i) = atoi(token);
			token = strtok(NULL, ",");
			i++;
		}

		i = 0;

		fgets (buffer, MAX_STRING, filePointer);
		token = strtok(buffer, ",");
		while(token != NULL){
			*(filter+i) = atof(token);
			token = strtok(NULL, ",");
			i++;
		}

		fclose(filePointer);
	}

	return;
}

//----------------------------------- FUNGSI KONVOLUSI -----------------------------------//
// Deskripsi: fungsi untuk konvolusi matriks input dengan filter. hasilnya disimpan pada variabel output
// Parameter:
// *input : pointer matriks input
// *filter : pointer matriks filter
// *output : pointer matriks output
//---------------------------------------------------------------------------------------//
void convolution(int *input, float *filter, float *output){
	//-----Tuliskan kode anda disini------//
	int i,j,k,l;	// variabel iterasi
	float sum;		// variabel jumlah perkalian satu tahap proses konvolusi

	// Proses konvolusi bergeser ke bawah untuk mengisi row output
	for(l=0; l<INPUT_ROW-FILTER_ROW+1; ++l){
		// Proses konvolusi bergeser ke kanan untuk mengisi column output
		for(k=0; k<INPUT_ROW-FILTER_ROW+1; ++k){
			// Me-reset variabel sementara menjadi 0 setiap awal satu proses konvolusi
			sum = 0;
			// Satu tahap proses konvolusi, perkalian dengan setiap elemen filter
			for(j=0; j<FILTER_ROW; ++j){
				for(i=0; i<FILTER_ROW; ++i){
					// Menjumlahkan hasil perkalian pada variabel sementara
					sum += input[i+j*INPUT_ROW+k+l*INPUT_ROW] * filter[i+j*FILTER_ROW];
				}
			}
			// Mengisi matriks output dengan jumlah perkalian satu proses konvolusi
			output[l*(INPUT_ROW-FILTER_ROW+1)+k] = sum;
		}
	}
}

//----------------------------------- FUNGSI OUTPUT -----------------------------------//
// Deskripsi : fungsi untuk mencetak matriks input, filter, dan output
// Parameter:
// *input : pointer matriks input
// *filter : pointer matriks filter
// *output : pointer matriks output
//---------------------------------------------------------------------------------------//
void printMatrix(int *input, float *filter, float *output){
	printf("Matriks input: \n");
	for(int row = 0; row < INPUT_ROW; row++){
		for(int col = 0; col < INPUT_COLUMN; col++){
			printf("%d,", *(input+row*(INPUT_COLUMN) + col));
		}
		printf("\n");
	}

	printf("Matriks filter: \n");
	for(int row = 0; row < FILTER_ROW; row++){
		for(int col = 0; col < FILTER_COLUMN; col++){
			printf("%.2f,", *(filter+row*(FILTER_COLUMN) + col));
		}
		printf("\n");
	}

	printf("Matriks output: \n");
	for(int row = 0; row < INPUT_ROW-FILTER_ROW+1; row++){
		for(int col = 0; col < INPUT_COLUMN-FILTER_COLUMN+1; col++){
			printf("%.2f,", *(output+row*(INPUT_COLUMN - FILTER_COLUMN + 1) + col));
		}
		printf("\n");
	}
}

int main(){
	//-----Tuliskan kode anda disini------//
	// Membaca matrix dari file eksternal
	getMatrix(inputMatrix, filterMatrix);
	
	// Jika file tidak ada, program selesai
	if(!isFileExist){
		return 0;
	}
	
	// Jika file ada, program melakukan konvolusi
	convolution(inputMatrix, filterMatrix, outputMatrix);
	
	// Menampilkan matriks hasil konvolusi
	printMatrix(inputMatrix, filterMatrix, outputMatrix);
	
	return 0;
}