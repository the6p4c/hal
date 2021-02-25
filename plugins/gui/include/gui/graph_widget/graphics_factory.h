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

#include "gui/graph_widget/items/nodes/gates/graphics_gate.h"
#include "gui/graph_widget/items/nodes/modules/graphics_module.h"

#include <QStringList>

#include <cassert>
#include <memory>

namespace hal
{
    /**
     * The GraphicsFactory namespace provides functions to create GraphicsModules and GraphicsGates
     */
    namespace GraphicsFactory
    {
        QStringList graphicsModuleTypes();
        QStringList graphicsGateTypes();

        // TODO: enum for GraphicsModule/GraphicsGate type? type necessary or legacy?
        /**
         * Creates a GraphicsModule for a certain module on the heap.
         *
         * @param m - The underlying module of the GraphicsModule
         * @param type - The type of the GraphicsModule (must be 0 currently)
         * @returns a pointer to the new GraphicsModules
         */
        GraphicsModule* createGraphicsModule(Module* m, const int type);

        /**
         * Creates a GraphicsGate for a certain gate on the heap.
         *
         * @param g - The underlying gate of the GraphicsModule
         * @param type - The type of the GraphicsGate (must be 0 currently)
         * @returns a pointer to the new GraphicsGate
         */
        GraphicsGate* createGraphicsGate(Gate* g, const int type);
    }
}