#include <iostream>
#include <fstream>
#include <cstring>
#include <string>
#include "cgi/cgi.h"

using namespace std;


void show_form(){
    cout<<"form action='tree.cgi' method='post'>\n"
          "<select>\n"
          "  <option>По фамилии</option>\n"
          "  <option>По среднему баллу</option>\n"
          "</select>"
          "<input name=\"btn\" class=\"submitbtn\" type=\"submit\" title=\"Отправить\">\n"
          "</form>"<<endl;
}
void show_content(){
//    ifstream f("data/comments.data", ios::binary);
//    if(f.is_open()){
//        Comment comment;
//        f.seekg(0, ios::beg);
//        cout<<"<div'>\n";
//        while(f.read((char*)&comment, sizeof(Comment))){
//            cout<<"<div class='comment'>"
//                <<"<h4 class='author'>"<<comment.name<<" "<<comment.surname<<"</h4>"
//                <<"<div>\n"<<comment.text<<"</div>"
//                <<"</div>\n"<<endl;
//        }
//        cout<<"</div>\n";
//        f.close();
//    }
}

int main() {
    cout << "Content-type: text/html;"
            "charset=utf-8\n\n";

    ifstream f;
    f.open("tree.html");
    if (f.is_open()){
        char *buf = new char[65536];
        while (!f.eof()) {
            f.getline(buf, 65536);
            if (strcmp(buf, "<!--main-content-->") == 0) {
                show_form();
                show_content();
            }
            cout << buf << endl;
        }
        delete[] buf;
        f.close();
    }
    return 0;
}