#pragma once

#define WEAK __declspec(selectany)

namespace game
{
	/***************************************************************
	 * Functions
	 **************************************************************/
	
	namespace mp
	{
		WEAK symbol<void(int localClientNum, int controllerIndex, const char* text)> Cbuf_AddText{0x0, 0x1CF480};
		WEAK symbol<void(const char* text_in, int limit)> Cmd_TokenizeStringWithLimit{0x0, 0x157A40};
	}

	namespace sp
	{
		WEAK symbol<void(int localClientNum, const char* text)> Cbuf_AddText{0x3764A0, 0x0};
		WEAK symbol<void(const char* text_in)> Cmd_TokenizeString{0x377790, 0x0};
		WEAK symbol<void()> Cmd_EndTokenizeString{0x376C90, 0x0};
	}

	WEAK symbol<void(int type, VariableUnion u)> AddRefToValue{0x3C1F50, 0x5090E0};
	WEAK symbol<void(int type, VariableUnion u)> RemoveRefToValue{0x3C3A60, 0x50ABF0};
	WEAK symbol<void(unsigned int id)> AddRefToObject{0x3C1F40, 0x5090D0};
	WEAK symbol<void(unsigned int id)> RemoveRefToObject{0x3C3950, 0x50AAE0};
	WEAK symbol<unsigned int(unsigned int id)> AllocThread{0x3C22B0, 0x509440};
	WEAK symbol<ObjectVariableValue*(unsigned int* id)> AllocVariable{0x3C2310, 0x5094A0};

	WEAK symbol<void(int localClientNum, int controllerIndex, const char* buffer,
		void (int, int, const char*))> Cbuf_ExecuteBufferInternal{0x3765B0, 0x155BC0};
	WEAK symbol<void(const char* message)> Conbuf_AppendText{0x0, 0x0};
	WEAK symbol<char*(int start)> ConcatArgs{0x296420, 0x413050};
	WEAK symbol<void(int localClientNum, int controllerIndex, const char* text)> Cmd_ExecuteSingleCommand{0x376FF0, 0x156E90};
	WEAK symbol<void(const char* cmdName, void(), cmd_function_s* allocedCmd)> Cmd_AddCommandInternal{0x376A40, 0x156880};
	WEAK symbol<void(const char*)> Cmd_RemoveCommand{0x377670, 0x157690};

	WEAK symbol<void(void*, void*)> AimAssist_AddToTargetList{0x0, 0xE66C0};

	WEAK symbol<void(unsigned int weapon, bool isAlternate, 
		char* output, unsigned int maxStringLen)> BG_GetWeaponNameComplete{0x4B19C0, 0x2E2500};

	WEAK symbol<void()> Com_Frame_Try_Block_Function{0x385280, 0x0};
	WEAK symbol<CodPlayMode()> Com_GetCurrentCoDPlayMode{0x0, 0x5AEF80};
	WEAK symbol<bool()> Com_InFrontend{0xF6430, 0x76A40};
	WEAK symbol<void(float, float, int)> Com_SetSlowMotion{0x0, 0x17E5F0};
	WEAK symbol<void(errorParm code, const char* message, ...)> Com_Error{0x384820, 0x159860};
	WEAK symbol<void()> Com_Quit_f{0x0, 0x1F9280};
	WEAK symbol<void(char const* finalMessage)> Com_Shutdown{0x3A6A50, 0x0};

	WEAK symbol<void()> Quit{0x3A5A20, 0x17CF50};

	WEAK symbol<void(int localClientNum, const char* message)> CG_GameMessage{0x15B3B0, 0x316210};
	WEAK symbol<void(int localClientNum, const char* message)> CG_GameMessageBold{0x15B110, 0x3122F0};
	WEAK symbol<void(int localClientNum, /*mp::cg_s**/void* cg, 
		const char* dvar, const char* value)> CG_SetClientDvarFromServer{0x0, 0x0};
	WEAK symbol<char*(const unsigned int weapon, 
		bool isAlternate, char* outputBuffer, int bufferLen)> CG_GetWeaponDisplayName{0x192B80, 0x104B70};

