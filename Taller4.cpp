#include "libs/TextFileHandler.h"
#include "libs/List.h"
#include "libs/BinaryFileHandler.h"
#include "libs/Product.h"

#include <iostream>

using namespace std;

void printMenu();
List<Product> readProductsFromBinaryFile(TextFileHandler textFileHandler, BinaryFileHandler<ProductBinary> binaryFileHandler);
List<Product> addProductToBinaryFile(BinaryFileHandler<ProductBinary> binaryFileHandler);
List<Product> deleteProductFromBinaryFile(BinaryFileHandler<ProductBinary> binaryFileHandler);
List<Product> searchProductsByNameAndDate(List<Product> products);
void searchAndPrintProducts(BinaryFileHandler<ProductBinary> binaryFileHandler);

void printProducts(List<Product> products);


int main() {
    
    
    int option = 0;
    List<Product> products;
    
    string textFileName = "productos.txt";
    TextFileHandler textFileHandler(textFileName);

    string binaryFileName = "productos.bin";
    BinaryFileHandler<ProductBinary> binaryFileHandler(binaryFileName);
    
    do {
        printMenu();
        cout << "Ingrese una opción: ";
        cin >> option;

        
       switch (option)
        {
            case 1:
                
                products = readProductsFromBinaryFile(textFileHandler, binaryFileHandler);
                break;
            case 2:
                printProducts(products);
                break;
            case 3:
                products = addProductToBinaryFile(binaryFileHandler);
                break;
            case 4:
                products = deleteProductFromBinaryFile(binaryFileHandler);
                break;
            case 5:
                searchAndPrintProducts(binaryFileHandler);
                break;
            case 0:
                cout << "Saliendo..." << endl;
                break;
            default:
                cout << "Opción inválida" << endl;
                break;
        } 

    } while (option != 0);
    
    return 0;
}

void printMenu() {
    cout << "1. Leer productos desde un archivo de texto y crear un archivo binario" << endl;
    cout << "2. Mostrar productos del archivo binario" << endl;
    cout << "3. Agregar un producto al archivo binario" << endl;
    cout << "4. Borrar un producto del archivo binario" << endl;
    cout << "5. Buscar productos por nombre y fecha de vigencia" << endl;
    cout << "0. Salir" << endl;
}

List<Product> readProductsFromBinaryFile(
    TextFileHandler textFileHandler, 
    BinaryFileHandler<ProductBinary> binaryFileHandler) {
    
    List<Product> productsFromTextFile = readProductsFromTextFile(textFileHandler);
    List<ProductBinary> productsBinary = toProductBinary(productsFromTextFile);
    binaryFileHandler.writeBinaryFile(productsBinary);

    List<ProductBinary> productsBinaryRead = binaryFileHandler.readBinaryFile();

    return toProduct(productsBinaryRead);

}

void printProducts(List<Product> products) {


    cout << "Productos: " << endl;
    cout << "==============================" << endl;
    if (products.size == 0) {
        cout << "No hay productos" << endl;
    }

    for (int i = 0; i < products.size; i++) {
        
        cout << i << ". " <<products.get(i).storeName << " " 
        << products.get(i).storeURL << " " 
        << products.get(i).productName << " " 
        << products.get(i).datePromotionPeriod << " " 
        << products.get(i).price << endl;
        cout << "-------------------------" << endl;
    }
}

List<Product> addProductToBinaryFile(BinaryFileHandler<ProductBinary> binaryFileHandler) {
    Product product;
    cout << "Ingrese el nombre de la tienda: ";
    cin >> product.storeName;
    cout << "Ingrese la URL de la tienda: ";
    cin >> product.storeURL;
    cout << "Ingrese el nombre del producto: ";
    cin >> product.productName;
    cout << "Ingrese la fecha de vigencia: ";
    cin >> product.datePromotionPeriod;
    cout << "Ingrese el precio: ";
    cin >> product.price;

    bool successWriting = binaryFileHandler.appendElementToFile(toProductBinary(product));
    
    if(successWriting) {
        cout << "Producto agregado exitosamente" << endl;
    } else {
        cout << "Error al agregar el producto" << endl;
    }

    List<ProductBinary> productsBinary = binaryFileHandler.readBinaryFile();

    return toProduct(productsBinary);
}

List<Product> deleteProductFromBinaryFile(BinaryFileHandler<ProductBinary> binaryFileHandler) {

    List<ProductBinary> productsBinary = binaryFileHandler.readBinaryFile();
    printProducts(toProduct(productsBinary));
    cout << "Ingrese la posición del producto a borrar: ";
    int position;
    cin >> position;

    binaryFileHandler.removeElementFromFile(position);

    List<ProductBinary> productsBinaryRead = binaryFileHandler.readBinaryFile();

    return toProduct(productsBinaryRead);
}

List<Product> searchProductsByNameAndDate(List<Product> products) {
    string name;
    string date;

    cout << "Ingrese el nombre del producto: ";
    getline(cin >> ws, name);
    cout << "Ingrese la fecha de vigencia: ";
    cin >> date;

    cout << "Productos encontrados para nombre " << name << " y fecha " << date << ": " << endl;

    return searchProducts(date, name, products);
}

void searchAndPrintProducts(BinaryFileHandler<ProductBinary> binaryFileHandler) {
    List<Product> products = toProduct(binaryFileHandler.readBinaryFile());
    printProducts(products);
    List<Product> productsFound = searchProductsByNameAndDate(products);
    printProducts(productsFound);
}

