#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main()
{

    int menu = 0;
    int jumlah = 0;

    // variable untuk write file
    char nama_barang[50];
    int jumlah_barang;
    int harga_barang;

    // variable untuk mengetahui jumlah barang yang ada di file
    char cek_jumlah_barang_yang_ada_di_file;
    int jumlah_barang_yang_ada_di_file_awal = 0;
    int jumlah_barang_yang_ada_di_file_update = 0;

    // variable untuk menampilkan barang yang ada di file
    char nama_barang_file[50][50];
    int jumlah_barang_file[50];
    int harga_barang_file[50];

    FILE * bukaFile = fopen("data_toko.txt", "a+");

    if( bukaFile == NULL ){
        printf("file toko tidak bisa dibuka !!!");
        exit(0);
    }else{
<<<<<<< HEAD
        while( (cek_jumlah_barang_yang_ada_di_file = fgetc(bukaFile)) != EOF ){
            if(cek_jumlah_barang_yang_ada_di_file == '\n'){
                jumlah_barang_yang_ada_di_file_awal++;
            }
        }
        jumlah_barang_yang_ada_di_file_awal += 1;
        const int jumlah_barang_yang_ada_di_file_sekarang = jumlah_barang_yang_ada_di_file_awal;
        jumlah_barang_yang_ada_di_file_update = jumlah_barang_yang_ada_di_file_sekarang;
    }
    menuutama:
    printf("Selamat datang di toko Teknik Komputer\n");
    printf("Pilih menu yang diinginkan :\n");
    printf("1.Input Barang ");
    printf("2. Lihat Barang ");
    printf("3. Tutup Program ");
    printf("\n");
    scanf("%d", &menu);
    switch(menu){

    case 1:
        bukaFile = fopen("data_toko.txt", "a+");
        printf("Masukkan jumlah barang yang ingin diinput:");
        scanf("%d", &jumlah);
        fflush(stdin);
        for(int i = 0; i<jumlah; i++){
            printf("\n");
            printf("Masukkan nama barang :");
            gets(nama_barang);
            printf("Masukkan jumlah barang :");
            scanf("%d", &jumlah_barang);
            printf("Masukkan harga barang :");
            scanf("%d", &harga_barang);
            fflush(stdin);
            fputc('\n', bukaFile);
            if((fprintf(bukaFile, "%s %d %d", nama_barang, jumlah_barang, harga_barang)) < 0){
                printf("data gagal dimaksukkan ke file");
            }else{
                printf("data berhasil dimasukkan ke file");
                jumlah_barang_yang_ada_di_file_update++;
            }
        }
        printf("\nIngin kembali ke menu utama ?\n");
        printf("1.ya\t2.tidak\n");
        scanf("%d", &menu);
        if(menu == 1){
            goto menuutama;
        }else if(menu == 2){
            goto keluar;
        }
        break;
    case 2:
        rewind(bukaFile);
        fseek(bukaFile, 0, SEEK_SET);
        if( (cek_jumlah_barang_yang_ada_di_file = fgetc(bukaFile)) == EOF){
            printf("Anda belum menginput satu barang pun, silahkan input barang terlebih dahulu\n");
            fclose(bukaFile);
            bukaFile = NULL;
            goto menuutama;
        }
        fseek(bukaFile, 0, SEEK_SET);
        for(int i = 0; i<jumlah_barang_yang_ada_di_file_update; i++){
            fscanf(bukaFile, "%s %d %d", nama_barang_file[i], &jumlah_barang_file[i], &harga_barang_file[i]);
        }
        printf("Data Toko Teknik Komputer \n");
        printf("Nama Barang\tJumlah Barang\tHarga Barang\n");
        for(int i = 0; i<jumlah_barang_yang_ada_di_file_update; i++){

            printf("%s\t\t%d\t\t%d\t\t\n", nama_barang_file[i], jumlah_barang_file[i], harga_barang_file[i]);
        }
        printf("\nJenis barang yang terdapat di Toko : %d\n", jumlah_barang_yang_ada_di_file_update);
        printf("\nIngin kembali ke menu utama ?\n");
        printf("1.ya\t2.tidak\n");
        scanf("%d", &menu);
        if(menu == 1){
            goto menuutama;
        }else if(menu == 2){
            goto keluar;
=======
        menuutama:
        printf("Selamat datang di toko Teknik Komputer\n");
        printf("Pilih menu yang diinginkan :\n");
        printf("1.Input Barang ");
        printf("2. Lihat Barang ");
        printf("3. Tutup Program ");
        printf("\n");
        scanf("%d", &menu);
        switch(menu){

        case 1:
            bukaFile = fopen("data_toko.txt", "a+");
            printf("Masukkan jumlah barang yang ingin diinput:");
            scanf("%d", &jumlah);
            fflush(stdin);
            for(int i = 0; i<jumlah; i++){
                printf("\n");
                printf("Masukkan nama barang :");
                gets(nama_barang);
                printf("Masukkan jumlah barang :");
                scanf("%d", &jumlah_barang);
                printf("Masukkan harga barang :");
                scanf("%d", &harga_barang);
                fflush(stdin);
                fputc('\n', bukaFile);
                if((fprintf(bukaFile, "%s %d %d", nama_barang, jumlah_barang, harga_barang)) < 0){
                    printf("data gagal dimaksukkan ke file");
                }else{
                    printf("data berhasil dimasukkan ke file");
                }
            }
            fclose(bukaFile);
            bukaFile = NULL;
            printf("\nIngin kembali ke menu utama ?\n");
            printf("1.ya\t2.tidak\n");
            scanf("%d", &menu);
            if(menu == 1){
                goto menuutama;
            }else if(menu == 2){
                goto keluar;
            }
            break;
        case 2:
            bukaFile = fopen("data_toko.txt", "a+");
            while( (cek_jumlah_barang_yang_ada_di_file = fgetc(bukaFile)) != EOF ){
                if(cek_jumlah_barang_yang_ada_di_file == '\n'){
                    jumlah_barang_yang_ada_di_file++;
                }
            }
            jumlah_barang_yang_ada_di_file += 1;
            fseek(bukaFile, 0, SEEK_SET);
            for(int i = 0; i<jumlah_barang_yang_ada_di_file; i++){
                fscanf(bukaFile, "%s %d %d", nama_barang_file[i], &jumlah_barang_file[i], &harga_barang_file[i]);
            }
            printf("Data Toko Teknik Komputer \n");
            printf("Nama Barang\tJumlah Barang\tHarga Barang\n");
            for(int i = 0; i<jumlah_barang_yang_ada_di_file; i++){

                printf("%s\t\t%d\t\t%d\t\t\n", nama_barang_file[i], jumlah_barang_file[i], harga_barang_file[i]);
            }
            fclose(bukaFile);
            bukaFile = NULL;
            printf("\nIngin kembali ke menu utama ?\n");
            printf("1.ya\t2.tidak\n");
            scanf("%d", &menu);
            if(menu == 1){
                goto menuutama;
            }else if(menu == 2){
                goto keluar;
            }
            break;

        case 3:
            keluar:
            printf("\nterima kasih");
            exit(0);
            break;
>>>>>>> 46b8e05bbb664f52c665f49889bb517e004578fa
        }
        break;

    case 3:
        keluar:
        fclose(bukaFile);
        bukaFile = NULL;
        printf("\nterima kasih");
        exit(0);
        break;
    default:
        printf("Menu yang anda pilih salah, silahkan coba lagi");
        goto menuutama;
    }


    return 0;
}