	WEAK symbol<bool()> CL_IsCgameInitialized{0x1A3210, 0x33C640};
	WEAK symbol<void(int a1)> CL_VirtualLobbyShutdown{0x0, 0x0};

	WEAK symbol<void(int hash, const char* name, const char* buffer)> Dvar_SetCommand{0x41BAD0, 0x1857D0};
	WEAK symbol<dvar_t*(const char* name)> Dvar_FindVar{0x41A600, 0x183EB0};
	WEAK symbol<dvar_t*(int hash)> Dvar_FindMalleableVar{0x41A570, 0x183E20};
	WEAK symbol<void(const dvar_t* dvar)> Dvar_ClearModified{0x41A4F0, 0x183D50};
	WEAK symbol<void(char* buffer, int index)> Dvar_GetCombinedString{0x3A7D60, 0x4EA020};
	WEAK symbol<const char*(dvar_t* dvar, bool is_hashed, dvar_value value)> Dvar_ValueToString{0x41CE00, 0x187000};
	WEAK symbol<void(dvar_t* dvar, DvarSetSource source)> Dvar_Reset{0x41B5F0, 0x185390};
	WEAK symbol<void(const char*, const char*, 
		DvarSetSource)> Dvar_SetFromStringByNameFromSource{0x41BD90, 0x185BD0};

	WEAK symbol<dvar_t*(int hash, const char* name, bool value, 
		unsigned int flags)> Dvar_RegisterBool{0x419220, 0x182340};
	WEAK symbol<dvar_t*(int hash, const char* name, int value, int min, int max, 
		unsigned int flags)> Dvar_RegisterInt{0x419700, 0x182A10};
	WEAK symbol<dvar_t*(int hash, const char* dvarName, float value, float min, 
		float max, unsigned int flags)> Dvar_RegisterFloat{0x4195F0, 0x1827F0};
	WEAK symbol<dvar_t*(int hash, const char* dvarName, float value, float min, 
		float max, unsigned int flags)> Dvar_RegisterFloatHashed{0x0, 0x182900};
	WEAK symbol<dvar_t*(int hash, const char* dvarName, const char* value, 
		unsigned int flags)> Dvar_RegisterString{0x4197E0, 0x182BD0};
	WEAK symbol<dvar_t*(int dvarName, const char* a2, float x, float y, float z, 
		float w, float min, float max, unsigned int flags)> Dvar_RegisterVec4{0x419C60, 0x183010};

	WEAK symbol<long long(const char* qpath, char** buffer)> FS_ReadFile{0x40E280, 0x1EC690};
	WEAK symbol<void(void* buffer)> FS_FreeFile{0x40E270, 0x59E2F0};
	WEAK symbol<void(const char* gameName)> FS_Startup{0x40D890, 0x0};
	WEAK symbol<void(const char* path, const char* dir)> FS_AddLocalizedGameDirectory{0x40B1E0, 0x1878F0};

	WEAK symbol<unsigned int(unsigned int, unsigned int)> GetVariable{0x3C3740, 0x50A8D0};
	WEAK symbol<unsigned int(unsigned int parentId, unsigned int unsignedValue)> GetNewVariable{0x3C3360, 0x50A4F0};
	WEAK symbol<unsigned int(unsigned int parentId, unsigned int unsignedValue)> GetNewArrayVariable{0x3C31E0, 0x50A370};
	WEAK symbol<unsigned int(unsigned int parentId, unsigned int name)> FindVariable{0x3C2E00, 0x509F90};
	WEAK symbol<unsigned int(int entnum, unsigned int classnum)> FindEntityId{0x3C2D00, 0x509E90};
	WEAK symbol<void(unsigned int parentId, unsigned int index)> RemoveVariableValue{0x3C3B00, 0x50AC90};
	WEAK symbol<void(VariableValue* result, unsigned int classnum, 
		int entnum, int offset)> GetEntityFieldValue{0x3C71A0, 0x50E2E0};

	WEAK symbol<int(const char* fname)> generateHashValue{0x11FEA0, 0x183F80};

