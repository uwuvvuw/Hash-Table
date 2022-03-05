#include <iostream>
#include <fstream>
#include <string>
#include <bits/stdc++.h>
#include "HashTable.cpp"

using namespace std;
void readFile(string file, vector<string>& vect);
int count_lines(string filename);
void printTimeInsert(string file, double time_taken);
void printTimeSearch(string file, double time_taken);
void printAll(string file, string found, string nf);
void printHashTable(string file);

int main(){

    printAll("setA.txt", "found.txt", "notFound.txt");
    cout << endl;
    printAll("setB.txt", "found.txt", "notFound.txt");
    cout << endl;
    printAll("setC.txt", "found.txt", "notFound.txt");
    cout << endl;

    //prints the ascii values and the hashtable
    printHashTable("setA.txt");
}

void printAll(string file, string found, string nf){
    clock_t start, end;
    int size = count_lines(file)*0.9; //size of hashtable
    vector<string> str;
    string target;
    HashTable<string> ht(size);

    cout << "Filename : " << file << endl;
    cout << "Size of hashtable: " << size << endl;

    readFile(file, str);
    start = clock(); //start clock
    for(int x = 0; x < str.size(); x++){
        ht.insert(str[x]);
    }
    end = clock(); //end clock
    cout << endl;
    double time_taken = double(end - start)/double(CLOCKS_PER_SEC); //calculate the time
    printTimeInsert(file, time_taken);

    vector<string> vectFound;
    readFile(found ,vectFound);

    time_taken = 0;
    double total = 0;
    for(int i = 0; i < vectFound.size(); i++){
        target = vectFound[i];
        start = clock();
        ht.retrieve(target);
        end = clock();
        time_taken = double(end - start)/double(CLOCKS_PER_SEC);
        total += time_taken;
        }
    printTimeSearch(found, total);


    vector<string> vectorNf;
    readFile(nf ,vectorNf);
      for(int i = 0; i < vectorNf.size(); i++){
        target = vectorNf[i];
        start = clock();
        ht.retrieve(target);
        end = clock();
        time_taken = double(end - start)/double(CLOCKS_PER_SEC);
        total += time_taken;
        }
    printTimeSearch(nf, total);
    }

//output the hashtable
void printHashTable(string file){
    vector<string> str;
    int size = count_lines(file)*0.9;
    HashTable<string> ht(size);

    readFile(file, str);
    cout << "ASCII Values for " << file << " :" << endl;

    for(int x = 0; x < str.size(); x++){
        ht.insert(str[x]);
        cout << x << ". " << str[x] ;
        cout << "\tValue : " << ht.ascii(str[x].c_str()) <<endl; //sum of ascii of the emails
        }
    cout << endl;
    cout << "Hashtable of " << file << " (chaining)"<< endl;
    cout << ht; //hashtable


}

//read the file
void readFile(string file, vector<string>& vect){
    ifstream infile(file);
    string line;

    while(getline(infile,line)){
        vect.push_back(line.c_str());
        }
    }

// count number of lines in a file
int count_lines(string filename){

    int no_of_lines = 0;
    string line;
    ifstream file(filename);

    while(getline(file,line)){
        no_of_lines++;
    }
    return no_of_lines;
}

void printTimeInsert(string file, double time){
    cout << "Time taken to insert into HashTable in " << file << " : " << fixed << time << setprecision(6) << "s" << endl;
}

void printTimeSearch(string file, double time){
    cout << "Total time taken to search from HashTable in " << file << " : " << fixed << time << setprecision(6) << "s" << endl;
}
