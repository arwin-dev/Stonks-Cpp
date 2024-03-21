#pragma once
#include "candlestick.h"


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

            smartCandlestick(String^ line);
	};

}