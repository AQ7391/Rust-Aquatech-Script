#include "RecoilDatas/RecoilTables.h"
#include "RecoilDatas/Features.h"
#include "extra/config.h"


HDC ragedc = NULL;
static int crosshairsize = 8;
static int cx = 0;
static int cy = 0;

static bool hideshow , hidescript1 = true;
static bool legitmode, crosshair = false;
static bool antiafk, autoloot, show_another_window, hip_active, menukey, bRapidf = false;
static bool resetbut, random_active, show_random, randomonline, randomxy_active, show_xycontrol, controlxy_active = false;
static bool ak_active, lr_active, mp5_active, thompson_active, custom_active, semi_active, m249_active, python_active, m39_active, bMuzzleBoost = false;
static bool holo_active, sniper_active, simple_active, x16_active, silencer_active, boost_active = false;
static bool BSound = FALSE;
static bool hidescript2 = true;
static int XSCALE = 1;
static int YSCALE = 1;

static int selectedItemWP = 0;
static int selectedItemSC = 0;
static int selectedItemBR = 0;

const char* Active_Weapon = "NONE";
const char* Active_Scopes = "NONE";
const char* Active_Barrel = "NONE";

static const char* itemWP[]{ Active_Weapon,
"AK47",
"LR300",
"MP5A4",
"CUSTOM",
"TOMMY",
"SEMI",
"M249",
"HMLMG"
};
static const char* itemSC[]{ Active_Scopes,
"8x",
"16x",
"HOLO",
"SIMPLE"
};
static const char* itemBR[]{ Active_Barrel,
"Silencer",
};

namespace CurrentWeapon {
	double BarrelAttachment() {

		if (silencer_active == true) {
			if (m249_active == true)
				Multiplyer::Barrel.Suppressor = 0.75;
			if (custom_active == true)
				Multiplyer::Barrel.Suppressor = 0.85;
			if (simple_active == true || holo_active == true)
				return 0.8;
			if (sniper_active == true && silencer_active == true)
				return 1.0;
			else
				return Multiplyer::Barrel.Suppressor;
		}
		else if (bMuzzleBoost == true) {
			return Multiplyer::Barrel.None;
		}
		else
			return Multiplyer::Barrel.None;
	}
	double ScopeAttachment() {
		if (sniper_active == true) {
			if (custom_active == true || thompson_active == true) {
				if (sniper_active == true)
					return Multiplyer::Scope.x8 + 0.75;
			}
			return Multiplyer::Scope.x8;
		}
		if (x16_active == true) {
			if (custom_active == true || thompson_active == true) {
				if (x16_active == true)
					return Multiplyer::Scope.x16 + 0.75;
			}
			return Multiplyer::Scope.x16;
		}
		else if (simple_active == true) {
			if (custom_active == true || thompson_active == true) {
				if (simple_active == true)
					return Multiplyer::Scope.Simple + 0.1;
			}
			return Multiplyer::Scope.Simple;
		}

		else if (holo_active == true) {
			if (custom_active == true || thompson_active == true) {
				if (holo_active == true)
					return Multiplyer::Scope.Holo + 0.3;
			}
			return Multiplyer::Scope.Holo;
		}
		else
			return Multiplyer::Scope.None;
	}

