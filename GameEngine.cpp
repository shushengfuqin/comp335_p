#include <iostream>
using namespace std;

class State{
public:
    virtual void UpdateState() = 0;

    virtual ~State(){

    }

    
};

class StartState: public State{
public:
    void UpdateState() override{
        cout << "Start State"<<endl;
    }
};

class MapLoadedState: public State{
public:
    void UpdateState() override{
        cout << "Map Loaded State"<<endl;
    }
};

class MapValidatedState: public State{
public:
    void UpdateState() override{
        cout << "Map Validated State"<<endl;
    }
};

class PlayerAddedState: public State{
public:
    void UpdateState() override{
        cout << "Player Added State"<<endl;
    }
};

class AssignReignforcementState: public State{
public:
    void UpdateState() override{
        cout << "Assign Reignforcement State"<<endl;
    }
};

class IssueOrdersState: public State{
public:
    void UpdateState() override{
        cout << "Issue Orders State"<<endl;
    }
};

class ExecuteOrdersState: public State{
public:
    void UpdateState() override{
        cout << "Execute Orders State"<<endl;
    }
};

class WinState: public State{
public:
    void UpdateState() override{
        cout << "Win State"<<endl;
    }
};

class StateController{
private:
    State* currentState = nullptr;

public:
    void Init(){
        currentState = new StartState();
    }

    void Update(){
        currentState->UpdateState();
    }

    void TransitionTo(char c){
        delete currentState;
    }

    ~StateController(){
        delete currentState;
    }
};

