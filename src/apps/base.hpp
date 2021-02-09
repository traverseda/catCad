#include <string>


class CatApp{
public:
    CatApp();

    //Name of the app window
    std::string appName;
    //Draws the outer window, hooks up callbacks
    virtual void raw_draw();
    //Override this for your actual catapp functionality
    virtual void draw()=0;
};