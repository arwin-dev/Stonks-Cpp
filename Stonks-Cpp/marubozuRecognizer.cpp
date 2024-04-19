#include "marubozuRecognizer.h"


namespace Stonks_Cpp {
	// Constructor for marubozuRecognizer class
	marubozuRecognizer::marubozuRecognizer() : recognizer(1, "Marubozu")
	{

	}

	// Override method to recognize a marubozu pattern for a single candlestick
	bool marubozuRecognizer::recognize(smartCandlestick^ cs)
	{
		return cs->IsMarubozu; // Check if the candlestick is a marubozu
	}
}