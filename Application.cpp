#include <iostream>
#include "Application.h"
#include <unistd.h>
using namespace std;

Application::Application()
    {

    }


void Application::welcome()
    {
        cout<<"Welcome to Cinema City"<<endl;
        sleep(2);

    }

void Application::menu()
{
    system("CLS");
    cout<<"1. Sign in "<<endl;
    cout<<" "<<endl;
    cout<<"2. Sign up "<<endl;
    cout<<" "<<endl;
    cout<<"3. Exit "<<endl;
}

void Application::loginmenu()
{

    system("CLS");
    cout<<"1. Customer login"<<endl;
    cout<<" "<<endl;
    cout<<"2. Admin login"<<endl;
    cout<<" "<<endl;
    cout<<"3. Exit "<<endl;

}

void Application::createaccount()
{
string name_sur,email,passwd;

cout<<"Welcome to Cinema City - account configuration panel"<<endl;
cout<<"Enter your name and surname: ";
cin.ignore();
getline(cin,name_sur);

cout<<"Enter your email: ";
getline(cin,email);

cout<<"Enter your password: ";
getline(cin,passwd);

c.create_account(name_sur,email,passwd);
system("pause");

}

bool Application::loginuser()
{
 string email,passwd;

    cout<<"Email: "<<endl;
    cin.ignore();
    getline(cin,email);

    cout<<"Password: "<<endl;
    getline(cin,passwd);

    if (c.login_user(email,passwd)){
        cout<<"Access granted"<<endl;
        return true;
    }
    else{
        cout<<"Wrong account"<<endl;
        return false;
    }
}

bool Application::loginadmin()
{
 string email,passwd;

    cout<<"Email: "<<endl;
    cin.ignore();
    getline(cin,email);

    cout<<"Password: "<<endl;
    getline(cin,passwd);


    if (c.login_admin(email,passwd)){
        cout<<"Access granted"<<endl;
        return true;
    }
    else {
        cout<<"Wrong account"<<endl;
        return false;
    }

}

void Application::user_menu()
{
    system("CLS");
    cout<<"1. Show track(current played movies) "<<endl;
    cout<<"2. Book your ticket "<<endl;
    cout<<"3. Show all movies "<<endl;
    cout<<"4. Show my tickets "<<endl;
    cout<<"5. Exit "<<endl;

}

void Application::admin_menu()
{
    system("CLS");
    cout<<"1. Show track(current played movies) "<<endl;
    cout<<"2. Add a movie "<<endl;
    cout<<"3. Display all orders "<<endl;
    cout<<"4. Display the room occupancy "<<endl;
    cout<<"5. Restore room "<<endl;
    cout<<"6. Update track "<<endl;
    cout<<"7. Exit "<<endl;
}


void Application::show_track()
{
    system("CLS");
    c.showTrack();
    system("pause");
}

void Application::addMovie()
{
    system("CLS");
    string title,language,type,descrp;

    cout<<"Movie adding panel"<<endl;
    cout<<" "<<endl;

    cout<<"Provide the title: "<<endl;
    cin.ignore();
    getline(cin,title);

    cout<<"Provide the language: "<<endl;
    getline(cin,language);

    cout<<"Provide the type: "<<endl;
    getline(cin,type);

    cout<<"Provide the description: "<<endl;
    getline(cin,descrp);

    c.addMovie(title,language,type,descrp);
    system("pause");

}

void Application::displaymovies()
{
    system("CLS");
    c.display_movies();
    system("pause");
}

void Application::place_order()
{

    system("CLS");
    string id,seat,email;
    c.showTrack();
    system("pause");
    cout<<"Choose movie[id]: "<<endl;
    cin.ignore();
    getline(cin,id);


    cout<<"Choose seat(Please specify as format 'R:number C:number'): "<<endl;
    cout<<"Rows 1-10 and Columns 1-10"<<endl;
    getline(cin,seat);

    cout<<"Enter your email: "<<endl;
    getline(cin,email);

    c.place_order(id,seat,email,"15");
    system("pause");

}

void Application::displayorders()
{
    system("CLS");
    c.display_orders();
    system("pause");
}

void Application::displayoccupancy()
{
    system("CLS");
    c.display_occupancy();
    system("pause");
}

void Application::restore_room()
{
    system("CLS");
    string id,capacity;

    c.showTrack();
    cout<<endl;
    cout<<endl;

    c.display_occupancy();

    cout<<"Specify the track id: "<<endl;
    cin.ignore();
    getline(cin,id);

    cout<<"Specify the capacity: "<<endl;
    getline(cin,capacity);

    c.restore_room_occupancy(id,capacity);
    system("pause");

}

void Application::showtickets()
{
    system("CLS");

    c.show_tickets();

    system("pause");
}

void Application::updatetrack()
{
    system("CLS");
    string movie,room,day_hour,capacity;
    c.display_movies();

    cout<<"Which movie: "<<endl;
    cin.ignore();
    getline(cin,movie);

    cout<<"Which room: "<<endl;
    getline(cin,room);

    cout<<"What day and hour: "<<endl;
    getline(cin,day_hour);

    cout<<"What is the maximum capacity: "<<endl;
    getline(cin,capacity);

    c.update_track(movie,room,day_hour,capacity);
    system("pause");
}
