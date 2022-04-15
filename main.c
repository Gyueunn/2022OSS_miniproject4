#include "manager.h"

int main(void){
    Product p[20];
    int count = 0, menu;
    int result;
    int i;
    int num;
    int no;
    int index=0;

    count=loadData(p);
    index=count;
    while (1){
        result = 0;
        menu = selectProduct();
        if (menu == 0) break;
        if (menu == 1){
            if(count>0){
                listProduct(p, index);
            }
	    else printf("=> 조회된 제품 없음!\n");
        }
	else if (menu == 2){
            count+=addProduct(&p[index++]);
            printf("=> 추가됨!\n");

        }
        else if (menu == 3){
            no = selectDataNo(p, index);
            if(no == 0){
                printf("=> 취소됨!\n");
                continue;
            }
            updateProduct(&p[no-1]);
        }
        else if (menu == 4){
            if(count>0){
                listProduct(p, index);
            }
            printf("번호는 (취소 :0)? ");
            scanf("%d", &no);
            if(no != 0){
                printf("정말로 삭제하시겠습니까?(삭제 :1)");
                scanf("%d", &num);
                if(num == 1){
                    result = deleteProduct(&p[no-1]);
                    if(result == 1){
                        printf("=> 삭제됨!\n");
                        count--;
                    }
                }
            }
            else{
                printf("=> 취소됨!\n");
                continue;
            } 
        }
        else if(menu == 5){
            saveData(p, count);
        }
        else if(menu == 6){
            searchName(p, count);
        }
        else if(menu == 7){
            searchPrice(p, count); //제품의 가격으로 검색할 때 사용하는 함수

        }
        else if(menu == 8){
            searchDelivery(p, count);
        }
    }
    printf("종료됨!\n");
    return 0;
}
