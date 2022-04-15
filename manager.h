#include <stdio.h>
#include <string.h>
typedef struct{
    char name[80];
    char data[80];
    char weight[20];
    int price;
    int delivery;
} Product;

int selectProduct();
int addProduct(Product *p);
void listProduct(Product *p, int count);
void readProduct(Product p);
int selectDataNo(Product *p, int count);
int updateProduct(Product *p);
int deleteProduct(Product *p);
int loadData(Product *p);
