#pragma once
#include "smartCandlestick.h" 

using namespace System;
using namespace System::Collections::Generic;

namespace Stonks_Cpp {

	// Abstract base class for candlestick pattern recognizers
	public ref class recognizer abstract
	{
	public:
		int patternSize; // Size of the pattern
		String^ patternName; // Name of the pattern

		// Constructor
		recognizer(int size, String^ name);

		// Abstract method to recognize a pattern for a single candlestick
		virtual bool recognize(smartCandlestick^ cs);

		// Abstract method to recognize a pattern for a list of candlesticks
		virtual bool recognize(List<smartCandlestick^>^ cs);
	};
}