	WEAK symbol<void()> G_Glass_Update{0x2992E0, 0x417940};
	WEAK symbol<int(int clientNum)> G_GetClientScore{0x0, 0x420420};
	WEAK symbol<unsigned int(const char* name)> G_GetWeaponForName{0x2F20F0, 0x461180};
	WEAK symbol<int(playerState_s* ps, unsigned int weapon, int dualWield, 
		int startInAltMode, int, int, int, char, ...)> G_GivePlayerWeapon{0x2F24F0, 0x461600};
	WEAK symbol<void(playerState_s* ps, unsigned int weapon, int hadWeapon)> G_InitializeAmmo{0x29D9E0, 0x41C170};
	WEAK symbol<void(int clientNum, unsigned int weapon)> G_SelectWeapon{0x2F2EA0, 0x462560};
	WEAK symbol<int(playerState_s* ps, unsigned int weapon)> G_TakePlayerWeapon{0x2F3050, 0x462770};

	WEAK symbol<char*(char* string)> I_CleanStr{0x4293E0, 0x5AF2E0};

	WEAK symbol<const char*(int, int, int)> Key_KeynumToString{0x1AC410, 0x199990};

	WEAK symbol<unsigned int(int)> Live_SyncOnlineDataFlags{0x0, 0x1A5C10};

	WEAK symbol<Material*(const char* material)> Material_RegisterHandle{0x56EA20, 0x692360};

	WEAK symbol<void(netadr_s*, sockaddr*)> NetadrToSockadr{0x416580, 0x59E580};
	WEAK symbol<void(netsrc_t, netadr_s*, const char*)> NET_OutOfBandPrint{0x3AA550, 0x4F1EB0};
	WEAK symbol<void(netsrc_t sock, int length, const void* data, const netadr_s* to)> NET_SendLoopPacket{0x0, 0x4F2070};
	WEAK symbol<bool(const char* s, netadr_s* a)> NET_StringToAdr{0x0, 0x4F2150};

	WEAK symbol<void(float x, float y, float width, float height, float s0, float t0, float s1, float t1,
		float* color, Material* material)> R_AddCmdDrawStretchPic{0x1A29A0, 0x33B2B0};
	WEAK symbol<Font_s*(const char* font, int size)> R_RegisterFont{0x55C4E0, 0x67F630};
	WEAK symbol<int(const char* text, int maxChars, Font_s* font)> R_TextWidth{0x55C7A0, 0x67F8F0};
	WEAK symbol<int(void* font)> R_GetFontHeight{0x55C5C0, 0x67F710};
	WEAK symbol<void*(int a1)> R_GetSomething{0x55BB90, 0x67ECE0};
	WEAK symbol<void()> R_SyncRenderThread{0x582F30, 0x6A78C0};
	WEAK symbol<void*(const char* text, int maxChars, void* font, int fontHeight, float x, 
		float y, float xScale, float yScale, float rotation, float* color, 
		int style, int cursor_pos, char cursor_char, 
		void* style_unk)> H1_AddBaseDrawTextCmd{0x57EA60, 0x6A3080};

#define R_AddCmdDrawText(TXT, MC, F, X, Y, XS, YS, R, C, S) \
	H1_AddBaseDrawTextCmd(TXT, MC, F, game::R_GetFontHeight(F), X, Y, XS, YS, R, C, S, -1, 0, game::R_GetSomething(S))
#define R_AddCmdDrawTextWithCursor(TXT, MC, F, UNK, X, Y, XS, YS, R, C, S, CP, CC) \
	H1_AddBaseDrawTextCmd(TXT, MC, F, game::R_GetFontHeight(F), X, Y, XS, YS, R, C, S, CP, CC, game::R_GetSomething(S))

	WEAK symbol<char* (GfxImage* image, uint32_t width, uint32_t height, uint32_t depth, uint32_t mipCount,
		uint32_t imageFlags, DXGI_FORMAT imageFormat, const char* name, const D3D11_SUBRESOURCE_DATA* initData)> Image_Setup{0x560740, 0x683890};

	WEAK symbol<unsigned int(unsigned int localId, const char* pos, 
		unsigned int paramcount)> VM_Execute{0x3C9E50, 0x510EB0};

