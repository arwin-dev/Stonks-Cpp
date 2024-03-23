#pragma once
#include "candlestick.h" 

// Using directives for simplifying namespaces
using namespace System;
using namespace System::Collections::Generic;
using namespace System::Globalization;
using namespace System::IO;

namespace Stonks_Cpp {
	// Forward declaration of smartCandlestick class
	ref class smartCandlestick : public candlestick
	{
	public:
		// Properties representing various aspects of candlestick
		// Add comments describing each property

		// Total range of the candlestick
		property double Range;

		// Range of the body of the candlestick
		property double BodyRange;

		// Highest price point of the candlestick
		property double TopPrice;

		// Lowest price point of the candlestick
		property double BottomPrice;

		// Length of the upper tail (wick) of the candlestick
		property double TopTail;

		// Length of the lower tail (wick) of the candlestick
		property double BottomTail;

		// Boolean indicating if the candlestick is bullish
		property bool IsBullish;

		// Boolean indicating if the candlestick is bearish
		property bool IsBearish;

		// Boolean indicating if the candlestick is a marubozu
		property bool IsMarubozu;

		// Boolean indicating if the candlestick is neutral
		property bool IsNeutral;

		// Boolean indicating if the candlestick is a doji
		property bool IsDoji;

		// Boolean indicating if the candlestick is a dragonfly doji
		property bool IsDragonFlyDoji;

		// Boolean indicating if the candlestick is a gravestone doji
		property bool IsGravestoneDoji;

		// Boolean indicating if the candlestick is a hammer
		property bool IsHammer;

		// Boolean indicating if the candlestick is an inverted hammer
		property bool IsInvertedHammer;

		// Dictionary to store candlestick patterns and their occurrence
		Dictionary<String^, bool>^ Patterns;

		// Constructor that initializes a smartCandlestick object
		smartCandlestick(String^ line);
	};

}
