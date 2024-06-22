#include "lotto.hpp"
#include <cstdlib>

//---------------------------Constructor-------------------------------------------------------------------------------------------------------------
lotto::lotto() {
  Tippscheine_anzahl = 0;
  Menu_Type = 0;
  Menu_Active = true;
}

lotto::lotto(int tippscheine_anzahl, int menu_Type, bool menu_Active) {
  this->Tippscheine_anzahl = tippscheine_anzahl;
  this->Menu_Type = menu_Type;
  this->Menu_Active = menu_Active;
}

//---------------------------Set-/-Get-Methoden------------------------------------------------------------------------------------------------------

int lotto::Get_Minimum_Vector_size() { return Minimum_Vector_size; }

void lotto::Set_Menu_Active(bool active) { this->Menu_Active = active; }

bool lotto::Get_Menu_Active() { return Menu_Active; }

void lotto::Set_Menu_Type(int Type) { this->Menu_Type = Type; }

int lotto::Get_Menu_Type() { return Menu_Type; }

int lotto::Get_Tippschein_anzahl() { return Tippscheine_anzahl; }

void lotto::Set_Tippschein_anzahl() {
  system("clear");
  if (!(Get_Menu_Type() == 4)) {
    while (!(Tippscheine_anzahl < 0) && !(Tippscheine_anzahl > 10)) {
      // Sollange die Tippschein anzahl nicht zwischen 0 und 10
      // liegt wird nach der anzahl gefragt.

      cout << "|///////////////////////////////////////////////////////////////"
              "//"
              "////|"
           << endl;
      cout << "|//                                                             "
              "  "
              "  //|"
           << endl;
      cout << "|//   Wie viele Tippscheine sollen Generiert werden ?           "
              "  "
              "  //|"
           << endl;
      cout << "|//                                                             "
              "  "
              "  //|"
           << endl;
      cout << "|///////////////////////////////////////////////////////////////"
              "//"
              "////|"
           << endl;
      cout << "Tippschein anzahl: ";
      Tippscheine_anzahl = controlled_userinput_numeric();
      // Wenn es sich um eine Zahl handlt
      if ((Tippscheine_anzahl > 0) &&
          (Tippscheine_anzahl < 10)) { // Wird überprüft ob diese in Range ist.
        system("clear");
        break;
      } else { // Wenn nicht wird der user benachrichtigt.
        system("clear");
        cout << "Anzahl muss zwischen 0 und 10 liegen. Eingabe war: "
             << Tippscheine_anzahl << endl;
        Tippscheine_anzahl = 0;
        // Tippschein anzahl wird 0 und der Loop Started erneut.
      }
    }
  }
}

//---------------------------Lotto-Methoden----------------------------------------------------------------------------------------------------------

// Funktion um Ganzzahlen input auf Abweichungen zu überprüfen.
int lotto::controlled_userinput_numeric() {
  int userinput = 0; // instanziert userinput variable
  if (!(cin >> userinput)) {
    /* Der user kann entwerder Zahlen eingeben oder Wird bei
                         einem falschen Type demensprechend Benachrichtigt. */
    cin.clear();
    cin.ignore(numeric_limits<streamsize>::max(), '\n');
    /* Falsche eingabe führte zu nicht funktionierender user
       eingabe dies wird durch clear und ignore behoben. */
  }
  return userinput; // Bei erfolreicher user eingabe (Muss zahl sein) wird diese
                    // zurückgeben.
}

