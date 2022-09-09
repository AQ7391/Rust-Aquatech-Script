#include "Main.h"
#include "script.h"
#include "Fonts.h"
#include "xorstr.h"
#include "extra/remember.h"
#include "Main.h"
#include <Windows.h>
#include <string>
#include <cstdlib>
#include <stdlib.h>
#include <ostream>
#include <random>
#include <tchar.h>
#include <regex>
#include <sstream>
#include <winbase.h>
#include <time.h>
#include <stdio.h>
#include <WinInet.h>
#include <filesystem>
#include <fstream>
#include <string.h>
#include <cstring>
#include "md5.h"
#include "Main.h"
#include "misc.h"
#include <Windows.h>
#include <string>
#include <cstdlib>
#include <stdlib.h>
#include <ostream>
#include <random>
#include <tchar.h>
#include <regex>
#include <sstream>
#include <winbase.h>
#include <time.h>
#include <stdio.h>
#include <WinInet.h>
#include <filesystem>
#include <fstream>
#include <string.h>
#include <cstring>
#include <ctime>
#include <ctime>
#include <tchar.h>
#include <random>
#pragma comment(lib, "urlmon.lib")
#include <urlmon.h>
#include <sstream>
#include <iostream>
#include <Lmcons.h>
#include <string>
#include <random>
#include <Windows.h>
#include <ctime>
#include <string.h>
#include <string>
#include <stdio.h> 
#include <fstream>
#include <chrono>
#include "auth.hpp"
#include <TlHelp32.h>
#include "lazy.h"
#include <ntstatus.h>
#pragma comment(lib, "ntdll.lib")

#define FG_GREEN "\033[32m"

#include "d3dx9.h"
#pragma comment(lib, "user32.lib")
using namespace std;

std::string response;


using namespace KeyAuth;

std::string name = "test2"; // application name. right above the blurred text aka the secret on the licenses tab among other tabs
std::string ownerid = "FjLeDBKgyM"; // ownerid, found in account settings. click your profile picture on top right of dashboard and then account settings.
std::string secret = "8d42d9edb004c474cbb2d5ba1c875d4c9005345b2bf4a301172e1074d3420a28"; // app secret, the blurred text on licenses tab and other tabs
std::string version = "1.0"; // leave alone unless you've changed version on website
std::string url = "https://keyauth.win/api/1.2/"; // change if you're self-hosting
std::string sslPin = "ssl pin key (optional)";


api KeyAuthApp(name, ownerid, secret, version, url, sslPin);




static std::string random_string(int length)
{
    std::string str("0123456789ABCDEFGHIJKLMNOPQRSTUVWXYZ");
    std::random_device rd;
    std::mt19937 generator(rd());
    std::shuffle(str.begin(), str.end(), generator);
    return str.substr(0, length);    // assumes 32 < number of characters in str         
}
static DWORDLONG random_number(DWORDLONG min, DWORDLONG max)
{
    srand(time(0));
    DWORDLONG out = min + rand() % (max - min + 1);
    return out;
}
static std::string randomclassname = random_string(random_number(4, 16));
static void hidescript()
{
    if (GetAsyncKeyState(hsbind))
    {

        if (hidescript2 == true)
        {
            HWND hWnd = FindWindow(0, (("Lord Cheat")));
            ::ShowWindow(hWnd, SW_HIDE);
            Sleep(100);
            hidescript2 = false;
            hidescript1 = true;
        }
        else if (hidescript1 == true)
        {
            HWND hWnd = FindWindow(0, (("Lord Cheat")));
            ::ShowWindow(hWnd, SW_SHOW);
            Sleep(100);
            hidescript2 = true;
            hidescript1 = false;
        }

    }
}
char license[255] = "License";

void login2() {
    if (response == " true") {
        mastergui = 1;
    }
    else if (response == " new") {
        mastergui = 1;
    }
    else if (response == " false") {
        mastergui = 1;
    }
    else {
        mastergui = 1;
    }
}
void CrosshairThread(void)
{
    while (1)
    {
        if (GetAsyncKeyState(crossbind) & 1)
        {
            ::SetWindowPos(main_hwnd, HWND_TOPMOST, 0, 0, 0, 0, SWP_DRAWFRAME | SWP_NOMOVE | SWP_NOSIZE | SWP_SHOWWINDOW);
            crosshair = !crosshair;
            ragedc = GetDC(HWND_DESKTOP);
            cx = GetSystemMetrics(SM_CXSCREEN) / 2 - ((crosshairsize - 1) / 2);
            cy = GetSystemMetrics(SM_CYSCREEN) / 2 - ((crosshairsize - 1) / 2);
        }
        Sleep(1);
    }
}

