#include "gui/module_model/module_proxy_model.h"
#include "gui/module_model/module_item.h"

#include "gui/gui_globals.h"

namespace hal
{
    ModuleProxyModel::ModuleProxyModel(QObject* parent) : QSortFilterProxyModel(parent), mSortMechanism(gui_utility::mSortMechanism::lexical)
    {
        // QTS PROXY MODELS ARE DUMB, IMPLEMENT CUSTOM SOLUTION OR SWITCH TO A DIFFERENT FILTER METHOD

        // IN VIEW
        // EVERY TIME FILTER CHANGES / ITEM GETS ADDED MODIFY LOCAL DATA STRUCTURE TO REFLECT CURRENT ITEM VISUALS
        // STYLED DELEGATES USE THAT DATA STRUCTURE TO DRAW THEMSELVES
    }

    bool ModuleProxyModel::filterAcceptsRow(int sourceRow, const QModelIndex& sourceParent) const
    {
        if(!filterRegExp().isEmpty())
        {
            //QModelIndex source_index = sourceModel()->index(sourceRow, filterKeyColumn(), sourceParent);
            QModelIndex source_index = sourceModel()->index(sourceRow, 0, sourceParent);
            if(source_index.isValid())
            {
                if (sourceModel()->data(source_index, filterRole()).toString().contains(filterRegExp()))
                {
                    static_cast<ModuleItem*>(sourceModel()->index(sourceRow, 0, sourceParent).internalPointer())->setHighlighted(true);
                    return true;
                }
                else
                {
                    static_cast<ModuleItem*>(sourceModel()->index(sourceRow, 0, sourceParent).internalPointer())->setHighlighted(false);
                    return false;
                }
            }
        }

        void* internal = sourceModel()->index(sourceRow, 0, sourceParent).internalPointer();

        if (internal)
            static_cast<ModuleItem*>(internal)->setHighlighted(false);

        return true;
        //return QSortFilterProxyModel::filterAcceptsRow(sourceRow, sourceParent);
    }

    bool ModuleProxyModel::lessThan(const QModelIndex &source_left, const QModelIndex &source_right) const
    {
        QString name_left = source_left.data().toString();
        QString name_right = source_right.data().toString();
        if (sortCaseSensitivity() == Qt::CaseInsensitive)
        {
            name_left = name_left.toLower();
            name_right = name_right.toLower();
        }

        return gui_utility::compare(mSortMechanism, name_left, name_right);
    }

    gui_utility::mSortMechanism ModuleProxyModel::sortMechanism()
    {
        return mSortMechanism;
    }

    void ModuleProxyModel::setSortMechanism(gui_utility::mSortMechanism sortMechanism)
    {
        mSortMechanism = sortMechanism;
        invalidate();
    }
}
