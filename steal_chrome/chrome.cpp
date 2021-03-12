#include "chrome.h"
#include <shlobj.h>

bool IsFileExists(const std::wstring& szPath) {
	DWORD dwAttrib = GetFileAttributes(szPath.c_str());
	return (dwAttrib != INVALID_FILE_ATTRIBUTES &&
		!(dwAttrib & FILE_ATTRIBUTE_DIRECTORY));
}

int enum_chrome_profiles() {
	int found = 0;
	wchar_t path[MAX_PATH] = { 0 };
	// 1. Chromeä¯ÀÀÆ÷
	if (SHGetFolderPath(0, CSIDL_LOCAL_APPDATA, 0, SHGFP_TYPE_CURRENT, path) == S_OK) {
		wcscat_s(path, MAX_PATH, L"\\Google\\Chrome\\User Data\\");
		std::wstring chrome_path = path;
		std::wstring default_cookies = chrome_path + L"Default\\Cookies";
		if (IsFileExists(default_cookies)) {
			found++;
			printf("%ws\r\n", default_cookies.c_str());
		}

		for (int j = 0; j < 100; j++) {
			auto db = chrome_path + L"Profile " + std::to_wstring(j) + L"\\Cookies";
			if (IsFileExists(db)) {
				found++;
				printf("%ws\r\n", db.c_str());
			}
		}
	}

	// 2. Edgeä¯ÀÀÆ÷
	if (SHGetFolderPath(0, CSIDL_LOCAL_APPDATA, 0, SHGFP_TYPE_CURRENT, path) == S_OK) {
		wcscat_s(path, MAX_PATH, L"\\Microsoft\\Edge\\User Data\\");
		std::wstring edge_path = path;
		std::wstring default_cookies = edge_path + L"Default\\Cookies";
		if (IsFileExists(default_cookies)) {
			found++;
			printf("%ws\r\n", default_cookies.c_str());
		}

		for (int j = 0; j < 100; j++) {
			auto db = edge_path + L"Profile " + std::to_wstring(j) + L"\\Cookies";
			if (IsFileExists(db)) {
				found++;
				printf("%ws\r\n", db.c_str());
			}
		}
	}
	return found;
}
