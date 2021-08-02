#include<iostream>
#include<string>
#include<fstream>
#include<map>
#include<vector>
#include<direct.h>
using namespace std ;

int main(){
    map<int,string> contest_type ;
    contest_type[0] = "ABC" ;
    contest_type[1] = "ARC" ;
    contest_type[2] = "AGC" ;
    contest_type[3] = "marathon" ;
    contest_type[4] = "other" ;
    vector<vector<string>> files = {
        {"a.cpp","b.cpp","c.cpp","d.cpp","e.cpp","f.cpp","g.cpp","h.cpp"},
        {"a.cpp","b.cpp","c.cpp","d.cpp"},
        {"a.cpp","b.cpp","c.cpp","d.cpp"},
        {"run.cpp","score.cpp"}
    } ;
    cout << "ABC -> 0\nARC -> 1\nAGC -> 2\nmarathon -> 3\nother -> 4\n" << endl ;
    cout << "Choose contest type: " ; 
    int type ; cin >> type ;
    if(type<0||type>4){
        cout << "Invalid contest type." << endl ;
        return 0 ;
    }
    cout << endl ;
    cout << "Enter contest name: " << (type<3?contest_type[type]:"") ;
    string name ;
    cin >> name ;
    if(type==4){
        cout << "What's the name of sorcefile you want to make?\n(enter \"fin\" when you list up all)" << endl ;
        string s ;
        while(true){
            cin >> s ;
            if(s=="fin") break ;
            if(s.find(".cpp")==string::npos) s += ".cpp" ;
            files[4].push_back(s) ;
        }
    }
    if(type<3) name = contest_type[type]+name ;
    string line ;
    vector<string> temp ;
    ifstream read ;
    read.open("Library\\template.cpp") ;
    while(!read.eof()){
        getline(read,line) ;
        temp.push_back(line) ;
    }
    read.close() ;
    string folder = name ;
    _mkdir(folder.c_str()) ;
    folder += "\\" ;
    ofstream write ;
    for(auto s:files[type]){
        name = folder+s ;
        cout << name << endl ;
        write.open(name) ;
        for(auto t:temp) write << t << endl ;
        write.close() ;
    }
    if(type==3){
        _mkdir((folder+"in").c_str()) ;
        _mkdir((folder+"out").c_str()) ;
        auto f = [&](string name){
            read.open("Library\\"+name) ;
            temp.clear() ;
            while(!read.eof()){
                getline(read,line) ;
                temp.push_back(line) ;
            }
            read.close() ;
            name = folder+name ;
            write.open(name) ;
            for(auto t:temp) write << t << endl ;
            write.close() ;
        } ;
        f("generate.py") ;
        f("generate.cpp") ;
        f("score.cpp") ;
        f("check.py") ;
    }
}