	WEAK symbol<void(unsigned int id, scr_string_t stringValue, 
		unsigned int paramcount)> Scr_NotifyId{0x3C92E0, 0x510340};
	WEAK symbol<const float*(const float* v)> Scr_AllocVector{0x3C42D0, 0x50B330};
	WEAK symbol<float(int index)> Scr_GetFloat{0x3C87D0, 0x50F870};
	WEAK symbol<const char*(int index)> Scr_GetString{0x3C8CC0, 0x50FCB0};
	WEAK symbol<int()> Scr_GetNumParam{0x0, 0x50F9D0};
	WEAK symbol<void()> Scr_ClearOutParams{0x3C7EF0, 0x50F070};
	WEAK symbol<scr_entref_t(unsigned int entId)> Scr_GetEntityIdRef{0x3C6760, 0x50D8E0};
	WEAK symbol<unsigned int(int classnum, unsigned int entnum)> Scr_GetEntityId{0x3C66B0, 0x50D830};
	WEAK symbol<int(unsigned int classnum, int entnum, int offset)> Scr_SetObjectField{0x2E8FC0, 0x459CD0};

	WEAK symbol<ScreenPlacement*()> ScrPlace_GetViewPlacement{0x1BCED0, 0x362840};

	WEAK symbol<void(XAssetType type, void(__cdecl* func)(XAssetHeader, void*), const void* inData, bool includeOverride)>
	DB_EnumXAssets_Internal{0x1F0BF0, 0x394C60};
	WEAK symbol<const char*(const XAsset* asset)> DB_GetXAssetName{0x1BF890, 0x366140};
	WEAK symbol<int(XAssetType type)> DB_GetXAssetTypeSize{0x0, 0x0};
	WEAK symbol<XAssetHeader(XAssetType type, const char* name, 
		int createDefault)> DB_FindXAssetHeader{0x1F1120, 0x3950C0};
	WEAK symbol<bool(const char* zone, int source)> DB_FileExists{0x1F0D50, 0x394DC0};
	WEAK symbol<void(XZoneInfo* zoneInfo, unsigned int zoneCount, DBSyncMode syncMode)> DB_LoadXAssets{0x1F31E0, 0x397500};

	WEAK symbol<void(int clientNum, const char* menu, 
		int a3, int a4, unsigned int a5)> LUI_OpenMenu{0x3F20A0, 0x1E1210};
	WEAK symbol<void()> LUI_EnterCriticalSection{0xF19A0, 0x2669B0};
	WEAK symbol<void()> LUI_LeaveCriticalSection{0xF6C40, 0x26BDC0};

	WEAK symbol<bool(int clientNum, const char* menu)> Menu_IsMenuOpenAndVisible{0x4F43C0, 0x389F70};

	WEAK symbol<scr_string_t(const char* str)> SL_FindString{0x3C0F50, 0x507FD0};
	WEAK symbol<scr_string_t(const char* str, unsigned int user)> SL_GetString{0x3C1210, 0x5083A0};
	WEAK symbol<const char*(scr_string_t stringValue)> SL_ConvertToString{0x3C0C50, 0x507CD0};
	WEAK symbol<unsigned int(const char* str)> SL_GetCanonicalString{0x3BDA20, 0x504A00};

	WEAK symbol<void(netadr_s* from)> SV_DirectConnect{0x0, 0x54DBF0};
	WEAK symbol<void(int arg, char* buffer, int bufferLength)> SV_Cmd_ArgvBuffer{0x377D40, 0x1CAC60};
	WEAK symbol<void(const char* text_in)> SV_Cmd_TokenizeString{0x377DC0, 0x1CACE0};
	WEAK symbol<void()> SV_Cmd_EndTokenizedString{0x377D80, 0x1CACA0};

	WEAK symbol<mp::gentity_s*(const char* name)> SV_AddBot{0x0, 0x54D4F0};
	WEAK symbol<bool(int clientNum)> SV_BotIsBot{0x0, 0x53B6D0};
	WEAK symbol<const char*()> SV_BotGetRandomName{0x0, 0x53ABD0};
	WEAK symbol<int(mp::gentity_s* ent)> SV_SpawnTestClient{0x0, 0x550580};

