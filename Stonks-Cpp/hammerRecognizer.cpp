#include "hammerRecognizer.h"

namespace Stonks_Cpp {
	// Constructor for bullishRecognizer class
	hammerRecognizer::hammerRecognizer() : recognizer(1, "Hammer")
	{

	}

	// Override method to recognize a bullish pattern for a single candlestick
	bool hammerRecognizer::recognize(smartCandlestick^ cs)
	{
		return cs->IsHammer; // Check if the candlestick is bullish
	}
}