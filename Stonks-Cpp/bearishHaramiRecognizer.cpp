#include "bearishHaramiRecognizer.h"

namespace Stonks_Cpp {
	// Constructor for bearishHaramiRecognizer class
	bearishHaramiRecognizer::bearishHaramiRecognizer() : recognizer(2, "Bearish Harami")
	{

	}

	// Override method to recognize a bearish harami pattern for a list of candlesticks
	bool bearishHaramiRecognizer::recognize(List<smartCandlestick^>^ sc)
	{
		// Check if there are exactly two candlesticks
		if (sc->Count == 2)
		{
			smartCandlestick^ sc1 = sc[0];
			smartCandlestick^ sc2 = sc[1];

			// Check conditions for bearish harami pattern
			return ((sc2->Close < sc2->Open) && (sc1->Close > sc1->Open) && (sc2->Close > sc1->Open) && (sc2->Open < sc1->Close));
		}

		return false;
	}
}