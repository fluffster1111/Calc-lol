#include "MainFrame.h"
#include <wx/wx.h>
#include <iostream>


enum IDs {
	OUTPUT_ID = 2,
	SIGN_ID = 3,
	NUM1_ID = 4,
	NUM2_ID = 5,
	BUTTON_ID = 6,
	PLUS_ID = 7,
	MINUS_ID = 8,
	MULT_ID = 9,
	DIVID_ID = 10,
	ANS_ID = 11,
	POWER_ID = 12,
	ROOT_ID = 13,
	POWER2_ID = 14,
	CLEAR_ID = 15,
	ROOTN_ID = 16
};

wxBEGIN_EVENT_TABLE(MainFrame, wxFrame)
	EVT_BUTTON(BUTTON_ID, MainFrame::calculate)
	EVT_BUTTON(ANS_ID, MainFrame::ANS)

	EVT_BUTTON(PLUS_ID, MainFrame::Operator)
	EVT_BUTTON(MINUS_ID, MainFrame::Operator)
	EVT_BUTTON(MULT_ID, MainFrame::Operator)
	EVT_BUTTON(DIVID_ID, MainFrame::Operator)
	EVT_BUTTON(POWER_ID, MainFrame::Operator)
	EVT_BUTTON(ROOT_ID, MainFrame::Operator)
	EVT_BUTTON(ROOT_ID, MainFrame::Operator)
	EVT_BUTTON(POWER2_ID, MainFrame::Operator)
	EVT_BUTTON(CLEAR_ID, MainFrame::Operator)
	EVT_BUTTON(ROOTN_ID, MainFrame::Operator)

wxEND_EVENT_TABLE()

MainFrame::MainFrame(const wxString& title)
	: wxFrame(nullptr, wxID_ANY, title), output(nullptr), sign(nullptr), num1(nullptr), num2(nullptr), mult(nullptr), divide(nullptr), plus(nullptr), minus(nullptr), calc(nullptr), ans(nullptr), power(nullptr), root2(nullptr), power2(nullptr), clear(nullptr), root(0x221A), xx(0x00B2), xn(0x207F)
{
	wxPanel* panel = new wxPanel(this);

	output = new wxStaticText(panel, OUTPUT_ID, "", wxPoint(100, 100), wxSize(600, 50), wxALIGN_CENTER | wxALIGN_CENTER_VERTICAL);
	output->SetBackgroundColour(wxColour(255,255,255));
	wxFont font1(24, wxFONTFAMILY_DEFAULT, wxFONTSTYLE_NORMAL, wxFONTWEIGHT_BOLD);
	output->SetFont(font1);

	wxString root_n = wxString::Format("%c%c", xn, root); //nth root

	choices.Add("Operators"); //0
	choices.Add("+");	//1
	choices.Add("-");	//2
	choices.Add("x");	//3
	choices.Add("/");	//4
	choices.Add(xn);	//5
	choices.Add(root); //6
	choices.Add(xx); //7
	choices.Add(root_n); //8

	

	choice = choices[0];

	wxFont font2(14, wxFONTFAMILY_DEFAULT, wxFONTSTYLE_NORMAL, wxFONTWEIGHT_BOLD);

	num1 = new wxTextCtrl(panel, NUM1_ID, " ", wxPoint(150, 280), wxSize(100, 50));
	num1->SetFont(font2);

	num2 = new wxTextCtrl(panel, NUM2_ID, " ", wxPoint(550, 280), wxSize(100, 50));
	num2->SetFont(font2);

	plus = new wxButton(panel, PLUS_ID, "+", wxPoint(280, 280), wxSize(50, 50));
	plus->SetBackgroundColour(wxColour(150, 150, 150));

	minus = new wxButton(panel, MINUS_ID, "-", wxPoint(340, 280), wxSize(50, 50));
	minus->SetBackgroundColour(wxColour(150, 150, 150));

	mult = new wxButton(panel, MULT_ID, "x", wxPoint(400, 280), wxSize(50, 50));
	mult->SetBackgroundColour(wxColour(150, 150, 150));

	divide = new wxButton(panel, DIVID_ID, "/", wxPoint(460, 280), wxSize(50, 50));
	divide->SetBackgroundColour(wxColour(150, 150, 150));

	power = new wxButton(panel, POWER_ID, wxString::Format("x%c", xn), wxPoint(340, 220), wxSize(50, 50));
	power->SetBackgroundColour(wxColour(150, 150, 150));

	root2 = new wxButton(panel, ROOT_ID, root, wxPoint(400, 220), wxSize(50, 50));
	root2->SetBackgroundColour(wxColour(150, 150, 150));

	power2 = new wxButton(panel, POWER2_ID, wxString::Format("x%c", xx), wxPoint(280, 220), wxSize(50, 50));
	power2->SetBackgroundColour(wxColour(150, 150, 150));

	rootnn = new wxButton(panel, ROOTN_ID, wxString::Format("%c%c", xn, root), wxPoint(280, 340), wxSize(50, 50));
	rootnn->SetBackgroundColour(wxColour(150, 150, 150));

	clear = new wxButton(panel, CLEAR_ID, "C", wxPoint(460, 220), wxSize(50, 50));
	clear->SetBackgroundColour(wxColour(150, 150, 150));

	calc = new wxButton(panel, BUTTON_ID, "=", wxPoint(400, 340), wxSize(110, 50));
	calc->SetBackgroundColour(wxColour(150, 150, 150));

	ans = new wxButton(panel, ANS_ID, "ANS", wxPoint(340, 340), wxSize(50, 50));
	ans->SetBackgroundColour(wxColour(150, 150, 150));
}

