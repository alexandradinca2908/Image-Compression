/*DINCA Alexandra-Cristina - 311CD*/

typedef struct node {
    unsigned char red;
    unsigned char green;
    unsigned char blue;
    struct node *child1;
    struct node *child2;
    struct node *child3;
    struct node *child4;
} *ImageNode;

typedef struct pixel {
    unsigned char red;
    unsigned char green;
    unsigned char blue;
} Pixels;