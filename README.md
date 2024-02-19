# Taller 4 - Manejo de archivos de Binarios

Suponga que tiene una aplicación que permite realizar algunas operaciones sobre los precios de las promociones de productos en tiendas de comercio electrónico. En este programa se usa la estructura `Product` para manejar la información. Esta estructura está definida en el archivo header [Product.h](libs/Product.h) como: 

```cpp
struct Product {
  string storeName;
  string storeURL;
  string productName;
  string datePromotionPeriod; //Formato dd/mm/yyyy
  double price;
}

```

Se ha definido que en esta aplicación se recibirán los datos iniciales en un [archivo de texto](productos.txt), que no será modificado. En cambio, se decidió que todas las operaciones para guardar y modificar información se harán sobre un archivo binario llamado `productos.dat`.

## Desarrollo del Programa en C++

En este taller es obligatorio el uso de estructuras y funciones. 

Debe usar headers para evitar que el código se vea muy extenso, y no puede usar `cin` o `cout` en ninguna parte del código que no sea el archivo `main.cpp`.

La recomendación es que debe tener los siguientes headers:

-`BinaryFileHandler.h`: en este header se encontrará la estructura `BinaryFileHandler`. La estructura debe permitir realizar ciertas operaciones sobre archivos binarios, además debe ser un template. Una parte de este [archivo](libs/BinaryFileHandler.h) ya está completo, pero debe terminar de implementar las funciones.

-`Product.h`: en este header se encontrará la estructura product, así como otra estructura llamada `ProductBinary`, que es la que usaremos como auxiliar para guardar información en el archivo binario. También se recomienda tener funciones que conviertan objetos de tipo `Product` a `ProductBinary`y viceversa. 

-`TextFileHandler.h`: Este archivo header es el que se desarrolló en el taller anterior. 

-`List.h`: Este archivo header es el que se ha usado en los demás talleres.

Desarrolle un programa que cuente con un menú que permita las siguientes operaciones:
1. **Antes de comenzar** es necesario que complete la estructura BinaryFileHandler, dentro del archivo [BinariFileHandler.h](https://github.com/clase-programacion-avanzada/CPP-Workshop-4/blob/main/libs/BinaryFileHandler.h)
   
2. **Leer archivo de texto y crear un archivo binario a partir de este:** debe leer el archivo de texto y crear un archivo binario a partir de la lista de productos (`List<Product>`).(1.0)<br />
    En este punto debe incluir una función que lea el archivo de texto y que retorne una lista de tipo `List<Product>`.<br />
    Debe crear un archivo binario que contenga la información de la lista de productos (Recuerde que en el archivo binario debe guardar elementos de tipo `ProductBinary`)
    <br />

3. **Mostrar lista de productos a partir del archivo binario:** debe mostrar la lista de productos almacenada en el punto anterior. (1.0)<br />
4. **Agregar producto al archivo binario:** debe agregar un producto a la lista de productos y actualizar el archivo binario. (1.0)<br />

5. **Eliminar producto del archivo binario:** debe eliminar un producto de la lista de productos y actualizar el archivo binario. (1.0)<br /><br />
    
6. **Buscar un producto:** 
   1. Desarrolle una [función](https://github.com/clase-programacion-avanzada/CPP-Workshop-4/blob/main/libs/Product.h#L22) que reciba como parámetros dos cadenas de caracteres que cada una representa una fecha en formato «dd/mm/yyyy» y que retorne true si la primera fecha es mayor o igual que la segunda fecha. (0.5) 
   El prototipo de la función es:
      ```cpp
        bool dateIsGreaterOrEqual(string date1,string date2);
      ```
   2. Desarrolle una [función](https://github.com/clase-programacion-avanzada/CPP-Workshop-4/blob/main/libs/Product.h#L28) que reciba como parámetro una fecha en formato «dd/mm/yyyy» y un nombre de producto, y que retorne una lista con todos aquellos productos del archivo productos.dat cuyo nombre del producto contenga el nombre del producto recibido como parámetro y cuya fecha de vigencia de la promoción sea mayor o igual a la fecha recibida como parámetro.(0.5)
      ```cpp
        List<Product> searchProducts(string date, string name);
      ``` 
   3. Desarrolle una función que, dada la lista generada con la función anterior, lo ordene de menor a mayor por el precio del producto y que grabe en un archivo llamado Mejores.txt, los 5 primeros productos de la lista ordenada. Debe grabarse toda la información del producto con cada campo separado por comas.(0.5)