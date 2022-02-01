class Game;

class State{
public:
    State(Game* game);
    virtual ~State();
    virtual void start();
    virtual void mapLoaded();
    virtual void mapValidated();
    virtual void playersAdded();
    virtual void assignReinforcement();
    virtual void issueOrders();
    virtual void executeOrders();
    virtual void win();

protected:
    Game* game;
};

class startState{
public:
    startState(Game* game)
    virt
};