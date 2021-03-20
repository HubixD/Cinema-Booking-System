#include <iostream>
#include <string>
#include "sqlite3.h"
#include "Cinema.h"
using namespace std;

class Application
{
private:
Cinema c;   //heart of the application - communication with the database and user interface

public:
Application();  //default constructor
void welcome(); //welcome animation
void menu();    //main-menu window
void loginmenu();   //login menu
bool loginuser();   //login user window
bool loginadmin();  //login admin window
void user_menu();   // menu for user
void admin_menu();  //menu for admin
void show_track();  //shows track for the cinema
void addMovie();    // admin may add a movie
void displaymovies();   //displays movies and info that are currently played
void place_order(); //user windows for placing an order
void displayorders(); //displays all orders for admin
void displayoccupancy();    //shows the statistics for admin
void restore_room();    //admin may edit the tickets/vacant seats
void showtickets(); //show tickets for logged in user
void updatetrack(); //admin may update the track
void createaccount();   //create account window for new users

};