	WEAK symbol<const char*(int clientNum)> SV_GetGuid{0x0, 0x551D90};
	WEAK symbol<int(int clientNum)> SV_GetClientPing{0x0, 0x551D70};
	WEAK symbol<playerState_s* (int num)> SV_GetPlayerstateForClientNum{0x4C3F10, 0x551E10};
	WEAK symbol<void(int index, const char* string)> SV_SetConfigstring{0x0, 0x553E60};
	WEAK symbol<bool()> SV_Loaded{0x4C4810, 0x553970};
	WEAK symbol<void(int clientNum, const char* reason)> SV_KickClientNum{0x0, 0x54C060};
	WEAK symbol<bool(const char* map)> SV_MapExists{0x0, 0x54C0C0};
	WEAK symbol<void(mp::client_t*, const char*, int)> SV_ExecuteClientCommand{0x0, 0x0};
	WEAK symbol<void(int localClientNum)> SV_FastRestart{0x0, 0x54BE00};
	WEAK symbol<void(void* cl, int type, const char* fmt, ...)> SV_SendServerCommand{0x0, 0x1CC040};
	WEAK symbol<void(mp::client_t* drop, const char* reason, bool tellThem)> SV_DropClient_Internal{0x0, 0x54E7F0};

	WEAK symbol<void()> Sys_ShowConsole{0x0, 0x0};
	WEAK symbol<void(const char* error, ...)> Sys_Error{0x0, 0x1D8710};
	WEAK symbol<void(char* path, int pathSize, Sys_Folder folder, const char* filename, const char* ext)>
		Sys_BuildAbsPath{0x42C330, 0x0};
	WEAK symbol<int()> Sys_Milliseconds{0x462B30, 0x5BDDF0};
	WEAK symbol<bool()> Sys_IsDatabaseReady2{0x3AB100, 0x4F79C0};
	WEAK symbol<bool(int, void const*, const netadr_s*)> Sys_SendPacket{0x0, 0x5BDA90};
	WEAK symbol<bool(const char* path)> Sys_FileExists{0x0, 0x0};

	WEAK symbol<const char*(const char*)> UI_GetMapDisplayName{0x0, 0x4DDEE0};
	WEAK symbol<const char*(const char*)> UI_GetGameTypeDisplayName{0x0, 0x4DD8C0};
	WEAK symbol<void(unsigned int localClientNum, const char** args)> UI_RunMenuScript{0x3F3AA0, 0x1E35B0};
	WEAK symbol<int(const char* text, int maxChars, Font_s* font, float scale)> UI_TextWidth{0x3F5D90, 0x0};

	WEAK symbol<const char*(const char* string)> UI_SafeTranslateString{0x3840A0, 0x4E8BC0};

	WEAK symbol<void*(jmp_buf* Buf, int Value)> longjmp{0x6DCA90, 0x826710};
	WEAK symbol<int(jmp_buf* Buf)> _setjmp{0x758980, 0x8A3190};

	/***************************************************************
	 * Variables
	 **************************************************************/

	WEAK symbol<CmdArgs> sv_cmd_args{0xB48FF90, 0x2ED1EB0};

	WEAK symbol<int> g_script_error_level{0xC3FD358, 0xB7AC1A4};
	WEAK symbol<jmp_buf> g_script_error{0xC3FD470, 0xB7AC2C0};
	
	WEAK symbol<unsigned int> levelEntityId{0xBD58DA0, 0xB1100B0};
	WEAK symbol<unsigned int> gameEntityId{0xBD58DA4, 0xB1100B4};

	WEAK symbol<const char*> command_whitelist{0x115ADF0, 0x10ACB70};
	WEAK symbol<cmd_function_s*> cmd_functions{0xB490038, 0x344DF18};
	WEAK symbol<CmdArgs> cmd_args{0xB48FEE0, 0x2ED1E00};
	WEAK symbol<CmdArgsPrivate> cmd_argsPrivate{0, 0x3513F20};

	WEAK symbol<int> connectionState{0x0, 0x2EC82C8};

	WEAK symbol<int> g_poolSize{0x0, 0x0};
	WEAK symbol<int> g_compressor{0x2574804, 0x3962804};

	WEAK symbol<scrVarGlob_t> scr_VarGlob{0xBD80E00, 0xB138180};
	WEAK symbol<scrVmPub_t> scr_VmPub{0xC3F4E20, 0xB7AE3C0};
	WEAK symbol<function_stack_t> scr_function_stack{0xC4015C0, 0xB7B8940};