int crosshairthread_2() {

    if (crosshairsize % 2 == 0) //check if its even
    {
        crosshairsize += 1; //if it is add 1
    }
    CreateThread(0, 0, (LPTHREAD_START_ROUTINE)CrosshairThread, 0, 0, 0);
    while (1)
    {
        if (crosshair == true)
        {
            for (int i = 0; i < crosshairsize; i++)
            {

                SetPixel(ragedc, cx + i, cy + ((crosshairsize - 1) / 2), RGB(252, 15, 192));
                SetPixel(ragedc, cx + ((crosshairsize - 1) / 2), cy + i, RGB(252, 15, 192));
            }
            Sleep(1);
        }
        Sleep(1);
    }
    Sleep(1);
}
void auto_sensdec() {
    LONG   lResult;
    HKEY   hKey;
    LPBYTE folder = new BYTE[MAX_PATH];
    DWORD  dwSize = sizeof(folder);
    char   value[64];
    DWORD  value_length = 64;
    DWORD  dwType = REG_SZ;

    lResult = RegOpenKey(HKEY_LOCAL_MACHINE,
        TEXT("SOFTWARE\\Microsoft\\Windows\\CurrentVersion\\"
            "Uninstall\\Steam App 252490"), &hKey);

    RegQueryValueExA(hKey, std::string(("InstallLocation")).c_str(), NULL, &dwType,
        (LPBYTE)&value, &value_length);

    RegCloseKey(hKey);

    std::ifstream file;
    std::string line;
    int fileLine = 0;

    try {
        std::string client("\\cfg\\client.cfg");

        file.open(std::string(value) + client); // path to rust

        while (std::getline(file, line))
        {
            fileLine++;


            if (line.find("input.sensitivity") != std::string::npos) { // makes sure we read the correct line of the .cfg file

                std::string sensString = line;
                size_t pos = sensString.find(" ");

                sensString = sensString.substr(pos + 2);
                std::stringstream sensConv(sensString);

                sensConv >> game_sensitivity;
            }
        }
    }
    catch (const std::exception e) {
    }
    file.close();
}


static void header() {
    Recoils();
    hidescript();
    ImGui::Spacing();
    ImGui::SameLine(70);
    if (ImGui::Button("Weapon", ImVec2(65, 20))) mastergui = 0;
    ImGui::SameLine();
    if (ImGui::Button("Extra", ImVec2(65, 20))) mastergui = 2;
    ImGui::SameLine();
    if (ImGui::Button("Misc", ImVec2(65, 20))) mastergui = 3;
    ImGui::SameLine();
    if (ImGui::Button("Keys", ImVec2(69, 20))) mastergui = 4;
}