	double x(int b) {

		if (randomxy_active == false) {

			if (ak_active) {
				return (Recoil_Ak47[b].x * ScopeAttachment() * BarrelAttachment() / 4) / game_sensitivity / XCONTROL;
			}
			else if (lr_active) {
				return (Recoil_Lr300[b].x * ScopeAttachment() * BarrelAttachment() / 4) / game_sensitivity / XCONTROL;
			}
			else if (mp5_active) {
				return (Recoil_Mp5a4[b].x * ScopeAttachment() * BarrelAttachment() / 4) / game_sensitivity / XCONTROL;
			}
			else if (thompson_active) {
				return (Recoil_Thompson_g[b].x * ScopeAttachment() * BarrelAttachment() / 4) / game_sensitivity / XCONTROL;
			}
			else if (custom_active) {
				return (Recoil_Custom_g[b].x * ScopeAttachment() * BarrelAttachment() / 4) / game_sensitivity / XCONTROL;
			}
			else if (m249_active) {
				return (Recoil_M249[b].x * ScopeAttachment() * BarrelAttachment() / 4) / game_sensitivity / XCONTROL;
			}
			else if (semi_active) {
				return (Recoil_Semi_r[b].x * ScopeAttachment() * BarrelAttachment() / 4) / game_sensitivity / XCONTROL;
			}
			else if (python_active) {
				return (python_t[b].x * ScopeAttachment() * BarrelAttachment() / 4) / game_sensitivity / XCONTROL;
			}
			else if (m39_active) {
				return (m39_t[b].x * ScopeAttachment() * BarrelAttachment() / 4) / game_sensitivity / XCONTROL;
			}
			else
				return 0;
		}
		if (randomxy_active == true) {                                                                 //X RANDOMIZATION ON AND OFF
			if (ak_active) {
				return ((Recoil_Ak47[b].x * ScopeAttachment()) * BarrelAttachment()) / 4 / game_sensitivity / XCONTROL + rand() % (XSCALE + XSCALE) + (-XSCALE);
			}
			else if (lr_active) {
				return ((Recoil_Lr300[b].x * ScopeAttachment()) * BarrelAttachment()) / 4 / game_sensitivity / XCONTROL + rand() % (XSCALE + XSCALE) + (-XSCALE);
			}
			else if (mp5_active) {
				return ((Recoil_Mp5a4[b].x * ScopeAttachment()) * BarrelAttachment()) / 4 / game_sensitivity / XCONTROL + rand() % (XSCALE + XSCALE) + (-XSCALE);
			}
			else if (thompson_active) {
				return ((Recoil_Thompson_g[b].x * ScopeAttachment()) * BarrelAttachment()) / 4 / game_sensitivity / XCONTROL + rand() % (XSCALE + XSCALE) + (-XSCALE);
			}
			else if (custom_active) {
				return ((Recoil_Custom_g[b].x * ScopeAttachment()) * BarrelAttachment()) / 4 / game_sensitivity / XCONTROL + rand() % (XSCALE + XSCALE) + (-XSCALE);
			}
			else if (m249_active) {
				return ((Recoil_M249[b].x * ScopeAttachment()) * BarrelAttachment()) / 4 / game_sensitivity / XCONTROL + rand() % (XSCALE + XSCALE) + (-XSCALE);
			}
			else if (semi_active) {
				return ((Recoil_Semi_r[b].x * ScopeAttachment()) * BarrelAttachment()) / 4 / game_sensitivity / XCONTROL + rand() % (XSCALE + XSCALE) + (-XSCALE);
			}
			else if (python_active) {
				return ((python_t[b].x * ScopeAttachment()) * BarrelAttachment()) / 4 / game_sensitivity / XCONTROL + rand() % (XSCALE + XSCALE) + (-XSCALE);
			}
			else if (m39_active) {
				return ((m39_t[b].x * ScopeAttachment()) * BarrelAttachment()) / 4 / game_sensitivity / XCONTROL + rand() % (XSCALE + XSCALE) + (-XSCALE);
			}
			else
				return 0;
		}
	}
	double y(int b) {                                                                                       //Y RANDOMIZATION ON AND OFF
		if (randomxy_active == false) {
			if (ak_active) {
				return (Recoil_Ak47[b].y * ScopeAttachment() * BarrelAttachment() / 4) / game_sensitivity / YCONTROL;
			}
			else if (lr_active) {
				return (Recoil_Lr300[b].y * ScopeAttachment() * BarrelAttachment() / 4) / game_sensitivity / YCONTROL;
			}
			else if (mp5_active) {
				return (Recoil_Mp5a4[b].y * ScopeAttachment() * BarrelAttachment() / 4) / game_sensitivity / YCONTROL;
			}
			else if (thompson_active) {
				return (Recoil_Thompson_g[b].y * ScopeAttachment() * BarrelAttachment() / 4) / game_sensitivity / YCONTROL;
			}
			else if (custom_active) {
				return (Recoil_Custom_g[b].y * ScopeAttachment() * BarrelAttachment() / 4) / game_sensitivity / YCONTROL;
			}
			else if (m249_active) {
				return (Recoil_M249[b].y * ScopeAttachment() * BarrelAttachment() / 4) / game_sensitivity / YCONTROL;
			}
			else if (semi_active) {
				return (Recoil_Semi_r[b].y * ScopeAttachment() * BarrelAttachment() / 4) / game_sensitivity / YCONTROL;
			}
			else if (python_active) {
				return (python_t[b].y * ScopeAttachment() * BarrelAttachment() / 4) / game_sensitivity / YCONTROL;
			}
			else if (m39_active) {
				return (m39_t[b].y * ScopeAttachment() * BarrelAttachment() / 4) / game_sensitivity / YCONTROL;
			}
			else
				return 0;
		}
		if (randomxy_active == true) {


			if (ak_active) {
				return ((Recoil_Ak47[b].y * ScopeAttachment()) * BarrelAttachment()) / 4 / game_sensitivity / YCONTROL + rand() % (YSCALE + YSCALE) + (-YSCALE);
			}
			else if (lr_active) {
				return ((Recoil_Lr300[b].y * ScopeAttachment()) * BarrelAttachment()) / 4 / game_sensitivity / YCONTROL + rand() % (YSCALE + YSCALE) + (-YSCALE);;
			}
			else if (mp5_active) {
				return ((Recoil_Mp5a4[b].y * ScopeAttachment()) * BarrelAttachment()) / 4 / game_sensitivity / YCONTROL + rand() % (YSCALE + YSCALE) + (-YSCALE);;
			}
			else if (thompson_active) {
				return ((Recoil_Thompson_g[b].y * ScopeAttachment()) * BarrelAttachment()) / 4 / game_sensitivity / YCONTROL + rand() % (YSCALE + YSCALE) + (-YSCALE);;
			}
			else if (custom_active) {
				return ((Recoil_Custom_g[b].y * ScopeAttachment()) * BarrelAttachment()) / 4 / game_sensitivity / YCONTROL + rand() % (YSCALE + YSCALE) + (-YSCALE);;
			}
			else if (m249_active) {
				return ((Recoil_M249[b].y * ScopeAttachment()) * BarrelAttachment()) / 4 / game_sensitivity / YCONTROL + rand() % (YSCALE + YSCALE) + (-YSCALE);;
			}
			else if (semi_active) {
				return ((Recoil_Semi_r[b].y * ScopeAttachment()) * BarrelAttachment()) / 4 / game_sensitivity / YCONTROL + rand() % (YSCALE + YSCALE) + (-YSCALE);;
			}
			else if (python_active) {
				return ((python_t[b].y * ScopeAttachment()) * BarrelAttachment()) / 4 / game_sensitivity / YCONTROL + rand() % (YSCALE + YSCALE) + (-YSCALE);;
			}
			else if (m39_active) {
				return ((m39_t[b].y * ScopeAttachment()) * BarrelAttachment()) / 4 / game_sensitivity / YCONTROL + rand() % (YSCALE + YSCALE) + (-YSCALE);;
			}
			else
				return 0;
		}

	}
	double Delay() {
		if (ak_active == true)
			return WeaponData::AK47.Delay;
		else if (lr_active == true)
			return WeaponData::LR300.Delay;
		else if (mp5_active == true)
			return WeaponData::MP5.Delay;
		else if (thompson_active == true)
			return WeaponData::THOMPSON.Delay;
		else if (custom_active == true)
			return WeaponData::CUSTOM_SMG.Delay;
		else if (m249_active == true)
			return WeaponData::M249.Delay;
		else if (semi_active == true)
			return WeaponData::SEMI.Delay;
		else if (python_active == true) {
			return WeaponData::PYTHON.Delay;
		}
		else if (m39_active == true) {
			return WeaponData::M39.Delay;
		}

		return 0;
	}
	double Control(int bullet) {
		if (legitmode == true) {
			if (ak_active == true)
				return WeaponData::AK47.Delay;
			else if (lr_active == true)
				return WeaponData::LR300.Delay;
			else if (mp5_active == true)
				return WeaponData::MP5.Delay;
			else if (thompson_active == true)
				return WeaponData::THOMPSON.Delay;
			else if (custom_active == true)
				return WeaponData::CUSTOM_SMG.Delay;
			else if (m249_active == true)
				return WeaponData::M249.Delay;
			else if (semi_active == true)
				return WeaponData::SEMI.Delay;
			else if (python_active == true) {
				return WeaponData::PYTHON.Delay;
			}
			else if (m39_active == true) {
				return WeaponData::M39.Delay;
			}
		}
		else {
			if (ak_active == true)
				return ControlTime_Ak47[bullet];
			else if (lr_active == true)
				return control_lr[bullet];
			else if (mp5_active == true)
				return control_mp5[bullet];
			else if (thompson_active == true)
				return control_thompson[bullet];
			else if (custom_active == true)
				return control_custom[bullet];
			else if (m249_active == true)
				return WeaponData::M249.Delay;
			else if (semi_active == true)
				return WeaponData::SEMI.Delay;
			else if (python_active == true) {
				return WeaponData::PYTHON.Delay;
			}
			else if (m39_active == true) {
				return WeaponData::M39.Delay;
			}
		}
		return 0;
	}
	int Bullet() {
		if (ak_active == true)
			return Recoil_Ak47.size() - 1;
		else if (lr_active == true)
			return Recoil_Lr300.size() - 1;
		else if (mp5_active == true)
			return Recoil_Mp5a4.size() - 1;
		else if (thompson_active == true)
			return Recoil_Thompson_g.size() - 1;
		else if (custom_active == true)
			return Recoil_Custom_g.size() - 1;
		else if (m249_active == true)
			return Recoil_M249.size() - 1;
		else if (semi_active == true)
			return Recoil_Semi_r.size() - 1;
		else if (python_active == true)
			return python_t.size() - 1;
		else if (m39_active == true)
			return m39_t.size() - 1;
		else
			return 0;
	}
	bool WeaponActive() {
		if (ak_active == true || lr_active == true || mp5_active == true || thompson_active == true || custom_active == true || semi_active == true || m249_active == true || python_active == true || m39_active == true)
			return true;
		else
			return false;
	}