	WEAK symbol<GfxDrawMethod_s> gfxDrawMethod{0xF7530B0, 0xE9213F0};

	WEAK symbol<int> dvarCount{0xC90E550, 0x2999C34};
	WEAK symbol<dvar_t> dvarPool{0xC90E560, 0x344DF20};

	WEAK symbol<void*> DB_XAssetPool{0xEC9FB0, 0x10B4460};
	WEAK symbol<const char*> g_assetNames{0x991BA0, 0x10B30D0};

	WEAK symbol<int> keyCatchers{0x252AF70, 0x2EC82C4};
	WEAK symbol<PlayerKeyState> playerKeys{0x2395B0C, 0x2999E1C};

	WEAK symbol<SOCKET> query_socket{0xD64D3F8, 0xC9DCD38};

	WEAK symbol<DWORD> threadIds{0xB896210, 0xAC80740};

	namespace mp
	{
		WEAK symbol<gentity_s> g_entities{0x0, 0x71F19E0};
		WEAK symbol<client_t*> svs_clients{0x0, 0x2DC3390};
		WEAK symbol<int> svs_numclients{0x0, 0x2DC338C};
		WEAK symbol<int> gameTime{0x0, 0x7361F9C};

		WEAK symbol<int> sv_serverId_value{0x0, 0x0};

		WEAK symbol<bool> virtualLobby_loaded{0x0, 0x2E6EC9D};

		WEAK symbol<client_state_t*> client_state{0x0, 0x2EC84F0};
		WEAK symbol<connect_state_t*> connect_state{0x0, 0x2EC8510};
	}

	namespace sp
	{
		WEAK symbol<gentity_s> g_entities{0x56E74D0, 0x0};
	}

	namespace hks
	{
		WEAK symbol<lua_State*> lua_state{0x1F0E408, 0x36647F8};
		WEAK symbol<void(lua_State* s, const char* str, unsigned int l)> hksi_lua_pushlstring{0x62E60, 0x79800};
		WEAK symbol<HksObject*(HksObject* result, lua_State* s, const HksObject* table, const HksObject* key)> hks_obj_getfield{0xB5100, 0x22CB90};
		WEAK symbol<void(lua_State* s, const HksObject* tbl, const HksObject* key, const HksObject* val)> hks_obj_settable{0xB6320, 0x22DDB0};
		WEAK symbol<HksObject* (HksObject* result, lua_State* s, const HksObject* table, const HksObject* key)> hks_obj_gettable{0xB55E0, 0x22D070};
		WEAK symbol<void(lua_State* s, int nargs, int nresults, const unsigned int* pc)> vm_call_internal{0xE5E40, 0x25D2F0};
		WEAK symbol<HashTable*(lua_State* s, unsigned int arraySize, unsigned int hashSize)> Hashtable_Create{0xA3570, 0x21B030};
		WEAK symbol<cclosure*(lua_State* s, lua_function function, int num_upvalues, 
			int internal_, int profilerTreatClosureAsFunc)> cclosure_Create{0xA3790, 0x21B250};
		WEAK symbol<int(lua_State* s, int t)> hksi_luaL_ref{0xB7F90, 0x236CC0};
		WEAK symbol<void(lua_State* s, int t, int ref)> hksi_luaL_unref{0xB8130, 0x22FC40};
		WEAK symbol<int(lua_State* s, const HksCompilerSettings* options, const char* buff, 
			unsigned __int64 sz, const char* name)> hksi_hksL_loadbuffer{0xB6B90, 0x22E620};
		WEAK symbol<int(lua_State* s, const char* what, lua_Debug* ar)> hksi_lua_getinfo{0xB84D0, 0x22FFE0};
		WEAK symbol<int(lua_State* s, int level, lua_Debug* ar)> hksi_lua_getstack{0xB87A0, 0x2302B0};
		WEAK symbol<void(lua_State* s, const char* fmt, ...)> hksi_luaL_error{0xBF120, 0x22F930};
		WEAK symbol<void(lua_State* s, int what, int data)> hksi_lua_gc{0, 0x236EF0};
		WEAK symbol<const char*> typenames{0x98CD20, 0x10AD750};
	}
}
