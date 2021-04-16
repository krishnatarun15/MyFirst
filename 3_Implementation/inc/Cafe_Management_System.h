/*The required header files for the "Cafe Management System"
For the standard inputs and outputs stdio.h is used.
For the Console inputs and outputs conio.h is used.
For the String function string.h is used
For the standard library functions stdlib.h is used. */
#include<stdio.h>
#include<conio.h>
#include<string.h>
#include<stdlib.h>

struct cafe
{
  //Structure Cafe is created to include menu in the Cafe which is stored in the external text file.
}

struct payments
{
  //Structure  payments is created to store bills details in the bill text file.
}


/*This is the ADMIN Portal in Cafe Management System in which admin can
add,remove,view items and payments after choosing the selection in welcome page. */
void admin()
{
  1.ADD NEW ITEM TO MENU
  2.REMOVE ITEM FROM MENU
  3.VIEW PAYMENTS
  4.BACK TO LOGIN
  5.VIEW MENU
    //A Switch case is added and when admin selects the required case particular action is performed.
}

/*This is the USER Portal in Cafe Management System in which user user can refer the contactless 
menu digitally and search the items and its price and can self generate the bill. */

void user()
{
  //User can view menu and submit the response using Y=Yes or N=No.
  //User can Select items until they give N=No response to the "choose next item".
}

/*This Function is for Admin where he can add the items.
void addition()
{
//In Addition function Admin can add the item into the menu with its Serial Number,Item Name,Price.
}
/*Admin creates and view menu
User can refer menu and select items. */ 
void menu()
{
  //Serial Number,Item Name,Price are displayed in Menu.
}

/*User can search the item from the referred menu */
void search()
{
  //User can search the Item with serial number and atlast bill is generated.
}

/*Based on User responses bill is generated at last. */
void billing()
{
  //In other file all the bills are stored.
}

/*Admin have access to this file. */ 
void payments()
{
//Admin have the list of payment history in the another readme file where the bill details are stored.
}


/*Admin can Delete Items using serial number from the Menu. */
void deletingitems()
{
//Items In Menu are deleted
}

/*This is the User Interface of the "Cafe Management System" application. */
void introduction()
{
//A welcome message is displayed.
//Cafe name is displayed.
//Regards of management team is displayed.
}

/*It is in main method. */
void back()
{
//User and Admin can go to the login.
}
