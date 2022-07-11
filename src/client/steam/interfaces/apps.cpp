#include <std_include.hpp>
#include "../steam.hpp"

namespace steam
{
	bool apps::BIsSubscribed()
	{
		return true;
	}

	bool apps::BIsLowViolence()
	{
		return false;
	}

	bool apps::BIsCybercafe()
	{
		return false;
	}

	bool apps::BIsVACBanned()
	{
		return false;
	}

	const char* apps::GetCurrentGameLanguage()
	{
		return language;
	}

	const char* apps::GetAvailableGameLanguages()
	{
		return language;
	}

	bool apps::BIsSubscribedApp(unsigned int appID)
	{
		return true;
	}

	bool apps::BIsDlcInstalled(unsigned int appID)
	{
		return true;
	}

	unsigned int apps::GetEarliestPurchaseUnixTime(unsigned int nAppID)
	{
		return 0;
	}

	bool apps::BIsSubscribedFromFreeWeekend()
	{
		return false;
	}

	int apps::GetDLCCount()
	{
		return 0;
	}

	bool apps::BGetDLCDataByIndex(int iDLC, unsigned int* pAppID, bool* pbAvailable, char* pchName,
	                              int cchNameBufferSize)
	{
		return false;
	}

	void apps::InstallDLC(unsigned int nAppID)
	{
	}

	void apps::UninstallDLC(unsigned int nAppID)
	{
	}

	void apps::RequestAppProofOfPurchaseKey(unsigned int nAppID)
	{
	}

	bool apps::GetCurrentBetaName(char* pchName, int cchNameBufferSize)
	{
		strncpy_s(pchName, cchNameBufferSize, "public", cchNameBufferSize);
		return true;
	}

	bool apps::MarkContentCorrupt(bool bMissingFilesOnly)
	{
		return false;
	}

	unsigned int apps::GetInstalledDepots(int* pvecDepots, unsigned int cMaxDepots)
	{
		return 0;
	}

	unsigned int apps::GetAppInstallDir(unsigned int appID, char* pchFolder, unsigned int cchFolderBufferSize)
	{
		return 0;
	}

	bool apps::BIsAppInstalled(unsigned int appID)
	{
		return false;
	}
}