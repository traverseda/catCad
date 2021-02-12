#include "imgui.h"
#include <Mahi/Gui.hpp>
#include <deque>
#include <iomanip>
#include <string>
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

    //The unique ID of this window
    virtual std::string appId(){
        std::stringstream stream;
        stream << std::hex << this;
        //Pointer as hex string
        std::string appPointer(stream.str());

        return appPointer;
    };

    virtual void draw(){
        ImGui::Text("Hello World");
    };
    virtual void raw_draw(){
        bool showWindow = true;
        if (ImGui::Begin((this->appName+"##"+this->appId()).c_str(), &showWindow)){
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

/*
#include <terminal/Terminal.hh>
#include <unistd.h>
#include <pty.h>
#include <fcntl.h>

class Tty: public CatApp {
public:
    int m_fd;
    terminal::Terminal m_terminal;
    pid_t m_pid = -1;

    //I have pretty much no idea what this actuall does
    // example copied from upstream
    void draw() override{

        //If the teminal exists, update terminal
        if (this->m_pid > 0) {
            char buf[256];
            ssize_t nbytes = read(this->m_fd, buf, sizeof(buf));
            for (ssize_t i = 0; i < nbytes; i++)
            this->m_terminal.write(buf[i]);
            };

        if (this->m_pid < 0) {
            this->m_pid = forkpty( & this->m_fd, nullptr, nullptr, nullptr);
        }

        if (this->m_pid < 0) {
          perror("forkpty");
        }

        if (!this->m_pid) {
          //! @todo set term to vt100?
          execl("/bin/bash", nullptr);
          perror("execl");
        }

        fcntl(this->m_fd, F_SETFL, fcntl(this->m_fd, F_GETFL, 0) | O_NONBLOCK);
        if (this->m_fd >= 0)
          write(this->m_fd, "ls\n", 3); //! @todo

        this->m_terminal.draw("Shell");
    }
};
*/