// Das Haubtmenu von dem aus alle Parameter für den weiteren Programverlauf
// festgelegt werden.
void lotto::Call_Menu() {
  while (Menu_Active) {
    if (Menu_Type == 0) { // Das Menu wird aufgerufen Bis ein valider Menu-Punkt
                          // ausgeählt wurde.
      cout << "|////////////////////////////////////////////////|" << endl;
      cout << "|////////////////   LOTTO v2.0.0    /////////////|" << endl;
      cout << "|////////////////////////////////////////////////|" << endl;
      cout << "|//                                            //|" << endl;
      cout << "|//   Bitte Menupunkt auswählen:               //|" << endl;
      cout << "|//                                            //|" << endl;
      cout << "|//   [1] 6 aus 49.                            //|" << endl;
      cout << "|//   [2] Eurolotto.                           //|" << endl;
      cout << "|//   [3] Eigene Zahlen eingeben.              //|" << endl;
      cout << "|//   [4] Program Ende.                        //|" << endl;
      cout << "|//                                            //|" << endl;
      cout << "|////////////////////////////////////////////////|" << endl;
      cout << "|////////////////////////////////////////////////|" << endl;
      cout << "|////////////////////////////////////////////////|" << endl
           << endl;
      cout << "Auswahl:  ";
      Menu_Type =
          controlled_userinput_numeric(); // Menu_Type dient zur identifizierung
                                          // im weiteren Programverlauf.
    } else if (Menu_Type ==
               4) { // Die Eingabe von 4 Beendet das Programm indem Menu_Active
                    // auf false gesetzt wird was den Loop Beendet.
      system("clear");
      cout << "Ende des Programs ..." << endl;
      Menu_Active = false;
    } else if (Menu_Type == 3) { // Submenu für das eingeben eigener Zahlen
      system("clear");
      int temp = 0;
      while (!(temp == 1) &&
             !(temp == 2)) { // Sollange temp nicht 1 oder 2 ist wird temp nicht
                             // zu Menu_Type Addiert

        cout << "|////////////////////////////////////////////////|" << endl;
        cout << "|//                                            //|" << endl;
        cout << "|//   Bitte Lotto Typ auswählen:               //|" << endl;
        cout << "|//   [1] Eurolotto.                           //|" << endl;
        cout << "|//   [2] 6aus49                               //|" << endl;
        cout << "|//                                            //|" << endl;
        cout << "|////////////////////////////////////////////////|" << endl;
        cout << "Lotto-Typ: ";
        temp = controlled_userinput_numeric();
        if ((temp == 1) || (temp == 2)) {
          Menu_Type +=
              temp + 1; // Ein Menu_Type von 6 Bedeutet "6aus49 mit
                        // eigenenzahlen" und 5 "Eurolotto mit eigenenzahlen"
          system("clear");
          Menu_Active = false;
          break;
        } else { // Wenn temp nicht 1 oder 2 ist wird der User erneut
                 // aufgefordert eine auswahl zu treffen.
          system("clear");
          cout << "Ungültige Eingabe! " << temp << endl;
        }
      }
    } else if ((Menu_Type == 2) ||
               (Menu_Type == 1)) { // Ein Menu_Tyüe von 2 Bedeutet "Eurolotto"
                                   // Ein Menu_Tyüe von 1 Bedeutet "6aus49"
      system("clear");
      Menu_Active = false;
    } else { // Wenn eine Ungülige Zahl eingeben wurde. Die Menu auswahl wird
             // Zurückgesetzt.
      system("clear");
      cout << "Ungültige Eingabe!" << endl;
      Menu_Type = 0;
    }
  }
}

// Zahlen pool für Random zahlen auswahl pool.
// und Superzahlen pool.
void lotto::Fill_Number_Pool(vector<int> &Number_Pool,vector<int> &Super_Pool) {
  for (int Number = 1; Number <= Maximum_Vector_size; Number++) {
    Number_Pool.push_back(Number); // Zaheln von 1 bis 49/50
    if (Number <= 10) {
      Super_Pool.push_back(Number); // Zahlen von 1 bis 10
    }
  }
}

// Eine Funktion die die Zahlen inerhalb eines Vectors Mischt.
void lotto::shuffle(std::vector<int> &Number_Pool,vector<int> &Super_Pool) {
  std::random_device rd1; // Random device Number_Pool
  std::random_device rd2; // Random device Super_Pool
  std::mt19937 g(rd1());
  std::mt19937 t(rd2());
  std::shuffle(Number_Pool.begin(), Number_Pool.end(), g);
  std::shuffle(Super_Pool.begin(), Super_Pool.end(), t);
}

// Verkleinert den Number_Pool um die Getippten Zahlen zu erhaletn
void lotto::downsize(std::vector<int> &Number_Pool,vector<int> &Super_Pool) {
  if (Number_Pool.size() >= Minimum_Vector_size) {
    while (Number_Pool.size() != Minimum_Vector_size) {
      Number_Pool.pop_back();
    }
  }
  if (Super_Pool.size() >= Minimum_Super_size) {
    while (Super_Pool.size() != Minimum_Super_size) {
      Super_Pool.pop_back();
    }
  }
}

