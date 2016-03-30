#include "stdafx.h"
#include "AccountsPage.h"
#include "../utils/utils.h"
#include "../utils/mac_migration.h"
#include "../controls/PictureWidget.h"
#include "../cache/avatars/AvatarStorage.h"

namespace Ui
{
    bool is_number(const QString& _value)
    {
        int num = _value.toInt();

        QString v = QString("%1").arg(num);
        return _value == v;
    }

    QString format_uin(const QString& _uin)
    {
        if (!is_number(_uin))
            return _uin;

        QString ss_uin;

        int counter = 0;
        for (QChar c : _uin)
        {
            if (counter >= 3)
            {
                ss_uin.append('-');
                counter = 0;
            }

            counter++;
            ss_uin.append(c);
        }


        return ss_uin;
    }

    account_widget::account_widget(QWidget* _parent, const MacProfile& uid)
        : QPushButton(_parent),
          account_(uid)
    {
        const int account_widget_height = Utils::scale_value(64);

        setObjectName("account_widget");
        
        setCursor(Qt::PointingHandCursor);

        const int h_margin = Utils::scale_value(12);

        QHBoxLayout* root_layout = new QHBoxLayout();
        root_layout->setSpacing(0);
        root_layout->setContentsMargins(0, h_margin, 0, h_margin);
        
        avatar_ = new QLabel(this);
        avatar_h_ = account_widget_height - h_margin - h_margin;
        
        avatar_->setFixedHeight(avatar_h_);
        avatar_->setFixedWidth(avatar_h_);
        avatar_loaded(uid.uin());
        
        root_layout->addWidget(avatar_);

        root_layout->addSpacing(Utils::scale_value(12));

        QVBoxLayout* name_layout = new QVBoxLayout();
        {
            name_layout->setAlignment(Qt::AlignTop);

            QLabel* name_label = new QLabel(this);
            name_label->setText(account_.name());
            name_label->setObjectName("label_account_nick");

            name_layout->addWidget(name_label);

            QLabel* uin_label = new QLabel(this);
            uin_label->setText(format_uin(account_.uin()));
            uin_label->setObjectName("label_account_uin");

            name_layout->addWidget(uin_label);
        }
        root_layout->addLayout(name_layout);

        root_layout->addSpacerItem(new QSpacerItem(0, 0, QSizePolicy::Expanding, QSizePolicy::Minimum));

        QLabel* arrow_right = new QLabel(this);
        arrow_right->setFixedHeight(Utils::scale_value(20));
        arrow_right->setFixedWidth(Utils::scale_value(20));
        arrow_right->setObjectName("arrow_right");
        root_layout->addWidget(arrow_right);
        
        setLayout(root_layout);
        
        setFixedHeight(account_widget_height);
        
//        connect(Logic::GetAvatarStorage(), SIGNAL(avatarChanged(QString)), this, SLOT(avatar_loaded(QString)), Qt::QueuedConnection);
    }

    void account_widget::avatar_loaded(QString uid)
    {
        if (uid == account_.uin())
        {
            bool isDefault = true;
            const auto avatarPix = Logic::GetAvatarStorage()->GetRounded(account_.uin(), account_.name(),
                                                                         Utils::scale_bitmap(Utils::scale_value(avatar_h_)),
                                                                         "", true, isDefault);
            avatar_->setPixmap(avatarPix->copy());
        }
    }
    
    account_widget::~account_widget()
    {
    }

    void account_widget::paintEvent(QPaintEvent* _e)
    {
        QStyleOption opt;
        opt.init(this);
        QPainter p(this);
        style()->drawPrimitive (QStyle::PE_Widget, &opt, &p, this);

        return QWidget::paintEvent(_e);
    }

