#pragma once

#include "component/console.hpp"
#include <utils/io.hpp>

namespace steam
{
	class apps
	{
	public:
		~apps() = default;

		char language[0x30] = { 0 };

		apps()
		{
			std::string content;
			if (::utils::io::read_file("h1-mod\\language.txt", &content))
			{
#if DEBUG
				console::info("Language switched to \"%s\".\n", content.data());
#endif
				strcpy_s(language, sizeof(language), content.data());
				return;
			}

			// default to english if no file is found
			strcpy_s(language, sizeof(language), "english");
		}

		virtual bool BIsSubscribed();
		virtual bool BIsLowViolence();
		virtual bool BIsCybercafe();
		virtual bool BIsVACBanned();
		virtual const char* GetCurrentGameLanguage();
		virtual const char* GetAvailableGameLanguages();
		virtual bool BIsSubscribedApp(unsigned int appID);
		virtual bool BIsDlcInstalled(unsigned int appID);
		virtual unsigned int GetEarliestPurchaseUnixTime(unsigned int nAppID);
		virtual bool BIsSubscribedFromFreeWeekend();
		virtual int GetDLCCount();
		virtual bool BGetDLCDataByIndex(int iDLC, unsigned int* pAppID, bool* pbAvailable, char* pchName,
		                                int cchNameBufferSize);
		virtual void InstallDLC(unsigned int nAppID);
		virtual void UninstallDLC(unsigned int nAppID);
		virtual void RequestAppProofOfPurchaseKey(unsigned int nAppID);
		virtual bool GetCurrentBetaName(char* pchName, int cchNameBufferSize);
		virtual bool MarkContentCorrupt(bool bMissingFilesOnly);
		virtual unsigned int GetInstalledDepots(int* pvecDepots, unsigned int cMaxDepots);
		virtual unsigned int GetAppInstallDir(unsigned int appID, char* pchFolder, unsigned int cchFolderBufferSize);
		virtual bool BIsAppInstalled(unsigned int appID);
	};
}