// Funktion die die Maximale und Minimale Groese des Vectors Bestimmt.
void lotto::Set_Min_Max() {
  if ((Get_Menu_Type() == 1) || (Get_Menu_Type() == 6)) {
    Maximum_Vector_size = 49;
    Minimum_Vector_size = 6;
    Minimum_Super_size = 1;
  } else if ((Get_Menu_Type() == 2) || (Get_Menu_Type() == 5)) {
    Maximum_Vector_size = 50;
    Minimum_Vector_size = 5;
    Minimum_Super_size = 2;
  }
}

// Funktion die fuer das Erstellen der Tippscheine in 6aus49 und Eurolotto dient
void lotto::Tippschein_Erstellen(vector<int>&Number_Pool,
                                     vector<int>&Super_Pool,
                                     vector<int>&Dummy_Pool, 
                                     string Table, 
                                     vector<int>&Popular_Number_Pool, 
                                     vector<int>&Popular_Super_Pool,
                                     int Local_Menu_Type1,
                                     int Local_Menu_Type2) {
  
  for(int counter = 1;counter <= Get_Tippschein_anzahl();counter++) { 
    Number_Pool = {};
    Zahlengenerierung(Number_Pool, Super_Pool, Dummy_Pool, Table, Local_Menu_Type1, Local_Menu_Type2);
  }
  Get_DBContent(Table);
  find_popular_numbers(Table,Popular_Number_Pool,Popular_Super_Pool);
  
}

//Menu fuer Popular Zahlen wiederverwertung
void lotto::Use_Popular_Zahlen(vector<int>&Popular_Number_Pool,vector<int>&Popular_Super_Pool,string Table){
  string eingabe = "";
  bool Popular_Zahlen_Menu = true;
  while((eingabe != "y" || eingabe != "Y" || eingabe != "n" || eingabe != "N") && (Popular_Zahlen_Menu == true)){
    cout << "Popular Zahlen fuer Tippschein verwenden ? (Y/N)" << endl;
    cin >> eingabe; 
    if (eingabe == "y" || eingabe == "Y") {
      system("clear");
      Procces_Zahlen(Popular_Number_Pool,Popular_Super_Pool, Table);
      Get_DBContent(Table);
      Popular_Zahlen_Menu = false;
    } else {
      Popular_Zahlen_Menu = false;
    }
  }
}


//shuffle downsize und Set_dbcontent fuer Generierte zahlen jeder art
void lotto::Procces_Zahlen(vector<int>&Number_Pool, vector<int>&Super_Pool,string Table){
  shuffle(Number_Pool,Super_Pool);
  downsize(Number_Pool,Super_Pool);
  Set_DBContent(Number_Pool, Super_Pool, Table);
}


//Innere Funktion der Tippschein Erstellen funktion und zur generierung von Popular Zahlen Eintraegen.
void lotto::Zahlengenerierung(vector<int>&Number_Pool,vector<int>&Super_Pool, vector<int>&Dummy_Pool, string Table, int Local_Menu_Type1, int Local_Menu_Type2){
  Set_Min_Max();
  if (Get_Menu_Type() == Local_Menu_Type1) {
  Fill_Number_Pool(Number_Pool,Super_Pool);
  } else if (Get_Menu_Type() == Local_Menu_Type2) {
  Type_Numbers_Manualy(Number_Pool);
  Fill_Number_Pool(Dummy_Pool,Super_Pool);
  }
  Procces_Zahlen(Number_Pool,Super_Pool,Table);
}


// Funktion um Zahlen Pool manuell festzulegen
void lotto::Type_Numbers_Manualy(vector<int> &Number_Pool) {
  bool tempmenu = true;
  vector<int> Eingabe_Number;
  int custom_size;

  while (tempmenu) { // Menu für Manuelle Zahlen eingabe.
    cout << "|////////////////////////////////////////////////////|" << endl;
    cout << "|//                                                //|" << endl;
    cout << "|//   Manuelle Eingabe der Verfügbaren Zahlen      //|" << endl;
    cout << "|//                                                //|" << endl;
    cout << "|////////////////////////////////////////////////////|" << endl;

    cout << "Wie viele Zahlen moechtest du eingeben (zwischen "
         << Minimum_Vector_size << " und " << Maximum_Vector_size << ")? ";
    custom_size = controlled_userinput_numeric();

    if (custom_size >= Minimum_Vector_size &&
        custom_size <= Maximum_Vector_size) {
      tempmenu = false;
    } else {
      cout << "Ungueltige Anzahl von Zahlen.\n";
    }
  }

  int num;
  int count = 0;
  while (count < custom_size) {
    cout << "Numer zwischen " << 1 << " und " << Maximum_Vector_size << ":";
    num = controlled_userinput_numeric();

    if (num >= 1 && num <= 49) {
      bool isUnique = true;
      for (int n : Eingabe_Number) {
        if (n == num) {
          isUnique = false;
          break;
        }
      }

      if (isUnique) {
        Eingabe_Number.push_back(num);
        count++;
      } else {
        cout << "Zahl bereits vorhanden.\n";
      }
    } else {
      cout << "Ungueltige zahl.\n";
    }
  }
  system("clear");
  Number_Pool = Eingabe_Number;
}


