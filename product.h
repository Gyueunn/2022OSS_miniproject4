typedef struct{
    char name[80]; //제품 이름
    char data[80]; //제품 상세 설명
    char weight[20]; //제품 중량
    int price; //제품 가격
    int delivery; //제품 배송 방법 여부(1: 새벽 배송/2: 택배 배송)
} Product;

int addProduct(Product *p); //제품을 추가 할 때 사용하는 함수
void readProduct(Product p); //제품의 정보를 출력하기 위함 함수
int updateProduct(Product *p); //제품의 정보를 수정할 때 사용하는 함수
int deleteProduct(Product *p); //제품을 삭제할 때 사용하는 함수
int loadData(Product *p); //파일에 있는 데이터를 읽어올 때 사용하는 함수
void saveData(Product *p, int count); //파일에 제품 정보를 저장할 때 사용하는 함수
void searchName(Product *p, int count); //제품의 이름으로 검색할 때 사용하는 함수
void searchPrice(Product *p, int count); //제품의 가격으로 검색할 때 사용하는 함수
void searchDelivery(Product *p, int count); //제품의 배송 방법으로 검색할 때 사용하는 함수

