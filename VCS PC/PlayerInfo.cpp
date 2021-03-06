#include "StdAfx.h"
#include "PlayerInfo.h"

#include "World.h"

// Wrappers
WRAPPER void CPlayerInfo::Clear() { EAXJMP(0x56F330); }
WRAPPER void CPlayerInfo::KillPlayer() { EAXJMP(0x56E580); }
WRAPPER void CPlayerInfo::ArrestPlayer() { EAXJMP(0x56E5D0); }

WRAPPER CVehicle* FindPlayerVehicle(signed int nPlayerID, bool bUnk) { WRAPARG(nPlayerID); WRAPARG(bUnk); EAXJMP(0x56E0D0); }

CWanted* FindPlayerWanted(signed int nPlayerID)
{
	if ( nPlayerID < 0 )
		return CWorld::Players[CWorld::PlayerInFocus].GetPlayerData().m_Wanted;

	return CWorld::Players[nPlayerID].GetPlayerData().m_Wanted;
}