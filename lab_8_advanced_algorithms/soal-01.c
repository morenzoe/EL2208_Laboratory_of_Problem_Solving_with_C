/*EL2208 Praktikum Pemecahan Masalah dengan C 2021/2022
*Modul            : 8 - Advanced Algorithms
*Percobaan        : 1
*Hari dan Tanggal : Kamis, 14 April 2022
*Nama (NIM)       : Eraraya Morenzo Muten (18320003)
*Asisten (NIM)    : Muhammad Morteza Mudrick (13219061)
*Nama File        : soal-01.c
*Deskripsi        : Program menghitung jumlah klaster dengan pendekatan
*                   Dept-First Search. Program menandai elemen matriks sebagai
*                   bagian dari klaster secara rekursif dengan memeriksa 8 elemen
*                   tetangga. Klaster baru didapatkan dari elemen yang memenuhi
*                   syarat namun belum ditandai.
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define BUFFER_SIZE 256
#define MAT_SIZE 10

/**
 * @brief fungsi untuk membaca file masukkan dan mengisi matriks
 *
 * @param filename nama file masukkan
 * @param mat matriks yang akan diisi
 */
void readFile(char *filename, int mat[MAT_SIZE][MAT_SIZE])
{
	char buffer[BUFFER_SIZE], *token;
	int i = 0, j = 0;
	FILE *f = fopen(filename, "r");

	while (fgets(buffer, BUFFER_SIZE, f))
	{
		j = 0;
		token = strtok(buffer, ",");
		while (token != NULL)
		{
			mat[i][j] = atoi(token);
			token = strtok(NULL, ",");
			j++;
		}
		i++;
	}
}

/**
 * @brief fungsi untuk memeriksa apakah koordinat merupakan bagian baru dari kluster
 *
 * @param mat matriks yang akan diperiksa
 * @param row baris dari koordinat
 * @param column kolom dari koordinat
 * @param thres nilai batas
 * @param cluster matriks boolean, 1: bagian klaster, 0: bukan bagian klaster
 */
int isNewClusterPart(int mat[MAT_SIZE][MAT_SIZE], int row, int column, int thres, int cluster[MAT_SIZE][MAT_SIZE]){
    // Koordinat elemen bisa menjadi bagian kluster jika bernilai sama atau lebih besar dari batas dan belum ditandai
    return ((mat[row][column]>=thres)&&(!cluster[row][column]));
}

/**
 * @brief fungsi untuk memeriksa apakah koordinat ada di luar matriks
 *
 * @param row baris dari koordinat
 * @param column kolom dari koordinat
 */
int isOutOfBound(int row, int column){
    // Koordinat elemen ada di luar matriks ukuran MAT_SIZE x MAT_SIZE jika baris atau kolomnya di bawah nol atau di atas MAT_SIZE
    return ((row<0)||(row>=MAT_SIZE)||(column<0)||(column>=MAT_SIZE));
}

/**
 * @brief fungsi untuk memeriksa apakah tetangga perimeter dari elemen bagian dari klaster
 *
 * @param mat matriks yang akan diperiksa
 * @param row baris dari koordinat
 * @param column kolom dari koordinat
 * @param thres nilai batas
 * @param cluster matriks boolean, 1: bagian klaster, 0: bukan bagian klaster
 */
void checkNeighbor(int mat[MAT_SIZE][MAT_SIZE], int row, int column, int thres, int cluster[MAT_SIZE][MAT_SIZE]){
    int i;                      // variabel iterasi
    int dir[8][2] = {{0,1},     // variabel untuk menyimpan arah pemeriksaan tetangga elemen
                     {1,1},     // pemeriksaan dimulai dari timur searah jarum jam
                     {1,0},     // {row, column}
                     {1,-1},
                     {0,-1},
                     {-1,-1},
                     {-1,0},
                     {-1,1}};
    
    // Menandai koordinat tersebut adalah bagian dari klaster
    cluster[row][column] = 1;
    
    // Memeriksa tetangga elemen dengan rekursif
    for(i=0;i<8;++i){
        // Tetangga elemen bagian dari klaster jika berada di dalam matriks dan memenuhi syarat
        if(!isOutOfBound(row+dir[i][0],column+dir[i][1])){
            if(isNewClusterPart(mat, row+dir[i][0], column+dir[i][1], thres, cluster)){
                // Rekursi
                checkNeighbor(mat, row+dir[i][0], column+dir[i][1], thres, cluster);
            }
        }
        // Basis
        // Jika seluruh tetangga sudah diperiksa dimana i==8
    }   
}

int main()
{
    char filename[BUFFER_SIZE];             // variabel nama file
    int thres;                              // variabel nilai batas
    int matrix[MAT_SIZE][MAT_SIZE];         // variabel matrix nilai    
    int cluster[MAT_SIZE][MAT_SIZE] = {0};  // variabel matrix bagian klaster. 1: bagian klaster, 0: bukan bagian klaster
    int numCluster = 0;                     // variabel jumlah klaster
    int i, j;                               // variabel iterasi
    
    // Meminta masukkan
	printf("Masukkan nama file: ");
	scanf("%s", filename);
	printf("Masukkan nilai batas: ");
	scanf("%d", &thres);
	
	// Membaca file dan mengisi matriks
	readFile(filename, matrix);
    
    // Menyusuri matriks
    for(i=0;i<MAT_SIZE;++i){
        for(j=0;j<MAT_SIZE;++j){
            // Menyusuri elemen yang melebihi batas dan belum diperiksa
            if(isNewClusterPart(matrix, i, j, thres, cluster)){
                // Memeriksa tetangga elemen
                checkNeighbor(matrix, i, j, thres, cluster);
                // Jika memenuhi, maka elemen pasti merupakan bagian klaster baru
                numCluster++;
            }
        }
    }

	// Mencetak jumlah klaster
	printf("Jumlah klaster: %d\n", numCluster);

	return 0;
}