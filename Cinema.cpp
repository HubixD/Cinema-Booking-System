#include <iostream>
#include <string>
#include "Cinema.h"
using namespace std;

Cinema::Cinema():dir("Cinema.db")
{
    sqlite3_open(dir,&DB);
}


int Cinema::callback(void* NotUsed, int argc, char** argv, char** azColName)
{
    for(int i=0; i<argc; i++)
    {
        cout<<azColName[i]<<":"<<argv[i]<<endl;
    }

    return 0;
}

int Cinema::callback_movies(void* NotUsed, int argc, char** argv, char** azColName)
{
    for(int i=0; i<argc; i++)
    {
        cout<<argv[i]<<endl;
    }

    return 0;
}

int Cinema::callback_display(void* NotUsed, int argc, char** argv, char** azColName)
{
   for(int i=0; i<argc; i++)
    {
        cout<<argv[i]<<" | ";
        if(i%3==0 && i>0)
        {
            cout<<endl;
            cout<<endl;
        }
        else
            continue;
    }

    return 0;

}

int Cinema::callback_tickets(void* NotUsed, int argc, char** argv, char** azColName)
{
   for(int i=0; i<argc; i++)
    {
        cout<<argv[i]<<" | ";
        if(i%5==0 && i>0)
        {
            cout<<endl;
            cout<<endl;
        }
        else
            continue;
    }
    cout<<endl;

    return 0;

}

int Cinema::callback_orders(void* NotUsed, int argc, char** argv, char** azColName)
{
   for(int i=0; i<argc; i++)
    {
        cout<<argv[i]<<" | ";
        if(i%6==0 && i>0)
        {
            cout<<endl;
            cout<<endl;
        }
        else
            continue;
    }
    cout<<endl;

    return 0;

}

int Cinema::callback_occupancy(void* NotUsed, int argc, char** argv, char** azColName)
{
   for(int i=0; i<argc; i++)
    {
        cout<<argv[i]<<" | ";
        if(i%9==0 && i>0)
        {
            cout<<endl;
            cout<<endl;
        }
        else
            continue;
    }
    cout<<endl;

    return 0;

}

int Cinema::callback_track(void* NotUsed, int argc, char** argv, char** azColName)
{
   for(int i=0; i<argc; i++)
    {
        cout<<argv[i]<<" | ";
        if(i%4==0 && i>0)
        {
            cout<<endl;
            cout<<endl;
        }
        else
            continue;
    }
    cout<<endl;

    return 0;

}

int Cinema::callback3(void* NotUsed, int argc, char** argv, char** azColName)
{
    ofstream check("pompa.txt",ios::app);
        for(int i=0; i<argc; i++)
    {
        check<<argv[i]<<endl;
    }
        check.close();

        if(atoi(argv[0])==1)
        {
            return 3;
        }
        else
            return 0;

}


void Cinema::showTrack()
{
    string s = "SELECT * FROM TRACK;";

    cout<<"ID"<<" | "<<"Title"<<" | "<<"Room"<<" | "<<"Day Hour"<<" | "<<"Tickets left"<<endl;
    sqlite3_exec(DB,s.c_str(),callback_track,NULL,NULL);

}

void Cinema::addMovie(string title, string language, string type, string descrp)
{
    char* msgerror;

    string s ="INSERT INTO MOVIE (TITLE_MOVIE, LANGUAGE_MOVIE, TYPE_MOVIE, DESCRP_MOVIE) VALUES('"+ title +"','"+ language +"','"+ type+"','"+ descrp +"');";
    int rc = sqlite3_exec(DB,s.c_str(),NULL,0,&msgerror);

    if(rc != SQLITE_OK){

        cerr<<"Error while adding a movie!"<<endl;
        sqlite3_free(msgerror);

    }
    else
        cout<< "Added a new movie: "<<title<<endl;
}

void Cinema::display_movies()
{
    cout<<"TITLE"<<" | "<<"LANGUAGE"<<" | "<<"MOVIE TYPE"<<" | "<<"DESCRIPTION"<<endl;
    string s = "SELECT TITLE_MOVIE,LANGUAGE_MOVIE,TYPE_MOVIE,DESCRP_MOVIE FROM MOVIE;";
    sqlite3_exec(DB,s.c_str(),callback_display,NULL,NULL);

}


void Cinema::place_order(string id, string seat, string email,string price)
{


    string ss = "SELECT CASE WHEN COUNT(SEAT_ROW_COL) > 0 THEN 1 ELSE 0 END AS OCCUPIED FROM ORDERS WHERE SEAT_ROW_COL='"+seat+"' AND DAY_HOUR=(SELECT DAY_HOUR FROM TRACK WHERE ID_TRACK='"+id+"');";
        int verify = sqlite3_exec(DB,ss.c_str(),callback3,NULL,NULL);

        if(verify!=4)
        {
            string sss = "SELECT CASE WHEN COUNT(ID_TRACK) > 0 THEN 1 ELSE 0 END AS JEST FROM TRACK WHERE ID_TRACK='"+id+"';";
            int verify2 = sqlite3_exec(DB,sss.c_str(),callback3,NULL,NULL);

            if(verify2==4)
            {
            char* msgerror;
            string s = "UPDATE TRACK SET CAPACITY=CAPACITY-1 WHERE ID_TRACK='"+id+"';";
            int rc = sqlite3_exec(DB,s.c_str(),NULL,0,&msgerror);

            if(rc != SQLITE_OK){

            cerr<<"No such movie is being played right now"<<endl;
            sqlite3_free(msgerror);

            }
        else
        {
        s = "INSERT INTO ORDERS(ROOM,USER,SEAT_ROW_COL,DAY_HOUR,MOVIE,PRICE) VALUES ((SELECT ROOM FROM TRACK WHERE ID_TRACK='"+id+"'),'"+email+"','"+seat+"',(SELECT DAY_HOUR FROM TRACK WHERE ID_TRACK='"+id+"'),(SELECT MOVIE FROM TRACK WHERE ID_TRACK='"+id+"'),'"+price+"');";
        rc = sqlite3_exec(DB,s.c_str(),NULL,0,&msgerror);
        if(rc != SQLITE_OK){

            cerr<<"No such movie is played / seat is already occupied"<<endl;
            sqlite3_free(msgerror);
        }
        else
            cout<< "Order placed successfully"<<endl;
    }
        }
        else
            cout<<"Movie unavailable"<<endl;
        }
            else
                cout<<"Seat occupied, please try again"<<endl;

}

