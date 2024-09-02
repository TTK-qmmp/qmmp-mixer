#include "settingsdialog.h"
#include "mixerplugin.h"

#include <QSettings>
#include <QAbstractButton>

SettingsDialog::SettingsDialog(QWidget *parent)
    : QDialog(parent)
{
    m_ui.setupUi(this);
    setAttribute(Qt::WA_DeleteOnClose);
#ifdef Q_OS_UNIX
    for(QAbstractButton *button : m_ui.buttonBox->buttons())
    {
        button->setFocusPolicy(Qt::NoFocus);
    }
#endif
#if QT_VERSION >= QT_VERSION_CHECK(6,0,0)
    QSettings settings;
#else
    QSettings settings(Qmmp::configFile(), QSettings::IniFormat);
#endif
    m_ui.type->addItems(QStringList() << tr("NullMix") <<tr("MonoToStereo") << tr("StereoToMono"));
    m_ui.type->setCurrentIndex(settings.value("ChannelMixer/type", MixerPlugin::Null).toInt());
}

void SettingsDialog::accept()
{
    const int index = m_ui.type->currentIndex();
#if QT_VERSION >= QT_VERSION_CHECK(6,0,0)
    QSettings settings;
#else
    QSettings settings(Qmmp::configFile(), QSettings::IniFormat);
#endif
    settings.setValue("ChannelMixer/type", index);

    if(MixerPlugin::instance())
    {
        MixerPlugin::instance()->setType(static_cast<MixerPlugin::MixerType>(index));
    }
    QDialog::accept();
}
