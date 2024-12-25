#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <conio.h>
#include <stdbool.h>
#include "function.h"
#include "random.h"
#include "sort.h"
#define RANDOM_MIN 65
#define RANDOM_MAX 122
#define STR_SIZE_MIN 1
#define STR_SIZE_MAX 100
#define STR_N_MIN 1
#define STR_N_MAX 20


int main() {
    srand(time(NULL));
    do {
        printf("Hello,\nThis program sorts strings (inputed by user or randomly). Works with latin symbols ONLY\n");
        int str_size = 0;
        int n_str = 0;
        do {
            printf("Enter a string size (1-100):\n");
            if (scanf("%d", &n_str) != 1 || n_str < STR_SIZE_MIN || n_str > STR_SIZE_MAX) {
                printf("Incorrect input\n");
            }
            while (getchar() != '\n') {
            };
        } while (n_str < STR_SIZE_MIN || n_str > STR_SIZE_MAX);
        do {
            printf("Enter an amount of symbols (1-20):\n");
            if (scanf("%d", &str_size) != 1 || str_size < STR_N_MIN || str_size > STR_N_MAX) {
                printf("Incorrect input\n");
            }
            while (getchar() != '\n') {
            };
        } while (str_size < STR_N_MIN || str_size > STR_N_MAX);

        char string_value[n_str][str_size + 1] = {};
        char *addres[n_str] = {};
        for (int i = 0; i < n_str; i++) {
            addres[i] = string_value[i];
        }
        int choice = 0;
        while (getchar() != '\n') {
        };
        printf("Type 1 to input by yourself or 2 for random\n");
        do {
            choice = getch();
            switch (choice) {
                case '1':
                    bool validInput;
                    printf("Enter the string [maximum %d]:\n", str_size);
                    for (int i = 0; i < n_str; i++) {
                        do {
                            while (getchar() != '\n') {
                            };
                            printf("String %d: ", i + 1);
                            fgets(string_value[i], str_size + 2, stdin);
                            string_value[i][strcspn(string_value[i], "\n")] = '\0';
                            if (strlen(string_value[i]) > str_size) {
                                printf("String is too long\n");
                                validInput = false;
                            } else if (strchr(string_value, ' ') != NULL) {
                                printf("Strings can`t contain SPACE\n");
                                validInput = false;
                            } else {
                                string_value[i][strcspn(string_value[i], "\n")] = '\0';
                                validInput = true;
                            }
                        } while (!validInput);
                    }
                    break;
                case '2':
                    for (int i = 0; i < n_str; i++) {
                        for (int j = 0; j < str_size; j++) {
                            string_value[i][j] = randomizer(RANDOM_MIN, RANDOM_MAX);
                        }
                        string_value[i][str_size] = '\0';
                    }
                    break;
                default:
                    printf("Wrong input, choose 1 or 2:\n");
                    break;
            }
        } while (choice != '1' && choice != '2');

        print_array(addres, n_str, "Before sorting:\n");

        int output = 0;
        while (getchar() != '\n') {
        };
        printf("Choose way of sorting (1 for descending or 2 for ascending)\n");
        do {
            output = getch();
            switch (output) {
                case '1':
                    sort_descending(addres, n_str);
                    print_array(addres, n_str, "After sorting:\n");
                    break;
                case '2':
                    sort_ascending(addres, n_str);
                    print_array(addres, n_str, "After sorting:\n");
                    break;
                default:
                    printf("Wrong input, choose 1 or 2:\n");
                    break;
            }
        } while (output != '1' && output != '2');

        printf("Press 'r' to restart a program or any key to finish\n");
    } while (getchar() == 114);
    return 0;
}