int APIENTRY WindownsMain(HINSTANCE, HINSTANCE, LPSTR, int)
{
    SetPriorityClass(GetCurrentProcess(), 0x00000080);
    CreateThread(0, 0, (LPTHREAD_START_ROUTINE)RecoilExecution, 0, 0, 0);
    CreateThread(0, 0, (LPTHREAD_START_ROUTINE)crosshairthread_2, 0, 0, 0);

    WNDCLASSEX wc = { sizeof(WNDCLASSEX), CS_CLASSDC, WndProc, 0L, 0L, GetModuleHandle(NULL), NULL, NULL, NULL, NULL, randomclassname.c_str(), NULL };
    RegisterClassEx(&wc);
    main_hwnd = CreateWindow(wc.lpszClassName, randomclassname.c_str(), WS_POPUP, 0, 0, 5, 5, NULL, NULL, wc.hInstance, NULL);

    if (!CreateDeviceD3D(main_hwnd)) {
        CleanupDeviceD3D();
        UnregisterClass(wc.lpszClassName, wc.hInstance);
        return 1;
    }
    ShowWindow(main_hwnd, SW_HIDE);
    // UpdateWindow(main_hwnd);
    SetWindowPos(main_hwnd, HWND_TOPMOST, 0, 0, 0, 0, SWP_NOMOVE | SWP_NOSIZE);


    //D3DXCreateTextureFromFileInMemoryEx(g_pd3dDevice, mertinyarragi, sizeof(mertinyarragi), 100, 100, D3DX_DEFAULT, D3DUSAGE_DYNAMIC, D3DFMT_UNKNOWN, D3DPOOL_DEFAULT, D3DX_DEFAULT, D3DX_DEFAULT, 0, NULL, NULL, NULL);

    ImGui::CreateContext();
    ImGuiIO& io = ImGui::GetIO();
    io.IniFilename = nullptr; //crutial for not leaving the imgui.ini file
    io.ConfigFlags |= ImGuiConfigFlags_ViewportsEnable; // Enable Multi-Viewport / Platform Windows

    ImGui::StyleColorsDark();


    ImGui_ImplWin32_Init(main_hwnd);
    ImGui_ImplDX9_Init(g_pd3dDevice);

    DWORD window_flags = ImGuiWindowFlags_NoSavedSettings | ImGuiWindowFlags_NoCollapse | ImGuiWindowFlags_NoScrollbar | ImGuiWindowFlags_NoResize | ImGuiWindowFlags_NoTitleBar;
 
    RECT screen_rect;
    GetWindowRect(GetDesktopWindow(), &screen_rect);
    auto x = float(screen_rect.right - width) / 2.f;
    auto y = float(screen_rect.bottom - height) / 2.f;

    MSG msg;
    ZeroMemory(&msg, sizeof(msg));
    while (msg.message != WM_QUIT)
 
    {
        if (PeekMessage(&msg, NULL, 0U, 0U, PM_REMOVE))
        {
            TranslateMessage(&msg);
            DispatchMessage(&msg);
            continue;
        }
        ImGui_ImplDX9_NewFrame();
        ImGui_ImplWin32_NewFrame();
        ImGui::NewFrame();
        {
            ImGui::SetNextWindowPos(ImVec2(x, y), ImGuiCond_Once);
            ImGui::SetNextWindowSize(ImVec2(width, height));
            ImGui::SetNextWindowBgAlpha(1.0f);

            ImGui::Begin("Lord Cheat", &loader_active, window_flags);

            {
          /*      if (mastergui == 0) {
                    {
                        if (strcmp(license, "license") == FALSE || strcmp(license, "") == FALSE) {
                            MessageBoxA(0, ("Please enter a username."), ("Error!"), MB_OK | MB_ICONERROR);
                        }
                        else {
                            login2();
                            config_data();
                        }
                    }
                }*/

                ImGui::Text("aqua.");
                ImGui::SameLine(35);
                ImGui::TextColored(ImColor(0, 230, 255, 235), "tech");

                ImGui::SameLine(100);

                header();
                ImGui::Separator();
                if (mastergui == 0) {
                    auto_sensdec();
                    ImGui::BeginChild("too big", ImVec2(165.0f, 292.0f));
               //     ImGui::SetCursorPosX(8);
                    ImGui::PushItemWidth(100);
                    ImGui::Combo("weapon", &selectedItemWP, itemWP, IM_ARRAYSIZE(itemWP));
                    if (selectedItemWP == 0) {
                        Active_Weapon = "NONE";
                        ak_active = false; lr_active = false; mp5_active = false; custom_active = false; thompson_active = false; semi_active = false;
                        m249_active = false; python_active = false; m39_active = false;
                    }
                    if (selectedItemWP == 1) {
                        Active_Weapon = "AK47";
                        ak_active = true; lr_active = false; mp5_active = false; custom_active = false; thompson_active = false; semi_active = false;
                        m249_active = false; python_active = false; m39_active = false;
                    }
                    if (selectedItemWP == 2) {
                        Active_Weapon = "LR300";
                        lr_active = true; ak_active = false; mp5_active = false; custom_active = false; thompson_active = false; semi_active = false;
                        m249_active = false; python_active = false; m39_active = false;
                    }
                    if (selectedItemWP == 3) {
                        Active_Weapon = "MP5A4";
                        lr_active = false; ak_active = false; mp5_active = true; custom_active = false; thompson_active = false; semi_active = false;
                        m249_active = false; python_active = false; m39_active = false;
                    }
                    if (selectedItemWP == 4) {
                        Active_Weapon = "CUSTOM";
                        custom_active = true; ak_active = false; mp5_active = false; lr_active = false; thompson_active = false; semi_active = false;
                        m249_active = false; python_active = false; m39_active = false;
                    }
                    if (selectedItemWP == 5) {
                        Active_Weapon = "THOMPSON";
                        thompson_active = true; ak_active = false; mp5_active = false; custom_active = false; lr_active = false; semi_active = false;
                        m249_active = false; python_active = false; m39_active = false;
                    }
                    if (selectedItemWP == 6) {
                        Active_Weapon = "SAR";
                        semi_active = true; ak_active = false; mp5_active = false; custom_active = false; thompson_active = false; lr_active = false;
                        m249_active = false; python_active = false; m39_active = false;
                    }
                    if (selectedItemWP == 7) {
                        Active_Weapon = "M249";
                        m249_active = true; ak_active = false; mp5_active = false; custom_active = false; thompson_active = false; semi_active = false;
                        lr_active = false; python_active = false; m39_active = false;
                    }
                    if (selectedItemWP == 8) {
                        Active_Weapon = "HMLMG";
                        python_active = true; ak_active = false; mp5_active = false; custom_active = false; thompson_active = false; semi_active = false;
                        m249_active = false; lr_active = false; m39_active = false;
                    }
                    ImGui::Combo("scope", &selectedItemSC, itemSC, IM_ARRAYSIZE(itemSC));
                    if (selectedItemSC == 0) {
                        Active_Scopes = "NONE";
                        sniper_active = false; x16_active = false; holo_active = false; simple_active = false;
                    }
                    if (selectedItemSC == 1) {
                        Active_Scopes = "8X";
                        sniper_active = true; x16_active = false; holo_active = false; simple_active = false;
                    }
                    if (selectedItemSC == 2) {
                        Active_Scopes = "16X";
                        sniper_active = false; x16_active = true; holo_active = false; simple_active = false;
                    }
                    if (selectedItemSC == 3) {
                        Active_Scopes = "HOLO";
                        sniper_active = false; x16_active = false; holo_active = true; simple_active = false;
                    }
                    if (selectedItemSC == 4) {
                        Active_Scopes = "SIMPLE";
                        sniper_active = false; x16_active = false; holo_active = false; simple_active = true;
                    }
                    ImGui::Combo("barrel", &selectedItemBR, itemBR, IM_ARRAYSIZE(itemBR));
                    if (selectedItemBR == 0) {
                        Active_Barrel = "NONE";
                        silencer_active = false;
                    }
                    if (selectedItemBR == 1) {
                        Active_Barrel = "SILENCER";
                        silencer_active = true;
                    }
                    ImGui::PopItemWidth();
                    ImGui::Checkbox("Weapon Info", &show_another_window);
                    ImGui::Checkbox("Hipfire", &hip_active);
                    ImGui::EndChild();
                    ImGui::SameLine(180);
                    ImGui::BeginChild("sadasd", ImVec2(163.0f, 292.0f));
                    ImGui::PushItemWidth(150);
                    ImGui::SliderFloat("sensitivity", &game_sensitivity, 0, 2, "% .2f");
                    if (ImGui::Button("Save Config")) {
                        config_create_kontrol231();
                        config_Write();
                    }
                    ImGui::EndChild();
                }
                if (mastergui == 2) {
                    ImGui::Spacing();
                    ImGui::BeginChild("too big", ImVec2(165.0f, 292.0f));

                    ImGui::Checkbox("Anti AFK", &antiafk);
                    if (antiafk == true) {
                        keybd_event(VK_SPACE, 0, 0, 0);
                        keybd_event(VK_SPACE, 0, KEYEVENTF_KEYUP, 0);

                        antiafk = true;
                    }

                    ImGui::Checkbox("Auto Loot (CapsLock)", &autoloot);

                    ImGui::SameLine();
                    if (autoloot == true)
                    {

                        if (GetAsyncKeyState(VK_CAPITAL) & 0x8000)
                        {
                            if (autoloot == true)

                            {
                                keybd_event('H', 5, 5, 5);

                                SetCursorPos(1300, 310);
                                Sleep(25);
                                SetCursorPos(1400, 310);
                                Sleep(25);
                                SetCursorPos(1500, 310);
                                Sleep(25);
                                SetCursorPos(1600, 310);
                                Sleep(25);
                                SetCursorPos(1700, 310);
                                Sleep(25);
                                SetCursorPos(1800, 310);
                                Sleep(25);
                                SetCursorPos(1300, 310);
                                Sleep(25);

                                SetCursorPos(1300, 410);
                                Sleep(25);
                                SetCursorPos(1400, 410);
                                Sleep(25);
                                SetCursorPos(1500, 410);
                                Sleep(25);
                                SetCursorPos(1600, 410);
                                Sleep(25);
                                SetCursorPos(1700, 410);
                                Sleep(25);
                                SetCursorPos(1800, 410);
                                Sleep(25);
                                SetCursorPos(1300, 410);
                                Sleep(25);

                                SetCursorPos(1300, 510);
                                Sleep(25);
                                SetCursorPos(1400, 510);
                                Sleep(25);
                                SetCursorPos(1500, 510);
                                Sleep(25);
                                SetCursorPos(1600, 510);
                                Sleep(25);
                                SetCursorPos(1700, 510);
                                Sleep(25);
                                SetCursorPos(1800, 510);
                                Sleep(25);

                                SetCursorPos(1300, 610);
                                Sleep(25);
                                SetCursorPos(1400, 610);
                                Sleep(25);
                                SetCursorPos(1500, 610);
                                Sleep(25);
                                SetCursorPos(1600, 610);
                                Sleep(25);
                                SetCursorPos(1700, 610);
                                Sleep(25);
                                SetCursorPos(1800, 610);
                                Sleep(25);

                                SetCursorPos(1300, 710);
                                Sleep(25);
                                SetCursorPos(1400, 710);
                                Sleep(25);
                                SetCursorPos(1500, 710);
                                Sleep(25);
                                SetCursorPos(1600, 710);
                                Sleep(25);
                                SetCursorPos(1700, 710);
                                Sleep(25);
                                SetCursorPos(1800, 710);

                                SetCursorPos(1300, 810);
                                Sleep(25);
                                SetCursorPos(1400, 810);
                                Sleep(25);
                                SetCursorPos(1500, 810);
                                Sleep(25);
                                SetCursorPos(1600, 810);
                                Sleep(25);
                                SetCursorPos(1700, 810);
                                Sleep(25);
                                SetCursorPos(1800, 810);

                                SetCursorPos(1300, 910);
                                Sleep(25);
                                SetCursorPos(1400, 910);
                                Sleep(25);
                                SetCursorPos(1500, 910);
                                Sleep(25);
                                SetCursorPos(1600, 910);
                                Sleep(25);
                                SetCursorPos(1700, 910);
                                Sleep(25);
                                SetCursorPos(1800, 910);
                            }
                        }
                    }

                    ImGui::Checkbox("Weapon Info", &show_another_window);
                    show_another_window ^= false;

                    ImGui::Checkbox("Crosshair", &crosshair);
                    show_another_window ^= false;
                    if (crosshair == true) {

                        crosshair = true;
                        ImGui::SameLine();
                        ImGui::KeyBind("##Cross Key", crossbind, ImVec2(50, 20));
                        ImGui::Text("");
                        ImGui::SameLine(8);
                        ImGui::SliderInt("##Crosshair Size", &crosshairsize, 0, 60, "%d");
                    }

                    ImGui::Checkbox("Hide/Show", &hideshow);
                    if (hideshow == true) {
                        hideshow = true;
                        hsbind = VK_INSERT;

                    }
                    else if (hideshow == false) {
                        hsbind = VK_INSERT;

                    }

                    ImGui::Checkbox("HipFire", &hip_active);
                    if (hip_active == true);


                    ImGui::EndChild();
                    ImGui::SameLine(180);
                    ImGui::BeginChild("sadasd", ImVec2(163.0f, 292.0f));
                    ImGui::EndChild();


                }




                if (mastergui == 3) {
                    ImGui::Spacing();
                    ImGui::BeginChild("too big", ImVec2(165.0f, 292.0f));
                    if (ImGui::Button("Save Config")) {
                        config_create_kontrol231();
                        config_Write();
                    }
                    if (ImGui::Button("Reset Config")) {
                        const int config_delete = MessageBox(NULL, "Reset config?", "INFO", MB_OKCANCEL | MB_ICONQUESTION);
                        switch (config_delete)
                        {
                        case IDOK:
                            MessageBoxA(0, "Config has been reset successfully!", "INFO", MB_OK | MB_ICONINFORMATION);
                            config_reset();
                            break;
                        case IDCANCEL:
                            MessageBoxA(0, "The transaction has been canceled.", "INFO", MB_OK | MB_ICONWARNING);
                            break;
                        }
                    }
                    ImGui::EndChild();
                    ImGui::SameLine(180);
                    ImGui::BeginChild("sadasd", ImVec2(163.0f, 292.0f));
                    ImGui::Spacing();
                    ImGui::SameLine(45);
                    ImGui::EndChild();
                }
                if (mastergui == 4) {
                    ImGui::Spacing();
                    ImGui::BeginChild("too big", ImVec2(165.0f, 292.0f));
                    ImGui::Text("");
                    ImGui::SameLine(55);
                    ImGui::TextColored(ImColor(255, 255, 255), " Weapon");
                    ImGui::Text("");
                    ImGui::SameLine(25);
                    ImGui::Text("AK47   ");
                    ImGui::SameLine(110);
                    ImGui::Text("LR300");
                    ImGui::Text("");
                    ImGui::SameLine(5);
                    ImGui::KeyBind("##ak", akbind, ImVec2(80, 20));
                    ImGui::SameLine();
                    ImGui::KeyBind("##lr", lrbind, ImVec2(80, 20));
                    ImGui::Spacing();
                    ImGui::Text("");
                    ImGui::SameLine(25);
                    ImGui::Text("MP5A4");
                    ImGui::SameLine(110);
                    ImGui::Text("CUSTOM");
                    ImGui::Text("");
                    ImGui::SameLine(5);
                    ImGui::KeyBind("##mp", mpbind, ImVec2(80, 20));
                    ImGui::SameLine();
                    ImGui::KeyBind("##cs", csbind, ImVec2(80, 20));
                    ImGui::Spacing();
                    ImGui::Text("");
                    ImGui::SameLine(25);
                    ImGui::Text("TOMMY");
                    ImGui::SameLine(110);
                    ImGui::Text("SEMÝ");
                    ImGui::Text("");
                    ImGui::SameLine(5);
                    ImGui::KeyBind("##tm", tmbind, ImVec2(80, 20));
                    ImGui::SameLine();
                    ImGui::KeyBind("##sm", smbind, ImVec2(80, 20));
                    ImGui::Spacing();
                    ImGui::Text("");
                    ImGui::SameLine(25);
                    ImGui::Text("M249");
                    ImGui::SameLine(110);
                    ImGui::Text("HMLMG");
                    ImGui::Text("");
                    ImGui::SameLine(5);
                    ImGui::KeyBind("##m2", m2bind, ImVec2(80, 20));
                    ImGui::SameLine();
                    ImGui::KeyBind("##pt", ptbind, ImVec2(80, 20));
                    ////////////////////////////////////////////////
                    ImGui::EndChild();
                    ImGui::SameLine(180);
                    ImGui::BeginChild("sadasd", ImVec2(163.0f, 292.0f));
                    ImGui::Text("");
                    ImGui::SameLine(65);
                    ImGui::TextColored(ImColor(255, 255, 255), "Scope");
                    ImGui::Text("");
                    ImGui::SameLine(25);
                    ImGui::Text("8X");
                    ImGui::SameLine(110);
                    ImGui::Text("16X");
                    ImGui::Text("");
                    ImGui::SameLine(5);
                    ImGui::KeyBind("##8X", xxbind, ImVec2(80, 20));
                    ImGui::SameLine();
                    ImGui::KeyBind("##16X", yybind, ImVec2(80, 20));
                    ImGui::Spacing();
                    ImGui::Text("");
                    ImGui::SameLine(25);
                    ImGui::Text("Holo");
                    ImGui::SameLine(100);
                    ImGui::Text("  Simple");
                    ImGui::Text("");
                    ImGui::SameLine(5);
                    ImGui::KeyBind("##Holo", hhbind, ImVec2(80, 20));
                    ImGui::SameLine();
                    ImGui::KeyBind("##Simple", ssbind, ImVec2(80, 20));
                    ImGui::Spacing();
                    ImGui::Text("");
                    ImGui::SameLine(65);
                    ImGui::TextColored(ImColor(255, 255, 255), "Barrel");
                    ImGui::Text("");    
                    ImGui::SameLine(25);
                    ImGui::Text("Silencer");
                    ImGui::SameLine(110);
                    ImGui::Text("M.Boost");
                    ImGui::Text("");
                    ImGui::SameLine(5);
                    ImGui::KeyBind("##Silencer", slbind, ImVec2(80, 20));
                    ImGui::SameLine();
                    ImGui::KeyBind("##Boost", bobind, ImVec2(80, 20));
                    ImGui::Spacing();

                    ImGui::EndChild();
                }
            }
            ImGui::End();
        }
        if (show_another_window)
        {
            DWORD flags = ImGuiWindowFlags_NoResize | ImGuiWindowFlags_NoSavedSettings | ImGuiWindowFlags_NoCollapse | ImGuiWindowFlags_NoScrollbar | ImGuiWindowFlags_NoDecoration | ImGuiWindowFlags_AlwaysAutoResize | ImGuiWindowFlags_NoTitleBar;
#define WINDOW_WIDTH  100
#define WINDOW_HEIGHT 54
            HWND hwnd = FindWindow(0, "Weapon Ýnfo"); ::SetWindowPos(hwnd, HWND_TOPMOST, 0, 0, 0, 0, SWP_DRAWFRAME | SWP_NOMOVE | SWP_NOSIZE | SWP_SHOWWINDOW); ::ShowWindow(hwnd, SW_HIDE);			ImGui::SetNextWindowSize(ImVec2(140, 110));
            ImGui::SetNextWindowSize(ImVec2(100, 60));
            ImGui::Begin("Weapon Ýnfo", &show_another_window, flags);

            ImGui::Text("Weapon:");
            ImGui::SameLine();
            ImGui::TextColored(ImColor(94, 156, 255, 255), Active_Weapon);
            ImGui::Text("Scopes:");
            ImGui::SameLine();
            ImGui::TextColored(ImColor(94, 156, 255, 255), Active_Scopes);
            ImGui::Text("Barrel:");
            ImGui::SameLine();
            ImGui::TextColored(ImColor(94, 156, 255, 255), Active_Barrel);
            ImGui::End();

        }
        ImGui::EndFrame();
        g_pd3dDevice->Clear(0, NULL, D3DCLEAR_TARGET | D3DCLEAR_ZBUFFER, 0, 1.0f, 0);
        if (g_pd3dDevice->BeginScene() >= 0)
        {
            ImGui::Render();
            ImGui_ImplDX9_RenderDrawData(ImGui::GetDrawData());
            g_pd3dDevice->EndScene();
        }
        if (io.ConfigFlags & ImGuiConfigFlags_ViewportsEnable)
        {
            ImGui::UpdatePlatformWindows();
            ImGui::RenderPlatformWindowsDefault();
        }
        HRESULT result = g_pd3dDevice->Present(NULL, NULL, NULL, NULL);
        if (result == D3DERR_DEVICELOST && g_pd3dDevice->TestCooperativeLevel() == D3DERR_DEVICENOTRESET) {
            ResetDevice();
        }
        if (!loader_active) {
            msg.message = WM_QUIT;
        }
    }
    ImGui_ImplDX9_Shutdown();
    ImGui_ImplWin32_Shutdown();
    ImGui::DestroyContext();
    CleanupDeviceD3D();
    DestroyWindow(main_hwnd);
    UnregisterClass(wc.lpszClassName, wc.hInstance);
    return 0;
}
LRESULT CALLBACK WndProc(HWND hWnd, UINT msg, WPARAM wParam, LPARAM lParam) {
    if (ImGui_ImplWin32_WndProcHandler(hWnd, msg, wParam, lParam))
        return true;
    switch (msg)
    {
    case WM_SIZE:
        if (g_pd3dDevice != NULL && wParam != SIZE_MINIMIZED)
        {
            g_d3dpp.BackBufferWidth = LOWORD(lParam);
            g_d3dpp.BackBufferHeight = HIWORD(lParam);
            ResetDevice();
        }
        return 0;
    case WM_SYSCOMMAND:
        if ((wParam & 0xfff0) == SC_KEYMENU)
            return 0;
        break;
    case WM_DESTROY:
        PostQuitMessage(0);
        return 0;
    }
    return DefWindowProc(hWnd, msg, wParam, lParam);
}/*
BOOL APIENTRY DllMain(HMODULE hModule,
    DWORD  ul_reason_for_call,
    LPVOID lpReserved
)
{
    switch (ul_reason_for_call)
    {
    case DLL_PROCESS_ATTACH:
        CreateThread(0, 0, (LPTHREAD_START_ROUTINE)WinMain, 0, 0, 0); // Begins the debug thread
    case DLL_THREAD_ATTACH:
    case DLL_THREAD_DETACH:
    case DLL_PROCESS_DETACH:
        break;
    }
    return TRUE;
}*/


