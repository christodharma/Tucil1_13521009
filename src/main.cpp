#include <iostream>
#include <fstream>
#include <cstdlib>
#include <ctime>
#include <vector>
#include <bits/stdc++.h>
#include <chrono>
#include "bruteforce.cpp"
using namespace std::chrono;
using namespace std;

//KAMUS
int mode;
int angka[4];
string cards[4];

void input();
void translate_toAngka();
void translate_toCards();

void input(){
    string valid_input = "A23456789JQK";
    string sepuluh = "10";
    do
    {
        cin >> mode;
    } while (mode != 1 && mode != 2);
    
    if (mode == 1){
        cout << "KEYBOARD INPUT:" << endl;
        for (int i = 0; i < 4; i++)
        {
            do
            {
                cin >> cards[i];
                if (valid_input.find(cards[i]) == -1 && cards[i] != sepuluh)
                {
                    cout << "Masukan tidak sesuai (input harus antara A, 2-10, J, Q, atau K)" << endl;
                }
            } while (valid_input.find(cards[i]) == -1 && cards[i] != sepuluh);
        }
        translate_toAngka();
    }
    else if (mode == 2){
        cout << "RANDOM INPUT:" << endl;
        for (int i = 0; i < 4; i++)
        {
            angka[i] = rand() % 13+1;
        }
        translate_toCards();
    }
    if (mode == 1){
        cout << "INPUT YANG DITERIMA: " << endl;
    }
    for (int i = 0; i < 4; i++)
    {
        cout << cards[i] << " ";
    }   
}

void translate_toAngka(){
    for (int i = 0; i < 4; i++)
    {
        if (cards[i] == "A")
        {
            angka[i] = 1;
        }
        else if (cards[i] == "J")
        {
            angka[i] = 11;
        }
        else if (cards[i] == "Q")
        {
            angka[i] = 12;
        }
        else if (cards[i] == "K")
        {
            angka[i] = 13;
        }
        else
        {
            angka[i] = stoi(cards[i]);
        }
    }
}

void translate_toCards(){
    for (int i = 0; i < 4; i++)
    {
        if (angka[i] == 1)
        {
            cards[i] = "A";
        }
        else if (angka[i] == 11)
        {
            cards[i] = "J";
        }
        else if (angka[i] == 12)
        {
            cards[i] = "Q";
        }
        else if (angka[i] == 13)
        {
            cards[i] = "K";
        }
        else
        {
            cards[i] = to_string(angka[i]);
        }
    }
}

int main() {
    char save;
    int count = 0;
    vector<string> solutions;
    //inisialisasi random untuk random input
    srand(time(NULL));
    //deklarasi kumpulan angka sebagai 0
    for (int i = 0; i < 4; i++)
    {
        angka[i] = 0;
    }
    cout << "========================================" << endl;\
    cout << "PROGRAM MENCARI SOLUSI DARI PERMAINAN KARTU 24" << endl;
    cout << "========================================" << endl;
    cout << "by Christophorus D.W. / NIM 13521009" << endl << endl;
    cout << "PILIH MODE INPUT:" << endl;
    cout << "1. KEYBOARD INPUT" << endl;
    cout << "2. RANDOM INPUT" << endl;
    cout << "PILIHAN: ";
    input();
    auto start = high_resolution_clock::now();
    bruteforce(angka, solutions, count);
    auto stop = high_resolution_clock::now();
    cout << endl;
    cout << count << " solutions found" << endl;
    for (vector<string>::const_iterator i = solutions.begin(); i != solutions.end(); ++i){
        cout << *i << endl;
    }
    cout << "Apakah ingin menyimpan solusi ke file? (Y/N): ";
    do
    {
        cin >> save;
        if (save == 'Y' || save == 'y'){
            ofstream myfile("test/solutions.txt");
            myfile << count << " solutions found" << endl;
            for (vector<string>::const_iterator i = solutions.begin(); i != solutions.end(); ++i){
                myfile << *i << endl;
            }
            cout << "Solusi disimpan ke file solutions.txt" << endl;
        } else if (save == 'N' || save == 'n'){
            cout << "Solusi tidak disimpan" << endl;
        }
        else {
            cout << "Masukan tidak sesuai (input harus Y atau N)" << endl;
        }
    } while (save != 'Y' && save != 'y' && save != 'N' && save != 'n');
    auto duration = stop - start;
    cout << "Runtime program : " << chrono::duration <double, milli> (duration).count() << " ms" << endl;
    cout << "Program selesai! Terima kasih! Press enter to close" << endl;
    cin.ignore();
    cin.get();
    return 0;
}