void MainFrame::Operator(wxCommandEvent& evt)
{
	int buttonID = evt.GetId();

	switch (buttonID) {
	case PLUS_ID:
		choice = choices[1];
		break;
	case MINUS_ID:
		choice = choices[2];
		break;
	case MULT_ID:
		choice = choices[3];
		break;
	case DIVID_ID:
		choice = choices[4];
		break;
	case POWER_ID:
		if (choice == choices[6] || choice == choices[7]) {
			num2->SetLabel("");
		}
		choice = choices[5];
		break;
	case ROOT_ID:
		number2 = 0;
		num2->SetLabel(root);
		choice = choices[6];
		break;
	case POWER2_ID:
		number2 = 0;
		num2->SetLabel(wxString::Format("x%c", xx));
		choice = choices[7];
		break;
	case CLEAR_ID:
		number1 = 0;
		number2 = 0;
		num1->SetLabel("");
		num2->SetLabel("");
		output->SetLabel("");
	case ROOTN_ID:
		choice = choices[8];
		break;
	}
}

void MainFrame::calculate(wxCommandEvent& evt)
{
	wxString GetNum1 = num1->GetValue();

	if (GetNum1.ToDouble(&number1)) {

	}
	else {
		wxMessageBox("Please enter valid number", "Invalid", wxOK | wxICON_ERROR);
	}

	wxString Getnum2 = num2->GetValue();

	if (Getnum2.ToDouble(&number2)) {

	} else if (Getnum2 == wxString::Format("x%c", xx) || Getnum2 == root) {

	} else {
		wxMessageBox("Please enter valid number", "Invalid", wxOK | wxICON_ERROR);
	}


	if (choice == "+") {
		result = number1 + number2;
		output->SetLabel(wxString::Format("%g + %g = %g", number1, number2, result));
	}
	else if (choice == "-") {
		result = number1 - number2;
		output->SetLabel(wxString::Format("%g - %g = %g", number1, number2, result));
	}
	else if (choice == "x") {
		result = number1 * number2;
		output->SetLabel(wxString::Format("%g * %g = %g", number1, number2, result));
	}
	else if (choice == "/") {
		if (number2 != 0) {
			result = number1 / number2;
			output->SetLabel(wxString::Format("%g / %g = %g", number1, number2, result));
		}
		else {
			wxMessageBox("Cannot divide by zero.", "Error", wxOK | wxICON_ERROR);
		}
	} 
	else if (choice == xn) {
		result = pow(number1, number2);
		output->SetLabel(wxString::Format("%g^%g = %g", number1, number2, result));
	}
	else if (choice == root) {
		result = sqrt(number1);
		output->SetLabel(wxString::Format("%s%g = %g",wxString(root), number1, result));
	}
	else if (choice == xx) {
		result = pow(number1, 2);
		output->SetLabel(wxString::Format("%g%s = %g", number1, wxString(xx), result));
	}
	else if (choice == choices[8]) {
		if (number2 != 0) {
			result = pow(number1, (1 / number2));
			output->SetLabel(wxString::Format("%g^%s%g = %g", number2, wxString(root), number1, result));
		}
		else {
			wxMessageBox("Please enter valid number", "Invalid", wxOK | wxICON_ERROR);
		}
		
	}
	
}

void MainFrame::ANS(wxCommandEvent& evt) {
	number1 = result;
	num1->SetLabel(wxString::Format("%g", number1));

	number2 = 0;
	num2->SetLabel("");
	
}
	