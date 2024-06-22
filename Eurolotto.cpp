#include "Eurolotto.hpp"
#include <vector>

// Default Constructor Eurolotto
Eurolotto::Eurolotto() { Euro_Number_Pool = {}; };

// Parameter Constructor Eurolotto.
Eurolotto::Eurolotto(int tippscheine_anzahl, int menu_Type, bool menu_Active): lotto(tippscheine_anzahl, menu_Type, menu_Active) {}

// Zahlen werden je nach Auswahl in Menu Generiert.
void Eurolotto::Set_Euro_Zahlen_Pool() {
  if (Get_Menu_Type() == 2 || Get_Menu_Type() == 5) {
    Tippschein_Erstellen(Euro_Number_Pool, Euro_Super_Pool, Euro_Dummy_Pool, "Eurolotto", Euro_Popular_Number_Pool, Euro_Popular_Super_Pool, 2, 5);
    Use_Popular_Zahlen(Euro_Popular_Number_Pool, Euro_Popular_Super_Pool,"Eurolotto");
  }
}

std::vector<int> Eurolotto::Get_Euro_Zahlen_Pool() { return Euro_Number_Pool; }

Eurolotto::~Eurolotto() {}