    AccountsPage::AccountsPage(QWidget* _parent, MacMigrationManager * manager)
        : QWidget(_parent)
    {
        setStyleSheet(Utils::LoadStyle(":/main_window/accounts_page.qss", Utils::get_scale_coefficient(), true));
        
        QVBoxLayout* verticalLayout = new QVBoxLayout(this);
        verticalLayout->setSpacing(0);
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        verticalLayout->setContentsMargins(0, 0, 0, 0);
        
        QWidget* main_widget = new QWidget(this);
        main_widget->setObjectName(QStringLiteral("main_widget"));
        QSizePolicy sizePolicy(QSizePolicy::Minimum, QSizePolicy::Expanding);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(main_widget->sizePolicy().hasHeightForWidth());
        main_widget->setSizePolicy(sizePolicy);
        QHBoxLayout* main_layout = new QHBoxLayout(main_widget);
        main_layout->setSpacing(0);
        main_layout->setObjectName(QStringLiteral("main_layout"));
        main_layout->setContentsMargins(0, 0, 0, 0);
        
        QWidget* controls_widget = new QWidget(main_widget);
        controls_widget->setObjectName(QStringLiteral("controls_widget"));
        QSizePolicy sizePolicy1(QSizePolicy::Minimum, QSizePolicy::Minimum);
        sizePolicy1.setHorizontalStretch(0);
        sizePolicy1.setVerticalStretch(0);
        sizePolicy1.setHeightForWidth(controls_widget->sizePolicy().hasHeightForWidth());
        controls_widget->setSizePolicy(sizePolicy1);
        controls_widget->setFixedWidth(500);
        QVBoxLayout* controls_layout = new QVBoxLayout(controls_widget);
        controls_layout->setSpacing(0);
        controls_layout->setObjectName(QStringLiteral("controls_layout"));
        controls_layout->setContentsMargins(0, 0, 0, 0);
        
        controls_layout->addSpacing(Utils::scale_value(50));
        
        PictureWidget* logo_widget = new PictureWidget(controls_widget, ":/resources/main_window/content_logo_100.png");
        logo_widget->setFixedHeight(Utils::scale_value(80));
        logo_widget->setFixedWidth(Utils::scale_value(80));
        controls_layout->addWidget(logo_widget);
        controls_layout->setAlignment(logo_widget, Qt::AlignHCenter);
        
        QLabel* welcome_label = new QLabel(controls_widget);
        welcome_label->setObjectName(QStringLiteral("welcome_label"));
        welcome_label->setAlignment(Qt::AlignCenter);
        welcome_label->setProperty("WelcomeTitle", QVariant(true));
        welcome_label->setText(QT_TRANSLATE_NOOP("login_page","Welcome to ICQ"));
        
        controls_layout->addWidget(welcome_label);
        
        QLabel* label_choose_comment = new QLabel(main_widget);
        label_choose_comment->setObjectName("choose_account_comment_label");
        label_choose_comment->setText(QT_TR_NOOP("Now we support only one ICQ account per session. Please choose prefered one to continue."));
        label_choose_comment->setWordWrap(true);
        label_choose_comment->setAlignment(Qt::AlignHCenter | Qt::AlignTop);
        controls_layout->addWidget(label_choose_comment);

        controls_layout->addSpacing(Utils::scale_value(24));
        
        QScrollArea* accounts_area = new QScrollArea(main_widget);
        QWidget* accounts_area_widget = new QWidget(main_widget);
        accounts_area_widget->setObjectName("accounts_area_widget");
        accounts_area->setWidget(accounts_area_widget);
        accounts_area->setWidgetResizable(true);
        accounts_area->setSizePolicy(QSizePolicy::Expanding, QSizePolicy::Expanding);
        
        QVBoxLayout* accounts_layout = new QVBoxLayout();
        accounts_layout->setSpacing(0);
        accounts_layout->setContentsMargins(0, 0, 0, 0);
        accounts_layout->setAlignment(Qt::AlignTop);

        const auto& accounts = manager->getProfiles();
        for (auto account : accounts)
        {
            account_widget* widget = new account_widget(accounts_area_widget, account);
            accounts_layout->addWidget(widget);
            connect(widget, &account_widget::clicked, [this, manager, account]()
            {
                manager->migrateProfile(account);

                emit account_selected();
            });
        }

        accounts_area_widget->setLayout(accounts_layout);
        
        controls_layout->addWidget(accounts_area);
        
        controls_layout->addSpacing(Utils::scale_value(24));
        
        QLabel* label_choose = new QLabel(main_widget);
        label_choose->setObjectName("choose_account_label");
        label_choose->setText(QT_TR_NOOP("Choose your account"));
        label_choose->setAlignment(Qt::AlignHCenter | Qt::AlignTop);
        controls_layout->addWidget(label_choose);
        
        controls_layout->addSpacing(Utils::scale_value(50));
        
        main_layout->addWidget(controls_widget);
        
//        QSpacerItem* horizontalSpacer_7 = new QSpacerItem(0, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);
//        
//        main_layout->addItem(horizontalSpacer_7);
//        
        verticalLayout->addWidget(main_widget);
    
//        QObject::connect(Ui::GetDispatcher(), SIGNAL(loginResult(int)), this, SLOT(loginResult(int)), Qt::DirectConnection);
    }


    AccountsPage::~AccountsPage()
    {
    }

    void AccountsPage::loginResult(int result)
    {
        if (result == 0)
        {
//            emit loggedIn();
        }
    }
    
}
