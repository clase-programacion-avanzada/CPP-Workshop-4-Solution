#ifndef BINARY_FILEHANDLER_H
#define BINARY_FILEHANDLER_H

#include "List.h"
#include <string>
#include <fstream>

using namespace std;

template <typename T>
struct BinaryFileHandler {

    string fileName;

    BinaryFileHandler(string path) {
        fileName = path;
    }
    
    bool writeBinaryFile(List<T> list) {

        fstream file;

    

        return true;
    }

    List<T> readBinaryFile() {

        List<T> list;

        fstream file;


        return list;
    }

    bool appendElementToFile(T element) {
        
        fstream file;

    

        return true;
    }

    T getElementFromFile(int index) {

        fstream file;

        file.open(fileName, ios::in | ios::binary);

        if (file.fail()) {
            return T();
        }

        file.seekg(index * sizeof(T), ios::beg);

        T element;

        file.read(reinterpret_cast<char *>(&element), sizeof(T));

        file.close();

        return element;
    }

    bool removeElementFromFile(int index) {

        fstream file;

        int fileSize = getFileSize();

        file.open(fileName, ios::out | ios::binary);

        if (file.fail()) {
            return false;
        }

        int elementsCount = fileSize / sizeof(T);

        if (index < 0 || index >= elementsCount) {
            return false;
        }

        for (int i = 0; i < elementsCount; i++) {
            if (i != index) {
                T element = getElementFromFile(i);
                file.write(reinterpret_cast<char *>(&element), sizeof(T));
            }
        }

        file.close();

        return true;
    }

    int getFileSize() {

        fstream file;

        file.open(fileName, ios::in | ios::binary);

        if (file.fail()) {
            return -1;
        }

        file.seekg(0, ios::end);
        int fileSize = file.tellg();
        file.close();

        return fileSize;
    }


    


};

#endif /* MYHEADER_H */