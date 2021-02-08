#include "Mahi/Gui/imgui_custom.hpp"
#include "imgui.h"
#include <Mahi/Gui.hpp>
#include <Mahi/Util.hpp>

using namespace mahi::gui;
using namespace mahi::util;
std::string out;

// Inherit from Application
class CatCad : public Application {
public:
    // 640x480 px window
    CatCad() : Application(640,480,"catCad") { }
    // Override update (called once per frame)
    void update() override {
        // App logic and/or ImGui code goes here
        ImGui::BeginMainMenuBar();
            if (ImGui::BeginMenu("File...")){
                if (ImGui::MenuItem("Open")){
                    if (open_dialog(out, {{"CAD", "ccad"},}) == DialogResult::DialogOkay)
                        print("Path: {}",out);
                }
                ImGui::EndMenu();
            }
        ImGui::EndMainMenuBar();
        ImGui::DockSpaceOverViewport();
        ImGui::ShowDemoWindow();
        ImGui::Begin("RootWindow");
        if (ImGui::Button("Press Me!"))
            print("Hello, World!");
        ImGui::End();
    }
};

int main() {
    CatCad app;
    ImGui::DisableViewports();
    app.run();
    return 0;
}