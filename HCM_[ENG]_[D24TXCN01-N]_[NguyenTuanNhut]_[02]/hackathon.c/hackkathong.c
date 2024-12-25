#include<stdio.h>
#include<math.h>
int main(){
    int n, m = 0, key, temp, value, pos, flag1 = 0;
    int arr[100];
    do {
        printf("Menu\n");
        printf("1. Nhap so phan tu va gia tri cho mang\n");
        printf("2. In ra cac gia tri phan tu trong mang theo dang (arr[0] = 1)\n");
        printf("3. Dem so luong cac phan tu chan le trong mang\n");
        printf("4. Tim gia tri lon thu hai trong mang\n");
        printf("5. Them phan tu vao dau mang\n");
        printf("6. Xoa phan tu tai mot vi tri cu the\n");
        printf("7. Sap xep mang giam dan\n");
        printf("8. Tim kiem phan tu trong mang\n");
        printf("9. In so nguyen to trong mang da duoc binh phuong\n");
        printf("10. Sap xep mang giam dan\n");
        printf("11. Thoat\n");
        printf("Nhap lua chon: ");
        scanf("%d", &n);
        switch (n) {
            case 1:
                printf("Nhap so luong phan tu: ");
                scanf("%d", &m);
                printf("Nhap mang: ");
                for (int i = 0; i < m; i++) {
                    scanf("%d", &arr[i]);
                }
                break;
            case 2:
                for (int i = 0; i < m; i++) {
                    printf("arr[%d] = %d\n", i, arr[i]);
                }
                break;
            case 3:
                if (m == 0) {
                    printf("Mang rong\n");
                    break;
                }
                temp = 0; key = 0;
                for (int i = 0; i < m; i++) {
                    if (arr[i] % 2 == 0) {
                        temp++;
                    } else {
                        key++;
                    }
                }
                printf("So luong phan tu chan: %d\n", temp);
                printf("So luong phan tu le: %d\n", key);
                break;
            case 4: {
                int max1 = arr[0], max2 = -1;
                for (int i = 1; i < m; i++) {
                    if (arr[i] > max1) {
                        max2 = max1;
                        max1 = arr[i];
                    } else if (arr[i] > max2 && arr[i] < max1) {
                        max2 = arr[i];
                    }
                }
                if (max2 == -1) {
                    printf("Khong co gia tri lon thu hai\n");
                } else {
                    printf("Gia tri lon thu hai la: %d\n", max2);
                }
                break;
            }
            case 5:
                printf("Nhap phan tu muon them: ");
                scanf("%d", &value);
                for (int i = m; i > 0; i--) {
                    arr[i] = arr[i - 1];
                }
                arr[0] = value;
                m++;
                break;
            case 6:
                printf("Nhap vi tri can xoa: ");
                scanf("%d", &pos);
                if (pos < 0 || pos >= m) {
                    printf("Vi tri khong hop le\n");
                    break;
                }
                for (int i = pos; i < m - 1; i++) {
                    arr[i] = arr[i + 1];
                }
                m--;
                break;
            case 7:
                for (int i = 1; i < m; i++) {
                    key = arr[i];
                    int j = i - 1;
                    while (j >= 0 && arr[j] < key) {
                        arr[j + 1] = arr[j];
                        j--;
                    }
                    arr[j + 1] = key;
                }
                printf("Mang sau khi sap xep giam dan:\n");
                for (int i = 0; i < m; i++) {
                    printf("%d ", arr[i]);
                }
                printf("\n");
                break;
            case 8:
                printf("Nhap phan tu muon tim kiem: ");
                scanf("%d", &value);
                int let = 0, right = m - 1, flag = 0;
                while (let <= right) {
                    int mid = (let + right) / 2;
                    if (value == arr[mid]) {
                        printf("Phan tu %d co ton tai trong mang\n", value);
                        flag = 1;
                        break;
                    } else if (arr[mid] < value) {
                        let = mid + 1;
                    } else {
                        right = mid - 1;
                    }
                }
                if (flag == 0) {
                    printf("Khong tim thay phan tu %d trong mang\n", value);
                }
                break;
            case 9:
                flag = 1; key = 0;
                for (int i = 0; i < m; i++) {
                    flag = 1;
                    if (arr[i] > 1) {
                        for (int j = 2; j <= sqrt(arr[i]); j++) {
                            if (arr[i] % j == 0) {
                                flag = 0;
                                break;
                            }
                        }
                    } else {
                        flag = 0;
                    }
                    if (flag) {
                        printf("%d ", arr[i] * arr[i]);
                        key = 1;
                    }
                }
                if (key == 0) {
                    printf("Khong co so nguyen to nao trong mang\n");
                }
                printf("\n");
                break;
            case 10:
                for (int i = 0; i < m - 1; i++) {
                    for (int j = 0; j < m - i - 1; j++) {
                        if (arr[j] < arr[j + 1]) {
                            temp = arr[j];
                            arr[j] = arr[j + 1];
                            arr[j + 1] = temp;
                        }
                    }
                }
                printf("Mang da duoc sap xep giam dan.\n");
                break;
            case 11:
                printf("Thoat chuong trinh.\n");
                return 0;
            default:
                printf("Lua chon khong hop le\n");
                break;
        }
    } while (n != 11);
    return 0;
}
