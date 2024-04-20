#pragma once
#include "recognizer.h" 

namespace Stonks_Cpp {
	// Concrete class for recognizing bearish patterns
	public ref class bearishRecognizer : public recognizer
	{
		public:
			bearishRecognizer();

			// Override method to recognize a bearish pattern 
			virtual bool recognize(List<smartCandlestick^>^ sc, int index) override;
	};
}

