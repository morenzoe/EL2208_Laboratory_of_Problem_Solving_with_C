#include <stdio.h>
#include <stdlib.h>

int main()
{
    // Deklarasi variabel
    int N;
    int i;
    int score[N];
    double sum=0;
	int min = 100;
	int max = 0;

    printf("Masukkan jumlah murid: ");
    scanf("%d", &N);
    printf("%d\n", N);

    for (i=0; i<N; ++i){
        do {
        printf("Masukkan nilai murid absen %d : ", i+1);
        scanf("%d", &score[i]);

        if (score[i]<0 || score[i]>100){
            printf("Input nilai tidak valid, coba lagi\n");
        }

        } while (score[i]<0 || score[i]>100);

        sum+=score[i];
		
		if (score[i]<min){
			min = score[i];
		} else if {
			
			
			

    }

    printf("\nRata-Rata Kelas: %d\n", sum/N);
	

    return 0;
}
