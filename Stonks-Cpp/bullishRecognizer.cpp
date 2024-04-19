#include "bullishRecognizer.h"


namespace Stonks_Cpp {
	// Constructor for bullishRecognizer class
	bullishRecognizer::bullishRecognizer() : recognizer(1, "Bullish")
	{

	}

	// Override method to recognize a bullish pattern for a single candlestick
	bool bullishRecognizer::recognize(smartCandlestick^ cs)
	{
		return cs->IsBullish; // Check if the candlestick is bullish
	}
}