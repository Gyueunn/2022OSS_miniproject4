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
    printf("제품의 중량은? ");
    scanf("%s", p->name);
    printf("제품의 중량은? ");
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
    scanf("%[^\n]s", p->data);
    printf("=> 수정성공!\n");
#endif    
    return 1;
}
int deleteProduct(Product *p){ //삭제
    p->price = -1;
    return 1;
}
