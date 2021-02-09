#include "imgui.h"
#include <Mahi/Gui.hpp>

struct IntDefault{int i = 0;};
//Two apps with the same name each need a unique pid
std::map<std::string, IntDefault > AppPids;

class CatApp{
public:
    
    CatApp(){
    }
    void draw(){}
    void raw_draw(){
        if (ImGui::Begin("Appname")){
            draw();
        }
        ImGui::End();
    };
};