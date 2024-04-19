#pragma once
#include "recognizer.h" 

namespace Stonks_Cpp {
	//class for recognizing bullish patterns
	public ref class neutralRecognizer : public recognizer
	{
		public:
			neutralRecognizer();

			// Override method to recognize a bullish pattern for a single candlestick
		virtual bool recognize(smartCandlestick^ cs) override;
	};
}

