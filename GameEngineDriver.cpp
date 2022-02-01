#include <iostream>
#include "GameEngine.cpp"
using namespace std;

int main(){
    StateController stateController;
    stateController.Init();

    string str = "n";

    while (str[0] != 'q'){
        stateController.Update();
        cin >> str;
        cout << std::endl;
    }

}