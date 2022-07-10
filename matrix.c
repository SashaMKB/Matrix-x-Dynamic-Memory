#include <stdio.h>
#include <stdlib.h>
// 1.Array of pointers to array segments within one buffer
// 2.Array of pointers to arrays
// 3.Array of pointers to segments of the second array
void first_func() {
    int help;
    int lenght;
    int hight;
    scanf("%d",&lenght);
    scanf("%d", &hight);
    int** single_array_matrix = malloc(lenght*hight*sizeof(int) + lenght*sizeof(int*));
    int* ptr = (int*)(single_array_matrix + lenght);
    
    for (int i = 0; i < lenght; i++) {
        single_array_matrix[i] = ptr + hight*i;
    }
    for (int i = 0;i < lenght; i++) {
        for (int j = 0; j < hight; j++) {
            if (scanf("%d", &help) == 1) {
            single_array_matrix[i][j] = help;
        }
    }
}
    for (int i = 0; i < lenght; i++) {
        printf("\n");
        for (int j = 0; j < hight; j++) {
            printf("%d ", single_array_matrix[i][j]);
        }
    }
    free(single_array_matrix);
}
void second_func() {
    int help;
    int lenght;
    int hight;
    scanf("%d",&lenght);
    scanf("%d", &hight);
    int** pointer_array = malloc(lenght*sizeof(int*));
    for(int i = 0; i < lenght; i++) {
    pointer_array[i]=malloc(hight*sizeof(int));
    }
    for (int i = 0;i < lenght; i++) {
        for (int j = 0; j < hight; j++) {
            if (scanf("%d", &help) == 1) {
                pointer_array[i][j] = help;
        }
    }
}
    for (int i = 0; i < lenght; i++) {
        printf("\n");
        for (int j = 0; j < hight; j++) {
            printf("%d ", pointer_array[i][j]);
        }
    }
    for (int i = 0; i < lenght; i++) {
        free(pointer_array[i]);
    }
    free(pointer_array);
}
void third_func() {
    int help;
    int lenght;
    int hight;
    scanf("%d",&lenght);
    scanf("%d", &hight);
    int** pointer_array = malloc(lenght*sizeof(int*));
    int* values_array = malloc (lenght*hight*sizeof(int));
    for(int i = 0; i < lenght; i++) {
    pointer_array[i]=values_array + hight*i;
    }
    for (int i = 0;i < lenght; i++) {
        for (int j = 0; j < hight; j++) {
            if (scanf("%d%c", &help) == 1) {
                pointer_array[i][j] = help;
        }
    }
}
    for (int i = 0; i < lenght; i++) {
        printf("\n");
        for (int j = 0; j < hight; j++) {
            printf("%d ", pointer_array[i][j]);
        }
    }
    free(values_array);
    free(pointer_array);
}


void menu() {
    int choice;
    printf("Please,enter type of memore allocation:\n");
    printf("1.First dynamic\n2.Seconf dynamic\n3.Third dynamic\n");
    scanf("%d", &choice);
    if (choice == 1) {
        first_func();
    } else if (choice == 2) {
            second_func();
    } else if (choice == 3) {
        third_func();
    } else {
        printf("Error");
    }
}

int main() {
    menu();
    return 0;
}
