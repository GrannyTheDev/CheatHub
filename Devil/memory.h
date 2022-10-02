#include <windows.h>
#include <vector>

namespace mem
{
	class ac_client
	{
	public:
		DWORD rifleammo = 0x0017E0A8;
		std::vector<DWORD> rifleammo_offsets = { 0x140 };
		DWORD riflemag = 0x0017E0A8;
		std::vector<DWORD> riflemag_offsets = { 0x11C };
		DWORD pistolammo = 0x0017E0A8;
		std::vector<DWORD> pistolammo_offsets = { 0x12C };
		DWORD pistolmag = 0x0017E0A8;
		std::vector<DWORD> pistolmag_offsets = { 0x108 };
		DWORD grenade = 0x0017E0A8;
		std::vector<DWORD> grenade_offsets = { 0x144 };
		DWORD rapidrifle = 0x0017E0A8;
		std::vector<DWORD> rapidrifle_offsets = { 0x164 };
		DWORD rapidpistol = 0x0017E0A8;
		std::vector<DWORD> rapidpistol_offsets = { 0x150 };
		DWORD rapidknife = 0x0017E0A8;
		std::vector<DWORD> rapidknife_offsets = { 0x14C };
		DWORD rapidgrenade = 0x0017E0A8;
		std::vector<DWORD> rapidgrenade_offsets = { 0x168 };
		DWORD health = 0x0017E0A8;
		std::vector<DWORD> health_offsets = { 0xEC };
		DWORD armor = 0x0017E0A8;
		std::vector<DWORD> armor_offsets = { 0xF0 };
		DWORD autofirerifle = 0x0017E0A8;
		std::vector<DWORD> autofirerifle_offsets = { 0x204 };
	};
}