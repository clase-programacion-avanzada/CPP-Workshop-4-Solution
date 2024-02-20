#ifndef PRODUCT_H
#define PRODUCT_H

#include <string>
#include "TextFileHandler.h"
#include "List.h"


using namespace std;

struct Product {
  string storeName;
  string storeURL;
  string productName;
  string datePromotionPeriod; //Format dd/mm/yyyy
  double price;
};

//structure to store the product in a binary file
struct ProductBinary {
  char storeName[50];
  char storeURL[100];
  char productName[100];
  char datePromotionPeriod[10]; //Format dd/mm/yyyy
  double price;
};

bool dateIsGreaterOrEqual(string date1,string date2) {
  
  char slash = '/';

  List<string> parts1 = split(date1, slash);
  List<string> parts2 = split(date2, slash);


  int day1 = stoi(parts1.get(0));
  int month1 = stoi(parts1.get(1));
  int year1 = stoi(parts1.get(2));

  int day2 = stoi(parts2.get(0));
  int month2 = stoi(parts2.get(1));
  int year2 = stoi(parts2.get(2));

  int yearDifference = year1 - year2;
  int monthDifference = month1 - month2;
  int dayDifference = day1 - day2;

  /*
  int dateInDays1 = year1 * 365 + month1 * 30 + day1;
  int dateInDays2 = year2 * 365 + month2 * 30 + day2;

  return dateInDays1 - dateInDays2 >= 0;
  */
  return yearDifference > 0 
  || (yearDifference == 0 && monthDifference > 0) 
  || (yearDifference == 0 && monthDifference == 0 && dayDifference >= 0);


}


List<Product> searchProducts(string date, string name, List<Product> products) {

  List<Product> filteredProducts;

  for (int i = 0; i < products.size; i++) {
    string datePromotionPeriod = products.get(i).datePromotionPeriod;
    string productName = products.get(i).productName;
    
    if (dateIsGreaterOrEqual(datePromotionPeriod, date) && productName == name) {
      filteredProducts.add(products.get(i));
    }

  }

  return filteredProducts;
}

ProductBinary toProductBinary(Product product) {
  
  ProductBinary productBinary;

  strcpy(productBinary.storeName, product.storeName.c_str());
  strcpy(productBinary.storeURL, product.storeURL.c_str());
  strcpy(productBinary.productName, product.productName.c_str());
  strcpy(productBinary.datePromotionPeriod, product.datePromotionPeriod.c_str());
  productBinary.price = product.price;

  return productBinary;

}

List<ProductBinary> toProductBinary(List<Product> products) {
  
  List<ProductBinary> productsBinary;

  for (int i = 0; i < products.size; i++) {
      productsBinary.add(toProductBinary(products.get(i)));
  }

  return productsBinary;

}

Product toProduct(ProductBinary productBinary) {
  
  Product product;

  product.storeName = productBinary.storeName;
  product.storeURL = productBinary.storeURL;
  product.productName = productBinary.productName;
  product.datePromotionPeriod = productBinary.datePromotionPeriod;
  product.price = productBinary.price;

  return product;

}

List<Product> toProduct(List<ProductBinary> productsBinary) {
  
  List<Product> products;

  for (int i = 0; i < productsBinary.size; i++) {
      products.add(toProduct(productsBinary.get(i)));
  }

  return products;

}


Product getProductFromLine(string line, char delimiter = ';') {
    Product product;

    List<string> parts = split(line, delimiter);

    product.storeName = parts.get(0);
    product.storeURL = parts.get(1);
    product.productName = parts.get(2);
    product.datePromotionPeriod = parts.get(3);
    product.price = stod(parts.get(4));

    return product;
}

List<Product> readProductsFromTextFile(TextFileHandler textFileHandler) {
    List<Product> products;

    List<string> lines = textFileHandler.readLines();

    for (int i = 0; i < lines.size; i++) {
        products.add(getProductFromLine(lines.get(i)));
    }

    return products;

}


#endif /* PRODUCT_H */