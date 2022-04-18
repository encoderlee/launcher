#include <windows.h>
#include <string>
#include <filesystem>
using namespace std;


wstring GetExecutablePath()
{
	wchar_t buffer[MAX_PATH + 1] = { 0 };
	GetModuleFileName(NULL, buffer, MAX_PATH);
	wstring path = buffer;
	size_t pos = path.rfind(L'\\');
	path.erase(pos + 1);
	return path;
}

wstring GetExecutableName()
{
	wchar_t buffer[MAX_PATH + 1] = { 0 };
	GetModuleFileName(NULL, buffer, MAX_PATH);
	wstring path = buffer;
	size_t pos = path.rfind(L'\\');
	path.erase(0, pos + 1);
	return path;
}

bool Exec(wstring path, wstring cmdline)
{
	cmdline = L"\"" + path + L"\" " + cmdline;
	STARTUPINFO start_info = { sizeof(start_info) };
	start_info.dwFlags = STARTF_FORCEOFFFEEDBACK;
	PROCESS_INFORMATION process_info = { 0 };
	if (!CreateProcess(NULL, (LPWSTR)cmdline.c_str(), NULL, NULL, FALSE, NULL, NULL, NULL, &start_info, &process_info))
		return false;
	WaitForInputIdle(process_info.hProcess, INFINITE);
	CloseHandle(process_info.hThread);
	CloseHandle(process_info.hProcess);
	return true;
}

int APIENTRY wWinMain(_In_ HINSTANCE hInstance,
                     _In_opt_ HINSTANCE hPrevInstance,
                     _In_ LPWSTR    lpCmdLine,
                     _In_ int       nCmdShow)
{
	wstring path = GetExecutablePath();
	wstring exe_name = GetExecutableName();
	wstring path_target = path + L"dist\\" + exe_name;
	if (!std::filesystem::exists(path_target))
	{
		MessageBox(NULL, (L"not find file: " + path_target).c_str(), L"error", MB_OK);
		return 2;
	}
	if (!Exec(path_target, lpCmdLine))
		return 3;
	return 0;
}
