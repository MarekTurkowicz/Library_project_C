#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <ctype.h>
#include <windows.h>
#define size 255
typedef struct
{
    int catalog_nb;
    char author[size];
    char title[size];
    char category[size];
    int date;
    char publ_house[size];
    int is_available;
    struct LIBRARY* next;
}LIBRARY;

void add_element(LIBRARY **first_el,int cat,char aut[size],char tit[size], char cate[size], char publ_h[size], int date, int is_av);
void save_in(LIBRARY **START);
void change_to_floor(char* character);
void change_to_space(char* character);
void print_list(LIBRARY *f);
void print_element(LIBRARY *START);
void read_file(LIBRARY *START, char *file_name);
void write_file(LIBRARY *START, char *file_name);
bool available_status(LIBRARY *START);
bool is_empty(LIBRARY *START);
bool is_alone(LIBRARY *START);
int amount_of_elements(LIBRARY *START);
bool is_available_catalog_nb(LIBRARY *START,int number);
void insertion_sort(LIBRARY *START);
void clearr(LIBRARY **START);
