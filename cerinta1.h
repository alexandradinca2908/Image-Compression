/*DINCA Alexandra-Cristina - 311CD*/

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <math.h>

//  ALLOCING AN IMAGE NODE
ImageNode createImage() {
    ImageNode newImage = malloc(sizeof(struct node));
    newImage->red = 0;
    newImage->green = 0;    
    newImage->blue = 0;
    newImage->child1 = NULL;
    newImage->child2 = NULL;
    newImage->child3 = NULL;
    newImage->child4 = NULL;
    return newImage;
}

ImageNode compressImage(Pixels **imageMatrix, int lineIdx, int colIdx, int size, int factor) {
    ImageNode newImage = createImage();
    unsigned long long red = 0, green = 0, blue = 0;
    for (int i = lineIdx; i < lineIdx + size; i++) {
        for (int j = colIdx; j < colIdx + size; j++) {
            red += imageMatrix[i][j].red;
            green += imageMatrix[i][j].green;
            blue += imageMatrix[i][j].blue;
        }
        
    }
    red /= (size * size);
    green /= (size * size);
    blue /= (size * size);

    unsigned long long mean = 0;
    for (int i = lineIdx; i < lineIdx + size; i++) {
        for (int j = colIdx; j < colIdx + size; j++) {
            unsigned long long comp1, comp2, comp3;
            comp1 = (red - imageMatrix[i][j].red) * (red - imageMatrix[i][j].red);
            comp2 = (green - imageMatrix[i][j].green) * (green - imageMatrix[i][j].green);
            comp3 = (blue - imageMatrix[i][j].blue) * (blue - imageMatrix[i][j].blue);
            mean += (comp1 + comp2 + comp3);   
        }
    }

    mean = (mean / (3 * size * size));
    
    size /= 2;

    if (mean > factor) {
        newImage->child1 = compressImage(imageMatrix, lineIdx, colIdx, size, factor);
        newImage->child2 = compressImage(imageMatrix, lineIdx, colIdx + size, size, factor);
        newImage->child3 = compressImage(imageMatrix, lineIdx + size, colIdx + size, size,
                            factor);
        newImage->child4 = compressImage(imageMatrix, lineIdx + size, colIdx, size, factor);
    } else {
        newImage->red = red;
        newImage->green = green;
        newImage->blue = blue;
    }
    return newImage;
}

int max(int a, int b) {
    if (a > b) {
        return a;
    } else {
        return b;
    }
}

int min(int a, int b) {
    if (a < b) {
        return a;
    } else {
        return b;
    }
}

//  DETERMINES THE TREE LEVEL
int levels(ImageNode imageTree) {
    if (imageTree == NULL) {
        return 0;
    }
    if (imageTree->child1 == NULL) {
        return 1;
    }
    int one, two, three, four;
    one = levels(imageTree->child1);    //  first branch
    two = levels(imageTree->child2);    //  second branch
    three = levels(imageTree->child3);  //  third branch
    four = levels(imageTree->child4);   //  fourth branch

    one = max(one, two);                //  comparison between child 1 and 2
    two = max(three, four);             //  comparison between child 3 and 4

    return max(one, two) + 1;
}

//  DETERMINES THE SMALLEST BRANCH
int smallestLevels(ImageNode imageTree) {
    if (imageTree == NULL) {
        return 0;
    }
    if (imageTree->child1 == NULL) {
        return 1;
    }
    int one, two, three, four;
    one = smallestLevels(imageTree->child1);    //  first branch
    two = smallestLevels(imageTree->child2);    //  second branch
    three = smallestLevels(imageTree->child3);  //  third branch
    four = smallestLevels(imageTree->child4);   //  fourth branch

    one = min(one, two);                //  comparison between child 1 and 2
    two = min(three, four);             //  comparison between child 3 and 4

    return min(one, two) + 1;
}

int numberOfLeaves(ImageNode imageTree) {
    if (imageTree == NULL) {
        return 0;
    }
    if (imageTree->child1 == NULL) {
        return 1;
    }
    int one, two, three, four;
    one = numberOfLeaves(imageTree->child1);    //  first branch
    two = numberOfLeaves(imageTree->child2);    //  second branch
    three = numberOfLeaves(imageTree->child3);  //  third branch
    four = numberOfLeaves(imageTree->child4);   //  fourth branch

    return (one + two + three + four);
}

//  CACULATES THE SIDE OF THE LARGEST NON-SPLIT AREA
int largestSection(ImageNode imageTree, int size) {
    if (imageTree == NULL) {
        return 0;
    }
    int one, two, three, four;
    one = smallestLevels(imageTree->child1);    //  first branch
    two = smallestLevels(imageTree->child2);    //  second branch
    three = smallestLevels(imageTree->child3);  //  third branch
    four = smallestLevels(imageTree->child4);   //  fourth branch

    one = min(one, two);                //  comparison between child 1 and 2
    two = min(three, four);             //  comparison between child 3 and 4

    int minLevel = min(one, two);       //  minimum level of the children + root
    int side = size / pow(2, minLevel);
    return side;
}

void freeTree(ImageNode imageTree) {
    if (imageTree->child1 == NULL) {
        free(imageTree);
        return;
    }
    freeTree(imageTree->child1);
    freeTree(imageTree->child2);
    freeTree(imageTree->child3);
    freeTree(imageTree->child4);
    free(imageTree);
}
