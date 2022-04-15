#include <stdio.h>
#include <string.h>
#include "product.h"

int selectProduct(){
    int menu;
    printf("\n*****************\n");
    printf("1. 조회\n");
    printf("2. 추가\n");
    printf("3. 수정\n");
    printf("4. 삭제\n");
    printf("5. 파일저장\n");
    printf("6. 이름 검색\n");
    printf("7. 가격 점색\n");
    printf("8. 배송 밥법 검색\n");
    printf("0. 종료\n\n");
    printf("=> 원하는 메뉴는? ");
    scanf("%d", &menu);
    return menu;
}
int main(void){
    Product p;
    int count = 0, menu;
    int result;
    
    count=loadData(&p);
    while (1){
        result = 0;
        menu = selectProduct();
        if (menu == 0) break;
        if (menu == 1){
            printf("*****************\n");
            readProduct(p);
        }
        else if (menu == 2){
            result = addProduct(&p);
        }
        else if (menu == 3){
            result = updateProduct(&p);
        }
        else if (menu == 4){
            result = deleteProduct(&p);
            if(result == 1) printf("=> 삭제됨!\n");
        }
        else if(menu == 5){
            saveData(&p, count);
        }
        else if(menu == 6){
            searchName(&p, count);
        }
        else if(menu==7){
            searchPrice(&p, count); //제품의 가격으로 검색할 때 사용하는 함수

        }
        else if(menu==8){
            searchDelivery(&p, count);
        }
    }
    printf("종료됨!\n");
    return 0;
}
int addProduct(Product *p){ //추가
    printf("제품의 이름은? ");
    getchar();
    fgets(p->name, 80, stdin);
    p->name[strlen(p->name)-1]='\0';
    printf("제품의 중량은? ");
    scanf("%s", p->weight);
    printf("가격은? ");
    scanf("%d", &p->price);
    printf("제품의 배송방법은?(1: 새벽/2: 택배) ");
    scanf("%d", &p->delivery);
    printf("제품의 상세설명은? ");
    getchar();
    fgets(p->data, 80, stdin);
    p->data[strlen(p->data)-1]='\0';
    return 1;
}
void readProduct(Product p){ //조회
    if(p.price!=-1){
    	printf("%s %s %d %d\n", p.name, p.weight, p.price, p.delivery);
    	printf("%s\n", p.data);
    }
    else printf("-> 제품 없음!\n");
}
int updateProduct(Product *p){ //수정
    printf("새 제품의 이름은? ");
    getchar();
    fgets(p->name, 80, stdin);
    p->name[strlen(p->name)-1]='\0';
    printf("새 제품의 중량은? ");
    scanf("%s", p->weight);
    printf("새 가격은? ");
    scanf("%d", &p->price);
    printf("새 제품의 배송방법은?(1: 새벽/2: 택배) ");
    scanf("%d", &p->delivery);
    printf("새 제품의 상세설명은? ");
    getchar();
    fgets(p->data, 80, stdin);
    p->data[strlen(p->data)-1]='\0';
    printf("=> 수정성공!\n");
    return 1;
}
int deleteProduct(Product *p){ //삭제
    p->price = -1;
    return 1;
}
int loadData(Product *p){
    int count=0;
    int i=0;
    FILE*data;
    if((data=fopen("Product.txt", "rt"))){
        for(i=0; i<100; i++){
            fscanf(data, "%s", p->name);
            if(feof(data)) break;
            fscanf(data, "%s", p->weight);
            fscanf(data, "%d", &p->price);
            fscanf(data, "%d", &p->delivery);
            fscanf(data, "%[^\n]s", p->data);
        }
        fclose(data);
        printf("=> 로딩 성공!\n");
    }
    else printf("=> 파일 없음\n");
    return i;
}
void saveData(Product *p, int count){
    int i;
    FILE* data;
    data=fopen("Product.txt", "wt");
    for(i=0; i<count; i++){
        if(p->price!=-1){
            fprintf(data, "%s %s %d %d %s\n", p->name, p->weight, p->price, p->delivery, p->data);
        }
    }
    fclose(data);
    printf("=> 저장됨!\n");
}
void searchName(Product *p, int count){
    int num;
    char search[80];

    printf("검색할 제품의 이름은? ");
    getchar();
    fgets(search, 80, stdin);
    search[strlen(search)-1]='\0';
    printf("*********************\n");
    if(p->price!=-1){
        if(strstr(p->name, search)){
            readProduct(*p);
            num++;
        }
    }
    if(num==0) printf("=> 검색된 데이터 없음!");
    printf("\n");
}
void searchPrice(Product *p, int count){
    int num;
    int mon;

    printf("검색할 가격은? ");
    scanf("%d", &mon);
    printf("*********************\n");
    if(p->price!=-1){
        if(p->price==mon){
            readProduct(*p);
            num++;
        }
    }
    if(num==0) printf("=> 검색된 데이터 없음!");
    printf("\n");    
}
void searchDelivery(Product *p, int count){
    int num;
    int no;

    printf("검색할 제품의 배송방법은?(1: 새벽/2: 택배)? ");
    scanf("%d", &no);
    printf("*********************\n");
    if(p->price!=-1){
        if(p->delivery==no){
            readProduct(*p);
            num++;
        }  
    }
    if(num==0) printf("=> 검색된 데이터 없음!");
    printf("\n");
}
