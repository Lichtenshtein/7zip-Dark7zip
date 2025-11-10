// BannerDlg.cpp

#include "BannerDlg.h"
#include "resource.h"

#define RECT_W(X) (((X).right > (X).left) ? ((X).right - (X).left) : 0)
#define RECT_H(X) (((X).bottom > (X).top) ? ((X).bottom - (X).top) : 0)

static const wchar_t *const DEF_TITLE   = L"Setup";
static const wchar_t *const DEF_MESSAGE = L"Setup is launching, please stay tuned...";

CBannerDlg::CBannerDlg(const HINSTANCE hInstance, const UString &title, const UString &message)
:
  _message(message)
{
  _hwnd = CreateWindowExW(0, L"#32770", title.IsEmpty() ? DEF_TITLE : title.Ptr(), WS_OVERLAPPED | WS_CAPTION | WS_THICKFRAME | WS_SYSMENU, CW_USEDEFAULT, CW_USEDEFAULT, 384, 96, NULL, NULL, hInstance, NULL);
  if (_hwnd != NULL)
  {
    RECT workRect, wndRect;
    HICON hIcon;
    SetWindowLongPtrW(_hwnd, GWLP_WNDPROC, (LONG_PTR)&MyWndProc);
    SetWindowLongPtrW(_hwnd, GWLP_USERDATA, (LONG_PTR)this);
    SetWindowPos(_hwnd, HWND_TOPMOST, 0, 0, 0, 0, SWP_NOMOVE | SWP_NOSIZE);
    if (SystemParametersInfoW(SPI_GETWORKAREA, 0, &workRect, 0) && GetWindowRect(_hwnd, &wndRect))
    {
      MoveWindow(_hwnd, (RECT_W(workRect)-RECT_W(wndRect))/2, (RECT_H(workRect)-RECT_H(wndRect))/2, RECT_W(wndRect), RECT_H(wndRect), true);
    }
    if((hIcon = (HICON)LoadImageW(hInstance, MAKEINTRESOURCEW(IDI_ICON), IMAGE_ICON, 16, 16, LR_DEFAULTCOLOR | LR_SHARED)) != NULL)
    {
      SendMessage(_hwnd, WM_SETICON, (WPARAM)ICON_SMALL, (LPARAM)hIcon);
    }
    if((hIcon = (HICON)LoadImageW(hInstance, MAKEINTRESOURCEW(IDI_ICON), IMAGE_ICON, 48, 48, LR_DEFAULTCOLOR | LR_SHARED)) != NULL)
    {
      SendMessage(_hwnd, WM_SETICON, (WPARAM)ICON_BIG, (LPARAM)hIcon);
    }
  }
}

CBannerDlg::~CBannerDlg(void)
{
  if (_hwnd != NULL)
  {
    DestroyWindow(_hwnd);
    _hwnd = NULL;
  }
}

bool CBannerDlg::Show(void)
{
  if (_hwnd != NULL)
  {
    ShowWindow(_hwnd, SW_SHOWNORMAL);
    ProcessPendingMessages();
    Sleep(125);
    SetForegroundWindow(_hwnd);
    SetCapture(_hwnd);
    return true;
  }
  return false;
}

LRESULT CALLBACK CBannerDlg::MyWndProc(HWND hwnd, UINT uMsg, WPARAM wParam, LPARAM lParam)
{
  switch(uMsg)
  {
  case WM_PAINT:
    PAINTSTRUCT ps;
    if(const HDC hdc = BeginPaint(hwnd, &ps))
    {
      const CBannerDlg *const self = (const CBannerDlg*)GetWindowLongPtrW(hwnd, GWLP_USERDATA);
      FillRect(hdc, &ps.rcPaint, (HBRUSH)(COLOR_WINDOW + 1));
      DrawTextExW(hdc, (LPWSTR)(self->_message.IsEmpty() ? DEF_MESSAGE : self->_message.Ptr()), -1, &ps.rcPaint, DT_CENTER|DT_SINGLELINE|DT_VCENTER, NULL);
      EndPaint(hwnd, &ps);
    }
  case WM_CLOSE:
    return 0; /*ignore WM_CLOSE msg*/
  default:
    return DefWindowProc(hwnd, uMsg, wParam, lParam);
  }
}

void CBannerDlg::ProcessPendingMessages()
{
  if (_hwnd != NULL)
  {
    MSG msg = {};
    for (Byte i = 0U; i < 8U; ++i)
    {
      BOOL flag = FALSE;
      if(i > 0U)
      {
        Sleep(1); /*delay*/
      }
      for (UInt16 k = 0U; k < 8192U; ++k)
      {
        if (PeekMessageW(&msg, _hwnd, 0U, 0U, PM_REMOVE))
        {
          flag = TRUE;
          TranslateMessage(&msg);
          DispatchMessageW(&msg);
          continue;
        }
        break;
      }
      if(!flag)
      {
        break; /*did not process any messages*/
      }
    }
  }
}
