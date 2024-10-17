/*DINCA Alexandra-Cristina - 311CD*/

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <math.h>

//  CREATES A QUADTREE BASED ON AN INPUT FILE
void addValuesToTree(ImageNode imageTree, int level, FILE* in) {
    if (imageTree == NULL) {
        return;
    }
    if (level == 0) {
        unsigned char type;
        fread(&type, sizeof(unsigned char), 1, in);
        if (type == 1) {        
            fread(&imageTree->red, sizeof(unsigned char), 1, in);
            fread(&imageTree->green, sizeof(unsigned char), 1, in);
            fread(&imageTree->blue, sizeof(unsigned char), 1, in);
        } else {
            imageTree->child1 = createImage();
            imageTree->child2 = createImage();
            imageTree->child3 = createImage();
            imageTree->child4 = createImage();
        }
        return;
    }
    addValuesToTree(imageTree->child1, level - 1, in);
    addValuesToTree(imageTree->child2, level - 1, in);
    addValuesToTree(imageTree->child3, level - 1, in);
    addValuesToTree(imageTree->child4, level - 1, in);
}

//  ADDS DATA FROM A FILE IN ORDER
void iterateTree(ImageNode imageTree, FILE* in) {
    unsigned char data = 0;
    int eofCheck = fread(&data, sizeof(unsigned char), 1, in);
    for (int i = 0; eofCheck == 1; i++) {
        fseek(in, -1, SEEK_CUR);
        addValuesToTree(imageTree, i, in);
        eofCheck = fread(&data, sizeof(unsigned char), 1, in);
    }
}

void decompressImg(ImageNode imageTree, Pixels **imageMatrix, int lineIdx, int colIdx, int size) {
    if (imageTree == NULL) {
        return;
    }
    if (imageTree->child1 == NULL) {
        for (int i = lineIdx; i < lineIdx + size; i++) {
            for (int j = colIdx; j < colIdx + size; j++) {
                imageMatrix[i][j].red = imageTree->red;
                imageMatrix[i][j].green = imageTree->green;
                imageMatrix[i][j].blue = imageTree->blue;
            }
    }
        return;
    }
    size /= 2;
    decompressImg(imageTree->child1, imageMatrix, lineIdx, colIdx, size);
    decompressImg(imageTree->child2, imageMatrix, lineIdx, colIdx + size, size);
    decompressImg(imageTree->child3, imageMatrix, lineIdx + size, colIdx + size, size);
    decompressImg(imageTree->child4, imageMatrix, lineIdx + size, colIdx, size);
}