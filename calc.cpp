#include "calc.h"
#include "MainFrame.h"
#include <wx/wx.h>

wxIMPLEMENT_APP(calc);

bool calc::OnInit() {
	MainFrame* mainFrame = new MainFrame("Calc.....short for calculator");
	mainFrame->SetClientSize(800, 600);
	mainFrame->Center();
	mainFrame->Show();
	return true;
}
