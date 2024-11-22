module;

#include <vector>
#include <wx/wx.h>
#include <wx/icon.h>

export module MainFrame;

import std;
import TodoList;
import Task;

export class MainFrame : public wxFrame
{
public:
    MainFrame();

private:
    wxPanel *mainPanel;
    wxCheckBox *checkbox;
    wxCheckListBox *checkboxList;
    wxTextCtrl *nameOfTask;
    std::vector<Task> tasks;

    void AddControlls();
    void OnExit(wxCommandEvent& event);
    void OnAbout(wxCommandEvent& event);
    void OnAddMenuButtonClicked(wxCommandEvent& event);
    void onDeleteMenuButtonClicked(wxCommandEvent& event);
    void CreateTaskButton(wxCommandEvent& evt);
    void DeleteTaskButton(wxCommandEvent& evt);
    void UpdateTaskList();
};

class CreateTaskWindow : public wxFrame
{
private:
    wxTextCtrl* taskName;
    wxTextCtrl* taskDescription;
    wxPanel* mainPanel;
    wxStaticText* name;
    wxStaticText* description;
    wxButton* createButton;
    wxButton* quitButton;
    wxString taskNameString;
    wxString taskDescriptionString;
    
    void QuitButtonClicked(wxCommandEvent& evt);
    void CreateButtonClicked(wxCommandEvent& evt);

public:
    CreateTaskWindow();
    wxString GetTaskName();
    wxString GetTaskDescription();
};

enum
{
    ADD_TODOLIST_ID = 2,
    DELETE_TODOLIST_ID = 3
};

MainFrame::MainFrame() : wxFrame(nullptr, wxID_ANY, "Todo List")
{    
    AddControlls();

    tasks.insert(tasks.begin(), Task("Task 1", "No"));
    tasks.insert(tasks.begin(), Task("Task 2", "Nod"));
    tasks.insert(tasks.begin(), Task("Task 4", "No"));
    tasks.insert(tasks.begin(), Task("Task 3", "No"));

    // todo json file einbinden
    
    UpdateTaskList();
}

void MainFrame::AddControlls()
{
    wxIcon appIcon("..\\resources\\appIcon.ico", wxBITMAP_TYPE_ICO);
    SetIcon(appIcon);
    SetSize(wxSize(300, 400));
    MainFrame::SetMinSize(wxSize(300, 400));
    MainFrame::SetMaxSize(wxSize(300, 400));
    MainFrame::SetBackgroundColour(*wxWHITE);
    CenterOnScreen();
    
    wxMenu *menuFile = new wxMenu;
    menuFile->Append(ADD_TODOLIST_ID, "Add new Todo List");
    menuFile->Append(DELETE_TODOLIST_ID, "Delete a TodoList");
    menuFile->AppendSeparator();
    menuFile->Append(wxID_EXIT);
    wxMenu *vieTodoListMenu = new wxMenu;
    wxMenu *menuHelp = new wxMenu;
    menuHelp->Append(wxID_ABOUT);
    wxMenuBar *menuBar = new wxMenuBar;
    
    menuBar->Append(menuFile, "&File");
    menuBar->Append(vieTodoListMenu, "&To Do Lists");
    menuBar->Append(menuHelp, "&Help");
    MainFrame::SetMenuBar( menuBar );
    
    Bind(wxEVT_MENU, &MainFrame::OnAbout, this, wxID_ABOUT);
    Bind(wxEVT_MENU, &MainFrame::OnExit, this, wxID_EXIT);
    Bind(wxEVT_MENU, &MainFrame::OnAddMenuButtonClicked, this, ADD_TODOLIST_ID);
    Bind(wxEVT_MENU, &MainFrame::onDeleteMenuButtonClicked, this, DELETE_TODOLIST_ID);
    
    mainPanel = new wxPanel(this, wxID_ANY);
    wxButton* AddButton = new wxButton(mainPanel, wxID_ANY, wxT("Add"),
                        wxPoint(10,10), wxSize(120, 35));
    wxButton* DeleteButton = new wxButton(mainPanel, wxID_ANY, wxT("Delete"),
                        wxPoint(150,10), wxSize(120, 35));
    checkboxList = new wxCheckListBox(mainPanel, wxID_ANY,
                        wxPoint(10,55), wxSize(260,270));
    
    AddButton->Bind(wxEVT_BUTTON, &MainFrame::CreateTaskButton, this);
    DeleteButton->Bind(wxEVT_BUTTON, &MainFrame::DeleteTaskButton, this);
}


