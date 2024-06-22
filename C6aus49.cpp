#include "C6aus49.hpp"
#include <vector>

// Defualt Constructor C6aus46
C6aus49::C6aus49() { Number_Pool_6aus49 = {}; }

// Parameter Constructor C6aus49
C6aus49::C6aus49(int tippscheine_anzahl, int menu_Type, bool menu_Active)  : lotto(tippscheine_anzahl, menu_Type, menu_Active) {}

// Zahlen werden basierent auf der User auswahl generiert.
void C6aus49::Set_6aus49_Number_Pools() {
  if (Get_Menu_Type() == 1 || Get_Menu_Type() == 6) {
  Tippschein_Erstellen(Number_Pool_6aus49, Super_Pool_6aus49, Dummy_Pool_6aus49, "6aus49", Popular_Number_Pool_6aus49, Popular_Super_Pool_6aus49, 1 ,6);
  Use_Popular_Zahlen(Popular_Number_Pool_6aus49, Popular_Super_Pool_6aus49,"6aus49");
  }
}

vector<int> C6aus49::Get_6aus49_Number_Pools() { return Number_Pool_6aus49; }

C6aus49::~C6aus49() {}