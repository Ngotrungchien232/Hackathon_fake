#include<stdio.h>

int main(){
	int lua_chon;
	int n = 0;
	int arr[100];
	int i, j;
	int max;
	int num, is_prime = 1;
	
	
	while(1){
		//in ra menu
		printf("\n\n\n\nMENU\n\n\n\n");
		printf("\n");
		printf("1. nhap so phan tu can nhap va gia tri cac phan tu\n");
		printf("2. in ra gia tri cac phan tu dang quan ly\n");
		printf("3. in ra gia tri lon nhat trong mang\n");
		printf("4. in ra cac phan tu la so nguyen to trong mang\n");
		printf("5. them mot phan tu vao mang\n");
		printf("6. xoa mot phan tu trong mang\n");
		printf("7. sap xep mang theo thu tu tang dan\n");
		printf("8. tim kiem phan tu(nguoi dung nhap) va in ra vi tri index cua phan tu do\n");
		printf("9. thoat\n");
		printf("\n");
		printf("\n");
		//tien hanh cho nguoi dung nhap vao lua chon cua minh
		printf("lua chon cua ban la: ");
		scanf("%d", &lua_chon);
		
		//sau do dung lenh switch case de co the thuc hien cac chuc nang 
		switch(lua_chon){
			
			case 1:
				//nhap so phan tu can nhap va gan gia tri cho cac phan tu
				// cho nguoi dung nhap kich thuoc mang
				printf("kich thuoc mang ma ban mong muon la: \n");
				scanf("%d", &n);
				// cho nguoi dung nhap vao gia tri cho cac phan tu
				for(i = 0; i < n; i++){
					printf(" phan tu %d la: \n", i);
					scanf("%d", &arr[i]);
				}
				break;
			
			case 2:
				// in ra cac gia tri dang quan ly
				if(n == 0){
					printf("mang cua ban dang trong, moi ban quay lai 1 de nhap phan tu");
				} else {
				printf("Cac phan tu co trong mang la: \n");
				for(i = 0; i < n; i++){
					printf("number[%d] = %d\n", i, arr[i]);
				}
			}
				break;
			
			case 3:
			//in ra gia tri lon nhat trong mang
			if(n == 0){
				printf("mang cua ban dang trong, moi ban quay lai 1 de nhap phan tu");
			} else {
			max = arr[0];
			for(i = 0; i < n; i++){
				if(arr[i] > max){
					max = arr[i];
				}
			}
		}
			printf("phan tu lon nhat trong mang hien tai la: %d", max);
			break;
			
			case 4:
			// tim so nguyen to trong mang
			if(n == 0){
				printf("mang cua ban khong chua phan tu nao, moi ban quay lai 1 de co the nhap them phan tu vao mang");
			} else{
				printf("cac so nguyen to trong mang: ");
				for(i = 0; i < n; i++){
					int num = arr[i];
					int is_prime = 1;
				if(n < 2){
					is_prime = 0;
				} else {
					for(j = 2; j * j <= num; j++){
						if(num % 2 == 0){
							is_prime = 0;
							break;
						}
					}
				}
				if(is_prime){
					printf("%d\n", num);
				}
				}
				printf("\n");
			}
			break;
			
			 case 5:
			 	//them mot phan tu vao mang
			 	 if (n < 100) {
                    int a;
                    printf("Nhap gia tri phan tu moi: ");
                    scanf("%d", &a);
                    //them phan tu vao cuoi mang
                    arr[n] = a;
                    //tang kich thuoc mang len 1
                    n++;
                    printf("%d da duoc ban them vao mang: \n", a);
                } else {
                    printf("khong the them phan tu do mang da max: \n");
                }
                break;
                
            case 6:
            	//xoa mot phan tu trong mang
            	if(n == 0){
            		printf("khong co phan tu nao trong mang de xoa, moi ban quay tro lai 1 de nhap them phan tu vao mang");
				} else {
				if(n > 0){
					int index;
					printf("moi ban nhap vao phan tu ma ban muon xoa(luu y chi tu 0 den %d) la: ", n - 1);
					scanf("%d", &index);
					if(index >= 0 && index < n){
						for(i = index; i < n - 1; i++){
							arr[i] = arr[i + 1];
							n--;
							printf("phan tu o vi tri %d da duoc xoa", index);
						} 
					} else{
							printf(" vi tri ban chon khong hop le, moi ban chon lai\n");
						}
				}
			}
				
				break;
			
			case 7:
				//sap xep cac phan tu trong mang
				//in ra cac phan tu khi chua sap xep
				if(n == 0){
            		printf("khong co phan tu nao trong mang de xoa, moi ban quay tro lai 1 de nhap them phan tu vao mang");
				} else {
				printf("Cac phan tu co trong mang la: \n");
				for(i = 0; i < n; i++){
					printf("number[%d] = %d\n", i, arr[i]);
				}
				printf("\n");
				printf("cac phan tu khi da duoc sap xep la: \n");
				int temp;
				for(i = 0; i < n; i++){
					for(j = 0; j < n - 1 - i; j++){
						if(arr[j] > arr[j + 1]){
						temp = arr[j];
						arr[j] = arr[j + 1];
						arr[j + 1] = temp;
					}
					}
				}
				for(i = 0; i < n; i++){
					printf("number[%d] = %d\n", i, arr[i]);
				}
			}
				break;
			
			case 8:
				//tim gia tri trong mang
				if (n == 0) {
                    printf("Mang cua ban dang trong, moi ban quay tro lai buoc 1 de nhap phan tu\n");
                } else {
                    int x, found = 0;
                    printf("Nhap phan tu can tim: ");
                    scanf("%d", &x);
                    for (i = 0; i < n; i++) {
                        if (arr[i] == x) {
                            printf("Tim thay %d tai vi tri %d\n", x, i);
                            found = 1;
                        }
                    }
                    if (!found) printf("Khong tim thay\n");
                }
                break;
				
				 
				
				
		}
	}
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	//ket thuc chuong trinh 
	return 0;
}