void MainFrame::OnExit(wxCommandEvent& event)
{
    event.Skip();   
    Close(true);
}
 
void MainFrame::OnAbout(wxCommandEvent& event)
{
    event.Skip();   
    wxMessageBox("Written by Markus Kammerstetter","", wxOK | wxICON_INFORMATION);
}

void MainFrame::OnAddMenuButtonClicked(wxCommandEvent& event)
{
    event.Skip();
    wxMessageBox("A new Todo List was created");
    TodoList tdl = TodoList();
}

void MainFrame::onDeleteMenuButtonClicked(wxCommandEvent& event)
{
    event.Skip();
    wxMessageBox("Deleted a todolist");
}

void MainFrame::CreateTaskButton(wxCommandEvent& evt)
{
    evt.Skip();
    CreateTaskWindow* AddFrame = new CreateTaskWindow();
    AddFrame->CenterOnParent();
    AddFrame->Show(true);
    AddFrame->Bind(wxEVT_CLOSE_WINDOW, [this, AddFrame](wxCloseEvent&)
    {
        wxString name = AddFrame->GetTaskName();
        wxString description = AddFrame->GetTaskDescription();
        tasks.insert(tasks.begin(),
        Task(name.ToStdString(), description.ToStdString()));
        UpdateTaskList();
        AddFrame->Destroy();
    });
}

void MainFrame::DeleteTaskButton(wxCommandEvent& evt)
{
    evt.Skip();
} // TODO

void MainFrame::UpdateTaskList()
{
    checkboxList->Clear();
    for (auto& task : tasks)
    {
        checkboxList->Insert(task.getName(), 0);
    }
}

CreateTaskWindow::CreateTaskWindow() : wxFrame(nullptr, wxID_ANY, "Add new Task")
{
    wxIcon appIcon("..\\resources\\appIcon.ico", wxBITMAP_TYPE_ICO);
    SetIcon(appIcon);
    CreateTaskWindow::SetBackgroundColour(*wxWHITE);
    SetSize(wxSize(400, 400));
    CreateTaskWindow::SetMinSize(wxSize(400, 400));
    CreateTaskWindow::SetMaxSize(wxSize(400, 400));
    
    mainPanel = new wxPanel(this, wxID_ANY);
    name = new wxStaticText(mainPanel, wxID_ANY, wxT("Task Name"),
                                    wxPoint(20, 20), wxDefaultSize, 0);
    description = new wxStaticText(mainPanel, wxID_ANY, wxT("Task Description"),
                                    wxPoint(20, 120), wxDefaultSize, 0);
    taskName = new wxTextCtrl(mainPanel, wxID_ANY, "",
                                    wxPoint(20, 50), wxSize(345, 25));
    taskDescription = new wxTextCtrl(mainPanel, wxID_ANY, "",
                                    wxPoint(20, 150), wxSize(345, 90));
    createButton = new wxButton(mainPanel, wxID_ANY, wxT("Create Task"),
                                    wxPoint(225, 275), wxSize(100, 50));
    quitButton = new wxButton(mainPanel, wxID_ANY, wxT("Quit"),
                                    wxPoint(50, 275), wxSize(100, 50));
    quitButton->Bind(wxEVT_BUTTON, &CreateTaskWindow::QuitButtonClicked, this);
    createButton->Bind(wxEVT_BUTTON, &CreateTaskWindow::CreateButtonClicked, this);
}

void CreateTaskWindow::QuitButtonClicked(wxCommandEvent& evt)
{
    evt.Skip();
    Close(true);
}

void CreateTaskWindow::CreateButtonClicked(wxCommandEvent& evt)
{
    evt.Skip();
    taskNameString = taskName->GetValue();
    taskDescriptionString = taskDescription->GetValue();
    if (taskNameString.empty())
    {
        wxMessageBox("No task name selected");
        Close(true);
    }
    wxMessageBox("Task: " + taskNameString + " created");
    Close();
}

wxString CreateTaskWindow::GetTaskName()
{
    return taskNameString;
}

wxString CreateTaskWindow::GetTaskDescription()
{
    return taskDescriptionString;
}