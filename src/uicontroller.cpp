#include "uicontroller.h"

#include <unistd.h>
#include <sys/select.h>

wint_t UiController::GetKey(int p_TimeOutMs)
{
  fd_set fds;
  FD_ZERO(&fds);
  FD_SET(STDIN_FILENO, &fds);
  int maxfd = STDIN_FILENO;
  struct timeval tv = {(p_TimeOutMs / 1000), (p_TimeOutMs % 1000) * 1000};
  wint_t key = 0;
  select(maxfd + 1, &fds, NULL, NULL, &tv); // ignore select() rv to get resize events
  if (FD_ISSET(STDIN_FILENO, &fds))
  {
    get_wch(&key);
  }

  return key;
}
