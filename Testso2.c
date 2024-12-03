#include <stdio.h>

int main() {
    int arr[100][100];
    int n, m, lua_chon, x, i, j;
    int tich = 1;
    int duong_cheo_chinh[100];
    int temp;

    while (1) {
        // Hien thi menu
        printf("\nMENU\n");
        printf("1. Nhap kich co va gia tri cho mang\n");
        printf("2. In gia tri cua mang\n");
        printf("3. In ra cac phan tu tren duong bien\n");
        printf("4. In ra cac phan tu tren duong cheo chinh\n");
        printf("5. In ra cac phan tu tren duong cheo phu\n");
        printf("6. Sap xep duong cheo chinh theo thu tu tang dan\n");
        printf("7. Tim kiem mot phan tu va in phan tu do ra trong mang\n");
        printf("8. Thoat\n");
        printf("\n");
        printf("Lua chon cua ban: ");
        scanf("%d", &lua_chon);

        switch (lua_chon) {
            case 1:
                // nhap kich thuoc va gia tri cho mang
                printf("Nhap so dong (n): ");
                scanf("%d", &n);
                printf("Nhap so cot (m): ");
                scanf("%d", &m);

                if (n <= 0 || m <= 0) {
                    printf("Kich thuoc mang khong hop le!\n");
                    break;
                }

                for (i = 0; i < n; i++) {
                    for (j = 0; j < m; j++) {
                        printf("Nhap gia tri cho arr[%d][%d]: ", i, j);
                        scanf("%d", &arr[i][j]);
                    }
                }
                break;

            case 2:
                // In ra gia tri cua mang
                printf("Ma tran cua ban la:\n");
                for (i = 0; i < n; i++) {
                    for (j = 0; j < m; j++) {
                        printf("%d ", arr[i][j]);
                    }
                    printf("\n");
                }
                break;

            case 3:
                if (n <= 1 || m <= 1) {
                    printf("Ma tran qua nho de co duong bien\n");
                    break;
                }
                //in cac phan tu tren duong bien va tich
                printf("Cac phan tu tren duong bien la:\n");
                tich = 1; // Ð?t l?i tích
                for (i = 0; i < n; i++) {
                    for (j = 0; j < m; j++) {
                        if (i == 0 || i == n - 1 || j == 0 || j == m - 1) {
                            printf("%d ", arr[i][j]);
                            tich *= arr[i][j];
                        }
                    }
                }
                printf("\nTich cac phan tu nam tren duong bien la: %d\n", tich);
                break;

            case 4:
                // In cac phan tu tren duong cheo chinh
                printf("Cac phan tu tren duong cheo chinh la:\n");
                for (i = 0; i < n && i < m; i++) {
                    printf("%d ", arr[i][i]);
                }
                printf("\n");
                break;

            case 5:
                // In cac phan tu tren duong cheo phu
                printf("Cac phan tu tren duong cheo phu la:\n");
                for (i = 0; i < n && i < m; i++) {
                    printf("%d ", arr[i][m - i - 1]);
                }
                printf("\n");
                break;

            case 6:
                // sap xep cac phan tu tren duong cxheo chinh
                if (n == 0 || m == 0) {
                    printf("Mang cua ban dang trong. Vui long nhap gia tri cho mang.\n");
                    break;
                }

                // Luu cac phan tu tren duong cheo chinh
                for (i = 0; i < n && i < m; i++) {
                    duong_cheo_chinh[i] = arr[i][i];
                }

                // sap xep phan tu bubble sort
                for (i = 0; i < (n < m ? n : m) - 1; i++) {
                    for (j = 0; j < (n < m ? n : m) - i - 1; j++) {
                        if (duong_cheo_chinh[j] > duong_cheo_chinh[j + 1]) {
                            temp = duong_cheo_chinh[j];
                            duong_cheo_chinh[j] = duong_cheo_chinh[j + 1];
                            duong_cheo_chinh[j + 1] = temp;
                        }
                    }
                }

                // Gán lai gia tri sau khi da sap xep
                for (i = 0; i < n && i < m; i++) {
                    arr[i][i] = duong_cheo_chinh[i];
                }

                // In ra ma tran sau khi sap xep
                printf("Ma tran sau khi sap xep la:\n");
                for (i = 0; i < n; i++) {
                    for (j = 0; j < m; j++) {
                        printf("%d ", arr[i][j]);
                    }
                    printf("\n");
                }
                break;

            case 7:
                // Tim kiem phan tu
                printf("Nhap phan tu can tim: ");
                scanf("%d", &x);
                int kiemtra = 0;
                for (i = 0; i < n; i++) {
                    for (j = 0; j < m; j++) {
                        if (arr[i][j] == x) {
                            printf("Tim thay %d tai vi tri arr[%d][%d]\n", x, i, j);
                            kiemtra = 1;
                        }
                    }
                }
                if (!kiemtra) {
                    printf("Khong tim thay %d trong mang.\n", x);
                }
                break;

            case 8:
                // Thoat chuong trinh
                printf("Thoat chuong trinh.\n");
                return 0;

            default:
                // lua chon khong hop le
                printf("Lua chon khong hop le. Vui long nhap lai!\n");
        }
    }

    return 0;
}

