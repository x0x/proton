#pragma once

#include <string>
#include <vector>

#include "uidialog.h"

class UiMessageDialog : public UiDialog
{
public:
  UiMessageDialog(const UiDialogParams& p_Params, const std::string& p_Message);
  virtual ~UiMessageDialog();

  bool Run();
  void KeyHandler(wint_t p_Key);

private:
  void Draw();

protected:
  bool m_Running = true;
  bool m_Result = false;
  std::string m_Message;
};
