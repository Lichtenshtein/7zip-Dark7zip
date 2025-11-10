// BannerDlg.h

#include "../../../Common/MyString.h"

#define WIN32_LEAN_AND_MEAN
#include <windows.h>

class CBannerDlg
{
public:
  CBannerDlg(const HINSTANCE hInstance, const UString &title, const UString &message);
  ~CBannerDlg(void);
  bool Show(void);
  void ProcessPendingMessages();
  HWND Hwnd() const { return _hwnd; }
private:
  CBannerDlg(CBannerDlg const&) {}
  CBannerDlg& operator=(const CBannerDlg&) {}
  static LRESULT CALLBACK MyWndProc(HWND hwnd, UINT uMsg, WPARAM wParam, LPARAM lParam);
  HWND _hwnd;
  const UString _message;
};
