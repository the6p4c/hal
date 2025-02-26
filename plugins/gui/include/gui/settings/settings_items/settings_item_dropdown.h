//  MIT License
//
//  Copyright (c) 2019 Ruhr-University Bochum, Germany, Chair for Embedded Security. All Rights reserved.
//  Copyright (c) 2019 Marc Fyrbiak, Sebastian Wallat, Max Hoffmann ("ORIGINAL AUTHORS"). All rights reserved.
//
//  Permission is hereby granted, free of charge, to any person obtaining a copy
//  of this software and associated documentation files (the "Software"), to deal
//  in the Software without restriction, including without limitation the rights
//  to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
//  copies of the Software, and to permit persons to whom the Software is
//  furnished to do so, subject to the following conditions:
//
//  The above copyright notice and this permission notice shall be included in all
//  copies or substantial portions of the Software.
//
//  THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
//  IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
//  FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
//  AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
//  LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
//  OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
//  SOFTWARE.

#pragma once

#include "gui/settings/settings_items/settings_item.h"

#include <QStringList>
#include <QMetaEnum>

namespace hal
{
    /**
     * @ingroup settings
     */
    class SettingsItemDropdown : public SettingsItem
    {
        Q_OBJECT

    public:
        SettingsItemDropdown(const QString& label, const QString& tag, int defVal, const QString& cat = QString(), const QString& desc = QString(), bool isGlobal = true);

        virtual QVariant value() const override;
        virtual QVariant defaultValue() const override;
        virtual void setValue(const QVariant& v) override;
        virtual void setDefaultValue(const QVariant& dv) override;
        virtual SettingsWidget* editWidget(QWidget* parent = nullptr) override;

        virtual QVariant persistToSettings() const override;
        virtual void restoreFromSettings(const QVariant& val) override;

        const QStringList& valueNames() const
        {
            return mValueNames;
        }

        template <typename T> void setValueNames()
        {
            mValueNames.clear();

            QMetaEnum metaEnum = QMetaEnum::fromType<T>();

            for(int i = 0; i < metaEnum.keyCount(); i++)
                mValueNames.append(metaEnum.key(i));

            reloadSettings();
        }

    Q_SIGNALS:
        void intChanged(int value);

    private:
        int mValue;
        int mDefaultValue;
        QStringList mValueNames;

        int valueFromString(const QString& s) const;
        void reloadSettings();
    };
}
