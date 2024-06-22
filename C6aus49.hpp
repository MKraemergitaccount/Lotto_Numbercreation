#pragma once
#include "lotto.hpp"
#include <vector>

class C6aus49 : public virtual lotto {
protected:
  vector<int> Number_Pool_6aus49;
  vector<int> Super_Pool_6aus49;
  vector<int> Dummy_Pool_6aus49;
  vector<int> Popular_Number_Pool_6aus49;
  vector<int> Popular_Super_Pool_6aus49;

public:
  //--------Constructor-/-Destructor-------------------------
  C6aus49();
  C6aus49(int, int, bool);
  ~C6aus49();
  //--------Methods------------------------------------------

  //--------Set-/-Get----------------------------------------
  void Set_6aus49_Number_Pools();
  std::vector<int> Get_6aus49_Number_Pools();
};