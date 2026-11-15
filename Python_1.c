#include <stdio.h>
#include <stdlib.h>

int tarif(int jam, int total){
    int hari = jam / 24;
    int sisa = jam % 24;
    if (jam <= 24){
        for (int i = 1; i <= jam; i++){
            if(i == 1)  total += 3000;
            else total += 2000;
        } if (total > 15000) total = 15000;
    } else {
        total = hari * 15000;
        for(int i = sisa; i > 0; i--){
            if(i == 1) total += 3000;
            else total += 2000;
        } 
    } return total;
}

int main (){
    system("cls");
    int menit, jam = 0, total = 0;
    
    input_ulang:
    
    printf("masukkan durasi parkir (menit): ");
    scanf("%d", &menit);

    if (menit <= 0) {
        printf("Durasi Harus Lebih dari Nol\n"); 
        goto input_ulang;
    }
    else if (menit <= 60) jam = 1;
    else {
        for(int i = menit; i > 0; i-=60){
            jam += 1;
        }
    }

    total = tarif(jam, total);

    printf("Durasi Parkir: %d menit (ditagih %d jam)\n", menit, jam);
    printf("Total Biaya: Rp%d", total);

    return 0;
}