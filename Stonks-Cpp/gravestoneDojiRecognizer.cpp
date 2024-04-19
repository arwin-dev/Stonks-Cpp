#include "gravestoneDojiRecognizer.h"

namespace Stonks_Cpp {

	// Constructor for gravestoneDojiRecognizer class
	gravestoneDojiRecognizer::gravestoneDojiRecognizer() : recognizer(1, "GravestoneDoji")
	{

	}

	// Override method to recognize a gravestone doji pattern for a single candlestick
	bool gravestoneDojiRecognizer::recognize(smartCandlestick^ cs)
	{
		return cs->IsGravestoneDoji; // Check if the candlestick is a gravestone doji
	}
}