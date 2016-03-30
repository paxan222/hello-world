#ifndef __CALL_PANEL_H__
#define __CALL_PANEL_H__

#include "CallMenu.h"
#include "AvatarContainerWidget.h"
#include "NameAndStatusWidget.h"

namespace voip_manager {
    struct ContactEx;
    struct Contact;
}

class QLabel;
namespace Ui {
    class PushButton_t : public QPushButton {
    public:
        enum eButtonState {
            normal = 0, 
            hovered, 
            pressed, 
            //--------
            total
        };

    public:
        PushButton_t(QWidget* parent = NULL);
        void setImageForState(const eButtonState state, const std::string& image);
        void setOffsets(int fromIconToText);
        void setIconSize(const int w, const int h);

    protected:
        void paintEvent(QPaintEvent*) override;
        bool event(QEvent*) override;

    private:
        eButtonState currentState_;
        QPixmap      bitmapsForStates_[total];
        int          fromIconToText_;
        int          iconW_;
        int          iconH_;
    };   

    class SliderEx : public QWidget {
        Q_OBJECT

    private Q_SLOTS:
        void onVolumeChanged(int);
        void onVolumeReleased();
        void onIconClicked();

    Q_SIGNALS:
        void onSliderReleased();
        void onIconClick();
        void onSliderValueChanged(int);

    public:
        SliderEx(QWidget* parent);
        ~SliderEx();

        void set_value(int);
        void set_enabled(bool);

        void setIconForState(const PushButton_t::eButtonState state, const std::string& image);
        void setIconSize(const int w, const int h);

        void set_property_for_icon(const char* name, bool val);
        void set_property_for_slider(const char* name, bool val);

    private:
        QHBoxLayout  *horizontal_layout_;
        PushButton_t *slider_icon_;
        QSlider      *slider_;
    };

    class CallPanelMain : public QWidget {
        Q_OBJECT

    private Q_SLOTS:
        void onHangUpButtonClicked();
        void onMenuButtonClicked();
        void onMenuOpenChanged(bool);

        void onVideoOnOffClicked();
        void onMuteMicOnOffClicked();
        void onVolumeChanged(int);
        void onVolumeReleased();
        void onVolumeOnOff();

        void onVoipCallNameChanged(const std::vector<voip_manager::Contact>&);
        void onVoipVolumeChanged(const std::string&,int);
        void onVoipCallDestroyed(const voip_manager::ContactEx& contact_ex);
        void onVoipMuteChanged(const std::string& device_type, bool muted);
		void onVoipCallTimeChanged(unsigned sec_elapsed, bool have_call);
        void onVoipMediaLocalAudio(bool enabled);
        void onVoipMediaLocalVideo(bool enabled);

    public:
        CallPanelMain(QWidget* parent);
        ~CallPanelMain();

    protected:
        std::string _get_tick_count();

    private:
        CallMenu _menu;
        QPushButton* menu_show_;
        int actual_vol_;

        AvatarContainerWidget* avatar_container_;
        NameAndStatusWidget*   name_and_status_container_;
    };
}

#endif//__CALL_PANEL_H__