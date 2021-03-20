#include <iostream>
#include <string>
#include <fstream>
#include "sqlite3.h"
using namespace std;


class Cinema
{

private:
const char* dir;      //access to database
sqlite3* DB;
string e;             //information about the user who is logging in
static int callback(void* NotUsed, int argc, char** argv, char** azColName);                      // various callbacks for user-friendly displaying interface
static int callback_movies(void* NotUsed, int argc, char** argv, char** azColName);
static int callback_display(void* NotUsed, int argc, char** argv, char** azColName);
static int callback_tickets(void* NotUsed, int argc, char** argv, char** azColName);
static int callback_orders(void* NotUsed, int argc, char** argv, char** azColName);
static int callback_occupancy(void* NotUsed, int argc, char** argv, char** azColName);
static int callback3(void* NotUsed, int argc, char** argv, char** azColName);
static int callback_track(void* NotUsed, int argc, char** argv, char** azColName);

public:
Cinema();   //default constructor
void showTrack();   //displays the whole track in the cinema
void addMovie(string title, string language, string type, string descrp);   //admin can add movies
void display_movies();  //displays current available movies
void place_order(string id, string seat, string email,string price);    // placing order method for customers
void display_orders();  //displays all orders for the admin
void display_occupancy();   //shows the admin room statistics
void restore_room_occupancy(string id, string capacity_init); //editing panel for the admin
void show_tickets();    //displays tickets for the logged in user
void update_track(string movie,string room,string day_hour,string capacity);    //admin may add update the track
void create_account(string name_surn, string email, string password);   // creates account for new users
bool login_user(string email, string pwd);  //login panel with verification for user
bool login_admin(string email, string pwd); //login panel with verification for admin
void set_login(string email){e = email;};   //information about logged in user
string get_login(){return e;};  //retrieving information about logged in user
};