void Cinema::display_orders()
{
    cout<<"ORDER ID"<<" | "<<"ROOM"<<" | "<<"NAME SURNAME"<<" | "<<"SEAT"<<" | "<<"DAY HOUR"<<" | "<<"MOVIE"<<" | "<<"PRICE(zl)"<<endl;
    string s = "SELECT * FROM ORDERS;";
    sqlite3_exec(DB,s.c_str(),callback_orders,NULL,NULL);

}

void Cinema::display_occupancy()
{
    cout<<"ID"<<" | "<<"MOVIE"<<" | "<<"DAY HOUR"<<" | "<<"ROOM"<<" | "<<"MAX ROOM CAPICITY"<<" | "<<"AVAILABLE TICKETS"<<endl;
    string s = "SELECT TRACK.ID_TRACK,TRACK.MOVIE,TRACK.DAY_HOUR,ROOM.NAME_ROOM, ROOM.CAPACITY_ROOM,TRACK.CAPACITY FROM ROOM INNER JOIN TRACK ON ROOM.NAME_ROOM = TRACK.ROOM;";
    sqlite3_exec(DB,s.c_str(),callback_occupancy,NULL,NULL);
}

void Cinema::restore_room_occupancy(string id, string capacity_init)
{
    char* msgerror;

    string s ="UPDATE TRACK SET CAPACITY = "+capacity_init+" WHERE ID_TRACK='"+id+"';";
    int rc = sqlite3_exec(DB,s.c_str(),NULL,0,&msgerror);

    if(rc != SQLITE_OK){

        cerr<<"Error while restoring room capacity"<<endl;
        sqlite3_free(msgerror);

    }
    else
        cout<< "Room restored"<<endl;

}


void Cinema::show_tickets()

{
    string email = get_login();
    cout<<" | "<<"ROOM"<<" | "<<"SEAT"<<" | "<<"DAY HOUR"<<" | "<<"MOVIE"<<" | "<<"PRICE(zl)"<<endl;
    string s = "SELECT ROOM,SEAT_ROW_COL,DAY_HOUR,MOVIE,PRICE FROM ORDERS WHERE USER='"+email+"';";
    sqlite3_exec(DB,s.c_str(),callback_tickets,NULL,NULL);

}


void Cinema::update_track(string movie,string room,string day_hour,string capacity)
{
    char* msgerror;

    string s ="INSERT INTO TRACK (MOVIE,ROOM, DAY_HOUR, CAPACITY) VALUES('"+ movie +"','"+ room +"','"+day_hour+"','"+capacity+"');";
    int rc = sqlite3_exec(DB,s.c_str(),NULL,0,&msgerror);

    if(rc != SQLITE_OK){

        cerr<<"Error while updating Track"<<endl;
        sqlite3_free(msgerror);

    }
    else
        cout<< "Track updated "<<endl;

}

void Cinema::create_account(string name_surn, string email, string password)
{
    char *msgerror;

    string s ="INSERT INTO USER (NAME_SURNAME_USER, EMAIL_USER, PASSWD_USER) VALUES('"+name_surn+"','"+email+"','"+password+"');";
    int rc = sqlite3_exec(DB,s.c_str(),NULL,0,&msgerror);

    if(rc != SQLITE_OK){

        cerr<<"Error while creating account"<<endl;
        sqlite3_free(msgerror);

    }
    else
        cout<< "Account created"<<endl;
}




bool Cinema::login_user(string email, string pwd)
{
    string s = "SELECT CASE WHEN COUNT(PASSWD_USER) > 0 THEN 1 ELSE 0 END AS VERIFICATION FROM USER WHERE EMAIL_USER = \""+email+"\" AND PASSWD_USER = \""+pwd+"\";";
    int rc = sqlite3_exec(DB,s.c_str(),callback3,NULL,NULL);

      if(rc==4)
        {
          cout<<"Successfully connected"<<" "<< email <<endl;
          set_login(email);
          return true;
        }
    else
        {
        cout<<"Incorrect email or password"<<endl;
        return false;
        }
}

bool Cinema::login_admin(string email, string pwd)
{
    string s = "SELECT CASE WHEN COUNT(PASSWD_ADMIN) > 0 THEN 1 ELSE 0 END AS VERIFICATION FROM ADMIN WHERE EMAIL_ADMIN = \""+email+"\" AND PASSWD_ADMIN = \""+pwd+"\";";

    int rc = sqlite3_exec(DB,s.c_str(),callback3,NULL,NULL);


    if(rc==4)
      {
          cout<<"Successfully connected ADMIN"<<endl;
          return true;
      }
    else
    {
        cout<<"Incorrect email or password"<<endl;
        return false;
    }
}
