#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void createPassword(char *password) {
    int i, index;
    char upperLetters[] = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
    char lowerLetters[] = "abcdefghijklmnopqrstuvwxyz";
    char digits[] = "01247";

    srand(time(0));

    // Ýlk iki karakter büyük harf
    for (i = 0; i < 2; i++) {
        index = rand() % 26;
        password[i] = upperLetters[index];
    }

    // Sonraki dört karakter küçük harf
    for (i = 2; i < 6; i++) {
        index = rand() % 26;
        password[i] = lowerLetters[index];
    }

    // Son iki karakter rakam
    for (i = 6; i < 8; i++) {
        index = rand() % 5;
        password[i] = digits[index];
    }

    password[8] = '\0'; // Null karakteri ekleyerek C-string oluþturuyoruz
}

int validatePassword(char *password, char *input) {
    int i;
    for (i = 0; i < 8; i++) {
        if (password[i] != input[i]) {
            return 0; // Þifreler uyuþmuyor
        }
    }
    return 1; // Þifreler uyuþuyor
}

int main() {
    int choice, attempt = 0;
    char password[9], input[9];

    createPassword(password);

    while (1) {
        printf("MENU\n");
        printf("1. Sifre olusturma\n");
        printf("2. Sifre girisi\n");
        printf("3. Programdan cikis\n");
        printf("Seciminizi yapin: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                createPassword(password);
                printf("Olusturulan sifre: %s\n\n", password);
                break;
            case 2:
                printf("Sifreyi girin: ");
                scanf("%s", input);
                if (validatePassword(password, input)) {
                    printf("Sifre dogru! Programa hos geldiniz.\n\n");
                    attempt = 0;
                } else {
                    attempt++;
                    if (attempt >= 3) {
                        printf("Hatali girisler. Programdan cikis yapiliyor.\n");
                        exit(0);
                    } else {
                        printf("Hatali sifre! Tekrar deneyin.\n\n");
                    }
                }
                break;
            case 3:
                printf("Programdan cikiliyor...\n");
                exit(0);
            default:
                printf("Gecersiz secim!\n\n");
        }
    }

    return 0;
}
