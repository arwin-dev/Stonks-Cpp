#include "invertedHammerRecognizer.h"

namespace Stonks_Cpp {
	// Constructor for invertedHammerRecognizer class
	invertedHammerRecognizer::invertedHammerRecognizer() : recognizer(1, "InvertedHammer")
	{

	}

	// Override method to recognize an inverted hammer pattern for a single candlestick
	bool invertedHammerRecognizer::recognize(smartCandlestick^ cs)
	{
		return cs->IsInvertedHammer; // Check if the candlestick is an inverted hammer
	}
}