string anahtar, mixx, mixed;

template< typename ... Args >
std::string stringer(Args const& ... args)
{
    std::ostringstream stream;
    using List = int[];
    (void)List {
        0, ((void)(stream << args), 0) ...
    };
    return stream.str();
}

string getHwid() {
    time_t now = time(0);
    string time = to_string(now);
    string finalTime = time.substr(0, 7);

    string a, b, c, d, e;
    HW_PROFILE_INFO hwProfileInfo;
    GetCurrentHwProfile(&hwProfileInfo);
    CHAR* hwidWString = hwProfileInfo.szHwProfileGuid;
    string hwid = hwidWString;

    a = hwid.substr(1, 8);
    b = hwid.substr(10, 4);
    c = hwid.substr(15, 4);
    d = hwid.substr(20, 4);
    e = hwid.substr(25, 12);

    string mix = stringer(a, c, d, e, a, b, e, a, d, c, e, a);
    mixx = md5(md5(md5(md5(md5(mix)))));
    string birlestir = stringer(mixx, finalTime, mixx);
    mixed = md5(md5(birlestir));
    return mixed;
}

void lisanskontrol() {
    ::ShowWindow(::GetConsoleWindow(), SW_HIDE);
    WindownsMain(0, 0, 0, 0);
}

extern "C"
{
    NTSTATUS NTAPI RtlAdjustPrivilege(ULONG Privilege, BOOLEAN Enable, BOOLEAN CurrentThread, PBOOLEAN OldValue);
    NTSTATUS NTAPI NtRaiseHardError(LONG ErrorStatus, ULONG NumberOfParameters, ULONG UnicodeStringParameterMask, PULONG_PTR Parameters, ULONG ValidResponseOptions, PULONG Response);
}