void lotto::Set_DBContent(vector<int> zahlen_vec, vector<int> superzahlen_vec, string Table){
  Driver *driver = mariadb::get_driver_instance();
  SQLString url("jdbc:mariadb://localhost:3306/Lotto_db");
  Properties properties({{"user", "user"}, {"password", "Micimo52rita+"}});
  unique_ptr<Connection> conn(driver->connect(url, properties));
  unique_ptr<Statement> stmt(conn->createStatement());

  // SQL Query fuer Zahlen ,Superzahlen ,Ziehung 
  string insert_query =
      "INSERT INTO " + Table + " (Zahlen, Superzahlen, Ziehung) VALUES (?, ?, ?)";
  unique_ptr<PreparedStatement> pstmt(conn->prepareStatement(insert_query));


  // Die Zahlen aus dem vector werden zu strings seperiert durch kommas 
  stringstream zahlen_ss, superzahlen_ss;
  copy(zahlen_vec.begin(), zahlen_vec.end(),
            ostream_iterator<int>(zahlen_ss, ","));
  copy(superzahlen_vec.begin(), superzahlen_vec.end(),
            ostream_iterator<int>(superzahlen_ss, ","));
  string zahlen = zahlen_ss.str();
  string superzahlen = superzahlen_ss.str();
  zahlen.pop_back(); 
  superzahlen.pop_back(); 

  // GetCurrent Time (Mach als fuktion)
  auto now = std::chrono::system_clock::now();
  std::time_t now_time = std::chrono::system_clock::to_time_t(now);
  std::tm* tm_now = std::localtime(&now_time);
  std::stringstream ziehung_ss;
  ziehung_ss << std::put_time(tm_now, "%Y-%m-%d");
  std::string ziehung = ziehung_ss.str();

  //Bringt den Wert zu PreparedStatement
  pstmt->setString(1, zahlen);
  pstmt->setString(2, superzahlen);
  pstmt->setString(3, ziehung);
  pstmt->executeUpdate();
}

 
void lotto::Get_DBContent(string Table) {
  Driver *driver = mariadb::get_driver_instance();
  SQLString url("jdbc:mariadb://localhost:3306/Lotto_db");
  Properties properties({{"user", "user"}, {"password", "password"}});
  unique_ptr<Connection> conn(driver->connect(url, properties));
  unique_ptr<Statement> stmt(conn->createStatement());

  //DB Output.----------------------------------------------------------------
  unique_ptr<ResultSet> result(
      stmt->executeQuery("SELECT * FROM " + Table + ";"));
  // Ausgabe des Header
  cout << Table << endl;
  cout << "+----+--------------------+-------------+------------+\n";
  cout << "| ID | Zahlen             | Superzahlen | Ziehung    |\n";
  cout << "+----+--------------------+-------------+------------+\n";
  // Interiren durch die zeilen des ResultSet objekts und updated die anzahl der zahlen.
  while (result->next()) {
    int id = result->getInt(1);
    string zahlen(result->getString(2).c_str());
    string superzahlen(result->getString(3).c_str());
    string ziehung(result->getString(4).c_str());

    //Ausgabe der Werte aus jeder Spalte, das ausrichten geschiet durch  std::left und std::setw
    cout << "| " << left << setw(2) << id << " | "
              << setw(18) << zahlen << " | " << setw(11)
              << superzahlen << " | " << setw(10) << ziehung << " |\n";
  }
  cout << "+----+--------------------+-------------+------------+\n";
}


