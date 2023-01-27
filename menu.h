#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <ctype.h>
#include <windows.h>
#define size 255


void view_author_alfp(LIBRARY *START); ///DONE
void view_title(LIBRARY *START); ///DONE
void view_available(LIBRARY *START); ///DONE
void view_year_increase(LIBRARY *START);///DONE
void edit_add(LIBRARY *START);///DONE
void edit_delete(LIBRARY **START);
void edit_edit();//TODO
void search_title(LIBRARY *START);///DONE
void search_year(LIBRARY *START);///DONE
void search_author(LIBRARY *START);///DONE
void search_available(LIBRARY *START);///DONE
void wait_for_user_move();


void view_menu_print(LIBRARY *START);
void search_menu_print(LIBRARY *START);
void edit_menu_print(LIBRARY *START);



void main_menu_options_print();
void view_menu();
void search_menu();
void edit_menu();