	void RecoilBreak(int count) {
		if (semi_active == true) {
			mouse_event(MOUSEEVENTF_LEFTUP, 0, 0, 0, 0);
		}
		if (m39_active == true) {
			mouse_event(MOUSEEVENTF_LEFTUP, 0, 0, 0, 0);
		}
		if (semi_active == true) {
			mouse_event(MOUSEEVENTF_LEFTUP, 0, 0, 0, 0);
		}
		else if (m249_active == true) {
		}
		else if (semi_active != true || m249_active != true || m39_active != true) {
			if (count == CurrentWeapon::Bullet()) {
				if (BSound == true) {
					Beep(1200, 90);
					Beep(1500, 90);
				}
				mouse_event(MOUSEEVENTF_LEFTUP, 0, 0, 0, 0);
			}
		}
	}
};

void Smoothing(double delay, double control_time, int x, int y) {
	int x_ = 0, y_ = 0, t_ = 0;
	for (int i = 1; i <= (int)control_time; ++i) {
		int xI = i * x / (int)control_time;
		int yI = i * y / (int)control_time;
		int tI = i * (int)control_time / (int)control_time;
		mouse_event(1, (int)xI - (int)x_, (int)yI - (int)y_, 0, 0);
		pQuerySleep((int)tI - (int)t_);
		x_ = xI; y_ = yI; t_ = tI;
	}
	pQuerySleep((int)delay - (int)control_time);
}
int IsMuzzleBoost(float Delay) {
	if (bMuzzleBoost == true) {
		float difference = Delay * 0.1f;
		Delay = Delay - difference;
		return (int)Delay + 2;
	}
	else
		return (int)Delay;
}
bool RecoilExecution() {
	for (;;) {
		if (CurrentWeapon::WeaponActive() == true)
		{
			for (int i = 0; i <= CurrentWeapon::Bullet() && GetAsyncKeyState(VK_LBUTTON) & 0x8000 && GetAsyncKeyState(VK_RBUTTON) & 0x8000; i++)
			{
				Smoothing((int)IsMuzzleBoost((float)CurrentWeapon::Delay()), (int)IsMuzzleBoost(CurrentWeapon::Control(i)), (int)CurrentWeapon::x(i), (int)CurrentWeapon::y(i));
				CurrentWeapon::RecoilBreak(i);
			}
			Sleep(1);
		}
		Sleep(1);
	}
	return false;
}

