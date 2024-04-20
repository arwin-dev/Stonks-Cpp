#pragma once
#include "recognizer.h" 

namespace Stonks_Cpp {
	//class for recognizing bullish patterns
	public ref class bearishEngulfingRecognizer : public recognizer
	{
	public:
		bearishEngulfingRecognizer();

		// Override method to recognize a bullish pattern for a single candlestick
		virtual bool recognize(List<smartCandlestick^>^ scs, int index) override;
	};
}


