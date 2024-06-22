#pragma once
#include "lotto.hpp"
#include <vector>

class Eurolotto : public virtual lotto {
protected:
  vector<int> Euro_Number_Pool;
  vector<int> Euro_Super_Pool;
  vector<int> Euro_Dummy_Pool;
  vector<int> Euro_Popular_Number_Pool;
  vector<int> Euro_Popular_Super_Pool;

public:
  Eurolotto();
  Eurolotto(int, int, bool);
  ~Eurolotto();

  void Set_Euro_Zahlen_Pool();
  std::vector<int> Get_Euro_Zahlen_Pool();
};