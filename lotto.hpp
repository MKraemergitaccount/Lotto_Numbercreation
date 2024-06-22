#pragma once
#include <algorithm>
#include <cstdlib>
#include <ctime>
#include <fstream>
#include <iostream>
#include <istream>
#include <limits>
#include <random>
#include <sstream>
#include <vector>
#include </usr/include/mariadb/conncpp.hpp>
#include </usr/include/mariadb/conncpp/Statement.hpp>
#include <chrono>
#include <sstream>
#include <iterator>
#include <iomanip> //standard input/output manipulator header file
#include <iostream>
using namespace std;
using namespace sql;


class lotto {
private:
  int Tippscheine_anzahl;
  int Menu_Type;
  bool Menu_Active;
  int Minimum_Vector_size;
  int Maximum_Vector_size;
  int Minimum_Super_size;
 
public:
  //--------Constructor-/-Destructor-------------------------
  lotto();
  lotto(int, int, bool);
  ~lotto();
  //--------Methods------------------------------------------
  void Call_Menu();
  int controlled_userinput_numeric();
  void Fill_Number_Pool(vector<int> &,vector<int> &);
  void Type_Numbers_Manualy(vector<int> &);
  
  void Set_DBContent(vector<int>, vector<int>, string);
  void Get_DBContent(string);
  void find_popular_numbers(string, vector<int>&, vector<int>&);


  void Tippschein_Erstellen(vector<int>&,vector<int>&,vector<int>&,string,vector<int>&,vector<int>&, int, int);
  void Zahlengenerierung(vector<int>&,vector<int>&, vector<int>&, string, int, int);
  void Use_Popular_Zahlen(vector<int>&, vector<int>&, string);
  void Procces_Zahlen(vector<int>&, vector<int>&,string);

  void read_menu();
  void Tippschein_Generator(vector<int>);
  void shuffle(std::vector<int> &,vector<int> &);
  void downsize(std::vector<int> &,vector<int> &);
  //--------Set-/-Get----------------------------------------
  void Set_Min_Max();
  int Get_Minimum_Vector_size();

  void Set_Menu_Active(bool);
  bool Get_Menu_Active();

  void Set_Menu_Type(int);
  int Get_Menu_Type();

  void Set_Tippschein_anzahl();
  int Get_Tippschein_anzahl();

};
