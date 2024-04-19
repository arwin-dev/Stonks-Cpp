#include "valleyRecognizer.h"

namespace Stonks_Cpp {
	// Constructor for valleyRecognizer class
	valleyRecognizer::valleyRecognizer() : recognizer(3, "Valley")
	{

	}

	// Override method to recognize a valley pattern for a list of candlesticks
	bool valleyRecognizer::recognize(List<smartCandlestick^>^ sc)
	{
		// Check if there are exactly three candlesticks
		if (sc->Count == 3)
		{
			smartCandlestick^ sc1 = sc[0];
			smartCandlestick^ sc2 = sc[1];
			smartCandlestick^ sc3 = sc[2];

			// Check conditions for valley pattern
			return (sc2->Low < sc1->Low) && (sc2->Low < sc3->Low);
		}

		return false;
	}
}