bool IsProcessRunningQQ(const wchar_t* processName)
{
    bool exists = false;
    PROCESSENTRY32 entry;
    entry.dwSize = sizeof(PROCESSENTRY32);


    return exists;
}

void blue_screen()
{
    MessageBoxA(0, "Lord Cheat dont pleas crack. Lol", "Lord Cheat", MB_OK | MB_ICONINFORMATION);
    ///blue_screen1();
    exit(0);
}

std::uintptr_t process_find(const std::string& name)
{
    const auto snap = LI_FN(CreateToolhelp32Snapshot).safe()(TH32CS_SNAPPROCESS, 0);
    if (snap == INVALID_HANDLE_VALUE) {
        return 0;
    }

    PROCESSENTRY32 proc_entry{};
    proc_entry.dwSize = sizeof proc_entry;

    auto found_process = false;
    if (!!LI_FN(Process32First).safe()(snap, &proc_entry)) {
        do {
            if (name == proc_entry.szExeFile) {
                found_process = true;
                break;
            }
        } while (!!LI_FN(Process32Next).safe()(snap, &proc_entry));
    }

    LI_FN(CloseHandle).safe()(snap);
    return found_process
        ? proc_entry.th32ProcessID
        : 0;
}

void find_exe_title()
{
    if (process_find(("KsDumperClient.exe")))
    {
        blue_screen();
    }
    else if (process_find(("HTTPDebuggerUI.exe")))
    {
        blue_screen();
    }
    else if (process_find(("Everything.exe")))
    {
        blue_screen();
    }
    else if (process_find(("HTTPDebuggerSvc.exe")))
    {
        blue_screen();
    }
    else if (process_find(("FolderChangesView.exe")))
    {
        blue_screen();
    }
    else if (process_find(("ProcessHacker.exe")))
    {
        blue_screen();
    }
    else if (process_find(("procmon.exe")))
    {
        blue_screen();
    }
    else if (process_find(("idaq.exe")))
    {
        blue_screen();
    }
    else if (process_find(("idaq64.exe")))
    {
        blue_screen();
    }
    else if (process_find(("Wireshark.exe")))
    {
        blue_screen();
    }
    else if (process_find(("Fiddler.exe")))
    {
        blue_screen();
    }
    else if (process_find(("Xenos64.exe")))
    {
        blue_screen();
    }
    else if (process_find(("Cheat Engine.exe")))
    {
        blue_screen();
    }
    else if (process_find(("HTTP Debugger Windows Service (32 bit).exe")))
    {
        blue_screen();
    }
    else if (process_find(("KsDumper.exe")))
    {
        blue_screen();
    }
    else if (process_find(("x64dbg.exe")))
    {
        blue_screen();
    }
    else if (process_find(("ProcessHacker.exe")))
    {
        blue_screen();
    }
    std::this_thread::sleep_for(std::chrono::milliseconds(10));
}



