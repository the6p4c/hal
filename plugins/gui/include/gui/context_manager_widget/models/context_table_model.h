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

#include "hal_core/defines.h"
#include "gui/graph_widget/contexts/graph_context.h"

#include <QAbstractTableModel>

namespace hal
{
    /**
     * @ingroup utility_widgets-context
     * @brief Base model for the ContextManagerWidget to manage GraphContext%s.
     *
     * The ContextTableModel implements a standard table model to manage the GraphContext%s
     * that are created/deleted/modified by the user. It provides the neccessary interface for
     * the ContextManagerWidget to store and display the data. For specific information on how to
     * implement a table model, refer to qt's QAbstractTableModel class and its examples.
     */
    class ContextTableModel : public QAbstractTableModel
    {
        Q_OBJECT

    public:
        ContextTableModel(QObject* parent = nullptr);
        int rowCount(const QModelIndex& parent = QModelIndex()) const override;
        int columnCount(const QModelIndex& parent = QModelIndex()) const override;
        QVariant data(const QModelIndex& inddex, int role = Qt::DisplayRole) const override;
        QVariant headerData(int section, Qt::Orientation orientation, int role = Qt::DisplayRole) const override;
        void addContext(GraphContext* context);
        void removeContext(GraphContext* context);

        GraphContext* getContext(const QModelIndex& index) const;
        QModelIndex getIndex(GraphContext* context) const;

        void beginInsertContext(GraphContext* context);
        void endInsertContext();

        void beginRemoveContext(GraphContext* context);
        void endRemoveContext();

        void clear();

        const QVector<GraphContext*>& list() const { return mContextList; }
    private Q_SLOTS:
        void handleDataChanged();

    private:
        QVector<GraphContext*> mContextList;
    };
}    // namespace hal
