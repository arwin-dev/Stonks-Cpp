#pragma once
#include "candlestick.h"

using namespace System;
using namespace System::Collections::Generic;
using namespace System::Globalization;
using namespace System::IO;

namespace Stonks_Cpp {
	using namespace System;

	ref class smartCandlestick : public candlestick
	{
        public:
            // Smart Candlestick Properties
            property double Range;
            property double BodyRange;
            property double TopPrice;
            property double BottomPrice;
            property double TopTail;
            property double BottomTail;

            property bool IsBullish;
            property bool IsBearish;
            property bool IsMarubozu;
            property bool IsNeutral;
            property bool IsDoji;
            property bool IsDragonFlyDoji;
            property bool IsGravestoneDoji;
            property bool IsHammer;
            property bool IsInvertedHammer;

            Dictionary<String^, bool>^ Patterns;

            smartCandlestick(String^ line);
	};

}