bool Recoils() {
	if (GetAsyncKeyState(akbind)) {

		ak_active = !ak_active;
		if (ak_active == true)
		{
			lr_active = false, mp5_active = false, thompson_active = false, custom_active = false, m249_active = false, semi_active = false; python_active = false; m39_active = false;
			selectedItemWP = 1;
			Active_Weapon = "AK47";

			if (BSound == true) {
				Beep(300, 150);
			}
			Sleep(200);
		}
		else if (ak_active == false) {
			ak_active = false, lr_active = false, mp5_active = false, thompson_active = false, custom_active = false, m249_active = false, semi_active = false;
			holo_active = false, sniper_active = false, simple_active = false; x16_active = false;
			silencer_active = false;


			selectedItemWP = 0;

			Active_Weapon = "NONE";
			if (BSound == true) {
				Beep(150, 150);
			};
			Sleep(200);
		}
	}
	if (GetAsyncKeyState(lrbind)) {

		lr_active = !lr_active;
		if (lr_active == true)
		{
			ak_active = false, mp5_active = false, thompson_active = false, custom_active = false, m249_active = false, semi_active = false; python_active = false; m39_active = false;
			selectedItemWP = 2;
			Active_Weapon = "LR300";
			if (BSound == true) {
				Beep(150, 150);
			}
			Sleep(200);
		}
		else if (lr_active == false) {
			ak_active = false, lr_active = false, mp5_active = false, thompson_active = false, custom_active = false, m249_active = false, semi_active = false;
			holo_active = false, sniper_active = false, simple_active = false; x16_active = false;
			silencer_active = false;



			selectedItemWP = 0;
			Active_Weapon = "NONE";
			if (BSound == true) {
				Beep(150, 150);
			}
			Sleep(200);
		}
	}
	if (GetAsyncKeyState(mpbind)) {

		mp5_active = !mp5_active;
		if (mp5_active == true)
		{
			ak_active = false, lr_active = false, thompson_active = false, custom_active = false, m249_active = false, semi_active = false; python_active = false; m39_active = false;
			Active_Weapon = "MP5";
			selectedItemWP = 3;
			if (BSound == true) {
				Beep(150, 150);
			}
			Sleep(200);

		}
		else if (mp5_active == false) {
			ak_active = false, lr_active = false, mp5_active = false, thompson_active = false, custom_active = false, m249_active = false, semi_active = false;
			holo_active = false, sniper_active = false, simple_active = false; x16_active = false;
			silencer_active = false;



			selectedItemWP = 0;
			Active_Weapon = "NONE";

			if (BSound == true) {
				Beep(150, 150);
			}
			Sleep(200);
		}
	}
	if (GetAsyncKeyState(csbind) != 0) {

		custom_active = !custom_active;
		if (custom_active == true)
		{
			ak_active = false, lr_active = false, mp5_active = false, thompson_active = false, m249_active = false, semi_active = false; python_active = false; m39_active = false;
			selectedItemWP = 4;
			Active_Weapon = "SMG";
			if (BSound == true) {
				Beep(150, 150);
			}
			Sleep(200);
		}
		else if (custom_active == false) {
			ak_active = false, lr_active = false, mp5_active = false, thompson_active = false, custom_active = false, m249_active = false, semi_active = false;
			holo_active = false, sniper_active = false, simple_active = false; x16_active = false;
			silencer_active = false;



			selectedItemWP = 0;
			Active_Weapon = "NONE";
			if (BSound == true) {
				Beep(150, 150);
			}
			Sleep(200);
		}
	}
	if (GetAsyncKeyState(tmbind) != 0) {

		thompson_active = !thompson_active;
		if (thompson_active == true)
		{
			ak_active = false, lr_active = false, mp5_active = false, custom_active = false, m249_active = false, semi_active = false; python_active = false; m39_active = false;
			selectedItemWP = 5;
			Active_Weapon = "TOMMY";
			if (BSound == true) {
				Beep(150, 150);
			}
			Sleep(200);
		}
		else if (thompson_active == false) {
			ak_active = false, lr_active = false, mp5_active = false, thompson_active = false, custom_active = false, m249_active = false, semi_active = false;
			holo_active = false, sniper_active = false, simple_active = false; x16_active = false;
			silencer_active = false;



			selectedItemWP = 0;
			Active_Weapon = "NONE";
			if (BSound == true) {
				Beep(150, 150);
			}
			Sleep(200);
		}
	}
	if (GetAsyncKeyState(smbind) != 0) {

		semi_active = !semi_active;
		if (semi_active == true)
		{
			ak_active = false, lr_active = false, mp5_active = false, thompson_active = false, m249_active = false, custom_active = false; python_active = false; m39_active = false;
			selectedItemWP = 6;
			Active_Weapon = "SEMI";
			if (BSound == true) {
				Beep(150, 150);
			}
			Sleep(200);
		}
		else if (semi_active == false) {
			ak_active = false, lr_active = false, mp5_active = false, thompson_active = false, custom_active = false, m249_active = false, semi_active = false;
			holo_active = false, sniper_active = false, simple_active = false; x16_active = false;
			silencer_active = false;



			selectedItemWP = 0;
			Active_Weapon = "NONE";
			if (BSound == true) {
				Beep(150, 150);
			}
			Sleep(200);
		}
	}
	if (GetAsyncKeyState(m2bind)) {

		m249_active = !m249_active;
		if (m249_active == true)
		{
			ak_active = false, lr_active = false, mp5_active = false, thompson_active = false, semi_active = false, custom_active = false; python_active = false; m39_active = false;
			selectedItemWP = 7;
			Active_Weapon = "M249";
			if (BSound == true) {
				Beep(150, 150);
			}
			Sleep(200);
		}
		else if (m249_active == false) {
			ak_active = false, lr_active = false, mp5_active = false, thompson_active = false, custom_active = false, m249_active = false, semi_active = false;
			holo_active = false, sniper_active = false, simple_active = false; x16_active = false;
			silencer_active = false;



			selectedItemWP = 0;
			Active_Weapon = "NONE";

			if (BSound == true) {
				Beep(150, 150);
			}
			Sleep(200);
		}
	}
	if (GetAsyncKeyState(ptbind) != 0) {


		python_active = !python_active;
		if (python_active == true)
		{
			ak_active = false, lr_active = false, mp5_active = false, thompson_active = false, semi_active = false, custom_active = false; m249_active = false; m39_active = false;
			selectedItemWP = 8;
			Active_Weapon = "HMLMG";
			if (BSound == true) {
				Beep(150, 150);
			}
			Sleep(200);
		}
		else if (python_active == false) {
			ak_active = false, lr_active = false, mp5_active = false, thompson_active = false, custom_active = false, m249_active = false, semi_active = false;
			holo_active = false, sniper_active = false, simple_active = false; x16_active = false;
			silencer_active = false;



			selectedItemWP = 0;
			Active_Weapon = "NONE";
			if (BSound == true) {
				Beep(150, 150);
			}
			Sleep(200);
		}
	}
	///////Scopes
	if (GetAsyncKeyState(hhbind)) {
		holo_active = !holo_active;
		if (holo_active == true)
		{
			sniper_active = false, simple_active = false; x16_active = false;

			Active_Scopes = "HOLO";
			selectedItemSC = 3;
			if (BSound == true) {
				Beep(150, 150);
			}
			Sleep(200);
		}
		else if (holo_active == false) {

			Active_Scopes = "NONE";
			selectedItemSC = 0;
			if (BSound == true) {
				Beep(150, 150);
			}
			Sleep(200);
		}
	}
	if (GetAsyncKeyState(xxbind)) {
		sniper_active = !sniper_active;
		if (sniper_active == true)
		{
			holo_active = false, simple_active = false; x16_active = false;
			selectedItemSC = 1;
			Active_Scopes = "8X";
			if (BSound == true) {
				Beep(150, 150);
			}
			Sleep(200);
		}
		else if (sniper_active == false) {
			selectedItemSC = 0;

			Active_Scopes = "NONE";
			if (BSound == true) {
				Beep(150, 150);
			}
			Sleep(200);
		}
	}
	if (GetAsyncKeyState(ssbind)) {
		simple_active = !simple_active;
		if (simple_active == true)
		{
			holo_active = false, sniper_active = false; x16_active = false;
			selectedItemSC = 4;
			Active_Scopes = "SIMPLE";
			if (BSound == true) {
				Beep(150, 150);
			}
			Sleep(200);
		}
		else if (simple_active == false) {

			Active_Scopes = "NONE";
			selectedItemSC = 0;
			if (BSound == true) {
				Beep(150, 150);
			}
			Sleep(200);
		}
	}
	if (GetAsyncKeyState(yybind) != 0) {
		x16_active = !x16_active;
		if (x16_active == true)
		{
			holo_active = false, sniper_active = false; simple_active = false;
			selectedItemSC = 2;
			Active_Scopes = "16X";
			if (BSound == true) {
				Beep(150, 150);
			}
			Sleep(200);
		}
		else if (x16_active == false) {

			Active_Scopes = "NONE";

			selectedItemSC = 0;
			if (BSound == true) {
				Beep(150, 150);
			}
			Sleep(200);
		}
	}
	if (GetAsyncKeyState(slbind) != 0) {
		silencer_active = !silencer_active;
		if (silencer_active == true)
		{
			selectedItemBR = 1;
			Active_Barrel = "SILENCER";
			if (BSound == true) {
				Beep(150, 150);
			}
			Sleep(200);
		}
		else if (silencer_active == false) {
			selectedItemBR = 0;
			Active_Barrel = "NONE";
			if (BSound == true) {
				Beep(150, 150);
			}
			Sleep(200);
		}


	}
	if (GetAsyncKeyState(rpbind) & 0x8000)
	{
		if (bRapidf == true) {

			mouse_event(MOUSEEVENTF_LEFTDOWN, 0, 0, 0, 0);
			Sleep(75);
			mouse_event(MOUSEEVENTF_LEFTUP, 0, 0, 0, 0);
			Sleep(75);
		}
		else {
		}
	}
	if (GetAsyncKeyState(resbind) != 0) {

		ak_active, lr_active, mp5_active, custom_active, thompson_active, m249_active, python_active, m39_active = false;
		sniper_active, x16_active, holo_active, simple_active, silencer_active = false;

		selectedItemWP = 0;
		selectedItemSC = 0;
		selectedItemBR = 0;

		Active_Weapon = "NONE";
		Active_Scopes = "NONE";
		Active_Barrel = "NONE";

		if (BSound == true) {
			Beep(150, 150);
		}
		Sleep(200);
	}



	return false;
}

void pQuerySleep(int ms) // Sleep / Delay
{
	LONGLONG timerResolution;
	LONGLONG wantedTime;
	LONGLONG currentTime;

	QueryPerformanceFrequency((LARGE_INTEGER*)&timerResolution);
	timerResolution /= 1000;

	QueryPerformanceCounter((LARGE_INTEGER*)&currentTime);
	wantedTime = currentTime / timerResolution + ms;
	currentTime = 0;
	while (currentTime < wantedTime)
	{
		QueryPerformanceCounter((LARGE_INTEGER*)&currentTime);
		currentTime /= timerResolution;
	}
}