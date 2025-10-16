#include <wx/choice.h>
#include <wx/slider.h>
#include <wx/textctrl.h>
#include <wx/wx.h>

class MyFrame : public wxFrame {
public:
  MyFrame()
      : wxFrame(nullptr, wxID_ANY, "wxWidgets Controls Demo", wxDefaultPosition,
                {640, 420}) {
    wxPanel *panel = new wxPanel(this);

    // Layout sizer
    wxBoxSizer *vbox = new wxBoxSizer(wxVERTICAL);

    // Label + text control
    wxBoxSizer *h1 = new wxBoxSizer(wxHORIZONTAL);
    h1->Add(new wxStaticText(panel, wxID_ANY, "Name:"), 0,
            wxALIGN_CENTER_VERTICAL | wxRIGHT, 8);
    nameCtrl = new wxTextCtrl(panel, wxID_ANY);
    h1->Add(nameCtrl, 1, wxEXPAND);
    vbox->Add(h1, 0, wxALL | wxEXPAND, 10);

    // Buttons
    wxBoxSizer *h2 = new wxBoxSizer(wxHORIZONTAL);
    wxButton *btnHello = new wxButton(panel, wxID_ANY, "Say Hello");
    wxButton *btnClear = new wxButton(panel, wxID_ANY, "Clear");
    h2->Add(btnHello, 0, wxRIGHT, 8);
    h2->Add(btnClear, 0);
    vbox->Add(h2, 0, wxLEFT | wxBOTTOM, 10);

    // Slider + gauge
    wxBoxSizer *h3 = new wxBoxSizer(wxHORIZONTAL);
    slider = new wxSlider(panel, wxID_ANY, 50, 0, 100);
    h3->Add(new wxStaticText(panel, wxID_ANY, "Volume:"), 0,
            wxALIGN_CENTER_VERTICAL | wxRIGHT, 8);
    h3->Add(slider, 1, wxEXPAND);
    gauge = new wxGauge(panel, wxID_ANY, 100);
    h3->Add(gauge, 0, wxLEFT, 12);
    vbox->Add(h3, 0, wxALL | wxEXPAND, 10);

    // Choice (combo) and checkbox
    wxBoxSizer *h4 = new wxBoxSizer(wxHORIZONTAL);
    wxArrayString choices;
    choices.Add("Red");
    choices.Add("Green");
    choices.Add("Blue");
    choice = new wxChoice(panel, wxID_ANY, wxDefaultPosition, wxDefaultSize,
                          choices);
    choice->SetSelection(0);
    checkbox = new wxCheckBox(panel, wxID_ANY, "Enable feature");
    h4->Add(new wxStaticText(panel, wxID_ANY, "Color:"), 0,
            wxALIGN_CENTER_VERTICAL | wxRIGHT, 8);
    h4->Add(choice, 0, wxRIGHT, 16);
    h4->Add(checkbox, 0, wxALIGN_CENTER_VERTICAL);
    vbox->Add(h4, 0, wxALL, 10);

    // Multi-line log
    logCtrl = new wxTextCtrl(panel, wxID_ANY, "", wxDefaultPosition,
                             wxDefaultSize, wxTE_MULTILINE | wxTE_READONLY);
    vbox->Add(logCtrl, 1, wxALL | wxEXPAND, 10);

    panel->SetSizer(vbox);

    // Bind events
    btnHello->Bind(wxEVT_BUTTON, &MyFrame::OnHello, this);
    btnClear->Bind(wxEVT_BUTTON, &MyFrame::OnClear, this);
    slider->Bind(wxEVT_SLIDER, &MyFrame::OnSlider, this);
    choice->Bind(wxEVT_CHOICE, &MyFrame::OnChoice, this);
    checkbox->Bind(wxEVT_CHECKBOX, &MyFrame::OnCheck, this);
  }

private:
  wxTextCtrl *nameCtrl;
  wxSlider *slider;
  wxGauge *gauge;
  wxChoice *choice;
  wxCheckBox *checkbox;
  wxTextCtrl *logCtrl;

  void AppendLog(const wxString &s) { logCtrl->AppendText(s + "\n"); }

  void OnHello(wxCommandEvent &) {
    wxString name = nameCtrl->GetValue();
    if (name.IsEmpty())
      name = "World";
    AppendLog("Hello, " + name + "!");
  }

  void OnClear(wxCommandEvent &) {
    nameCtrl->Clear();
    AppendLog("Cleared name field.");
  }

  void OnSlider(wxCommandEvent &e) {
    int val = e.GetInt();
    gauge->SetValue(val);
    AppendLog(wxString::Format("Slider: %d", val));
  }

  void OnChoice(wxCommandEvent &e) {
    AppendLog("Color chosen: " + choice->GetStringSelection());
  }

  void OnCheck(wxCommandEvent &e) {
    AppendLog(
        wxString::Format("Feature %s", e.IsChecked() ? "enabled" : "disabled"));
  }
};

class MyApp : public wxApp {
public:
  bool OnInit() override {
    (new MyFrame())->Show();
    return true;
  }
};

wxIMPLEMENT_APP(MyApp);
