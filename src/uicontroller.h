#pragma once

#include <ncursesw/ncurses.h>

class UiController
{
public:
  static wint_t GetKey(int p_TimeOutMs);

private:
};
