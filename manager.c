#include "manager.h"
#define DEBUG

int selectProduct(){
    int menu;
    printf("\n*****************\n");
    printf("1. 조회\n");
    printf("2. 추가\n");
    printf("3. 수정\n");
    printf("4. 삭제\n");
    printf("5. 파일저장\n");
    printf("6. 이름 검색\n");
    printf("7. 가격 검색\n");
    printf("8. 배송 밥법 검색\n");
    printf("0. 종료\n\n");
    printf("=> 원하는 메뉴는? ");
    scanf("%d", &menu);
    return menu;
}
int addProduct(Product *p){ //추가
#ifdef DEBUG
    printf("제품의 이름은? ");
    getchar();
    scanf("%[^\n]s", p->name);
    printf("제품의 중량은? ");
    scanf("%s", p->weight);
    printf("가격은? ");
    scanf("%d", &p->price);
    printf("제품의 배송방법은?(1: 새벽/2: 택배) ");
    scanf("%d", &p->delivery);
    printf("제품의 상세설명은? ");
    getchar();
    scanf("%[^\n]s", p->data);
#endif
    return 1;
}
void listProduct(Product *p, int count){
    printf("*****************\n");
    for(int i=0; i<count; i++){
        if(p[i].price==-1) continue;
        printf("%2d. ", i+1);
        readProduct(p[i]);
    }
}
void readProduct(Product p){ //조회
    printf("%s %s %d %d %s\n", p.name, p.weight, p.price, p.delivery, p.data);
}
int selectDataNo(Product *p, int count){
    int no;
    listProduct(p, count);
    printf("번호는 (취소 :0)? ");
    scanf("%d", &no);
    return no;
}
int updateProduct(Product *p){ //수정
#ifdef DEBUG
    printf("새 제품의 이름은? ");
    getchar();
    scanf("%[^\n]s", p->name);
    printf("새 제품의 중량은? ");
    scanf("%s", p->weight);
    printf("새 가격은? ");
    scanf("%d", &p->price);
    printf("새 제품의 배송방법은?(1: 새벽/2: 택배) ");
    scanf("%d", &p->delivery);
    printf("새 제품의 상세설명은? ");
    getchar();
    scanf("%[^\n]s", p->data);
    printf("=> 수정성공!\n");
#endif    
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
        for(i=0; i<20; i++){
            fscanf(data, "%s", p[i].name);
            if(feof(data)) break;
            fscanf(data, "%s", p[i].weight);
            fscanf(data, "%d", &p[i].price);
            fscanf(data, "%d", &p[i].delivery);
            fscanf(data, "%[^\n]s", p[i].data);
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
        if(p[i].price!=-1){
            fprintf(data, "%s %s %d %d %s\n", p[i].name, p[i].weight, p[i].price, p[i].delivery, p[i].data);
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
    printf("*****************\n");
    for(int i=0; i<count; i++){
        if(p[i].price==-1) continue;
        if(strstr(p[i].name, search)){
            printf("%2d ", i+1);
            readProduct(p[i]);
            num++;
        }
    }
    if(num==0) printf("=> 검색된 데이터 없음!");
    else printf("=> 찾았음!");
    printf("\n");
}
void searchPrice(Product *p, int count){
    int num;
    int mon;

    printf("검색할 가격은? ");
    scanf("%d", &mon);
    printf("*****************\n");
    for(int i=0; i<count; i++){
        if(p[i].price==-1) continue;
        if(mon==p[i].price){
            printf("%2d ", i+1);
            readProduct(p[i]);
            num++;
        }
    }
    if(num==0) printf("=> 검색된 데이터 없음!");
    else printf("=> 찾았음!");
    printf("\n");
}
void searchDelivery(Product *p, int count){
    int num;
    int no;

    num=0;
    printf("검색할 제품의 배송방법은?(1: 새벽/2: 택배)? ");
    scanf("%d", &no);
    printf("*****************\n");
    for(int i=0; i<count; i++){
        if(p[i].price==-1) continue;
        if(no==p[i].delivery){
            printf("%2d ", i+1);
            readProduct(p[i]);
            num++;
        }
    }
    if(num==0) printf("=> 검색된 데이터 없음!");
    else printf("=> 찾았음!");
    printf("\n");
}
