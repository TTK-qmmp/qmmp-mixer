#include "effectmixerfactory.h"
#include "mixerplugin.h"
#include "settingsdialog.h"

#include <QMessageBox>

const EffectProperties EffectMixerFactory::properties() const
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

void EffectMixerFactory::showSettings(QWidget *parent)
{
    (new SettingsDialog(parent))->show();
}

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

