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

#include <QtGlobal>

namespace hal
{
    namespace graph_widget_constants
    {
        static const int sFontSize = 12;
        static const int sGridSize = 14;
        static const int sClusterSize = 8;

        static const qreal sGateMinLod = 0.2; // if current lod < than this use lowest level of detail
        static const qreal sGateMaxLod = 0.4; // if current lod > than this use highest level of detail

        static const qreal sNetMinLod = 0.1; // if current lod < than this use lowest level of detail
        static const qreal sNetMaxLod = 0.4; // if current lod > than this use highest level of detail

        static const qreal sEparatedNetMinLod = 0.1; // if current lod < than this use lowest level of detail
        static const qreal sEparatedNetMaxLod = 0.4; // if current lod > than this use highest level of detail

        static const qreal sGlobalNetMinLod = 0.1; // if current lod < than this use lowest level of detail
        static const qreal sGlobalNetMaxLod = 0.4; // if current lod > than this use highest level of detail

        static const qreal sNetFadeInLod = 0.1;
        static const qreal sNetFadeOutLod = 0.4;

        static const qreal sGridFadeStartLod = 0.4;
        static const qreal sGridFadeEndLod = 1.0;

        static const int mDragSwapSensitivityDistance = 100;

        enum class grid_type
        {
            Lines,
            Dots,
            None
        };
    }
}