/*EL2208 Praktikum Pemecahan Masalah dengan C 2021/2022
*Modul            : 5 - Recursive
*Percobaan        : TP
*Hari dan Tanggal : Kamis, 24 Maret 2022
*Nama (NIM)       : Eraraya Morenzo Muten (18320003)
*Asisten (NIM)    : Nikolas Notohardjo (13219041)
*Nama File        : recursive.c
*Deskripsi        : Program akan menerima bilangan integer n
*					kemudian mengembalikan nilai ke-n dari
*					deret Fibonacci.
*/

#include <stdio.h>

int fibonacci(int n){
    // Deskripsi: menampilkan nilai ke-n deret
    //            Fibonacci dengan metode rekursif
    
    // Basis
    if(n<=0){
        return 0;
    } else if(n==1){
        return 1;
    //Rekuren
    } else{
        // Nilai deret Fibonacci adalah jumlah
        // kedua nilai sebelumnya
        return fibonacci(n-1) + fibonacci(n-2);
    }
}

int main(){
    int n; // variabel urutan deret
    
    // Menerima input integer n
    printf("Masukkan n: ");
    scanf("%d", &n);
    
    // Menampilkan nilai deret Fibonacci ke-n
    printf("F(n) = %d", fibonacci(n));

    return 0;
}
