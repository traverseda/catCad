#include <string>


class CatApp{
public:
    CatApp();
    //Name of the app window
    std::string appName = typeid(this).name();
    virtual std::string appId();
    
    //Gets called every frame before draw(), whether or not the window is showing
    // don't put imgui calls in here, unless
    virtual void update();
    //Draws the outer window, hooks up callbacks
    virtual void raw_draw();
    //Override this for your actual catapp functionality
    virtual void draw();
};