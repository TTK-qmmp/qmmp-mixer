/***************************************************************************
 * This file is part of the TTK qmmp plugin project
 * Copyright (C) 2015 - 2025 Greedysky Studio

 * This program is free software; you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation; either version 3 of the License, or
 * (at your option) any later version.

 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.

 * You should have received a copy of the GNU General Public License along
 * with this program; If not, see <http://www.gnu.org/licenses/>.
 ***************************************************************************/

#ifndef EFFECTMIXERFACTORY_H
#define EFFECTMIXERFACTORY_H

#include <qmmp/qmmp.h>
#include <qmmp/effectfactory.h>

/*!
 * @author Greedysky <greedysky@163.com>
 */
class EffectMixerFactory : public QObject, public EffectFactory
{
    Q_OBJECT
    Q_PLUGIN_METADATA(IID "org.qmmp.qmmp.EffectFactoryInterface.1.0")
    Q_INTERFACES(EffectFactory)
public:
#if (QMMP_VERSION_INT < 0x10700) || (0x20000 <= QMMP_VERSION_INT && QMMP_VERSION_INT < 0x20200)
    virtual const EffectProperties properties() const override final;
#else
    virtual EffectProperties properties() const override final;
#endif
    virtual Effect *create() override final;
#if (QMMP_VERSION_INT < 0x10700) || (0x20000 <= QMMP_VERSION_INT && QMMP_VERSION_INT < 0x20200)
    virtual void showSettings(QWidget *parent) override final;
#else
    virtual QDialog *createSettings(QWidget *parent) override final;
#endif
    virtual void showAbout(QWidget *parent) override final;
    virtual QString translation() const override final;

};

#endif
