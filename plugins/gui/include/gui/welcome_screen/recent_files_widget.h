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

#include <QFrame>

class QVBoxLayout;

namespace hal
{
    class RecentFileItem;

    /**
     * @ingroup gui
     * @brief The welcome screen's RecentFiles section.
     *
     * The widget in the welcome screen that shows the recently used files.
     */
    class RecentFilesWidget : public QFrame
    {
        Q_OBJECT

    public:
        /**
         * Constructor. <br>
         * The list of recently used files are drawn from the settings in the constructor.
         *
         * @param parent - The parent widget
         */
        RecentFilesWidget(QWidget* parent = nullptr);

        /**
         * Initializes the appearance of the widget.
         */
        void repolish();

    public Q_SLOTS:
        /**
         * Q_SLOT to handle that a file has been opened. Used to append the file to the list of recently used files.
         * The updated list is persisted by updating the settings.
         *
         * @param fileName - The path of the opened file
         */
        void handleFileOpened(const QString& fileName);

        /**
         * Handles that a recentFileItem should be removed (by clicking the 'x'). It removed the item from the widget.
         *
         * @param item - The item to remove
         */
        void handleRemoveRequested(RecentFileItem* item);

    private:
        void readSettings();
        void updateSettings();

        QVBoxLayout* mLayout;

        QList<RecentFileItem*> mItems;
    };
}
