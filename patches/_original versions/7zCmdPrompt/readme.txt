Patch for ticket #945 (https://sourceforge.net/p/sevenzip/feature-requests/945/#)
Source files folder: CPP\7zip\UI\FileManager\
Description.
1) Files App.cpp, App.h: method void CApp::CommandPrompt () added.
2) Files resource.rc, resource.h: IDM_COMMAND_PROMPT added.
3) MyLoadMenu.cpp: line "case IDM_COMMAND_PROMPT: g_App.CommandPrompt (); break;" added.
__________________
Ihar Areshchankau,
r0bur@tut.by