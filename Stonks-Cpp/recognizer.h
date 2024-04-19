#pragma once
#include "smartCandlestick.h" 

using namespace System;
using namespace System::Collections::Generic;

namespace Stonks_Cpp {

	// Abstract base class for candlestick pattern recognizers
	public ref class recognizer abstract
	{
	public:
		int patternSize; // Size of the pattern
		String^ patternName; // Name of the pattern

		// Constructor
		recognizer(int size, String^ name);

		// Abstract method to recognize a pattern for a single candlestick
		virtual bool recognizePattern(smartCandlestick^ cs);

		// Abstract method to recognize a pattern for a list of candlesticks
		virtual bool recognizePattern(List<smartCandlestick^>^ cs);
	};

	// Concrete class for recognizing bullish patterns
	public ref class bullishRecognizer : public recognizer
	{
	public:
		bullishRecognizer();

		// Override method to recognize a bullish pattern for a single candlestick
		virtual bool recognizePattern(smartCandlestick^ cs) override;
	};

	// Concrete class for recognizing bearish patterns
	public ref class bearishRecognizer : public recognizer
	{
	public:
		bearishRecognizer();

		// Override method to recognize a bearish pattern for a single candlestick
		virtual bool recognizePattern(smartCandlestick^ cs) override;
	};

	// Concrete class for recognizing neutral patterns
	public ref class neutralRecognizer : public recognizer
	{
	public:
		neutralRecognizer();

		// Override method to recognize a neutral pattern for a single candlestick
		virtual bool recognizePattern(smartCandlestick^ cs) override;
	};

	// Concrete class for recognizing doji patterns
	public ref class dojiRecognizer : public recognizer
	{
	public:
		dojiRecognizer();

		// Override method to recognize a doji pattern for a single candlestick
		virtual bool recognizePattern(smartCandlestick^ cs) override;
	};

	// Concrete class for recognizing marubozu patterns
	public ref class marubozuRecognizer : public recognizer
	{
	public:
		marubozuRecognizer();

		// Override method to recognize a marubozu pattern for a single candlestick
		virtual bool recognizePattern(smartCandlestick^ cs) override;
	};

	// Concrete class for recognizing dragonfly doji patterns
	public ref class dragonFlyDojiRecognizer : public recognizer
	{
	public:
		dragonFlyDojiRecognizer();

		// Override method to recognize a dragonfly doji pattern for a single candlestick
		virtual bool recognizePattern(smartCandlestick^ cs) override;
	};

	// Concrete class for recognizing gravestone doji patterns
	public ref class gravestoneDojiRecognizer : public recognizer
	{
	public:
		gravestoneDojiRecognizer();

		// Override method to recognize a gravestone doji pattern for a single candlestick
		virtual bool recognizePattern(smartCandlestick^ cs) override;
	};

	// Concrete class for recognizing hammer patterns
	public ref class hammerRecognizer : public recognizer
	{
	public:
		hammerRecognizer();

		// Override method to recognize a hammer pattern for a single candlestick
		virtual bool recognizePattern(smartCandlestick^ cs) override;
	};

	// Concrete class for recognizing inverted hammer patterns
	public ref class invertedHammerRecognizer : public recognizer
	{
	public:
		invertedHammerRecognizer();

		// Override method to recognize an inverted hammer pattern for a single candlestick
		virtual bool recognizePattern(smartCandlestick^ cs) override;
	};

	// Concrete class for recognizing bullish engulfing patterns
	public ref class bullishEngulfingRecognizer : public recognizer
	{
	public:
		bullishEngulfingRecognizer();

		// Override method to recognize a bullish engulfing pattern for a list of candlesticks
		virtual bool recognizePattern(List<smartCandlestick^>^ sc) override;
	};

	// Concrete class for recognizing bearish engulfing patterns
	public ref class bearishEngulfingRecognizer : public recognizer
	{
	public:
		bearishEngulfingRecognizer();

		// Override method to recognize a bearish engulfing pattern for a list of candlesticks
		virtual bool recognizePattern(List<smartCandlestick^>^ sc) override;
	};

	// Concrete class for recognizing bullish harami patterns
	public ref class bullishHaramiRecognizer : public recognizer
	{
	public:
		bullishHaramiRecognizer();

		// Override method to recognize a bullish harami pattern for a list of candlesticks
		virtual bool recognizePattern(List<smartCandlestick^>^ sc) override;
	};

	// Concrete class for recognizing bearish harami patterns
	public ref class bearishHaramiRecognizer : public recognizer
	{
	public:
		bearishHaramiRecognizer();

		// Override method to recognize a bearish harami pattern for a list of candlesticks
		virtual bool recognizePattern(List<smartCandlestick^>^ sc) override;
	};

	// Concrete class for recognizing peak patterns
	public ref class peakRecognizer : public recognizer
	{
	public:
		peakRecognizer();

		// Override method to recognize a peak pattern for a list of candlesticks
		virtual bool recognizePattern(List<smartCandlestick^>^ sc) override;
	};

	// Concrete class for recognizing valley patterns
	public ref class valleyRecognizer : public recognizer
	{
	public:
		valleyRecognizer();

		// Override method to recognize a valley pattern for a list of candlesticks
		virtual bool recognizePattern(List<smartCandlestick^>^ sc) override;
	};
}
