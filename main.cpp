#include <iostream>
#include "Application.h"
using namespace std;


int main()
{

//Control variables
bool on = true;
Application a;
int choice;

// Program execution and whole menu with switch statements

a.welcome();

while(on)
{
    a.menu();

    cout<<"Choose option: ";
    if ( !(cin >>choice) )
        {
          cin.clear();
          cin.ignore();
          cout << "Incorrect entry. Try again: ";
        }

    switch(choice)
    {

    case 1:
        {

            bool ctrl = true;
            int choice2;
            while(ctrl)
            {
                a.loginmenu();
                cout<<"Choose option: ";
                if ( !(cin >>choice2) )
                {
                    cin.clear();
                    cin.ignore();
                    cout << "Incorrect entry. Try again: ";
                }
                cout<<endl;
                switch(choice2)
                {

                case 1:
                    {
                        if(a.loginuser())
                        {
                            bool login = true;

                            while(login)
                            {
                            a.user_menu();
                            cout<<"What do you want to do? Choose option:";

                            if ( !(cin >>choice2) )
                            {
                                cin.clear();
                                cin.ignore();
                                cout << "Incorrect entry. Try again: ";
                            }

                            switch(choice2)
                            {
                            case 1:
                                {
                                    a.show_track();
                                    break;
                                }
                            case 2:
                                {
                                    a.place_order();
                                    break;
                                }
                            case 3:
                                {
                                    a.displaymovies();
                                    break;
                                }
                            case 4:
                                {
                                    a.showtickets();
                                    break;
                                }
                            case 5:
                                {
                                    login = false;
                                    break;
                                }
                            default:
                                {
                                    cout<<"Wrong input, Back to user panel"<<endl;
                                    system("pause");
                                    continue;
                                }
                            }
                        }
                        }
                        else
                        {
                            cout<<"Back to main menu"<<endl;
                            system("pause");
                            ctrl = false;
                        }


                        break;
                    }
                case 2:
                    {
                        if(a.loginadmin())
                         {
                            bool login = true;

                            while(login)
                            {
                            a.admin_menu();
                            cout<<"What do you want to do? Choose option:";

                            if ( !(cin >>choice2) )
                            {
                                cin.clear();
                                cin.ignore();
                                cout << "Incorrect entry. Try again: ";
                            }
                            switch(choice2)
                            {
                            case 1:
                                {
                                    a.show_track();
                                    break;
                                }
                            case 2:
                                {
                                    a.addMovie();
                                    break;
                                }
                            case 3:
                                {
                                    a.displayorders();
                                    break;
                                }
                            case 4:
                                {
                                    a.displayoccupancy();
                                    break;
                                }
                            case 5:
                                {
                                    a.restore_room();
                                    break;
                                }
                            case 6:
                                {
                                    a.updatetrack();
                                    break;
                                }
                            case 7:
                                {
                                    login = false;
                                    break;
                                }
                            default:
                                {
                                    cout<<"Wrong input, Back to admin panel"<<endl;
                                    system("pause");
                                    continue;
                                }
                            }
                        }
                        }
                        else
                        {
                            cout<<"Back to main menu"<<endl;
                            system("pause");
                            ctrl = false;
                        }


                        break;
                    }
                case 3:
                    {
                        ctrl = false;
                        break;
                    }
                default:
                    {
                        cout<<"Wrong input"<<endl;
                        system("pause");
                        continue;
                    }
                }
            }


            break;
        }

    case 2:
        {
            a.createaccount();
            break;
        }

    case 3:
        {
            on = false;
            break;
        }

    default:
            {
            cout<<"Wrong input"<<endl;
            system("pause");
            system("CLS");
            break;
            }
    }

}
    return 0;
}
