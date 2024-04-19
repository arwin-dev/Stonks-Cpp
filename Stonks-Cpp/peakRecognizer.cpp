#include "peakRecognizer.h"

namespace Stonks_Cpp {
	// Constructor for peakRecognizer class
	peakRecognizer::peakRecognizer() : recognizer(3, "Peak")
	{

	}

	// Override method to recognize a peak pattern for a list of candlesticks
	bool peakRecognizer::recognize(List<smartCandlestick^>^ sc)
	{
		// Check if there are exactly three candlesticks
		if (sc->Count == 3)
		{
			smartCandlestick^ sc1 = sc[0];
			smartCandlestick^ sc2 = sc[1];
			smartCandlestick^ sc3 = sc[2];

			// Check conditions for peak pattern
			return (sc2->High > sc1->High) && (sc2->High > sc3->High);
		}

		return false;
	}
}