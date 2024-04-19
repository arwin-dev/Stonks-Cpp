#include "dojiRecognizer.h"


namespace Stonks_Cpp {
	// Constructor for dojiRecognizer class
	dojiRecognizer::dojiRecognizer() : recognizer(1, "Doji")
	{

	}

	// Override method to recognize a doji pattern for a single candlestick
	bool dojiRecognizer::recognize(smartCandlestick^ cs)
	{
		return cs->IsDoji; // Check if the candlestick is a doji
	}
}