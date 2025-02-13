#pragma once
#include <wx/wx.h>

class MainFrame : public wxFrame
{
public:
	MainFrame(const wxString& title);

private:
	void calculate(wxCommandEvent& evt);
	void Operator(wxCommandEvent& evt);
	void ANS(wxCommandEvent& evt);

public:
	wxStaticText* output;

	wxChoice* sign;
	wxArrayString choices;
	wxString choice;
	wxTextCtrl* num1;
	wxTextCtrl* num2;
	wxButton* calc;
	wxButton* plus;
	wxButton* minus;
	wxButton* mult;
	wxButton* divide;
	wxButton* ans;
	wxButton* power;
	wxButton* root2;
	wxButton* rootnn;
	wxButton* power2;
	wxButton* clear;

	wxUniChar root;
	wxUniChar xn;
	wxUniChar xx;
	
	
	double number1;
	double number2;
	double result;

	wxDECLARE_EVENT_TABLE();
};

