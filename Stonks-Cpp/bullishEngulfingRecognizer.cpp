#include "bullishEngulfingRecognizer.h"


namespace Stonks_Cpp {
	// Constructor for bullishEngulfingRecognizer class
	bullishEngulfingRecognizer::bullishEngulfingRecognizer() : recognizer(2, "Bullish Engulfing")
	{

	}

	// Override method to recognize a bullish engulfing pattern for a list of candlesticks
	bool bullishEngulfingRecognizer::recognize(List<smartCandlestick^>^ sc)
	{
		// Check if there are exactly two candlesticks
		if (sc->Count == 2)
		{
			smartCandlestick^ sc1 = sc[0];
			smartCandlestick^ sc2 = sc[1];

			// Check conditions for bullish engulfing pattern
			return (sc2->Close > sc2->Open) && (sc1->Close < sc1->Open) && (sc2->Close > sc1->Open) && (sc2->Open < sc1->Close);
		}

		return false;
	}
}