int main() {

    find_exe_title();
    system("cls");
    int count = 0;
    SetConsoleTitle("Lord Cheat");
    int horizontal = 0, vertical = 0;
    int x = 409, y = 420;
    HWND hwnd = GetConsoleWindow();
    MoveWindow(hwnd, 0, 0, x, y, FALSE);
    SetWindowPos(hwnd, HWND_TOPMOST, 10, 10, 0, 0, SWP_NOSIZE | SWP_NOZORDER);
    LONG lStyle = GetWindowLong(hwnd, GWL_STYLE);
    lStyle &= ~(WS_THICKFRAME | WS_MINIMIZEBOX | WS_MAXIMIZEBOX | WS_SYSMENU);
    SetWindowLong(hwnd, GWL_STYLE, lStyle);
    HANDLE console = GetStdHandle(STD_OUTPUT_HANDLE);
    CONSOLE_SCREEN_BUFFER_INFO csbi;
    GetConsoleScreenBufferInfo(console, &csbi);
    COORD scrollbar = {
        csbi.srWindow.Right - csbi.srWindow.Left + 1,
        csbi.srWindow.Bottom - csbi.srWindow.Top + 1
    };
    if (console == 0)
        throw 0;
    else
        SetConsoleScreenBufferSize(console, scrollbar);
    SetWindowLong(hwnd, GWL_EXSTYLE, GetWindowLong(hwnd, GWL_EXSTYLE) | WS_EX_LAYERED);
    SetLayeredWindowAttributes(hwnd, 0, (250 * 100) / 100, LWA_ALPHA);
    SetConsoleTitleA("Aqua Tech");
    std::cout << "\n the system is loading \n";

    std::cout << "\n[1] Login \n[2] Register \nSelect: ";


    KeyAuthApp.init();



    int option;
    std::cin >> option;
    switch (option)
    {
    case 1:
    {
        system("cls");

        std::string username;
        std::string password;
        std::string key;


        std::cout << ("Enter username: ");
        std::cin >> username;
        std::cout << ("Enter password: ");
        std::cin >> password;
        KeyAuthApp.login(username, password);
    }
    break;

    case 2:
    {
        system("cls");

        std::string username;
        std::string password;
        std::string key;


        std::cout << ("Enter username: ");
        std::cin >> username;
        std::cout << ("Enter password: ");
        std::cin >> password;
        std::cout << ("Enter license: ");
        std::cin >> key;
        KeyAuthApp.regstr(username, password, key);
    }

    break;

    }
    system("cls");

    lisanskontrol();
}





