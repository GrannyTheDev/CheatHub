#include <Windows.h>
#include <iostream>
#include <vector>
#include "memory.h"

using namespace std;

DWORD GetPointerAddress(DWORD ptr, std::vector<DWORD> offsets)
{
	DWORD addr = ptr;
	for (int i = 0; i < offsets.size(); ++i)
	{
		addr = *(DWORD*)addr;
		addr += offsets[i];
	}
	return addr;
}

DWORD hideConsole()
{
	HWND hWnd = GetConsoleWindow();
	ShowWindow(hWnd, SW_HIDE);
	return 0;
}

DWORD WINAPI MainThread(HMODULE hModule)
{
	AllocConsole();
	FILE* f;
	freopen_s(&f, "conin$", "r+t", stdin);
	freopen_s(&f, "conout$", "w+t", stdout);
	freopen_s(&f, "conout$", "w+t", stderr);
	string i;
	cout << "Select a cheat to load: Assault cube hack = 1" << endl;
	i = cin.get();
	while (true) {
		if (getchar() == '\n') {
			if (i == "1")
			{
				cout << "Selected Assault Cube hack" << endl;
				Sleep(100);
				cout << "Loading Cheat" << endl;
				Sleep(100);
				cout << "Loaded Cheat" << endl;
				Sleep(100);
				break;
			}
		}
	}
	hideConsole();
	if (i == "1")
	{
		DWORD moduleBase = (DWORD)GetModuleHandle("ac_client.exe");

		mem::ac_client ac_client;

		while (!GetAsyncKeyState(VK_END))
		{
			int* rifleammo = (int*)GetPointerAddress(moduleBase + ac_client.rifleammo, ac_client.rifleammo_offsets);
			*rifleammo = 999;
			int* rifleammomag = (int*)GetPointerAddress(moduleBase + ac_client.riflemag, ac_client.riflemag_offsets);
			*rifleammomag = 999;
			int* pistolammo = (int*)GetPointerAddress(moduleBase + ac_client.pistolammo, ac_client.pistolammo_offsets);
			*pistolammo = 999;
			int* pistolammomag = (int*)GetPointerAddress(moduleBase + ac_client.pistolmag, ac_client.pistolmag_offsets);
			*pistolammomag = 999;
			int* grenade = (int*)GetPointerAddress(moduleBase + ac_client.grenade, ac_client.grenade_offsets);
			*grenade = 999;
			int* rapidrifle = (int*)GetPointerAddress(moduleBase + ac_client.rapidrifle, ac_client.rapidrifle_offsets);
			*rapidrifle = 50;
			int* rapidpistol = (int*)GetPointerAddress(moduleBase + ac_client.rapidpistol, ac_client.rapidpistol_offsets);
			*rapidpistol = 50;
			int* rapidknife = (int*)GetPointerAddress(moduleBase + ac_client.rapidknife, ac_client.rapidknife_offsets);
			*rapidknife = 50;
			int* rapidgrenade = (int*)GetPointerAddress(moduleBase + ac_client.rapidgrenade, ac_client.rapidgrenade_offsets);
			*rapidgrenade = 0;
			int* health = (int*)GetPointerAddress(moduleBase + ac_client.health, ac_client.health_offsets);
			*health = 999;
			int* armor = (int*)GetPointerAddress(moduleBase + ac_client.armor, ac_client.armor_offsets);
			*armor = 100;
		}
	}

	FreeLibraryAndExitThread(hModule, 0);
	return 0;
}

DWORD APIENTRY DllMain(HMODULE hModule, DWORD ul_reason_for_call, LPVOID lpReserved)
{
	switch (ul_reason_for_call)
	{
	case DLL_PROCESS_ATTACH:
		CloseHandle(CreateThread(nullptr, 0, (LPTHREAD_START_ROUTINE)MainThread, hModule, 0, nullptr));
	case DLL_THREAD_ATTACH:
	case DLL_THREAD_DETACH:
	case DLL_PROCESS_DETACH:
		break;
	}
	return TRUE;
}