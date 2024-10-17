/*DINCA Alexandra-Cristina - 311CD*/

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <math.h>
#include "struct.h"
#include "cerinta1.h"
#include "cerinta2.h"
#include "cerinta3.h"

int main(int argc, char *argv[]) {
    //  READING ARGUMENTS FROM COMMAND LINE

    char flag[4] = {0}, imageType[3] = {0};
    int factor = 0;
    FILE *in, *out;
    strncpy(flag, argv[1], 3);
    if (flag[1] != 'd') {
        factor = atoi(argv[2]);
        in = fopen(argv[3], "rb");
        if (in == NULL) {
            printf("ERROR: COULD NOT OPEN FILE\n");
            return -1;
        }
        out = fopen(argv[4], "wt");
        if (out == NULL) {
            printf("ERROR: COULD NOT OPEN FILE\n");
            return -1;
        }
    } else {
        in = fopen(argv[2], "rb");
        if (in == NULL) {
            printf("ERROR: COULD NOT OPEN FILE\n");
            return -1;
        }
        out = fopen(argv[3], "wb");
        if (out == NULL) {
            printf("ERROR: COULD NOT OPEN FILE\n");
            return -1;
        }
    }

    //  EXECUTING ONE OF THE 3 TASKS

    //  TASK 1
    if (strcmp(flag, "-c1") == 0) {
        //  READING THE FILE HEADER 
        fscanf(in, "%s\n", imageType);
        int width = 0, height = 0, maxValue = 0;
        fscanf(in, "%d %d\n%d\n", &width, &height, &maxValue);

        Pixels **imageMatrix = malloc(height * sizeof(Pixels *));
        for (int i = 0; i < width; i++) {
            imageMatrix[i] = malloc(width * sizeof(Pixels));
        }
        for (int i = 0; i < height; i++) {
            for (int j = 0; j < width; j++) {
                fread(&imageMatrix[i][j].red, sizeof(unsigned char), 1, in);
                fread(&imageMatrix[i][j].green, sizeof(unsigned char), 1, in);
                fread(&imageMatrix[i][j].blue, sizeof(unsigned char), 1, in);
            }
        }
        
        ImageNode imageTree = compressImage(imageMatrix, 0, 0, height, factor);
        int level = levels(imageTree);
        int leaves = numberOfLeaves(imageTree);
        int section = largestSection(imageTree, height);
        fprintf(out, "%d\n%d\n%d\n", level, leaves, section);

        // FREE
        for (int i = 0; i < width; i++) {
            free(imageMatrix[i]);
        }
        free(imageMatrix);
        freeTree(imageTree);

    //  TASK 2    
    } else if (strcmp(flag, "-c2") == 0) {
        //  READING THE FILE HEADER
        fscanf(in, "%s\n", imageType);
        int width = 0, height = 0, maxValue = 0;
        fscanf(in, "%d %d\n%d\n", &width, &height, &maxValue);
        Pixels **imageMatrix = malloc(height * sizeof(Pixels *));
        for (int i = 0; i < width; i++) {
            imageMatrix[i] = malloc(width * sizeof(Pixels));
        }

        //  CREATING MATRIX AND QUAD TREE
        for (int i = 0; i < height; i++) {
            for (int j = 0; j < width; j++) {
                fread(&imageMatrix[i][j].red, sizeof(unsigned char), 1, in);
                fread(&imageMatrix[i][j].green, sizeof(unsigned char), 1, in);
                fread(&imageMatrix[i][j].blue, sizeof(unsigned char), 1, in);
            }
        }
        ImageNode imageTree = compressImage(imageMatrix, 0, 0, height, factor);

        //  PRINTS DATA IN FILE
        unsigned int size = (unsigned int)(height);
        fwrite(&size, sizeof(unsigned int), 1, out);
        printLevelOrder(imageTree, out);

        //  FREE
        for (int i = 0; i < width; i++) {
            free(imageMatrix[i]);
        }
        free(imageMatrix);
        freeTree(imageTree);
    
    //  TASK 3
    } else if (strcmp(flag, "-d") == 0) {
        //  CREATING MATRIX AND QUAD TREE
        ImageNode imageTree = createImage();
        unsigned int size = 0;
        fread(&size, sizeof(unsigned int), 1, in);
        Pixels **imageMatrix = malloc(size * sizeof(Pixels *));
        for (int i = 0; i < size; i++) {
            imageMatrix[i] = malloc(size * sizeof(Pixels));
        }

        //  ADDING THE DATA IN THE TREE, THEN THE MATRIX
        iterateTree(imageTree, in);
        decompressImg(imageTree, imageMatrix, 0, 0, size);

        //  PRINTS DATA IN FILE
        fprintf(out, "%s\n%d %d\n%d\n", "P6", size, size, 255);
        for (int i = 0; i < size; i++) {
            for (int j = 0; j < size; j++) {
                fwrite(&imageMatrix[i][j].red, sizeof(unsigned char), 1, out);
                fwrite(&imageMatrix[i][j].green, sizeof(unsigned char), 1, out);
                fwrite(&imageMatrix[i][j].blue, sizeof(unsigned char), 1, out);
            }
        }

        //  FREE
        for (int i = 0; i < size; i++) {
            free(imageMatrix[i]);
        }
        free(imageMatrix);
        freeTree(imageTree);
    }

    //  CLOSING FILES
    fclose(in);
    fclose(out);
    return 0;
}