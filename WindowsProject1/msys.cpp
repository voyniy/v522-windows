
#include "framework.h"


#include <vector>

struct Msgfn {
	UINT msg;
	void (*fn)(WPARAM wParam, LPARAM lParam);

	static void cntPlus()
	{
		cnt++;
	}
private:
	static UINT cnt;
};


std::vector<Msgfn> msgfnP;
std::vector<Msgfn> msgfnCommand;

//----------------------------------------------------------------------------
bool myEventLoop(HWND hWnd, UINT message, WPARAM wParam, LPARAM lParam)
{
	if (msgfnP.empty()) return false;
	if (message == WM_COMMAND)
	{
	for (auto item : msgfnCommand){
		 if (LOWORD(wParam) == item.msg) { item.fn(wParam, lParam); return true; }
		}
	}
	
	for (auto item : msgfnP){
		if (message == item.msg) { item.fn( wParam, lParam); return true; }
	   }
	return false;
}

//----------------------------------------------------------------------------
void myAddListner( UINT msg, void (*ptrfn)(WPARAM , LPARAM ))
{
	Msgfn _tmp;
	_tmp.msg = msg;
	_tmp.fn = ptrfn;

//	_tmp.cntPlus();
	Msgfn::cntPlus();

	msgfnP.push_back(_tmp);
	
}

//----------------------------------------------------------------------------
void myAddListnerCommand(UINT msg, void (*ptrfn)(WPARAM, LPARAM))
{
	Msgfn _tmp;
	_tmp.msg = msg;
	_tmp.fn = ptrfn;



	msgfnCommand.push_back(_tmp);
}

//----------------------------------------------------------------------------
void myCreateWidget(HWND hWnd)
{

//------------------------------------------------------------------------------------------------------------|
//                                                                                                            |number posle WM_COMMAND
	HWND hStatic =	CreateWindowA("static","qwertyuiop",WS_VISIBLE | WS_CHILD | ES_CENTER, 5,5,200,20, hWnd, NULL,NULL,NULL)
	// HWND h0 = CreateWindowA("edit",........................................| ES_MULTILINE -> edit > 1 stroki
	//                                                                                       | WS_VSCROLL -> + scrolling    
	//HWND h0 = CreateWindowA("button"

}