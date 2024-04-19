#include "bullishHaramiRecognizer.h"

namespace Stonks_Cpp {
	// Constructor for bullishHaramiRecognizer class
	bullishHaramiRecognizer::bullishHaramiRecognizer() : recognizer(2, "Bullish Harami")
	{

	}

	// Override method to recognize a bullish harami pattern for a list of candlesticks
	bool bullishHaramiRecognizer::recognize(List<smartCandlestick^>^ sc)
	{
		// Check if there are exactly two candlesticks
		if (sc->Count == 2)
		{
			smartCandlestick^ sc1 = sc[0];
			smartCandlestick^ sc2 = sc[1];

			// Check conditions for bullish harami pattern
			return ((sc2->Close > sc2->Open) && (sc1->Close < sc1->Open) && (sc2->Close < sc1->Open) && (sc2->Open > sc1->Open));
		}

		return false;
	}
}