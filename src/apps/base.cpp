#include "imgui.h"
#include <Mahi/Gui.hpp>
#include <deque>
#include <iomanip>
using std::enable_shared_from_this;

using namespace std;

class CatApp;

//Windows get their draw method called once per cycle
std::list<std::shared_ptr<CatApp>> CatApps;
//Apps that should get removed next frame. We can't remove apps in the middle of a frame
std::deque<std::shared_ptr<CatApp>> CatApps_to_remove;

class CatApp : public enable_shared_from_this<CatApp> {
public:
    std::string appName = typeid(this).name();
    CatApp(){};
    virtual void draw(){
        ImGui::Text("Hello World");
    };
    virtual void raw_draw(){
        std::stringstream stream;
        stream << std::hex << this;
        //Pointer as hex string
        std::string appPointer(stream.str());

        auto appId = this->appName+"##"+appPointer;

        bool showWindow = true;
        if (ImGui::Begin(appId.c_str(), &showWindow)){
            if (!showWindow)this->close();
            draw();
        }
        ImGui::End();
    };
    virtual bool close(){
        CatApps_to_remove.push_back(this->shared_from_this());
        return true;
    };
};

class Tty: public CatApp{

};