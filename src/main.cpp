#include "Mahi/Gui/imgui_custom.hpp"
#include "imgui.h"
#include <Mahi/Gui.hpp>
#include <Mahi/Util.hpp>
#include "apps/base.cpp"

using namespace mahi::gui;
using namespace mahi::util;
std::string out;

void clean_apps(){
    while (! CatApps_to_remove.empty()){
        auto app = CatApps_to_remove.front();
        CatApps.remove(app);
        CatApps_to_remove.pop_front();
    }
}

// Inherit from Application
class CatCad : public Application {
public:
    CatCad() : Application(640,480,"catCad") { }
    // Override update (called once per frame)
    void update() override {
        // App logic and/or ImGui code goes here
        ImGui::BeginMainMenuBar();
            if (ImGui::BeginMenu("File")){
                if (ImGui::MenuItem("Open")){
                    if (open_dialog(out, {{"All Supported", "ccad"},}) == DialogResult::DialogOkay){
                        print("Path: {}",out);
                    }
                }
                ImGui::EndMenu();
            }
            if (ImGui::BeginMenu("Tools")){
                if (ImGui::MenuItem("Sample")){
                    CatApps.push_back(std::shared_ptr<CatApp>(new CatApp()));
                };
                ImGui::EndMenu();
            }
        ImGui::EndMainMenuBar();
        ImGui::DockSpaceOverViewport();
        for (auto const& app : CatApps) {
            app->raw_draw();
        }
        clean_apps();
    }
};

int main() {
    CatCad app;
    ImGui::DisableViewports();
    app.run();
    return 0;
}