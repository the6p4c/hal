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

#include <QLabel>
#include <QWidget>

namespace hal
{
    /**
     * The DisputedBigIcon class is a utiliy class used for displaying big icons. It functions as a container
     * for the actual icon and is usually shown to display the gate, net and module specific icons within the
     * details widget.
     */
    class DisputedBigIcon : public QLabel
    {
        Q_OBJECT
    public:

        /**
         * The constructor.
         *
         * @param iconName - Just the name of the icon. It is loaded from a subpath in the qt resource file.
         * @param parent - The widget's parent.
         */
        DisputedBigIcon(const QString& iconName, QWidget* parent = nullptr);

    public Q_SLOTS:

        /**
         * A handler function for the settings-relay. It checks wether the key is the one that belongs to
         * this specific widget. If yes, the value that belongs to the key is updated (in this case wether the
         * icon shall be hidden or displayed).
         *
         * @param sender - The sender that triggered the setting change.
         * @param key - The setting's key.
         * @param value - The new setting's value.
         */
        void handleGlobalSettingsChanged(void* sender, const QString& key, const QVariant& value);

    private:
        void showOrHide();
        bool mIsVisible;
    };
}    // namespace hal