include(FetchContent) 
FetchContent_Declare(mahi-gui GIT_REPOSITORY https://github.com/mahilab/mahi-gui.git) 
FetchContent_MakeAvailable(mahi-gui)

FetchContent_Declare(ImGuiTerminal GIT_REPOSITORY https://github.com/timmoorhouse/imgui-terminal.git)
FetchContent_MakeAvailable(ImGuiTerminal)

FetchContent_Declare(Gecode GIT_REPOSITORY https://github.com/Gecode/gecode.git)
FetchContent_MakeAvailable(Gecode)

#FetchContent_Declare(Zep GIT_REPOSITORY https://github.com/Rezonality/zep.git)
#FetchContent_MakeAvailable(Zep)
project(catCad)
add_subdirectory(src)

add_executable(catCad "src/main.cpp")
target_link_libraries(catCad mahi::gui imgui-terminal)
#target_link_libraries(catCad mahi::gui Zep::Zep)
#target_link_libraries(catCad mahi::gui)