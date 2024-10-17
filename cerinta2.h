/*DINCA Alexandra-Cristina - 311CD*/

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <math.h>

//  PRINTS NODES IN ORDER ON THE SPECIFIED LEVEL
void printNodesForLevel(ImageNode imageTree, int level, FILE* out) {
    if (imageTree == NULL) {
        return;
    }
    if (level == 0) {
        unsigned char type = 1;
        if (imageTree->child1 == NULL) {
            fwrite(&type, sizeof(unsigned char), 1, out);
            fwrite(&imageTree->red, sizeof(unsigned char), 1, out);
            fwrite(&imageTree->green, sizeof(unsigned char), 1, out);
            fwrite(&imageTree->blue, sizeof(unsigned char), 1, out);
        } else {
            type = 0;
            fwrite(&type, sizeof(unsigned char), 1, out);
        }
        return;
    }
    printNodesForLevel(imageTree->child1, level - 1, out);
    printNodesForLevel(imageTree->child2, level - 1, out);
    printNodesForLevel(imageTree->child3, level - 1, out);
    printNodesForLevel(imageTree->child4, level - 1, out);
}

//  PRINTS ALL NODES IN LEVEL ORDER
void printLevelOrder(ImageNode imageTree, FILE* out) {
    int level = levels(imageTree);
    for (int i = 0; i < level; i++) {
        printNodesForLevel(imageTree, i, out);
    }
}