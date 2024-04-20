#pragma once
#include "recognizer.h" 

namespace Stonks_Cpp {
	//class for recognizing bullish patterns
	public ref class marubozuRecognizer : public recognizer
	{
	public:
		marubozuRecognizer();

		// Override method to recognize a bullish pattern for a single candlestick
		virtual bool recognize(List<smartCandlestick^>^ sc, int index) override;
	};
}

