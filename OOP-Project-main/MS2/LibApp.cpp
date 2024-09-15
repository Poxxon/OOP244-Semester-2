/* Citation and Sources...
Final Project Milestone 2
Module: LibApp
Filename: LibApp.cpp
Version 1.0
Author	Pouya Rad
Revision History
-----------------------------------------------------------
Date      Reason
2024/7/1  Preliminary release
2024/?/?  Debugged DMA
-----------------------------------------------------------
I have done all the coding by myself and only copied the code
that my professor provided to complete my workshops and assignments.
-----------------------------------------------------------*/


#include "LibApp.h"
#include <iostream>

using namespace std;

namespace seneca {

    LibApp::LibApp()
        : m_changed(false),
        m_mainMenu("Seneca Library Application"),
        m_exitMenu("Changes have been made to the data, what would you like to do?") {
        m_mainMenu.add("Add New Publication");
        m_mainMenu.add("Remove Publication");
        m_mainMenu.add("Checkout publication from library");
        m_mainMenu.add("Return publication to library");

        m_exitMenu.add("Save changes and exit");
        m_exitMenu.add("Cancel and go back to the main menu");

        load();
    }

    bool LibApp::confirm(const char* message) {
        Menu confirmMenu(message);
        confirmMenu.add("Yes");
        return confirmMenu.run() == 1;
    }

    void LibApp::load() {
        cout << "Loading Data" << endl;
    }

    void LibApp::save() {
        cout << "Saving Data" << endl << endl;
    }

    void LibApp::search() {
        cout << "Searching for publication" << endl;
    }

    void LibApp::returnPub() {
        search();
        cout << "Returning publication" << endl;
        cout << "Publication returned" << endl << endl;
        m_changed = true;
    }

    void LibApp::newPublication() {
        cout << "Adding new publication to library" << endl;
        if (confirm("Add this publication to library?")) {
            m_changed = true;
            cout << "Publication added" << endl << endl;
        }
        else {
            cout << endl;
        }
    }

    void LibApp::removePublication() {
        cout << "Removing publication from library" << endl;
        search();
        if (confirm("Remove this publication from the library?")) {
            m_changed = true;
            cout << "Publication removed" << endl << endl;
        }
        else {
            cout << endl;
        }
    }

    void LibApp::checkOutPub() {
        search();
        if (confirm("Check out publication?")) {
            m_changed = true;
            cout << "Publication checked out" << endl << endl;
        }
        else {
            cout << endl;
        }
    }

    void LibApp::run() {
        bool done = false;
        while (!done) {
            int selection = m_mainMenu.run();
            switch (selection) {
            case 1:
                newPublication();
                break;
            case 2:
                removePublication();
                break;
            case 3:
                checkOutPub();
                break;
            case 4:
                returnPub();
                break;
            case 0:
                if (m_changed) {
                    int exitSelection = m_exitMenu.run();
                    if (exitSelection == 1) {
                        save();
                        done = true;
                    }
                    else if (exitSelection == 0) {
                        if (confirm("This will discard all the changes are you sure?")) {
                            cout << endl;
                            done = true;
                        }
                        else {
                            cout << endl;
                        }
                    }
                    else {
                        cout << endl;
                    }
                }
                else {
                    cout << endl; 
                    done = true;
                }
                break;
            }
        }
        cout << "-------------------------------------------" << endl;
        cout << "Thanks for using Seneca Library Application" << endl ;
    }

}
