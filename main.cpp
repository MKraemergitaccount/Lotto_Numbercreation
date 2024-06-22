/*
Programm    : lotto
Autor       : Maik Krämer
Version     : 2.0.0
Datum       : 04.01.2024
Beschreibung: Möglichst realistische Tipzahlen zu generieren um ein reales Lotto
Spiel zu gewinnen.
*/
#include "C6aus49.hpp"
#include "Eurolotto.hpp"
#include "lotto.hpp"

int main() {
  lotto lotto_obj;
  lotto_obj.Call_Menu();
  // User Menu um verlauf des Programs fest zu legen.
  lotto_obj.Set_Tippschein_anzahl();
  // Anzahl der Tippscheine festlegen.

  // Werte die mit Menu unde Tippschein anzahl erstellt wurden werden in die
  // objekte geschrieben.
  Eurolotto Eurolotto_obj(lotto_obj.Get_Tippschein_anzahl(),lotto_obj.Get_Menu_Type(),lotto_obj.Get_Menu_Active());
  C6aus49 C6aus49_obj(lotto_obj.Get_Tippschein_anzahl(),lotto_obj.Get_Menu_Type(), lotto_obj.Get_Menu_Active());

  // Zahlen eingabe basierent auf Lotto typ und User auswahl.
  C6aus49_obj.Set_6aus49_Number_Pools();
  Eurolotto_obj.Set_Euro_Zahlen_Pool();
  return 0;
}