#pragma once

#include <tesla.hpp>
#include "../../ipc/music.h"

class ControlGui : public tsl::Gui {
  private:
    tsl::elm::List m_list;
    MusicPlayerStatus m_status;
    u32 m_counter;
    const char *m_current;
    const char *m_status_desc;
    const char *m_bottom_text;
    char m_progress_text[0x20];
    double m_percentage;
    double m_volume;

  public:
    ControlGui();

    virtual tsl::elm::Element *createUI() override;

    virtual void update() override;
    virtual bool handleInput(u64 keysDown, u64 keysHeld, touchPosition, JoystickPosition, JoystickPosition) override;

  private:
    void FetchStatus();
    void FetchCurrentSong();
    void FetchQueue();
    void FetchVolume();
    void FetchProgress();
};
