#include "bearishRecognizer.h"


namespace Stonks_Cpp {
	// Constructor for bearishRecognizer class
	bearishRecognizer::bearishRecognizer() : recognizer(1, "Bearish")
	{

	}

	// Override method to recognize a bearish pattern for a single candlestick
	bool bearishRecognizer::recognize(smartCandlestick^ cs)
	{
		return cs->IsBearish; // Check if the candlestick is bearish
	}
}