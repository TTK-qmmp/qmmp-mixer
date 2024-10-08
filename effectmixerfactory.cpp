#include "effectmixerfactory.h"
#include "mixerplugin.h"
#include "settingsdialog.h"

#include <QMessageBox>

#if (QMMP_VERSION_INT < 0x10700) || (0x20000 <= QMMP_VERSION_INT && QMMP_VERSION_INT < 0x20200)
const EffectProperties EffectMixerFactory::properties() const
#else
EffectProperties EffectMixerFactory::properties() const
#endif
{
    EffectProperties properties;
    properties.name = tr("Channel Mixer Plugin");
    properties.shortName = "mixer";
    properties.hasSettings = true;
    properties.hasAbout = true;
    return properties;
}

Effect *EffectMixerFactory::create()
{
    return new MixerPlugin();
}

#if (QMMP_VERSION_INT < 0x10700) || (0x20000 <= QMMP_VERSION_INT && QMMP_VERSION_INT < 0x20200)
void EffectMixerFactory::showSettings(QWidget *parent)
{
    (new SettingsDialog(parent))->show();
}
#else
QDialog *EffectMixerFactory::createSettings(QWidget *parent)
{
    return new SettingsDialog(parent);
}
#endif

void EffectMixerFactory::showAbout(QWidget *parent)
{
     QMessageBox::about(parent, tr("About Channel Mixer Effect Plugin"),
                        tr("Qmmp Channel Mixer Effect Plugin") + "\n" +
                        tr("Written by: Greedysky <greedysky@163.com>"));
}

QString EffectMixerFactory::translation() const
{
    return QString();
}

