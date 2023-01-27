#include "list.h" //deklaracje funkcji
#include "menu.h"
#include "sign.h"



int main(){
            ///DEFAULT ZMIANA
    LIBRARY *START = NULL;
    read_file(&START,"data_test.txt");
    //view_year_increase(START);
    //view_author_alfp(START);
    //search_author(START);
            ///MENU
int user_input;
    while(true){
            ///MAIN MENU
                    system("cls");
                library_sign();
                main_menu_options_print(START);
                scanf("%d",&user_input);
                while(user_input != 1 && user_input != 2 && user_input != 3 && user_input != 0 ){
                    printf("Podaj poprawna wartosc (1/2/3/0):");
                    scanf("%d",&user_input);
                }

            ///VIEW
            if(user_input == 1){
                    system("cls");
                view_menu_print(START);
            }
            ///SEARCH
            else if(user_input == 2){
                    system("cls");
                search_sign();
                search_menu_print(START);


            }
            ///EDIT
            else if(user_input == 3){
                    system("cls");
                edit_sign();
                edit_menu_print(START);


            }
            ///EXIT
            else if(user_input == 0){
                    system("cls");

                trwa_sigh();
                    sleep(1);
                    system("cls");
                synchronizacja_sigh();
                    sleep(1);
                    system("cls");
                danych_sigh();
                    sleep(1);
                    system("cls");
                    ///CLEARING MY LIST
                return 0;
            }


}
    clearr(&START);
    return 0;
}