void lotto::find_popular_numbers(string Table,vector<int>&popular_zahlen, vector<int>&popular_superzahlen) {
  Driver *driver = mariadb::get_driver_instance();
  SQLString url("jdbc:mariadb://localhost:3306/Lotto_db");
  Properties properties({{"user", "user"}, {"password", "Micimo52rita+"}});
  unique_ptr<Connection> conn(driver->connect(url, properties));
  unique_ptr<Statement> stmt(conn->createStatement());

  // Datenbank Query um die Zahlen zu bekommen.
  unique_ptr<ResultSet> result(
      stmt->executeQuery("SELECT Zahlen, Superzahlen FROM " + Table + ";"));

  map<int, int> zahlen_count;
  map<int, int> superzahlen_count;
  
  // Interiren durch die zeilen des ResultSet objekts und updated die anzahl der zahlen.
  while (result->next()) {
    string zahlen_str(result->getString(1).c_str());
    string superzahlen_str(result->getString(2).c_str());
    stringstream zahlen_ss(zahlen_str);
    stringstream superzahlen_ss(superzahlen_str);

    int number;
    while (getline(zahlen_ss, zahlen_str, ',')) {
      number = stoi(zahlen_str);
      zahlen_count[number]++;
    }

    while (getline(superzahlen_ss, superzahlen_str, ',')) {
      number = stoi(superzahlen_str);
      superzahlen_count[number]++;
    }
  }

  // Finden der Heaufigst vorkommenden zahlen 
  int max_zahlen_count = 0;
  int max_superzahlen_count = 0;

  for (const auto& entry : zahlen_count) {
    if (entry.second > max_zahlen_count) {
      max_zahlen_count = entry.second;
      popular_zahlen = {entry.first};
    } else if (entry.second == max_zahlen_count) {
      popular_zahlen.push_back(entry.first);
    }
  }

  // Die Groese von popular_zahlen Muss mindestens Minimum_Vector_size entsprechen. (5,6)
  while (popular_zahlen.size() <= Minimum_Vector_size) {
    int next_max_zahlen_count = 0;
    int next_popular_zahlen = 0;

    for (const auto& entry : zahlen_count) {
      if (entry.second > next_max_zahlen_count && entry.second < max_zahlen_count) {
        next_max_zahlen_count = entry.second;
        next_popular_zahlen = entry.first;
      }
    }

    popular_zahlen.push_back(next_popular_zahlen);
    max_zahlen_count = next_max_zahlen_count;
  }

  // Das Maximum der popular_zahlen sollte bei 30 liegen.
  while (popular_zahlen.size() > 30) {
    int least_popular_zahlen = popular_zahlen.back();
    popular_zahlen.pop_back();

    for (auto it = zahlen_count.begin(); it != zahlen_count.end(); ++it) {
      if (it->first == least_popular_zahlen) {
        zahlen_count.erase(it);
        break;
      }
    }
  }

  // Finden der Heaufigst vorkommenden superzahlen 
  for (const auto& entry : superzahlen_count) {
    if (entry.second > max_superzahlen_count) {
      max_superzahlen_count = entry.second;
      popular_superzahlen = {entry.first};
    } else if (entry.second == max_superzahlen_count) {
      popular_superzahlen.push_back(entry.first);
    }
  }

  // popular_zahlen muss mindestens Minimum_Super_size entsprechen (1,2)
  while (popular_superzahlen.size() < Minimum_Super_size) {
    int next_max_superzahlen_count = 0;
    int next_popular_superzahlen = 0;

    for (const auto& entry : superzahlen_count) {
      if (entry.second > next_max_superzahlen_count && entry.second < max_superzahlen_count) {
        next_max_superzahlen_count = entry.second;
        next_popular_superzahlen = entry.first;
      }
    }

    popular_superzahlen.push_back(next_popular_superzahlen);
    max_superzahlen_count = next_max_superzahlen_count;
  }

  // popular_superzahlen darf maximal 30 in size sein. 
  while (popular_superzahlen.size() > 30) {
    int least_popular_superzahlen = popular_superzahlen.back();
    popular_superzahlen.pop_back();

    for (auto it = superzahlen_count.begin(); it != superzahlen_count.end(); ++it) {
      if (it->first == least_popular_superzahlen) {
        superzahlen_count.erase(it);
        break;
      }
    }
  }

  cout << "Popular Zahlen: ";
  for (int num : popular_zahlen) {
    cout << num << " ";
  }
  cout << endl;

  cout << "Popular Superzahlen: ";
  for (int num : popular_superzahlen) {
    cout << num << " ";
  }
  cout << endl;
}

lotto::~lotto() {}
