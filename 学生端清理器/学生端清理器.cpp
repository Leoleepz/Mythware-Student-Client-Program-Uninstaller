// 学生端清理器.cpp: 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include "Services.h"
#include "Pri.h"
#include "Process.h"
#include "Reg.h"
#include "File.h"
using namespace std;
inline void CloseService()
{
	
	CHAR S[] = TEXT("STUDSRV");
	DeleteSampleService(S);
}

inline void CloseProgram()
{
	Kill("StudentMain.exe");
	Kill("GATESRV.exe");
	Kill("MasterHelper.exe");
	Kill("ProcHelper.exe");
}
int main()
{
	ios::sync_with_stdio(false);
	st:
	EnableDebugPrivilege();
	CloseService();
	CloseProgram();
	cout << "学生端程序终止：成功" << endl;
	CloseService();
	cout << "学生端服务删除：成功" << endl;
	cout << "正在搜寻注册表值...请稍后" << endl;
	DoKill();

	cout << endl << "正在删除剩余键值(x64)：SOFTWARE\\WOW6432Node\\TopDomain" << endl;
	if (SHDeleteKey(HKEY_LOCAL_MACHINE,
		TEXT("SOFTWARE\\WOW6432Node\\TopDomain")) == ERROR_SUCCESS)
		cout << "Done" << endl;
	cout << "正在删除剩余键值(x86)：SOFTWARE\\TopDomain" << endl;
	if (SHDeleteKey(HKEY_LOCAL_MACHINE,
		TEXT("SOFTWARE\\TopDomain")) == ERROR_SUCCESS)
		cout << "Done" << endl;

	cout << "注册表清理完毕" << endl << endl;
	cout << "正在强行删除学生端宿主程序" << endl;
	
	DeleteDirectory("C:\\Program Files (x86)\\Mythware");
	cout << "对于x64系统：C:\\Program Files (x86)\\Mythware删除完毕" << endl;
	DeleteDirectory("C:\\Program Files\\Mythware");
	cout << "对于x86系统：C:\\Program Files\\Mythware删除完毕" << endl << endl;
	if (FFF == false)
	{
		cout << "检测到本次操作有注册表故障，是否重试？（1：是，2：否）" << endl;
		FFF = true;
		int a;
		cin >> a;
		if (a == 1)
		{
			system("cls");
			goto st;
		}
		else
		{
			cout << "卸载极域电子教室2015操作完毕！任意键退出！" << endl;
			getchar();
			return 0;
		}
	}
	else
	{
		cout << "检测到msi安装环境损坏，正在为您修复环境..." << endl;
		char tt[MAX_PATH];
		char Buf[MAX_PATH];
		GetCurrentDirectory(MAX_PATH, Buf);
		strcat(Buf, "\\msiBE74.tmp");
		GetTempPath(MAX_PATH, tt);
		strcat(tt, "msiBE74.tmp");
		CopyFile(Buf, tt, 1);
		cout << "成功卸载极域电子教室2015！顺便帮您卸载了学生机房管理助手！任意键退出！" << endl;
		getchar();
	}
    return 0;
}

