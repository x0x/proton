#pragma once

#include <set>

#include "uilistdialog.h"
#include "fileutil.h"

class UiFileListDialog : public UiListDialog
{
public:
  UiFileListDialog(const UiDialogParams& p_Params);
  virtual ~UiFileListDialog();

  std::string GetSelectedPath();

protected:
  virtual void OnSelect();
  virtual void OnBack();
  virtual bool OnTimer();

  void UpdateList();

private:
  std::string m_CurrentDir;
  std::set<FileInfo, FileInfoCompare> m_FileInfos;
  std::set<FileInfo, FileInfoCompare> m_CurrentFileInfos;
  std::string m_SelectedPath;
};
